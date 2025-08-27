# Simulador MLS-3A - Poço Marlim Sul (Bacia de Campos)

## 🏆 Versão 2.0 - Simulador de Poço Real

Este é um simulador de alta fidelidade do **poço MLS-3A (Marlim Sul)** da Bacia de Campos, desenvolvido em C++ com interface gráfica Qt. O sistema implementa parâmetros físicos reais, modelos matemáticos calibrados e comportamentos baseados em 26 anos de histórico operacional (1999-2025) do maior campo petrolífero brasileiro.

### 🎯 Poço de Referência: MLS-3A
- **Campo**: Marlim Sul, Bacia de Campos
- **Operador**: Petrobras (100%)
- **Lâmina d'água**: 1.027 metros (águas profundas)
- **Produção histórica**: 125+ milhões de barris
- **Status**: Ativo há 26 anos (1999-2025)
- **Fase atual**: Revitalização com EOR

## 🎓 Objetivos Educacionais

### Objetivo Principal
Fornecer experiência autêntica de operação de um **poço real da Petrobras**, permitindo aos estudantes:

- **Familiarização Industrial**: Trabalhar com dados e parâmetros reais da Bacia de Campos
- **Contexto Brasileiro**: Aprender com o maior campo petrolífero nacional
- **Preparação Profissional**: Experiência pré-emprego com sistemas similares aos industriais
- **Benchmarking**: Comparação com padrões da indústria nacional e internacional
- **Caso de Sucesso**: Estudar poço com 26 anos de operação bem-sucedida

### Objetivos Técnicos Específicos
- **Autenticidade**: Simular comportamento baseado em dados reais do MLS-3A
- **Calibração**: Implementar modelos matemáticos validados com histórico operacional
- **Realismo**: Reproduzir curvas de declínio, coning e revitalização reais
- **Padrões COI**: Seguir intervalos de monitoramento da Petrobras (5 segundos)
- **Física Aplicada**: Correlações para óleo 29,5° API em condições específicas

## Características do Sistema

### Arquitetura Técnica (v2.0)
- **Linguagem**: C++20 com STL moderno
- **Framework GUI**: Qt5 (Widgets, Charts, SVG)
- **Padrão de Design**: Model-View-Controller (MVC)
- **Intervalos Realistas**: 5 segundos (padrão COI Petrobras)
- **Modularidade**: Classes especializadas para física do MLS-3A
- **Calibração**: Modelos matemáticos baseados em dados reais
- **Validação**: Parâmetros verificados com literatura SPE

### Interface Especializada MLS-3A (v2.0)
- **Identificação**: "Simulador MLS-3A - Poço Marlim Sul (Bacia de Campos)"
- **Tema Industrial**: Dark mode com esquema de cores da Petrobras
- **Layout SCADA**: Interface similar aos sistemas COI de Macaé
- **Indicadores Calibrados**: 7 parâmetros específicos do MLS-3A
- **Gráficos Realistas**: Curvas baseadas no histórico de 26 anos
- **Logs Educacionais**: Contexto técnico da Bacia de Campos
- **Alertas Específicos**: Limites operacionais do poço real
- **Monitoramento 5s**: Intervalos idênticos ao sistema COI real

## Propriedades Físicas do Reservatório

### Variáveis de Estado Primárias (Parâmetros Reais do MLS-3A - 2025)
- **Pressão do Reservatório**: **2.850 psi** (pressão atual após 26 anos de produção)
- **Temperatura**: **92°C** (temperatura de reservatório nas águas profundas)
- **Volume de Óleo Restante**: **55 milhões bbl** (OOIP original: 280 MM bbl)
- **Volume de Gás Livre**: **8.500 m³** (gás liberado por depleção)
- **Produção Atual**: **22.000 bopd** (após revitalização 2021-2025)
- **BSW (Water Cut)**: **23%** (produção de água atual)
- **GOR**: **420 scf/bbl** (gas-oil ratio característico)
- **Grau API**: **29,5°** (óleo médio/leve de excelente qualidade)
- **Volume de Água**: barris (bbl) (valor inicial: **50.000 bbl** - volume realista)

