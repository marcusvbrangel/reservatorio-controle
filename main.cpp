// --------------------------------------------------------------------------
// simulador.cpp
// Simulação de plataforma de petróleo com interface gráfica Qt.
// Esta versão foi modificada para remover todos os cálculos
// e exibições relacionadas a custos e lucro.
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Bibliotecas Qt necessárias para compilação.
// sudo apt install libqt5charts5-dev
// sudo apt install cmake make
// sudo apt install libqt5svg5-dev
// sudo apt install qtbase5-dev libqt5widgets5 libqt5charts5-dev libqt5svg5-dev
// --------------------------------------------------------------------------
// Comandos de compilação:
// rm -rf build
// mkdir build
// cd build
// cmake ..
// make
// --------------------------------------------------------------------------
// Comando para executar:
// ./reservatorio_01
// --------------------------------------------------------------------------

#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QMessageBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QValueAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QGroupBox>
#include <QGraphicsSvgItem>
#include <QIcon>
#include <QByteArray>
#include <QBuffer>
#include <QDialog>
#include <QTextStream>
#include <cmath>
#include <algorithm>

QT_CHARTS_USE_NAMESPACE

// ====================================================================
// CLASSE RESERVATORIO: MODELO DE FÍSICA E ENGENHARIA
// ====================================================================

class Reservatorio {
public:
    // Variáveis de Estado do Reservatório
    double pressao_psi;
    double temperatura_C;
    double volume_oleo_bbl;
    double volume_gas_m3;
    double volume_agua_bbl;

    // Propriedades Derivadas (Calculadas em cada passo)
    double viscosidade_oleo_cp;
    double vazao_oleo_bopd;
    double pressao_de_bolha_psi;
    double pressao_poco_psi;
    bool em_emergencia;
    double gas_oil_ratio;
    double water_oil_ratio;
    double tempo_simulacao_s;

    // Constantes do Reservatório
    const double GRAVIDADE_GAS_PESO_AR = 0.7;
    const double GRAVIDADE_API = 27.0;
    const double PRODUTIVIDADE_POCO_C = 1000.0;
    const double FATOR_INJECAO_GAS_BASE = 0.05;
    const double FATOR_INJECAO_AGUA_BASE = 0.01;
    const double PRODUCAO_MINIMA_ACEITAVEL_BOPD = 500.0;

    // Limites de Segurança Críticos
    const double LIMITE_PRESSAO_CRITICO_MIN = 1800.0;
    const double LIMITE_PRESSAO_CRITICO_MAX = 6500.0;
    const double LIMITE_VISCOSIDADE_CRITICO = 6.0;
    const double LIMITE_GAS_CRITICO = 10000.0;
    const double LIMITE_WOR_CRITICO = 0.5;
    const double LIMITE_GOR_CRITICO = 2000.0;

    // Construtor
    Reservatorio() :
        pressao_psi(3500.0), // valor seguro no meio do range (1800-6500)
        temperatura_C(80.0), // temperatura mais baixa para reduzir viscosidade
        volume_oleo_bbl(1000000.0),
        volume_gas_m3(5000.0), // valor inicial moderado (limite: 10000)
        volume_agua_bbl(50000.0), // volume inicial de água
        viscosidade_oleo_cp(2.5), // valor inicial que será recalculado
        vazao_oleo_bopd(1200.0), // acima do mínimo aceitável (500)
        pressao_de_bolha_psi(2800.0), // ajustada para ser menor que pressão inicial
        pressao_poco_psi(400.0), // pressão do poço menor que reservatório
        em_emergencia(false),
        gas_oil_ratio(300.0), // valor moderado (limite: 2000)
        water_oil_ratio(0.1), // valor baixo (limite: 0.5)
        tempo_simulacao_s(0.0) {}

    // Métodos de Cálculo e Simulação
    double calcularSolubilidadeGas(double pressao_psi, double temperatura_C) {
        double temp_F = 1.8 * temperatura_C + 32.0;
        double resultado = GRAVIDADE_GAS_PESO_AR * pow((pressao_psi / 18.2) * exp(0.0125 * GRAVIDADE_API * exp(0.0011 * temp_F)), 1.2045);
        return resultado;
    }

    double calcularViscosidadeOleo(double pressao_psi, double temperatura_C) {
        // Fórmula simplificada para garantir valores realistas
        double rs = calcularSolubilidadeGas(pressao_psi, temperatura_C);
        double temp_F = 1.8 * temperatura_C + 32.0;
        
        // Viscosidade base ajustada para valores típicos de reservatórios
        double viscosidade_base = 3.0; // cp - valor típico
        
        // Ajuste por temperatura (viscosidade diminui com temperatura)
        double fator_temp = 1.0 - (temperatura_C - 60.0) / 200.0;
        fator_temp = std::max(0.5, std::min(2.0, fator_temp));
        
        // Ajuste por pressão (pequeno efeito)
        double fator_pressao = 1.0 + (pressao_psi - 3000.0) / 10000.0;
        fator_pressao = std::max(0.8, std::min(1.2, fator_pressao));
        
        double resultado = viscosidade_base * fator_temp * fator_pressao;
        
        // Garantir que não exceda o limite crítico
        return std::min(resultado, LIMITE_VISCOSIDADE_CRITICO - 0.5);
    }

