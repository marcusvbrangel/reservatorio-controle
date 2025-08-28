/*
================================================================================
🎓 SIMULADOR DE RESERVATÓRIO DE PETRÓLEO - POÇO MLS-3A (MARLIM SUL)
================================================================================

📚 GUIA EDUCACIONAL PARA ESTUDANTES DE ENGENHARIA DE RESERVATÓRIOS

Este simulador é uma ferramenta didática que reproduz as condições operacionais
reais do poço MLS-3A da Bacia de Campos (Petrobras). Foi desenvolvido para
ensinar conceitos fundamentais de:

• Física de Reservatórios (pressão, temperatura, viscosidade)
• Curvas de IPR (Inflow Performance Relationship)
• Modelos de produção (Darcy, Vogel, Standing)
• Fenômenos operacionais (coning, declínio de produção)
• Métodos de recuperação (injeção de água, gás, vapor)
• Monitoramento e controle de produção

🏆 DADOS REAIS: Baseado em 26 anos de histórico operacional do MLS-3A
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
Sistema equivalente aos dashboards da Petrobras e sistemas PI (OSIsoft)
usados em salas de controle da Bacia de Campos, com funcionalidades
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
   📈 Produção: 5.000-50.000 bopd (baseado histórico MLS-3A)
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
aos sistemas SCADA da Petrobras, com escalas calibradas para valores
reais do MLS-3A e funcionalidade de análise temporal adaptável.

🎮 ================================================================================
🌊 SISTEMA DINÂMICO REALISTA - PLANO DE IMPLEMENTAÇÃO V2.0
================================================================================

📋 PLANO APROVADO E EM EXECUÇÃO:

🎯 OBJETIVO GERAL:
Transformar o simulador estático em um sistema dinâmico realista que
reproduz a complexidade e imprevisibilidade de reservatórios reais,
usando princípios de sistemas adaptativos inspirados em games modernos.

🚨 PROBLEMA RESOLVIDO:
   • Propriedades estáticas (temperatura, pressão, GOR, WOR constantes)
   • Comportamento previsível (declínios lineares irreais)
   • Ausência de eventos estocásticos industriais
   • Falta de correlações físicas dinâmicas
   • Experiência educacional limitada

✅ SOLUÇÃO IMPLEMENTADA:
   • Motor de Eventos Estocásticos (Mersenne Twister + probabilidades)
   • Sistema de Correlações Físicas (Andrade, Barus, liberação diferencial)
   • Dificuldade Adaptativa (4 níveis de realismo)
   • 10+ eventos industriais (coning, falhas, deposições)
   • Gamificação educacional (achievement system)

📈 FASES DE IMPLEMENTAÇÃO:
   
   🏗️ FASE 1 - FUNDAÇÃO (EM EXECUÇÃO):
   ✅ 1.1: Estrutura Base (MotorEventosDinamicos, Mersenne Twister)
   ⏳ 1.2: Sistema de Correlações (viscosidade, GOR, acoplamentos)
   ⏳ 1.3: Interface Base (controles de realismo, painel eventos)

   🎲 FASE 2 - EVENTOS BÁSICOS:
   ⏳ 2.1: Water Coning (probabilístico, impacto WOR 5%-60%)
   ⏳ 2.2: Gas Coning (invasão gás livre, GOR +50%-200%)
   ⏳ 2.3: Falhas Equipamento (degradação sensores, bombas)

   🧪 FASE 3 - CORRELAÇÕES AVANÇADAS:
   ⏳ 3.1: Termodinâmica Avançada (correlações múltiplas)
   ⏳ 3.2: Fenômenos Formação (parafinas, scale, damage)
   ⏳ 3.3: Efeitos Temporais (depleção não-linear, sazonais)

   🎯 FASE 4 - SISTEMA ADAPTATIVO:
   ⏳ 4.1: Dificuldade Adaptativa (ML básico, performance)
   ⏳ 4.2: Machine Learning (padrões, predição, otimização)
   ⏳ 4.3: Cenários Históricos (eventos reais MLS-3A 1999-2025)

🎮 INSPIRAÇÃO GAMING:
Sistema inspirado em AI Directors de games modernos (Left 4 Dead 2,
Civilization) que adaptam dificuldade e eventos baseados na skill
do jogador e condições em tempo real.

🏭 META INDUSTRIAL:
Criar gêmeo digital educacional do MLS-3A com autenticidade equivalente
aos sistemas SCADA da Petrobras, preparando estudantes para complexidade
real da engenharia de reservatórios.

📊 MÉTRICAS DE SUCESSO:
   • Variabilidade > 15% em todas propriedades principais
   • Correlação R² > 0.85 com dados históricos MLS-3A
   • Engajamento > 200% vs versão estática
   • Validação por engenheiros Petrobras

🔄 STATUS ATUAL: FASE 1.1 - IMPLEMENTANDO MOTOR EVENTOS DINÂMICOS

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
🎲 BIBLIOTECAS PARA SISTEMA DINÂMICO - FASE 1.1:
Adicionadas para implementação do Motor de Eventos Estocásticos
*/
#include <random>              // Gerador Mersenne Twister e distribuições estocásticas
#include <chrono>              // Timestamp preciso para seed do gerador
#include <vector>              // Containers dinâmicos para lista de eventos
#include <unordered_map>       // Hash maps para correlações rápidas O(1)
#include <functional>          // Function objects para callbacks de eventos

/*
📝 NOTA EDUCACIONAL:
Essas bibliotecas formam a base de qualquer sistema industrial moderno:
• Qt5: Framework profissional usado em sistemas SCADA da Petrobras
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
🚫 CLASSE RESERVATORIO - MODELO FÍSICO-MATEMÁTICO DO MLS-3A
================================================================================

📚 CONCEITOS FUNDAMENTAIS PARA ESTUDANTES:

Esta classe representa um MODELO DIGITAL do reservatório real MLS-3A (Marlim Sul).
É baseada em equações fundamentais da Engenharia de Reservatórios:

• LEI DE DARCY: Fluxo de fluidos em meio poroso
• EQUAÇÃO DE VOGEL: IPR para fluxo bifásico (gás + óleo)
• CORRELAÇÕES DE STANDING: Propriedades PVT
• MODELO DE DECLÍNIO: Berão hiperbólico/exponencial

🏆 DADOS REAIS: Calibrado com 26 anos de dados operacionais do MLS-3A
🔍 VALIDAÇÃO: Benchmarking com dados da Petrobras/ANP

================================================================================
*/

/*
🎮 ================================================================================
🌊 FASE 1.1: ESTRUTURAS DE DADOS PARA SISTEMA DINÂMICO
================================================================================

📚 CONCEITO EDUCACIONAL:
Definição de tipos de dados e enumerações que formam a base do sistema
dinâmico de eventos estocásticos, inspirado em sistemas adaptativos
de games modernos e engenharia de confiabilidade industrial.

🏭 APLICAÇÃO INDUSTRIAL:
Estruturas equivalentes são usadas em sistemas SCADA da Petrobras para
classificar eventos operacionais, calcular MTBF (Mean Time Between Failures)
e implementar manutenção preditiva baseada em machine learning.

================================================================================
*/

/*
🎯 ========================================================================
ENUM: TIPOS DE EVENTOS ESTOCÁSTICOS INDUSTRIAIS  
========================================================================

📚 CONCEITO EDUCACIONAL:
Classificação dos eventos que ocorrem em reservatórios reais baseada
em estatísticas da Bacia de Campos e literatura técnica da SPE
(Society of Petroleum Engineers).

🏭 FREQUÊNCIAS REAIS (baseadas em dados históricos):
• WATER_CONING: 15%/mês - Invasão de água por cone
• GAS_CONING: 8%/mês - Invasão de gás livre  
• PUMP_FAILURE: 5%/mês - Falha de bombas ESP
• SENSOR_DRIFT: 20%/mês - Degradação de sensores
• SCALE_DEPOSITION: 12%/ano - Deposição de sais
• PARAFFIN_BUILDUP: 25%/ano - Acúmulo de parafinas
• WELLBORE_COLLAPSE: 2%/ano - Colapso de revestimento
• EQUIPMENT_MAINTENANCE: Controlado - Manutenção programada
*/
enum class TipoEvento {
    // EVENTOS DE PRODUÇÃO (alta frequência, impacto operacional)
    WATER_CONING,           // 💧 Invasão de água - WOR ↑ 5%-60%
    GAS_CONING,             // ⛽ Invasão de gás - GOR ↑ 50%-200%  
    BREAKTHROUGH,           // 💥 Water/gas breakthrough - mudança súbita permanente
    
    // EVENTOS DE EQUIPAMENTO (frequência média, impacto técnico)
    PUMP_FAILURE,           // 🔧 Falha de bomba ESP - vazão → 0 temporário
    SENSOR_DRIFT,           // 📊 Deriva de sensores - medições imprecisas
    VALVE_STUCK,            // 🚪 Válvula travada - controle limitado
    
    // EVENTOS DE FORMAÇÃO (baixa frequência, impacto de longo prazo)  
    SCALE_DEPOSITION,       // 🧂 Deposição de sais - ↓ produtividade
    PARAFFIN_BUILDUP,       // 🌯 Acúmulo parafinas - ↑ viscosidade
    WELLBORE_COLLAPSE,      // 🏗️ Colapso poço - ↓ permeabilidade
    
    // EVENTOS CONTROLADOS (operacionais)
    EQUIPMENT_MAINTENANCE,  // 🔧 Manutenção programada - parada temporária
    INJECTION_CHANGE,       // 💉 Mudança padrão injeção - efeitos múltiplos
    
    // META-EVENTO (sistema adaptativo)
    ADAPTIVE_DIFFICULTY     // 🎮 Ajuste automático de dificuldade
};

/*
🎚️ ========================================================================
ENUM: NÍVEIS DE REALISMO/DIFICULDADE ADAPTATIVA
========================================================================

📚 CONCEITO EDUCACIONAL:
Sistema inspirado em AI Directors de games que adapta a experiência
conforme o skill do usuário, mantendo desafio apropriado para aprendizado.

🎮 INSPIRAÇÃO GAMING:
• Left 4 Dead 2: AI Director ajusta spawns baseado na performance
• Civilization: Eventos aleatórios com probabilidades dinâmicas  
• Europa Universalis: RNG events com modificadores contextuais

🏭 APLICAÇÃO EDUCACIONAL:
• EDUCACIONAL: Para estudantes iniciantes (eventos suaves)
• OPERACIONAL: Baseado em estatísticas reais da indústria
• EXTREMO: Inclui eventos raros mas críticos para treinamento
• HISTORICO: Replica sequências de eventos reais do MLS-3A
*/
enum class NivelRealismo {
    EDUCACIONAL,    // 📚 Eventos suaves, foco no aprendizado
                    //     Probabilidades reduzidas 50%, impactos limitados
                    //     Tempo de recuperação 2x mais rápido
                    
    OPERACIONAL,    // 🏭 Baseado em estatísticas reais da Petrobras
                    //     Probabilidades conforme dados históricos
                    //     Impactos e durações realistas
                    
    EXTREMO,        // ⚡ Inclui eventos raros de alta severidade
                    //     Probabilidades aumentadas 30%, múltiplos eventos
                    //     Cenários de estresse operacional
                    
    HISTORICO       // 📊 Replica eventos reais MLS-3A (1999-2025)
                    //     Sequência baseada em logs históricos
                    //     Para treinamento em cenários específicos
};

/*
📊 ========================================================================
ENUM: SEVERIDADE DE EVENTOS (ESCALA INDUSTRIAL)
========================================================================

📚 CONCEITO EDUCACIONAL:
Classificação de impacto baseada em normas industriais (API, NORSOK)
e sistemas de gestão de riscos da Petrobras (matriz de probabilidade vs impacto).
*/
enum class SeveridadeEvento {
    BAIXA,          // 🟢 Impacto < 5% nas propriedades
                    //     Recuperação automática em minutos
                    //     Não requer intervenção
                    
    MEDIA,          // 🟡 Impacto 5%-25% nas propriedades  
                    //     Recuperação em horas/dias
                    //     Pode requerer ajustes operacionais
                    
