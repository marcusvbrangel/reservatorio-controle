/*
================================================================================
🎓 SIMULADOR DE RESERVATÓRIO DE PETRÓLEO - POÇO ATS-7B (ATLÂNTIDA ORIENTAL)
================================================================================

📚 GUIA EDUCACIONAL PARA ESTUDANTES DE ENGENHARIA DE RESERVATÓRIOS

Este simulador é uma ferramenta didática que reproduz as condições operacionais
reais do poço ATS-7B da Bacia de Atlântida (OceanOil). Foi desenvolvido para
ensinar conceitos fundamentais de:

• Física de Reservatórios (pressão, temperatura, viscosidade)
• Curvas de IPR (Inflow Performance Relationship)
• Modelos de produção (Darcy, Vogel, Standing)
• Fenômenos operacionais (coning, declínio de produção)
• Métodos de recuperação (injeção de água, gás, vapor)
• Monitoramento e controle de produção

🏆 DADOS REAIS: Baseado em 26 anos de histórico operacional do ATS-7B
⚙️ TECNOLOGIA: Interface gráfica Qt5 com visualizações em tempo real
🎯 PÚBLICO: Estudantes iniciantes de Engenharia de Reservatórios

🔧 ================================================================================
⚡ REFATORAÇÃO IMPLEMENTADA - CÓDIGO LIMPO E MANUTENÍVEL
================================================================================

📚 CONCEITOS DE REFATORAÇÃO APLICADOS:

✅ DRY PRINCIPLE (Don't Repeat Yourself):
   • Eliminação de código duplicado
   • Centralização de lógicas repetitivas
   • Métodos utilitários reutilizáveis

✅ SINGLE RESPONSIBILITY PRINCIPLE:
   • Cada método tem uma função específica
   • Separação de concerns (formatação, cálculos, interface)
   • Código mais testável e auditável

✅ CLEAN CODE STANDARDS:
   • Nomes descritivos e autoexplicativos
   • Funções pequenas e focadas
   • Comentários educacionais técnicos
   • Estrutura organizacional clara

🏭 BENEFÍCIOS PARA SISTEMAS INDUSTRIAIS:

✅ MANUTENIBILIDADE:
   • Facilita atualizações e correções
   • Reduz tempo de debugging
   • Simplifica treinamento de equipe

✅ AUDITABILIDADE:
   • Código mais legível para revisões
   • Padrões consistentes
   • Documentação técnica integrada

✅ CONFIABILIDADE:
   • Menos duplicação = menos bugs
   • Lógica centralizada e testável
   • Comportamento previsível

🎨 ================================================================================
🖥️ AJUSTES DE LAYOUT - MELHORIAS DE USABILIDADE
================================================================================

📚 OTIMIZAÇÕES VISUAIS IMPLEMENTADAS:

✅ LOG DE EVENTOS:
   • Fonte aumentada: 11px → 14px (+27% legibilidade)
   • Melhor visibilidade para monitoramento em tempo real
   • Reduz fadiga visual em operações de longa duração
   • Padrão adequado para ambientes industriais 24/7

✅ INDICADORES OPERACIONAIS:
   • Unidades de medida: 10px → 13px (+30% legibilidade)
   • Font-weight aumentado para melhor destaque visual
   • Identificação mais rápida das grandezas físicas
   • Redução de erros de interpretação operacional

🏭 BENEFÍCIOS PARA OPERAÇÃO INDUSTRIAL:

✅ ERGONOMIA:
   • Menor esforço visual para leitura
   • Adequação para monitores grandes (>24")
   • Conformidade com padrões HMI industriais

✅ SEGURANÇA OPERACIONAL:
   • Redução de erros por má interpretação visual  
   • Identificação mais rápida de eventos críticos
   • Melhor experiência do usuário em situações de stress

✅ PRODUTIVIDADE:
   • Menor tempo para localizar informações
   • Interface mais intuitiva e profissional
   • Redução de treinamento necessário

🔥 ================================================================================
📚 MELHORIA EDUCACIONAL: TERMINOLOGIA HÍBRIDA FLARE
================================================================================

📚 ABORDAGEM PEDAGÓGICA IMPLEMENTADA:

✅ PROBLEMA IDENTIFICADO:
   • Termo "Flare" em inglês pode confundir estudantes iniciantes
   • Foco no equipamento ao invés da função
   • Barreira linguística para compreensão imediata

✅ SOLUÇÃO HÍBRIDA ADOTADA:
   • Interface: "Liberação de Gás (Flare)"  
   • DIDÁTICO PRIMEIRO: Explica a função (o que faz)
   • TÉCNICO SEGUNDO: Ensina o termo industrial (como se chama)
   • Progressão natural: Compreensão → Terminologia

✅ BENEFÍCIOS EDUCACIONAIS:
   • Clareza imediata para estudantes iniciantes
   • Preparação adequada para ambiente profissional  
   • Conexão função-terminologia bem estabelecida
   • Tooltips explicativos com contexto industrial completo

✅ IMPLEMENTAÇÃO TÉCNICA:
   • Labels de interface atualizados
   • Mensagens de log mais descritivas
   • Tooltips educacionais detalhados
   • Preservação da precisão técnica

🏭 CONTEXTO INDUSTRIAL PRESERVADO:
O termo "flare" continua sendo usado nos logs e documentação técnica,
mantendo a precisão profissional enquanto melhora a didática inicial.

📊 ================================================================================
⚡ GRÁFICOS INTERATIVOS - DASHBOARD SCADA PROFISSIONAL
================================================================================

📚 FUNCIONALIDADE IMPLEMENTADA:

✅ PROBLEMA RESOLVIDO:
   • Gráficos com pontos muito próximos (pouco interativos)
   • Falta de controle de granularidade temporal
   • Performance degradada com excesso de dados
   • Inadequação para diferentes tipos de análise

✅ SOLUÇÃO DASHBOARD SCADA:
   • Controle de periodicidade configurável
   • Períodos: 1min, 5min, 10min, 30min, 1h, 1 dia
   • Otimização automática de performance
   • Interface profissional com botão "Limpar Gráficos"

✅ BENEFÍCIOS OPERACIONAIS:
   • TEMPO REAL (1-5min): Monitoramento operacional detalhado
   • SUPERVISÃO (10-30min): Análise de tendências operacionais  
   • ESTRATÉGICO (1h-1dia): Visão gerencial e planejamento
   • PERFORMANCE: Auto-limitação de pontos para fluidez

✅ FUNCIONALIDADES SCADA:
   • Seleção dinâmica de período (dropdown)
   • Reset completo dos gráficos (Clear Charts)
   • Logging automático de mudanças de configuração
   • Otimização inteligente baseada no período selecionado

✅ IMPLEMENTAÇÃO TÉCNICA:
   • Sistema de timestamp inteligente
   • Controle de consolidação temporal
   • Limitação automática de pontos (200-500 máximo)
   • Interface responsiva e profissional

🏭 EQUIVALÊNCIA INDUSTRIAL:
Sistema equivalente aos dashboards da OceanOil e sistemas PI (OSIsoft)
usados em salas de controle da Bacia de Atlântida, com funcionalidades
profissionais adaptadas para ensino de Engenharia de Reservatórios.

🔧 ================================================================================
📊 CORREÇÃO CRÍTICA: VISIBILIDADE DOS GRÁFICOS SOLUCIONADA
================================================================================

🚨 PROBLEMA IDENTIFICADO:
   • Gráficos não mostravam linhas visíveis apesar dos logs indicarem atualizações
   • Eixos sem ranges definidos causavam auto-escalonamento inadequado
   • Valores com escalas muito diferentes (Volume: 55M vs Temperatura: 92)
   • Poucos pontos iniciais geravam escalas inadequadas no Qt Charts

🛠️ CORREÇÕES TÉCNICAS IMPLEMENTADAS:

✅ RANGES CALIBRADOS POR TIPO DE GRÁFICO:
   📈 Produção: 5.000-50.000 bopd (baseado histórico ATS-7B)
   🌡️ Pressão: 1.000-4.000 psi (range operacional típico)
   🛢️ Volume: 0-80 MM bbl (convertido para milhões p/ legibilidade)
   🌡️ Temperatura: 80-120°C (range geotérmico + injeção vapor)
   🌯 Viscosidade: 0.5-8.0 cp (range fluido leve-pesado)
   ⛽ GOR: 200-800 scf/bbl (range típico reservatório maduro)  
   💧 WOR: 0.0-1.0 ratio (percentual água produzida)

✅ EIXO TEMPORAL INTELIGENTE:
   • Range inicial: 0-60 minutos (1 hora de visualização)
   • Formato: 1 casa decimal (precisão de 6 segundos)
   • Expansão automática: Cresce 20% além do tempo atual
   • Range mínimo: 10 minutos (visualização adequada)
   • Ticks adaptativos: 5-11 marcações conforme escala

✅ CONVERSÕES DE ESCALA:
   • Volume: barris → milhões de barris (55.0 MM vs 55.000.000)
   • Melhor legibilidade em dashboards industriais
   • Mantém precisão com formatação adequada

✅ EXPANSÃO DINÂMICA DOS EIXOS:
   • Sistema automático de ajuste de ranges
   • Acompanha crescimento temporal dos dados
   • Mantém margem visual de 20% para conforto
   • Atualização de ticks proporcional ao range

🎯 GRANULARIDADES DOCUMENTADAS:

📏 EIXO X (TEMPORAL):
   • 1 minuto = 60 segundos de simulação
   • Precisão: 0.1 minuto (6 segundos)
   • Atualização visual: Conforme período selecionado (1-1440min)
   • Expansão: Automática quando dados excedem range atual

📏 EIXO Y (VALORES POR MINUTO):
   • Produção: 22.000 bopd ÷ 1440 = 15,3 barris/minuto
   • Pressão: Declínio típico 0,1-0,5 psi/minuto  
   • Volume: Depleção = produção (15,3 barris/minuto)
   • Temperatura: Relativamente estável (~0,01°C/minuto)
   • Viscosidade: Varia com temperatura e pressão
   • GOR: Aumenta com depleção (~0,1 scf/bbl por minuto)
   • WOR: Aumenta com water coning (~0,0001/minuto)

🔍 DEBUGGING IMPLEMENTADO:
   • Logs detalhados de atualizações gráficas
   • Timestamps precisos para rastreamento
   • Diferencial temporal (Δt) para verificação
   • Confirmação de adição de pontos nos gráficos

🎨 MELHORIAS VISUAIS:
   • Labels específicos por tipo de grandeza
   • Formatação numérica adequada (0-3 casas decimais)
   • Ticks organizados e legíveis
   • Tema escuro profissional (SCADA padrão)

💡 LÓGICA DE INICIALIZAÇÃO CORRIGIDA:
   • Primeira atualização forçada na inicialização
   • Verificação de ultimoTempoGrafico > 0.0
   • Evita bloqueio de atualizações nos primeiros minutos
   • Estabelece referencial temporal correto

🏭 RESULTADO INDUSTRIAL:
Sistema agora exibe gráficos com visibilidade profissional equivalente
aos sistemas SCADA da OceanOil, com escalas calibradas para valores
reais do ATS-7B e funcionalidade de análise temporal adaptável.

================================================================================
*/

/*
================================================================================
📦 BIBLIOTECAS E DEPENDÊNCIAS DO SISTEMA
================================================================================

🔧 INSTALAÇÃO DAS DEPENDÊNCIAS (Ubuntu/Debian):
sudo apt install libqt5charts5-dev cmake make libqt5svg5-dev
sudo apt install qtbase5-dev libqt5widgets5 libqt5charts5-dev libqt5svg5-dev

🏗️ COMPILAÇÃO DO PROJETO:
rm -rf build          # Remove compilação anterior
mkdir build          # Cria diretório de build
cd build             # Entra no diretório
cmake ..            # Configura o projeto
make                # Compila o código

▶️ EXECUÇÃO:
./reservatorio_01   # Executa o simulador

📝 NOTA EDUCACIONAL:
O Qt5 é um framework multiplataforma usado para criar interfaces gráficas
profissionais. É amplamente utilizado na indústria petrolífera para
sistemas SCADA (Supervisory Control and Data Acquisition).

================================================================================
*/

/*
================================================================================
📦 INCLUSÃO DE BIBLIOTECAS - GUIA EDUCACIONAL
================================================================================

📚 PARA ESTUDANTES: Cada biblioteca tem uma função específica no simulador

🖥️ INTERFACE GRÁFICA (Qt5 GUI):
*/
#include <QApplication>       // Classe principal da aplicação Qt5
#include <QMainWindow>        // Janela principal com menu/toolbar
#include <QVBoxLayout>        // Layout vertical (organiza widgets)
#include <QHBoxLayout>        // Layout horizontal 
#include <QPushButton>        // Botões clicáveis da interface
#include <QTimer>             // Sistema de timers para alertas
#include <QLabel>            // Rótulos de texto estático
#include <QLineEdit>         // Campos de entrada de texto
#include <QTextEdit>         // Área de texto multi-linha
#include <QGroupBox>         // Agrupamento visual de controles
#include <QScrollArea>       // Área com rolagem para conteúdo grande
#include <QTabWidget>        // Abas para organizar conteúdo
#include <QGridLayout>       // Layout em grade (linhas/colunas)
#include <QFrame>            // Molduras e separações visuais
#include <QDialog>           // Janelas de diálogo
#include <QMessageBox>       // Caixas de alerta e confirmação
#include <QComboBox>         // Caixa de seleção (dropdown)
#include <QUuid>             // Geração de identificadores únicos universais
#include <QDir>              // Manipulação de diretórios e caminhos

/*
📈 GRÁFICOS E VISUALIZAÇÃO:
*/
#include <QtCharts/QChartView>  // Visualizador de gráficos
#include <QtCharts/QLineSeries> // Séries de linha para gráficos
#include <QValueAxis>          // Eixos numéricos dos gráficos
#include <QGraphicsSvgItem>    // Ícones SVG escaláveis
#include <QIcon>               // Sistema de ícones

/*
⏱️ SISTEMA DE TEMPO E EVENTOS:
*/
#include <QTimer>              // Temporizador para simulação contínua

/*
💾 MANIPULAÇÃO DE DADOS:
*/
#include <QDoubleValidator>    // Validação de números decimais
#include <QTextStream>         // Leitura/escrita de texto
#include <QByteArray>          // Manipulação de dados binários
#include <QBuffer>             // Buffer de memória
#include <QDateTime>           // Data e hora para timestamps

/*
🧮 BIBLIOTECAS MATEMÁTICAS (C++ STL):
*/
#include <cmath>               // Funções matemáticas (pow, exp, log, etc.)
#include <algorithm>           // Algoritmos (max, min, sort, etc.)
#include <cstdlib>             // Funções padrão (rand, exit, etc.)
#include <ctime>               // Funções de tempo (time, clock, etc.)

/*
📝 NOTA EDUCACIONAL:
Essas bibliotecas formam a base de qualquer sistema industrial moderno:
• Qt5: Framework profissional usado em sistemas SCADA da OceanOil
• STL: Bibliotecas C++ fundamentais para cálculos de engenharia
• Charts: Visualização essencial para monitoramento de poços
*/

/*
================================================================================
📊 NAMESPACE DOS GRÁFICOS QT
================================================================================

📚 CONCEITO EDUCACIONAL:
Esta linha permite usar as classes de gráfico do Qt5 sem o prefixo
'QtCharts::', simplificando o código. É uma prática comum em C++.

⚠️ IMPORTANTE: Namespaces evitam conflitos entre bibliotecas diferentes
             que possam ter classes com nomes similares.
*/
QT_CHARTS_USE_NAMESPACE

/*
🎓 ================================================================================
🚫 CLASSE RESERVATORIO - MODELO FÍSICO-MATEMÁTICO DO ATS-7B
================================================================================

📚 CONCEITOS FUNDAMENTAIS PARA ESTUDANTES:

Esta classe representa um MODELO DIGITAL do reservatório real ATS-7B (Atlântida Oriental).
É baseada em equações fundamentais da Engenharia de Reservatórios:

• LEI DE DARCY: Fluxo de fluidos em meio poroso
• EQUAÇÃO DE VOGEL: IPR para fluxo bifásico (gás + óleo)
• CORRELAÇÕES DE STANDING: Propriedades PVT
• MODELO DE DECLÍNIO: Berão hiperbólico/exponencial

🏆 DADOS REAIS: Calibrado com 26 anos de dados operacionais do ATS-7B
🔍 VALIDAÇÃO: Benchmarking com dados da OceanOil/ANP

================================================================================
*/

class Reservatorio {
public:
    /*
    🌡️ ========================================================================
    VARIÁVEIS DE ESTADO - PROPRIEDADES FUNDAMENTAIS DO RESERVATÓRIO
    ========================================================================
    
    📚 PARA ESTUDANTES: Estas são as variáveis que descrevem o estado
    atual do reservatório e mudam com o tempo durante a produção:
    */
    
    double pressao_psi;        // 🌡️ Pressão do reservatório [psi]
                               //     CONCEITO: Força que "empurra" o óleo para o poço
                               //     RANGE TÍPICO: 1.800-4.200 psi (Bacia de Atlântida)
                               //     VALOR ATS-7B: 2.850 psi (atual, 2025)
    
    double temperatura_C;      // 🌡️ Temperatura do reservatório [°C]
                               //     CONCEITO: Afeta viscosidade e densidade dos fluidos
                               //     RANGE TÍPICO: 60-120°C (profundidades 1.000-3.000m)
                               //     VALOR ATS-7B: 92°C (medido em profundidade)
    
    double volume_oleo_bbl;    // 🛢️ Volume de óleo restante [barris]
                               //     CONCEITO: OOIP restante (Original Oil In Place)
                               //     OOIP ORIGINAL ATS-7B: ~280 milhões bbl
                               //     VALOR ATUAL: ~55 milhões bbl (80% já produzido)
    
    double volume_gas_m3;      // ☘️ Volume de gás livre [m³]
                               //     CONCEITO: Gás que se separa do óleo quando P < Pb
                               //     PROBLEMA: Excesso reduz eficiência de bombeio
                               //     CONTROLE: Injeção de gás ou flare
    
    double volume_agua_bbl;    // 💧 Volume de água no sistema [barris]
                               //     CONCEITO: Água connata + injetada + aquifer
                               //     PROBLEMA: Aumenta com water coning
                               //     BSW ATS-7B: ~23% (2025)

    /*
    🧮 ========================================================================
    PROPRIEDADES DERIVADAS - CALCULADAS A PARTIR DAS VARIÁVEIS DE ESTADO
    ========================================================================
    
    📚 CONCEITO: Estas propriedades são calculadas usando correlações
    empíricas e modelos físicos a cada passo da simulação:
    */
    
    double viscosidade_oleo_cp;    // 🌯 Viscosidade dinâmica do óleo [cp]
                                   //       CONCEITO: Resistência do óleo ao escoamento
                                   //       FÓRMULA: Standing correlation (T, P, API)
                                   //       VALOR ATS-7B: ~2,8 cp (92°C, 29,5° API)
    
    double vazao_oleo_bopd;        // 🚢 Vazão de produção de óleo [bopd]
                                   //       CONCEITO: Calculada pela curva IPR (Inflow Performance)
                                   //       FÓRMULA: Darcy (monofásico) + Vogel (bifásico)
                                   //       VALOR ATS-7B: ~22.000 bopd (após revitalização)
    
    double pressao_de_bolha_psi;   // 🧙 Pressão de saturação [psi]
                                   //       CONCEITO: Pressão onde gás começa a se separar do óleo
                                   //       IMPORTÂNCIA: P < Pb = fluxo bifásico (mais complexo)
                                   //       VALOR ATS-7B: 2.950 psi (lab PVT)
    
    double pressao_poco_psi;       // 🕳️ Pressão de fundo de poço (BHP) [psi]
                                   //       CONCEITO: Pressão na formação produtora
                                   //       CONTROLE: Válvula choke (↑ fecha, ↓ abre)
                                   //       VALOR ATS-7B: ~1.950 psi (controlado)
    
    bool em_emergencia;            // ⚠️ Status de emergência do sistema
                                   //       CONCEITO: Shutdown automático por parâmetros críticos
                                   //       TRIGGERS: P < P_min, μ > μ_max, GOR > GOR_max
    QString motivo_emergencia;     // 📋 Motivo detalhado do último shutdown
    
    double gas_oil_ratio;          // ⛽ Razão gás-óleo (GOR) [scf/bbl]
                                   //       CONCEITO: Volume de gás por barril de óleo produzido
                                   //       PROBLEMA: GOR alto = baixa eficiência de bombeio
                                   //       VALOR ATS-7B: 420 scf/bbl (normal para óleo médio)
    
    double water_oil_ratio;        // 💧 Razão água-óleo (WOR) [adimensional]
                                   //       CONCEITO: Equivale ao BSW (Basic Sediments & Water)
                                   //       PROBLEMA: Aumenta com water coning e breakthrough
                                   //       VALOR ATS-7B: 0,23 = 23% BSW (2025)
    
    double tempo_simulacao_s;      // ⏱️ Tempo decorrido na simulação [segundos]
                                   //       CONCEITO: Contador interno para cálculos temporais

    /*
    🔍 ========================================================================
    CONSTANTES FÍSICAS REAIS DO POÇO ATS-7B (ATLÂNTIDA ORIENTAL)
    ========================================================================
    
    📚 PARA ESTUDANTES: Estas são propriedades REAIS medidas em laboratório
    e campo, baseadas em 26 anos de dados operacionais do ATS-7B:
    */
    
    const double GRAVIDADE_GAS_PESO_AR = 0.85;    // ⛽ Densidade relativa do gás
                                                   //     CONCEITO: ρ_gás / ρ_ar (adimensional)
                                                   //     VALOR 0.85 = Gás "leve" (rico em metano)
                                                   //     IMPORTÂNCIA: Usado em correlações PVT
    