    double calcularVazaoProducao(double pressao_reservatorio_psi) {
        double q_max = PRODUTIVIDADE_POCO_C;
        if (pressao_reservatorio_psi >= pressao_de_bolha_psi) {
            double ratio = pressao_poco_psi / pressao_reservatorio_psi;
            return q_max * (1 - 0.2 * ratio - 0.8 * pow(ratio, 2));
        } else {
            double ratio_bub = pressao_poco_psi / pressao_de_bolha_psi;
            double aof_pb = q_max * (1 - 0.2 * ratio_bub - 0.8 * pow(ratio_bub, 2));
            double slope = (aof_pb - (q_max / 1.8)) / (pressao_de_bolha_psi - 0);
            return slope * pressao_reservatorio_psi;
        }
    }

    void simularEfeitoProducao(double tempo_passado_s) {
        if (em_emergencia) {
            vazao_oleo_bopd = 0.0;
            return;
        }
        vazao_oleo_bopd = calcularVazaoProducao(pressao_psi);
        double oleo_produzido_bbl = vazao_oleo_bopd * (tempo_passado_s / 86400.0);
        volume_oleo_bbl -= oleo_produzido_bbl;
        if (volume_oleo_bbl < 0) volume_oleo_bbl = 0;
        pressao_psi -= 0.1 * oleo_produzido_bbl / 1000.0;
        if (pressao_psi < 0) pressao_psi = 0;
        if (pressao_psi < pressao_de_bolha_psi) {
            volume_gas_m3 += oleo_produzido_bbl * 100.0;
        }
        simularConing();
        double agua_produzida_bbl = oleo_produzido_bbl * water_oil_ratio;
        volume_oleo_bbl -= agua_produzida_bbl;
        volume_agua_bbl -= agua_produzida_bbl;
        if (volume_oleo_bbl < 0) volume_oleo_bbl = 0;
        double gas_produzido_scfd = vazao_oleo_bopd * gas_oil_ratio;
        volume_gas_m3 += gas_produzido_scfd / 35.315 * (tempo_passado_s / 86400.0);
    }

    void simularConing() {
        if (pressao_poco_psi < 200) {
            gas_oil_ratio += 50.0;
            if (gas_oil_ratio > LIMITE_GOR_CRITICO) gas_oil_ratio = LIMITE_GOR_CRITICO;
            water_oil_ratio += 0.01;
            if (water_oil_ratio > LIMITE_WOR_CRITICO) water_oil_ratio = LIMITE_WOR_CRITICO;
        } else {
            gas_oil_ratio = std::max(100.0, gas_oil_ratio - 1.0);
            water_oil_ratio = std::max(0.0, water_oil_ratio - 0.001);
        }
    }

    void atualizarEstado(double tempo_passado_s) {
        viscosidade_oleo_cp = calcularViscosidadeOleo(pressao_psi, temperatura_C);
        simularEfeitoProducao(tempo_passado_s);
        verificarEmergencia();
        tempo_simulacao_s += tempo_passado_s;
    }

    void verificarEmergencia() {
        em_emergencia = false;
        em_emergencia = (
            pressao_psi < LIMITE_PRESSAO_CRITICO_MIN ||
            pressao_psi > LIMITE_PRESSAO_CRITICO_MAX ||
            viscosidade_oleo_cp > LIMITE_VISCOSIDADE_CRITICO ||
            volume_gas_m3 > LIMITE_GAS_CRITICO ||
            water_oil_ratio > LIMITE_WOR_CRITICO ||
            gas_oil_ratio > LIMITE_GOR_CRITICO
        );
    }

    // Métodos de Intervenção
    void injetarAgua(double volume_bbl, double temp_inj_C) {
        volume_agua_bbl += volume_bbl;
        double fator_temp_pressao = 1.0 + (temp_inj_C - temperatura_C) / 100.0;
        pressao_psi += volume_bbl * FATOR_INJECAO_AGUA_BASE * fator_temp_pressao;
        temperatura_C += volume_bbl * 0.00001 * (temp_inj_C - temperatura_C) / volume_oleo_bbl;
    }

    void injetarGas(double volume_m3, double densidade_gas_ar) {
        volume_gas_m3 += volume_m3;
        double fator_densidade_pressao = 1.0 + (densidade_gas_ar - GRAVIDADE_GAS_PESO_AR) * 0.5;
        pressao_psi += volume_m3 * FATOR_INJECAO_GAS_BASE * fator_densidade_pressao;
    }

    void injetarVapor(double tempo_inundacao_s) {
        temperatura_C += tempo_inundacao_s * 0.1;
        temperatura_C = std::min(200.0, temperatura_C);
    }

    void liberarGasParaQueima(double vazao_scfd) {
        double gas_queimado_m3 = vazao_scfd / 35.315 * (1.0 / 86400.0);
        volume_gas_m3 -= gas_queimado_m3;
        volume_gas_m3 = std::max(0.0, volume_gas_m3);
        pressao_psi -= vazao_scfd * 0.0001;
        pressao_psi = std::max(0.0, pressao_psi);
    }

    void ajustarPressaoPoco(double ajuste_psi) {
        pressao_poco_psi += ajuste_psi;
        pressao_poco_psi = std::max(100.0, std::min(1000.0, pressao_poco_psi));
    }
};

// ====================================================================
// ESTRUTURA PARA DADOS DE LOG (sem custos)
// ====================================================================

struct DadosPontos {
    double tempo_min;
    double vazao_oleo;
    double pressao;
    double viscosidade_cp;
    double volume_oleo;
    double temperatura;
    double gor;
    double wor;
};