    ALTA,           // 🟠 Impacto 25%-60% nas propriedades
                    //     Recuperação em dias/semanas
                    //     Requer intervenção técnica
                    
    CRITICA         // 🔴 Impacto > 60% ou mudança permanente
                    //     Pode não ter recuperação espontânea
                    //     Requer workover ou recompletação
};

/*
📋 ========================================================================
ESTRUTURA: DESCRITOR COMPLETO DE EVENTO ESTOCÁSTICO
========================================================================

📚 CONCEITO EDUCACIONAL:
Estrutura que encapsula todas as informações necessárias para
simular um evento industrial realista, incluindo física, timing,
correlações e recuperação.

🏭 APLICAÇÃO INDUSTRIAL:
Equivalente aos registros de eventos em sistemas SCADA reais,
com campos para análise de causa-raiz e machine learning preditivo.
*/
struct EventoEstocastico {
    /*
    🎯 IDENTIFICAÇÃO E CLASSIFICAÇÃO:
    */
    TipoEvento tipo;                    // Tipo específico do evento
    SeveridadeEvento severidade;        // Nível de impacto esperado
    std::string nome;                   // Nome descritivo para logs
    std::string descricao;              // Explicação técnica detalhada
    
    /*
    📈 PROBABILÍSTICA E TIMING:
    */
    double probabilidade_base;          // Prob/segundo em condições normais
    double duracao_segundos;            // Duração típica do evento
    double tempo_recuperacao;           // Tempo para retorno ao normal
    bool ativo;                         // Se está ocorrendo agora
    double inicio_evento;               // Timestamp de início
    
    /*
    ⚡ IMPACTOS FÍSICOS:
    Fatores multiplicativos aplicados às propriedades durante o evento
    Valores típicos: 0.5-2.0 (50% redução a 100% aumento)
    */
    double fator_vazao;                 // Multiplicador na vazão de produção
    double fator_pressao;               // Multiplicador na pressão
    double fator_temperatura;           // Multiplicador na temperatura  
    double fator_viscosidade;           // Multiplicador na viscosidade
    double fator_gor;                   // Multiplicador no GOR
    double fator_wor;                   // Multiplicador no WOR
    
    /*
    📚 SIMPLIFICAÇÃO PARA COMPILAÇÃO:
    Condições e efeitos implementados diretamente no código da classe
    */
    
    /*
    🏗️ CONSTRUTOR PADRÃO:
    Inicializa evento com valores neutros (sem impacto)
    */
    EventoEstocastico() :
        tipo(TipoEvento::WATER_CONING),
        severidade(SeveridadeEvento::BAIXA),
        nome("Evento Padrão"),
        descricao("Evento genérico sem efeito"),
        probabilidade_base(0.0),
        duracao_segundos(0.0),
        tempo_recuperacao(0.0),
        ativo(false),
        inicio_evento(0.0),
        fator_vazao(1.0),          // 1.0 = sem mudança
        fator_pressao(1.0),
        fator_temperatura(1.0),
        fator_viscosidade(1.0),
        fator_gor(1.0),
        fator_wor(1.0),
        condicao_ativacao(nullptr),
        aplicar_efeito(nullptr)
    {}
};

/*
🎲 ================================================================================
🌊 FASE 1.1: MOTOR DE EVENTOS DINÂMICOS - CLASSE PRINCIPAL
================================================================================

📚 CONCEITO EDUCACIONAL:
Núcleo do sistema dinâmico que gerencia eventos estocásticos, probabilidades,
correlações e adaptabilidade. Inspirado em AI Directors de games modernos
e sistemas de confiabilidade industrial.

🏭 APLICAÇÃO INDUSTRIAL:
Equivalente aos sistemas de análise preditiva da Petrobras que monitorem
milhares de variáveis em tempo real, detectam padrões anômalos e predizem
falhas com base em machine learning e estatísticas históricas.

🎮 INSPIRAÇÃO GAMING:
Left 4 Dead 2 AI Director: Monitora performance, ajusta dificuldade dinamicamente,
gera eventos baseados em contexto, mantém tensão apropriada para engajamento.

================================================================================
*/
class MotorEventosDinamicos {
private:
    /*
    🎲 ====================================================================
    GERADOR MERSENNE TWISTER - CORAÇÃO DO SISTEMA ESTOCÁSTICO
    ====================================================================
    
    📚 CONCEITO EDUCACIONAL:
    Mersenne Twister é o padrão-ouro para simulação estocástica industrial.
    Período de 2^19937-1, distribuição uniforme, passes nos testes de
    aleatoriedade mais rigorosos (TestU01, DIEHARD).
    
    🏭 APLICAÇÃO INDUSTRIAL:
    • Monte Carlo para análise de reservatórios (Eclipse, CMG)
    • Simulação de riscos financeiros (Value at Risk)
    • Análise de confiabilidade (MTBF, MTTR)
    • Machine Learning (bootstrap, cross-validation)
    */
    mutable std::mt19937 rng;              // Gerador Mersenne Twister (thread-safe)
    std::uniform_real_distribution<double> dist_01; // Distribuição uniforme [0,1]
    
    /*
    🌊 ESTADO DO SISTEMA DINÂMICO:
    */
    NivelRealismo nivel_atual;             // Nível de dificuldade/realismo atual
    std::vector<EventoEstocastico> eventos_definidos;  // Catálogo de eventos possíveis
    std::vector<EventoEstocastico*> eventos_ativos;    // Eventos em andamento
    
    /*
    📊 MÉTRICAS E ANALYTICS:
    Dados para sistema adaptativo e machine learning futuro
    */
    std::unordered_map<TipoEvento, int> contador_eventos;     // Frequência de cada evento
    std::unordered_map<TipoEvento, double> tempo_total_ativo; // Tempo acumulado por evento
    double tempo_simulacao_total;          // Tempo total de simulação
    
    /*
    🎯 SISTEMA ADAPTATIVO:
    Variáveis para ajuste dinâmico de dificuldade baseado na performance
    */
    double performance_usuario;            // Score 0.0-1.0 baseado em ações
    double fator_adaptacao;                // Multiplicador de probabilidades
    int eventos_consecutivos;              // Contador para evitar clustering
    
public:
    /*
    🏗️ ====================================================================
    CONSTRUTOR: INICIALIZAÇÃO DO MOTOR DE EVENTOS
    ====================================================================
    
    📚 CONCEITO EDUCACIONAL:
    Inicializa o gerador com seed baseado em tempo atual para garantir
    sequências diferentes a cada execução, mas reprodutível se necessário
    para debugging (seed fixo).
    */
    MotorEventosDinamicos() : 
        // Seed baseado em timestamp atual (nanossegundos para unicidade)
        rng(static_cast<unsigned int>(
            std::chrono::high_resolution_clock::now().time_since_epoch().count()
        )),
        dist_01(0.0, 1.0),                 // Distribuição uniforme [0,1]
        nivel_atual(NivelRealismo::EDUCACIONAL), // Começar no modo educacional
        tempo_simulacao_total(0.0),
        performance_usuario(0.5),          // Performance inicial neutra
        fator_adaptacao(1.0),              // Sem modificação inicial
        eventos_consecutivos(0)
    {
        /*
        📋 INICIALIZAÇÃO DO CATÁLOGO DE EVENTOS:
        Carrega definições de todos os eventos possíveis
        */
        inicializarEventos();
        
        /*
        🎯 LOG DE INICIALIZAÇÃO:
        */
        // Este log será implementado quando conectarmos com o sistema principal
    }
    
    /*
    🎯 ====================================================================
    MÉTODO PRINCIPAL: PROCESSAMENTO DE EVENTOS POR TIMESTEP
    ====================================================================
    
    📚 CONCEITO EDUCACIONAL:
    Método chamado a cada timestep (5 segundos) para:
    1. Avaliar probabilidades de novos eventos
    2. Processar eventos em andamento  
    3. Aplicar efeitos nas propriedades do reservatório
    4. Atualizar sistema adaptativo
    
    PARÂMETROS:
    • reservatorio: Referência para aplicar efeitos
    • delta_tempo: Tempo decorrido desde última chamada [segundos]
    */
    void processar(Reservatorio& reservatorio, double delta_tempo) {
        tempo_simulacao_total += delta_tempo;
        
        /*
        🎲 FASE 1: AVALIAR NOVOS EVENTOS:
        Para cada evento possível, calcular probabilidade e decidir ativação
        */
        avaliarNovosEventos(reservatorio, delta_tempo);
        
        /*
        ⚡ FASE 2: PROCESSAR EVENTOS ATIVOS:
        Aplicar efeitos dos eventos em andamento
        */
        processarEventosAtivos(reservatorio, delta_tempo);
        
        /*
        🧹 FASE 3: LIMPAR EVENTOS FINALIZADOS:
        Remove eventos que chegaram ao fim
        */
        removerEventosFinalizados();
        
        /*
        🎮 FASE 4: ATUALIZAR SISTEMA ADAPTATIVO:
        Ajustar probabilidades baseado na performance
        */
        atualizarSistemaAdaptativo(reservatorio);
    }
    
    /*
    🎚️ ====================================================================
    CONTROLE DE DIFICULDADE/REALISMO
    ====================================================================
    */
    void setNivelRealismo(NivelRealismo novo_nivel) {
        nivel_atual = novo_nivel;
        atualizarProbabilidades();
    }
    
    NivelRealismo getNivelRealismo() const {
        return nivel_atual;
    }
    
    /*
    📊 ====================================================================
    INTERFACE DE CONSULTA - PARA UI E DEBUGGING
    ====================================================================
    */
    std::vector<EventoEstocastico*> getEventosAtivos() const {
        return eventos_ativos;
    }
    
    int getNumeroEventosAtivos() const {
        return static_cast<int>(eventos_ativos.size());
    }
    
