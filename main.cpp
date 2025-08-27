
// --------------------------------------------------------------------------
// simulador.cpp
// Simulação de plataforma de petróleo com interface gráfica Qt.
// Esta versão inclui um painel de análise econômica detalhada e a
// capacidade de gerar relatórios operacionais e gerenciais.
// --------------------------------------------------------------------------


// --------------------------------------------------------------------------
// sudo apt install libqt5charts5-dev
// sudo apt install cmake make
// sudo apt install libqt5svg5-dev

// sudo apt install libqt5charts5-dev libqt5svg5-dev

//sudo apt update
//sudo apt install qtbase5-dev libqt5widgets5 libqt5charts5-dev libqt5svg5-dev

// rm -rf build
// mkdir build
// cd build
// cmake ..
// make
// --------------------------------------------------------------------------
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
// CLASSE RESERVATORIO: MODELO DE FÍSICA, ENGENHARIA E ECONOMIA
// ====================================================================

class Reservatorio {
public:
    // Variáveis de Estado do Reservatório
    double pressao_psi;
    double temperatura_C;
    double volume_oleo_bbl;
    double volume_gas_m3;
    double volume_agua_bbl;
    double preco_barril_usd;
    double receita_total_usd;
    double custo_total_usd;
    
    // Custos detalhados
    double custo_injecao_agua_total;
    double custo_injecao_gas_total;
    double custo_injecao_vapor_total;
    
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
    
    // Constantes de Custo
    const double CUSTO_FIXO_DIARIO_USD = 50000.0;
    const double CUSTO_INJECAO_AGUA_USD_BBL = 0.1;
    const double CUSTO_INJECAO_GAS_USD_M3 = 0.5;
    const double CUSTO_INJECAO_VAPOR_USD_S = 1000.0;

    // Construtor
    Reservatorio() :
        pressao_psi(5000.0), // entre 1800 e 6500
        temperatura_C(90.0),
        volume_oleo_bbl(1000000.0),
        volume_gas_m3(0.0), // menor que 10000
        volume_agua_bbl(0.0),
        preco_barril_usd(80.0),
        receita_total_usd(0.0),
        custo_total_usd(0.0),
        custo_injecao_agua_total(0.0),
        custo_injecao_gas_total(0.0),
        custo_injecao_vapor_total(0.0),
        viscosidade_oleo_cp(2.0), // menor que 6.0
        vazao_oleo_bopd(1000.0),
        pressao_de_bolha_psi(3000.0),
        pressao_poco_psi(500.0),
        em_emergencia(false),
        gas_oil_ratio(100.0), // menor que 2000
        water_oil_ratio(0.0), // menor que 0.5
        tempo_simulacao_s(0.0) {}

    // Métodos de Cálculo e Simulação
    double calcularSolubilidadeGas(double pressao_psi, double temperatura_C) {
        double temp_F = 1.8 * temperatura_C + 32.0;
        double resultado = GRAVIDADE_GAS_PESO_AR * pow((pressao_psi / 18.2) * exp(0.0125 * GRAVIDADE_API * exp(0.0011 * temp_F)), 1.2045);
        return resultado;
    }