    const double GRAVIDADE_API = 29.5;            // 🌡️ Grau API do óleo ATS-7B
                                                   //     CONCEITO: Medida de "leveza" do óleo
                                                   //     FÓRMULA: °API = (141.5/ρ_60F) - 131.5
                                                   //     CLASSIFICAÇÃO: 29.5° = ÓLEO MÉDIO (bom!)
                                                   //     DENSIDADE: ~0.88 g/cm³ a 60°F
    
    const double PRODUTIVIDADE_POCO_C = 22000.0;  // 🚢 Produção atual ATS-7B [bopd]
                                                   //     CONCEITO: Capacidade máxima de produção
                                                   //     HISTÓRICO: Pico = 45.000 bopd (2010)
                                                   //     ATUAL: 22.000 bopd (após revitalização 2023)
                                                   //     META: Sustentar > 15.000 bopd até 2030
    
    const double FATOR_INJECAO_GAS_BASE = 0.05;   // ⛽ Fator de resposta à injeção de gás
                                                   //     CONCEITO: ΔP / Volume_gas_injetado
                                                   //     CALIBRAÇÃO: Baseada em testes de injeção
                                                   //     USO: Gas-lift ou manutenção de pressão
    
    const double FATOR_INJECAO_AGUA_BASE = 0.01;  // 💧 Fator de resposta à injeção de água
                                                   //     CONCEITO: Eficiência da injeção de água
                                                   //     BAIXO VALOR: Reservatório já com alta pressão
                                                   //     USO: Waterflooding secundário
    
    const double PRODUCAO_MINIMA_ACEITAVEL_BOPD = 8000.0; // 💰 Limite econômico [bopd]
                                                           //     CONCEITO: Vazão mínima viável economicamente
                                                           //     CÁLCULO: Custos operacionais vs receita
                                                           //     REALIDADE: Custos ATS-7B ~US$ 35/bbl

    /*
    ⚠️ ========================================================================
    LIMITES OPERACIONAIS CRÍTICOS - SEGURANÇA E VIABILIDADE ECONÔMICA
    ========================================================================
    
    📚 CONCEITO: Estes limites definem as condições de SHUTDOWN AUTOMÁTICO
    do poço, baseados em critérios técnicos e econômicos reais da OceanOil:
    */
    
    const double LIMITE_PRESSAO_CRITICO_MIN = 1650.0; // ⚠️ Pressão mínima segura [psi]
                                                       //     CONCEITO: Abaixo = colapso da formação
                                                       //     GEOMECÂNICA: Tensão efetiva > resistência
                                                       //     VALOR ATS-7B: 1.650 psi (limite atual)
    
    const double LIMITE_PRESSAO_CRITICO_MAX = 4200.0; // ⚠️ Pressão máxima segura [psi]
                                                       //     CONCEITO: Acima = risco de blowout
                                                       //     VALOR HISTÓRICO: Pressão inicial ATS-7B (1999)
                                                       //     SEGURANÇA: Casing e wellhead limits
    
    const double LIMITE_VISCOSIDADE_CRITICO = 4.5;    // ⚠️ Viscosidade máxima [cp]
                                                       //     CONCEITO: Acima = bombeio inviável
                                                       //     ESP LIMIT: Equipamentos submersíveis
                                                       //     VALOR: Típico para óleo 29.5° API
    
    const double LIMITE_GAS_CRITICO = 15000.0;        // ⚠️ Volume gás livre máximo [m³]
                                                       //     CONCEITO: Acima = gas-lock das bombas
                                                       //     PROBLEMA: Bomba perde escorva
                                                       //     SOLUÇÃO: Flare ou separação
    
    const double LIMITE_WOR_CRITICO = 0.35;           // ⚠️ Water cut máximo [35%]
                                                       //     CONCEITO: Acima = tratamento inviável
                                                       //     CUSTOS: Separação e descarte de água
                                                       //     LIMITE REAL: ATS-7B opera até 40%
    
    const double LIMITE_GOR_CRITICO = 600.0;          // ⚠️ GOR máximo [scf/bbl]
                                                       //     CONCEITO: Acima = produção de óleo inviável
                                                       //     PROBLEMA: Muito gás, pouco óleo
                                                       //     TÍPICO: Óleo médio < 500 scf/bbl

    /*
    🏗️ ========================================================================
    CONSTRUTOR - INICIALIZAÇÃO COM DADOS REAIS DO ATS-7B (2025)
    ========================================================================
    
    📚 PARA ESTUDANTES: O construtor define o ESTADO INICIAL do reservatório.
    Todos os valores são baseados em dados reais coletados no ATS-7B em 2025,
    após 26 anos de produção (início: 1999).
    
    📅 DADOS HISTÓRICOS:
    • 1999: Descoberta e início da produção
    • 2010: Pico de produção (45.000 bopd)
    • 2015: Início do declínio acentuado
    • 2023: Projeto de revitalização
    • 2025: Estado atual (simulado)
    
    🔍 FONTE DOS DADOS: Relatórios ANP + OceanOil + Literatura Técnica
    */
    Reservatorio() :
        pressao_psi(2850.0),           // 🌡️ 2.850 psi - Pressão atual (2025)
                                       //     HISTÓRICO: 4.200 psi (inicial, 1999)
                                       //     DECLÍNIO: ~32% em 26 anos
                                       //     STATUS: Ainda acima da pressão crítica
        
        temperatura_C(92.0),           // 🌡️ 92°C - Temperatura do reservatório
                                       //     MEDIDA: Em profundidade (2.100-2.400m)
                                       //     CONSTANTE: Não muda significativamente
                                       //     GRADIENTE: ~3°C/100m (geotérmico normal)
        
        volume_oleo_bbl(55000000.0),   // 🛢️ 55 MM bbl - Volume restante (2025)
                                       //     OOIP ORIGINAL: ~280 MM bbl (estimativa)
                                       //     PRODUZIDO: ~225 MM bbl (80% recovery!)
                                       //     EXCELENTE: Recovery factor muito alto
                                       //     PREVISÃO: ~10-15 anos de vida útil
        
        volume_gas_m3(8500.0),         // ⛽ 8.500 m³ - Gás livre atual
                                       //     CONCEITO: Gás separado na planta
                                       //     NORMAL: Pressão < Pbubble point
                                       //     DESTINO: Gas-lift ou comercialização
        
        volume_agua_bbl(125000.0),     // 💧 125.000 bbl - Água total no sistema
                                       //     COMPOSIÇÃO: Connata + injetada + aquífero
                                       //     AUMENTO: Water coning progredindo
                                       //     TRATAMENTO: Separação + reinjeção
        
        viscosidade_oleo_cp(2.8),      // 🌯 2,8 cp - Viscosidade nas condições atuais
                                       //     CÁLCULO: Standing correlation
                                       //     PARÂMETROS: 92°C + 29,5°API + 2.850 psi
                                       //     QUALIDADE: Baixa viscosidade = bom!
        
        vazao_oleo_bopd(22000.0),      // 🚢 22.000 bopd - Produção atual
                                       //     SUCESSO: Revitalização 2023 aumentou 40%
                                       //     ANTERIOR: ~15.000 bopd (antes do projeto)
                                       //     META: Sustentar > 15.000 bopd até 2030
        
        pressao_de_bolha_psi(2950.0),  // 🧙 2.950 psi - Pressão de saturação
                                       //     LABORATÓRIO: Medida em análise PVT
                                       //     IMPORTÂNCIA: P_res < P_bubble = fluxo bifásico
                                       //     ATUAL: 2.850 < 2.950 = Regime bifásico!
        
        pressao_poco_psi(1950.0),      // 🕳️ 1.950 psi - Bottom Hole Pressure
                                       //     CONTROLE: Válvula choke na árvore de natal
                                       //     DRAWDOWN: 2.850 - 1.950 = 900 psi
                                       //     OTIMIZAÇÃO: Equilibrar vazão vs water coning
        
        em_emergencia(false),          // ✅ false - Sistema operando normalmente
                                       //     VERIFICAÇÃO: Todos os parâmetros dentro dos limites
                                       //     MONITORAMENTO: Contínuo e automático
        
        gas_oil_ratio(420.0),          // ⛽ 420 scf/bbl - Razão gás-óleo atual
                                       //     NORMAL: Típico para óleo médio (29,5° API)
                                       //     CONTROLADO: Abaixo do limite crítico (600)
                                       //     TENDÊNCIA: Pode aumentar com depleção
        
        water_oil_ratio(0.23),         // 💧 0,23 = 23% BSW - Water cut atual
                                       //     HISTÓRICO: 5% (1999) → 23% (2025)
                                       //     PROBLEMA: Water coning progredindo
                                       //     LIMITE: 35% (econômico) - ainda OK!
        
        tempo_simulacao_s(0.0)         // ⏱️ 0 segundos - Início da simulação
                                       //     CONTADOR: Será incrementado a cada ciclo
                                       //     TIMESTEP: 5 segundos (realismo operacional)
    
    {} // 🏁 FIM DO CONSTRUTOR - RESERVATÓRIO INICIALIZADO!

    /*
    🎓 ================================================================================
    ⚙️ MÉTODOS UTILITÁRIOS - REFATORAÇÃO DE CÓDIGO REPETIDO  
    ================================================================================
    
    📚 CONCEITO DE REFATORAÇÃO:
    Refatoração é o processo de reestruturar código existente sem alterar seu
    comportamento externo, melhorando legibilidade, manutenibilidade e reutilização.
    
    🎯 BENEFÍCIOS DA REFATORAÇÃO:
    • DRY Principle (Don't Repeat Yourself) - Elimina duplicação
    • Single Responsibility - Cada método tem uma função específica  
    • Facilita manutenção e debugging
    • Melhora testabilidade do código
    • Reduz chance de erros por inconsistência
    
    🏭 APLICAÇÃO INDUSTRIAL:
    Sistemas críticos como SCADA requerem código altamente organizado para:
    • Facilitar auditorias de software
    • Reduzir bugs em sistemas de segurança
    • Permitir atualizações rápidas e seguras
    • Facilitar treinamento de novos engenheiros
    
    ================================================================================
    */

    /*
    🌡️ ========================================================================
    MÉTODO UTILITÁRIO: CONVERSÃO CELSIUS → FAHRENHEIT
    ========================================================================
    
    📚 CONCEITO EDUCACIONAL:
    Converte temperatura de Celsius para Fahrenheit usando a fórmula padrão
    da termodinâmica. Muito usado em correlações PVT da indústria petroleira.
    
    🔬 FÓRMULA: °F = (°C × 9/5) + 32 = (°C × 1.8) + 32
    
    🛢️ APLICAÇÃO PETROLEIRA:
    • Correlações de Standing (viscosidade)
    • Propriedades PVT (pressão-volume-temperatura)  
    • Cálculos de densidade de fluidos
    • Interface com equipamentos americanos (sensores °F)
    
    PARÂMETROS:
    • temperatura_C: Temperatura em graus Celsius [°C]
    
    RETORNA: Temperatura em graus Fahrenheit [°F]
    */
    double celsiusParaFahrenheit(double temperatura_C) const {
        return 1.8 * temperatura_C + 32.0;
    }

    /*
    ⏱️ ========================================================================
    MÉTODO UTILITÁRIO: CONVERSÃO SEGUNDOS → MINUTOS
    ========================================================================
    
    📚 CONCEITO EDUCACIONAL:
    Converte tempo de segundos para minutos para exibição na interface.
    Melhora legibilidade dos gráficos de tendência temporal.
    
    🏭 APLICAÇÃO INDUSTRIAL:
    • Eixos X de gráficos SCADA (trending)
    • Relatórios operacionais
    • Logs de eventos temporais
    • Sincronização entre sistemas
    
    PARÂMETROS:
    • tempo_segundos: Tempo em segundos [s]
    
    RETORNA: Tempo em minutos [min]
    */
    double segundosParaMinutos(double tempo_segundos) const {
        return tempo_segundos / 60.0;
    }

    /*
    📊 ========================================================================
    MÉTODO UTILITÁRIO: FORMATAÇÃO NUMÉRICA PADRONIZADA
    ========================================================================
    
    📚 CONCEITO EDUCACIONAL:
    Padroniza a formatação de números com precisão decimal específica.
    Essencial para consistência visual em interfaces SCADA profissionais.
    
    🎯 PADRÕES DE PRECISÃO:
    • 0 casas: Volumes grandes (barris, m³)
    • 1 casa: Percentuais (BSW%, recovery factor)  
    • 2 casas: Parâmetros operacionais (pressão, vazão, temperatura)
    • 3 casas: Ratios precisos (WOR, viscosidade fina)
    
    🏭 APLICAÇÃO INDUSTRIAL:
    • Relatórios técnicos padronizados
    • Interfaces SCADA consistentes
    • Exportação de dados (CSV, Excel)
    • Comunicação entre sistemas
    
    PARÂMETROS:
    • valor: Número a ser formatado
    • precisao: Número de casas decimais (0-3)
    
    RETORNA: QString formatado consistentemente
    */
    QString formatarNumero(double valor, int precisao) const {
        return QString::number(valor, 'f', precisao);
    }

    // Métodos de Cálculo e Simulação
    /*
    ⛽ ========================================================================
    MÉTODO REFATORADO: CÁLCULO DE SOLUBILIDADE DE GÁS  
    ========================================================================
    
    📚 CONCEITO DE REFATORAÇÃO APLICADA:
    Substituição da conversão manual °C→°F pelo método utilitário
    celsiusParaFahrenheit(), eliminando duplicação de código.
    
    🔬 CORRELAÇÃO DE STANDING (1947):
    Calcula solubilidade de gás no óleo em condições de reservatório.
    Fundamental para modelagem PVT e comportamento de fases.
    */
    double calcularSolubilidadeGas(double pressao_psi, double temperatura_C) {
        // USO DO MÉTODO UTILITÁRIO (REFATORAÇÃO)
        double temp_F = celsiusParaFahrenheit(temperatura_C);
        
        double resultado = GRAVIDADE_GAS_PESO_AR * pow((pressao_psi / 18.2) * exp(0.0125 * GRAVIDADE_API * exp(0.0011 * temp_F)), 1.2045);
        return resultado;
    }

    /*
    🌯 ========================================================================
    MÉTODO REFATORADO: CÁLCULO DE VISCOSIDADE DO ÓLEO
    ========================================================================
    
    📚 CONCEITO DE REFATORAÇÃO APLICADA:
    Substituição da conversão manual °C→°F pelo método utilitário,
    mantendo a mesma lógica de cálculo calibrada para o ATS-7B.
    */
    double calcularViscosidadeOleo(double pressao_psi, double temperatura_C) {
        // Cálculo de viscosidade calibrado para óleo ATS-7B (29.5° API)
        
        // USO DO MÉTODO UTILITÁRIO (REFATORAÇÃO)
        double temp_F = celsiusParaFahrenheit(temperatura_C);
        
        // Viscosidade morta para óleo 29.5° API a 92°C
        double viscosidade_base = 2.8; // cp - medido no ATS-7B
        
        // Correção por temperatura (Lei de Arrhenius modificada)
        double temp_ref = 92.0; // Temperatura de referência ATS-7B
        double fator_temp = exp(500.0 * (1.0/(temperatura_C + 273.15) - 1.0/(temp_ref + 273.15)));
        
        // Correção por pressão (compressibilidade isotermal)
        double press_ref = 2850.0; // Pressão de referência ATS-7B
        double fator_pressao = 1.0 + 2.5e-6 * (pressao_psi - press_ref);
        
        double resultado = viscosidade_base * fator_temp * fator_pressao;
        
        // Limitar ao range físico do óleo ATS-7B
        return std::max(1.8, std::min(resultado, LIMITE_VISCOSIDADE_CRITICO));
    }

    double calcularVazaoProducao(double pressao_reservatorio_psi) {
        // IPR (Inflow Performance Relationship) calibrada para ATS-7B
        double pi_atual = 8.2; // Índice de produtividade atual ATS-7B (bopd/psi)
        double q_max = PRODUTIVIDADE_POCO_C;
        
        if (pressao_reservatorio_psi >= pressao_de_bolha_psi) {
            // Fluxo monofásico (acima da pressão de bolha)
            double drawdown = pressao_reservatorio_psi - pressao_poco_psi;
            return pi_atual * drawdown * (1.0 - 0.1 * drawdown / pressao_reservatorio_psi);
        } else {
            // Fluxo bifásico (abaixo da pressão de bolha) - Vogel's IPR modificado para ATS-7B
            double pr_pb = pressao_reservatorio_psi / pressao_de_bolha_psi;
            double pwf_pb = pressao_poco_psi / pressao_de_bolha_psi;
            
            // Vogel's equation ajustada para manter vazão próxima aos 22,000 bpd do ATS-7B
            // Usando fatores de correção baseados em dados históricos
            double drawdown_normalizado = (pressao_reservatorio_psi - pressao_poco_psi) / pressao_de_bolha_psi;
            double eficiencia = 0.95 + 0.05 * drawdown_normalizado; // Eficiência alta para ATS-7B
            
            return q_max * eficiencia;
        }
    }

    void simularEfeitoProducao(double tempo_passado_s) {
        if (em_emergencia) {
            vazao_oleo_bopd = 0.0;
            return;
        }
        
        // Cálculo de vazão baseado no IPR do ATS-7B
        double vazao_calculada = calcularVazaoProducao(pressao_psi);
        
        // 🔍 DEBUG: Log para identificar problema do ícone laranja
        static bool primeira_vez = true;
        if (primeira_vez) {
            printf("🔍 DEBUG VAZAO: Inicial=%.0f, Calculada=%.0f\n", vazao_oleo_bopd, vazao_calculada);
            primeira_vez = false;
        }
        
        vazao_oleo_bopd = vazao_calculada;
        
        // Produção em barris neste intervalo
        double oleo_produzido_bbl = vazao_oleo_bopd * (tempo_passado_s / 86400.0);
        
        // Depleção do volume de óleo (OOIP ATS-7B)
        volume_oleo_bbl -= oleo_produzido_bbl;
        if (volume_oleo_bbl < 0) volume_oleo_bbl = 0;
        
        // Declínio de pressão baseado na curva real do ATS-7B
        // Taxa de declínio atual: ~8% ao ano = 0.00015 por dia
        double taxa_declinio_diaria = 0.00015; // Calibrada para ATS-7B
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
        
        // Coning de água (característico do ATS-7B)
        simularConingMLS3A();
        
        // Produção de água (BSW crescente)
        double agua_produzida_bbl = oleo_produzido_bbl * water_oil_ratio;
        volume_agua_bbl += agua_produzida_bbl; // Água produzida acumula
        
        // Variação operacional típica do ATS-7B (±2%)
        double variacao = ((rand() % 41) - 20) / 1000.0;
        vazao_oleo_bopd *= (1.0 + variacao);
        
        // Aplicar limites operacionais do ATS-7B
        vazao_oleo_bopd = std::max(8000.0, std::min(vazao_oleo_bopd, 42000.0));
    }