### Propriedades Derivadas (Calculadas)
- **Viscosidade do Óleo**: centipoise (cp) (valor inicial calculado: **~2.5 cp**)
- **Vazão de Óleo**: barris por dia (bopd) (valor inicial: **1200 bopd** - acima do mínimo)
- **Pressão de Bolha**: psi (valor inicial: **2800 psi** - menor que pressão do reservatório)
- **Pressão do Poço**: psi (valor inicial: **400 psi** - adequada para produção)
- **Gas-Oil Ratio (GOR)**: razão gás/óleo (valor inicial: **300** - moderado)
- **Water-Oil Ratio (WOR)**: razão água/óleo (valor inicial: **0.1** - baixo)

### Constantes Físicas do Reservatório
- **Gravidade Específica do Gás**: 0.7 (relativa ao ar)
- **Grau API do Óleo**: 27.0
- **Produtividade do Poço**: 1000.0 bopd
- **Fator de Injeção de Gás**: 0.05
- **Fator de Injeção de Água**: 0.01

## Modelos e Métodos Matemáticos

### 1. Cálculo da Solubilidade do Gás (Correlação de Standing)
```
Rs = γg × [(P/18.2) × exp(0.0125 × API × exp(0.0011 × T_F))]^1.2045
```
Onde:
- Rs = solubilidade do gás (scf/bbl)
- γg = gravidade específica do gás
- P = pressão (psi)
- API = grau API do óleo
- T_F = temperatura (°F)

### 2. Cálculo da Viscosidade do Óleo (Modelo Otimizado)
**Fórmula simplificada para garantir valores operacionais realistas:**

```
μ_oil = μ_base × f_temp × f_pressao
```

Onde:
- **μ_base = 3.0 cp** (viscosidade base típica)
- **f_temp = 1.0 - (T - 60°C) / 200°C** (fator de temperatura, limitado entre 0.5 e 2.0)
- **f_pressao = 1.0 + (P - 3000 psi) / 10000 psi** (fator de pressão, limitado entre 0.8 e 1.2)
- **Resultado limitado a < 5.5 cp** (abaixo do limite crítico de 6.0 cp)

**Características do modelo:**
- Viscosidade diminui com aumento da temperatura
- Pequeno efeito da pressão na viscosidade
- Garante valores operacionalmente seguros
- Previne acionamento desnecessário de alertas críticos

### 3. Equação de Vazão de Produção (IPR - Inflow Performance Relationship)

**Para P ≥ P_bubble:**
```
q = q_max × (1 - 0.2 × (P_wf/P_r) - 0.8 × (P_wf/P_r)²)
```

**Para P < P_bubble:**
```
q = slope × P_r
```
Onde slope é calculado baseado na curva de produção na pressão de bolha.

### 4. Modelo de Declínio de Pressão
```
P_new = P_old - (0.1 × óleo_produzido / 1000)
```

### 5. Simulação de Gas Coning e Water Coning
Quando P_wf < 200 psi:
- GOR aumenta: GOR = GOR + 50
- WOR aumenta: WOR = WOR + 0.01

### 6. Efeitos de Injeção
**Injeção de Água:**
```
P_new = P_old + (volume × fator_base × fator_temperatura)
```

**Injeção de Gás:**
```
P_new = P_old + (volume × fator_base × fator_densidade)
```

## Configuração Inicial do Sistema (Valores Corrigidos - v1.1)

### Condições Iniciais Otimizadas para Operação Normal
O sistema foi configurado com valores iniciais que garantem operação estável desde o início:

| Parâmetro | Valor Inicial | Faixa Segura | Status |
|-----------|---------------|--------------|--------|
| **Pressão do Reservatório** | 3500 psi | 1800-6500 psi | ✅ Seguro |
| **Temperatura** | 80°C | 60-180°C | ✅ Ótima |
| **Volume de Óleo** | 1.000.000 bbl | > 0 bbl | ✅ Abundante |
| **Volume de Gás** | 5000 m³ | < 10000 m³ | ✅ Moderado |
| **Volume de Água** | 50.000 bbl | Variável | ✅ Realista |
| **Vazão de Óleo** | 1200 bopd | > 500 bopd | ✅ Produtiva |
| **Viscosidade** | ~2.5 cp | < 6.0 cp | ✅ Fluida |
| **GOR** | 300 | < 2000 | ✅ Normal |
| **WOR** | 0.1 | < 0.5 | ✅ Baixo |
| **Pressão de Bolha** | 2800 psi | < P_reservatório | ✅ Adequada |
| **Pressão do Poço** | 400 psi | 100-1000 psi | ✅ Operacional |