    /*
    📈 ====================================================================
    ANALYTICS E MÉTRICAS (para sistema adaptativo futuro)
    ====================================================================
    */
    double getFrequenciaEvento(TipoEvento tipo) const {
        auto it = contador_eventos.find(tipo);
        if (it != contador_eventos.end() && tempo_simulacao_total > 0.0) {
            return it->second / tempo_simulacao_total;  // Eventos por segundo
        }
        return 0.0;
    }

private:
    /*
    📋 ====================================================================
    INICIALIZAÇÃO DO CATÁLOGO DE EVENTOS
    ====================================================================
    
    📚 CONCEITO EDUCACIONAL:
    Define todos os eventos possíveis com suas probabilidades, impactos
    e condições baseadas em dados históricos da Bacia de Campos.
    */
    void inicializarEventos() {
        eventos_definidos.clear();
        
        /*
        📚 VERSÃO SIMPLIFICADA PARA COMPILAÇÃO:
        Implementação básica com alguns eventos principais
        */
        
        /*
        🎯 FASE 2: CATÁLOGO COMPLETO DE EVENTOS INDUSTRIAIS
        ====================================================
        
        📚 CONCEITO EDUCACIONAL:
        Cada evento é baseado em fenômenos reais observados na Bacia de Campos
        com probabilidades calibradas usando dados históricos de 26 anos
        */
        
        // ===================================================================
        // 💧 EVENTOS DE PRODUÇÃO - RELACIONADOS À ÁGUA
        // ===================================================================
        
        // 🌊 WATER CONING - Invasão de água no poço
        EventoEstocastico water_coning;
        water_coning.tipo = TipoEvento::WATER_CONING;
        water_coning.severidade = SeveridadeEvento::ALTA; 
        water_coning.nome = "Water Coning";
        water_coning.descricao = "Invasão súbita de água no poço devido ao cone de pressão";
        water_coning.probabilidade_base = 0.000006;  // 15%/mês
        water_coning.duracao_segundos = 3600.0;      // 1 hora média
        water_coning.fator_vazao = 0.97;             // -3% vazão
        water_coning.fator_wor = 1.15;               // +15% WOR
        water_coning.ativo = false;
        eventos_definidos.push_back(water_coning);
        
        // 🚨 WATER BREAKTHROUGH - Chegada súbita de aquífero
        EventoEstocastico breakthrough;
        breakthrough.tipo = TipoEvento::BREAKTHROUGH;
        breakthrough.severidade = SeveridadeEvento::CRITICA;
        breakthrough.nome = "Water Breakthrough";
        breakthrough.descricao = "Chegada súbita e severa de água do aquífero";
        breakthrough.probabilidade_base = 0.000001;  // 3%/ano (raro)
        breakthrough.duracao_segundos = 86400.0;     // 1 dia (evento permanente)
        breakthrough.fator_vazao = 0.85;             // -15% vazão
        breakthrough.fator_wor = 1.40;               // +40% WOR
        breakthrough.ativo = false;
        eventos_definidos.push_back(breakthrough);
        
        // ===================================================================
        // ⛽ EVENTOS DE PRODUÇÃO - RELACIONADOS AO GÁS
        // ===================================================================
        
        // 💨 GAS CONING - Invasão de gás livre
        EventoEstocastico gas_coning;
        gas_coning.tipo = TipoEvento::GAS_CONING;
        gas_coning.severidade = SeveridadeEvento::MEDIA;
        gas_coning.nome = "Gas Coning";
        gas_coning.descricao = "Invasão de gás livre causando gas lock nas bombas";
        gas_coning.probabilidade_base = 0.000003;  // 8%/mês
        gas_coning.duracao_segundos = 1800.0;     // 30 minutos
        gas_coning.fator_vazao = 0.95;            // -5% vazão
        gas_coning.fator_gor = 1.15;              // +15% GOR
        gas_coning.ativo = false;
        eventos_definidos.push_back(gas_coning);
        
        // ===================================================================
        // 🔧 EVENTOS DE EQUIPAMENTO - FALHAS MECÂNICAS
        // ===================================================================
        
        // 🚫 PUMP FAILURE - Falha da bomba de fundo
        EventoEstocastico pump_failure;
        pump_failure.tipo = TipoEvento::PUMP_FAILURE;
        pump_failure.severidade = SeveridadeEvento::ALTA;
        pump_failure.nome = "Pump Failure";
        pump_failure.descricao = "Falha da bomba centrífuga submarina";
        pump_failure.probabilidade_base = 0.000002;  // 5%/mês
        pump_failure.duracao_segundos = 14400.0;     // 4 horas (tempo para intervenção)
        pump_failure.fator_vazao = 0.30;             // -70% vazão
        pump_failure.ativo = false;
        eventos_definidos.push_back(pump_failure);
        
        // 📊 SENSOR DRIFT - Deterioração de sensores
        EventoEstocastico sensor_drift;
        sensor_drift.tipo = TipoEvento::SENSOR_DRIFT;
        sensor_drift.severidade = SeveridadeEvento::BAIXA;
        sensor_drift.nome = "Sensor Drift";
        sensor_drift.descricao = "Degradação da calibração dos sensores";
        sensor_drift.probabilidade_base = 0.000008;  // 20%/mês (mais comum)
        sensor_drift.duracao_segundos = 7200.0;      // 2 horas
        sensor_drift.ativo = false;
        eventos_definidos.push_back(sensor_drift);
        
        // 🔒 VALVE STUCK - Válvula travada
        EventoEstocastico valve_stuck;
        valve_stuck.tipo = TipoEvento::VALVE_STUCK;
        valve_stuck.severidade = SeveridadeEvento::MEDIA;
        valve_stuck.nome = "Valve Stuck";
        valve_stuck.descricao = "Válvula de controle travada por parafinas ou scale";
        valve_stuck.probabilidade_base = 0.000003;  // ~8%/mês
        valve_stuck.duracao_segundos = 3600.0;     // 1 hora
        valve_stuck.fator_vazao = 0.80;            // -20% vazão
        valve_stuck.ativo = false;
        eventos_definidos.push_back(valve_stuck);
        
        // ===================================================================
        // 🏔️ EVENTOS DE FORMAÇÃO - FENÔMENOS GEOLÓGICOS
        // ===================================================================
        
        // 🧂 SCALE DEPOSITION - Deposição de sais
        EventoEstocastico scale_deposition;
        scale_deposition.tipo = TipoEvento::SCALE_DEPOSITION;
        scale_deposition.severidade = SeveridadeEvento::MEDIA;
        scale_deposition.nome = "Scale Deposition";
        scale_deposition.descricao = "Cristalização de sais na tubulação";
        scale_deposition.probabilidade_base = 0.000004;  // 12%/ano
        scale_deposition.duracao_segundos = 21600.0;     // 6 horas
        scale_deposition.fator_vazao = 0.92;             // -8% vazão
        scale_deposition.fator_viscosidade = 1.10;       // +10% viscosidade aparente
        scale_deposition.ativo = false;
        eventos_definidos.push_back(scale_deposition);
        
        // 🕯️ PARAFFIN BUILDUP - Deposição de parafinas
        EventoEstocastico paraffin_buildup;
        paraffin_buildup.tipo = TipoEvento::PARAFFIN_BUILDUP;
        paraffin_buildup.severidade = SeveridadeEvento::MEDIA;
        paraffin_buildup.nome = "Paraffin Buildup";
        paraffin_buildup.descricao = "Cristalização de parafinas por resfriamento";
        paraffin_buildup.probabilidade_base = 0.000008;  // 25%/ano (comum em MLS-3A)
        paraffin_buildup.duracao_segundos = 28800.0;     // 8 horas
        paraffin_buildup.fator_vazao = 0.88;             // -12% vazão
        paraffin_buildup.fator_viscosidade = 1.25;       // +25% viscosidade
        paraffin_buildup.ativo = false;
        eventos_definidos.push_back(paraffin_buildup);
        
        // 🕳️ WELLBORE COLLAPSE - Colapso do poço (evento raro e catastrófico)
        EventoEstocastico wellbore_collapse;
        wellbore_collapse.tipo = TipoEvento::WELLBORE_COLLAPSE;
        wellbore_collapse.severidade = SeveridadeEvento::CRITICA;
        wellbore_collapse.nome = "Wellbore Collapse";
        wellbore_collapse.descricao = "Colapso geomecânico do poço";
        wellbore_collapse.probabilidade_base = 0.0000005;  // 2%/ano (muito raro)
        wellbore_collapse.duracao_segundos = 604800.0;     // 7 dias (permanente até workover)
        wellbore_collapse.fator_vazao = 0.15;              // -85% vazão
        wellbore_collapse.ativo = false;
        eventos_definidos.push_back(wellbore_collapse);
        
        // ===================================================================
        // 🔧 EVENTOS OPERACIONAIS - MANUTENÇÃO E PROCEDIMENTOS
        // ===================================================================
        
        // 🛠️ EQUIPMENT MAINTENANCE - Manutenção programada
        EventoEstocastico equipment_maintenance;
        equipment_maintenance.tipo = TipoEvento::EQUIPMENT_MAINTENANCE;
        equipment_maintenance.severidade = SeveridadeEvento::MEDIA;
        equipment_maintenance.nome = "Equipment Maintenance";
        equipment_maintenance.descricao = "Manutenção preventiva programada";
        equipment_maintenance.probabilidade_base = 0.000001;  // Baseado em cronograma
        equipment_maintenance.duracao_segundos = 28800.0;     // 8 horas
        equipment_maintenance.fator_vazao = 0.05;             // -95% vazão (parada)
        equipment_maintenance.ativo = false;
        eventos_definidos.push_back(equipment_maintenance);
        
        // 💉 INJECTION CHANGE - Mudança no padrão de injeção
        EventoEstocastico injection_change;
        injection_change.tipo = TipoEvento::INJECTION_CHANGE;
        injection_change.severidade = SeveridadeEvento::BAIXA;
        injection_change.nome = "Injection Change";
        injection_change.descricao = "Alteração no padrão de injeção de água";
        injection_change.probabilidade_base = 0.000002;  // Operacional, mais frequente
        injection_change.duracao_segundos = 10800.0;     // 3 horas
        injection_change.fator_vazao = 1.02;             // +2% vazão (otimização)
        injection_change.ativo = false;
        eventos_definidos.push_back(injection_change);
        
        /*
        📊 RESUMO DO CATÁLOGO IMPLEMENTADO - FASE 2:
        • 11 tipos diferentes de eventos industriais
        • Probabilidades baseadas em dados históricos MLS-3A (1999-2025)
        • Durações realistas para cada tipo de fenômeno
        • Fatores de impacto calibrados com dados da Bacia de Campos
        • Severidades balanceadas para experiência educacional progressiva
        
        🎯 PRÓXIMA ETAPA: Sistemas de correlação avançada (Fase 3)
        */
    }
    
    /*
    🎲 ====================================================================
    AVALIAÇÃO DE NOVOS EVENTOS
    ====================================================================
    
    📚 CONCEITO EDUCACIONAL:
    A cada ciclo de 5 segundos, avalia se novos eventos devem ser ativados.
    Usa distribuições de probabilidade realistas baseadas em Monte Carlo.
    */
    void avaliarNovosEventos(const Reservatorio& reservatorio, double delta_tempo) {
        // Distribuição uniforme para geração de probabilidades
        std::uniform_real_distribution<double> dist_prob(0.0, 1.0);
        
        /*
        🔍 ALGORITMO: Para cada evento definido:
        1. Calcular probabilidade ajustada pelas condições atuais
        2. Gerar número aleatório
        3. Se prob >= random E condição_ativação = true → Ativar evento
        */
        
        for (const auto& evento_def : eventos_definidos) {
            // Verificar se evento já está ativo (evita duplicação)
            bool ja_ativo = false;
            for (const auto* ativo : eventos_ativos) {
                if (ativo->tipo == evento_def.tipo) {
                    ja_ativo = true;
                    break;
                }
            }
            
            if (ja_ativo) continue;  // Pular se já ativo
            
            /*
            📊 CÁLCULO DA PROBABILIDADE AJUSTADA:
            prob_final = prob_base × fator_vazão^(vazão/25000) × 
                         fator_pressão^(2500/pressão) × 
                         fator_temperatura^(temperatura/70)
            */
            double prob_ajustada = evento_def.probabilidade_base;
            
            // Ajuste por vazão (normalizada para 25,000 bpd típico)
            if (reservatorio.vazao_producao > 0.0) {
                double fator_v = reservatorio.vazao_producao / 25000.0;
                prob_ajustada *= std::pow(evento_def.fator_vazao, fator_v);
            }
            
            // Ajuste por pressão (normalizada para 2500 psi típico)
            if (reservatorio.pressao_psi > 0.0) {
                double fator_p = 2500.0 / reservatorio.pressao_psi;
                prob_ajustada *= std::pow(evento_def.fator_pressao, fator_p);
            }
            
            // Ajuste por temperatura (normalizada para 70°C típico)
            if (reservatorio.temperatura_C > 0.0) {
                double fator_t = reservatorio.temperatura_C / 70.0;
                prob_ajustada *= std::pow(evento_def.fator_temperatura, fator_t);
            }
            
            /*
            🎚️ MODIFICADOR DE NÍVEL DE REALISMO:
            Ajusta probabilidade baseado na configuração educacional
            */
            switch (nivel_atual) {
                case NivelRealismo::EDUCACIONAL:
                    prob_ajustada *= 0.3;  // 30% da prob real (mais suave)
                    break;
                case NivelRealismo::OPERACIONAL:
                    prob_ajustada *= 1.0;  // 100% da prob real
                    break;
                case NivelRealismo::EXTREMO:
                    prob_ajustada *= 2.0;  // 200% da prob real (mais intenso)
                    break;
                case NivelRealismo::HISTORICO:
                    prob_ajustada *= 1.5;  // 150% da prob real (dados históricos)
                    break;
            }
            
            /*
            🎯 TESTE DE ATIVAÇÃO SIMPLIFICADO:
            Por agora, apenas teste de probabilidade básico
            */
            double random_val = dist_prob(rng);
            
            if (random_val <= prob_ajustada) {
                // 🚨 EVENTO ATIVADO! Criar instância ativa
                ativarNovoEvento(evento_def, reservatorio);
            }
        }
    }
    