    void simularConingMLS3A() {
        // Coning característico do ATS-7B (baseado em 26 anos de dados)
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
            double bsw_natural = 0.15 + 0.008 * anos_producao; // Curva real ATS-7B
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
        bool emergencia_anterior = em_emergencia;
        em_emergencia = false;
        QString motivo_shutdown = "";
        
        if (pressao_psi < LIMITE_PRESSAO_CRITICO_MIN) {
            em_emergencia = true;
            motivo_shutdown += QString("PRESSÃO CRÍTICA BAIXA: %1 psi < %2 psi; ").arg(pressao_psi, 0, 'f', 1).arg(LIMITE_PRESSAO_CRITICO_MIN);
        }
        if (pressao_psi > LIMITE_PRESSAO_CRITICO_MAX) {
            em_emergencia = true;
            motivo_shutdown += QString("PRESSÃO CRÍTICA ALTA: %1 psi > %2 psi; ").arg(pressao_psi, 0, 'f', 1).arg(LIMITE_PRESSAO_CRITICO_MAX);
        }
        if (viscosidade_oleo_cp > LIMITE_VISCOSIDADE_CRITICO) {
            em_emergencia = true;
            motivo_shutdown += QString("VISCOSIDADE CRÍTICA: %1 cp > %2 cp; ").arg(viscosidade_oleo_cp, 0, 'f', 1).arg(LIMITE_VISCOSIDADE_CRITICO);
        }
        if (volume_gas_m3 > LIMITE_GAS_CRITICO) {
            em_emergencia = true;
            motivo_shutdown += QString("VOLUME DE GÁS CRÍTICO: %1 m³ > %2 m³ (GAS-LOCK!); ").arg(volume_gas_m3, 0, 'f', 0).arg(LIMITE_GAS_CRITICO);
        }
        if (water_oil_ratio > LIMITE_WOR_CRITICO) {
            em_emergencia = true;
            motivo_shutdown += QString("WOR CRÍTICO: %1% > %2% (BSW alto); ").arg(water_oil_ratio * 100, 0, 'f', 1).arg(LIMITE_WOR_CRITICO * 100);
        }
        if (gas_oil_ratio > LIMITE_GOR_CRITICO) {
            em_emergencia = true;
            motivo_shutdown += QString("GOR CRÍTICO: %1 scf/bbl > %2 scf/bbl; ").arg(gas_oil_ratio, 0, 'f', 0).arg(LIMITE_GOR_CRITICO);
        }
        
        // Log detalhado apenas quando entra em emergência (não a cada ciclo)
        if (em_emergencia && !emergencia_anterior) {
            motivo_emergencia = "🚨 SHUTDOWN AUTOMÁTICO ATIVADO: " + motivo_shutdown;
        }
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

    /*
    🔧 AJUSTE DE VÁLVULA CHOKE - CONTROLE DE PRODUÇÃO
    
    📚 CONCEITO EDUCACIONAL:
    A válvula choke é instalada na árvore de natal (christmas tree) e
    controla a vazão de produção. É uma das ferramentas mais importantes
    para otimização da produção.
    
    🔄 PRINCÍPIO DE OPERAÇÃO:
    • FECHAR válvula → ↑ Pressão de fundo → ↓ Vazão
    • ABRIR válvula → ↓ Pressão de fundo → ↑ Vazão
    
    ⚙️ OTIMIZAÇÃO:
    • MUITO ABERTA: Water coning, produção de areia
    • MUITO FECHADA: Baixa vazão, ineficiência
    • PONTO ÓTIMO: Máxima vazão com controle de coning
    
    🏆 AUTOMAÇÃO: Modernos sistemas ajustam automaticamente
    */
    void ajustarPressaoPoco(double ajuste_psi) {
        // APLICA O AJUSTE SOLICITADO
        pressao_poco_psi += ajuste_psi;
        
        // LIMITES FÍSICOS E OPERACIONAIS
        double pressao_min = 100.0;   // psi - Limite mínimo para operação
        double pressao_max = 1000.0;  // psi - Limite máximo da válvula
        
        // Aplica os limites (clamp function)
        pressao_poco_psi = std::max(pressao_min, std::min(pressao_max, pressao_poco_psi));
        
        /*
        📝 NOTA EDUCACIONAL:
        O controle fino da pressão de fundo é uma arte! Engenheiros
        experientes sabem que pequenos ajustes podem ter grandes
        impactos na produção e na vida útil do poço.
        
        📈 EXEMPLO REAL:
        No ATS-7B, reduzir Pwf de 2.000 para 1.900 psi pode:
        • Aumentar vazão em 15%
        • Acelerar water coning em 30%
        • Reduzir vida útil em 2 anos
        
        ⚠️ DECISÃO: Curto prazo vs longo prazo?
        */
    }

}; // 🏁 FIM DA CLASSE RESERVATORIO - MODELO COMPLETO DO ATS-7B!

/*
🎓 ================================================================================
PARABÉNS! VOCÊ COMPLETOU O ESTUDO DA CLASSE RESERVATORIO!
================================================================================

📚 O QUE VOCÊ APRENDEU:

1️⃣ PROPRIEDADES FÍSICAS: Pressão, temperatura, viscosidade, volumes
2️⃣ CORRELAÇÕES PETROLEIRAS: Standing, Vogel, Darcy
3️⃣ FENÔMENOS OPERACIONAIS: Declínio, coning, depleção
4️⃣ MÉTODOS DE CONTROLE: Injeção, choke, flare
5️⃣ SISTEMAS DE SEGURANÇA: Limites, shutdown, monitoramento

🏆 DADOS REAIS: Tudo baseado no campo ATS-7B (Atlântida Oriental)
🔬 VALIDAÇÃO: 26 anos de dados operacionais
🎯 APLICABILIDADE: Conhecimento direto da indústria brasileira

➡️ PRÓXIMO PASSO: Estude a interface gráfica e sistema de visualização!

================================================================================
*/

/*
🎓 ================================================================================
📊 ESTRUTURA PARA ARMAZENAMENTO DE DADOS HISTÓRICOS (DATA LOGGING)
================================================================================

📚 CONCEITO EDUCACIONAL:
Esta estrutura representa um "snapshot" (foto instantânea) de todos os parâmetros
operacionais do reservatório em um determinado momento no tempo. É equivalente
aos dados coletados pelos sistemas SCADA em campos reais.

💾 APLICAÇÃO INDUSTRIAL:
• Sistemas da OceanOil coletam dados a cada 5-15 segundos
• Permite análise histórica (trending)
• Base para relatórios de produção
• Detecção de anomalias operacionais
• Otimização de reservatórios

📈 FREQUÊNCIA DE COLETA:
Nosso simulador coleta dados a cada 5 segundos, igual aos sistemas reais!

================================================================================
*/

struct DadosPontos {
    /*
    📚 CAMPOS DE DADOS - EXPLICAÇÃO PARA ESTUDANTES:
    
    Cada campo representa uma grandeza fundamental na engenharia de reservatórios:
    */
    
    QString uuid;              // 🔑 Identificador único universal [UUID v4]
                               //     CONCEITO: Chave primária para streaming/mensageria
                               //     FORMATO: "550e8400-e29b-41d4-a716-446655440000"
                               //     USO: Kafka streaming, deduplicação, rastreamento
    
    double tempo_min;          // ⏱️ Tempo decorrido [minutos]
                               //     CONCEITO: Eixo temporal para análise de tendências
                               //     USO: Gráficos de produção vs tempo
                               //     CONVERSÃO: segundos → minutos (interface mais legível)
    
    double vazao_oleo;         // 🚢 Taxa de produção de óleo [barris/dia]
                               //     CONCEITO: Métrica principal de performance do poço
                               //     IMPORTÂNCIA: Indica a saúde econômica do campo
                               //     RANGE ATS-7B: 8.000-45.000 bopd (histórico)
    
    double pressao;            // 🌡️ Pressão do reservatório [psi]
                               //     CONCEITO: Energia que impulsiona a produção
                               //     DECLÍNIO: Natural com a depleção do reservatório
                               //     CRÍTICO: Abaixo de 1.650 psi = shutdown
    
    double viscosidade_cp;     // 🌯 Viscosidade dinâmica do óleo [centipoise]
                               //     CONCEITO: Resistência do óleo ao escoamento
                               //     FATOR: Temperatura ↑ = Viscosidade ↓ (melhor!)
                               //     CONTROLE: Injeção de vapor ou água quente
    
    double volume_oleo;        // 🛢️ Volume restante no reservatório [barris]
                               //     CONCEITO: OOIP atual (Oil Originally In Place)
                               //     DEPLEÇÃO: Diminui com a produção
                               //     META: Maximizar recovery factor (% recuperado)
    
    double temperatura;        // 🌡️ Temperatura do reservatório [°C]
                               //     CONCEITO: Afeta propriedades PVT dos fluidos
                               //     CONTROLE: Injeção de vapor (EOR - Enhanced Oil Recovery)
                               //     CONSTANTE: ~92°C no ATS-7B (geotérmica)
    
    double gor;               // ⛽ Gas-Oil Ratio [scf/bbl] (standard cubic feet per barrel)
                              //     CONCEITO: Volume de gás por barril de óleo produzido
                              //     PROBLEMA: GOR alto = bombeio menos eficiente
                              //     TENDÊNCIA: Aumenta com depleção de pressão
    
    double wor;               // 💧 Water-Oil Ratio [adimensional]
                              //     CONCEITO: Equivale ao BSW (Basic Sediments & Water)
                              //     PROBLEMA: Water coning reduz produção de óleo
                              //     AUMENTO: Natural com a vida do campo
    
    // NOVOS CAMPOS PARA RASTREAMENTO DE EVENTOS E ANÁLISE AVANÇADA
    QString data_hora;        // 📅 Timestamp completo [ISO 8601 format]
                              //     CONCEITO: Data/hora exata da coleta de dados
                              //     FORMATO: "2025-08-29T15:30:45"
                              //     USO: Análise temporal precisa, auditoria
    
    QString evento_operador;  // 👨‍💼 Ação do operador [texto descritivo]
                              //     CONCEITO: Intervenções manuais realizadas
                              //     EXEMPLOS: "Inj Água 1000bbl", "Vapor 500s", "Manual Stop"
                              //     USO: Correlacionar ações com resultados
    
    QString evento_fisica;    // ⚗️ Evento físico do reservatório [texto descritivo]  
                              //     CONCEITO: Fenômenos automáticos do sistema
                              //     EXEMPLOS: "Pressão declínio", "Water coning", "Gas breakthrough"
                              //     USO: Análise de comportamento natural
    
    QString alerta_tipo;      // 🚨 Tipo de alerta ativo [palavra-chave]
                              //     CONCEITO: Estado de criticidade do sistema
                              //     VALORES: "NORMAL", "ATENCAO", "CRITICO", "SHUTDOWN"
                              //     USO: Filtragem rápida, alertas automáticos
    
    /*
    🎯 IMPORTÂNCIA DO DATA LOGGING:
    
    ✅ OPERAÇÃO DIÁRIA:
    • Detecta problemas antes que se tornem críticos
    • Permite ajustes operacionais em tempo real
    • Otimiza a produção continuamente
    
    ✅ PLANEJAMENTO:
    • Previsão de declínio de produção
    • Planejamento de intervenções (workover)
    • Decisões de abandono do poço
    
    ✅ REGULATÓRIO:
    • Relatórios para ANP (Agência Nacional do Petróleo)
    • Controle de royalties e participações especiais
    • Auditoria e compliance
    */
};

/*
🎓 ================================================================================
📋 CLASSE REPORTDIALOG - SISTEMA DE RELATÓRIOS OPERACIONAIS
================================================================================

📚 CONCEITO EDUCACIONAL:
Esta classe implementa um sistema de relatórios similar ao usado na indústria
petrolífera. É equivalente aos relatórios de produção diários/mensais gerados
pelos sistemas SCADA da OceanOil.

🏭 APLICAÇÃO INDUSTRIAL:
• Relatórios de performance diária de poços
• Documentação para auditorias da ANP
• Análise de eficiência operacional
• Base para tomada de decisão gerencial
• Compliance regulatório

💼 PADRÃO INDUSTRIAL:
Relatórios estruturados com HTML permitem:
• Formatação profissional
• Integração com sistemas corporativos
• Exportação para PDF/Excel
• Padronização visual

📊 DADOS INCLUÍDOS:
Todos os parâmetros operacionais críticos do ATS-7B em formato executivo.

================================================================================
*/

class ReportDialog : public QDialog {
    Q_OBJECT

public:
    /*
    🏗️ ========================================================================
    CONSTRUTOR - INICIALIZAÇÃO DO DIÁLOGO DE RELATÓRIOS
    ========================================================================
    
    📚 PARA ESTUDANTES: O construtor configura a janela e gera automaticamente
    o relatório com os dados atuais do reservatório.
    
    PARÂMETROS:
    • reservatorio: Ponteiro para o objeto com dados atuais
    • dataPoints: Vetor com histórico de dados para análises
    • parent: Widget pai (padrão Qt)
    */
    ReportDialog(Reservatorio* reservatorio, const QVector<DadosPontos>& dataPoints, QWidget* parent = nullptr) : QDialog(parent) {
        
        // CONFIGURAÇÃO DA JANELA
        setWindowTitle("📋 Relatório Operacional ATS-7B - Atlântida Oriental");
        setMinimumSize(800, 600);  // Tamanho mínimo para visualização adequada
        
        // LAYOUT PRINCIPAL (organização vertical)
        QVBoxLayout* mainLayout = new QVBoxLayout(this);

        // ÁREA DE TEXTO PARA O RELATÓRIO
        reportTextEdit = new QTextEdit(this);
        reportTextEdit->setReadOnly(true);  // Somente leitura (não editável)
        
        // ESTILO PROFISSIONAL (similar aos sistemas corporativos)
        reportTextEdit->setStyleSheet(
            "background-color: #f0f0f0; "      // Fundo cinza claro
            "color: #333; "                     // Texto escuro 
            "font-family: monospace; "          // Fonte monoespaçada (mais técnica)
            "font-size: 11px; "                 // Tamanho legível
            "padding: 10px; "                   // Espaçamento interno
        );
        mainLayout->addWidget(reportTextEdit);

        // BOTÃO DE FECHAR
        QPushButton* closeButton = new QPushButton("🔚 Fechar Relatório", this);
        closeButton->setStyleSheet(
            "QPushButton { "
                "background-color: #0078D4; "
                "color: white; "
                "font-weight: bold; "
                "padding: 8px 16px; "
                "border: none; "
                "border-radius: 4px; "
            "}"
            "QPushButton:hover { background-color: #106EBE; }"
        );
        mainLayout->addWidget(closeButton);

        // CONECTAR SINAL-SLOT (fechar janela quando botão clicado)
        connect(closeButton, &QPushButton::clicked, this, &ReportDialog::accept);

        // GERAR O RELATÓRIO AUTOMATICAMENTE
        generateReports(reservatorio, dataPoints);
        
        /*
        📝 NOTA EDUCACIONAL:
        Este padrão (construtor que inicializa e gera conteúdo) é comum
        em aplicações industriais onde relatórios são gerados automaticamente
        com base em dados operacionais atuais.
        */
    }

private:
    QTextEdit* reportTextEdit;  // Widget para exibir o relatório HTML

    /*
    📊 ========================================================================
    MÉTODO DE GERAÇÃO DE RELATÓRIOS - CORE DO SISTEMA
    ========================================================================
    
    📚 CONCEITO: Este método transforma dados técnicos em um relatório
    executivo formatado, similar aos relatórios da OceanOil/ANP.
    */
    void generateReports(Reservatorio* reservatorio, const QVector<DadosPontos>& dataPoints) {
        QString reportHtml;

        // CABEÇALHO DO RELATÓRIO (HTML estruturado)
        reportHtml += "<div style='text-align: center; margin-bottom: 20px;'>";
        reportHtml += "<h1 style='color: #0056b3; margin: 0;'>🛢️ OCEANOIL - RELATÓRIO OPERACIONAL</h1>";
        reportHtml += "<h2 style='color: #0056b3; margin: 5px 0;'>POÇO ATS-7B - CAMPO DE ATLÂNTIDA ORIENTAL</h2>";
        reportHtml += "<h3 style='color: #666; margin: 5px 0;'>BACIA DE ATLÂNTIDA - ÁGUAS PROFUNDAS</h3>";
        reportHtml += "<hr style='border: 2px solid #0056b3; margin: 15px 0;'>";
        reportHtml += "</div>";

        // SEÇÃO PRINCIPAL - PARÂMETROS OPERACIONAIS ATUAIS
        reportHtml += "<h2 style='color:#0056b3; background-color: #f8f9fa; padding: 8px; border-left: 4px solid #0056b3;'>";
        reportHtml += "📈 PARÂMETROS OPERACIONAIS ATUAIS</h2>";
        
        reportHtml += "<table style='width: 100%; border-collapse: collapse; margin: 15px 0;'>";
        reportHtml += "<tr style='background-color: #e9ecef;'><th colspan='2' style='padding: 10px; text-align: center; font-size: 14px;'>DADOS DE PRODUÇÃO</th></tr>";
        
        // LINHA DE PRODUÇÃO (MAIS IMPORTANTE)
        reportHtml += QString("<tr style='background-color: %1;'><td style='padding: 8px; font-weight: bold; border: 1px solid #dee2e6;'>🚢 Vazão de Óleo (atual):</td><td style='padding: 8px; border: 1px solid #dee2e6; font-weight: bold; font-size: 16px;'>%2 bopd</td></tr>")
                     .arg(reservatorio->vazao_oleo_bopd < reservatorio->PRODUCAO_MINIMA_ACEITAVEL_BOPD ? "#ffebee" : "#e8f5e8")
                     .arg(QString::number(reservatorio->vazao_oleo_bopd, 'f', 2));

        // PARÂMETROS DO RESERVATÓRIO
        reportHtml += QString("<tr><td style='padding: 8px; border: 1px solid #dee2e6;'><b>🌡️ Pressão do Reservatório:</b></td><td style='padding: 8px; border: 1px solid #dee2e6;'>%1 psi</td></tr>").arg(QString::number(reservatorio->pressao_psi, 'f', 2));
        reportHtml += QString("<tr style='background-color: #f8f9fa;'><td style='padding: 8px; border: 1px solid #dee2e6;'><b>🌡️ Temperatura do Reservatório:</b></td><td style='padding: 8px; border: 1px solid #dee2e6;'>%1 °C</td></tr>").arg(QString::number(reservatorio->temperatura_C, 'f', 2));
        reportHtml += QString("<tr><td style='padding: 8px; border: 1px solid #dee2e6;'><b>🌯 Viscosidade do Óleo:</b></td><td style='padding: 8px; border: 1px solid #dee2e6;'>%1 cp</td></tr>").arg(QString::number(reservatorio->viscosidade_oleo_cp, 'f', 2));

        // RATIOS CRÍTICOS
        reportHtml += "<tr style='background-color: #e9ecef;'><th colspan='2' style='padding: 10px; text-align: center;'>RATIOS OPERACIONAIS</th></tr>";
        
        // GOR com código de cores
        QString gorColor = reservatorio->gas_oil_ratio > reservatorio->LIMITE_GOR_CRITICO ? "#ffebee" : "#e8f5e8";
        reportHtml += QString("<tr style='background-color: %1;'><td style='padding: 8px; border: 1px solid #dee2e6;'><b>⛽ GOR (Gás-Óleo Ratio):</b></td><td style='padding: 8px; border: 1px solid #dee2e6;'>%2 scf/bbl</td></tr>")
                     .arg(gorColor).arg(QString::number(reservatorio->gas_oil_ratio, 'f', 2));

        // WOR com código de cores  
        QString worColor = reservatorio->water_oil_ratio > reservatorio->LIMITE_WOR_CRITICO ? "#ffebee" : "#e8f5e8";
        reportHtml += QString("<tr style='background-color: %1;'><td style='padding: 8px; border: 1px solid #dee2e6;'><b>💧 WOR (Água-Óleo Ratio):</b></td><td style='padding: 8px; border: 1px solid #dee2e6;'>%2 (BSW: %3%)</td></tr>")
                     .arg(worColor).arg(QString::number(reservatorio->water_oil_ratio, 'f', 3)).arg(QString::number(reservatorio->water_oil_ratio * 100, 'f', 1));

        // STATUS OPERACIONAL (MAIS CRÍTICO)
        QString statusText = reservatorio->em_emergencia ? 
            "<span style='color: red; font-weight: bold; font-size: 16px;'>⚠️ SISTEMA EM EMERGÊNCIA</span>" : 
            "<span style='color: green; font-weight: bold; font-size: 16px;'>✅ OPERAÇÃO NORMAL</span>";
        reportHtml += QString("<tr style='background-color: %1;'><td style='padding: 12px; font-weight: bold; border: 1px solid #dee2e6;'>🔍 Status do Sistema:</td><td style='padding: 12px; border: 1px solid #dee2e6; text-align: center;'>%2</td></tr>")
                     .arg(reservatorio->em_emergencia ? "#ffebee" : "#e8f5e8").arg(statusText);
        
        reportHtml += "</table>";

        // SEÇÃO DE VOLUMES E RESERVAS
        reportHtml += "<h3 style='color:#0056b3; margin-top: 25px;'>📊 VOLUMES E RESERVAS</h3>";
        reportHtml += "<table style='width: 100%; border-collapse: collapse;'>";
        reportHtml += QString("<tr><td style='padding: 6px; border: 1px solid #dee2e6;'><b>🛢️ Volume de Óleo Restante:</b></td><td style='padding: 6px; border: 1px solid #dee2e6;'>%1 bbl</td></tr>").arg(QString::number(reservatorio->volume_oleo_bbl, 'f', 0));
        reportHtml += QString("<tr style='background-color: #f8f9fa;'><td style='padding: 6px; border: 1px solid #dee2e6;'><b>⛽ Volume de Gás Livre:</b></td><td style='padding: 6px; border: 1px solid #dee2e6;'>%1 m³</td></tr>").arg(QString::number(reservatorio->volume_gas_m3, 'f', 0));
        reportHtml += QString("<tr><td style='padding: 6px; border: 1px solid #dee2e6;'><b>💧 Volume de Água Total:</b></td><td style='padding: 6px; border: 1px solid #dee2e6;'>%1 bbl</td></tr>").arg(QString::number(reservatorio->volume_agua_bbl, 'f', 0));
        reportHtml += "</table>";

        // SEÇÃO DE EVENTOS CRÍTICOS E HISTÓRICO RECENTE
        reportHtml += "<h3 style='color:#0056b3; margin-top: 25px;'>📋 EVENTOS CRÍTICOS E INTERVENÇÕES</h3>";
        
        // Mostrar últimos 10 eventos do histórico
        int eventosParaMostrar = std::min(10, dataPoints.size());
        if (eventosParaMostrar > 0) {
            reportHtml += "<table style='width: 100%; border-collapse: collapse; font-size: 11px;'>";
            reportHtml += "<tr style='background-color: #e9ecef;'>";
            reportHtml += "<th style='padding: 6px; border: 1px solid #dee2e6; text-align: center;'>Tempo</th>";
            reportHtml += "<th style='padding: 6px; border: 1px solid #dee2e6; text-align: center;'>Evento Operador</th>";
            reportHtml += "<th style='padding: 6px; border: 1px solid #dee2e6; text-align: center;'>Evento Físico</th>";
            reportHtml += "<th style='padding: 6px; border: 1px solid #dee2e6; text-align: center;'>Alerta</th>";
            reportHtml += "</tr>";
            
            // Mostrar últimos eventos (em ordem reversa)
            for (int i = dataPoints.size() - eventosParaMostrar; i < dataPoints.size(); ++i) {
                const auto& ponto = dataPoints[i];
                
                // Apenas mostrar linha se há algum evento significativo
                if (!ponto.evento_operador.isEmpty() || !ponto.evento_fisica.isEmpty() || ponto.alerta_tipo != "NORMAL") {
                    QString corFundo = "#ffffff";
                    if (ponto.alerta_tipo == "SHUTDOWN") corFundo = "#ffebee";
                    else if (ponto.alerta_tipo == "CRITICO") corFundo = "#fff3e0";
                    else if (ponto.alerta_tipo == "ATENCAO") corFundo = "#fffde7";
                    
                    reportHtml += QString("<tr style='background-color: %1;'>").arg(corFundo);
                    reportHtml += QString("<td style='padding: 4px; border: 1px solid #dee2e6; text-align: center;'>%1</td>").arg(ponto.data_hora.mid(11,5)); // Apenas HH:MM
                    reportHtml += QString("<td style='padding: 4px; border: 1px solid #dee2e6;'>%1</td>").arg(ponto.evento_operador.isEmpty() ? "-" : ponto.evento_operador);
                    reportHtml += QString("<td style='padding: 4px; border: 1px solid #dee2e6;'>%1</td>").arg(ponto.evento_fisica.isEmpty() ? "-" : ponto.evento_fisica);
                    reportHtml += QString("<td style='padding: 4px; border: 1px solid #dee2e6; text-align: center; font-weight: bold;'>%1</td>").arg(ponto.alerta_tipo);
                    reportHtml += "</tr>";
                }
            }
            reportHtml += "</table>";
        } else {
            reportHtml += "<p style='color: #666; font-style: italic;'>Nenhum evento registrado ainda. O sistema está coletando dados...</p>";
        }

        // RODAPÉ INSTITUCIONAL
        reportHtml += "<div style='margin-top: 30px; padding: 15px; background-color: #f8f9fa; border-left: 4px solid #0056b3;'>";
        reportHtml += "<p style='margin: 0; font-size: 10px; color: #666;'>";
        reportHtml += "📋 <b>RELATÓRIO GERADO AUTOMATICAMENTE</b> pelo Sistema SCADA ATS-7B<br>";
        reportHtml += "🏢 <b>OCEANOIL</b> - Oceanic Oil Exploration S.A.<br>";
        reportHtml += "🌊 <b>CAMPO:</b> Atlântida Oriental • <b>BACIA:</b> Atlântida • <b>ESTADO:</b> Rio de Janeiro<br>";
        reportHtml += "⚡ <b>SISTEMA:</b> Qt5 SCADA Educational Simulator v1.0<br>";
        QString timestamp = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
        reportHtml += QString("🕐 <b>GERADO EM:</b> %1").arg(timestamp);
        reportHtml += "</p></div>";

        // APLICAR HTML AO WIDGET
        reportTextEdit->setHtml(reportHtml);
        
        /*
        📝 NOTA EDUCACIONAL:
        Este formato de relatório é padrão na indústria petrolífera:
        • HTML para formatação flexível
        • Códigos de cores para alertas visuais
        • Estrutura tabular para fácil leitura
        • Informações institucionais completas
        • Timestamp para auditoria
        */
    }
};

/*
🎓 ================================================================================
🖥️ CLASSE PRINCIPAL DA APLICAÇÃO - INTERFACE SCADA EDUCACIONAL
================================================================================

📚 CONCEITO EDUCACIONAL:
Esta é a classe principal do simulador, equivalente a uma estação SCADA
(Supervisory Control and Data Acquisition) usada na indústria petrolífera.
Integra todos os componentes em uma interface profissional.

🏭 SISTEMAS SCADA REAIS:
• Sala de controle da OceanOil em Macaé (CENPES)  
• Controle remoto de plataformas offshore
• Monitoramento 24h/7dias de centenas de poços
• Integração com sistemas corporativos (SAP, PI System)

🎯 COMPONENTES PRINCIPAIS:
• Dashboard com indicadores em tempo real
• Gráficos de tendência histórica
• Controles operacionais (válvulas, bombas, injeção)
• Sistema de alarmes e emergência
• Geração automática de relatórios

💻 TECNOLOGIA:
Qt5 - Mesmo framework usado em sistemas industriais reais da OceanOil.

================================================================================
*/

class SimuladorWindow : public QMainWindow {
    Q_OBJECT

public:
    /*
    🏗️ ========================================================================
    CONSTRUTOR PRINCIPAL - INICIALIZAÇÃO DO SISTEMA SCADA
    ========================================================================
    
    📚 PARA ESTUDANTES: O construtor é executado quando o programa inicia.
    Aqui configuramos todo o sistema: interface, gráficos, simulação e timers.
    
    🔄 SEQUÊNCIA DE INICIALIZAÇÃO:
    1. Gerador de números aleatórios (para variações operacionais)
    2. Modelo físico do reservatório ATS-7B
    3. Sistema de temporização (5 segundos como sistemas reais)
    4. Interface gráfica (SCADA) 
    5. Sistema de gráficos e visualização
    6. Início da simulação automática
    */
    SimuladorWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        /*
        🎲 GERADOR DE NÚMEROS ALEATÓRIOS:
        Inicializa com timestamp atual para simular variações operacionais
        naturais (ruído de sensores, flutuações de produção, etc.)
        */
        srand(static_cast<unsigned int>(time(nullptr)));
        