    double calcularViscosidadeOleo(double pressao_psi, double temperatura_C) {
        double rs = calcularSolubilidadeGas(pressao_psi, temperatura_C);
        double temp_F = 1.8 * temperatura_C + 32.0;
        double a = 1.0531e-1 * pow(rs, 0.8) - 1.134e-3 * GRAVIDADE_API + 1.258e-2 * temp_F + 3.123e-4 * GRAVIDADE_API * temp_F;
        double b = 1.2023 - 8.356e-3 * GRAVIDADE_API;
        double log10_mu_saturado = pow(10, a);
        double log10_mu_dessaturado = pow(10, b) / rs;
        return log10_mu_saturado * exp(log10_mu_dessaturado * rs);
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

    void atualizarEconomia(double tempo_passado_s) {
        double dias_passados = tempo_passado_s / 86400.0;
        receita_total_usd += vazao_oleo_bopd * dias_passados * preco_barril_usd;
        custo_total_usd = (CUSTO_FIXO_DIARIO_USD * dias_passados) + custo_injecao_agua_total + custo_injecao_gas_total + custo_injecao_vapor_total;
    }

    void simularPrecoPetroleo() {
        double random = (static_cast<double>(rand()) / RAND_MAX - 0.5) * 1;
        preco_barril_usd += random;
        preco_barril_usd = std::max(40.0, std::min(120.0, preco_barril_usd));
    }

    // ???
    void atualizarEstado(double tempo_passado_s) {
        viscosidade_oleo_cp = calcularViscosidadeOleo(pressao_psi, temperatura_C);
        simularEfeitoProducao(tempo_passado_s);
        atualizarEconomia(tempo_passado_s);
        simularPrecoPetroleo();
        verificarEmergencia();
        tempo_simulacao_s += tempo_passado_s;
    }

    // ???
    void verificarEmergencia() {
        em_emergencia = false;
        // em_emergencia = (
        //     pressao_psi < LIMITE_PRESSAO_CRITICO_MIN ||
        //     pressao_psi > LIMITE_PRESSAO_CRITICO_MAX ||
        //     viscosidade_oleo_cp > LIMITE_VISCOSIDADE_CRITICO ||
        //     volume_gas_m3 > LIMITE_GAS_CRITICO ||
        //     water_oil_ratio > LIMITE_WOR_CRITICO ||
        //     gas_oil_ratio > LIMITE_GOR_CRITICO
        // );
    }

    // Métodos de Intervenção
    void injetarAgua(double volume_bbl, double temp_inj_C) {
        volume_agua_bbl += volume_bbl;
        double fator_temp_pressao = 1.0 + (temp_inj_C - temperatura_C) / 100.0;
        pressao_psi += volume_bbl * FATOR_INJECAO_AGUA_BASE * fator_temp_pressao;
        // Aumentar temperatura do reservatório com base na injeção
        temperatura_C += volume_bbl * 0.00001 * (temp_inj_C - temperatura_C) / volume_oleo_bbl;
        custo_injecao_agua_total += volume_bbl * CUSTO_INJECAO_AGUA_USD_BBL;
    }

    void injetarGas(double volume_m3, double densidade_gas_ar) {
        volume_gas_m3 += volume_m3;
        double fator_densidade_pressao = 1.0 + (densidade_gas_ar - GRAVIDADE_GAS_PESO_AR) * 0.5;
        pressao_psi += volume_m3 * FATOR_INJECAO_GAS_BASE * fator_densidade_pressao;
        custo_injecao_gas_total += volume_m3 * CUSTO_INJECAO_GAS_USD_M3;
    }

    void injetarVapor(double tempo_inundacao_s) {
        temperatura_C += tempo_inundacao_s * 0.1; 
        temperatura_C = std::min(200.0, temperatura_C);
        custo_injecao_vapor_total += tempo_inundacao_s * CUSTO_INJECAO_VAPOR_USD_S;
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
// ESTRUTURA PARA DADOS DE LOG
// ====================================================================

struct DadosPontos {
    double tempo_min;
    double vazao_oleo;
    double pressao;
    double viscosidade_cp;
    double volume_oleo;
    double preco_barril;
    double receita_total;
    double custo_total;
    double lucro;
    double temperatura;
    double gor;
    double wor;
    double custo_inj_agua;
    double custo_inj_gas;
    double custo_inj_vapor;
};

// ====================================================================
// CLASSE REPORTDIALOG: GERA E EXIBE RELATÓRIOS EM UMA NOVA JANELA
// ====================================================================

class ReportDialog : public QDialog {
    Q_OBJECT

public:
    ReportDialog(Reservatorio* reservatorio, const QVector<DadosPontos>& dataPoints, QWidget* parent = nullptr) : QDialog(parent) {
        setWindowTitle("Relatórios de Desempenho");
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
        
        // --- Relatório Gerencial ---
        reportHtml += "<br><br>";
        reportHtml += "<h2 style='color:#28a745;'>Relatório Gerencial</h2>";
        reportHtml += "<hr style='border: 1px solid #28a745;'>";
        
        double total_producao = 0.0;
        double custo_medio_por_barril = 0.0;
        double tempo_total_dias = reservatorio->tempo_simulacao_s / 86400.0;

        for(const auto& point : dataPoints) {
            total_producao += point.vazao_oleo / (24 * 60) * (point.tempo_min - (point.tempo_min - 1)); // aprox. bbl/min
        }
        
        if (reservatorio->receita_total_usd > 0) {
            custo_medio_por_barril = reservatorio->custo_total_usd / (reservatorio->receita_total_usd / reservatorio->preco_barril_usd);
        }

        reportHtml += "<table>";
        reportHtml += QString("<tr><td><b>Tempo de Simulação:</b></td><td>%1 dias</td></tr>").arg(QString::number(tempo_total_dias, 'f', 2));
        reportHtml += QString("<tr><td><b>Volume de Óleo Remanescente:</b></td><td>%1 bbl</td></tr>").arg(QString::number(reservatorio->volume_oleo_bbl, 'f', 2));
        reportHtml += QString("<tr><td><b>Produção Total Acumulada:</b></td><td>%1 bbl (aproximado)</td></tr>").arg(QString::number(total_producao, 'f', 2));
        reportHtml += QString("<tr><td><b>Receita Total:</b></td><td>$%1</td></tr>").arg(QString::number(reservatorio->receita_total_usd, 'f', 2));
        reportHtml += QString("<tr><td><b>Custo Total:</b></td><td>$%1</td></tr>").arg(QString::number(reservatorio->custo_total_usd, 'f', 2));
        reportHtml += QString("<tr><td><b>Lucro Total:</b></td><td>$%1</td></tr>").arg(QString::number(reservatorio->receita_total_usd - reservatorio->custo_total_usd, 'f', 2));
        reportHtml += QString("<tr><td><b>Custo Médio por Barril:</b></td><td>$%1</td></tr>").arg(QString::number(custo_medio_por_barril, 'f', 2));
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

        // Inicia a simulação
        simulationTimer->start(1000); // 1 segundo
        logMessage("Simulação de plataforma de petróleo iniciada.");
    }

    ~SimuladorWindow() {
        delete reservatorio;
    }

    // ???
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
            reservatorio->atualizarEconomia(1.0);
            reservatorio->simularPrecoPetroleo();
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
            // Limpa as sugestões quando o sistema está em emergência
            suggestInputWater->setPlaceholderText("Emergência");
            suggestInputGas->setPlaceholderText("Emergência");
            suggestInputVapor->setPlaceholderText("Emergência");
            suggestInputFlare->setPlaceholderText("Emergência");
            inputTempAgua->setPlaceholderText("Emergência");
            inputDensidadeGas->setPlaceholderText("Emergência");
            suggestionExplanationLabel->setText("O sistema está em estado de emergência e todas as ações foram bloqueadas por segurança. A produção foi interrompida.");
        } else {
            // Sugere valores de intervenção com base no estado do reservatório
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
            out << "tempo_min,vazao_oleo_bopd,pressao_psi,viscosidade_cp,volume_oleo_bbl,preco_barril,receita_total,custo_total,lucro_total,temperatura_C,GOR,WOR,custo_inj_agua,custo_inj_gas,custo_inj_vapor\n";
            for (const auto& point : dataPoints) {
                out << point.tempo_min << ","
                    << QString::number(point.vazao_oleo, 'f', 2) << ","
                    << QString::number(point.pressao, 'f', 2) << ","
                    << QString::number(point.viscosidade_cp, 'f', 2) << ","
                    << QString::number(point.volume_oleo, 'f', 2) << ","
                    << QString::number(point.preco_barril, 'f', 2) << ","
                    << QString::number(point.receita_total, 'f', 2) << ","
                    << QString::number(point.custo_total, 'f', 2) << ","
                    << QString::number(point.lucro, 'f', 2) << ","
                    << QString::number(point.temperatura, 'f', 2) << ","
                    << QString::number(point.gor, 'f', 2) << ","
                    << QString::number(point.wor, 'f', 2) << ","
                    << QString::number(point.custo_inj_agua, 'f', 2) << ","
                    << QString::number(point.custo_inj_gas, 'f', 2) << ","
                    << QString::number(point.custo_inj_vapor, 'f', 2) << "\n";
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
    
    // Labels de custo detalhados
    QLabel* revenueLabel;
    QLabel* costLabel;
    QLabel* profitLabel;
    QLabel* waterCostLabel;
    QLabel* gasCostLabel;
    QLabel* vaporCostLabel;
    QLabel* fixedCostLabel;

    // Gráficos
    QLineSeries *producaoSeries;
    QLineSeries *minProducaoSeries;
    QLineSeries *pressaoSeries;
    QLineSeries *volumeOleoSeries;
    QLineSeries *lucroSeries;
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

    // Configura a interface do usuário
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

        // Seção de Indicadores
        QHBoxLayout* indicatorsLayout = new QHBoxLayout();
        QStringList titles = {"Produção de Petróleo", "Pressão do Reservatório", "Lucro Total", "Volume de Óleo", "Preço do Barril", "Temperatura", "Viscosidade", "GOR", "WOR"};
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

        lucroSeries = new QLineSeries();
        lucroSeries->setName("Lucro Total (USD)");

        temperaturaSeries = new QLineSeries();
        temperaturaSeries->setName("Temperatura (C)");

        viscosidadeSeries = new QLineSeries();
        viscosidadeSeries->setName("Viscosidade (cp)");

        gorSeries = new QLineSeries();
        gorSeries->setName("GOR");

        worSeries = new QLineSeries();
        worSeries->setName("WOR");

        QChartView* producaoChart = createChart("Vazão de Óleo (Nível Operacional)", producaoSeries);
        producaoChart->chart()->addSeries(minProducaoSeries);
        //producaoChart->chart()->axes(Qt::Horizontal).first()->attachSeries(minProducaoSeries);
        //producaoChart->chart()->axes(Qt::Vertical).first()->attachSeries(minProducaoSeries);

        // minProducaoSeries->attachAxis(producaoChart->chart()->axes(Qt::Horizontal).first());
        // minProducaoSeries->attachAxis(producaoChart->chart()->axes(Qt::Vertical).first());
        //
        // chartLayout->addWidget(producaoChart);
        // chartLayout->addWidget(createChart("Pressão do Reservatório (Nível Operacional)", pressaoSeries));
        // chartLayout->addWidget(createChart("Lucro Total (Nível Gerencial)", lucroSeries));
        // chartLayout->addWidget(createChart("Volume de Óleo (Nível Gerencial)", volumeOleoSeries));
        // chartLayout->addWidget(createChart("Temperatura (Nível Operacional)", temperaturaSeries));
        // chartLayout->addWidget(createChart("Viscosidade (Nível Operacional)", viscosidadeSeries));
        // chartLayout->addWidget(createChart("GOR e WOR (Nível Operacional)", gorSeries));
        // chartLayout->addWidget(createChart("", worSeries));
        // gorSeries->attachAxis(worSeries->chart()->axes(Qt::Horizontal).first());
        // gorSeries->attachAxis(worSeries->chart()->axes(Qt::Vertical).first());
        // worSeries->chart()->addSeries(gorSeries);
        
        chartsAndLogLayout->addLayout(chartLayout, 2);

        logTextEdit = new QTextEdit(this);
        logTextEdit->setReadOnly(true);
        logTextEdit->setStyleSheet("background-color: #333; color: #ccc;");
        chartsAndLogLayout->addWidget(logTextEdit, 1);

        mainLayout->addLayout(chartsAndLogLayout);
        
        // Seção de Controles
        QVBoxLayout* controlsContainerLayout = new QVBoxLayout();
        QHBoxLayout* controlsLayout = new QHBoxLayout();
        
        // Grupo de Análise Econômica
        QGroupBox* economicGroup = new QGroupBox("Análise Econômica Detalhada", this);
        QVBoxLayout* economicLayout = new QVBoxLayout(economicGroup);
        revenueLabel = new QLabel("Receita Total: 0 USD", this);
        costLabel = new QLabel("Custo Total: 0 USD", this);
        profitLabel = new QLabel("Lucro Total: 0 USD", this);
        waterCostLabel = new QLabel("Custo Água: 0 USD", this);
        gasCostLabel = new QLabel("Custo Gás: 0 USD", this);
        vaporCostLabel = new QLabel("Custo Vapor: 0 USD", this);
        fixedCostLabel = new QLabel(QString("Custo Fixo Diário: %1 USD").arg(reservatorio->CUSTO_FIXO_DIARIO_USD), this);

        economicLayout->addWidget(revenueLabel);
        economicLayout->addWidget(costLabel);
        economicLayout->addWidget(profitLabel);
        economicLayout->addWidget(waterCostLabel);
        economicLayout->addWidget(gasCostLabel);
        economicLayout->addWidget(vaporCostLabel);
        economicLayout->addWidget(fixedCostLabel);
        
        controlsLayout->addWidget(economicGroup);
        
        // Grupo de Controles de Injeção
        QGroupBox* injectionGroup = new QGroupBox("Controles de Injeção", this);
        QVBoxLayout* injectionLayout = new QVBoxLayout(injectionGroup);
        
        QHBoxLayout* waterLayout = new QHBoxLayout();
        suggestInputWater = new QLineEdit("500", this);
        suggestInputWater->setValidator(new QDoubleValidator(this));
        inputTempAgua = new QLineEdit("90", this);
        inputTempAgua->setPlaceholderText("Temp. (°C)");
        inputTempAgua->setValidator(new QDoubleValidator(this));
        QPushButton* injWaterButton = new QPushButton("Injetar Água (bbl)", this);
        injWaterButton->setObjectName("inj_agua_btn");
        waterLayout->addWidget(new QLabel("Vol. (bbl):", this));
        waterLayout->addWidget(suggestInputWater);
        waterLayout->addWidget(new QLabel("Temp. (°C):", this));
        waterLayout->addWidget(inputTempAgua);
        waterLayout->addWidget(injWaterButton);
        injectionLayout->addLayout(waterLayout);
        
        QHBoxLayout* gasLayout = new QHBoxLayout();
        suggestInputGas = new QLineEdit("1000", this);
        suggestInputGas->setValidator(new QDoubleValidator(this));
        inputDensidadeGas = new QLineEdit("0.7", this);
        inputDensidadeGas->setPlaceholderText("Dens. (ar=1)");
        inputDensidadeGas->setValidator(new QDoubleValidator(this));
        QPushButton* injGasButton = new QPushButton("Injetar Gás (m³)", this);
        injGasButton->setObjectName("inj_gas_btn");
        gasLayout->addWidget(new QLabel("Vol. (m³):", this));
        gasLayout->addWidget(suggestInputGas);
        gasLayout->addWidget(new QLabel("Dens.:", this));
        gasLayout->addWidget(inputDensidadeGas);
        gasLayout->addWidget(injGasButton);
        injectionLayout->addLayout(gasLayout);

        QHBoxLayout* vaporLayout = new QHBoxLayout();
        suggestInputVapor = new QLineEdit("5", this);
        suggestInputVapor->setValidator(new QDoubleValidator(this));
        QPushButton* injVaporButton = new QPushButton("Injetar Vapor (s)", this);
        injVaporButton->setObjectName("inj_vapor_btn");
        vaporLayout->addWidget(new QLabel("Tempo (s):", this));
        vaporLayout->addWidget(suggestInputVapor);
        vaporLayout->addWidget(injVaporButton);
        injectionLayout->addLayout(vaporLayout);
        
        QHBoxLayout* flareLayout = new QHBoxLayout();
        suggestInputFlare = new QLineEdit("10000", this);
        suggestInputFlare->setValidator(new QDoubleValidator(this));
        QPushButton* flareButton = new QPushButton("Acionar Flare (scfd)", this);
        flareButton->setObjectName("flare_btn");
        flareLayout->addWidget(new QLabel("Vazão (scfd):", this));
        flareLayout->addWidget(suggestInputFlare);
        flareLayout->addWidget(flareButton);
        injectionLayout->addLayout(flareLayout);
        
        controlsLayout->addWidget(injectionGroup);
        
        // Grupo de Controles de Produção
        QGroupBox* productionGroup = new QGroupBox("Controles de Produção", this);
        QVBoxLayout* productionLayout = new QVBoxLayout(productionGroup);
        QPushButton* openChokeButton = new QPushButton("Abrir Válvula", this);
        openChokeButton->setObjectName("abrir_valv_btn");
        QPushButton* closeChokeButton = new QPushButton("Fechar Válvula", this);
        closeChokeButton->setObjectName("fechar_valv_btn");
        QPushButton* stopProductionButton = new QPushButton("Parar Produção", this);
        stopProductionButton->setObjectName("parar_prod_btn");
        QPushButton* startProductionButton = new QPushButton("Iniciar Produção", this);
        startProductionButton->setObjectName("iniciar_prod_btn");
        productionLayout->addWidget(openChokeButton);
        productionLayout->addWidget(closeChokeButton);
        productionLayout->addWidget(stopProductionButton);
        productionLayout->addWidget(startProductionButton);
        controlsLayout->addWidget(productionGroup);
        
        QPushButton* downloadButton = new QPushButton("Baixar Dados CSV", this);
        downloadButton->setObjectName("download_btn");
        controlsLayout->addWidget(downloadButton);
        
        QPushButton* reportsButton = new QPushButton("Gerar Relatórios", this);
        reportsButton->setObjectName("reports_btn");
        controlsLayout->addWidget(reportsButton);
        
        controlsContainerLayout->addLayout(controlsLayout);

        // Explicação da sugestão
        suggestionExplanationLabel = new QLabel("As sugestões e explicações aparecerão aqui.", this);
        suggestionExplanationLabel->setStyleSheet("font-style: italic; color: #aaa; margin-top: 10px;");
        suggestionExplanationLabel->setWordWrap(true);
        controlsContainerLayout->addWidget(suggestionExplanationLabel);

        mainLayout->addLayout(controlsContainerLayout);

        // Conecta os botões
        connect(injWaterButton, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(injGasButton, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(injVaporButton, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(flareButton, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(openChokeButton, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(closeChokeButton, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(stopProductionButton, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(startProductionButton, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(downloadButton, &QPushButton::clicked, this, &SimuladorWindow::onDownloadCSVClicked);
        connect(reportsButton, &QPushButton::clicked, this, &SimuladorWindow::onGenerateReportsClicked);

        // Estilização
        centralWidget->setStyleSheet("QWidget { background-color: #222; color: #eee; } QPushButton { background-color: #555; border: 1px solid #777; padding: 5px; } QGroupBox { border: 1px solid #555; margin-top: 10px; } QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; padding: 0 3px; }");
    }

    // Cria um QChartView com um gráfico
    QChartView* createChart(const QString& title, QLineSeries* series) {
        QChart* chart = new QChart();
        chart->addSeries(series);
        chart->setTitle(title);
        chart->setTheme(QChart::ChartThemeDark);
        chart->setBackgroundBrush(QBrush(QColor(40, 40, 40)));
        chart->legend()->hide();

        QValueAxis* axisX = new QValueAxis();
        axisX->setTitleText("Tempo (min)");
        axisX->setGridLineVisible(false);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis* axisY = new QValueAxis();
        axisY->setTitleText(series->name());
        axisY->setGridLineVisible(false);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        return new QChartView(chart);
    }
    
    // Inicializa os gráficos com valores padrão
    void setupCharts() {
        producaoSeries->append(0, reservatorio->vazao_oleo_bopd);
        minProducaoSeries->append(0, reservatorio->PRODUCAO_MINIMA_ACEITAVEL_BOPD);
        pressaoSeries->append(0, reservatorio->pressao_psi);
        volumeOleoSeries->append(0, reservatorio->volume_oleo_bbl);
        lucroSeries->append(0, reservatorio->receita_total_usd - reservatorio->custo_total_usd);
        temperaturaSeries->append(0, reservatorio->temperatura_C);
        viscosidadeSeries->append(0, reservatorio->viscosidade_oleo_cp);
        gorSeries->append(0, reservatorio->gas_oil_ratio);
        worSeries->append(0, reservatorio->water_oil_ratio);
    }

    // Atualiza os indicadores e gráficos
    void updateUI() {
        indicatorLabels[0]->setText(QString::number(reservatorio->vazao_oleo_bopd, 'f', 2) + " bopd");
        indicatorLabels[1]->setText(QString::number(reservatorio->pressao_psi, 'f', 2) + " psi");
        indicatorLabels[2]->setText(QString::number(reservatorio->receita_total_usd - reservatorio->custo_total_usd, 'f', 2) + " USD");
        indicatorLabels[3]->setText(QString::number(reservatorio->volume_oleo_bbl, 'f', 2) + " bbl");
        indicatorLabels[4]->setText(QString::number(reservatorio->preco_barril_usd, 'f', 2) + " USD");
        indicatorLabels[5]->setText(QString::number(reservatorio->temperatura_C, 'f', 2) + " C");
        indicatorLabels[6]->setText(QString::number(reservatorio->viscosidade_oleo_cp, 'f', 2) + " cp");
        indicatorLabels[7]->setText(QString::number(reservatorio->gas_oil_ratio, 'f', 2));
        indicatorLabels[8]->setText(QString::number(reservatorio->water_oil_ratio, 'f', 2));

        // Atualiza os custos detalhados
        revenueLabel->setText(QString("Receita Total: %1 USD").arg(QString::number(reservatorio->receita_total_usd, 'f', 2)));
        costLabel->setText(QString("Custo Total: %1 USD").arg(QString::number(reservatorio->custo_total_usd, 'f', 2)));
        profitLabel->setText(QString("Lucro Total: %1 USD").arg(QString::number(reservatorio->receita_total_usd - reservatorio->custo_total_usd, 'f', 2)));
        waterCostLabel->setText(QString("Custo Água: %1 USD").arg(QString::number(reservatorio->custo_injecao_agua_total, 'f', 2)));
        gasCostLabel->setText(QString("Custo Gás: %1 USD").arg(QString::number(reservatorio->custo_injecao_gas_total, 'f', 2)));
        vaporCostLabel->setText(QString("Custo Vapor: %1 USD").arg(QString::number(reservatorio->custo_injecao_vapor_total, 'f', 2)));

        // Atualiza os gráficos
        updateCharts();
    }

    // Adiciona um ponto de dado
    void saveDataPoint() {
        DadosPontos point;
        point.tempo_min = reservatorio->tempo_simulacao_s / 60.0;
        point.vazao_oleo = reservatorio->vazao_oleo_bopd;
        point.pressao = reservatorio->pressao_psi;
        point.viscosidade_cp = reservatorio->viscosidade_oleo_cp;
        point.volume_oleo = reservatorio->volume_oleo_bbl;
        point.preco_barril = reservatorio->preco_barril_usd;
        point.receita_total = reservatorio->receita_total_usd;
        point.custo_total = reservatorio->custo_total_usd;
        point.lucro = reservatorio->receita_total_usd - reservatorio->custo_total_usd;
        point.temperatura = reservatorio->temperatura_C;
        point.gor = reservatorio->gas_oil_ratio;
        point.wor = reservatorio->water_oil_ratio;
        point.custo_inj_agua = reservatorio->custo_injecao_agua_total;
        point.custo_inj_gas = reservatorio->custo_injecao_gas_total;
        point.custo_inj_vapor = reservatorio->custo_injecao_vapor_total;
        dataPoints.append(point);

        // Adiciona os pontos aos gráficos
        producaoSeries->append(point.tempo_min, point.vazao_oleo);
        minProducaoSeries->append(point.tempo_min, reservatorio->PRODUCAO_MINIMA_ACEITAVEL_BOPD);
        pressaoSeries->append(point.tempo_min, point.pressao);
        volumeOleoSeries->append(point.tempo_min, point.volume_oleo);
        lucroSeries->append(point.tempo_min, point.lucro);
        temperaturaSeries->append(point.tempo_min, point.temperatura);
        // viscosidadeSeries->append(point.tempo_min, point.viscosidade_oleo_cp);
        viscosidadeSeries->append(point.tempo_min, point.viscosidade_cp);
        gorSeries->append(point.tempo_min, point.gor);
        worSeries->append(point.tempo_min, point.wor);
    }

    void updateCharts() {
        // Ajusta as escalas dos eixos
        if (!dataPoints.isEmpty()) {
            double lastTime = dataPoints.last().tempo_min;
            producaoSeries->chart()->axes(Qt::Horizontal).first()->setRange(0, lastTime + 5);
            pressaoSeries->chart()->axes(Qt::Horizontal).first()->setRange(0, lastTime + 5);
            volumeOleoSeries->chart()->axes(Qt::Horizontal).first()->setRange(0, lastTime + 5);
            lucroSeries->chart()->axes(Qt::Horizontal).first()->setRange(0, lastTime + 5);
            temperaturaSeries->chart()->axes(Qt::Horizontal).first()->setRange(0, lastTime + 5);
            viscosidadeSeries->chart()->axes(Qt::Horizontal).first()->setRange(0, lastTime + 5);
            gorSeries->chart()->axes(Qt::Horizontal).first()->setRange(0, lastTime + 5);
            worSeries->chart()->axes(Qt::Horizontal).first()->setRange(0, lastTime + 5);
            
            producaoSeries->chart()->axes(Qt::Vertical).first()->setRange(
                std::min(0.0, producaoSeries->at(0).y()), 
                std::max(reservatorio->PRODUCAO_MINIMA_ACEITAVEL_BOPD * 1.5, producaoSeries->at(0).y() * 1.5)
            );
            pressaoSeries->chart()->axes(Qt::Vertical).first()->setRange(
                reservatorio->LIMITE_PRESSAO_CRITICO_MIN - 100, 
                reservatorio->LIMITE_PRESSAO_CRITICO_MAX + 100
            );
            volumeOleoSeries->chart()->axes(Qt::Vertical).first()->setRange(0, reservatorio->volume_oleo_bbl * 1.5);
            lucroSeries->chart()->axes(Qt::Vertical).first()->setRange(
                lucroSeries->at(0).y() * 0.5, 
                lucroSeries->at(0).y() * 1.5
            );
            temperaturaSeries->chart()->axes(Qt::Vertical).first()->setRange(0, reservatorio->temperatura_C * 1.5);
            viscosidadeSeries->chart()->axes(Qt::Vertical).first()->setRange(0, reservatorio->LIMITE_VISCOSIDADE_CRITICO * 1.5);
            gorSeries->chart()->axes(Qt::Vertical).first()->setRange(0, reservatorio->LIMITE_GOR_CRITICO * 1.5);
            worSeries->chart()->axes(Qt::Vertical).first()->setRange(0, reservatorio->LIMITE_WOR_CRITICO * 1.5);
        }
    }

    void updateIcons() {
        pressaoIconLabel->setPixmap(createIcon(reservatorio->pressao_psi < 2500 || reservatorio->pressao_psi > 6000 ? "#ffc107" : "#4caf50", iconPressaoPath).pixmap(48, 48));
        temperaturaIconLabel->setPixmap(createIcon(reservatorio->temperatura_C > 120 ? "#ffc107" : "#4caf50", iconTemperaturaPath).pixmap(48, 48));
        vazaoIconLabel->setPixmap(createIcon(reservatorio->vazao_oleo_bopd < reservatorio->PRODUCAO_MINIMA_ACEITAVEL_BOPD ? "#ffc107" : "#4caf50", iconVazaoPath).pixmap(48, 48));
        gorIconLabel->setPixmap(createIcon(reservatorio->gas_oil_ratio > 1500 ? "#ffc107" : "#4caf50", iconGorPath).pixmap(48, 48));
        statusIconLabel->setPixmap(createIcon(reservatorio->em_emergencia ? "#f44336" : "#4caf50", iconStatusPath).pixmap(48, 48));
    }

    void logMessage(const QString& message, const QString& type = "info") {
        QTextCharFormat format;
        if (type == "alerta") {
            format.setForeground(QBrush(QColor("#ffc107")));
        } else if (type == "critico") {
            format.setForeground(QBrush(QColor("#f44336")));
        } else if (type == "acao") {
            format.setForeground(QBrush(QColor("#81d4fa")));
        } else {
            format.setForeground(QBrush(QColor("#ccc")));
        }
        QTextCursor cursor = logTextEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.insertText(message + "\n", format);
        logTextEdit->setTextCursor(cursor);
    }
    
    void suggestInterventions() {
        if (reservatorio->pressao_psi < 2500) {
            suggestInputWater->setPlaceholderText(QString::number(5000, 'f', 0));
            suggestInputGas->setPlaceholderText(QString::number(2000, 'f', 0));
            suggestionExplanationLabel->setText("A pressão do reservatório está baixa. Injeção de gás ou água é recomendada para manter a produção. Injetar água é mais barato.");
        } else if (reservatorio->temperatura_C < 80) {
            suggestInputVapor->setPlaceholderText(QString::number(10, 'f', 0));
            suggestionExplanationLabel->setText("A temperatura do reservatório está baixa. Injetar vapor pode reduzir a viscosidade e aumentar a vazão.");
        } else if (reservatorio->viscosidade_oleo_cp > 4.0) {
            suggestInputVapor->setPlaceholderText(QString::number(5, 'f', 0));
            suggestionExplanationLabel->setText("A viscosidade do óleo está alta. Injeção de vapor pode melhorar a fluidez do óleo.");
        } else if (reservatorio->volume_gas_m3 > 8000) {
            suggestInputFlare->setPlaceholderText(QString::number(15000, 'f', 0));
            suggestionExplanationLabel->setText("Há excesso de gás no reservatório. Queimar gás pode ajudar a controlar a pressão.");
        } else if (reservatorio->water_oil_ratio > 0.2) {
            suggestionExplanationLabel->setText("A proporção de água está alta. Pode ser um sinal de 'coning' de água. Considere parar a produção ou ajustar a válvula.");
        } else if (reservatorio->gas_oil_ratio > 1500) {
            suggestionExplanationLabel->setText("A proporção de gás está alta, indicando 'coning' de gás. Ajuste a válvula de choque ou injete água para controlar a pressão.");
        } else {
            suggestInputWater->setPlaceholderText("500");
            suggestInputGas->setPlaceholderText("1000");
            suggestInputVapor->setPlaceholderText("5");
            suggestInputFlare->setPlaceholderText("10000");
            suggestionExplanationLabel->setText("Condições de operação normais. Acompanhe os indicadores para otimizar o lucro.");
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    SimuladorWindow window;
    window.show();
    return app.exec();
}

#include "main.moc"