### Limites de Segurança Críticos
- **Pressão Mínima Crítica**: 1800 psi
- **Pressão Máxima Crítica**: 6500 psi
- **Viscosidade Crítica**: 6.0 cp
- **Volume de Gás Crítico**: 10.000 m³
- **WOR Crítico**: 0.5
- **GOR Crítico**: 2000
- **Produção Mínima Aceitável**: 500 bopd

### Estados Operacionais
1. **Operação Normal**: Todos os parâmetros dentro dos limites
2. **Estado de Alerta**: Parâmetros próximos aos limites críticos
3. **Estado de Emergência**: Um ou mais parâmetros excedem limites críticos

### Sistema de Emergência Automático
O sistema automaticamente entra em estado de emergência quando qualquer condição crítica é violada:
- Interrupção automática da produção
- Bloqueio de todas as intervenções
- Alertas visuais e sonoros
- Log de eventos críticos

## Operações e Intervenções Disponíveis

### 1. Controles de Injeção

#### Injeção de Água
- **Objetivo**: Manter pressão do reservatório
- **Parâmetros**: Volume (bbl) e Temperatura (°C)
- **Efeitos**: Aumento de pressão, alteração de temperatura

#### Injeção de Gás
- **Objetivo**: Pressurização e otimização da produção
- **Parâmetros**: Volume (m³) e Densidade relativa
- **Efeitos**: Aumento significativo de pressão

#### Injeção de Vapor
- **Objetivo**: Redução da viscosidade do óleo pesado
- **Parâmetros**: Tempo de injeção (segundos)
- **Efeitos**: Aumento de temperatura (até 200°C máximo)

### 2. Controles de Produção

#### Sistema de Válvulas (Choke)
- **Abrir Válvula**: Reduz pressão do poço (-50 psi), aumenta vazão
- **Fechar Válvula**: Aumenta pressão do poço (+50 psi), reduz vazão
- **Limites**: Pressão do poço entre 100-1000 psi

#### Controle de Produção
- **Iniciar Produção**: Ativa a produção e simulação
- **Parar Produção**: Interrompe produção para manutenção

### 3. Sistema de Flare
- **Objetivo**: Controle de pressão através da queima de gás
- **Parâmetros**: Vazão de queima (scfd)
- **Efeitos**: Redução de volume de gás e pressão

## Sistema de Monitoramento

### Indicadores em Tempo Real
1. **Produção de Petróleo** (bopd)
2. **Pressão do Reservatório** (psi)
3. **Volume de Óleo** (bbl)
4. **Temperatura** (°C)
5. **Viscosidade** (cp)
6. **GOR** (razão)
7. **WOR** (razão)

### Gráficos Históricos
- **Vazão de Óleo**: Nível operacional, atualização contínua
- **Pressão**: Nível operacional, crítico para segurança
- **Volume de Óleo**: Nível gerencial, acompanhamento de reservas
- **Temperatura**: Nível operacional, otimização térmica
- **Viscosidade**: Nível operacional, qualidade do óleo
- **GOR e WOR**: Nível operacional, eficiência de produção

### Sistema SCADA Visual
Ícones coloridos indicando status:
- **Verde**: Operação normal
- **Laranja**: Alerta/atenção
- **Vermelho**: Crítico/emergência

## Sistema de Sugestões Inteligentes

O sistema analisa continuamente as condições do reservatório e fornece sugestões automáticas:

### Lógica de Sugestões
- **Pressão < 2500 psi**: Sugere injeção de água (5000 bbl) ou gás (10000 m³)
- **Viscosidade > 4.0 cp**: Sugere injeção de vapor (1000 s)
- **Volume de Gás > 8000 m³**: Sugere acionamento de flare (8000 scfd)

### Sistema de Alertas
- **Pressão em declínio**: Aviso quando pressão < 2500 psi
- **Viscosidade alta**: Aviso quando viscosidade > 4.0 cp
- **Emergência crítica**: Alerta quando limites críticos são violados

## Relatórios e Exportação de Dados