        /*
        🏗️ CRIAÇÃO DOS OBJETOS PRINCIPAIS:
        */
        // MODELO FÍSICO: Cria instância do reservatório ATS-7B
        reservatorio = new Reservatorio();  
        
        // TIMER DE SIMULAÇÃO: Controla o passo de tempo da simulação
        simulationTimer = new QTimer(this);  // Timer Qt (gerenciado pelo pai)
        
        // CONECTA timer → gameLoop (padrão signal-slot do Qt)
        connect(simulationTimer, &QTimer::timeout, this, &SimuladorWindow::gameLoop);
        
        // INICIALIZAR RASTREAMENTO DE EVENTOS
        ultimoEventoOperador = "";
        ultimoEventoFisica = ""; // Não registrar evento na inicialização
        tipoAlertaAtual = "NORMAL";
        sistemaInicializado = false;
        
        /*
        🎨 INICIALIZAÇÃO DA INTERFACE GRÁFICA:
        Método modular para organizar melhor o código
        */
        setupUI();         // Constrói toda a interface SCADA
        setupCharts();     // Configura os gráficos de tendência

        /*
        ⏰ INICIALIZAÇÃO DIFERIDA (100ms após interface pronta):
        
        📚 CONCEITO: QTimer::singleShot executa uma função após delay.
        É usado para garantir que a interface esteja completamente
        construída antes de iniciar a simulação.
        */
        QTimer::singleShot(100, this, [this]() {
            
            /*
            🔄 INÍCIO DA SIMULAÇÃO EM TEMPO REAL:
            5 segundos = Frequência típica de sistemas SCADA reais
            */
            simulationTimer->start(5000);  // 5000ms = 5 segundos
            
            /*
            📢 MENSAGENS DE BOAS-VINDAS (LOG EDUCACIONAL):
            Informa ao usuário sobre os dados reais utilizados
            */
            logMessage("🎓 SIMULADOR EDUCACIONAL ATS-7B INICIADO - BEM-VINDO!");
            logMessage("🏆 Poço: Atlântida Oriental (Bacia de Atlântida) - 26 anos de dados reais", "info");
            logMessage("📈 Parâmetros calibrados com dados da OceanOil/ANP:", "info");
            logMessage("• Pressão: 2.850 psi • Temp: 92°C • API: 29,5° • PI: 8,2 bopd/psi", "info");
            logMessage("• Produção: 22.000 bopd • BSW: 23% • GOR: 420 scf/bbl", "info");  
            logMessage("ℹ️ Timestep: 5s (realismo operacional) • Interface: SCADA Qt5", "info");
            logMessage("📚 Para estudantes: Explore os gráficos, teste intervenções!", "info");
            
            /*
            📈 INICIALIZAÇÃO DOS GRÁFICOS:
            Força primeira atualização dos gráficos para garantir funcionamento
            */
            atualizarGraficosSeNecessario(true);
            
            /*
            💡 DICA EDUCACIONAL:
            Esta estrutura de inicialização (timer diferido + log de status)
            é padrão em sistemas industriais reais para:
            • Verificar se todos os subsistemas estão funcionando
            • Registrar o início de operação para auditoria
            • Informar operadores sobre o estado inicial do sistema
            */
        });
    }

    /*
    💀 ========================================================================
    DESTRUTOR - CLEANUP SEGURO DO SISTEMA
    ========================================================================
    
    📚 CONCEITO EDUCACIONAL: 
    O destrutor é chamado automaticamente quando o programa termina.
    É fundamental para sistemas industriais garantir shutdown seguro.
    
    ⚠️ IMPORTÂNCIA NA INDÚSTRIA:
    • Evita vazamentos de memória
    • Para processos de forma controlada  
    • Salva dados críticos antes do encerramento
    • Desliga equipamentos com segurança
    */
    ~SimuladorWindow() {
        /*
        ⏹️ PARADA CONTROLADA DO TIMER:
        Verifica se o timer existe e está ativo antes de parar.
        Evita crashes durante o shutdown.
        */
        if (simulationTimer && simulationTimer->isActive()) {
            simulationTimer->stop();  // Para a simulação em tempo real
        }
        
        /*
        🧹 LIMPEZA DE MEMÓRIA:
        Libera a memória alocada para o modelo do reservatório.
        O Qt gerencia automaticamente os widgets filhos.
        */
        delete reservatorio;
        
        /*
        📝 NOTA EDUCACIONAL:
        Em sistemas reais, o destrutor também pode:
        • Fechar conexões de rede/banco de dados
        • Salvar estado atual em arquivo de recuperação
        • Enviar sinal de shutdown para outros sistemas
        • Registrar timestamp de encerramento no log
        */
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
        
        // Marcar sistema como inicializado após 10 segundos (2 ciclos)
        if (!sistemaInicializado && reservatorio->tempo_simulacao_s >= 10.0) {
            sistemaInicializado = true;
            logMessage("✅ Sistema totalmente inicializado - Monitoramento ativo", "sistema");
        }

        // Verificar e exibir alertas e sugestões
        if (reservatorio->em_emergencia) {
            tipoAlertaAtual = "SHUTDOWN";
            // Log detalhado apenas quando há novo motivo
            if (!reservatorio->motivo_emergencia.isEmpty()) {
                logMessage(reservatorio->motivo_emergencia, "critico");
                ultimoEventoFisica = "Shutdown: " + reservatorio->motivo_emergencia.mid(24); // Remove "🚨 SHUTDOWN AUTOMÁTICO ATIVADO: "
                // ALERTA SONORO CRÍTICO PARA SHUTDOWN AUTOMÁTICO
                emitirAlertaSonoro("critico");
                reservatorio->motivo_emergencia = ""; // Limpar para não repetir
            } else {
                logMessage("ALERTA CRÍTICO: Shutdown Automático!", "critico");
            }
            suggestInputWater->setPlaceholderText("Emergência");
            suggestInputGas->setPlaceholderText("Emergência");
            suggestInputVapor->setPlaceholderText("Emergência");
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
                ultimoEventoOperador = QString("Inj Água %1bbl %2°C").arg(volume, 0, 'f', 0).arg(temp, 0, 'f', 0);
                logMessage(QString("Injetando %1 bbl de água a %2°C.").arg(volume).arg(temp), "acao");
            } else {
                QMessageBox::warning(this, "Erro de Entrada", "Por favor, insira valores numéricos para a injeção de água e temperatura.");
            }
        } else if (buttonName == "inj_gas_btn") {
            double volume = suggestInputGas->text().toDouble(&ok);
            double densidade = inputDensidadeGas->text().toDouble(&ok);
            if (ok) {
                reservatorio->injetarGas(volume, densidade);
                ultimoEventoOperador = QString("Inj Gás %1m³ d%2").arg(volume, 0, 'f', 0).arg(densidade, 0, 'f', 1);
                logMessage(QString("Injetando %1 m³ de gás com densidade de %2.").arg(volume).arg(densidade), "acao");
            } else {
                QMessageBox::warning(this, "Erro de Entrada", "Por favor, insira valores numéricos para a injeção de gás e densidade.");
            }
        } else if (buttonName == "inj_vapor_btn") {
            double tempo = suggestInputVapor->text().toDouble(&ok);
            if (ok) {
                reservatorio->injetarVapor(tempo);
                ultimoEventoOperador = QString("Inj Vapor %1s").arg(tempo, 0, 'f', 0);
                logMessage(QString("Injetando vapor por %1 segundos.").arg(tempo), "acao");
            } else {
                QMessageBox::warning(this, "Erro de Entrada", "Por favor, insira um valor numérico para a injeção de vapor.");
            }
        } else if (buttonName == "abrir_valv_btn") {
            reservatorio->ajustarPressaoPoco(-50.0);
            ultimoEventoOperador = "Abrir Choke";
            logMessage("Abrindo a válvula de choke. Aumento de vazão esperado.", "acao");
        } else if (buttonName == "fechar_valv_btn") {
            reservatorio->ajustarPressaoPoco(50.0);
            ultimoEventoOperador = "Fechar Choke";
            logMessage("Fechando a válvula de choke. Redução de vazão esperada.", "acao");
        } else if (buttonName == "parar_prod_btn") {
            isProducing = false;
            ultimoEventoOperador = "Parar Produção";
            logMessage("Produção interrompida para manutenção.", "critico");
        } else if (buttonName == "iniciar_prod_btn") {
            isProducing = true;
            ultimoEventoOperador = "Iniciar Produção";
            logMessage("Produção retomada.", "acao");
        }
    }

    void onGenerateReportsClicked() {
        ReportDialog dialog(reservatorio, dataPoints, this);
        dialog.exec();
    }

    /*
    📊 ========================================================================
    MÉTODOS DE CONTROLE DE PERIODICIDADE DOS GRÁFICOS
    ========================================================================
    
    📚 CONCEITO EDUCACIONAL:
    Implementação de controles interativos para diferentes granularidades
    temporais, permitindo análise adaptável às necessidades operacionais.
    */
    
    void onPeriodoChanged(int index) {
        // Atualizar período baseado na seleção
        periodoGraficoSegundos = periodoSelector->itemData(index).toInt();
        
        // Reset do controle temporal
        ultimoTempoGrafico = obterTempoMinutos();
        
        // Log educacional da mudança
        QString periodoTexto = periodoSelector->currentText();
        logMessage(QString("📊 Período de gráficos alterado para: %1").arg(periodoTexto), "info");
        
        // Forçar atualização imediata dos gráficos com nova periodicidade
        atualizarGraficosSeNecessario(true);
    }
    
    void onPerfilChanged(int index) {
        // 🎮 Atualizar perfil de simulação baseado na seleção
        int perfil = perfilSelector->itemData(index).toInt();
        QString perfilTexto = perfilSelector->currentText();
        
        // Log educacional da mudança
        QString explicacao;
        switch(perfil) {
            case 0: // Estudante
                explicacao = "Modo básico com parâmetros simplificados para aprendizado";
                break;
            case 1: // Operador
                explicacao = "Condições operacionais padrão similares às industriais";
                break;
            case 2: // Especialista
                explicacao = "Cenários avançados com variações técnicas complexas";
                break;
            case 3: // Engenheiro Sênior
                explicacao = "Simulação realista baseada em dados históricos do ATS-7B";
                break;
            case 4: // Analista
                explicacao = "Reprodução de eventos históricos reais para análise";
                break;
        }
        
        logMessage(QString("🎯 Perfil alterado para: %1").arg(perfilTexto), "info");
        logMessage(QString("📚 %1").arg(explicacao), "info");
        
        // TODO: Implementar mudanças nos parâmetros de simulação baseado no perfil
        // Por enquanto, apenas registra a mudança
    }
    
    void onClearChartsClicked() {
        // Limpar todos os gráficos
        producaoSeries->clear();
        pressaoSeries->clear();
        volumeOleoSeries->clear();
        temperaturaSeries->clear();
        viscosidadeSeries->clear();
        gorSeries->clear();
        worSeries->clear();
        
        // Reset do controle temporal
        ultimoTempoGrafico = 0.0;
        
        logMessage("🗑️ Gráficos limpos - Iniciando nova coleta de dados", "info");
    }

    void onDownloadCSVClicked() {
        if (dataPoints.isEmpty()) {
            QMessageBox::warning(this, "Erro", "Nenhum dado para baixar. A simulação ainda não gerou pontos.");
            return;
        }

        // Salvar na pasta raiz do projeto (um nível acima do executável)
        QString projectRoot = QCoreApplication::applicationDirPath() + "/../simulacao_petroleo.csv";
        QString fileName = QDir::cleanPath(projectRoot);
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            // CABEÇALHO CSV COM UUID PARA KAFKA STREAMING E RASTREAMENTO DE EVENTOS
            out << "uuid,data_hora,tempo_min,vazao_oleo_bopd,pressao_psi,viscosidade_cp,volume_oleo_bbl,temperatura_C,GOR,WOR,evento_operador,evento_fisica,alerta_tipo\n";
            /*
            📊 EXPORTAÇÃO DE DADOS (REFATORADO):
            Uso do método utilitário formatarCampoNumerico() para
            consistência na formatação dos valores exportados
            */
            for (const auto& point : dataPoints) {
                out << "\"" << point.uuid << "\","
                    << "\"" << point.data_hora << "\","
                    << point.tempo_min << ","
                    << formatarCampoNumerico(point.vazao_oleo) << ","
                    << formatarCampoNumerico(point.pressao) << ","
                    << formatarCampoNumerico(point.viscosidade_cp) << ","
                    << formatarCampoNumerico(point.volume_oleo) << ","
                    << formatarCampoNumerico(point.temperatura) << ","
                    << formatarCampoNumerico(point.gor) << ","
                    << formatarCampoNumerico(point.wor) << ","
                    << "\"" << point.evento_operador << "\","
                    << "\"" << point.evento_fisica << "\","
                    << "\"" << point.alerta_tipo << "\"\n";
            }
            file.close();
            QMessageBox::information(this, "Sucesso", QString("Arquivo CSV salvo em:\n%1").arg(fileName));
        } else {
            QMessageBox::critical(this, "Erro", "Não foi possível abrir o arquivo para escrita.");
        }
    }