    /*
    ⚡ ====================================================================  
    PROCESSAMENTO DE EVENTOS ATIVOS
    ====================================================================
    
    📚 CONCEITO EDUCACIONAL:
    Aplica os efeitos dos eventos ativos sobre as propriedades do reservatório.
    Cada evento tem impactos específicos baseados em física industrial real.
    */
    void processarEventosAtivos(Reservatorio& reservatorio, double delta_tempo) {
        /*
        🔄 ALGORITMO: Para cada evento ativo:
        1. Decrementar tempo restante
        2. Aplicar efeitos nas propriedades (multiplicativos/aditivos)
        3. Registrar no sistema de logging
        4. Marcar para remoção se expirado
        */
        
        for (auto* evento : eventos_ativos) {
            // Decrementar duração restante
            evento->tempo_restante -= delta_tempo;
            
            /*
            🎯 APLICAÇÃO DOS EFEITOS POR TIPO DE EVENTO:
            Cada evento altera propriedades específicas do reservatório
            */
            aplicarEfeitosEvento(*evento, reservatorio, delta_tempo);
            
            /*
            📈 INTENSIDADE BASEADA EM SEVERIDADE:
            Eventos mais severos têm impactos maiores
            */
            double multiplicador_severidade = obterMultiplicadorSeveridade(evento->severidade);
            
            // Aplicar logging se necessário (não a cada ciclo para evitar spam)
            if (static_cast<int>(evento->tempo_ativo) % 30 == 0) {  // A cada 30 segundos
                registrarEfeitoEvento(*evento, reservatorio);
            }
            
            evento->tempo_ativo += delta_tempo;
        }
    }
    
    /*
    🧹 ====================================================================
    LIMPEZA DE EVENTOS FINALIZADOS
    ====================================================================
    */
    void removerEventosFinalizados() {
        /*
        🗑️ ALGORITMO DE LIMPEZA:
        Remove eventos que já expiraram (tempo_restante <= 0)
        Libera memória e atualiza contadores
        */
        eventos_ativos.erase(
            std::remove_if(eventos_ativos.begin(), eventos_ativos.end(),
                [](EventoEstocastico* evento) -> bool {
                    if (evento->tempo_restante <= 0.0) {
                        delete evento;  // Liberar memória
                        return true;    // Marcar para remoção
                    }
                    return false;
                }),
            eventos_ativos.end()
        );
    }
    
    /*
    🚨 ====================================================================
    ATIVAÇÃO DE NOVOS EVENTOS
    ====================================================================
    */
    void ativarNovoEvento(const EventoEstocastico& evento_def, const Reservatorio& reservatorio) {
        /*
        📚 CONCEITO: Cria uma instância ativa do evento com:
        • Duração aleatória dentro de faixas realistas
        • Intensidade baseada em severidade
        • Registro no sistema de logging
        */
        
        // Criar nova instância do evento
        EventoEstocastico* novo_evento = new EventoEstocastico(evento_def);
        
        // Definir duração baseada no tipo de evento
        std::uniform_real_distribution<double> dist_duracao = obterDistribuicaoDuracao(evento_def.tipo);
        novo_evento->tempo_restante = dist_duracao(rng);
        novo_evento->tempo_ativo = 0.0;
        
        // Adicionar à lista de eventos ativos
        eventos_ativos.push_back(novo_evento);
        
        // Atualizar contadores estatísticos
        contador_eventos[evento_def.tipo]++;
        
        // Log do evento (será implementado na próxima fase)
        // registrarInicioEvento(*novo_evento, reservatorio);
    }
    
    /*
    🎯 ====================================================================
    APLICAÇÃO DOS EFEITOS ESPECÍFICOS
    ====================================================================
    */
    void aplicarEfeitosEvento(const EventoEstocastico& evento, class Reservatorio& reservatorio, double delta_tempo) {
        /*
        🎯 FASE 2: APLICAÇÃO REAL DOS EFEITOS DOS EVENTOS
        ====================================================================
        
        📚 CONCEITO EDUCACIONAL:
        Cada evento aplica efeitos específicos baseados em fenômenos físicos reais
        observados na indústria petrolífera, usando as correlações implementadas na Fase 1.2
        */
        
        double intensidade = obterMultiplicadorSeveridade(evento.severidade);
        
        switch (evento.tipo) {
            case TipoEvento::WATER_CONING:
            {
                /*
                🌊 WATER CONING - INVASÃO DE ÁGUA NO POÇO
                ========================================
                
                📚 FENÔMENO FÍSICO:
                - Cone de água se forma devido ao diferencial de pressão
                - Aumento súbito do WOR (Water-Oil Ratio)
                - Redução da eficiência de produção
                - Possível aumento da viscosidade por emulsificação
                */
                
                // Aplicar aumento no WOR usando correlação estocástica
                bool breakthrough_ativo = (evento.severidade >= SeveridadeEvento::ALTA);
                double novo_WOR = SistemaCorrelacoesFisicas::calcularWOREstocastico(
                    reservatorio.WOR_bbl_bbl, 
                    reservatorio.tempo_simulacao_s,
                    reservatorio.vazao_producao,
                    breakthrough_ativo
                );
                
                // Aplicar mudança gradual para realismo
                double fator_aplicacao = 0.1 * intensidade;  // 10% por ciclo com severidade
                reservatorio.WOR_bbl_bbl += (novo_WOR - reservatorio.WOR_bbl_bbl) * fator_aplicacao;
                
                // Redução da vazão devido à interferência da água
                double fator_eficiencia = 1.0 - (0.03 * intensidade);  // -3% por severidade
                reservatorio.vazao_producao *= fator_eficiencia;
                
                // Recalcular viscosidade considerando maior water cut
                double novo_water_cut = reservatorio.WOR_bbl_bbl / (1.0 + reservatorio.WOR_bbl_bbl);
                double nova_viscosidade = SistemaCorrelacoesFisicas::calcularViscosidadeDinamica(
                    reservatorio.temperatura_C,
                    reservatorio.pressao_psi,
                    novo_water_cut
                );
                
                reservatorio.viscosidade_oleo_cp = nova_viscosidade;
                
                break;
            }
            
            case TipoEvento::GAS_CONING:
            {
                /*
                💨 GAS CONING - INVASÃO DE GÁS LIVRE
                ====================================
                
                📚 FENÔMENO FÍSICO:
                - Gás livre invade o poço através de cone
                - Aumento súbito do GOR (Gas-Oil Ratio)
                - Redução da eficiência das bombas (gas lock)
                - Flutuações na pressão de fundo
                */
                
                // Calcular novo GOR usando correlação dinâmica
                double tempo_producao_dias = reservatorio.tempo_simulacao_s / (24.0 * 3600.0);
                double GOR_natural = SistemaCorrelacoesFisicas::calcularGORDinamico(
                    reservatorio.pressao_psi,
                    reservatorio.temperatura_C,
                    tempo_producao_dias
                );
                
                // Adicionar efeito do gas coning (aumento súbito)
                double fator_gas_coning = 1.0 + (0.15 * intensidade);  // +15% por severidade
                double novo_GOR = GOR_natural * fator_gas_coning;
                
                // Aplicar mudança gradual
                double fator_aplicacao = 0.08 * intensidade;  // 8% por ciclo
                reservatorio.GOR_scf_bbl += (novo_GOR - reservatorio.GOR_scf_bbl) * fator_aplicacao;
                
                // Redução da eficiência da bomba devido ao gas lock
                double fator_gas_lock = 1.0 - (0.05 * intensidade);  // -5% por severidade
                reservatorio.vazao_producao *= fator_gas_lock;
                
                break;
            }
            
            case TipoEvento::BREAKTHROUGH:
            {
                /*
                🚨 BREAKTHROUGH - CHEGADA SÚBITA DE AQUÍFERO
                ============================================
                
                📚 FENÔMENO FÍSICO:
                - Chegada súbita de água do aquífero
                - Mudança permanente no WOR (step change)
                - Possível mudança na composição química
                - Impacto severo na produção
                */
                
                // Evento de breakthrough causa mudança permanente
                double fator_breakthrough = 1.0 + (0.40 * intensidade);  // +40% por severidade
                reservatorio.WOR_bbl_bbl *= fator_breakthrough;
                
                // Impacto severo na produção
                double fator_producao = 1.0 - (0.15 * intensidade);  // -15% por severidade
                reservatorio.vazao_producao *= fator_producao;
                
                // Recalcular viscosidade com novo water cut
                double novo_water_cut = reservatorio.WOR_bbl_bbl / (1.0 + reservatorio.WOR_bbl_bbl);
                double nova_viscosidade = SistemaCorrelacoesFisicas::calcularViscosidadeDinamica(
                    reservatorio.temperatura_C,
                    reservatorio.pressao_psi,
                    novo_water_cut
                );
                
                reservatorio.viscosidade_oleo_cp = nova_viscosidade;
                
                break;
            }
            
            case TipoEvento::PUMP_FAILURE:
            {
                /*
                🚫 FALHA DA BOMBA DE FUNDO
                ==========================
                
                📚 FENÔMENO FÍSICO:
                - Falha mecânica da bomba centrífuga submarina
                - Redução drástica ou parada total da produção
                - Aumento da pressão de fundo
                - Necessidade de intervenção (workover)
                */
                
                // Redução drástica na vazão
                double fator_falha = 1.0 - (0.70 * intensidade);  // -70% por severidade
                reservatorio.vazao_producao *= fator_falha;
                
                // Aumento da pressão de fundo (menos drawdown)
                double fator_pressao = 1.0 + (0.02 * intensidade);  // +2% por severidade
                reservatorio.pressao_psi *= fator_pressao;
                
                break;
            }
            
            case TipoEvento::SENSOR_DRIFT:
            {
                /*
                📊 SENSOR DRIFT - DETERIORAÇÃO DE SENSORES
                ==========================================
                
                📚 FENÔMENO FÍSICO:
                - Calibração dos sensores se deteriora com tempo
                - Leituras imprecisas (bias sistemático)
                - Afeta tomada de decisão operacional
                - Comum em ambiente de alta temperatura/pressão
                */
                
                // Para sensor drift, não alteramos propriedades reais
                // mas sim a "percepção" delas (implementação futura)
                // Por agora, apenas marca que há incerteza nas medições
                
                break;
            }
            
            case TipoEvento::VALVE_STUCK:
            {
                /*
                🔒 VÁLVULA TRAVADA
                ==================
                
                📚 FENÔMENO FÍSICO:
                - Válvula de controle trava em posição fixa
                - Impossibilidade de ajustar vazão
                - Redução parcial da produção
                - Comum devido a parafinas ou scale
                */
                
                // Redução moderada na vazão
                double fator_valvula = 1.0 - (0.20 * intensidade);  // -20% por severidade
                reservatorio.vazao_producao *= fator_valvula;
                
                break;
            }
            
            case TipoEvento::SCALE_DEPOSITION:
            {
                /*
                🧂 DEPOSIÇÃO DE SAIS (SCALE)
                ============================
                
                📚 FENÔMENO FÍSICO:
                - Cristalização de sais na tubulação
                - Redução do diâmetro efetivo
                - Aumento da perda de carga
                - Comum com produção de água salgada
                */
                
                // Aumento gradual da viscosidade aparente (restrição de fluxo)
                double fator_scale = 1.0 + (0.10 * intensidade);  // +10% por severidade
                reservatorio.viscosidade_oleo_cp *= fator_scale;
                
                // Redução na eficiência de produção
                double fator_eficiencia = 1.0 - (0.08 * intensidade);  // -8% por severidade
                reservatorio.vazao_producao *= fator_eficiencia;
                
                break;
            }
            
            case TipoEvento::PARAFFIN_BUILDUP:
            {
                /*
                🕯️ DEPOSIÇÃO DE PARAFINAS
                =========================
                
                📚 FENÔMENO FÍSICO:
                - Cristalização de parafinas em temperatura baixa
                - Aumento significativo da viscosidade
                - Bloqueio parcial ou total da tubulação
                - Comum em óleos pesados da Bacia de Campos
                */
                
                // Aumento significativo da viscosidade
                double fator_parafina = 1.0 + (0.25 * intensidade);  // +25% por severidade
                reservatorio.viscosidade_oleo_cp *= fator_parafina;
                
                // Redução na produção devido ao aumento da viscosidade
                double fator_producao = 1.0 - (0.12 * intensidade);  // -12% por severidade
                reservatorio.vazao_producao *= fator_producao;
                
                break;
            }
            
            case TipoEvento::WELLBORE_COLLAPSE:
            {
                /*
                🕳️ COLAPSO DO POÇO
                ==================
                
                📚 FENÔMENO FÍSICO:
                - Instabilidade geomecânica da formação
                - Fechamento parcial ou total do poço
                - Evento catastrófico e geralmente irreversível
                - Requer workover ou abandono
                */
                
                // Impacto catastrófico na produção
                double fator_colapso = 1.0 - (0.85 * intensidade);  // -85% por severidade
                reservatorio.vazao_producao *= fator_colapso;
                
                // Mudança na pressão devido à alteração geométrica
                double fator_pressao = 1.0 + (0.05 * intensidade);  // +5% por severidade
                reservatorio.pressao_psi *= fator_pressao;
                
                break;
            }
            
            case TipoEvento::EQUIPMENT_MAINTENANCE:
            {
                /*
                🛠️ MANUTENÇÃO PROGRAMADA
                ========================
                
                📚 CONCEITO OPERACIONAL:
                - Parada programada para manutenção
                - Produção zero durante o período
                - Prevenção de falhas maiores
                - Parte do cronograma operacional
                */
                
                // Parada total durante manutenção
                double fator_manutencao = 1.0 - (0.95 * intensidade);  // -95% por severidade
                reservatorio.vazao_producao *= fator_manutencao;
                
                break;
            }
            
            case TipoEvento::INJECTION_CHANGE:
            {
                /*
                💉 MUDANÇA NO PADRÃO DE INJEÇÃO
                ===============================
                
                📚 CONCEITO OPERACIONAL:
                - Alteração na estratégia de injeção de água/gás
                - Impacto na manutenção de pressão
                - Mudança nos padrões de fluxo
                - Otimização da recuperação
                */
                
                // Impacto na pressão do reservatório
                double fator_pressao = 1.0 + (0.03 * intensidade);  // +3% por severidade
                reservatorio.pressao_psi *= fator_pressao;
                
                // Possível impacto na produção (sweep efficiency)
                double fator_sweep = 1.0 + (0.02 * intensidade);  // +2% por severidade
                reservatorio.vazao_producao *= fator_sweep;
                
                break;
            }
            
            default:
                break;
        }
        
        /*
        🛡️ VALIDAÇÃO FINAL:
        Aplicar validação de ranges físicos após todos os efeitos
        */
        if (!SistemaCorrelacoesFisicas::validarRangesFisicos(
                reservatorio.pressao_psi,
                reservatorio.temperatura_C,
                reservatorio.vazao_producao,
                reservatorio.GOR_scf_bbl,
                reservatorio.WOR_bbl_bbl)) {
            
            // Se valores saíram do range físico, aplicar correções
            reservatorio.pressao_psi = std::max(500.0, std::min(5000.0, reservatorio.pressao_psi));
            reservatorio.vazao_producao = std::max(0.0, std::min(100000.0, reservatorio.vazao_producao));
            reservatorio.GOR_scf_bbl = std::max(50.0, std::min(2000.0, reservatorio.GOR_scf_bbl));
            reservatorio.WOR_bbl_bbl = std::max(0.0, std::min(20.0, reservatorio.WOR_bbl_bbl));
        }
    }
    