// ====================================================================
// CLASSE REPORTDIALOG: GERA E EXIBE RELATÓRIOS EM UMA NOVA JANELA
// ====================================================================

class ReportDialog : public QDialog {
    Q_OBJECT

public:
    ReportDialog(Reservatorio* reservatorio, const QVector<DadosPontos>& dataPoints, QWidget* parent = nullptr) : QDialog(parent) {
        setWindowTitle("Relatório Operacional");
        setMinimumSize(800, 600);
        QVBoxLayout* mainLayout = new QVBoxLayout(this);

        reportTextEdit = new QTextEdit(this);
        reportTextEdit->setReadOnly(true);
        reportTextEdit->setStyleSheet("background-color: #f0f0f0; color: #333; font-family: monospace;");
        mainLayout->addWidget(reportTextEdit);

        QPushButton* closeButton = new QPushButton("Fechar", this);
        mainLayout->addWidget(closeButton);

        connect(closeButton, &QPushButton::clicked, this, &ReportDialog::accept);

        generateReports(reservatorio, dataPoints);
    }

private:
    QTextEdit* reportTextEdit;

    void generateReports(Reservatorio* reservatorio, const QVector<DadosPontos>& dataPoints) {
        QString reportHtml;

        // --- Relatório Operacional ---
        reportHtml += "<h2 style='color:#0056b3;'>Relatório Operacional</h2>";
        reportHtml += "<hr style='border: 1px solid #0056b3;'>";
        reportHtml += "<table>";
        reportHtml += QString("<tr><td><b>Vazão de Óleo (atual):</b></td><td>%1 bopd</td></tr>").arg(QString::number(reservatorio->vazao_oleo_bopd, 'f', 2));
        reportHtml += QString("<tr><td><b>Pressão do Reservatório:</b></td><td>%1 psi</td></tr>").arg(QString::number(reservatorio->pressao_psi, 'f', 2));
        reportHtml += QString("<tr><td><b>Temperatura do Reservatório:</b></td><td>%1 °C</td></tr>").arg(QString::number(reservatorio->temperatura_C, 'f', 2));
        reportHtml += QString("<tr><td><b>Viscosidade do Óleo:</b></td><td>%1 cp</td></tr>").arg(QString::number(reservatorio->viscosidade_oleo_cp, 'f', 2));
        reportHtml += QString("<tr><td><b>GOR (Gás-Óleo Ratio):</b></td><td>%1</td></tr>").arg(QString::number(reservatorio->gas_oil_ratio, 'f', 2));
        reportHtml += QString("<tr><td><b>WOR (Água-Óleo Ratio):</b></td><td>%1</td></tr>").arg(QString::number(reservatorio->water_oil_ratio, 'f', 2));
        reportHtml += QString("<tr><td><b>Status do Sistema:</b></td><td><b>%1</b></td></tr>").arg(reservatorio->em_emergencia ? "<span style='color:red;'>EMERGÊNCIA</span>" : "<span style='color:green;'>Operação Normal</span>");
        reportHtml += "</table>";

        reportTextEdit->setHtml(reportHtml);
    }
};

// ====================================================================
// CLASSE PRINCIPAL DA APLICAÇÃO (WIDGET PRINCIPAL)
// ====================================================================

class SimuladorWindow : public QMainWindow {
    Q_OBJECT

public:
    SimuladorWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        // Inicializa o reservatório e o temporizador
        reservatorio = new Reservatorio();
        simulationTimer = new QTimer(this);
        connect(simulationTimer, &QTimer::timeout, this, &SimuladorWindow::gameLoop);

        // Inicializa a interface
        setupUI();
        setupCharts();

        // Inicia a simulação após a interface estar pronta
        QTimer::singleShot(100, this, [this]() {
            simulationTimer->start(1000); // 1 segundo
            logMessage("Simulação de plataforma de petróleo iniciada.");
        });
    }

    ~SimuladorWindow() {
        // Para o timer antes de destruir os objetos
        if (simulationTimer && simulationTimer->isActive()) {
            simulationTimer->stop();
        }
        delete reservatorio;
    }