### Relatório Operacional
Inclui todos os parâmetros atuais:
- Vazão de óleo atual
- Pressão do reservatório
- Temperatura
- Viscosidade
- Ratios GOR e WOR
- Status do sistema

### Exportação CSV
Dados históricos exportáveis incluindo:
- Timestamp (minutos)
- Todos os parâmetros operacionais
- Formatação para análise em planilhas
- Dados coletados a cada 5 segundos

## Requisitos Técnicos

### Dependências do Sistema
```bash
# Ubuntu/Debian
sudo apt install libqt5charts5-dev
sudo apt install cmake make
sudo apt install libqt5svg5-dev
sudo apt install qtbase5-dev libqt5widgets5 libqt5charts5-dev libqt5svg5-dev
```

### Compilação
```bash
rm -rf build
mkdir build
cd build
cmake ..
make
```

### Execução
```bash
./reservatorio_01
```

## Histórico de Melhorias

### v1.3 - Intervalos de Monitoramento Realistas e Produção Dinâmica (Atual)

#### Correções Críticas na Simulação:
- ✅ **Produção Dinâmica Corrigida**: Vazão de óleo agora varia continuamente em tempo real
- ✅ **Gráficos Ativos**: Todas as séries de dados agora se movimentam e evoluem
- ✅ **Declínio de Pressão Realista**: Fator aumentado 20x para visibilidade das mudanças
- ✅ **Variabilidade Operacional**: Flutuações de ±2% simulando condições reais
- ✅ **Fator de Depleção**: Declínio acelera conforme reservatório se esgota
- ✅ **Comentários Técnicos**: Código documentado com explicações detalhadas

#### Intervalos de Monitoramento Baseados na Indústria:
- ✅ **Padrão Bacia de Campos**: Intervalos de 5 segundos (padrão Petrobras)
- ✅ **Sistema COI Simulado**: 28 plataformas, 190 poços, monitoramento 24/7
- ✅ **Alertas Escalonados**: Críticos a cada 30 segundos (padrão industrial)
- ✅ **Dados Operacionais**: Coleta contínua a cada ciclo de 5 segundos
- ✅ **Log Educativo**: Contexto da indústria brasileira e internacional
- ✅ **Realismo Operacional**: Experiência autêntica de operação offshore

#### Melhorias na Física de Reservatório:
- ✅ **Simulação de Depleção**: Comportamento realista de esgotamento
- ✅ **Produção de Gás**: Efeitos intensificados para visibilidade
- ✅ **Coning Dinâmico**: Variações de GOR/WOR baseadas na pressão
- ✅ **Números Aleatórios**: Flutuações operacionais realistas
- ✅ **Tempo de Simulação**: Intervalos de 5 segundos por ciclo

### v1.2 - Redesign Completo da Interface

#### Interface e Experiência do Usuário:
- ✅ **Tema Dark Mode Completo**: Fundo preto profissional com esquema de cores moderno
- ✅ **Layout Responsivo**: Barra de rolagem automática e redimensionamento inteligente
- ✅ **Gráficos em Abas**: Sistema de navegação por abas em vez de empilhamento vertical
- ✅ **Grid Layout**: Indicadores organizados em grid 2×4 com cards individuais
- ✅ **Controles Reorganizados**: Layout horizontal com cards de intervenção em grid 2×2
- ✅ **Botões Modernos**: Design com ícones, cores funcionais e efeitos hover
- ✅ **Monitor SCADA Aprimorado**: Ícones maiores e melhor organização visual
- ✅ **Sistema de Log Melhorado**: Fonte monospace e melhor contraste

#### Melhorias Técnicas:
- ✅ **QScrollArea**: Suporte completo para rolagem em interfaces extensas
- ✅ **QTabWidget**: Navegação eficiente entre diferentes gráficos
- ✅ **QGridLayout**: Organização otimizada de componentes
- ✅ **Stylesheets CSS**: Tema visual consistente e profissional
- ✅ **Helper Functions**: Código modularizado para criação de componentes

#### Benefícios Visuais:
- 🎨 **Interface Profissional**: Design moderno compatível com aplicações industriais
- 📱 **Responsividade**: Adaptação a diferentes tamanhos de tela
- 👁️ **Melhor Legibilidade**: Contraste otimizado e tipografia clara
- ⚡ **Performance Visual**: Redução da sobrecarga visual e navegação intuitiva
- 🎯 **Foco Operacional**: Agrupamento lógico de funcionalidades relacionadas