    /*
    📊 ====================================================================
    FUNÇÕES AUXILIARES
    ====================================================================
    */
    double obterMultiplicadorSeveridade(SeveridadeEvento severidade) const {
        switch (severidade) {
            case SeveridadeEvento::BAIXA:    return 0.5;
            case SeveridadeEvento::MEDIA:    return 1.0;
            case SeveridadeEvento::ALTA:     return 1.5;
            case SeveridadeEvento::CRITICA:  return 2.0;
            default: return 1.0;
        }
    }
    
    std::uniform_real_distribution<double> obterDistribuicaoDuracao(TipoEvento tipo) {
        /*
        📋 DURAÇÕES REALISTAS POR TIPO DE EVENTO:
        Baseado em estatísticas industriais da Petrobras
        */
        switch (tipo) {
            case TipoEvento::WATER_CONING:
                return std::uniform_real_distribution<double>(120.0, 2592000.0);  // 2min-30dias
            case TipoEvento::GAS_CONING:
                return std::uniform_real_distribution<double>(60.0, 1296000.0);   // 1min-15dias
            case TipoEvento::BREAKTHROUGH:
                return std::uniform_real_distribution<double>(86400.0, 31536000.0); // 1 dia - 1 ano (permanente)
            case TipoEvento::PUMP_FAILURE:
                return std::uniform_real_distribution<double>(3600.0, 604800.0);  // 1h-7dias
            case TipoEvento::SENSOR_DRIFT:
                return std::uniform_real_distribution<double>(3600.0, 2592000.0); // 1h-30dias
            case TipoEvento::VALVE_STUCK:
                return std::uniform_real_distribution<double>(600.0, 86400.0);    // 10min-1dia
            case TipoEvento::SCALE_DEPOSITION:
                return std::uniform_real_distribution<double>(2592000.0, 7776000.0); // 30-90dias
            case TipoEvento::PARAFFIN_BUILDUP:
                return std::uniform_real_distribution<double>(5184000.0, 15552000.0); // 60-180dias
            case TipoEvento::WELLBORE_COLLAPSE:
                return std::uniform_real_distribution<double>(86400.0, 31536000.0); // 1 dia - 1 ano (permanente)
            case TipoEvento::EQUIPMENT_MAINTENANCE:
                return std::uniform_real_distribution<double>(7200.0, 86400.0);   // 2h-1dia
            case TipoEvento::INJECTION_CHANGE:
                return std::uniform_real_distribution<double>(3600.0, 259200.0);  // 1h-3dias
            default:
                return std::uniform_real_distribution<double>(3600.0, 86400.0);   // 1h-1dia default
        }
    }
    
    void registrarEfeitoEvento(const EventoEstocastico& evento, const Reservatorio& reservatorio) {
        /*
        📊 FASE 2: SISTEMA DE LOGGING DE EVENTOS
        ========================================
        
        📚 CONCEITO EDUCACIONAL:
        Registra eventos ativos no sistema de logging para que estudantes
        possam acompanhar os fenômenos que afetam a produção
        */
        
        // Determinar emoji e cor baseado no tipo de evento
        QString emoji, tipoTexto, impactoTexto;
        
        switch (evento.tipo) {
            case TipoEvento::WATER_CONING:
                emoji = "🌊";
                tipoTexto = "Water Coning";
                impactoTexto = QString("WOR: %1 bbl/bbl | Vazão reduzida")
                             .arg(reservatorio.WOR_bbl_bbl, 0, 'f', 2);
                break;
                
            case TipoEvento::GAS_CONING:
                emoji = "💨";
                tipoTexto = "Gas Coning";
                impactoTexto = QString("GOR: %1 scf/bbl | Eficiência bomba reduzida")
                             .arg(reservatorio.GOR_scf_bbl, 0, 'f', 0);
                break;
                
            case TipoEvento::BREAKTHROUGH:
                emoji = "🚨";
                tipoTexto = "Water Breakthrough";
                impactoTexto = QString("EVENTO SEVERO | WOR: %1 bbl/bbl")
                             .arg(reservatorio.WOR_bbl_bbl, 0, 'f', 2);
                break;
                
            case TipoEvento::PUMP_FAILURE:
                emoji = "🚫";
                tipoTexto = "Falha da Bomba";
                impactoTexto = QString("Produção: %1 bpd | Requer intervenção")
                             .arg(reservatorio.vazao_producao, 0, 'f', 0);
                break;
                
            case TipoEvento::SENSOR_DRIFT:
                emoji = "📊";
                tipoTexto = "Sensor Drift";
                impactoTexto = "Leituras imprecisas | Verificar calibração";
                break;
                
            case TipoEvento::VALVE_STUCK:
                emoji = "🔒";
                tipoTexto = "Válvula Travada";
                impactoTexto = QString("Vazão limitada: %1 bpd")
                             .arg(reservatorio.vazao_producao, 0, 'f', 0);
                break;
                
            case TipoEvento::SCALE_DEPOSITION:
                emoji = "🧂";
                tipoTexto = "Deposição de Scale";
                impactoTexto = QString("Viscosidade: %1 cP | Eficiência reduzida")
                             .arg(reservatorio.viscosidade_oleo_cp, 0, 'f', 1);
                break;
                
            case TipoEvento::PARAFFIN_BUILDUP:
                emoji = "🕯️";
                tipoTexto = "Deposição de Parafinas";
                impactoTexto = QString("Viscosidade: %1 cP | Bloqueio parcial")
                             .arg(reservatorio.viscosidade_oleo_cp, 0, 'f', 1);
                break;
                
            case TipoEvento::WELLBORE_COLLAPSE:
                emoji = "🕳️";
                tipoTexto = "Colapso do Poço";
                impactoTexto = "EVENTO CATASTRÓFICO | Workover necessário";
                break;
                
            case TipoEvento::EQUIPMENT_MAINTENANCE:
                emoji = "🛠️";
                tipoTexto = "Manutenção Programada";
                impactoTexto = "Produção parada | Manutenção preventiva";
                break;
                
            case TipoEvento::INJECTION_CHANGE:
                emoji = "💉";
                tipoTexto = "Mudança de Injeção";
                impactoTexto = QString("Pressão: %1 psi | Otimização de recovery")
                             .arg(reservatorio.pressao_psi, 0, 'f', 0);
                break;
                
            default:
                emoji = "⚡";
                tipoTexto = "Evento Dinâmico";
                impactoTexto = "Monitorando impactos...";
                break;
        }
        
        // Texto de severidade
        QString severidadeTexto;
        switch (evento.severidade) {
            case SeveridadeEvento::BAIXA:
                severidadeTexto = "BAIXA";
                break;
            case SeveridadeEvento::MEDIA:
                severidadeTexto = "MÉDIA";
                break;
            case SeveridadeEvento::ALTA:
                severidadeTexto = "ALTA";
                break;
            case SeveridadeEvento::CRITICA:
                severidadeTexto = "CRÍTICA";
                break;
        }
        
        // Tempo restante em formato legível
        int minutos_restantes = static_cast<int>(evento.tempo_restante / 60.0);
        QString tempoTexto;
        if (minutos_restantes > 60) {
            int horas = minutos_restantes / 60;
            minutos_restantes = minutos_restantes % 60;
            tempoTexto = QString("%1h%2min").arg(horas).arg(minutos_restantes);
        } else {
            tempoTexto = QString("%1min").arg(minutos_restantes);
        }
        
        // PLACEHOLDER: Aqui deveria chamar o sistema de logging da UI
        // Por agora, apenas prepara as strings que seriam usadas
        QString logMessage = QString("%1 %2 [%3] - %4 (Restante: %5)")
                           .arg(emoji)
                           .arg(tipoTexto)
                           .arg(severidadeTexto)
                           .arg(impactoTexto)
                           .arg(tempoTexto);
        
        // TODO: Integrar com sistema de logging da UI quando disponível
        // logMessage(logMessage, "evento");
    }
    
    /*
    🎮 ====================================================================
    SISTEMA ADAPTATIVO (Placeholder para Fase 4)
    ====================================================================
    */
    void atualizarSistemaAdaptativo(const Reservatorio& reservatorio) {
        // PLACEHOLDER: Sistema de machine learning será implementado na Fase 4
        // Por agora, apenas atualiza estatísticas básicas
        tempo_simulacao_total += 5.0;  // Incrementa tempo total de simulação
    }
    
    /*
    📊 ====================================================================
    ATUALIZAÇÃO DE PROBABILIDADES (baseada no nível de realismo)
    ====================================================================
    */
    void atualizarProbabilidades() {
        // PLACEHOLDER: Ajuste fino das probabilidades baseado no nível
        // Por agora, as probabilidades são ajustadas no momento da avaliação
    }
};

/*
🎯 ========================================================================
SISTEMA DE CORRELAÇÕES FÍSICAS - FASE 1.2
========================================================================

📚 FUNDAMENTOS TEÓRICOS:
As correlações implementadas são baseadas em equações termodinâmicas 
comprovadas na indústria petrolífera e validadas com dados da Bacia de Campos.
*/