private slots:
    // Slot para o loop da simulação
    void gameLoop() {
        if (reservatorio->volume_oleo_bbl <= 0) {
            logMessage("Reservatório esgotado. Fim da vida útil do campo.", "critico");
            // simulationTimer->stop();
            // return;
        }

        if (isProducing) {
            reservatorio->atualizarEstado(1.0);
        } else {
            // Remove a chamada para simularPrecoPetroleo()
            reservatorio->verificarEmergencia();
            reservatorio->tempo_simulacao_s += 1.0;
        }

        // Salvar dados a cada 5 segundos para um log mais detalhado
        if (static_cast<int>(reservatorio->tempo_simulacao_s) % 5 == 0) {
            saveDataPoint();
        }

        // Verificar e exibir alertas e sugestões
        if (reservatorio->em_emergencia) {
            logMessage("ALERTA CRÍTICO: Shutdown Automático!", "critico");
            suggestInputWater->setPlaceholderText("Emergência");
            suggestInputGas->setPlaceholderText("Emergência");
            suggestInputVapor->setPlaceholderText("Emergência");
            suggestInputFlare->setPlaceholderText("Emergência");
            inputTempAgua->setPlaceholderText("Emergência");
            inputDensidadeGas->setPlaceholderText("Emergência");
            suggestionExplanationLabel->setText("O sistema está em estado de emergência e todas as ações foram bloqueadas por segurança. A produção foi interrompida.");
        } else {
            suggestInterventions();
            if (reservatorio->pressao_psi < 2500) {
                logMessage("AVISO: Pressão do reservatório em declínio. Injeção de água ou gás pode ser necessária.", "alerta");
            } else if (reservatorio->viscosidade_oleo_cp > 4.0) {
                logMessage("AVISO: Viscosidade do óleo alta. Injeção de vapor ou água quente pode ser necessária.", "alerta");
            }
        }
        updateUI();
        updateIcons(); // Chamada para atualizar os ícones SCADA
    }

    void onActionButtonClicked() {
        QPushButton* button = qobject_cast<QPushButton*>(sender());
        if (!button) return;

        if (reservatorio->em_emergencia) {
            QMessageBox::warning(this, "Erro", "O sistema de emergência está ativo. Intervenções estão bloqueadas.");
            return;
        }

        QString buttonName = button->objectName();
        bool ok;

        if (buttonName == "inj_agua_btn") {
            double volume = suggestInputWater->text().toDouble(&ok);
            double temp = inputTempAgua->text().toDouble(&ok);
            if (ok) {
                reservatorio->injetarAgua(volume, temp);
                logMessage(QString("Injetando %1 bbl de água a %2°C.").arg(volume).arg(temp), "acao");
            } else {
                QMessageBox::warning(this, "Erro de Entrada", "Por favor, insira valores numéricos para a injeção de água e temperatura.");
            }
        } else if (buttonName == "inj_gas_btn") {
            double volume = suggestInputGas->text().toDouble(&ok);
            double densidade = inputDensidadeGas->text().toDouble(&ok);
            if (ok) {
                reservatorio->injetarGas(volume, densidade);
                logMessage(QString("Injetando %1 m³ de gás com densidade de %2.").arg(volume).arg(densidade), "acao");
            } else {
                QMessageBox::warning(this, "Erro de Entrada", "Por favor, insira valores numéricos para a injeção de gás e densidade.");
            }
        } else if (buttonName == "inj_vapor_btn") {
            double tempo = suggestInputVapor->text().toDouble(&ok);
            if (ok) {
                reservatorio->injetarVapor(tempo);
                logMessage(QString("Injetando vapor por %1 segundos.").arg(tempo), "acao");
            } else {
                QMessageBox::warning(this, "Erro de Entrada", "Por favor, insira um valor numérico para a injeção de vapor.");
            }
        } else if (buttonName == "flare_btn") {
            double vazao = suggestInputFlare->text().toDouble(&ok);
            if (ok) {
                reservatorio->liberarGasParaQueima(vazao);
                logMessage(QString("Acionando flare com vazão de %1 scfd.").arg(vazao), "acao");
            } else {
                QMessageBox::warning(this, "Erro de Entrada", "Por favor, insira um valor numérico para a vazão do flare.");
            }
        } else if (buttonName == "abrir_valv_btn") {
            reservatorio->ajustarPressaoPoco(-50.0);
            logMessage("Abrindo a válvula de choke. Aumento de vazão esperado.", "acao");
        } else if (buttonName == "fechar_valv_btn") {
            reservatorio->ajustarPressaoPoco(50.0);
            logMessage("Fechando a válvula de choke. Redução de vazão esperada.", "acao");
        } else if (buttonName == "parar_prod_btn") {
            isProducing = false;
            logMessage("Produção interrompida para manutenção.", "critico");
        } else if (buttonName == "iniciar_prod_btn") {
            isProducing = true;
            logMessage("Produção retomada.", "acao");
        }
    }

    void onGenerateReportsClicked() {
        ReportDialog dialog(reservatorio, dataPoints, this);
        dialog.exec();
    }

    void onDownloadCSVClicked() {
        if (dataPoints.isEmpty()) {
            QMessageBox::warning(this, "Erro", "Nenhum dado para baixar. A simulação ainda não gerou pontos.");
            return;
        }

        QString fileName = "simulacao_petroleo.csv";
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            // Removida a coluna de preço
            out << "tempo_min,vazao_oleo_bopd,pressao_psi,viscosidade_cp,volume_oleo_bbl,temperatura_C,GOR,WOR\n";
            for (const auto& point : dataPoints) {
                out << point.tempo_min << ","
                    << QString::number(point.vazao_oleo, 'f', 2) << ","
                    << QString::number(point.pressao, 'f', 2) << ","
                    << QString::number(point.viscosidade_cp, 'f', 2) << ","
                    << QString::number(point.volume_oleo, 'f', 2) << ","
                    << QString::number(point.temperatura, 'f', 2) << ","
                    << QString::number(point.gor, 'f', 2) << ","
                    << QString::number(point.wor, 'f', 2) << "\n";
            }
            file.close();
            QMessageBox::information(this, "Sucesso", "Arquivo CSV baixado com sucesso!");
        } else {
            QMessageBox::critical(this, "Erro", "Não foi possível abrir o arquivo para escrita.");
        }
    }

