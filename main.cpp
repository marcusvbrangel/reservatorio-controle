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
#include <QScrollArea>
#include <QTabWidget>
#include <QGridLayout>
#include <QFrame>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>

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

    // Constantes do MLS-3A (Marlim Sul)
    const double GRAVIDADE_GAS_PESO_AR = 0.85;  // Densidade específica do gás MLS-3A
    const double GRAVIDADE_API = 29.5;          // Grau API real do óleo MLS-3A
    const double PRODUTIVIDADE_POCO_C = 22000.0; // Produção atual MLS-3A (bopd)
    const double FATOR_INJECAO_GAS_BASE = 0.05;
    const double FATOR_INJECAO_AGUA_BASE = 0.01;
    const double PRODUCAO_MINIMA_ACEITAVEL_BOPD = 8000.0; // Limite econômico MLS-3A

    // Limites Operacionais MLS-3A (Baseados no Poço Real)
    const double LIMITE_PRESSAO_CRITICO_MIN = 1650.0; // Pressão crítica atual MLS-3A
    const double LIMITE_PRESSAO_CRITICO_MAX = 4200.0; // Pressão inicial MLS-3A
    const double LIMITE_VISCOSIDADE_CRITICO = 4.5;    // Viscosidade limite para óleo 29.5° API
    const double LIMITE_GAS_CRITICO = 15000.0;        // Volume gás livre máximo
    const double LIMITE_WOR_CRITICO = 0.35;           // Water cut crítico MLS-3A
    const double LIMITE_GOR_CRITICO = 600.0;          // GOR crítico para óleo médio

    // Construtor
    // Construtor com Parâmetros Reais do MLS-3A (Marlim Sul - 2025)
    Reservatorio() :
        pressao_psi(2850.0),           // Pressão atual MLS-3A (2025)
        temperatura_C(92.0),           // Temperatura de reservatório MLS-3A
        volume_oleo_bbl(55000000.0),   // 55 MM bbl restantes (OOIP - produzido)
        volume_gas_m3(8500.0),         // Volume gás livre atual
        volume_agua_bbl(125000.0),     // Água de formação + produzida
        viscosidade_oleo_cp(2.8),      // Viscosidade nas condições de reservatório
        vazao_oleo_bopd(22000.0),      // Produção atual após revitalização
        pressao_de_bolha_psi(2950.0),  // Pressão de saturação MLS-3A
        pressao_poco_psi(1950.0),      // BHP (Bottom Hole Pressure) atual
        em_emergencia(false),
        gas_oil_ratio(420.0),          // GOR atual MLS-3A (scf/bbl)
        water_oil_ratio(0.23),         // BSW atual 23% (2025)
        tempo_simulacao_s(0.0) {}

    // Métodos de Cálculo e Simulação
    double calcularSolubilidadeGas(double pressao_psi, double temperatura_C) {
        double temp_F = 1.8 * temperatura_C + 32.0;
        double resultado = GRAVIDADE_GAS_PESO_AR * pow((pressao_psi / 18.2) * exp(0.0125 * GRAVIDADE_API * exp(0.0011 * temp_F)), 1.2045);
        return resultado;
    }

    double calcularViscosidadeOleo(double pressao_psi, double temperatura_C) {
        // Cálculo de viscosidade calibrado para óleo MLS-3A (29.5° API)
        double temp_F = 1.8 * temperatura_C + 32.0;
        
        // Viscosidade morta para óleo 29.5° API a 92°C
        double viscosidade_base = 2.8; // cp - medido no MLS-3A
        
        // Correção por temperatura (Lei de Arrhenius modificada)
        double temp_ref = 92.0; // Temperatura de referência MLS-3A
        double fator_temp = exp(500.0 * (1.0/(temperatura_C + 273.15) - 1.0/(temp_ref + 273.15)));
        
        // Correção por pressão (compressibilidade isotermal)
        double press_ref = 2850.0; // Pressão de referência MLS-3A
        double fator_pressao = 1.0 + 2.5e-6 * (pressao_psi - press_ref);
        
        double resultado = viscosidade_base * fator_temp * fator_pressao;
        
        // Limitar ao range físico do óleo MLS-3A
        return std::max(1.8, std::min(resultado, LIMITE_VISCOSIDADE_CRITICO));
    }

    double calcularVazaoProducao(double pressao_reservatorio_psi) {
        // IPR (Inflow Performance Relationship) calibrada para MLS-3A
        double pi_atual = 8.2; // Índice de produtividade atual MLS-3A (bopd/psi)
        double q_max = PRODUTIVIDADE_POCO_C;
        
        if (pressao_reservatorio_psi >= pressao_de_bolha_psi) {
            // Fluxo monofásico (acima da pressão de bolha)
            double drawdown = pressao_reservatorio_psi - pressao_poco_psi;
            return pi_atual * drawdown * (1.0 - 0.1 * drawdown / pressao_reservatorio_psi);
        } else {
            // Fluxo bifásico (abaixo da pressão de bolha) - Vogel's IPR modificado para MLS-3A
            double pr_pb = pressao_reservatorio_psi / pressao_de_bolha_psi;
            double pwf_pb = pressao_poco_psi / pressao_de_bolha_psi;
            
            // Vogel's equation calibrada para características do MLS-3A
            double qmax_at_pb = pi_atual * (pressao_reservatorio_psi - pressao_de_bolha_psi);
            double vogel_term = 1.0 - 0.2 * pwf_pb - 0.8 * pow(pwf_pb, 2);
            
            return qmax_at_pb + (q_max - qmax_at_pb) * vogel_term;
        }
    }

    void simularEfeitoProducao(double tempo_passado_s) {
        if (em_emergencia) {
            vazao_oleo_bopd = 0.0;
            return;
        }
        
        // Cálculo de vazão baseado no IPR do MLS-3A
        vazao_oleo_bopd = calcularVazaoProducao(pressao_psi);
        
        // Produção em barris neste intervalo
        double oleo_produzido_bbl = vazao_oleo_bopd * (tempo_passado_s / 86400.0);
        
        // Depleção do volume de óleo (OOIP MLS-3A)
        volume_oleo_bbl -= oleo_produzido_bbl;
        if (volume_oleo_bbl < 0) volume_oleo_bbl = 0;
        
        // Declínio de pressão baseado na curva real do MLS-3A
        // Taxa de declínio atual: ~8% ao ano = 0.00015 por dia
        double taxa_declinio_diaria = 0.00015; // Calibrada para MLS-3A
        double declinio_pressao = pressao_psi * taxa_declinio_diaria * (tempo_passado_s / 86400.0);
        
        // Fator de depleção acelerada (baseado no OOIP original = 280 MM bbl)
        double recovery_factor = 1.0 - (volume_oleo_bbl / 280000000.0);
        declinio_pressao *= (1.0 + 2.0 * recovery_factor); // Aceleração progressiva
        
        pressao_psi -= declinio_pressao;
        if (pressao_psi < 0) pressao_psi = 0;
        
        // Liberação de gás livre (pressão < pressão de bolha)
        if (pressao_psi < pressao_de_bolha_psi) {
            // GOR aumenta conforme pressão diminui (comportamento típico)
            double gor_increment = 200.0 * (pressao_de_bolha_psi - pressao_psi) / pressao_de_bolha_psi;
            gas_oil_ratio = std::min(gas_oil_ratio + gor_increment * (tempo_passado_s / 86400.0), LIMITE_GOR_CRITICO);
            volume_gas_m3 += oleo_produzido_bbl * gas_oil_ratio / 178.1; // Conversão scf para m³
        }
        
        // Coning de água (característico do MLS-3A)
        simularConingMLS3A();
        
        // Produção de água (BSW crescente)
        double agua_produzida_bbl = oleo_produzido_bbl * water_oil_ratio;
        volume_agua_bbl += agua_produzida_bbl; // Água produzida acumula
        
        // Variação operacional típica do MLS-3A (±2%)
        double variacao = ((rand() % 41) - 20) / 1000.0;
        vazao_oleo_bopd *= (1.0 + variacao);
        
        // Aplicar limites operacionais do MLS-3A
        vazao_oleo_bopd = std::max(8000.0, std::min(vazao_oleo_bopd, 42000.0));
    }

    void simularConingMLS3A() {
        // Coning característico do MLS-3A (baseado em 26 anos de dados)
        double drawdown = pressao_psi - pressao_poco_psi;
        double drawdown_critico = 900.0; // psi - limite para coning severo
        
        if (drawdown > drawdown_critico) {
            // Coning severo - aumento acelerado de BSW
            double incremento_bsw = 0.002; // 0.2% por ciclo
            water_oil_ratio += incremento_bsw;
            water_oil_ratio = std::min(water_oil_ratio, LIMITE_WOR_CRITICO);
            
            // Gas coning também aumenta
            gas_oil_ratio += 15.0; // scf/bbl por ciclo
            gas_oil_ratio = std::min(gas_oil_ratio, LIMITE_GOR_CRITICO);
        } else {
            // Coning controlado - crescimento natural do BSW
            double anos_producao = tempo_simulacao_s / (365.25 * 86400.0);
            double bsw_natural = 0.15 + 0.008 * anos_producao; // Curva real MLS-3A
            water_oil_ratio = std::min(bsw_natural, LIMITE_WOR_CRITICO);
            
            // GOR se mantém estável ou cresce lentamente
            if (gas_oil_ratio > 420.0) {
                gas_oil_ratio = std::max(420.0, gas_oil_ratio - 2.0);
            }
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
        // Inicializa gerador de números aleatórios
        srand(static_cast<unsigned int>(time(nullptr)));
        
        // Inicializa o reservatório e o temporizador
        reservatorio = new Reservatorio();
        simulationTimer = new QTimer(this);
        connect(simulationTimer, &QTimer::timeout, this, &SimuladorWindow::gameLoop);

        // Inicializa a interface
        setupUI();
        setupCharts();

        // Inicia a simulação após a interface estar pronta
        QTimer::singleShot(100, this, [this]() {
            // Intervalo realista: 5 segundos (similar à Bacia de Campos)
            simulationTimer->start(5000); // 5 segundos - realismo operacional
            logMessage("🏆 Simulador MLS-3A iniciado - Poço Marlim Sul (Bacia de Campos)");
            logMessage("📈 Parâmetros calibrados com dados reais do poço MLS-3A:", "info");
            logMessage("• Pressão atual: 2.850 psi • Temperatura: 92°C • API: 29,5°", "info");
            logMessage("• Produção: 22.000 bopd • BSW: 23% • GOR: 420 scf/bbl", "info");
            logMessage("ℹ️ Monitoramento: 5s (padrão COI Petrobras) • 26 anos de histórico", "info");
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
            // Simular 5 segundos de operação real a cada ciclo
            reservatorio->atualizarEstado(5.0);
        } else {
            // Mesmo sem produção, o tempo avança
            reservatorio->verificarEmergencia();
            reservatorio->tempo_simulacao_s += 5.0;
        }

        // Salvar dados a cada ciclo (representa coleta de dados operacionais)
        // Em um sistema real, isso seria equivalent a dados coletados a cada 5 segundos
        saveDataPoint();

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
            
            // Alertas com frequência controlada (como sistemas reais)
            // Verifica alertas críticos a cada 30 segundos (6 ciclos)
            if (static_cast<int>(reservatorio->tempo_simulacao_s) % 30 == 0) {
                if (reservatorio->pressao_psi < 2500) {
                    logMessage("AVISO: Pressão do reservatório em declínio. Injeção de água ou gás pode ser necessária.", "alerta");
                } else if (reservatorio->viscosidade_oleo_cp > 4.0) {
                    logMessage("AVISO: Viscosidade do óleo alta. Injeção de vapor ou água quente pode ser necessária.", "alerta");
                }
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
        setWindowTitle("Simulador MLS-3A - Poço Marlim Sul (Bacia de Campos)");
        setMinimumSize(1400, 900);

        // Widget principal com scroll
        QScrollArea* scrollArea = new QScrollArea(this);
        QWidget* centralWidget = new QWidget();
        scrollArea->setWidget(centralWidget);
        scrollArea->setWidgetResizable(true);
        setCentralWidget(scrollArea);
        
        // Tema visual melhorado com fundo preto
        setStyleSheet(
            "QMainWindow { background-color: #000000; }"
            "QScrollArea { background-color: #000000; border: none; }"
            "QWidget { background-color: #000000; color: #FFFFFF; }"
            "QGroupBox { "
                "background-color: #1a1a1a; "
                "border: 2px solid #333333; "
                "border-radius: 8px; "
                "margin-top: 8px; "
                "padding-top: 10px; "
                "font-weight: bold; "
            "}"
            "QGroupBox::title { "
                "subcontrol-origin: margin; "
                "subcontrol-position: top center; "
                "padding: 0 8px; "
                "color: #00AAFF; "
            "}"
            "QPushButton { "
                "background-color: #2d2d2d; "
                "border: 2px solid #555555; "
                "border-radius: 6px; "
                "padding: 8px; "
                "font-weight: bold; "
                "min-height: 25px; "
            "}"
            "QPushButton:hover { background-color: #404040; border-color: #777777; }"
            "QPushButton:pressed { background-color: #1a1a1a; }"
            "QLineEdit { "
                "background-color: #2d2d2d; "
                "border: 2px solid #555555; "
                "border-radius: 4px; "
                "padding: 5px; "
                "selection-background-color: #0078d4; "
            "}"
            "QLabel { color: #FFFFFF; }"
            "QTextEdit { "
                "background-color: #1a1a1a; "
                "border: 2px solid #333333; "
                "border-radius: 6px; "
                "color: #CCCCCC; "
            "}"
        );
        
        QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
        mainLayout->setSpacing(15);
        mainLayout->setContentsMargins(20, 20, 20, 20);

        // Seção de Ícones SCADA em GroupBox
        QGroupBox* scadaGroupBox = new QGroupBox("Monitor SCADA - Status em Tempo Real");
        QHBoxLayout* scadaIconsLayout = new QHBoxLayout(scadaGroupBox);
        scadaIconsLayout->setAlignment(Qt::AlignCenter);
        scadaIconsLayout->setSpacing(30);

        // Criação dos ícones SCADA com estilo melhorado
        auto createScadaIcon = [this, scadaIconsLayout](const QString& name, const QString& tooltip) -> QLabel* {
            QVBoxLayout* iconLayout = new QVBoxLayout();
            QLabel* iconLabel = new QLabel();
            iconLabel->setFixedSize(60, 60);
            iconLabel->setAlignment(Qt::AlignCenter);
            iconLabel->setToolTip(tooltip);
            
            QLabel* textLabel = new QLabel(name);
            textLabel->setAlignment(Qt::AlignCenter);
            textLabel->setStyleSheet("color: #FFFFFF; font-weight: bold; font-size: 12px; margin-top: 5px;");
            
            QWidget* container = new QWidget();
            QVBoxLayout* containerLayout = new QVBoxLayout(container);
            containerLayout->addWidget(iconLabel);
            containerLayout->addWidget(textLabel);
            containerLayout->setSpacing(5);
            containerLayout->setContentsMargins(10, 5, 10, 5);
            
            scadaIconsLayout->addWidget(container);
            return iconLabel;
        };

        pressaoIconLabel = createScadaIcon("Pressão", "Status da Pressão do Reservatório");
        temperaturaIconLabel = createScadaIcon("Temperatura", "Status da Temperatura do Reservatório");  
        vazaoIconLabel = createScadaIcon("Vazão", "Status da Vazão de Produção de Óleo");
        gorIconLabel = createScadaIcon("GOR", "Status do Gás-Óleo Ratio");
        statusIconLabel = createScadaIcon("Sistema", "Status Geral do Sistema");

        mainLayout->addWidget(scadaGroupBox);

        // Seção de Indicadores Principais em Grid
        QGroupBox* indicatorsGroupBox = new QGroupBox("Indicadores Operacionais");
        QGridLayout* indicatorsLayout = new QGridLayout(indicatorsGroupBox);
        indicatorsLayout->setSpacing(15);
        
        QStringList titles = {"Produção de Petróleo", "Pressão do Reservatório", "Volume de Óleo", "Temperatura", "Viscosidade", "GOR", "WOR"};
        QStringList units = {"bopd", "psi", "bbl", "°C", "cp", "ratio", "ratio"};
        
        for (int i = 0; i < titles.size(); ++i) {
            // Container para cada indicador
            QFrame* indicatorFrame = new QFrame();
            indicatorFrame->setFrameStyle(QFrame::Box | QFrame::Raised);
            indicatorFrame->setLineWidth(1);
            indicatorFrame->setStyleSheet(
                "QFrame { "
                    "background-color: #2a2a2a; "
                    "border: 2px solid #444444; "
                    "border-radius: 8px; "
                    "padding: 10px; "
                "}"
            );
            
            QVBoxLayout* boxLayout = new QVBoxLayout(indicatorFrame);
            boxLayout->setSpacing(5);
            
            QLabel* titleLabel = new QLabel(titles[i], this);
            titleLabel->setAlignment(Qt::AlignCenter);
            titleLabel->setStyleSheet("font-weight: bold; font-size: 12px; color: #CCCCCC; margin-bottom: 5px;");
            titleLabel->setWordWrap(true);
            
            QLabel* valueLabel = new QLabel("0", this);
            valueLabel->setAlignment(Qt::AlignCenter);
            valueLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: #00FF00; min-height: 30px;");
            indicatorLabels.append(valueLabel);
            
            QLabel* unitLabel = new QLabel(units[i], this);
            unitLabel->setAlignment(Qt::AlignCenter);
            unitLabel->setStyleSheet("font-size: 10px; color: #888888; margin-top: 2px;");
            
            boxLayout->addWidget(titleLabel);
            boxLayout->addWidget(valueLabel);
            boxLayout->addWidget(unitLabel);
            
            // Posicionamento em grid (2 linhas)
            int row = i < 4 ? 0 : 1;
            int col = i < 4 ? i : i - 4;
            indicatorsLayout->addWidget(indicatorFrame, row, col);
        }
        
        mainLayout->addWidget(indicatorsGroupBox);

        // Seção de Monitoramento e Gráficos
        QHBoxLayout* monitoringLayout = new QHBoxLayout();
        
        // Gráficos organizados em abas
        QTabWidget* chartsTabWidget = new QTabWidget();
        chartsTabWidget->setStyleSheet(
            "QTabWidget::pane { border: 2px solid #333333; background-color: #1a1a1a; }"
            "QTabBar::tab { "
                "background-color: #2d2d2d; "
                "border: 2px solid #555555; "
                "padding: 8px 16px; "
                "margin-right: 2px; "
                "border-top-left-radius: 6px; "
                "border-top-right-radius: 6px; "
            "}"
            "QTabBar::tab:selected { "
                "background-color: #404040; "
                "border-bottom-color: #1a1a1a; "
            "}"
            "QTabBar::tab:hover { background-color: #383838; }"
        );

        // Inicializar séries
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
        temperaturaSeries->setName("Temperatura (°C)");

        viscosidadeSeries = new QLineSeries();
        viscosidadeSeries->setName("Viscosidade (cp)");

        gorSeries = new QLineSeries();
        gorSeries->setName("GOR");

        worSeries = new QLineSeries();
        worSeries->setName("WOR");

        // Adicionar gráficos às abas
        chartsTabWidget->addTab(createChart("Produção de Óleo", producaoSeries), "Produção");
        chartsTabWidget->addTab(createChart("Pressão do Reservatório", pressaoSeries), "Pressão");
        chartsTabWidget->addTab(createChart("Volume de Óleo", volumeOleoSeries), "Volume");
        chartsTabWidget->addTab(createChart("Temperatura", temperaturaSeries), "Temperatura");
        chartsTabWidget->addTab(createChart("Viscosidade", viscosidadeSeries), "Viscosidade");
        
        // Aba combinada para ratios
        QWidget* ratiosWidget = new QWidget();
        QVBoxLayout* ratiosLayout = new QVBoxLayout(ratiosWidget);
        ratiosLayout->addWidget(createChart("GOR (Gas-Oil Ratio)", gorSeries));
        ratiosLayout->addWidget(createChart("WOR (Water-Oil Ratio)", worSeries));
        chartsTabWidget->addTab(ratiosWidget, "Ratios");

        monitoringLayout->addWidget(chartsTabWidget, 3);

        // Log de eventos com título
        QGroupBox* logGroupBox = new QGroupBox("Log de Eventos do Sistema");
        QVBoxLayout* logLayout = new QVBoxLayout(logGroupBox);
        
        logTextEdit = new QTextEdit();
        logTextEdit->setReadOnly(true);
        logTextEdit->setMinimumHeight(300);
        logTextEdit->setStyleSheet(
            "QTextEdit { "
                "background-color: #0a0a0a; "
                "border: 1px solid #333333; "
                "color: #CCCCCC; "
                "font-family: 'Courier New', monospace; "
                "font-size: 11px; "
            "}"
        );
        logLayout->addWidget(logTextEdit);
        
        monitoringLayout->addWidget(logGroupBox, 1);
        
        mainLayout->addLayout(monitoringLayout);

        // Seção de Controles Operacionais
        QHBoxLayout* controlsLayout = new QHBoxLayout();
        
        // Controles de Intervenção em grid
        QGroupBox* interventionGroupBox = new QGroupBox("Controles de Intervenção");
        QGridLayout* interventionGrid = new QGridLayout(interventionGroupBox);
        interventionGrid->setSpacing(10);

        // Helper function para criar controle de intervenção
        auto createInterventionControl = [this](const QString& title, const QString& param1Label, 
                                              const QString& param1Default, const QString& param2Label = "",
                                              const QString& param2Default = "") -> QWidget* {
            QFrame* frame = new QFrame();
            frame->setFrameStyle(QFrame::StyledPanel);
            frame->setStyleSheet(
                "QFrame { "
                    "background-color: #252525; "
                    "border: 1px solid #444444; "
                    "border-radius: 6px; "
                    "padding: 8px; "
                "}"
            );
            
            QVBoxLayout* frameLayout = new QVBoxLayout(frame);
            frameLayout->setSpacing(8);
            
            // Título
            QLabel* titleLabel = new QLabel(title);
            titleLabel->setStyleSheet("font-weight: bold; color: #00AAFF; font-size: 12px;");
            titleLabel->setAlignment(Qt::AlignCenter);
            frameLayout->addWidget(titleLabel);
            
            // Parâmetros
            QGridLayout* paramsLayout = new QGridLayout();
            paramsLayout->setSpacing(5);
            
            QLabel* label1 = new QLabel(param1Label);
            label1->setStyleSheet("font-size: 10px; color: #CCCCCC;");
            QLineEdit* input1 = new QLineEdit(param1Default);
            input1->setValidator(new QDoubleValidator(this));
            input1->setFixedWidth(80);
            
            paramsLayout->addWidget(label1, 0, 0);
            paramsLayout->addWidget(input1, 0, 1);
            
            QLineEdit* input2 = nullptr;
            if (!param2Label.isEmpty()) {
                QLabel* label2 = new QLabel(param2Label);
                label2->setStyleSheet("font-size: 10px; color: #CCCCCC;");
                input2 = new QLineEdit(param2Default);
                input2->setValidator(new QDoubleValidator(this));
                input2->setFixedWidth(80);
                
                paramsLayout->addWidget(label2, 1, 0);
                paramsLayout->addWidget(input2, 1, 1);
            }
            
            frameLayout->addLayout(paramsLayout);
            
            // Botão de ação
            QPushButton* actionBtn = new QPushButton("Executar");
            actionBtn->setStyleSheet(
                "QPushButton { "
                    "background-color: #0078D4; "
                    "border: none; "
                    "color: white; "
                    "font-weight: bold; "
                    "padding: 6px; "
                    "border-radius: 4px; "
                "}"
                "QPushButton:hover { background-color: #106EBE; }"
                "QPushButton:pressed { background-color: #005A9E; }"
            );
            
            frameLayout->addWidget(actionBtn);
            
            // Armazenar referências dos inputs
            frame->setProperty("input1", QVariant::fromValue((QObject*)input1));
            if (input2) frame->setProperty("input2", QVariant::fromValue((QObject*)input2));
            frame->setProperty("button", QVariant::fromValue((QObject*)actionBtn));
            
            return frame;
        };
        
        // Criar controles de intervenção
        QWidget* waterControl = createInterventionControl("Injeção de Água", "Volume (bbl)", "1000", "Temp (°C)", "100");
        QWidget* gasControl = createInterventionControl("Injeção de Gás", "Volume (m³)", "5000", "Densidade", "0.7");
        QWidget* vaporControl = createInterventionControl("Injeção de Vapor", "Tempo (s)", "500");
        QWidget* flareControl = createInterventionControl("Sistema Flare", "Vazão (scfd)", "5000");
        
        // Posicionar controles em grid 2x2
        interventionGrid->addWidget(waterControl, 0, 0);
        interventionGrid->addWidget(gasControl, 0, 1);
        interventionGrid->addWidget(vaporControl, 1, 0);
        interventionGrid->addWidget(flareControl, 1, 1);
        
        // Recuperar referências dos inputs
        suggestInputWater = qobject_cast<QLineEdit*>(waterControl->property("input1").value<QObject*>());
        inputTempAgua = qobject_cast<QLineEdit*>(waterControl->property("input2").value<QObject*>());
        QPushButton* waterBtn = qobject_cast<QPushButton*>(waterControl->property("button").value<QObject*>());
        waterBtn->setObjectName("inj_agua_btn");
        
        suggestInputGas = qobject_cast<QLineEdit*>(gasControl->property("input1").value<QObject*>());
        inputDensidadeGas = qobject_cast<QLineEdit*>(gasControl->property("input2").value<QObject*>());
        QPushButton* gasBtn = qobject_cast<QPushButton*>(gasControl->property("button").value<QObject*>());
        gasBtn->setObjectName("inj_gas_btn");
        
        suggestInputVapor = qobject_cast<QLineEdit*>(vaporControl->property("input1").value<QObject*>());
        QPushButton* vaporBtn = qobject_cast<QPushButton*>(vaporControl->property("button").value<QObject*>());
        vaporBtn->setObjectName("inj_vapor_btn");
        
        suggestInputFlare = qobject_cast<QLineEdit*>(flareControl->property("input1").value<QObject*>());
        QPushButton* flareBtn = qobject_cast<QPushButton*>(flareControl->property("button").value<QObject*>());
        flareBtn->setObjectName("flare_btn");

        controlsLayout->addWidget(interventionGroupBox, 2);
        
        // Coluna direita com controles de produção e sistema
        QVBoxLayout* rightControlsLayout = new QVBoxLayout();
        
        // Controles de Produção
        QGroupBox* productionGroupBox = new QGroupBox("Controles de Produção");
        QVBoxLayout* productionLayout = new QVBoxLayout(productionGroupBox);
        
        // Botões de produção com estilo
        auto createProductionButton = [](const QString& text, const QString& objName, const QString& color) -> QPushButton* {
            QPushButton* btn = new QPushButton(text);
            btn->setObjectName(objName);
            btn->setMinimumHeight(40);
            btn->setStyleSheet(QString(
                "QPushButton { "
                    "background-color: %1; "
                    "border: none; "
                    "color: white; "
                    "font-weight: bold; "
                    "border-radius: 6px; "
                    "font-size: 12px; "
                "}"
                "QPushButton:hover { background-color: %2; }"
                "QPushButton:pressed { background-color: %3; }"
            ).arg(color).arg(color + "CC").arg(color + "AA"));
            return btn;
        };
        
        QPushButton* startBtn = createProductionButton("▶ Iniciar Produção", "iniciar_prod_btn", "#28A745");
        QPushButton* stopBtn = createProductionButton("⏸ Parar Produção", "parar_prod_btn", "#DC3545");
        QPushButton* openValveBtn = createProductionButton("⬆ Abrir Válvula", "abrir_valv_btn", "#17A2B8");
        QPushButton* closeValveBtn = createProductionButton("⬇ Fechar Válvula", "fechar_valv_btn", "#FD7E14");
        
        productionLayout->addWidget(startBtn);
        productionLayout->addWidget(stopBtn);
        productionLayout->addWidget(openValveBtn);
        productionLayout->addWidget(closeValveBtn);
        
        rightControlsLayout->addWidget(productionGroupBox);
        
        // Sugestões do Sistema
        QGroupBox* suggestionGroupBox = new QGroupBox("Sugestões Inteligentes");
        QVBoxLayout* suggestionLayout = new QVBoxLayout(suggestionGroupBox);
        
        suggestionExplanationLabel = new QLabel("🤖 O sistema fornecerá sugestões automáticas baseadas nas condições operacionais.");
        suggestionExplanationLabel->setStyleSheet(
            "color: #CCCCCC; "
            "font-style: italic; "
            "padding: 10px; "
            "background-color: #1a1a1a; "
            "border: 1px solid #333333; "
            "border-radius: 4px; "
            "font-size: 11px; "
        );
        suggestionExplanationLabel->setWordWrap(true);
        suggestionExplanationLabel->setMinimumHeight(80);
        
        suggestionLayout->addWidget(suggestionExplanationLabel);
        rightControlsLayout->addWidget(suggestionGroupBox);
        
        // Botões de Sistema
        QGroupBox* systemGroupBox = new QGroupBox("Sistema e Relatórios");
        QVBoxLayout* systemLayout = new QVBoxLayout(systemGroupBox);
        
        QPushButton* reportBtn = createProductionButton("📊 Gerar Relatórios", "report_btn", "#6F42C1");
        QPushButton* downloadBtn = createProductionButton("💾 Exportar CSV", "download_csv_btn", "#20C997");
        
        systemLayout->addWidget(reportBtn);
        systemLayout->addWidget(downloadBtn);
        
        rightControlsLayout->addWidget(systemGroupBox);
        rightControlsLayout->addStretch(); // Espaço flexível no final
        
        controlsLayout->addLayout(rightControlsLayout, 1);
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
    a.setApplicationName("Simulador MLS-3A Marlim Sul");
    a.setApplicationVersion("1.0");
    
    SimuladorWindow w;
    w.show();
    
    // Garante que a janela seja completamente mostrada antes de continuar
    a.processEvents();
    
    return a.exec();
}