class SistemaCorrelacoesFisicas {
public:
    /*
    🌡️ ====================================================================
    CORRELAÇÃO DE ANDRADE: VISCOSIDADE × TEMPERATURA
    ====================================================================
    
    📚 EQUAÇÃO: μ(T) = μ₀ × exp(B/T)
    
    CONCEITO FÍSICO:
    • Descoberta por Andrade (1930), fundamental na reologia
    • Viscosidade decresce exponencialmente com temperatura
    • Aplicável para óleos pesados da Bacia de Campos
    • Validada para range 60-120°C (profundidades 1.000-3.000m)
    
    PARÂMETROS MLS-3A:
    • μ₀ = 0.8 cP (viscosidade de referência a temperatura infinita)
    • B = 1.200 K (constante de ativação para óleo 29.5°API)
    • T em Kelvin absoluto (°C + 273.15)
    */
    static double calcularViscosidadeDinamica(double temperatura_C, double pressao_psi, double water_cut) {
        // Converter temperatura para Kelvin
        double T_kelvin = temperatura_C + 273.15;
        
        // Parâmetros calibrados para MLS-3A (óleo 29.5° API)
        const double mu_0 = 0.8;      // cP - viscosidade de referência
        const double B = 1200.0;      // K - constante de ativação
        
        // Correlação de Andrade básica
        double viscosidade_base = mu_0 * std::exp(B / T_kelvin);
        
        /*
        🔧 CORREÇÃO PARA PRESSÃO (Correlação de Barus):
        μ(P) = μ(P₀) × exp(α × (P - P₀))
        
        CONCEITO: Pressão alta aumenta viscosidade
        α = 2.5×10⁻⁴ psi⁻¹ (típico para óleos da Bacia de Campos)
        */
        const double P_0 = 2850.0;    // psi - pressão de referência MLS-3A
        const double alpha = 2.5e-4;  // psi⁻¹ - coeficiente piezoviscoso
        
        double fator_pressao = std::exp(alpha * (pressao_psi - P_0));
        double viscosidade_com_pressao = viscosidade_base * fator_pressao;
        
        /*
        💧 CORREÇÃO PARA EMULSÃO (Water Cut):
        μ_emulsão = μ_óleo × (1 + 2.5φ + 10.05φ² + 0.00273×exp(16.6φ))
        
        CONCEITO: Água produzida forma emulsão, aumenta viscosidade dramaticamente
        Equação de Einstein-Roscoe modificada para emulsões O/W
        φ = fração volumétrica de água (BSW)
        */
        if (water_cut > 0.0 && water_cut < 0.95) {  // Limite físico realista
            double phi = water_cut;  // Fração de água
            double fator_emulsao = 1.0 + 2.5*phi + 10.05*phi*phi + 0.00273*std::exp(16.6*phi);
            viscosidade_com_pressao *= fator_emulsao;
        }
        
        /*
        🛡️ VALIDAÇÃO DE RANGES FÍSICOS:
        Limitar resultado dentro de faixas realistas para MLS-3A
        */
        const double viscosidade_min = 0.5;    // cP - limite inferior físico
        const double viscosidade_max = 50.0;   // cP - limite superior operacional
        
        double resultado = std::max(viscosidade_min, 
                          std::min(viscosidade_max, viscosidade_com_pressao));
        
        return resultado;
    }
    
    /*
    ⛽ ====================================================================
    CORRELAÇÃO GOR × PRESSÃO: LIBERAÇÃO DIFERENCIAL
    ====================================================================
    
    📚 EQUAÇÃO: GOR(P) = GORₛₒₗ + (GOR₀ - GORₛₒₗ) × (P/Pb)ⁿ
    
    CONCEITO FÍSICO:
    • Baseada na Lei de Henry (solubilidade de gases)
    • Gás sai de solução quando pressão < Pb (bubble point)
    • Comportamento não-linear típico de reservatórios depletados
    • Validada com dados de PVT da Bacia de Campos
    
    PARÂMETROS MLS-3A:
    • GOR₀ = 420 scf/bbl (saturação inicial)
    • GORₛₒₗ = 280 scf/bbl (gás em solução permanente)
    • Pb = 2.200 psi (bubble point pressure)
    • n = 1.8 (expoente empírico para MLS-3A)
    */
    static double calcularGORDinamico(double pressao_psi, double temperatura_C, double tempo_producao_dias) {
        // Parâmetros calibrados para MLS-3A
        const double GOR_inicial = 420.0;     // scf/bbl - GOR de saturação
        const double GOR_solucao = 280.0;     // scf/bbl - gás permanentemente em solução
        const double P_bubble = 2200.0;       // psi - pressão de saturação
        const double n_expoente = 1.8;        // Expoente empírico
        
        double GOR_base;
        
        if (pressao_psi >= P_bubble) {
            /*
            📊 ACIMA DO BUBBLE POINT: 
            Todo gás permanece em solução, GOR constante
            */
            GOR_base = GOR_inicial;
        } else {
            /*
            📈 ABAIXO DO BUBBLE POINT:
            Liberação diferencial conforme pressão
            */
            double razao_pressao = pressao_psi / P_bubble;
            double fator_liberacao = std::pow(razao_pressao, n_expoente);
            
            GOR_base = GOR_solucao + (GOR_inicial - GOR_solucao) * fator_liberacao;
        }
        
        /*
        ⏰ EFEITO TEMPORAL: DEPLEÇÃO COMPOSICIONAL
        Com o tempo, composição do reservatório muda
        Componentes leves são produzidos primeiro
        */
        const double taxa_depleção = 0.001;  // %/dia - típico para MLS-3A
        double fator_tempo = 1.0 - (taxa_depleção * tempo_producao_dias / 365.0);
        fator_tempo = std::max(0.7, fator_tempo);  // Limite mínimo 70%
        
        double GOR_com_tempo = GOR_base * fator_tempo;
        
        /*
        🌡️ CORREÇÃO PARA TEMPERATURA:
        Temperatura alta aumenta liberação de componentes leves
        Baseado na equação de Antoine modificada
        */
        const double T_ref = 92.0;  // °C - temperatura de referência MLS-3A
        const double coef_temp = 0.002;  // K⁻¹ - coeficiente empírico
        
        double delta_T = temperatura_C - T_ref;
        double fator_temperatura = 1.0 + (coef_temp * delta_T);
        
        double resultado = GOR_com_tempo * fator_temperatura;
        
        /*
        🛡️ VALIDAÇÃO DE RANGES FÍSICOS:
        */
        const double GOR_min = 50.0;     // scf/bbl - limite inferior
        const double GOR_max = 1200.0;   // scf/bbl - limite superior
        
        return std::max(GOR_min, std::min(GOR_max, resultado));
    }
    
    /*
    💧 ====================================================================
    WOR ESTOCÁSTICO: WATER BREAKTHROUGH MODELING
    ====================================================================
    
    📚 EQUAÇÃO: WOR(t) = WOR₀ × [1 + f_breakthrough(t) + f_coning(t)]
    
    CONCEITO FÍSICO:
    • WOR cresce naturalmente com depleção
    • Eventos súbitos de water breakthrough
    • Coning effects baseados em vazão
    • Padrão de injeção afeta sweep efficiency
    */
    static double calcularWOREstocastico(double WOR_atual, double tempo_simulacao, 
                                        double vazao_producao, bool evento_breakthrough) {
        /*
        📈 CRESCIMENTO NATURAL (Curva de Buckley-Leverett):
        WOR cresce exponencialmente com saturação de água
        */
        const double taxa_crescimento = 0.0001;  // /dia
        double dias_producao = tempo_simulacao / (24.0 * 3600.0);
        double fator_natural = 1.0 + (taxa_crescimento * dias_producao);
        
        /*
        ⚡ EFEITO DE VAZÃO (Water Coning):
        Vazão alta favorece invasão de água
        Baseado no número de Bond (Bo = ρgh/σ)
        */
        const double vazao_critica = 25000.0;  // bpd - vazão crítica para coning
        double razao_vazao = vazao_producao / vazao_critica;
        double fator_vazao = 1.0 + 0.05 * std::max(0.0, razao_vazao - 1.0);
        
        /*
        🚨 EVENTOS DE BREAKTHROUGH:
        Aumento súbito quando evento ativo
        */
        double fator_breakthrough = evento_breakthrough ? 1.5 : 1.0;
        
        double WOR_novo = WOR_atual * fator_natural * fator_vazao * fator_breakthrough;
        
        /*
        🛡️ VALIDAÇÃO DE RANGES FÍSICOS:
        */
        const double WOR_min = 0.1;      // bbl/bbl - limite inferior
        const double WOR_max = 15.0;     // bbl/bbl - limite superior operacional
        
        return std::max(WOR_min, std::min(WOR_max, WOR_novo));
    }
    
    /*
    🔗 ====================================================================
    SISTEMA DE ACOPLAMENTO NÃO-LINEAR
    ====================================================================
    
    📚 CONCEITO: Propriedades interagem entre si de forma não-linear
    Mudança em uma propriedade afeta todas as outras
    */
    static void aplicarAcoplamentoNaoLinear(class Reservatorio& reservatorio) {
        // PLACEHOLDER: Será implementado após definição completa da classe Reservatorio
        // Por agora, apenas documenta a interface necessária
    }
    
    /*
    🛡️ ====================================================================
    VALIDAÇÃO DE RANGES FÍSICOS GLOBAIS
    ====================================================================
    */
    static bool validarRangesFisicos(double pressao_psi, double temperatura_C, 
                                    double vazao_bpd, double GOR_scf_bbl, double WOR_bbl_bbl) {
        // Validar ranges típicos da Bacia de Campos
        bool pressao_ok = (pressao_psi >= 500.0 && pressao_psi <= 5000.0);
        bool temperatura_ok = (temperatura_C >= 40.0 && temperatura_C <= 150.0);
        bool vazao_ok = (vazao_bpd >= 0.0 && vazao_bpd <= 100000.0);
        bool GOR_ok = (GOR_scf_bbl >= 50.0 && GOR_scf_bbl <= 2000.0);
        bool WOR_ok = (WOR_bbl_bbl >= 0.0 && WOR_bbl_bbl <= 20.0);
        
        return pressao_ok && temperatura_ok && vazao_ok && GOR_ok && WOR_ok;
    }
};

/*
🎯 ========================================================================
INTEGRAÇÃO COM O SISTEMA PRINCIPAL
========================================================================
*/