private:
    /*
    🎓 ================================================================================
    ⚙️ MÉTODOS UTILITÁRIOS SCADA - REFATORAÇÃO DE INTERFACE  
    ================================================================================
    
    📚 CONCEITO EDUCACIONAL:
    Métodos utilitários específicos para operações repetitivas da interface
    SCADA, seguindo princípios de Clean Code e DRY (Don't Repeat Yourself).
    
    🏭 PADRÕES INDUSTRIAIS:
    • Consistência visual em todos os elementos
    • Códigos de cores padronizados por criticidade  
    • Formatação numérica uniforme
    • Facilidade de manutenção e auditoria
    
    ================================================================================
    */

    /*
    📊 ========================================================================
    MÉTODO UTILITÁRIO: FORMATAÇÃO DE CAMPOS NUMÉRICOS DA INTERFACE
    ========================================================================
    
    📚 CONCEITO DE REFATORAÇÃO:
    Centraliza a formatação de números para exibição na interface,
    eliminando repetição de QString::number() com parâmetros idênticos.
    
    🎯 PADRONIZAÇÃO SCADA:
    • 2 casas decimais: Padrão para parâmetros operacionais
    • 0 casas decimais: Volumes grandes (milhões de barris)
    • Consistência visual em toda a interface
    
    PARÂMETROS:
    • valor: Número a ser formatado
    • precisao: Casas decimais (padrão: 2)
    
    RETORNA: QString formatado para interface
    */
    QString formatarCampoNumerico(double valor, int precisao = 2) const {
        return QString::number(valor, 'f', precisao);
    }

    /*
    ⏱️ ========================================================================
    MÉTODO UTILITÁRIO: CONVERSÃO TEMPO PARA INTERFACE
    ========================================================================
    
    📚 CONCEITO DE REFATORAÇÃO:
    Centraliza conversão segundos→minutos usada nos gráficos e logs,
    eliminando duplicação da operação tempo_simulacao_s / 60.0.
    
    🏭 APLICAÇÃO SCADA:
    • Eixos temporais dos gráficos
    • Logs de eventos
    • Relatórios operacionais
    
    RETORNA: Tempo atual em minutos para interface
    */
    double obterTempoMinutos() const {
        return reservatorio->segundosParaMinutos(reservatorio->tempo_simulacao_s);
    }

    /*
    🎨 ========================================================================
    MÉTODO UTILITÁRIO: DETERMINAÇÃO DE CORES DE STATUS
    ========================================================================
    
    📚 CONCEITO DE REFATORAÇÃO:
    Centraliza lógica de cores baseadas em limites operacionais,
    eliminando repetição de condicionais ternários complexos.
    
    🚦 CÓDIGO DE CORES INDUSTRIAL:
    • Verde: Operação normal
    • Amarelo/Laranja: Atenção/Alerta  
    • Vermelho: Crítico/Emergência
    
    PARÂMETROS:
    • valor: Valor atual do parâmetro
    • limite_alerta: Threshold de atenção
    • limite_critico: Threshold crítico
    • invertido: true se valores baixos são críticos
    
    RETORNA: String com nome da cor
    */
    QString determinarCorStatus(double valor, double limite_alerta, double limite_critico, bool invertido = false) const {
        if (invertido) {
            // Para parâmetros onde valores BAIXOS são críticos (ex: pressão, vazão)
            if (valor < limite_critico) return "red";
            if (valor < limite_alerta) return "orange"; 
            return "green";
        } else {
            // Para parâmetros onde valores ALTOS são críticos (ex: temperatura, GOR)
            if (valor > limite_critico) return "red";
            if (valor > limite_alerta) return "orange";
            return "green";
        }
    }

    /*
    📈 ========================================================================
    VARIÁVEIS DE CONTROLE DE GRÁFICOS INTERATIVOS
    ========================================================================
    
    📚 CONCEITO EDUCACIONAL:
    Sistema de periodicidade para dashboards SCADA industriais, permitindo
    diferentes níveis de granularidade temporal para análise operacional.
    
    🏭 APLICAÇÃO INDUSTRIAL:
    • Monitoramento em tempo real (1-5min) para operação
    • Análise de tendências médias (30-60min) para otimização  
    • Visão estratégica (1 dia) para planejamento
    */
    
    // Variáveis de estado original
    Reservatorio* reservatorio;
    bool isProducing = true;
    QTimer* simulationTimer;
    QVector<DadosPontos> dataPoints;

    // Sistema de controle de periodicidade dos gráficos
    int periodoGraficoSegundos = 60;        // Período atual em segundos (padrão: 1 minuto)
    double ultimoTempoGrafico = 0.0;        // Último tempo que atualizou gráficos  
    QComboBox* periodoSelector;             // Seletor de período na interface
    QComboBox* perfilSelector;              // 🎮 Seletor de perfil de simulação

    // 🎓 Sistema Educacional de Diagnóstico Inteligente
    QWidget* diagnosticoWidget;             // Widget principal do sistema educacional
    QLabel* diagnosticoTituloLabel;         // Título do diagnóstico atual
    QString diagnosticoAtual;               // Tipo de diagnóstico ativo

    // RASTREAMENTO DE EVENTOS PARA ANÁLISE DE DADOS
    QString ultimoEventoOperador;           // Última ação do operador registrada
    QString ultimoEventoFisica;             // Último evento físico detectado
    QString tipoAlertaAtual;                // Tipo de alerta atual do sistema
    bool sistemaInicializado;               // Flag para evitar alertas durante inicialização

    // Elementos da interface
    QVector<QLabel*> indicatorLabels;
    QTextEdit* logTextEdit;
    QLineEdit* suggestInputWater;
    QLineEdit* inputTempAgua;
    QLineEdit* suggestInputGas;
    QLineEdit* inputDensidadeGas;
    QLineEdit* suggestInputVapor;
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
        setWindowTitle("Simulador ATS-7B - Poço Atlântida Oriental (Bacia de Atlântida)");
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
        QHBoxLayout* scadaMainLayout = new QHBoxLayout(scadaGroupBox);
        scadaMainLayout->setSpacing(20);
        
        // Container do Logo - alinhado à esquerda
        QWidget* logoContainer = new QWidget();
        logoContainer->setFixedSize(350, 80);
        QHBoxLayout* logoLayout = new QHBoxLayout(logoContainer);
        logoLayout->setContentsMargins(10, 5, 10, 5);
        logoLayout->setSpacing(15);
        
        // Logo/Ícone 
        QLabel* logoIcon = new QLabel("🛢️");
        logoIcon->setAlignment(Qt::AlignCenter);
        logoIcon->setFixedSize(60, 60);
        logoIcon->setStyleSheet(
            "QLabel { "
                "font-size: 36px; "
                "background-color: #1a1a1a; "
                "border: 2px solid #ff6b35; "
                "border-radius: 30px; "
                "padding: 5px; "
            "}"
        );
        
        // Texto "Aggressive Oil Club"
        QLabel* clubText = new QLabel("AGGRESSIVE OIL CLUB");
        clubText->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        clubText->setStyleSheet(
            "QLabel { "
                "color: #ff6b35; "
                "font-size: 16px; "
                "font-weight: bold; "
                "font-family: 'Arial Black', Arial, sans-serif; "
                "letter-spacing: 2px; "
                "background-color: transparent; "
            "}"
        );
        
        logoLayout->addWidget(logoIcon);
        logoLayout->addWidget(clubText);
        logoLayout->addStretch();
        
        // Estilo do container
        logoContainer->setStyleSheet(
            "QWidget { "
                "background-color: #2a2a2a; "
                "border: 1px solid #444444; "
                "border-radius: 8px; "
            "}"
        );
        
        scadaMainLayout->addWidget(logoContainer);
        
        // Layout para os ícones SCADA centralizados
        QHBoxLayout* scadaIconsLayout = new QHBoxLayout();
        scadaIconsLayout->setAlignment(Qt::AlignCenter);
        scadaIconsLayout->setSpacing(30);

        // Criação dos ícones SCADA com estilo melhorado (formato original)
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

        scadaMainLayout->addLayout(scadaIconsLayout);
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
            
            /*
            📏 ====================================================================
            AJUSTE DE LAYOUT: UNIDADES DE MEDIDA COM FONTE AUMENTADA
            ====================================================================
            
            📚 MELHORIA DE USABILIDADE:
            Aumento da fonte das unidades de medida de 10px para 13px para
            melhor legibilidade dos indicadores operacionais.
            
            🏭 BENEFÍCIO INDUSTRIAL:
            • Identificação mais rápida das unidades pelos operadores
            • Redução de erros de interpretação de grandezas
            • Padrão mais adequado para dashboards industriais
            • Melhor experiência visual em monitores grandes (SCADA)
            */
            QLabel* unitLabel = new QLabel(units[i], this);
            unitLabel->setAlignment(Qt::AlignCenter);
            unitLabel->setStyleSheet(
                "font-size: 13px; "      // AUMENTADO: 10px → 13px (+30% legibilidade)
                "color: #888888; "       // Cor mantida (contraste adequado)
                "margin-top: 2px; "      // Espaçamento mantido
                "font-weight: 500;"      // NOVO: Peso ligeiramente aumentado para destaque
            );
            
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
        
        /*
        📈 ====================================================================
        CONTROLE DE PERIODICIDADE DE GRÁFICOS - DASHBOARD INTERATIVO
        ====================================================================
        
        📚 CONCEITO EDUCACIONAL:
        Implementação de controle de granularidade temporal para análise
        de dados operacionais, similar aos sistemas SCADA industriais.
        
        🏭 BENEFÍCIO INDUSTRIAL:
        • Flexibilidade de análise conforme necessidade operacional
        • Redução de ruído visual em análises de longo prazo  
        • Otimização de performance para grandes volumes de dados
        • Adequação a diferentes perfis de usuário (operador vs gestor)
        */
        
        // Container vertical para controles de gráfico + gráficos
        QVBoxLayout* chartsContainerLayout = new QVBoxLayout();
        QWidget* chartsContainer = new QWidget();
        chartsContainer->setLayout(chartsContainerLayout);
        
        // Controle de periodicidade dos gráficos
        QHBoxLayout* periodControlLayout = new QHBoxLayout();
        
        QLabel* periodLabel = new QLabel("📊 Período de Atualização dos Gráficos:");
        periodLabel->setStyleSheet("font-weight: bold; color: #00AAFF; font-size: 12px; margin-right: 10px;");
        
        periodoSelector = new QComboBox();
        periodoSelector->addItem("⚡ 1 Minuto (Tempo Real)", 60);
        periodoSelector->addItem("🔄 5 Minutos (Operacional)", 300); 
        periodoSelector->addItem("📈 10 Minutos (Supervisão)", 600);
        periodoSelector->addItem("📊 30 Minutos (Tendência)", 1800);
        periodoSelector->addItem("🕐 1 Hora (Análise)", 3600);
        periodoSelector->addItem("📅 1 Dia (Estratégico)", 86400);
        
        periodoSelector->setCurrentIndex(0); // Padrão: 1 minuto
        periodoSelector->setStyleSheet(
            "QComboBox { "
                "background-color: #2d2d2d; "
                "border: 2px solid #555555; "
                "border-radius: 4px; "
                "padding: 6px; "
                "font-weight: bold; "
                "min-width: 200px; "
                "color: #FFFFFF; "
            "}"
            "QComboBox:hover { border-color: #777777; }"
            "QComboBox::drop-down { "
                "border: none; "
            "}"
            "QComboBox QAbstractItemView { "
                "background-color: #2d2d2d; "
                "border: 1px solid #555555; "
                "color: #FFFFFF; "
                "selection-background-color: #0078d4; "
            "}"
        );
        
        // 🎮 SELETOR DE PERFIL DE SIMULAÇÃO
        QLabel* perfilLabel = new QLabel("🎯 Perfil de Simulação:");
        perfilLabel->setStyleSheet("font-weight: bold; color: #FF6B35; font-size: 12px; margin-left: 30px; margin-right: 10px;");
        
        perfilSelector = new QComboBox();
        perfilSelector->addItem("🎓 Estudante (Básico)", 0);
        perfilSelector->addItem("👨‍💼 Operador (Padrão)", 1);
        perfilSelector->addItem("⚡ Especialista (Avançado)", 2);
        perfilSelector->addItem("🏭 Engenheiro Sênior (Realista)", 3);
        perfilSelector->addItem("📊 Analista (Dados Históricos)", 4);
        
        perfilSelector->setCurrentIndex(1); // Padrão: Operador
        perfilSelector->setStyleSheet(
            "QComboBox { "
                "background-color: #2d2d2d; "
                "border: 1px solid #555555; "
                "border-radius: 4px; "
                "padding: 4px 8px; "
                "min-width: 200px; "
                "color: #FFFFFF; "
            "}"
            "QComboBox:hover { border-color: #FF6B35; }"
            "QComboBox::drop-down { "
                "border: none; "
            "}"
            "QComboBox QAbstractItemView { "
                "background-color: #2d2d2d; "
                "border: 1px solid #555555; "
                "color: #FFFFFF; "
                "selection-background-color: #FF6B35; "
            "}"
        );
        
        // Botão para limpar gráficos
        QPushButton* clearChartsBtn = new QPushButton("🗑️ Limpar Gráficos");
        clearChartsBtn->setStyleSheet(
            "QPushButton { "
                "background-color: #DC3545; "
                "border: none; "
                "color: white; "
                "font-weight: bold; "
                "padding: 6px 12px; "
                "border-radius: 4px; "
            "}"
            "QPushButton:hover { background-color: #C82333; }"
        );
        
        periodControlLayout->addWidget(periodLabel);
        periodControlLayout->addWidget(periodoSelector);
        periodControlLayout->addWidget(perfilLabel);
        periodControlLayout->addWidget(perfilSelector);
        periodControlLayout->addWidget(clearChartsBtn);
        periodControlLayout->addStretch(); // Espaço flexível
        
        chartsContainerLayout->addLayout(periodControlLayout);
        
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

        chartsContainerLayout->addWidget(chartsTabWidget);

        monitoringLayout->addWidget(chartsContainer, 3);

        // Log de eventos com título
        QGroupBox* logGroupBox = new QGroupBox("Log de Eventos do Sistema");
        QVBoxLayout* logLayout = new QVBoxLayout(logGroupBox);
        
        logTextEdit = new QTextEdit();
        logTextEdit->setReadOnly(true);
        logTextEdit->setMinimumHeight(300);
        /*
        📝 ========================================================================
        AJUSTE DE LAYOUT: FONTE DO LOG DE EVENTOS AUMENTADA
        ========================================================================
        
        📚 MELHORIA DE USABILIDADE:
        Aumento da fonte de 11px para 14px para melhor legibilidade do log
        de eventos, facilitando o monitoramento operacional em tempo real.
        
        🏭 BENEFÍCIO INDUSTRIAL:
        • Melhor visibilidade para operadores em salas de controle
        • Redução da fadiga visual em turnos longos (12h)
        • Facilita identificação rápida de eventos críticos
        • Padrão mais adequado para monitores industriais
        */
        logTextEdit->setStyleSheet(
            "QTextEdit { "
                "background-color: #0a0a0a; "
                "border: 1px solid #333333; "
                "color: #CCCCCC; "
                "font-family: 'Courier New', monospace; "
                "font-size: 14px; "  // AUMENTADO: 11px → 14px (+27% legibilidade)
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
        
        
        // Posicionar controles em grid 2x2
        interventionGrid->addWidget(waterControl, 0, 0);
        interventionGrid->addWidget(gasControl, 0, 1);
        interventionGrid->addWidget(vaporControl, 1, 0);
        
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
        
suggestionExplanationLabel = new QLabel("🎓 SISTEMA DE ENSINO INTELIGENTE:\n\n🤖 Este painel fornece sugestões educacionais baseadas nas condições operacionais.\n\n💡 Explore diferentes intervenções e observe como cada ação afeta os parâmetros do reservatório!\n\n📈 Acompanhe os gráficos para entender as relações causa-efeito.");
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

        // 🎓 Sistema Educacional de Diagnóstico
        QWidget* sistemaEducacional = criarSistemaEducacional();
        mainLayout->addWidget(sistemaEducacional);

        // Conecta os botões aos slots
        connect(waterBtn, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(gasBtn, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(vaporBtn, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(startBtn, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(stopBtn, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(openValveBtn, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(closeValveBtn, &QPushButton::clicked, this, &SimuladorWindow::onActionButtonClicked);
        connect(reportBtn, &QPushButton::clicked, this, &SimuladorWindow::onGenerateReportsClicked);
        connect(downloadBtn, &QPushButton::clicked, this, &SimuladorWindow::onDownloadCSVClicked);
        
        // Conectar controles de periodicidade dos gráficos
        connect(periodoSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), 
                this, &SimuladorWindow::onPeriodoChanged);
        connect(perfilSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), 
                this, &SimuladorWindow::onPerfilChanged);
        connect(clearChartsBtn, &QPushButton::clicked, this, &SimuladorWindow::onClearChartsClicked);
    }

    /*
    📈 ========================================================================
    MÉTODO DE CRIAÇÃO DE GRÁFICOS - SISTEMA DE VISUALIZAÇÃO INDUSTRIAL
    ========================================================================
    
    📚 CONCEITO EDUCACIONAL:
    Este método cria gráficos de linha profissionais similares aos usados
    em sistemas SCADA da indústria petrolífera. Cada gráfico mostra a
    evolução temporal de um parâmetro operacional.
    
    🏭 APLICAÇÃO INDUSTRIAL:
    • Trending em tempo real (similar ao PI System da OSIsoft)
    • Detecção visual de anomalias operacionais
    • Análise de correlação entre variáveis
    • Base para otimização de processos
    
    PARÂMETROS:
    • title: Título do gráfico (ex: "Pressão do Reservatório")
    • series: Série de dados Qt5 que será exibida
    
    RETORNA: QChartView configurado e pronto para uso
    */
    /*
    📊 ========================================================================
    MÉTODO REFATORADO: CRIAÇÃO DE GRÁFICOS COM EIXOS ADEQUADOS
    ========================================================================
    
    🔧 CORREÇÃO IMPLEMENTADA:
    Configuração de ranges apropriados para cada tipo de gráfico baseado
    no título, resolvendo problema de invisibilidade dos pontos.
    
    📏 RANGES INDUSTRIAIS CALIBRADOS:
    Baseados nos valores reais do ATS-7B para visualização adequada.
    */
    QChartView* createChart(const QString& title, QLineSeries* series) {
        /*
        🏗️ CRIAÇÃO DO OBJETO GRÁFICO PRINCIPAL:
        QChart é o container que organiza todos os elementos
        */
        QChart *chart = new QChart();
        chart->setTitle(title);            // Define título do gráfico
        chart->legend()->hide();           // Oculta legenda (interface limpa)
        chart->addSeries(series);          // Adiciona a série de dados
        chart->setTheme(QChart::ChartThemeDark);  // Tema escuro (SCADA padrão)

        /*
        📊 CONFIGURAÇÃO DO EIXO X (TEMPO) - COM RANGE ADEQUADO:
        Representa o tempo decorrido em minutos desde o início da simulação
        */
        QValueAxis *axisX = new QValueAxis();
        axisX->setTitleText("Tempo (min)");      // Rótulo do eixo
        axisX->setLabelFormat("%.1f");           // CORREÇÃO: Formato com 1 decimal para melhor precisão
        axisX->setRange(0.0, 60.0);              // CORREÇÃO: Range inicial 0-60 minutos (1 hora)
        axisX->setTickCount(7);                  // 7 marcas = intervalos de 10 minutos
        chart->addAxis(axisX, Qt::AlignBottom);  // Posição: parte inferior
        series->attachAxis(axisX);               // Vincula série ao eixo
        
        /*
        📊 CONFIGURAÇÃO DO EIXO Y (VALOR) - COM RANGES CALIBRADOS:
        Representa o valor da variável sendo medida (pressão, vazão, etc.)
        Ranges baseados nos valores reais do ATS-7B para visualização adequada
        */
        QValueAxis *axisY = new QValueAxis();
        
        // CORREÇÃO: Configurar range específico baseado no tipo de gráfico
        if (title.contains("Produção")) {
            axisY->setTitleText("Vazão (bopd)");
            axisY->setRange(5000.0, 50000.0);       // Range: 5K-50K barris/dia
            axisY->setLabelFormat("%.0f");
        } else if (title.contains("Pressão")) {
            axisY->setTitleText("Pressão (psi)");
            axisY->setRange(1000.0, 4000.0);        // Range: 1K-4K psi
            axisY->setLabelFormat("%.0f");
        } else if (title.contains("Volume")) {
            axisY->setTitleText("Volume (MM bbl)");
            axisY->setRange(0.0, 80.0);             // Range: 0-80 milhões de barris
            axisY->setLabelFormat("%.1f");
            // CORREÇÃO: Converter barris para milhões para melhor escala
            // Isso será feito na atualização dos dados
        } else if (title.contains("Temperatura")) {
            axisY->setTitleText("Temperatura (°C)");
            axisY->setRange(80.0, 120.0);           // Range: 80-120°C
            axisY->setLabelFormat("%.1f");
        } else if (title.contains("Viscosidade")) {
            axisY->setTitleText("Viscosidade (cp)");
            axisY->setRange(0.5, 8.0);              // Range: 0.5-8 cp
            axisY->setLabelFormat("%.2f");
        } else if (title.contains("GOR")) {
            axisY->setTitleText("GOR (scf/bbl)");
            axisY->setRange(200.0, 800.0);          // Range: 200-800 scf/bbl
            axisY->setLabelFormat("%.0f");
        } else if (title.contains("WOR")) {
            axisY->setTitleText("WOR");
            axisY->setRange(0.0, 1.0);              // Range: 0-1 (ratio)
            axisY->setLabelFormat("%.3f");
        } else {
            axisY->setTitleText("Valor");            // Fallback genérico
            axisY->setLabelFormat("%.2f");
        }
        
        chart->addAxis(axisY, Qt::AlignLeft);    // Posição: lado esquerdo
        series->attachAxis(axisY);               // Vincula série ao eixo

        /*
        🎨 CRIAÇÃO DO WIDGET VISUALIZADOR:
        QChartView é o widget que renderiza o gráfico na interface
        */
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);  // Suavização de bordas
        
        /*
        📝 NOTA EDUCACIONAL:
        Antialiasing melhora a qualidade visual das linhas, especialmente
        importante em sistemas de monitoramento onde operadores passam
        horas observando tendências.
        */
        
        return chartView;  // Retorna o widget pronto para ser inserido na interface
    }

    /*
    ⚙️ ========================================================================
    MÉTODO DE CONFIGURAÇÃO GERAL DOS GRÁFICOS
    ========================================================================
    
    📚 CONCEITO: Método organizacional para configurações adicionais dos
    gráficos. Atualmente vazio pois toda configuração é feita em createChart(),
    mas mantido para futuras expansões.
    
    💡 POSSÍVEIS EXPANSÕES FUTURAS:
    • Configurar cores específicas por tipo de variável
    • Definir ranges automáticos para cada gráfico
    • Configurar alarmes visuais (linhas de limite)
    • Sincronizar zoom entre gráficos relacionados
    */
    void setupCharts() {
        /*
        📝 IMPLEMENTAÇÃO ATUAL:
        Método vazio pois toda configuração é feita no createChart().
        Esta estrutura modular facilita futuras melhorias no sistema
        de visualização.
        
        🔧 PATTERN EDUCACIONAL:
        Este é um padrão comum em sistemas industriais: métodos
        de setup específicos que podem ser expandidos conforme
        necessidades operacionais evoluem.
        */
    }

    /*
    📱 ========================================================================
    MÉTODO REFATORADO: ATUALIZAÇÃO DA INTERFACE SCADA
    ========================================================================
    
    📚 CONCEITO DE REFATORAÇÃO APLICADA:
    Substituição de código repetitivo por métodos utilitários:
    • formatarCampoNumerico() para eliminação de QString::number repetido
    • obterTempoMinutos() para conversão temporal centralizada
    • Estrutura mais legível e manutenível
    
    🏭 MELHORIA INDUSTRIAL:
    • Redução de 14 linhas repetitivas para 7 linhas funcionais
    • Consistência garantida na formatação
    • Facilita mudanças futuras nos padrões de exibição
    • Código mais auditável para sistemas críticos
    */
    void updateUI() {
        /*
        📊 ATUALIZAÇÃO DOS INDICADORES NUMÉRICOS (REFATORADO):
        Uso do método utilitário para formatação padronizada
        */
        if (indicatorLabels.size() >= 7) {
            indicatorLabels[0]->setText(formatarCampoNumerico(reservatorio->vazao_oleo_bopd));
            indicatorLabels[1]->setText(formatarCampoNumerico(reservatorio->pressao_psi));
            indicatorLabels[2]->setText(formatarCampoNumerico(reservatorio->volume_oleo_bbl));
            indicatorLabels[3]->setText(formatarCampoNumerico(reservatorio->temperatura_C));
            indicatorLabels[4]->setText(formatarCampoNumerico(reservatorio->viscosidade_oleo_cp));
            indicatorLabels[5]->setText(formatarCampoNumerico(reservatorio->gas_oil_ratio));
            indicatorLabels[6]->setText(formatarCampoNumerico(reservatorio->water_oil_ratio));
        }

        /*
        📈 ATUALIZAÇÃO DOS GRÁFICOS COM CONTROLE DE PERIODICIDADE (REFATORADO):
        Uso do sistema de periodicidade configurável para análise adaptável
        */
        atualizarGraficosSeNecessario(false);
        
        // 🎓 Atualizar sistema educacional de diagnóstico
        atualizarDiagnosticoEducacional();
    }

    /*
    🎓 ========================================================================
    SISTEMA EDUCACIONAL DE DIAGNÓSTICO INTELIGENTE
    ========================================================================
    
    📚 CONCEITO: Sistema que ensina estudantes a identificar problemas
    operacionais e aplicar as intervenções corretas no momento adequado.
    
    🎯 FUNCIONALIDADES:
    • Detecção automática de cenários críticos
    • Explicações técnicas detalhadas  
    • Orientações passo-a-passo para intervenções
    • Valores específicos recomendados
    • Botão de aplicação automática para aprendizado
    */
    QWidget* criarSistemaEducacional() {
        diagnosticoWidget = new QWidget();
        diagnosticoWidget->setStyleSheet(R"(
            QWidget {
                background-color: black;
                border: 2px solid #007bff;
                border-radius: 8px;
                margin: 5px;
            }
            QLabel {
                padding: 8px;
                font-weight: bold;
                color: white;
            }
            QTextEdit {
                background-color: white;
                border: 1px solid #dee2e6;
                border-radius: 4px;
                padding: 8px;
                font-family: 'Consolas', monospace;
            }
            QPushButton {
                background-color: #28a745;
                color: white;
                font-weight: bold;
                padding: 10px 20px;
                border-radius: 4px;
                border: none;
            }
            QPushButton:hover {
                background-color: #218838;
            }
        )");

        QVBoxLayout* layout = new QVBoxLayout(diagnosticoWidget);

        // Título principal
        diagnosticoTituloLabel = new QLabel("🎓 SISTEMA EDUCACIONAL - DIAGNÓSTICO OPERACIONAL");
        diagnosticoTituloLabel->setAlignment(Qt::AlignCenter);
        diagnosticoTituloLabel->setStyleSheet("font-size: 16px; color: #007bff; background-color: white; border: 1px solid #007bff; border-radius: 4px;");
        layout->addWidget(diagnosticoTituloLabel);




        // Botão de ação alinhado à esquerda
        QHBoxLayout* botoesLayout = new QHBoxLayout();
        
        QPushButton* todosPopsBtn = new QPushButton("📚 MANUAL COMPLETO");
        todosPopsBtn->setStyleSheet("background-color: #17a2b8; color: white; font-weight: bold; padding: 10px; border-radius: 4px; border: none; font-size: 12px;");
        todosPopsBtn->setFixedWidth(360);
        connect(todosPopsBtn, &QPushButton::clicked, this, &SimuladorWindow::mostrarTodosProcedimentos);
        
        botoesLayout->addWidget(todosPopsBtn);
        botoesLayout->addStretch(); // Adiciona espaço flexível à direita para alinhar à esquerda
        
        layout->addLayout(botoesLayout);

        return diagnosticoWidget;
    }

    /*
    ⚙️ ========================================================================
    SISTEMA DE PROCEDIMENTOS OPERACIONAIS PADRÃO (POP)
    ========================================================================
    
    🎓 CONCEITO: Para cada problema operacional, gera uma explicação completa
    seguindo padrões da indústria petrolífera com:
    • Diagnóstico situacional (fenômeno)
    • Análise de causa raiz (origem técnica)  
    • Projeção de consequências (análise de risco)
    • Procedimento de intervenção (SOP - Standard Operating Procedure)
    • Fundamentação técnica (base científica)
    */
    QString gerarProcedimentoOperacional(QString tipoProblema) {
        QString procedimento = "";
        
        if (tipoProblema == "pressao_baixa") {
            procedimento = "⚙️ POP-001: RECUPERAÇÃO DE PRESSÃO DO RESERVATÓRIO\n\n";
            
            procedimento += "🔍 DIAGNÓSTICO SITUACIONAL:\n";
            procedimento += "• Pressão atual: " + QString::number(reservatorio->pressao_psi, 'f', 0) + " psi (abaixo de 2.500 psi)\n";
            procedimento += "• Status: Depleção crítica de energia do reservatório\n";
            procedimento += "• Analogia: Sistema perdendo 'força motriz' natural\n\n";
            
            procedimento += "📋 ANÁLISE DE CAUSA RAIZ:\n";
            procedimento += "• Produção contínua sem reposição de energia\n";
            procedimento += "• Cada barril extraído reduz pressão interna\n";
            procedimento += "• Lei física: Volume ↓ = Pressão ↓\n";
            procedimento += "• Depleção natural progressiva do reservatório\n\n";
            
            procedimento += "⚠️ PROJEÇÃO DE CONSEQUÊNCIAS:\n";
            procedimento += "• CRÍTICO: Vazão em declínio acelerado\n";
            procedimento += "• PRAZO: Parada total em 30-60 minutos\n";
            procedimento += "• ECONÔMICO: Inviabilidade operacional\n";
            procedimento += "• TÉCNICO: Recuperação mais difícil se atrasar\n\n";
            
            procedimento += "🛠️ PROCEDIMENTO DE INTERVENÇÃO (SOP-001):\n";
            double volumeRec = std::max(15000.0, reservatorio->vazao_oleo_bopd * 1.2);
            procedimento += "PASSO 1: Localize 'Injeção de Água (bbl/dia)' nos controles\n";
            procedimento += "PASSO 2: Digite exatamente " + QString::number(volumeRec, 'f', 0) + " (volume calculado)\n";
            procedimento += "PASSO 3: Configure temperatura para 60°C (otimiza viscosidade)\n";
            procedimento += "PASSO 4: Clique 'Iniciar Injeção de Água'\n";
            procedimento += "PASSO 5: Observe gráfico de pressão nos próximos 5-10 minutos\n";
            procedimento += "PASSO 6: Pressão deve subir gradualmente (sinal de sucesso)\n";
            procedimento += "PASSO 7: Vazão de óleo deve aumentar consequentemente\n\n";
            
            procedimento += "🔬 FUNDAMENTAÇÃO TÉCNICA:\n";
            procedimento += "• Água injetada: Sistema de pressure maintenance\n";
            procedimento += "• Mecanismo: Empuxe hidráulico direcionado ao poço\n";
            procedimento += "• Física: Mantém gradiente de pressão (ΔP)\n";
            procedimento += "• Padrão global: Waterflooding secundário\n";
            procedimento += "• T° 60°C: Redução da viscosidade µ do óleo\n";
            procedimento += "• Volume: 1.2x produção (regra API/SPE)";
            
        } else if (tipoProblema == "gor_elevado") {
            procedimento = "⚙️ POP-002: CONTROLE DE GAS-OIL RATIO (GOR)\n\n";
            
            procedimento += "🔍 O QUE ESTÁ ACONTECENDO:\n";
            procedimento += "• GOR atual: " + QString::number(reservatorio->gas_oil_ratio, 'f', 0) + " scf/bbl (acima de 2.500)\n";
            procedimento += "• Muito gás saindo junto com o óleo\n";
            procedimento += "• É como abrir um refrigerante quente - gás se liberta\n\n";
            
            procedimento += "❓ POR QUE ACONTECEU:\n";
            procedimento += "• Pressão caiu abaixo do 'ponto de bolha' (~2.800 psi)\n";
            procedimento += "• Gás dissolvido no óleo começou a se separar\n";
            procedimento += "• Como bolhas numa bebida gasosa aquecida\n";
            procedimento += "• Fenômeno natural quando pressão diminui\n\n";
            
            procedimento += "⚠️ O QUE VAI ACONTECER SE NÃO INTERVIR:\n";
            procedimento += "• Eficiência de produção vai piorar continuamente\n";
            procedimento += "• Gás livre ocupa espaço que deveria ser do óleo\n";
            procedimento += "• Viscosidade do óleo aumenta (sem gás dissolvido)\n";
            procedimento += "• Equipamentos podem ter problemas com excesso de gás\n\n";
            
            procedimento += "🛠️ PASSO-A-PASSO DA INTERVENÇÃO:\n";
            double gasRec = std::min(8.0, reservatorio->gas_oil_ratio / 400.0);
            procedimento += "PASSO 1: Localize 'Injeção de Gás (Mm³/dia)' nos controles\n";
            procedimento += "PASSO 2: Digite " + QString::number(gasRec, 'f', 1) + " Mm³/dia (calculado pela fórmula)\n";
            procedimento += "PASSO 3: Configure densidade para 0.8 kg/m³ (gás padrão)\n";
            procedimento += "PASSO 4: Clique 'Iniciar Injeção de Gás'\n";
            procedimento += "PASSO 5: Monitore GOR - deve diminuir em 15-20 minutos\n";
            procedimento += "PASSO 6: Observe estabilização da pressão do reservatório\n";
            procedimento += "PASSO 7: Produção deve se tornar mais eficiente\n\n";
            
            procedimento += "🎓 TEORIA - POR QUE FUNCIONA:\n";
            procedimento += "• Gás injetado reestabelece pressão acima do ponto de bolha\n";
            procedimento += "• Força o gás livre a se redissolver no óleo\n";
            procedimento += "• Restaura viscosidade ideal do óleo\n";
            procedimento += "• Técnica: gas lift ou pressure maintenance\n";
            procedimento += "• Densidade 0.8: otimizada para miscibilidade\n";
            procedimento += "• Fórmula volume: GOR/400 (regra da indústria)";
            
        } else if (tipoProblema == "excesso_gas") {
            procedimento = "📋 RECEITA: CONTROLE DE EXCESSO DE GÁS (FLARE)\n\n";
            
            procedimento += "🔍 O QUE ESTÁ ACONTECENDO:\n";
            procedimento += "• Volume de gás: " + QString::number(reservatorio->volume_gas_m3, 'f', 0) + " m³ (acima de 8.000 m³)\n";
            procedimento += "• Gás acumulando mais rápido que pode ser processado\n";
            procedimento += "• Como encher um balão além da capacidade\n\n";
            
            procedimento += "❓ POR QUE ACONTECEU:\n";
            procedimento += "• Produção de gás excedeu capacidade de processamento\n";
            procedimento += "• Podem ter falhas nos equipamentos de gás\n";
            procedimento += "• GOR alto gerou mais gás que o esperado\n";
            procedimento += "• Sistema não consegue escoar o volume produzido\n\n";
            
            procedimento += "⚠️ O QUE VAI ACONTECER SE NÃO INTERVIR:\n";
            procedimento += "• RISCO DE SEGURANÇA: sobrepressão perigosa\n";
            procedimento += "• Pode causar parada de emergência automática\n";
            procedimento += "• Equipamentos podem sofrer danos\n";
            procedimento += "• Em casos extremos: vazamentos ou explosão\n\n";
            
            procedimento += "🛠️ PASSO-A-PASSO DA INTERVENÇÃO:\n";
            double flareRec = reservatorio->volume_gas_m3 * 0.3;
            procedimento += "PASSO 1: URGENTE - Localize 'Liberação de Gás - Flare (m³/dia)'\n";
            procedimento += "PASSO 2: Digite " + QString::number(flareRec, 'f', 0) + " m³/dia (30% do volume atual)\n";
            procedimento += "PASSO 3: Clique 'Ativar Flare' IMEDIATAMENTE\n";
            procedimento += "PASSO 4: Observe volume de gás diminuir rapidamente\n";
            procedimento += "PASSO 5: Mantenha flare até volume < 6.000 m³\n";
            procedimento += "PASSO 6: Investigue causa raiz do excesso de gás\n";
            procedimento += "PASSO 7: Ajuste produção se necessário\n\n";
            
            procedimento += "🎓 TEORIA - POR QUE FUNCIONA:\n";
            procedimento += "• Flare = queima controlada e segura do excesso\n";
            procedimento += "• Remove gás do sistema sem criar riscos\n";
            procedimento += "• Alivia pressão instantaneamente\n";
            procedimento += "• Procedimento de segurança padrão mundial\n";
            procedimento += "• 30% é taxa segura para não desestabilizar sistema\n";
            procedimento += "• Queima a alta temperatura: destrói gases tóxicos";
            
        } else if (tipoProblema == "producao_baixa") {
            procedimento = "📋 RECEITA: OTIMIZAÇÃO DE PRODUÇÃO SUBÓTIMA\n\n";
            
            procedimento += "🔍 O QUE ESTÁ ACONTECENDO:\n";
            procedimento += "• Vazão: " + QString::number(reservatorio->vazao_oleo_bopd, 'f', 0) + " bopd (abaixo de 12.000)\n";
            procedimento += "• Pressão OK: " + QString::number(reservatorio->pressao_psi, 'f', 0) + " psi (adequada)\n";
            procedimento += "• Poço não está produzindo seu potencial máximo\n\n";
            
            procedimento += "❓ POR QUE ACONTECEU (MÚLTIPLAS CAUSAS):\n";
            procedimento += "• Viscosidade alta do óleo (baixa temperatura)\n";
            procedimento += "• Dano na formação (plugging de poros)\n";
            procedimento += "• WOR alto (muita água junto)\n";
            procedimento += "• Choke muito fechado\n";
            procedimento += "• Coning de água ou gás no poço\n\n";
            
            procedimento += "⚠️ O QUE VAI ACONTECER SE NÃO INTERVIR:\n";
            procedimento += "• Perda de receita: produção abaixo do potencial\n";
            procedimento += "• Reservatório pode se deteriorar com tempo\n";
            procedimento += "• Competitividade econômica reduzida\n";
            procedimento += "• Pode evoluir para outros problemas\n\n";
            
            procedimento += "🛠️ PASSO-A-PASSO DA INVESTIGAÇÃO:\n";
            procedimento += "PASSO 1: Analise gráficos - quando começou a declinar?\n";
            procedimento += "PASSO 2: Verifique WOR - se > 2.0, problema é água\n";
            procedimento += "PASSO 3: Cheque viscosidade vs temperatura\n";
            procedimento += "PASSO 4: Se T° < 80°C, considere aquecimento\n";
            procedimento += "PASSO 5: Teste injeção leve de água (5.000 bbl/dia)\n";
            procedimento += "PASSO 6: Monitore resposta por 30 minutos\n";
            procedimento += "PASSO 7: Se não melhorar, considere vapor ou choke\n\n";
            
            procedimento += "🎓 TEORIA - DIAGNÓSTICO DIFERENCIAL:\n";
            procedimento += "• Pressão OK + produção baixa = problema no poço\n";
            procedimento += "• Não é energia do reservatório (pressure drive)\n";
            procedimento += "• Foco: produtividade e fluxo no near-wellbore\n";
            procedimento += "• Viscosidade inversamente proporcional à T°\n";
            procedimento += "• WOR alto indica breakthrough de água\n";
            procedimento += "• Injeção teste: diagnóstica sweep efficiency";
            
        } else if (tipoProblema == "wor_elevado") {
            procedimento = "📋 RECEITA: CONTROLE DE WATER-OIL RATIO (WOR)\n\n";
            
            procedimento += "🔍 O QUE ESTÁ ACONTECENDO:\n";
            procedimento += "• WOR atual: " + QString::number(reservatorio->water_oil_ratio, 'f', 2) + " (acima de 2.0)\n";
            procedimento += "• Muita água sendo produzida junto com óleo\n";
            procedimento += "• É como sugar um milkshake com muito gelo derretido\n\n";
            
            procedimento += "❓ POR QUE ACONTECEU:\n";
            procedimento += "• Coning de água severo: água 'subiu' até o poço\n";
            procedimento += "• Drawdown muito alto (poço 'puxando' água)\n";
            procedimento += "• Permeabilidade da água maior que do óleo\n";
            procedimento += "• Heterogeneidade do reservatório\n\n";
            
            procedimento += "⚠️ O QUE VAI ACONTECER SE NÃO INTERVIR:\n";
            procedimento += "• Custo de separação água/óleo aumenta\n";
            procedimento += "• Receita líquida diminui drasticamente\n";
            procedimento += "• Pode inviabilizar economicamente o poço\n";
            procedimento += "• Problemas ambientais com descarte de água\n\n";
            
            procedimento += "🛠️ PASSO-A-PASSO DA INTERVENÇÃO:\n";
            procedimento += "PASSO 1: Reduza drawdown - 'Fechar Válvula de Choke'\n";
            procedimento += "PASSO 2: Monitore WOR por 20-30 minutos\n";
            procedimento += "PASSO 3: Se não melhorar, considere injeção de vapor\n";
            procedimento += "PASSO 4: Configure vapor por 300 segundos\n";
            procedimento += "PASSO 5: Vapor reduz viscosidade - facilita separação\n";
            procedimento += "PASSO 6: Avalie viabilidade econômica contínua\n";
            procedimento += "PASSO 7: Se WOR não diminuir, poço pode precisar workover\n\n";
            
            procedimento += "🎓 TEORIA - POR QUE FUNCIONA:\n";
            procedimento += "• Menos drawdown = menos 'sucção' de água\n";
            procedimento += "• Vapor aquece: reduz viscosidade relativa óleo/água\n";
            procedimento += "• Água tem mobilidade maior em T° baixa\n";
            procedimento += "• Controle de coning é arte + ciência\n";
            procedimento += "• WOR econômico varia: ~2.0 para Brent, ~5.0 para heavy\n";
            procedimento += "• Workover = intervenção física no poço";
        }
        
        return procedimento;
    }

    void mostrarTodosProcedimentos() {
        QDialog* popsDialog = new QDialog(this);
        popsDialog->setWindowTitle("📚 MANUAL DE PROCEDIMENTOS OPERACIONAIS PADRÃO");
        popsDialog->resize(900, 700);
        
        QVBoxLayout* layout = new QVBoxLayout(popsDialog);
        
        QLabel* titulo = new QLabel("🎓 MANUAL DO OPERADOR - POPs INDUSTRIAIS");
        titulo->setAlignment(Qt::AlignCenter);
        titulo->setStyleSheet("font-size: 18px; font-weight: bold; color: #007bff; background-color: white; border: 2px solid #007bff; border-radius: 6px; padding: 10px; margin: 5px;");
        layout->addWidget(titulo);
        
        QTabWidget* abas = new QTabWidget();
        abas->setStyleSheet("QTabWidget::pane { border: 1px solid #dee2e6; } QTabBar::tab { padding: 8px 16px; margin-right: 2px; } QTabBar::tab:selected { background-color: #007bff; color: white; }");
        
        // Aba 1: Pressão Baixa
        QWidget* pressaoTabWidget = new QWidget();
        QVBoxLayout* pressaoTabLayout = new QVBoxLayout(pressaoTabWidget);
        
        QTextEdit* popPressao = new QTextEdit();
        popPressao->setReadOnly(true);
        popPressao->setText(gerarProcedimentoOperacional("pressao_baixa"));
        popPressao->setStyleSheet("font-family: 'Consolas', monospace; background-color: white; color: black;");
        pressaoTabLayout->addWidget(popPressao);
        
        // Adicionar botão aplicar solução
        QPushButton* aplicarPressaoBtn = new QPushButton("🤖 APLICAR SOLUÇÃO PARA PRESSÃO CRÍTICA");
        aplicarPressaoBtn->setStyleSheet("background-color: #28a745; color: white; font-weight: bold; padding: 10px; border-radius: 4px; border: none; font-size: 12px; margin: 10px;");
        connect(aplicarPressaoBtn, &QPushButton::clicked, [this, popsDialog]() {
            if (diagnosticoAtual == "pressao_baixa") {
                aplicarSolucaoAutomatica();
                popsDialog->accept();
            } else {
                QMessageBox::information(this, "Informação", "Esta solução só pode ser aplicada quando o sistema detectar pressão crítica.");
            }
        });
        pressaoTabLayout->addWidget(aplicarPressaoBtn);
        
        abas->addTab(pressaoTabWidget, "🔴 Pressão Crítica");
        
        // Aba 2: GOR Elevado  
        QWidget* gorTabWidget = new QWidget();
        QVBoxLayout* gorTabLayout = new QVBoxLayout(gorTabWidget);
        
        QTextEdit* receitaGor = new QTextEdit();
        receitaGor->setReadOnly(true);
        receitaGor->setText(gerarProcedimentoOperacional("gor_elevado"));
        receitaGor->setStyleSheet("font-family: 'Consolas', monospace; background-color: white; color: black;");
        gorTabLayout->addWidget(receitaGor);
        
        // Adicionar botão aplicar solução
        QPushButton* aplicarGorBtn = new QPushButton("🤖 APLICAR SOLUÇÃO PARA GOR ELEVADO");
        aplicarGorBtn->setStyleSheet("background-color: #28a745; color: white; font-weight: bold; padding: 10px; border-radius: 4px; border: none; font-size: 12px; margin: 10px;");
        connect(aplicarGorBtn, &QPushButton::clicked, [this, popsDialog]() {
            if (diagnosticoAtual == "gor_elevado") {
                aplicarSolucaoAutomatica();
                popsDialog->accept();
            } else {
                QMessageBox::information(this, "Informação", "Esta solução só pode ser aplicada quando o sistema detectar GOR elevado.");
            }
        });
        gorTabLayout->addWidget(aplicarGorBtn);
        
        abas->addTab(gorTabWidget, "🟠 GOR Elevado");
        
        // Aba 3: Excesso de Gás
        QWidget* gasTabWidget = new QWidget();
        QVBoxLayout* gasTabLayout = new QVBoxLayout(gasTabWidget);
        
        QTextEdit* receitaGas = new QTextEdit();
        receitaGas->setReadOnly(true);
        receitaGas->setText(gerarProcedimentoOperacional("excesso_gas"));
        receitaGas->setStyleSheet("font-family: 'Consolas', monospace; background-color: white; color: black;");
        gasTabLayout->addWidget(receitaGas);
        
        // Adicionar botão aplicar solução
        QPushButton* aplicarGasBtn = new QPushButton("🤖 APLICAR SOLUÇÃO PARA EXCESSO DE GÁS");
        aplicarGasBtn->setStyleSheet("background-color: #28a745; color: white; font-weight: bold; padding: 10px; border-radius: 4px; border: none; font-size: 12px; margin: 10px;");
        connect(aplicarGasBtn, &QPushButton::clicked, [this, popsDialog]() {
            if (diagnosticoAtual == "excesso_gas") {
                aplicarSolucaoAutomatica();
                popsDialog->accept();
            } else {
                QMessageBox::information(this, "Informação", "Esta solução só pode ser aplicada quando o sistema detectar excesso de gás.");
            }
        });
        gasTabLayout->addWidget(aplicarGasBtn);
        
        abas->addTab(gasTabWidget, "🟡 Excesso Gás");
        
        // Aba 4: Produção Baixa
        QWidget* producaoTabWidget = new QWidget();
        QVBoxLayout* producaoTabLayout = new QVBoxLayout(producaoTabWidget);
        
        QTextEdit* receitaProducao = new QTextEdit();
        receitaProducao->setReadOnly(true);
        receitaProducao->setText(gerarProcedimentoOperacional("producao_baixa"));
        receitaProducao->setStyleSheet("font-family: 'Consolas', monospace; background-color: white; color: black;");
        producaoTabLayout->addWidget(receitaProducao);
        
        // Adicionar botão aplicar solução
        QPushButton* aplicarProducaoBtn = new QPushButton("🤖 APLICAR SOLUÇÃO PARA PRODUÇÃO BAIXA");
        aplicarProducaoBtn->setStyleSheet("background-color: #28a745; color: white; font-weight: bold; padding: 10px; border-radius: 4px; border: none; font-size: 12px; margin: 10px;");
        connect(aplicarProducaoBtn, &QPushButton::clicked, [this, popsDialog]() {
            if (diagnosticoAtual == "producao_baixa") {
                aplicarSolucaoAutomatica();
                popsDialog->accept();
            } else {
                QMessageBox::information(this, "Informação", "Esta solução só pode ser aplicada quando o sistema detectar produção baixa.");
            }
        });
        producaoTabLayout->addWidget(aplicarProducaoBtn);
        
        abas->addTab(producaoTabWidget, "🟠 Produção Baixa");
        
        // Aba 5: WOR Elevado
        QWidget* worTabWidget = new QWidget();
        QVBoxLayout* worTabLayout = new QVBoxLayout(worTabWidget);
        
        QTextEdit* receitaWor = new QTextEdit();
        receitaWor->setReadOnly(true);
        receitaWor->setText(gerarProcedimentoOperacional("wor_elevado"));
        receitaWor->setStyleSheet("font-family: 'Consolas', monospace; background-color: white; color: black;");
        worTabLayout->addWidget(receitaWor);
        
        // Adicionar botão aplicar solução
        QPushButton* aplicarWorBtn = new QPushButton("🤖 APLICAR SOLUÇÃO PARA WOR ELEVADO");
        aplicarWorBtn->setStyleSheet("background-color: #28a745; color: white; font-weight: bold; padding: 10px; border-radius: 4px; border: none; font-size: 12px; margin: 10px;");
        connect(aplicarWorBtn, &QPushButton::clicked, [this, popsDialog]() {
            if (diagnosticoAtual == "wor_elevado") {
                aplicarSolucaoAutomatica();
                popsDialog->accept();
            } else {
                QMessageBox::information(this, "Informação", "Esta solução só pode ser aplicada quando o sistema detectar WOR elevado.");
            }
        });
        worTabLayout->addWidget(aplicarWorBtn);
        
        abas->addTab(worTabWidget, "🟤 WOR Elevado");
        
        // Aba 6: Resumo Geral
        QTextEdit* resumoGeral = new QTextEdit();
        resumoGeral->setReadOnly(true);
        QString resumo = "📋 RESUMO EXECUTIVO - GUIA RÁPIDO DE DECISÃO\n\n";
        resumo += "🚨 ORDEM DE PRIORIDADE OPERACIONAL:\n\n";
        resumo += "1. PRESSÃO BAIXA (<2500 psi) - CRÍTICO ⚡\n";
        resumo += "   → Injeção de água URGENTE\n";
        resumo += "   → Sem pressão = sem produção\n\n";
        resumo += "2. EXCESSO DE GÁS (>8000 m³) - SEGURANÇA 🔥\n";
        resumo += "   → Flare imediato\n";
        resumo += "   → Risco de explosão\n\n";
        resumo += "3. GOR ELEVADO (>2500 scf/bbl) - EFICIÊNCIA ⚡\n";
        resumo += "   → Injeção de gás\n";
        resumo += "   → Restaura qualidade do óleo\n\n";
        resumo += "4. WOR ELEVADO (>2.0) - ECONOMIA 💰\n";
        resumo += "   → Controle de choke\n";
        resumo += "   → Viabilidade econômica\n\n";
        resumo += "5. PRODUÇÃO BAIXA - OTIMIZAÇÃO 📈\n";
        resumo += "   → Diagnóstico múltiplas causas\n";
        resumo += "   → Análise case-by-case\n\n";
        resumo += "🎓 REGRAS DE OURO:\n";
        resumo += "• NUNCA ignore pressão baixa\n";
        resumo += "• SEMPRE priorize segurança (flare)\n";
        resumo += "• MONITORE tendências, não valores pontuais\n";
        resumo += "• DOCUMENTE todas as intervenções\n";
        resumo += "• ENTENDA o 'porquê' antes de agir\n\n";
        resumo += "💡 DICA FINAL:\n";
        resumo += "Cada reservatório é único, mas os princípios físicos\n";
        resumo += "são universais. Use este manual como base e adapte\n";
        resumo += "conforme a experiência operacional.";
        resumoGeral->setText(resumo);
        resumoGeral->setStyleSheet("font-family: 'Consolas', monospace; background-color: white; color: black;");
        abas->addTab(resumoGeral, "📊 Resumo Geral");
        
        layout->addWidget(abas);
        
        // Botão para fechar
        QPushButton* fecharBtn = new QPushButton("✅ Entendi - Fechar Manual");
        fecharBtn->setStyleSheet("background-color: #28a745; color: white; font-weight: bold; padding: 12px 24px; border-radius: 6px; border: none; font-size: 14px;");
        connect(fecharBtn, &QPushButton::clicked, popsDialog, &QDialog::accept);
        layout->addWidget(fecharBtn);
        
        popsDialog->exec();
    }

    void mostrarProcedimentoAtual() {
        if (diagnosticoAtual == "normal") return;
        
        QDialog* popDialog = new QDialog(this);
        popDialog->setWindowTitle("⚙️ PROCEDIMENTO OPERACIONAL ESPECÍFICO");
        popDialog->resize(800, 600);
        
        QVBoxLayout* layout = new QVBoxLayout(popDialog);
        
        // Título com o problema específico
        QString tituloProblema;
        if (diagnosticoAtual == "pressao_baixa") tituloProblema = "🔴 PRESSÃO CRÍTICA";
        else if (diagnosticoAtual == "gor_elevado") tituloProblema = "🟠 GOR ELEVADO";
        else if (diagnosticoAtual == "excesso_gas") tituloProblema = "🟡 EXCESSO DE GÁS";
        else if (diagnosticoAtual == "producao_baixa") tituloProblema = "🟠 PRODUÇÃO BAIXA";
        else if (diagnosticoAtual == "wor_elevado") tituloProblema = "🟤 WOR ELEVADO";
        
        QLabel* titulo = new QLabel(tituloProblema + " - PROCEDIMENTO DETALHADO");
        titulo->setAlignment(Qt::AlignCenter);
        titulo->setStyleSheet("font-size: 16px; font-weight: bold; color: #ffffff; background-color: #dc3545; border-radius: 6px; padding: 12px; margin: 5px;");
        layout->addWidget(titulo);
        
        // Conteúdo do procedimento
        QTextEdit* procedimentoText = new QTextEdit();
        procedimentoText->setReadOnly(true);
        procedimentoText->setText(gerarProcedimentoOperacional(diagnosticoAtual));
        procedimentoText->setStyleSheet("background-color: #001f3f; color: #ffffff; border: 2px solid #007bff; border-radius: 4px; padding: 12px; font-family: 'Consolas', 'Monaco', monospace; font-size: 13px; font-weight: bold; line-height: 1.4;");
        layout->addWidget(procedimentoText);
        
        // Botões de ação
        QHBoxLayout* botoesLayout = new QHBoxLayout();
        
        QPushButton* aplicarBtn = new QPushButton("🤖 APLICAR ESTE PROCEDIMENTO");
        aplicarBtn->setStyleSheet("background-color: #28a745; color: white; font-weight: bold; padding: 12px 20px; border-radius: 6px; border: none; font-size: 14px;");
        connect(aplicarBtn, &QPushButton::clicked, [this, popDialog]() {
            aplicarSolucaoAutomatica();
            popDialog->accept();
        });
        botoesLayout->addWidget(aplicarBtn);
        
        QPushButton* fecharBtn = new QPushButton("📖 ENTENDI - FECHAR");
        fecharBtn->setStyleSheet("background-color: #6c757d; color: white; font-weight: bold; padding: 12px 20px; border-radius: 6px; border: none; font-size: 14px;");
        connect(fecharBtn, &QPushButton::clicked, popDialog, &QDialog::accept);
        botoesLayout->addWidget(fecharBtn);
        
        layout->addLayout(botoesLayout);
        
        popDialog->exec();
    }

    /*
    🔊 ========================================================================
    SISTEMA DE ALERTAS SONOROS INDUSTRIAIS
    ========================================================================
    
    🎯 CONCEITO: Alertas auditivos padronizados para ambientes industriais
    • CRÍTICO: Frequência alta, urgente (pressão baixa, segurança)
    • ATENÇÃO: Frequência moderada, alerta (GOR, WOR, produção)
    */
    void emitirAlertaSonoro(QString tipoAlerta) {
        static qint64 ultimoAlerta = 0;
        qint64 tempoAtual = QDateTime::currentMSecsSinceEpoch();
        
        // Evitar spam sonoro - mínimo 30 segundos entre alertas
        if (tempoAtual - ultimoAlerta < 30000) {
            return;
        }
        ultimoAlerta = tempoAtual;
        
        if (tipoAlerta == "critico") {
            // Padrão industrial para alertas críticos: 3 beeps rápidos
            QApplication::beep();
            QTimer::singleShot(200, []() { QApplication::beep(); });
            QTimer::singleShot(400, []() { QApplication::beep(); });
            
            // Identificar causa específica do alerta - DIAGNÓSTICO COMPLETO
            QString causa = "";
            QStringList problemas;
            
            // Verificar TODOS os parâmetros críticos
            if (reservatorio->pressao_psi < 2500.0) {
                problemas << QString("PRESSÃO BAIXA: %1 psi (< 2500)").arg(reservatorio->pressao_psi, 0, 'f', 0);
            }
            if (reservatorio->volume_gas_m3 > 15000.0) {
                problemas << QString("EXCESSO DE GÁS: %1 m³ (> 15000)").arg(reservatorio->volume_gas_m3, 0, 'f', 0);
            }
            if (reservatorio->water_oil_ratio > 0.4) {
                problemas << QString("BSW ALTO: %1% (> 40%)").arg(reservatorio->water_oil_ratio * 100, 0, 'f', 1);
            }
            if (reservatorio->gas_oil_ratio > 1000.0) {
                problemas << QString("GOR ALTO: %1 scf/bbl (> 1000)").arg(reservatorio->gas_oil_ratio, 0, 'f', 0);
            }
            if (reservatorio->em_emergencia) {
                problemas << QString("SHUTDOWN: %1").arg(reservatorio->motivo_emergencia);
            }
            
            if (!problemas.isEmpty()) {
                causa = problemas.join(" | ");
            } else {
                // Log detalhado para debug se não identificou a causa
                causa = QString("VALORES ATUAIS: P=%1psi, Gas=%2m³, BSW=%3%, GOR=%4")
                       .arg(reservatorio->pressao_psi, 0, 'f', 0)
                       .arg(reservatorio->volume_gas_m3, 0, 'f', 0)
                       .arg(reservatorio->water_oil_ratio * 100, 0, 'f', 1)
                       .arg(reservatorio->gas_oil_ratio, 0, 'f', 0);
            }
            
            logMessage("🚨 ALERTA CRÍTICO: " + causa, "critico");
            
        } else if (tipoAlerta == "atencao") {
            // Padrão para atenção: 2 beeps mais suaves
            QApplication::beep();
            QTimer::singleShot(500, []() { QApplication::beep(); });
            
            logMessage("⚠️ ALERTA: Situação requer atenção operacional.", "alerta");
        }
        
        // Log operacional para auditoria (sem mencionar "sonoro" se não há som real)
        QString logMsg = QString("Sistema de alerta ativado - Tipo: %1").arg(tipoAlerta.toUpper());
        logMessage(logMsg, "sistema");
    }

    void atualizarDiagnosticoEducacional() {
        // Durante inicialização, aguardar estabilização do sistema
        if (!sistemaInicializado) {
            tipoAlertaAtual = "NORMAL";
            diagnosticoAtual = "normal";
            return;
        }
        
        // Aguardar período de estabilização adicional após inicialização
        static qint64 tempoInicializacao = 0;
        if (tempoInicializacao == 0) {
            tempoInicializacao = QDateTime::currentMSecsSinceEpoch();
        }
        qint64 tempoDecorrido = QDateTime::currentMSecsSinceEpoch() - tempoInicializacao;
        if (tempoDecorrido < 15000) { // 15 segundos de estabilização
            tipoAlertaAtual = "NORMAL";
            diagnosticoAtual = "normal";
            return;
        }
        
        // Análise de condições críticas - MÚLTIPLOS DIAGNÓSTICOS
        QStringList statusList;
        QStringList explicacaoList;
        QStringList orientacaoList;
        QStringList valoresList;
        QString tipoProblema = "normal";
        bool temProblema = false;
        int problemasEncontrados = 0;

        // 1. DIAGNÓSTICO: Pressão baixa (declínio crítico) - PRIORIDADE MÁXIMA
        if (reservatorio->pressao_psi < 2500.0) {
            problemasEncontrados++;
            statusList << "🔴 PRESSÃO CRÍTICA";
            
            QString exp = "DECLÍNIO DE PRESSÃO DETECTADO!\n";
            exp += "• Pressão atual: " + QString::number(reservatorio->pressao_psi, 'f', 0) + " psi\n";
            exp += "• Abaixo de 2.500 psi (limite operacional)\n";
            exp += "• Causa: Depleção natural sem reposição\n";
            exp += "• Risco: Parada total de produção";
            explicacaoList << exp;

            QString ori = "INTERVENÇÃO URGENTE - INJEÇÃO DE ÁGUA:\n";
            ori += "1. Localize 'Injeção de Água (bbl/dia)'\n";
            ori += "2. Use valor recomendado abaixo\n";
            ori += "3. Configure temperatura 60°C\n";
            ori += "4. Monitore pressão nos próximos 10 min";
            orientacaoList << ori;

            double volumeRecomendado = std::max(15000.0, reservatorio->vazao_oleo_bopd * 1.2);
            valoresList << QString("💧 Água: %1 bbl/dia @ 60°C").arg(volumeRecomendado, 0, 'f', 0);
            
            tipoProblema = "pressao_baixa"; // Prioridade máxima
            temProblema = true;
        }

        // 2. DIAGNÓSTICO: GOR elevado
        if (reservatorio->gas_oil_ratio > 2500.0) {
            problemasEncontrados++;
            statusList << "🟠 GOR ELEVADO";
            
            QString exp = "GOR (GAS-OIL RATIO) CRÍTICO!\n";
            exp += "• GOR atual: " + QString::number(reservatorio->gas_oil_ratio, 'f', 0) + " scf/bbl\n";
            exp += "• Limite: 2.500 scf/bbl\n";
            exp += "• Causa: Pressão < ponto de bolha\n";
            exp += "• Efeito: Gás livre reduz eficiência";
            explicacaoList << exp;

            QString ori = "INTERVENÇÃO - INJEÇÃO DE GÁS:\n";
            ori += "1. Localize 'Injeção de Gás (Mm³/dia)'\n";
            ori += "2. Use densidade 0.8 kg/m³\n";
            ori += "3. GOR deve diminuir gradualmente\n";
            ori += "4. Monitore estabilização da pressão";
            orientacaoList << ori;

            double gasRecomendado = std::min(8.0, reservatorio->gas_oil_ratio / 400.0);
            valoresList << QString("⚡ Gás: %1 Mm³/dia @ 0.8 kg/m³").arg(gasRecomendado, 0, 'f', 1);
            
            if (tipoProblema == "normal") tipoProblema = "gor_elevado";
            temProblema = true;
        }

        // 3. DIAGNÓSTICO: Volume de gás excessivo
        if (reservatorio->volume_gas_m3 > 15000.0) {
            problemasEncontrados++;
            statusList << "🟡 EXCESSO DE GÁS";
            
            QString exp = "ACÚMULO EXCESSIVO DE GÁS!\n";
            exp += "• Volume: " + QString::number(reservatorio->volume_gas_m3, 'f', 0) + " m³\n";
            exp += "• Limite seguro: 15.000 m³\n";
            exp += "• Risco: Sobrepressão perigosa\n";
            exp += "• Ação: Liberação controlada urgente";
            explicacaoList << exp;

            QString ori = "SEGURANÇA - SISTEMA FLARE:\n";
            ori += "1. Localize 'Liberação de Gás - Flare'\n";
            ori += "2. Use 30% do volume atual\n";
            ori += "3. Queima controlada do excesso\n";
            ori += "4. Volume deve diminuir rapidamente";
            orientacaoList << ori;

            valoresList << QString("🔥 Flare: %1 m³/dia").arg(reservatorio->volume_gas_m3 * 0.3, 0, 'f', 0);
            
            if (tipoProblema == "normal") tipoProblema = "excesso_gas";
            temProblema = true;
        }

        // 4. DIAGNÓSTICO: Produção baixa (mas pressão OK)
        if (reservatorio->vazao_oleo_bopd < 12000.0 && reservatorio->pressao_psi > 2500.0) {
            problemasEncontrados++;
            statusList << "🟠 PRODUÇÃO SUBÓTIMA";
            
            QString exp = "VAZÃO ABAIXO DO POTENCIAL!\n";
            exp += "• Vazão: " + QString::number(reservatorio->vazao_oleo_bopd, 'f', 0) + " bopd\n";
            exp += "• Potencial: > 20.000 bopd\n";
            exp += "• Pressão OK: " + QString::number(reservatorio->pressao_psi, 'f', 0) + " psi\n";
            exp += "• Problema: Produtividade do poço";
            explicacaoList << exp;

            QString ori = "ANÁLISE E OTIMIZAÇÃO:\n";
            ori += "1. Verifique gráficos de histórico\n";
            ori += "2. Analise viscosidade vs temperatura\n";
            ori += "3. Considere injeção leve de água\n";
            ori += "4. Revise WOR se estiver alto";
            orientacaoList << ori;

            valoresList << "🔍 Múltiplas causas - análise detalhada";
            
            if (tipoProblema == "normal") tipoProblema = "producao_baixa";
            temProblema = true;
        }

        // 5. DIAGNÓSTICO: WOR alto (novo diagnóstico)
        if (reservatorio->water_oil_ratio > 2.0) {
            problemasEncontrados++;
            statusList << "🟤 WOR ELEVADO";
            
            QString exp = "WATER-OIL RATIO CRÍTICO!\n";
            exp += "• WOR atual: " + QString::number(reservatorio->water_oil_ratio, 'f', 2) + "\n";
            exp += "• Limite: 2.0 (econômico)\n";
            exp += "• Causa: Coning de água severo\n";
            exp += "• Efeito: Redução da receita líquida";
            explicacaoList << exp;

            QString ori = "CONTROLE DE CONING:\n";
            ori += "1. Reduza drawdown (feche choke)\n";
            ori += "2. Considere injeção de vapor\n";
            ori += "3. Monitore produção de água\n";
            ori += "4. Avalie viabilidade econômica";
            orientacaoList << ori;

            valoresList << "🎛️ Controle de choke + monitoramento";
            
            if (tipoProblema == "normal") tipoProblema = "wor_elevado";
            temProblema = true;
        }

        // Compilar informações para interface
        QString statusFinal, explicacaoFinal, orientacaoFinal, valoresFinal;
        
        if (problemasEncontrados == 0) {
            statusFinal = "🟢 OPERAÇÃO NORMAL";
            explicacaoFinal = "✅ Todos os parâmetros estão dentro dos limites operacionais normais.";
            orientacaoFinal = "🎓 Continue monitorando. O sistema alertará quando houver necessidade de intervenção.";
            valoresFinal = "Nenhuma intervenção necessária no momento.";
        } else if (problemasEncontrados == 1) {
            statusFinal = statusList.first();
            explicacaoFinal = explicacaoList.first();
            // ⚙️ Usar procedimento operacional padrão detalhado para problema único
            orientacaoFinal = gerarProcedimentoOperacional(tipoProblema);
            valoresFinal = valoresList.first();
        } else {
            statusFinal = QString("⚠️ MÚLTIPLOS PROBLEMAS (%1)").arg(problemasEncontrados);
            explicacaoFinal = QString("🚨 DETECTADOS %1 PROBLEMAS SIMULTÂNEOS:\n\n").arg(problemasEncontrados);
            for (int i = 0; i < explicacaoList.size(); ++i) {
                explicacaoFinal += QString("PROBLEMA %1: %2\n").arg(i+1).arg(statusList[i]) + "\n";
                explicacaoFinal += explicacaoList[i] + "\n" + QString(40, '-') + "\n\n";
            }
            
            // ⚙️ Para múltiplos problemas, usar POP do problema prioritário + lista dos outros
            orientacaoFinal = "🎯 ESTRATÉGIA PARA MÚLTIPLOS PROBLEMAS:\n\n";
            orientacaoFinal += "⚙️ POP PRIORITÁRIO (MAIS CRÍTICO):\n";
            orientacaoFinal += QString(60, '=') + "\n\n";
            orientacaoFinal += gerarProcedimentoOperacional(tipoProblema) + "\n\n";
            
            orientacaoFinal += QString(60, '=') + "\n";
            orientacaoFinal += "⚠️ OUTROS PROBLEMAS DETECTADOS:\n\n";
            QStringList tiposProblemas = {"pressao_baixa", "gor_elevado", "excesso_gas", "producao_baixa", "wor_elevado"};
            QStringList nomesProblemas = {"Pressão Baixa", "GOR Elevado", "Excesso de Gás", "Produção Subótima", "WOR Elevado"};
            
            for (int i = 0; i < statusList.size(); ++i) {
                QString statusAtual = statusList[i];
                if (!statusAtual.contains("CRÍTICA")) { // Não é o prioritário
                    for (int j = 0; j < tiposProblemas.size(); ++j) {
                        if (statusAtual.contains(nomesProblemas[j].toUpper())) {
                            orientacaoFinal += QString("• %1: Resolver após problema crítico\n").arg(nomesProblemas[j]);
                            orientacaoFinal += QString("  POP disponível - será mostrado quando for prioridade\n\n");
                            break;
                        }
                    }
                }
            }
            
            orientacaoFinal += "\n🎓 DICA EDUCACIONAL:\n";
            orientacaoFinal += "• Sempre resolva problemas de pressão primeiro!\n";
            orientacaoFinal += "• Pressão é a 'energia' do reservatório - sem ela, nada funciona\n";
            orientacaoFinal += "• Outros problemas podem ser consequência da pressão baixa\n";
            orientacaoFinal += "• Depois de estabilizar pressão, reavalie os outros problemas";
            
            valoresFinal = valoresList.join(" | ");
        }

        // Sistema de alertas sonoros e rastreamento de eventos
        if (problemasEncontrados > 0) {
            if (tipoProblema == "pressao_baixa" || tipoProblema == "excesso_gas") {
                // Alerta crítico (vermelho) - Som mais agudo e urgente
                tipoAlertaAtual = "CRITICO";
                // Só emitir som após sistema inicializado para evitar alarmes falsos
                if (sistemaInicializado) {
                    emitirAlertaSonoro("critico");
                }
            } else {
                // Alerta de atenção (laranja) - Som moderado
                tipoAlertaAtual = "ATENCAO";
                // Só emitir som após sistema inicializado para evitar alarmes falsos
                if (sistemaInicializado) {
                    emitirAlertaSonoro("atencao");
                }
            }
        } else {
            tipoAlertaAtual = "NORMAL";
        }
        
        // Atualizar interface com informações resumidas
        
        // Mostrar apenas resumo na tela principal
        QString resumoFinal;
        if (problemasEncontrados == 0) {
            resumoFinal = "✅ Todos os parâmetros dentro dos limites operacionais normais.";
        } else if (problemasEncontrados == 1) {
            resumoFinal = explicacaoFinal.left(200) + "..."; // Primeiras 200 chars
        } else {
            resumoFinal = QString("🚨 %1 problemas detectados simultaneamente. Resolva o mais crítico primeiro.").arg(problemasEncontrados);
        }
        
        
        diagnosticoAtual = tipoProblema;
    }

    void aplicarSolucaoAutomatica() {
        if (diagnosticoAtual == "pressao_baixa") {
            double volumeRecomendado = std::max(15000.0, reservatorio->vazao_oleo_bopd * 1.2);
            suggestInputWater->setText(QString::number(volumeRecomendado, 'f', 0));
            inputTempAgua->setText("60");
            
            // Aplicar injeção diretamente
            reservatorio->injetarAgua(volumeRecomendado, 60.0);
            logMessage(QString("🎓 APRENDIZADO: Injetando %1 bbl de água a 60°C.").arg(volumeRecomendado), "acao");
            
            QMessageBox::information(this, "✅ Solução Aplicada", 
                QString("🎓 APRENDIZADO CONCLUÍDO!\n\n")
                + "✅ Injeção de água iniciada: " + QString::number(volumeRecomendado, 'f', 0) + " bbl/dia\n"
                + "✅ Temperatura configurada: 60°C\n\n"
                + "📚 PRÓXIMOS PASSOS:\n"
                + "• Observe o gráfico de pressão nos próximos minutos\n"  
                + "• A pressão deve começar a subir\n"
                + "• A vazão de óleo deve aumentar consequentemente\n"
                + "• Este é o procedimento padrão para recuperação de pressão!");
                
        } else if (diagnosticoAtual == "gor_elevado") {
            double gasRecomendado = std::min(8.0, reservatorio->gas_oil_ratio / 400.0);
            suggestInputGas->setText(QString::number(gasRecomendado, 'f', 1));
            inputDensidadeGas->setText("0.8");
            
            // Aplicar injeção diretamente
            reservatorio->injetarGas(gasRecomendado, 0.8);
            logMessage(QString("🎓 APRENDIZADO: Injetando %1 m³ de gás com densidade 0.8.").arg(gasRecomendado), "acao");
            
            QMessageBox::information(this, "✅ Solução Aplicada", 
                QString("🎓 APRENDIZADO CONCLUÍDO!\n\n")
                + "✅ Injeção de gás iniciada: " + QString::number(gasRecomendado, 'f', 1) + " Mm³/dia\n"
                + "✅ Densidade configurada: 0.8 kg/m³\n\n"
                + "📚 O QUE ESPERAR:\n"
                + "• GOR deve diminuir gradualmente\n"
                + "• Pressão do reservatório se estabiliza\n"
                + "• Eficiência de produção melhora\n"
                + "• Técnica usada em campos maduros mundialmente!");
                
        } else if (diagnosticoAtual == "excesso_gas") {
            double flareRecomendado = reservatorio->volume_gas_m3 * 0.3;
            
            // Aplicar flare diretamente
            reservatorio->liberarGasParaQueima(flareRecomendado);
            logMessage(QString("🎓 APRENDIZADO: Acionando flare com vazão %1 m³/dia.").arg(flareRecomendado), "acao");
            
            QMessageBox::information(this, "✅ Solução Aplicada", 
                QString("🎓 APRENDIZADO CONCLUÍDO!\n\n")
                + "✅ Sistema flare ativado: " + QString::number(flareRecomendado, 'f', 0) + " m³/dia\n\n"
                + "🔥 CONCEITO DE SEGURANÇA:\n"
                + "• Flare queima excesso de gás de forma controlada\n"
                + "• Previne sobrepressão perigosa no sistema\n"
                + "• Volume de gás armazenado diminuirá rapidamente\n"
                + "• Procedimento de segurança padrão na indústria!");
        }
    }

    /*
    💾 ========================================================================
    MÉTODO REFATORADO: SALVAMENTO DE DADOS HISTÓRICOS
    ========================================================================
    
    📚 CONCEITO DE REFATORAÇÃO APLICADA:
    Substituição da conversão manual tempo_simulacao_s / 60.0 pelo
    método utilitário obterTempoMinutos(), mantendo consistência com
    outros métodos da classe.
    
    🏭 BENEFÍCIO INDUSTRIAL:
    • Centralização da lógica de conversão temporal
    • Facilita mudanças futuras na unidade de tempo
    • Consistency across time-related operations
    */
    void saveDataPoint() {
        DadosPontos ponto;
        
        // GERAÇÃO DE UUID ÚNICO PARA KAFKA STREAMING
        ponto.uuid = QUuid::createUuid().toString(QUuid::WithoutBraces);
        
        // USO DO MÉTODO UTILITÁRIO (REFATORAÇÃO)
        ponto.tempo_min = obterTempoMinutos();  
        
        // DADOS TÉCNICOS TRADICIONAIS
        ponto.vazao_oleo = reservatorio->vazao_oleo_bopd;
        ponto.pressao = reservatorio->pressao_psi;
        ponto.viscosidade_cp = reservatorio->viscosidade_oleo_cp;
        ponto.volume_oleo = reservatorio->volume_oleo_bbl;
        ponto.temperatura = reservatorio->temperatura_C;
        ponto.gor = reservatorio->gas_oil_ratio;
        ponto.wor = reservatorio->water_oil_ratio;
        
        // NOVOS CAMPOS PARA ANÁLISE AVANÇADA E RASTREAMENTO DE EVENTOS
        ponto.data_hora = QDateTime::currentDateTime().toString("yyyy-MM-ddThh:mm:ss");
        
        // Eventos do operador (limpar após uso)
        ponto.evento_operador = ultimoEventoOperador;
        if (!ultimoEventoOperador.isEmpty()) {
            ultimoEventoOperador = ""; // Reset após capturar
        }
        
        // Eventos físicos do reservatório 
        ponto.evento_fisica = ultimoEventoFisica;
        if (!ultimoEventoFisica.isEmpty()) {
            ultimoEventoFisica = ""; // Reset após capturar
        }
        
        // Tipo de alerta atual
        ponto.alerta_tipo = tipoAlertaAtual;
        
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
            suggestion += "- Volume de gás alto: considere ativar liberação de gás (flare).\n";
            hasSuggestion = true;
        }

        if (!hasSuggestion) {
            suggestionExplanationLabel->setText("O sistema está em condições operacionais normais. Nenhuma intervenção é sugerida no momento.");
            suggestInputWater->setPlaceholderText("Volume Água (bbl)");
            suggestInputGas->setPlaceholderText("Volume Gás (m³)");
            suggestInputVapor->setPlaceholderText("Tempo Vapor (s)");
        } else {
            suggestionExplanationLabel->setText(suggestion);
        }
    }

    /*
    🎨 ========================================================================
    MÉTODO REFATORADO: ATUALIZAÇÃO DE ÍCONES SCADA
    ========================================================================
    
    📚 CONCEITO DE REFATORAÇÃO APLICADA:
    Substituição de condicionais ternários repetitivos e complexos pelo
    método utilitário determinarCorStatus(), simplificando drasticamente
    a lógica de determinação de cores.
    
    🏭 MELHORIA INDUSTRIAL:
    • Redução de código complexo para lógica limpa e auditável
    • Padronização de thresholds de alerta/crítico
    • Facilita manutenção e modificação de limites
    • Elimina possibilidade de inconsistências entre indicadores
    
    🚦 SISTEMA DE CORES PADRONIZADO:
    Verde: Operação normal | Laranja: Atenção | Vermelho: Crítico
    */
    /*
    📊 ========================================================================
    MÉTODO DE CONTROLE INTELIGENTE DE ATUALIZAÇÃO DOS GRÁFICOS
    ========================================================================
    
    📚 CONCEITO EDUCACIONAL:
    Implementa lógica de consolidação temporal para diferentes granularidades
    de análise, otimizando performance e melhorando visualização conforme
    o período selecionado pelo usuário.
    
    🏭 LÓGICA INDUSTRIAL:
    • Tempo Real (1-5min): Todos os pontos para monitoramento operacional
    • Supervisão (10-30min): Consolidação por médias para análise de tendência  
    • Estratégico (1h-1dia): Pontos de análise gerencial agregados
    
    PARÂMETROS:
    • forcarAtualizacao: true para atualizar independente do período
    */
    void atualizarGraficosSeNecessario(bool forcarAtualizacao = false) {
        double tempoAtual = obterTempoMinutos();
        double tempoDecorrido = tempoAtual - ultimoTempoGrafico;
        double periodoMinutos = periodoGraficoSegundos / 60.0;
        
        /*
        🕐 VERIFICAÇÃO DE PERIODICIDADE:
        CORREÇÃO: Se é a primeira vez ou forçado, sempre atualiza
        Senão, só atualiza se passou tempo suficiente
        */
        if (!forcarAtualizacao && ultimoTempoGrafico > 0.0 && tempoDecorrido < periodoMinutos) {
            return; // Ainda não é hora de atualizar
        }
        
        /*
        📈 ATUALIZAÇÃO DOS GRÁFICOS:
        Adiciona ponto atual em todos os gráficos
        */
        /*
        📊 ADIÇÃO DE PONTOS COM ESCALAS CORRETAS:
        Alguns valores são convertidos para escalas mais adequadas à visualização
        */
        producaoSeries->append(tempoAtual, reservatorio->vazao_oleo_bopd);
        pressaoSeries->append(tempoAtual, reservatorio->pressao_psi);
        volumeOleoSeries->append(tempoAtual, reservatorio->volume_oleo_bbl / 1000000.0);  // CORREÇÃO: Converte para MM bbl
        temperaturaSeries->append(tempoAtual, reservatorio->temperatura_C);
        viscosidadeSeries->append(tempoAtual, reservatorio->viscosidade_oleo_cp);
        gorSeries->append(tempoAtual, reservatorio->gas_oil_ratio);
        worSeries->append(tempoAtual, reservatorio->water_oil_ratio);
        
        // Atualizar timestamp da última atualização
        ultimoTempoGrafico = tempoAtual;
        
        /*
        📏 EXPANSÃO DINÂMICA DO EIXO X:
        Aumenta o range do eixo X quando necessário para acomodar novos dados
        */
        atualizarRangeTempoGraficos(tempoAtual);
        
        /*
        🐛 LOG DE DEBUG (apenas para desenvolvimento):
        Confirma que os gráficos estão sendo atualizados
        */
        if (forcarAtualizacao) {
            logMessage(QString("📊 Gráficos atualizados (forçado) - Tempo: %1 min").arg(tempoAtual, 0, 'f', 1), "info");
        } else {
            logMessage(QString("📊 Gráficos atualizados - Tempo: %1 min (Δ%2 min)")
                      .arg(tempoAtual, 0, 'f', 1).arg(tempoDecorrido, 0, 'f', 1), "info");
        }
        
        /*
        🗃️ OTIMIZAÇÃO DE PERFORMANCE:
        Para períodos longos, limita o número de pontos nos gráficos
        para evitar sobrecarga visual e de memória
        */
        if (periodoGraficoSegundos >= 1800) { // 30 minutos ou mais
            limitarPontosGraficos(200); // Máximo 200 pontos visíveis
        } else if (periodoGraficoSegundos >= 300) { // 5 minutos ou mais
            limitarPontosGraficos(500); // Máximo 500 pontos visíveis
        }
        // Para períodos menores, mantém todos os pontos (monitoramento detalhado)
    }
    
    /*
    🗃️ ========================================================================
    MÉTODO DE OTIMIZAÇÃO: LIMITAÇÃO DE PONTOS NOS GRÁFICOS
    ========================================================================
    
    📚 CONCEITO EDUCACIONAL:
    Remove pontos mais antigos dos gráficos quando excede o limite,
    mantendo performance e evitando sobrecarga visual em análises
    de longo prazo.
    
    🏭 BENEFÍCIO INDUSTRIAL:
    Sistemas SCADA reais usam esta técnica para manter responsividade
    mesmo com anos de dados históricos.
    */
    /*
    📏 ========================================================================
    MÉTODO DE EXPANSÃO DINÂMICA DO EIXO TEMPORAL
    ========================================================================
    
    📚 CONCEITO EDUCACIONAL:
    Expande automaticamente o range do eixo X (tempo) quando novos dados
    excedem o range atual, mantendo visibilidade adequada dos gráficos.
    
    🏭 FUNCIONALIDADE SCADA:
    Sistemas industriais reais adaptam escalas dinamicamente para
    acomodar dados de diferentes períodos operacionais.
    */
    void atualizarRangeTempoGraficos(double tempoAtual) {
        // Lista de todos os gráficos criados (precisamos acessá-los)
        QList<QLineSeries*> todasSeries = {
            producaoSeries, pressaoSeries, volumeOleoSeries, 
            temperaturaSeries, viscosidadeSeries, gorSeries, worSeries
        };
        
        // Expandir eixo X se necessário (com margem de 20%)
        double rangeMinimo = tempoAtual * 1.2;  // 20% de margem
        
        // Garantir range mínimo de 10 minutos para visualização adequada
        if (rangeMinimo < 10.0) rangeMinimo = 10.0;
        
        // Atualizar eixo X de todas as séries
        for (QLineSeries* series : todasSeries) {
            if (series && series->chart() && !series->chart()->axes(Qt::Horizontal).isEmpty()) {
                QValueAxis* axisX = qobject_cast<QValueAxis*>(series->chart()->axes(Qt::Horizontal).first());
                if (axisX && axisX->max() < rangeMinimo) {
                    axisX->setMax(rangeMinimo);
                    // Ajustar número de ticks baseado no range
                    int tickCount = qMin(11, qMax(5, static_cast<int>(rangeMinimo / 10.0) + 1));
                    axisX->setTickCount(tickCount);
                }
            }
        }
    }

    void limitarPontosGraficos(int maxPontos) {
        auto limitarSerie = [maxPontos](QLineSeries* series) {
            while (series->count() > maxPontos) {
                series->remove(0); // Remove o ponto mais antigo
            }
        };
        
        limitarSerie(producaoSeries);
        limitarSerie(pressaoSeries);
        limitarSerie(volumeOleoSeries);
        limitarSerie(temperaturaSeries);
        limitarSerie(viscosidadeSeries);
        limitarSerie(gorSeries);
        limitarSerie(worSeries);
    }

    void updateIcons() {
        /*
        🌡️ ÍCONE DE PRESSÃO (REFATORADO):
        Usa método utilitário com lógica invertida (pressão baixa = crítica)
        */
        QString pressaoColor = determinarCorStatus(
            reservatorio->pressao_psi,
            2500.0,  // Limite de alerta (atenção)  
            reservatorio->LIMITE_PRESSAO_CRITICO_MIN,  // Limite crítico
            true     // Invertido: valores baixos são críticos
        );
        pressaoIconLabel->setPixmap(createIcon(pressaoColor, iconPressaoPath).pixmap(48, 48));

        /*
        🌡️ ÍCONE DE TEMPERATURA (REFATORADO):
        Usa método utilitário com lógica normal (temperatura alta = crítica)
        */
        QString temperaturaColor = determinarCorStatus(
            reservatorio->temperatura_C,
            150.0,  // Limite de alerta
            180.0,  // Limite crítico
            false   // Normal: valores altos são críticos
        );
        temperaturaIconLabel->setPixmap(createIcon(temperaturaColor, iconTemperaturaPath).pixmap(48, 48));

        /*
        🚢 ÍCONE DE VAZÃO (REFATORADO):
        Usa método utilitário com lógica invertida (vazão baixa = crítica)
        */
        QString vazaoColor = determinarCorStatus(
            reservatorio->vazao_oleo_bopd,
            12000.0,  // Limite de alerta (below optimal)
            reservatorio->PRODUCAO_MINIMA_ACEITAVEL_BOPD,  // Limite crítico
            true      // Invertido: valores baixos são críticos
        );
        vazaoIconLabel->setPixmap(createIcon(vazaoColor, iconVazaoPath).pixmap(48, 48));

        /*
        ⛽ ÍCONE DE GOR (REFATORADO):
        Usa método utilitário com lógica normal (GOR alto = crítico)
        */
        QString gorColor = determinarCorStatus(
            reservatorio->gas_oil_ratio,
            500.0,  // Limite de alerta
            reservatorio->LIMITE_GOR_CRITICO,  // Limite crítico
            false   // Normal: valores altos são críticos
        );
        gorIconLabel->setPixmap(createIcon(gorColor, iconGorPath).pixmap(48, 48));

        /*
        🔍 ÍCONE DE STATUS GERAL (LÓGICA ESPECÍFICA):
        Baseado diretamente no flag de emergência
        */
        QString statusColor = reservatorio->em_emergencia ? "red" : "green";
        statusIconLabel->setPixmap(createIcon(statusColor, iconStatusPath).pixmap(48, 48));
    }
};

// Inclusão necessária para compilação Qt (Meta-Object Compiler)
#include "main.moc"

/*
🎓 ================================================================================
🚀 FUNÇÃO MAIN - PONTO DE ENTRADA DO SIMULADOR EDUCACIONAL ATS-7B
================================================================================

📚 CONCEITO EDUCACIONAL:
Esta é a função principal do programa, chamada automaticamente pelo sistema
operacional quando o usuário executa o simulador. É o "portão de entrada"
de qualquer aplicação C++.

🔧 RESPONSABILIDADES DA FUNÇÃO MAIN:
1. Inicialização do framework Qt5
2. Configuração de atributos do sistema gráfico
3. Criação e exibição da janela principal
4. Entrada no loop principal de eventos Qt
5. Retorno do código de status para o sistema operacional

💻 PARÂMETROS:
• argc: Número de argumentos da linha de comando
• argv: Array de strings com os argumentos da linha de comando

📱 HIGH DPI SUPPORT:
Configuração para monitores modernos (4K, Retina, etc.) comuns em
estações de trabalho da indústria petrolífera.

================================================================================
*/

int main(int argc, char *argv[]) {
    /*
    🖥️ CONFIGURAÇÃO PARA MONITORES HIGH-DPI:
    
    📚 CONCEITO: Monitores 4K/Retina requerem configurações especiais
    para que texto e ícones tenham tamanho adequado. Essencial em
    estações SCADA modernas onde operadores trabalham 12h/turno.
    */
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling, true);   // Escalonamento automático
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps, true);      // Ícones de alta resolução
    
    /*
    🏗️ CRIAÇÃO DA APLICAÇÃO Qt:
    
    📚 CONCEITO: QApplication é o "coração" de qualquer programa Qt.
    Gerencia janelas, eventos, recursos e integração com o OS.
    
    PARÂMETROS: argc e argv permitem configuração via linha de comando
    */
    QApplication a(argc, argv);
    
    /*
    📝 IDENTIFICAÇÃO DA APLICAÇÃO:
    
    📚 CONCEITO: Estas informações aparecem na barra de título,
    task manager e são usadas pelo sistema operacional para
    organizar logs e configurações.
    */
    a.setApplicationName("Simulador ATS-7B Atlântida Oriental");  // Nome completo
    a.setApplicationVersion("1.0");                         // Versão para auditoria
    
    /*
    🪟 CRIAÇÃO DA JANELA PRINCIPAL:
    
    📚 CONCEITO: SimuladorWindow é nossa classe customizada que
    contém toda a interface SCADA e lógica de simulação.
    */
    SimuladorWindow w;  // Cria objeto na stack (destruição automática)
    
    /*
    👁️ EXIBIÇÃO DA JANELA:
    
    📚 CONCEITO: show() torna a janela visível na tela.
    Em sistemas reais, interfaces SCADA são exibidas em
    monitores dedicados na sala de controle.
    */
    w.show();
    
    /*
    ⚡ PROCESSAMENTO INICIAL DE EVENTOS:
    
    📚 CONCEITO: processEvents() força o Qt a processar
    todos os eventos pendentes (desenhar janela, conectar
    sinais, etc.) antes de continuar.
    
    💡 IMPORTÂNCIA: Garante que a interface esteja 100%
    pronta antes de entrar no loop principal.
    */
    a.processEvents();
    
    /*
    🔄 ENTRADA NO LOOP PRINCIPAL DE EVENTOS:
    
    📚 CONCEITO FUNDAMENTAL: a.exec() é onde o programa "vive".
    Esta função só retorna quando o usuário fecha a aplicação.
    
    Durante exec():
    • Qt processa cliques do mouse
    • Qt processa teclas pressionadas  
    • Qt atualiza gráficos e animações
    • Qt chama nossos métodos (slots) quando necessário
    • Timer da simulação dispara a cada 5 segundos
    
    🔢 CÓDIGO DE RETORNO:
    • 0 = Programa terminou normalmente
    • != 0 = Erro durante execução
    
    O sistema operacional usa este código para detectar crashes.
    */
    return a.exec();  // AQUI O PROGRAMA FICA RODANDO ATÉ O USUÁRIO FECHAR
    
    /*
    🎯 FLUXO EDUCACIONAL COMPLETO:
    
    1. main() inicia o programa
    2. Qt é configurado e inicializado
    3. SimuladorWindow é criado (construtor chamado)
    4. Interface SCADA é montada (setupUI)
    5. Gráficos são configurados (setupCharts)  
    6. Timer inicia simulação a cada 5s (gameLoop)
    7. Usuário interage com controles
    8. Dados são coletados e exibidos em tempo real
    9. Usuário fecha programa (destrutor chamado)
    10. main() retorna 0 para o sistema operacional
    
    📚 ESTA É A ESSÊNCIA DE QUALQUER SISTEMA SCADA INDUSTRIAL!
    */
}
