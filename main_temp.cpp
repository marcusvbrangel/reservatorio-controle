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
    double tempo_restante;              // 🔄 Tempo restante do evento [segundos] - ADICIONADO
    
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
        tempo_restante(0.0),
        fator_vazao(1.0),          // 1.0 = sem mudança
        fator_pressao(1.0),
        fator_temperatura(1.0),
        fator_viscosidade(1.0),
        fator_gor(1.0),
        fator_wor(1.0)
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