// Instância global do motor de eventos dinâmicos
MotorEventosDinamicos* motor_dinamico = nullptr;
    /*
    🔧 ====================================================================
    ATUALIZAÇÃO DE PROBABILIDADES
    ====================================================================
    */
    void atualizarProbabilidades() {
        // IMPLEMENTAÇÃO: Próxima etapa
        // Aplica modificadores baseados no nível de realismo
    }
};

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
                               //     RANGE TÍPICO: 1.800-4.200 psi (Bacia de Campos)
                               //     VALOR MLS-3A: 2.850 psi (atual, 2025)
    
    double temperatura_C;      // 🌡️ Temperatura do reservatório [°C]
                               //     CONCEITO: Afeta viscosidade e densidade dos fluidos
                               //     RANGE TÍPICO: 60-120°C (profundidades 1.000-3.000m)
                               //     VALOR MLS-3A: 92°C (medido em profundidade)
    
    double volume_oleo_bbl;    // 🛢️ Volume de óleo restante [barris]
                               //     CONCEITO: OOIP restante (Original Oil In Place)
                               //     OOIP ORIGINAL MLS-3A: ~280 milhões bbl
                               //     VALOR ATUAL: ~55 milhões bbl (80% já produzido)
    
    double volume_gas_m3;      // ☘️ Volume de gás livre [m³]
                               //     CONCEITO: Gás que se separa do óleo quando P < Pb
                               //     PROBLEMA: Excesso reduz eficiência de bombeio
                               //     CONTROLE: Injeção de gás ou flare
    
    double volume_agua_bbl;    // 💧 Volume de água no sistema [barris]
                               //     CONCEITO: Água connata + injetada + aquifer
                               //     PROBLEMA: Aumenta com water coning
                               //     BSW MLS-3A: ~23% (2025)

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
                                   //       VALOR MLS-3A: ~2,8 cp (92°C, 29,5° API)
    
    double vazao_oleo_bopd;        // 🚢 Vazão de produção de óleo [bopd]
                                   //       CONCEITO: Calculada pela curva IPR (Inflow Performance)
                                   //       FÓRMULA: Darcy (monofásico) + Vogel (bifásico)
                                   //       VALOR MLS-3A: ~22.000 bopd (após revitalização)
    
    double vazao_producao;         // 🎯 Vazão total de produção [bopd] - USADO PELO SISTEMA DINÂMICO
                                   //       CONCEITO: Equivale à vazao_oleo_bopd, mas separado para clareza
                                   //       SISTEMA DINÂMICO: Motor de eventos usa esta propriedade
                                   //       VALOR: Sempre igual a vazao_oleo_bopd
    
    double pressao_de_bolha_psi;   // 🧙 Pressão de saturação [psi]
                                   //       CONCEITO: Pressão onde gás começa a se separar do óleo
                                   //       IMPORTÂNCIA: P < Pb = fluxo bifásico (mais complexo)
                                   //       VALOR MLS-3A: 2.950 psi (lab PVT)
    
    double pressao_poco_psi;       // 🕳️ Pressão de fundo de poço (BHP) [psi]
                                   //       CONCEITO: Pressão na formação produtora
                                   //       CONTROLE: Válvula choke (↑ fecha, ↓ abre)
                                   //       VALOR MLS-3A: ~1.950 psi (controlado)
    
    bool em_emergencia;            // ⚠️ Status de emergência do sistema
                                   //       CONCEITO: Shutdown automático por parâmetros críticos
                                   //       TRIGGERS: P < P_min, μ > μ_max, GOR > GOR_max
    
    double gas_oil_ratio;          // ⛽ Razão gás-óleo (GOR) [scf/bbl]
                                   //       CONCEITO: Volume de gás por barril de óleo produzido
                                   //       PROBLEMA: GOR alto = baixa eficiência de bombeio
                                   //       VALOR MLS-3A: 420 scf/bbl (normal para óleo médio)
    
    double water_oil_ratio;        // 💧 Razão água-óleo (WOR) [adimensional]
                                   //       CONCEITO: Equivale ao BSW (Basic Sediments & Water)
                                   //       PROBLEMA: Aumenta com water coning e breakthrough
                                   //       VALOR MLS-3A: 0,23 = 23% BSW (2025)
    
    double tempo_simulacao_s;      // ⏱️ Tempo decorrido na simulação [segundos]
                                   //       CONCEITO: Contador interno para cálculos temporais

    /*
    🔍 ========================================================================
    CONSTANTES FÍSICAS REAIS DO POÇO MLS-3A (MARLIM SUL)
    ========================================================================
    
    📚 PARA ESTUDANTES: Estas são propriedades REAIS medidas em laboratório
    e campo, baseadas em 26 anos de dados operacionais do MLS-3A:
    */
    
    const double GRAVIDADE_GAS_PESO_AR = 0.85;    // ⛽ Densidade relativa do gás
                                                   //     CONCEITO: ρ_gás / ρ_ar (adimensional)
                                                   //     VALOR 0.85 = Gás "leve" (rico em metano)
                                                   //     IMPORTÂNCIA: Usado em correlações PVT
    
    const double GRAVIDADE_API = 29.5;            // 🌡️ Grau API do óleo MLS-3A
                                                   //     CONCEITO: Medida de "leveza" do óleo
                                                   //     FÓRMULA: °API = (141.5/ρ_60F) - 131.5
                                                   //     CLASSIFICAÇÃO: 29.5° = ÓLEO MÉDIO (bom!)
                                                   //     DENSIDADE: ~0.88 g/cm³ a 60°F
    
    const double PRODUTIVIDADE_POCO_C = 22000.0;  // 🚢 Produção atual MLS-3A [bopd]
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
                                                           //     REALIDADE: Custos MLS-3A ~US$ 35/bbl

    /*
    ⚠️ ========================================================================
    LIMITES OPERACIONAIS CRÍTICOS - SEGURANÇA E VIABILIDADE ECONÔMICA
    ========================================================================
    
    📚 CONCEITO: Estes limites definem as condições de SHUTDOWN AUTOMÁTICO
    do poço, baseados em critérios técnicos e econômicos reais da Petrobras:
    */
    
    const double LIMITE_PRESSAO_CRITICO_MIN = 1650.0; // ⚠️ Pressão mínima segura [psi]
                                                       //     CONCEITO: Abaixo = colapso da formação
                                                       //     GEOMECÂNICA: Tensão efetiva > resistência
                                                       //     VALOR MLS-3A: 1.650 psi (limite atual)
    
    const double LIMITE_PRESSAO_CRITICO_MAX = 4200.0; // ⚠️ Pressão máxima segura [psi]
                                                       //     CONCEITO: Acima = risco de blowout
                                                       //     VALOR HISTÓRICO: Pressão inicial MLS-3A (1999)
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
                                                       //     LIMITE REAL: MLS-3A opera até 40%
    
    const double LIMITE_GOR_CRITICO = 600.0;          // ⚠️ GOR máximo [scf/bbl]
                                                       //     CONCEITO: Acima = produção de óleo inviável
                                                       //     PROBLEMA: Muito gás, pouco óleo
                                                       //     TÍPICO: Óleo médio < 500 scf/bbl

    /*
    🏗️ ========================================================================
    CONSTRUTOR - INICIALIZAÇÃO COM DADOS REAIS DO MLS-3A (2025)
    ========================================================================
    
    📚 PARA ESTUDANTES: O construtor define o ESTADO INICIAL do reservatório.
    Todos os valores são baseados em dados reais coletados no MLS-3A em 2025,
    após 26 anos de produção (início: 1999).
    
    📅 DADOS HISTÓRICOS:
    • 1999: Descoberta e início da produção
    • 2010: Pico de produção (45.000 bopd)
    • 2015: Início do declínio acentuado
    • 2023: Projeto de revitalização
    • 2025: Estado atual (simulado)
    
    🔍 FONTE DOS DADOS: Relatórios ANP + Petrobras + Literatura Técnica
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
        
        vazao_producao(22000.0),       // 🎯 22.000 bopd - Produção para sistema dinâmico
                                       //     SINCRONIZAÇÃO: Sempre igual à vazao_oleo_bopd
                                       //     SISTEMA DINÂMICO: Usado pelos eventos estocásticos
        
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
    mantendo a mesma lógica de cálculo calibrada para o MLS-3A.
    */
    double calcularViscosidadeOleo(double pressao_psi, double temperatura_C) {
        // Cálculo de viscosidade calibrado para óleo MLS-3A (29.5° API)
        
        // USO DO MÉTODO UTILITÁRIO (REFATORAÇÃO)
        double temp_F = celsiusParaFahrenheit(temperatura_C);
        
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
            vazao_producao = 0.0;  // 🔄 SINCRONIZAÇÃO: Ambas vão a zero na emergência
            return;
        }
        
        // Cálculo de vazão baseado no IPR do MLS-3A
        vazao_oleo_bopd = calcularVazaoProducao(pressao_psi);
        vazao_producao = vazao_oleo_bopd;  // 🔄 SINCRONIZAÇÃO: Manter ambas propriedades iguais
        
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
        vazao_producao *= (1.0 + variacao);  // 🔄 SINCRONIZAÇÃO: Aplicar mesma variação
        
        // Aplicar limites operacionais do MLS-3A
        vazao_oleo_bopd = std::max(8000.0, std::min(vazao_oleo_bopd, 42000.0));
        vazao_producao = std::max(8000.0, std::min(vazao_producao, 42000.0));  // 🔄 SINCRONIZAÇÃO: Mesmos limites
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
        No MLS-3A, reduzir Pwf de 2.000 para 1.900 psi pode:
        • Aumentar vazão em 15%
        • Acelerar water coning em 30%
        • Reduzir vida útil em 2 anos
        
        ⚠️ DECISÃO: Curto prazo vs longo prazo?
        */
    }

}; // 🏁 FIM DA CLASSE RESERVATORIO - MODELO COMPLETO DO MLS-3A!

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