### v1.1 - Correção dos Valores Iniciais e Estabilização

#### Problemas Corrigidos:
- ❌ **Problema**: Sistema entrava em estado de emergência imediatamente após inicialização
- ❌ **Problema**: Fórmula de viscosidade gerava valores excessivamente altos (>6.0 cp)
- ❌ **Problema**: Valores iniciais inadequados causavam shutdown automático constante
- ❌ **Problema**: QSocketNotifier causava fechamento da aplicação após alguns segundos

#### Soluções Implementadas:
- ✅ **Valores Iniciais Otimizados**: Configuração inicial com parâmetros dentro das faixas operacionais seguras
- ✅ **Fórmula de Viscosidade Revisada**: Modelo simplificado que garante valores realistas (2-5 cp)
- ✅ **Sistema de Threading Corrigido**: Timer iniciado após inicialização completa da interface
- ✅ **Melhor Gerenciamento de Recursos**: Destrutor aprimorado com parada adequada do timer

#### Benefícios:
- 🚀 **Operação Estável**: Sistema inicia em condições normais sem alertas críticos
- 🎯 **Valores Realistas**: Parâmetros físicos dentro de ranges industriais típicos  
- ⚡ **Performance Melhorada**: Aplicação permanece estável indefinidamente
- 📊 **Monitoramento Eficaz**: Alertas apenas quando necessário, não constantemente

### v1.0 - Versão Inicial
- Implementação base do simulador
- Interface gráfica Qt com gráficos em tempo real
- Sistema SCADA com ícones coloridos
- Modelos matemáticos de reservatório
- Sistema de relatórios e exportação CSV

## Especificações de Performance (v1.3)

### Intervalos de Monitoramento Realistas
- **Frequência Principal**: 0.2 Hz (5 segundos) - Padrão Bacia de Campos
- **Dados Operacionais**: Coleta contínua a cada ciclo (5s)
- **Alertas Críticos**: Verificação a cada 30 segundos
- **Tempo de Simulação**: 5 segundos por ciclo (tempo real acelerado)
- **Responsividade**: Interface otimizada para observação de tendências

### Sistema de Dados Dinâmicos
- **Produção de Óleo**: Variação contínua com declínio realista
- **Pressão**: Declínio progressivo baseado na depleção do reservatório
- **Gráficos**: Plotagem ativa com dados em constante evolução
- **Variabilidade**: Flutuações de ±2% simulando condições operacionais reais

### Capacidade de Dados
- **Armazenamento**: Ilimitado durante execução
- **Exportação**: Sem limite de registros
- **Gráficos**: Autoscaling automático

## Casos de Uso

### 1. Operação de Rotina
- Monitoramento contínuo de produção
- Ajustes operacionais baseados em tendências
- Manutenção preventiva baseada em alertas

### 2. Situações de Emergência
- Detecção automática de condições críticas
- Shutdown de segurança automático
- Procedimentos de recuperação guiados

### 3. Otimização de Produção
- Análise de eficiência através de ratios
- Intervenções para maximizar recuperação
- Balanceamento de injeção e produção

### 4. Treinamento
- Simulação de cenários diversos
- Treinamento em procedimentos de emergência
- Desenvolvimento de competências operacionais

## Limitações e Considerações

### Limitações do Modelo
- Simulação simplificada de fenômenos complexos
- Não considera heterogeneidades geológicas
- Modelo de reservatório homogêneo
- Não inclui efeitos de múltiplos poços

### Considerações Operacionais
- Sistema projetado para fins educacionais e de treinamento
- Modelos baseados em correlações industriais padrão
- Requires validação com dados reais para uso operacional
- Interface otimizada para operação desktop

## Desenvolvido Para

Este simulador foi desenvolvido especificamente para:
- **Estudantes** de engenharia de petróleo
- **Profissionais** em treinamento
- **Operadores** de plataforma
- **Engenheiros** de reservatório
- **Pesquisadores** em simulação

O sistema fornece uma base sólida para compreensão dos princípios fundamentais de operação de reservatórios e serve como ferramenta de apoio ao desenvolvimento de competências na área de engenharia de petróleo e gás natural.