private:
    // Variáveis de estado
    Reservatorio* reservatorio;
    bool isProducing = true;
    QTimer* simulationTimer;
    QVector<DadosPontos> dataPoints;

    // Elementos da interface
    QVector<QLabel*> indicatorLabels;
    QTextEdit* logTextEdit;
    QLineEdit* suggestInputWater;
    QLineEdit* inputTempAgua;
    QLineEdit* suggestInputGas;
    QLineEdit* inputDensidadeGas;
    QLineEdit* suggestInputVapor;
    QLineEdit* suggestInputFlare;
    QLabel* suggestionExplanationLabel;

    // Gráficos
    QLineSeries *producaoSeries;
    QLineSeries *minProducaoSeries;
    QLineSeries *pressaoSeries;
    QLineSeries *volumeOleoSeries;
    QLineSeries *temperaturaSeries;
    QLineSeries *viscosidadeSeries;
    QLineSeries *gorSeries;
    QLineSeries *worSeries;

    // Novos elementos para os ícones SCADA
    QLabel* pressaoIconLabel;
    QLabel* temperaturaIconLabel;
    QLabel* vazaoIconLabel;
    QLabel* gorIconLabel;
    QLabel* statusIconLabel;

    // Estilização dos ícones SVG
    const QString svgTemplate = "<svg xmlns='http://www.w3.org/2000/svg' width='48' height='48' viewBox='0 0 24 24'><path fill='%1' d='%2'/></svg>";
    const QString iconPressaoPath = "M12 2a10 10 0 1 0 10 10A10 10 0 0 0 12 2zm0 18a8 8 0 1 1 8-8 8 8 0 0 1-8 8zM12 4a1.5 1.5 0 0 1 1.5 1.5V12a1.5 1.5 0 0 1-3 0V5.5A1.5 1.5 0 0 1 12 4zM12 12a1 1 0 1 1 1-1 1 1 0 0 1-1 1z'/>";
    const QString iconTemperaturaPath = "M12 3a3 3 0 0 0-3 3v5a5 5 0 0 0 5 5h1a5 5 0 0 0 5-5V6a3 3 0 0 0-3-3zm0 2h3a1 1 0 0 1 1 1v5a3 3 0 0 1-3 3h-1a3 3 0 0 1-3-3V6a1 1 0 0 1 1-1zM10 17v5h4v-5z'/>";
    const QString iconVazaoPath = "M12 2a10 10 0 1 0 10 10A10 10 0 0 0 12 2zm0 18a8 8 0 1 1 8-8 8 8 0 0 1-8 8zm0-12a4 4 0 1 0 4 4 4 4 0 0 0-4-4z'/>";
    const QString iconGorPath = "M12 2a10 10 0 1 0 10 10A10 10 0 0 0 12 2zm0 18a8 8 0 1 1 8-8 8 8 0 0 1-8 8zM12 6a1 1 0 0 1 1 1v5a1 1 0 0 1-2 0V7a1 1 0 0 1 1-1zM12 14a1 1 0 1 1 1-1 1 1 0 0 1-1 1z'/>";
    const QString iconStatusPath = "M12 2a10 10 0 1 0 10 10A10 10 0 0 0 12 2z'/>";

    QIcon createIcon(const QString& color, const QString& path) {
        QString svg = svgTemplate.arg(color, path);
        QByteArray data(svg.toUtf8());
        QBuffer buffer(&data);
        QIcon icon;
        QSize size(48, 48);
        icon.addPixmap(QPixmap::fromImage(QImage::fromData(data, "SVG")), QIcon::Normal, QIcon::On);
        return icon;
    }

    void setupUI() {
        setWindowTitle("Simulador de Plataforma de Petróleo (Qt)");
        setMinimumSize(1200, 800);

        QWidget* centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);
        QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);

        // Seção de Ícones SCADA
        QHBoxLayout* scadaIconsLayout = new QHBoxLayout();
        scadaIconsLayout->setAlignment(Qt::AlignCenter);

        pressaoIconLabel = new QLabel("Pressão");
        pressaoIconLabel->setToolTip("Status da Pressão do Reservatório");
        pressaoIconLabel->setStyleSheet("color: #fff;");
        scadaIconsLayout->addWidget(pressaoIconLabel);

        temperaturaIconLabel = new QLabel("Temperatura");
        temperaturaIconLabel->setToolTip("Status da Temperatura do Reservatório");
        temperaturaIconLabel->setStyleSheet("color: #fff;");
        scadaIconsLayout->addWidget(temperaturaIconLabel);

        vazaoIconLabel = new QLabel("Vazão");
        vazaoIconLabel->setToolTip("Status da Vazão de Produção de Óleo");
        vazaoIconLabel->setStyleSheet("color: #fff;");
        scadaIconsLayout->addWidget(vazaoIconLabel);

        gorIconLabel = new QLabel("GOR");
        gorIconLabel->setToolTip("Status do Gás-Óleo Ratio");
        gorIconLabel->setStyleSheet("color: #fff;");
        scadaIconsLayout->addWidget(gorIconLabel);

        statusIconLabel = new QLabel("Sistema");
        statusIconLabel->setToolTip("Status Geral do Sistema");
        statusIconLabel->setStyleSheet("color: #fff;");
        scadaIconsLayout->addWidget(statusIconLabel);

        mainLayout->addLayout(scadaIconsLayout);

        // Seção de Indicadores (removido 'Preço do Barril')
        QHBoxLayout* indicatorsLayout = new QHBoxLayout();
        QStringList titles = {"Produção de Petróleo", "Pressão do Reservatório", "Volume de Óleo", "Temperatura", "Viscosidade", "GOR", "WOR"};
        for (const QString& title : titles) {
            QVBoxLayout* boxLayout = new QVBoxLayout();
            QLabel* titleLabel = new QLabel(title, this);
            titleLabel->setStyleSheet("font-weight: bold; font-size: 16px;");
            boxLayout->addWidget(titleLabel);
            QLabel* valueLabel = new QLabel("0", this);
            valueLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: yellow;");
            indicatorLabels.append(valueLabel);
            boxLayout->addWidget(valueLabel);
            indicatorsLayout->addLayout(boxLayout);
        }
        mainLayout->addLayout(indicatorsLayout);

        // Seção de Gráficos e Log
        QHBoxLayout* chartsAndLogLayout = new QHBoxLayout();
        QVBoxLayout* chartLayout = new QVBoxLayout();

        producaoSeries = new QLineSeries();
        producaoSeries->setName("Vazão de Óleo (bopd)");
        minProducaoSeries = new QLineSeries();
        minProducaoSeries->setColor(Qt::red);
        minProducaoSeries->setName("Mínimo Aceitável");

        pressaoSeries = new QLineSeries();
        pressaoSeries->setName("Pressão do Reservatório (psi)");

        volumeOleoSeries = new QLineSeries();
        volumeOleoSeries->setName("Volume de Óleo (bbl)");

        temperaturaSeries = new QLineSeries();
        temperaturaSeries->setName("Temperatura (C)");

        viscosidadeSeries = new QLineSeries();
        viscosidadeSeries->setName("Viscosidade (cp)");

        gorSeries = new QLineSeries();
        gorSeries->setName("GOR");

        worSeries = new QLineSeries();
        worSeries->setName("WOR");

        chartLayout->addWidget(createChart("Vazão de Óleo (Nível Operacional)", producaoSeries));
        chartLayout->addWidget(createChart("Pressão do Reservatório (Nível Operacional)", pressaoSeries));
        chartLayout->addWidget(createChart("Volume de Óleo (Nível Gerencial)", volumeOleoSeries));
        chartLayout->addWidget(createChart("Temperatura (Nível Operacional)", temperaturaSeries));
        chartLayout->addWidget(createChart("Viscosidade (Nível Operacional)", viscosidadeSeries));
        chartLayout->addWidget(createChart("GOR e WOR (Nível Operacional)", gorSeries));
        chartLayout->addWidget(createChart("", worSeries));

        chartsAndLogLayout->addLayout(chartLayout, 2);

        logTextEdit = new QTextEdit(this);
        logTextEdit->setReadOnly(true);
        logTextEdit->setStyleSheet("background-color: #333; color: #ccc;");
        chartsAndLogLayout->addWidget(logTextEdit, 1);

        mainLayout->addLayout(chartsAndLogLayout);

        // Seção de Análise e Controles
        QHBoxLayout* controlsLayout = new QHBoxLayout();
        QVBoxLayout* interventionLayout = new QVBoxLayout();

        // Controles de Injeção
        QGroupBox* injectionGroupBox = new QGroupBox("Controles de Intervenção", this);
        QVBoxLayout* injectionLayout = new QVBoxLayout(injectionGroupBox);

        // Injeção de Água
        QHBoxLayout* waterLayout = new QHBoxLayout();
        QLabel* waterLabel = new QLabel("Volume Água (bbl):");
        suggestInputWater = new QLineEdit("1000");
        suggestInputWater->setValidator(new QDoubleValidator(this));
        QLabel* tempLabel = new QLabel("Temp (°C):");
        inputTempAgua = new QLineEdit("100");
        inputTempAgua->setValidator(new QDoubleValidator(this));
        QPushButton* waterBtn = new QPushButton("Injetar Água");
        waterBtn->setObjectName("inj_agua_btn");
        waterLayout->addWidget(waterLabel);
        waterLayout->addWidget(suggestInputWater);
        waterLayout->addWidget(tempLabel);
        waterLayout->addWidget(inputTempAgua);
        waterLayout->addWidget(waterBtn);
        injectionLayout->addLayout(waterLayout);

        // Injeção de Gás
        QHBoxLayout* gasLayout = new QHBoxLayout();
        QLabel* gasLabel = new QLabel("Volume Gás (m³):");
        suggestInputGas = new QLineEdit("5000");
        suggestInputGas->setValidator(new QDoubleValidator(this));
        QLabel* densidadeLabel = new QLabel("Densidade:");
        inputDensidadeGas = new QLineEdit("0.7");
        inputDensidadeGas->setValidator(new QDoubleValidator(this));
        QPushButton* gasBtn = new QPushButton("Injetar Gás");
        gasBtn->setObjectName("inj_gas_btn");
        gasLayout->addWidget(gasLabel);
        gasLayout->addWidget(suggestInputGas);
        gasLayout->addWidget(densidadeLabel);
        gasLayout->addWidget(inputDensidadeGas);
        gasLayout->addWidget(gasBtn);
        injectionLayout->addLayout(gasLayout);

        // Injeção de Vapor
        QHBoxLayout* vaporLayout = new QHBoxLayout();
        QLabel* vaporLabel = new QLabel("Tempo Vapor (s):");
        suggestInputVapor = new QLineEdit("500");
        suggestInputVapor->setValidator(new QDoubleValidator(this));
        QPushButton* vaporBtn = new QPushButton("Injetar Vapor");
        vaporBtn->setObjectName("inj_vapor_btn");
        vaporLayout->addWidget(vaporLabel);
        vaporLayout->addWidget(suggestInputVapor);
        vaporLayout->addWidget(vaporBtn);
        injectionLayout->addLayout(vaporLayout);

        // Flare
        QHBoxLayout* flareLayout = new QHBoxLayout();
        QLabel* flareLabel = new QLabel("Vazão Flare (scfd):");
        suggestInputFlare = new QLineEdit("5000");
        suggestInputFlare->setValidator(new QDoubleValidator(this));
        QPushButton* flareBtn = new QPushButton("Acionar Flare");
        flareBtn->setObjectName("flare_btn");
        flareLayout->addWidget(flareLabel);
        flareLayout->addWidget(suggestInputFlare);
        flareLayout->addWidget(flareBtn);
        injectionLayout->addLayout(flareLayout);

        // Botões de Produção
        QGroupBox* productionGroupBox = new QGroupBox("Controles de Produção", this);
        QVBoxLayout* productionLayout = new QVBoxLayout(productionGroupBox);
        QHBoxLayout* productionButtonsLayout = new QHBoxLayout();
        QPushButton* startBtn = new QPushButton("Iniciar Produção");
        startBtn->setObjectName("iniciar_prod_btn");
        QPushButton* stopBtn = new QPushButton("Parar Produção");
        stopBtn->setObjectName("parar_prod_btn");
        productionButtonsLayout->addWidget(startBtn);
        productionButtonsLayout->addWidget(stopBtn);
        productionLayout->addLayout(productionButtonsLayout);

        // Botões de Válvula
        QHBoxLayout* valveButtonsLayout = new QHBoxLayout();
        QPushButton* openValveBtn = new QPushButton("Abrir Válvula");
        openValveBtn->setObjectName("abrir_valv_btn");
        QPushButton* closeValveBtn = new QPushButton("Fechar Válvula");
        closeValveBtn->setObjectName("fechar_valv_btn");
        valveButtonsLayout->addWidget(openValveBtn);
        valveButtonsLayout->addWidget(closeValveBtn);
        productionLayout->addLayout(valveButtonsLayout);

        interventionLayout->addWidget(injectionGroupBox);
        interventionLayout->addWidget(productionGroupBox);

        // Seção de Sugestões
        QGroupBox* suggestionGroupBox = new QGroupBox("Sugestões do Sistema", this);
        QVBoxLayout* suggestionLayout = new QVBoxLayout(suggestionGroupBox);
        suggestionExplanationLabel = new QLabel("O sistema fornecerá sugestões de intervenção aqui.");
        suggestionExplanationLabel->setStyleSheet("font-style: italic; color: #777;");
        suggestionExplanationLabel->setWordWrap(true);
        suggestionLayout->addWidget(suggestionExplanationLabel);

        interventionLayout->addWidget(suggestionGroupBox);

        // Botões de Relatório
        QPushButton* reportBtn = new QPushButton("Gerar Relatórios");
        reportBtn->setObjectName("report_btn");
        QPushButton* downloadBtn = new QPushButton("Baixar CSV");
        downloadBtn->setObjectName("download_csv_btn");
        QHBoxLayout* reportButtonsLayout = new QHBoxLayout();
        reportButtonsLayout->addWidget(reportBtn);
        reportButtonsLayout->addWidget(downloadBtn);
        interventionLayout->addLayout(reportButtonsLayout);

        controlsLayout->addLayout(interventionLayout);
        mainLayout->addLayout(controlsLayout);

        // Conecta os botões aos slots
        connect(waterBtn, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(gasBtn, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(vaporBtn, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(flareBtn, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(startBtn, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(stopBtn, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(openValveBtn, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(closeValveBtn, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(reportBtn, &QPushButton::clicked, this, &SimuladorWindow::onGenerateReportsClicked);
        connect(downloadBtn, &QPushButton::clicked, this, &SimuladorWindow::onDownloadCSVClicked);
    }

    // Método para criar um gráfico de linha
    QChartView* createChart(const QString& title, QLineSeries* series) {
        QChart *chart = new QChart();
        chart->setTitle(title);
        chart->legend()->hide();
        chart->addSeries(series);
        chart->setTheme(QChart::ChartThemeDark);

        QValueAxis *axisX = new QValueAxis();
        axisX->setTitleText("Tempo (min)");
        axisX->setLabelFormat("%i");
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setTitleText("Valor");
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        return chartView;
    }

    // Método para configurar todos os gráficos
    void setupCharts() {
        // Nada de especial a ser feito, pois os gráficos já são configurados em createChart
    }

    // Método para atualizar os valores exibidos na interface
    void updateUI() {
        if (indicatorLabels.size() >= 7) {
            indicatorLabels[0]->setText(QString::number(reservatorio->vazao_oleo_bopd, 'f', 2));
            indicatorLabels[1]->setText(QString::number(reservatorio->pressao_psi, 'f', 2));
            indicatorLabels[2]->setText(QString::number(reservatorio->volume_oleo_bbl, 'f', 2));
            indicatorLabels[3]->setText(QString::number(reservatorio->temperatura_C, 'f', 2));
            indicatorLabels[4]->setText(QString::number(reservatorio->viscosidade_oleo_cp, 'f', 2));
            indicatorLabels[5]->setText(QString::number(reservatorio->gas_oil_ratio, 'f', 2));
            indicatorLabels[6]->setText(QString::number(reservatorio->water_oil_ratio, 'f', 2));
        }

        // Atualizar os gráficos
        double tempo_min = reservatorio->tempo_simulacao_s / 60.0;
        producaoSeries->append(tempo_min, reservatorio->vazao_oleo_bopd);
        pressaoSeries->append(tempo_min, reservatorio->pressao_psi);
        volumeOleoSeries->append(tempo_min, reservatorio->volume_oleo_bbl);
        temperaturaSeries->append(tempo_min, reservatorio->temperatura_C);
        viscosidadeSeries->append(tempo_min, reservatorio->viscosidade_oleo_cp);
        gorSeries->append(tempo_min, reservatorio->gas_oil_ratio);
        worSeries->append(tempo_min, reservatorio->water_oil_ratio);
    }

    // Método para salvar os dados da simulação
    void saveDataPoint() {
        DadosPontos ponto;
        ponto.tempo_min = reservatorio->tempo_simulacao_s / 60.0;
        ponto.vazao_oleo = reservatorio->vazao_oleo_bopd;
        ponto.pressao = reservatorio->pressao_psi;
        ponto.viscosidade_cp = reservatorio->viscosidade_oleo_cp;
        ponto.volume_oleo = reservatorio->volume_oleo_bbl;
        ponto.temperatura = reservatorio->temperatura_C;
        ponto.gor = reservatorio->gas_oil_ratio;
        ponto.wor = reservatorio->water_oil_ratio;
        dataPoints.append(ponto);
    }

    // Método para logar mensagens na caixa de texto
    void logMessage(const QString& message, const QString& type = "info") {
        QString styledMessage;
        if (type == "acao") {
            styledMessage = QString("<span style='color: #4CAF50;'>[AÇÃO] %1</span>").arg(message);
        } else if (type == "alerta") {
            styledMessage = QString("<span style='color: #FFC107;'>[AVISO] %1</span>").arg(message);
        } else if (type == "critico") {
            styledMessage = QString("<span style='color: #F44336;'>[CRÍTICO] %1</span>").arg(message);
        } else {
            styledMessage = QString("<span style='color: #888;'>[INFO] %1</span>").arg(message);
        }
        logTextEdit->append(styledMessage);
    }

    // Método para sugerir intervenções com base no estado do reservatório
    void suggestInterventions() {
        QString suggestion = "Sugestões de intervenção:\n";
        bool hasSuggestion = false;

        if (reservatorio->pressao_psi < 2500) {
            suggestion += "- Pressão baixa: considere injetar água ou gás.\n";
            suggestInputWater->setText("5000");
            suggestInputGas->setText("10000");
            hasSuggestion = true;
        }

        if (reservatorio->viscosidade_oleo_cp > 4.0) {
            suggestion += "- Viscosidade alta: considere injetar vapor para aquecer o óleo.\n";
            suggestInputVapor->setText("1000");
            hasSuggestion = true;
        }

        if (reservatorio->volume_gas_m3 > 8000) {
            suggestion += "- Volume de gás alto: considere liberar gás para queima (flare).\n";
            suggestInputFlare->setText("8000");
            hasSuggestion = true;
        }

        if (!hasSuggestion) {
            suggestionExplanationLabel->setText("O sistema está em condições operacionais normais. Nenhuma intervenção é sugerida no momento.");
            suggestInputWater->setPlaceholderText("Volume Água (bbl)");
            suggestInputGas->setPlaceholderText("Volume Gás (m³)");
            suggestInputVapor->setPlaceholderText("Tempo Vapor (s)");
            suggestInputFlare->setPlaceholderText("Vazão Flare (scfd)");
        } else {
            suggestionExplanationLabel->setText(suggestion);
        }
    }

    // Método para atualizar os ícones de status SCADA
    void updateIcons() {
        // Ícone de Pressão
        QString pressaoColor = (reservatorio->pressao_psi < reservatorio->LIMITE_PRESSAO_CRITICO_MIN || reservatorio->pressao_psi > reservatorio->LIMITE_PRESSAO_CRITICO_MAX) ? "red" : "green";
        pressaoIconLabel->setPixmap(createIcon(pressaoColor, iconPressaoPath).pixmap(48, 48));

        // Ícone de Temperatura
        QString temperaturaColor = (reservatorio->temperatura_C > 180.0) ? "red" : ((reservatorio->temperatura_C > 150.0) ? "orange" : "green");
        temperaturaIconLabel->setPixmap(createIcon(temperaturaColor, iconTemperaturaPath).pixmap(48, 48));

        // Ícone de Vazão
        QString vazaoColor = (reservatorio->vazao_oleo_bopd < reservatorio->PRODUCAO_MINIMA_ACEITAVEL_BOPD) ? "orange" : "green";
        vazaoIconLabel->setPixmap(createIcon(vazaoColor, iconVazaoPath).pixmap(48, 48));

        // Ícone de GOR
        QString gorColor = (reservatorio->gas_oil_ratio > reservatorio->LIMITE_GOR_CRITICO) ? "red" : "green";
        gorIconLabel->setPixmap(createIcon(gorColor, iconGorPath).pixmap(48, 48));

        // Ícone de Status Geral
        QString statusColor = reservatorio->em_emergencia ? "red" : "green";
        statusIconLabel->setPixmap(createIcon(statusColor, iconStatusPath).pixmap(48, 48));
    }
};

#include "main.moc"

int main(int argc, char *argv[]) {
    // Configura atributos Qt antes de criar QApplication
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling, true);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps, true);
    
    QApplication a(argc, argv);
    
    // Configura o nome da aplicação para Qt
    a.setApplicationName("Simulador de Plataforma de Petroleo");
    a.setApplicationVersion("1.0");
    
    SimuladorWindow w;
    w.show();
    
    // Garante que a janela seja completamente mostrada antes de continuar
    a.processEvents();
    
    return a.exec();
}