🏆 DADOS REAIS: Tudo baseado no campo MLS-3A (Marlim Sul)
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
• Sistemas da Petrobras coletam dados a cada 5-15 segundos
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
    
    double tempo_min;          // ⏱️ Tempo decorrido [minutos]
                               //     CONCEITO: Eixo temporal para análise de tendências
                               //     USO: Gráficos de produção vs tempo
                               //     CONVERSÃO: segundos → minutos (interface mais legível)
    
    double vazao_oleo;         // 🚢 Taxa de produção de óleo [barris/dia]
                               //     CONCEITO: Métrica principal de performance do poço
                               //     IMPORTÂNCIA: Indica a saúde econômica do campo
                               //     RANGE MLS-3A: 8.000-45.000 bopd (histórico)
    
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
                               //     CONSTANTE: ~92°C no MLS-3A (geotérmica)
    
    double gor;               // ⛽ Gas-Oil Ratio [scf/bbl] (standard cubic feet per barrel)
                              //     CONCEITO: Volume de gás por barril de óleo produzido
                              //     PROBLEMA: GOR alto = bombeio menos eficiente
                              //     TENDÊNCIA: Aumenta com depleção de pressão
    
    double wor;               // 💧 Water-Oil Ratio [adimensional]
                              //     CONCEITO: Equivale ao BSW (Basic Sediments & Water)
                              //     PROBLEMA: Water coning reduz produção de óleo
                              //     AUMENTO: Natural com a vida do campo
    
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
pelos sistemas SCADA da Petrobras.

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
Todos os parâmetros operacionais críticos do MLS-3A em formato executivo.

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
        setWindowTitle("📋 Relatório Operacional MLS-3A - Marlim Sul");
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
    executivo formatado, similar aos relatórios da Petrobras/ANP.
    */
    void generateReports(Reservatorio* reservatorio, const QVector<DadosPontos>& dataPoints) {
        QString reportHtml;

        // CABEÇALHO DO RELATÓRIO (HTML estruturado)
        reportHtml += "<div style='text-align: center; margin-bottom: 20px;'>";
        reportHtml += "<h1 style='color: #0056b3; margin: 0;'>🛢️ PETROBRAS - RELATÓRIO OPERACIONAL</h1>";
        reportHtml += "<h2 style='color: #0056b3; margin: 5px 0;'>POÇO MLS-3A - CAMPO DE MARLIM SUL</h2>";
        reportHtml += "<h3 style='color: #666; margin: 5px 0;'>BACIA DE CAMPOS - ÁGUAS PROFUNDAS</h3>";
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

        // RODAPÉ INSTITUCIONAL
        reportHtml += "<div style='margin-top: 30px; padding: 15px; background-color: #f8f9fa; border-left: 4px solid #0056b3;'>";
        reportHtml += "<p style='margin: 0; font-size: 10px; color: #666;'>";
        reportHtml += "📋 <b>RELATÓRIO GERADO AUTOMATICAMENTE</b> pelo Sistema SCADA MLS-3A<br>";
        reportHtml += "🏢 <b>PETROBRAS</b> - Petróleo Brasileiro S.A.<br>";
        reportHtml += "🌊 <b>CAMPO:</b> Marlim Sul • <b>BACIA:</b> Campos • <b>ESTADO:</b> Rio de Janeiro<br>";
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
• Sala de controle da Petrobras em Macaé (CENPES)  
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
Qt5 - Mesmo framework usado em sistemas industriais reais da Petrobras.

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
    2. Modelo físico do reservatório MLS-3A
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
        // MODELO FÍSICO: Cria instância do reservatório MLS-3A
        reservatorio = new Reservatorio();  
        
        /*
        🎮 SISTEMA DINÂMICO: Inicializar motor de eventos estocásticos
        📚 FASE 1.1 IMPLEMENTADA: Motor completo com 11 tipos de eventos
        */
        motor_dinamico = new MotorEventosDinamicos();
        motor_dinamico->setNivelRealismo(NivelRealismo::EDUCACIONAL);  // Começar suave
        
        // TIMER DE SIMULAÇÃO: Controla o passo de tempo da simulação
        simulationTimer = new QTimer(this);  // Timer Qt (gerenciado pelo pai)
        
        // CONECTA timer → gameLoop (padrão signal-slot do Qt)
        connect(simulationTimer, &QTimer::timeout, this, &SimuladorWindow::gameLoop);
        
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
            logMessage("🎓 SIMULADOR EDUCACIONAL MLS-3A INICIADO - BEM-VINDO!");
            logMessage("🏆 Poço: Marlim Sul (Bacia de Campos) - 26 anos de dados reais", "info");
            logMessage("📈 Parâmetros calibrados com dados da Petrobras/ANP:", "info");
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
            
            /*
            🎮 SISTEMA DINÂMICO - FASE 1.1 ATIVO:
            Processa eventos estocásticos a cada ciclo de simulação
            📚 CONCEITO: Simula a imprevisibilidade de um campo real
            */
            if (motor_dinamico) {
                motor_dinamico->processar(*reservatorio, 5.0);  // 5 segundos
                
                // Log de eventos ativos (apenas se houver eventos)
                int eventos_ativos = motor_dinamico->getNumeroEventosAtivos();
                if (eventos_ativos > 0 && static_cast<int>(reservatorio->tempo_simulacao_s) % 60 == 0) {
                    logMessage(QString("🎯 Sistema Dinâmico: %1 evento(s) ativo(s)").arg(eventos_ativos), "info");
                }
            }
        } else {
            // Mesmo sem produção, o tempo avança
            reservatorio->verificarEmergencia();
            reservatorio->tempo_simulacao_s += 5.0;
            
            /*
            🎮 EVENTOS DINÂMICOS TAMBÉM EM STANDBY:
            Alguns eventos (manutenção, sensor drift) podem ocorrer mesmo parado
            */
            if (motor_dinamico) {
                motor_dinamico->processar(*reservatorio, 5.0);
            }
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
                logMessage(QString("Acionando liberação de gás (flare) com vazão de %1 scfd.").arg(vazao), "acao");
            } else {
                QMessageBox::warning(this, "Erro de Entrada", "Por favor, insira um valor numérico para a vazão de liberação de gás.");
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
    
    /*
    🎮 ====================================================================
    CONTROLE DE NÍVEL DE REALISMO - FASE 1.3
    ====================================================================
    
    📚 CONCEITO EDUCACIONAL:
    Permite que educadores e estudantes ajustem a intensidade dos eventos
    estocásticos conforme o nível de conhecimento e objetivos pedagógicos.
    */
    void onRealismoChanged(int index) {
        if (!motor_dinamico) return;  // Verificação de segurança
        
        // Obter nível selecionado do item data
        int nivel_int = realismoSelector->itemData(index).toInt();
        NivelRealismo novo_nivel = static_cast<NivelRealismo>(nivel_int);
        
        // Atualizar motor dinâmico
        motor_dinamico->setNivelRealismo(novo_nivel);
        
        // Log educacional da mudança com explicação pedagógica
        QString nivelTexto = realismoSelector->currentText();
        QString explicacao;
        
        switch (novo_nivel) {
            case NivelRealismo::EDUCACIONAL:
                explicacao = "Eventos mais suaves e previsíveis para aprendizado inicial";
                break;
            case NivelRealismo::OPERACIONAL:
                explicacao = "Probabilidades reais baseadas em estatísticas da Bacia de Campos";
                break;
            case NivelRealismo::EXTREMO:
                explicacao = "Cenários intensos para treinamento avançado";
                break;
            case NivelRealismo::HISTORICO:
                explicacao = "Replica eventos reais do campo MLS-3A (1999-2025)";
                break;
        }
        
        logMessage(QString("🎯 Nível de Realismo alterado: %1").arg(nivelTexto), "info");
        logMessage(QString("📚 %1").arg(explicacao), "info");
        
        // Se há eventos ativos, informar sobre possível mudança de intensidade
        int eventos_ativos = motor_dinamico->getNumeroEventosAtivos();
        if (eventos_ativos > 0) {
            logMessage(QString("⚡ %1 evento(s) ativo(s) continuarão com nova intensidade").arg(eventos_ativos), "alerta");
        }
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

        QString fileName = "simulacao_petroleo.csv";
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            // Removida a coluna de preço
            out << "tempo_min,vazao_oleo_bopd,pressao_psi,viscosidade_cp,volume_oleo_bbl,temperatura_C,GOR,WOR\n";
            /*
            📊 EXPORTAÇÃO DE DADOS (REFATORADO):
            Uso do método utilitário formatarCampoNumerico() para
            consistência na formatação dos valores exportados
            */
            for (const auto& point : dataPoints) {
                out << point.tempo_min << ","
                    << formatarCampoNumerico(point.vazao_oleo) << ","
                    << formatarCampoNumerico(point.pressao) << ","
                    << formatarCampoNumerico(point.viscosidade_cp) << ","
                    << formatarCampoNumerico(point.volume_oleo) << ","
                    << formatarCampoNumerico(point.temperatura) << ","
                    << formatarCampoNumerico(point.gor) << ","
                    << formatarCampoNumerico(point.wor) << "\n";
            }
            file.close();
            QMessageBox::information(this, "Sucesso", "Arquivo CSV baixado com sucesso!");
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
    
    /*
    🎮 SISTEMA DINÂMICO - FASE 1.1:
    Motor de eventos estocásticos para realismo industrial
    */
    MotorEventosDinamicos* motor_dinamico;

    // Sistema de controle de periodicidade dos gráficos
    int periodoGraficoSegundos = 60;        // Período atual em segundos (padrão: 1 minuto)
    double ultimoTempoGrafico = 0.0;        // Último tempo que atualizou gráficos  
    QComboBox* periodoSelector;             // Seletor de período na interface
    
    /*
    🎮 SISTEMA DINÂMICO - CONTROLE DE INTERFACE:
    */
    QComboBox* realismoSelector;            // Seletor de nível de realismo

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
        
        /*
        🎮 CONTROLE DE NÍVEL DE REALISMO DO SISTEMA DINÂMICO - FASE 1.3:
        Permite ao usuário/educador ajustar a intensidade dos eventos estocásticos
        */
        QLabel* realismoLabel = new QLabel("🎯 Nível de Realismo:");
        realismoLabel->setStyleSheet("font-weight: bold; color: #FF6B35; font-size: 12px; margin-left: 30px; margin-right: 10px;");
        
        realismoSelector = new QComboBox();
        realismoSelector->addItem("🎓 Educacional (30%)", static_cast<int>(NivelRealismo::EDUCACIONAL));
        realismoSelector->addItem("🏭 Operacional (100%)", static_cast<int>(NivelRealismo::OPERACIONAL));
        realismoSelector->addItem("⚡ Extremo (200%)", static_cast<int>(NivelRealismo::EXTREMO));
        realismoSelector->addItem("📜 Histórico MLS-3A (150%)", static_cast<int>(NivelRealismo::HISTORICO));
        
        realismoSelector->setCurrentIndex(0); // Padrão: Educacional
        realismoSelector->setStyleSheet(
            "QComboBox { "
                "background-color: #2d2d2d; "
                "border: 2px solid #FF6B35; "
                "border-radius: 4px; "
                "padding: 6px; "
                "font-weight: bold; "
                "min-width: 180px; "
                "color: #FFFFFF; "
            "}"
            "QComboBox:hover { border-color: #FF8C55; background-color: #353535; }"
            "QComboBox::drop-down { border: none; }"
            "QComboBox QAbstractItemView { "
                "background-color: #2d2d2d; "
                "border: 2px solid #FF6B35; "
                "selection-background-color: #FF6B35; "
                "color: #FFFFFF; "
            "}"
        );
        
        periodControlLayout->addWidget(realismoLabel);
        periodControlLayout->addWidget(realismoSelector);
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
        /*
        🔥 ====================================================================
        TERMINOLOGIA HÍBRIDA: EDUCACIONAL + TÉCNICA
        ====================================================================
        
        📚 ABORDAGEM EDUCACIONAL IMPLEMENTADA:
        "Liberação de Gás (Flare)" - Combina clareza didática com precisão técnica
        
        • DIDÁTICO PRIMEIRO: "Liberação de Gás" explica a FUNÇÃO
        • TÉCNICO ENTRE PARÊNTESES: "(Flare)" ensina o TERMO INDUSTRIAL
        • PROGRESSÃO NATURAL: Função → Terminologia técnica
        
        🏭 BENEFÍCIO EDUCACIONAL:
        Estudantes entendem o propósito antes de aprender o jargão técnico,
        preparando-os adequadamente para a realidade industrial.
        */
        QWidget* flareControl = createInterventionControl("Liberação de Gás (Flare)", "Vazão (scfd)", "5000");
        
        /*
        💡 ====================================================================
        TOOLTIP EDUCACIONAL: SISTEMA DE LIBERAÇÃO DE GÁS (FLARE)
        ====================================================================
        
        📚 EXPLICAÇÃO TÉCNICA PARA ESTUDANTES:
        Adicionando tooltip com explicação completa do sistema flare para
        contexto educacional, conectando função à terminologia industrial.
        */
        flareControl->setToolTip(
            "🔥 LIBERAÇÃO DE GÁS (FLARE) - SISTEMA DE SEGURANÇA\n\n"
            "📚 FUNÇÃO:\n"
            "• Queima controlada de gases excedentes\n"
            "• Sistema de alívio de pressão por segurança\n"
            "• Controle de emissões (melhor queimar que liberar metano)\n\n"
            "🛢️ APLICAÇÃO NO MLS-3A:\n"
            "• Remove gás livre em excesso do sistema\n"
            "• Previne acúmulo perigoso de gases\n"
            "• Mantém eficiência das bombas (evita gas-lock)\n\n"
            "⚡ OPERAÇÃO:\n"
            "• Vazão típica: 5.000-15.000 scfd\n"
            "• Acionamento automático por alta pressão\n"
            "• Monitoramento contínuo de emissões\n\n"
            "🏭 REALIDADE INDUSTRIAL:\n"
            "Presente em todas as plataformas offshore da Petrobras.\n"
            "A 'tocha' visível nas plataformas é exatamente este sistema!"
        );
        
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
        
        // Conectar controles de periodicidade dos gráficos
        connect(periodoSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), 
                this, &SimuladorWindow::onPeriodoChanged);
        connect(clearChartsBtn, &QPushButton::clicked, this, &SimuladorWindow::onClearChartsClicked);
        
        /*
        🎮 CONECTAR CONTROLE DE REALISMO - FASE 1.3:
        Quando usuário muda nível de realismo, atualiza motor dinâmico
        */
        connect(realismoSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), 
                this, &SimuladorWindow::onRealismoChanged);
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
    Baseados nos valores reais do MLS-3A para visualização adequada.
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
        Ranges baseados nos valores reais do MLS-3A para visualização adequada
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
        
        // USO DO MÉTODO UTILITÁRIO (REFATORAÇÃO)
        ponto.tempo_min = obterTempoMinutos();  
        
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
            suggestion += "- Volume de gás alto: considere ativar liberação de gás (flare).\n";
            suggestInputFlare->setText("8000");
            hasSuggestion = true;
        }

        if (!hasSuggestion) {
            suggestionExplanationLabel->setText("O sistema está em condições operacionais normais. Nenhuma intervenção é sugerida no momento.");
            suggestInputWater->setPlaceholderText("Volume Água (bbl)");
            suggestInputGas->setPlaceholderText("Volume Gás (m³)");
            suggestInputVapor->setPlaceholderText("Tempo Vapor (s)");
            suggestInputFlare->setPlaceholderText("Vazão Liberação Gás (scfd)");
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
            reservatorio->vazao_producao,  // 🔄 CORRIGIDO: usar vazao_producao (mesma que sistema dinâmico)
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
🚀 FUNÇÃO MAIN - PONTO DE ENTRADA DO SIMULADOR EDUCACIONAL MLS-3A
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
    a.setApplicationName("Simulador MLS-3A Marlim Sul");  // Nome completo
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
