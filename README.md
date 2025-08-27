# Simulador de Reservatório de Petróleo e Gás Natural

## Descrição

Este é um simulador avançado de plataforma de petróleo desenvolvido em C++ com interface gráfica Qt, focado no monitoramento e controle operacional de reservatórios de petróleo e gás natural. O sistema implementa modelos físicos e matemáticos realistas para simular o comportamento de reservatórios em tempo real, permitindo aos operadores monitorar condições críticas e implementar intervenções para otimizar a produção.

## Objetivos

### Objetivo Principal
Fornecer uma ferramenta de simulação e controle para operação e monitoramento de reservatórios de petróleo, permitindo:

- **Monitoramento em Tempo Real**: Acompanhamento contínuo das condições do reservatório
- **Controle Operacional**: Implementação de intervenções para otimização da produção
- **Análise Preditiva**: Identificação de situações críticas e sugestões de intervenção
- **Treinamento Operacional**: Ambiente seguro para treinamento de operadores
- **Documentação e Relatórios**: Geração de relatórios operacionais e exportação de dados

### Objetivos Específicos
- Simular comportamento físico realista de reservatórios de petróleo
- Implementar sistemas de segurança com alertas automáticos
- Fornecer interface SCADA para monitoramento visual
- Permitir intervenções operacionais em tempo real
- Gerar dados históricos para análise

## Características do Sistema

### Arquitetura
- **Linguagem**: C++20
- **Framework GUI**: Qt5 (Widgets, Charts, SVG)
- **Padrão de Design**: Model-View-Controller (MVC)
- **Tempo Real**: Sistema de simulação contínua com timer de 1 segundo
- **Modularidade**: Classes separadas para reservatório, interface e relatórios

### Interface do Usuário
- **Painel SCADA**: Ícones visuais com status colorido em tempo real
- **Indicadores Numéricos**: Valores atualizados continuamente
- **Gráficos em Tempo Real**: 7 gráficos independentes para monitoramento
- **Sistema de Log**: Mensagens categorizadas por tipo e importância
- **Controles de Intervenção**: Botões e campos para ações operacionais

## Propriedades Físicas do Reservatório

### Variáveis de Estado Primárias (Valores Otimizados para Operação Normal)
- **Pressão do Reservatório**: 1800-6500 psi (valor inicial: **3500 psi** - seguro no meio do range)
- **Temperatura**: °C (valor inicial: **80°C** - otimizada para reduzir viscosidade)
- **Volume de Óleo**: barris (bbl) (valor inicial: **1.000.000 bbl**)
- **Volume de Gás**: metros cúbicos (m³) (valor inicial: **5000 m³** - moderado)
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

### v1.1 - Correção dos Valores Iniciais e Estabilização (Atual)

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

## Especificações de Performance

### Tempo Real
- **Frequência de Atualização**: 1 Hz (1 segundo)
- **Coleta de Dados**: A cada 5 segundos
- **Responsividade**: Interface atualizada em tempo real
- **Gráficos**: Plotagem contínua sem lag perceptível

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