# 📚 GLOSSÁRIO COMPLETO - SIMULADOR DE RESERVATÓRIO PETROLÍFERO ATS-7B

## 📋 ÍNDICE TEMÁTICO

- **[A] PARÂMETROS FÍSICOS FUNDAMENTAIS**
- **[B] CONSTANTES OPERACIONAIS E LIMITES**
- **[C] VARIÁVEIS DE CONTROLE E MONITORAMENTO**
- **[D] OPERAÇÕES E INTERVENÇÕES**
- **[E] SISTEMA DE ALERTAS E SEGURANÇA**
- **[F] TERMOS TÉCNICOS E CONCEITOS**
- **[G] UNIDADES DE MEDIDA E CONVERSÕES**

---

## **[A] PARÂMETROS FÍSICOS FUNDAMENTAIS**

### 📊 **PRESSÃO DO RESERVATÓRIO (pressao_psi)**

**🔬 DEFINIÇÃO TÉCNICA:**
Pressão média do fluido no reservatório, medida em pounds per square inch (psi).

**📍 LOCALIZAÇÃO NO CÓDIGO:** 
- Inicialização: `main.cpp:566` → `pressao_psi(2850.0)`
- Limites: `main.cpp:517-522`

**⚙️ VALORES OPERACIONAIS:**
- **Valor Inicial:** 2850.0 psi
- **Limite Crítico Mínimo:** 1650.0 psi
- **Limite Crítico Máximo:** 4200.0 psi
- **Pressão de Abandono:** < 1800 psi (shutdown automático)
- **Pressão de Segurança:** > 4000 psi (alerta crítico)

**🎯 POR QUE É CRÍTICO:**
- **Driving Force:** Principal força motriz da produção
- **IPR Calculation:** Base para cálculo da curva de produção
- **Safety Concern:** Pressões extremas causam falhas catastróficas

**⚠️ O QUE ACONTECE SE:**
- **< 1650 psi:** Shutdown automático (produção inviável)
- **> 4200 psi:** Risco de blowout, acionamento válvula alívio
- **Declínio rápido:** Indica water breakthrough ou depleção severa

**🔧 COMO É CALCULADA:**
```cpp
// Declínio natural baseado na produção
double declinio_pressao = vazao_oleo_bopd * 0.0001;
pressao_psi -= declinio_pressao * (tempo_passado_s / 86400.0);
```

---

### 🌡️ **TEMPERATURA DO RESERVATÓRIO (temperatura_C)**

**🔬 DEFINIÇÃO TÉCNICA:**
Temperatura média da formação rochosa e fluidos, em graus Celsius.

**📍 LOCALIZAÇÃO NO CÓDIGO:**
- Inicialização: `main.cpp:571` → `temperatura_C(92.0)`
- Cálculos: `main.cpp:773-790` (correlação viscosidade)

**⚙️ VALORES OPERACIONAIS:**
- **Valor Inicial:** 92.0°C
- **Faixa Operacional:** 60-120°C
- **Temperatura Crítica Baixa:** < 80°C
- **Temperatura Máxima Vapor:** 200°C (limitada)

**🎯 POR QUE É IMPORTANTE:**
- **Viscosity Control:** Inversamente proporcional à viscosidade
- **Phase Behavior:** Afeta solubilidade do gás no óleo
- **Thermal Recovery:** Base para métodos térmicos (vapor)

**⚠️ O QUE ACONTECE SE:**
- **< 80°C:** Viscosidade aumenta drasticamente
- **> 120°C:** Riscos de estabilidade térmica
- **Variações bruscas:** Tensões termo-mecânicas na rocha

**🔧 CORRELAÇÕES IMPLEMENTADAS:**
```cpp
// Equação de Andrade para viscosidade vs temperatura
double B = 600.0 + 1500.0 * exp(-0.02 * pressao_psi);
double resultado = A * exp(B / (temperatura_C + 273.15));
```

---

### 🛢️ **VAZÃO DE ÓLEO (vazao_oleo_bopd)**

**🔬 DEFINIÇÃO TÉCNICA:**
Taxa de produção de óleo líquido, em barris por dia (bopd - barrels of oil per day).

**📍 LOCALIZAÇÃO NO CÓDIGO:**
- Inicialização: `main.cpp:597` → `vazao_oleo_bopd(22000.0)`
- Cálculo IPR: `main.cpp:800-832`

**⚙️ VALORES OPERACIONAIS:**
- **Valor Atual:** 22.000 bopd (pós-revitalização 2023)
- **Valor Histórico:** 15.000 bopd (antes do projeto)
- **Limite Econômico:** 8.000 bopd
- **Capacidade Máxima:** 42.000 bopd

**🎯 POR QUE É FUNDAMENTAL:**
- **Economic Indicator:** Principal parâmetro econômico do campo
- **Production Decline:** Monitora declínio natural da produção
- **Intervention Trigger:** Base para decisões operacionais

**⚠️ O QUE ACONTECE SE:**
- **< 8000 bopd:** Campo torna-se antieconômico
- **< 500 bopd:** Intervenção crítica necessária
- **Declínio > 5%/mês:** Investigação de problemas

**🔧 FÓRMULA IPR IMPLEMENTADA:**
```cpp
// Darcy (monofásico) + Vogel (bifásico)
double drawdown_normalizado = (pressao_estatica - pwf) / pressao_estatica;
double eficiencia = 0.95 + 0.05 * drawdown_normalizado;
vazao_calculada = PRODUTIVIDADE_POCO_C * drawdown_normalizado * eficiencia;
```

---

### 🛢️ **VOLUME DE ÓLEO RESTANTE (volume_oleo_bbl)**

**🔬 DEFINIÇÃO TÉCNICA:**
Original Oil In Place (OOIP) remanescente no reservatório, em barris.

**📍 LOCALIZAÇÃO NO CÓDIGO:**
- Inicialização: `main.cpp:576` → `volume_oleo_bbl(55000000.0)`
- Depleção: `main.cpp:838-839`

**⚙️ VALORES HISTÓRICOS:**
- **OOIP Original:** 280 milhões bbl (estimativa)
- **Volume Atual:** 55 milhões bbl (2025)
- **Produção Acumulada:** 225 milhões bbl
- **Recovery Factor:** 80% (excelente!)

**🎯 POR QUE É ESTRATÉGICO:**
- **Reserve Estimation:** Base para vida útil do campo
- **Depletion Rate:** Controla declínio de pressão
- **Economic Planning:** Planejamento de investimentos

**⚠️ O QUE ACONTECE SE:**
- **= 0:** Fim da vida útil do campo
- **< 10MM bbl:** Início fase de abandono
- **Depleção acelerada:** Revisão de estratégia de produção

**🔧 CÁLCULO DE DEPLEÇÃO:**
```cpp
// Produção em barris neste intervalo
double oleo_produzido_bbl = vazao_oleo_bopd * (tempo_passado_s / 86400.0);
volume_oleo_bbl -= oleo_produzido_bbl;
```

---

### ⛽ **GAS OIL RATIO - GOR (gas_oil_ratio)**

**🔬 DEFINIÇÃO TÉCNICA:**
Razão gás-óleo produzida, em pés cúbicos padrão por barril (scf/bbl).

**📍 LOCALIZAÇÃO NO CÓDIGO:**
- Inicialização: `main.cpp:616` → `gas_oil_ratio(420.0)`
- Limite crítico: `main.cpp:542` → `LIMITE_GOR_CRITICO = 600.0`

**⚙️ VALORES OPERACIONAIS:**
- **Valor Inicial:** 420 scf/bbl
- **Faixa Normal:** 300-600 scf/bbl
- **Limite Crítico:** 600 scf/bbl
- **Alerta Atenção:** > 1000 scf/bbl
- **Shutdown:** > 2000 scf/bbl

**🎯 POR QUE É IMPORTANTE:**
- **Solution Gas:** Indica liberação de gás da solução
- **Pressure Decline:** Aumenta com queda de pressão
- **Gas Handling:** Impacta facilidades de superfície

**⚠️ O QUE ACONTECE SE:**
- **> 600 scf/bbl:** Problemas de separação gás-óleo
- **> 1500 scf/bbl:** Limitações de compressão
- **Aumenta rapidamente:** Water coning ou gas coning

**🔧 CORRELAÇÃO FÍSICA:**
```cpp
// GOR aumenta com declínio de pressão
double gor_increment = 0.5 * exp(-(pressao_psi / 1000.0));
gas_oil_ratio = std::min(gas_oil_ratio + gor_increment, LIMITE_GOR_CRITICO);
```

---

### 💧 **WATER OIL RATIO - WOR (water_oil_ratio)**

**🔬 DEFINIÇÃO TÉCNICA:**
Razão água-óleo produzida, também conhecida como BSW (Basic Sediments and Water).

**📍 LOCALIZAÇÃO NO CÓDIGO:**
- Inicialização: `main.cpp:621` → `water_oil_ratio(0.23)`
- Limite crítico: `main.cpp:537` → `LIMITE_WOR_CRITICO = 0.35`

**⚙️ VALORES OPERACIONAIS:**
- **Valor Inicial:** 0.23 (23% BSW)
- **Limite Operacional:** 0.35 (35%)
- **Limite Real ATS-7B:** 0.40 (40%)
- **Alerta Crítico:** > 60%
- **Shutdown:** > 95%

**🎯 POR QUE É CRÍTICO:**
- **Water Coning:** Principal mecanismo de entrada de água
- **Economic Limit:** Determina viabilidade econômica
- **Processing Cost:** Custos de separação e descarte

**⚠️ O QUE ACONTECE SE:**
- **> 35%:** Redução significativa da rentabilidade
- **> 60%:** Operação crítica, necessária intervenção
- **> 95%:** Poço praticamente produzindo só água

**🔧 EVOLUÇÃO NATURAL:**
```cpp
// Water coning natural com o tempo
double bsw_natural = 0.23 + (tempo_simulacao_s / 86400.0) * 0.00005;
water_oil_ratio = std::min(bsw_natural, LIMITE_WOR_CRITICO);
```

---

### 🌯 **VISCOSIDADE DO ÓLEO (viscosidade_oleo_cp)**

**🔬 DEFINIÇÃO TÉCNICA:**
Resistência do óleo ao escoamento, medida em centipoise (cp).

**📍 LOCALIZAÇÃO NO CÓDIGO:**
- Inicialização: `main.cpp:592` → `viscosidade_oleo_cp(2.8)`
- Cálculo: `main.cpp:773-790`
- Limite: `main.cpp:527` → `LIMITE_VISCOSIDADE_CRITICO = 4.5`

**⚙️ VALORES OPERACIONAIS:**
- **Valor Inicial:** 2.8 cp
- **Faixa Normal:** 1.8-4.5 cp
- **Limite Crítico:** 4.5 cp
- **Alerta Atenção:** > 10 cp
- **Shutdown:** > 20 cp

**🎯 POR QUE É FUNDAMENTAL:**
- **Flow Resistance:** Determina capacidade de escoamento
- **Pumping Requirements:** Afeta dimensionamento de bombas
- **Enhanced Recovery:** Base para métodos térmicos

**⚠️ O QUE ACONTECE SE:**
- **> 4.5 cp:** Redução significativa da produtividade
- **> 10 cp:** Necessária injeção de vapor ou aquecimento
- **> 20 cp:** Óleo praticamente imóvel

**🔧 EQUAÇÃO DE ANDRADE:**
```cpp
// Correlação viscosidade vs temperatura e pressão
double A = 0.2 + 0.8 * exp(-pressao_psi / 5000.0);
double B = 600.0 + 1500.0 * exp(-0.02 * pressao_psi);
resultado = A * exp(B / (temperatura_C + 273.15));
```

---

## **[B] CONSTANTES OPERACIONAIS E LIMITES**

### ⚖️ **GRAVIDADE_API (29.5°API)**

**🔬 DEFINIÇÃO TÉCNICA:**
Densidade do óleo segundo escala American Petroleum Institute.

**📍 LOCALIZAÇÃO NO CÓDIGO:** `main.cpp:481`

**⚙️ CLASSIFICAÇÃO:**
- **29.5°API:** Óleo médio (medium crude)
- **Densidade:** ~0.88 g/cm³ a 60°F
- **Qualidade:** Boa para refino

**🎯 USO NO SIMULADOR:**
```cpp
// Usado no cálculo de solubilidade de gás
resultado = GRAVIDADE_GAS_PESO_AR * pow((pressao_psi / 18.2) * 
           exp(0.0125 * GRAVIDADE_API * exp(0.0011 * temp_F)), 1.2045);
```

---

### ⛽ **GRAVIDADE_GAS_PESO_AR (0.85)**

**🔬 DEFINIÇÃO TÉCNICA:**
Densidade relativa do gás natural em relação ao ar (adimensional).

**📍 LOCALIZAÇÃO NO CÓDIGO:** `main.cpp:476`

**⚙️ CARACTERÍSTICAS:**
- **0.85:** Gás natural típico
- **Composição:** Principalmente metano
- **Comparação:** Ar = 1.0 (referência)

**🎯 IMPACTO OPERACIONAL:**
- **Compressão:** Afeta dimensionamento de compressores
- **Separação:** Influencia eficiência de separadores
- **Injeção:** Usado em cálculos de gas lift

---

### 🚢 **PRODUTIVIDADE_POCO_C (22000.0 bopd)**

**🔬 DEFINIÇÃO TÉCNICA:**
Índice de produtividade atual do poço ATS-7B.

**📍 LOCALIZAÇÃO NO CÓDIGO:** `main.cpp:487`

**⚙️ HISTÓRICO:**
- **2023 (Atual):** 22.000 bopd (pós-revitalização)
- **2022 (Anterior):** 15.000 bopd
- **Incremento:** 40% após projeto

**🎯 CONTEXTO TÉCNICO:**
Base para cálculo IPR (Inflow Performance Relationship):
```cpp
vazao_calculada = PRODUTIVIDADE_POCO_C * drawdown_normalizado * eficiencia;
```

---

### 🔧 **FATORES DE INJEÇÃO**

#### **FATOR_INJECAO_GAS_BASE (0.05)**
**📍 LOCALIZAÇÃO:** `main.cpp:493`
**🔬 DEFINIÇÃO:** Resposta de pressão por m³ de gás injetado
**⚙️ APLICAÇÃO:**
```cpp
pressao_psi += volume_m3 * FATOR_INJECAO_GAS_BASE * fator_densidade_pressao;
```

#### **FATOR_INJECAO_AGUA_BASE (0.01)**
**📍 LOCALIZAÇÃO:** `main.cpp:498`
**🔬 DEFINIÇÃO:** Resposta de pressão por bbl de água injetada
**⚙️ APLICAÇÃO:**
```cpp
pressao_psi += volume_bbl * FATOR_INJECAO_AGUA_BASE * fator_temp_pressao;
```

---

### 💰 **PRODUCAO_MINIMA_ACEITAVEL_BOPD (8000.0)**

**🔬 DEFINIÇÃO TÉCNICA:**
Limite econômico mínimo de produção para viabilidade operacional.

**📍 LOCALIZAÇÃO NO CÓDIGO:** `main.cpp:503`

**⚙️ CRITÉRIO ECONÔMICO:**
- **OPEX:** Custos operacionais fixos
- **Break-even:** Ponto de equilíbrio financeiro
- **Abandono:** Abaixo deste limite = abandono

**🎯 IMPACTO DECISÓRIO:**
```cpp
if (vazao_oleo_bopd < PRODUCAO_MINIMA_ACEITAVEL_BOPD) {
    // Campo antieconômico - considerar abandono
}
```

---

## **[C] VARIÁVEIS DE CONTROLE E MONITORAMENTO**

### 🕐 **SISTEMA DE TEMPO**

#### **tempo_simulacao_s**
**🔬 DEFINIÇÃO:** Contador interno de tempo decorrido em segundos
**📍 LOCALIZAÇÃO:** `main.cpp:464`
**⚙️ USO:** Base para todos os cálculos temporais

#### **currentTimeLabel / operationTimeLabel**
**🔬 DEFINIÇÃO:** Displays de tempo real e operacional
**📍 LOCALIZAÇÃO:** `main.cpp:2140-2141`
**⚙️ FORMATO:** 
- Real: 🕐 HH:MM:SS
- Operação: ⏱️ HH:MM:SS

---

### 📊 **VARIÁVEIS DE CONTROLE FÍSICO**

#### **volume_gas_m3**
**🔬 DEFINIÇÃO:** Volume de gás livre no reservatório
**⚙️ LIMITE:** 15.000 m³ (gas-lock prevention)

#### **volume_agua_bbl**
**🔬 DEFINIÇÃO:** Volume total de água no sistema
**⚙️ MONITORAMENTO:** Controle de water coning

#### **em_emergencia**
**🔬 DEFINIÇÃO:** Flag de estado de emergência
**⚙️ COMPORTAMENTO:** Bloqueia intervenções quando true

---

## **[D] OPERAÇÕES E INTERVENÇÕES**

### 💧 **INJEÇÃO DE ÁGUA (injetarAgua)**

**🔬 DEFINIÇÃO TÉCNICA:**
Injeção de água para manutenção de pressão do reservatório.

**📍 LOCALIZAÇÃO NO CÓDIGO:** `main.cpp:947-952`

**⚙️ PARÂMETROS:**
- **Volume:** bbl/dia
- **Temperatura:** °C (recomendado 60°C)

**🎯 OBJETIVOS:**
- **Pressure Support:** Manter pressão do reservatório
- **Sweep Efficiency:** Melhorar varrido do óleo
- **Recovery Enhancement:** Aumentar fator de recuperação

**⚠️ RISCOS:**
- **Water Breakthrough:** Chegada prematura de água
- **Formation Damage:** Danos à formação rochosa
- **Incompatibilidade:** Reações água-rocha

**🔧 CÁLCULO DE RESPOSTA:**
```cpp
// Fator considerando temperatura de injeção
double fator_temp_pressao = 1.0 + (temp_inj_C - temperatura_C) / 100.0;
pressao_psi += volume_bbl * FATOR_INJECAO_AGUA_BASE * fator_temp_pressao;
```

---

### ⛽ **INJEÇÃO DE GÁS (injetarGas)**

**🔬 DEFINIÇÃO TÉCNICA:**
Injeção de gás para suporte de pressão e gas lift.

**📍 LOCALIZAÇÃO NO CÓDIGO:** `main.cpp:954-958`

**⚙️ PARÂMETROS:**
- **Volume:** m³/dia
- **Densidade:** relativa ao ar (típico 0.8)

**🎯 MECANISMOS:**
- **Gas Cap Maintenance:** Manutenção da capa de gás
- **Gas Lift:** Redução da densidade da coluna
- **Pressure Support:** Suporte de pressão natural

**⚠️ CONTROLE DE QUALIDADE:**
```cpp
double fator_densidade_pressao = 1.0 + (densidade_gas_ar - GRAVIDADE_GAS_PESO_AR) * 0.5;
pressao_psi += volume_m3 * FATOR_INJECAO_GAS_BASE * fator_densidade_pressao;
```

---

### 🔥 **INJEÇÃO DE VAPOR (injetarVapor)**

**🔬 DEFINIÇÃO TÉCNICA:**
Injeção de vapor para recuperação térmica de óleo pesado.

**📍 LOCALIZAÇÃO NO CÓDIGO:** `main.cpp:960-963`

**⚙️ PARÂMETROS:**
- **Tempo:** segundos de injeção
- **Temperatura:** Limitada a 200°C

**🎯 BENEFÍCIOS:**
- **Viscosity Reduction:** Redução drástica da viscosidade
- **Thermal Recovery:** Método EOR (Enhanced Oil Recovery)
- **Mobility Improvement:** Melhora mobilidade do óleo

**🔧 IMPLEMENTAÇÃO:**
```cpp
temperatura_C += tempo_inundacao_s * 0.1;
temperatura_C = std::min(200.0, temperatura_C);
```

---

### ⚖️ **VÁLVULA DE ALÍVIO**

**🔬 DEFINIÇÃO TÉCNICA:**
Sistema de segurança para alívio de sobrepressão.

**⚙️ CONFIGURAÇÃO PADRÃO:**
- **Pressão de abertura:** 3500 psi
- **Taxa de alívio:** 20%

**🎯 FUNÇÃO DE SEGURANÇA:**
Previne pressões perigosas que podem causar blowout.

---

### 🔥 **SISTEMA DE AQUECIMENTO**

**🔬 DEFINIÇÃO TÉCNICA:**
Sistema para aquecimento do reservatório e redução de viscosidade.

**⚙️ CONFIGURAÇÃO PADRÃO:**
- **Temperatura alvo:** 90°C
- **Potência:** 150 kW

**🎯 APLICAÇÃO:**
Ativado quando temperatura < 80°C para manter flow properties adequadas.

---

### 🚀 **ESTIMULAÇÃO DE POÇO**

**🔬 DEFINIÇÃO TÉCNICA:**
Intervenção para aumento da produtividade do poço.

**⚙️ CONFIGURAÇÃO PADRÃO:**
- **Pressão:** 3000 psi
- **Tempo:** 60 min
- **Incremento:** +100 bopd

**🎯 MECANISMOS:**
- **Acidificação:** Remoção de danos próximos ao poço
- **Fraturamento:** Criação de caminhos preferenciais
- **Limpeza:** Remoção de parafinas e asfaltenos

---

## **[E] SISTEMA DE ALERTAS E SEGURANÇA**

### 🚨 **HIERARQUIA DE ALERTAS**

#### **NORMAL**
- **Cor:** Verde (#00FF88)
- **Condição:** Todos parâmetros dentro dos limites
- **Ação:** Operação contínua

#### **ATENÇÃO**
- **Cor:** Amarelo (#FFA500)
- **Condições:** BSW > 40%, Temperatura < 80°C
- **Ação:** Monitoramento intensificado

#### **CRÍTICO**
- **Cor:** Vermelho (#FF4444)
- **Condições:** Pressão < 2500 psi, GAS > 15000 m³
- **Ação:** Sirene + intervenção imediata

#### **EMERGÊNCIA**
- **Cor:** Vermelho piscante
- **Condições:** Shutdown automático acionado
- **Ação:** Parada total + investigação

---

### 🔊 **SISTEMA DE ÁUDIO - SIRENES DE BOMBEIRO**

#### **SIRENE CRÍTICA**
**📍 LOCALIZAÇÃO:** `main.cpp:emitirProcessAlarm`
**🎵 PADRÃO:** Sweep 400-1200-400 Hz (3 ciclos)
**⏱️ DURAÇÃO:** ~2.4 segundos
**🚨 TRIGGER:** Problemas críticos (pressão baixa, excesso gás)

#### **SIRENE ATENÇÃO**
**📍 LOCALIZAÇÃO:** `main.cpp:emitirCautelAlarm`
**🎵 PADRÃO:** Sweep 300-800-300 Hz (2 ciclos)
**⏱️ DURAÇÃO:** ~4.0 segundos
**🚨 TRIGGER:** Problemas moderados (BSW alto, temperatura baixa)

#### **SIRENE EVACUAÇÃO**
**📍 LOCALIZAÇÃO:** `main.cpp:emitirEvacuationAlarm`
**🎵 PADRÃO:** Sweep 200-1500-200 Hz (4 ciclos)
**⏱️ DURAÇÃO:** ~5.2 segundos
**🚨 TRIGGER:** Shutdown automático/emergência total

---

### ⚠️ **CONDIÇÕES DE SHUTDOWN AUTOMÁTICO**

**📍 LOCALIZAÇÃO:** `main.cpp:915-937` (método `verificarEmergencia`)

#### **PRESSÃO CRÍTICA BAIXA**
```cpp
if (pressao_psi < LIMITE_PRESSAO_CRITICO_MIN) {
    // 1650 psi - Limite de segurança
}
```

#### **PRESSÃO CRÍTICA ALTA**
```cpp
if (pressao_psi > LIMITE_PRESSAO_CRITICO_MAX) {
    // 4200 psi - Risco de blowout
}
```

#### **VISCOSIDADE CRÍTICA**
```cpp
if (viscosidade_oleo_cp > LIMITE_VISCOSIDADE_CRITICO) {
    // 4.5 cp - Óleo praticamente imóvel
}
```

#### **GAS-LOCK**
```cpp
if (volume_gas_m3 > LIMITE_GAS_CRITICO) {
    // 15000 m³ - Interferência de gás livre
}
```

#### **BSW CRÍTICO**
```cpp
if (water_oil_ratio > LIMITE_WOR_CRITICO) {
    // 35% - Produção principalmente água
}
```

#### **GOR CRÍTICO**
```cpp
if (gas_oil_ratio > LIMITE_GOR_CRITICO) {
    // 600 scf/bbl - Problemas de handling
}
```

---

## **[F] TERMOS TÉCNICOS E CONCEITOS**

### 📈 **IPR (Inflow Performance Relationship)**

**🔬 DEFINIÇÃO:**
Relação entre vazão de produção e diferencial de pressão (drawdown).

**📍 IMPLEMENTAÇÃO:** `main.cpp:800-832`

**🔧 EQUAÇÃO COMBINADA:**
```cpp
// Darcy para fluxo monofásico + Vogel para bifásico
vazao_calculada = PRODUTIVIDADE_POCO_C * drawdown_normalizado * eficiencia;
```

**🎯 COMPONENTES:**
- **Drawdown:** (Pressão estática - Pressão de fundo)
- **Eficiência:** Função da completação do poço
- **Skin Factor:** Danos próximos ao poço

---

### 🛢️ **OOIP (Original Oil In Place)**

**🔬 DEFINIÇÃO:**
Volume original de óleo no reservatório antes da produção.

**⚙️ ATS-7B HISTÓRICO:**
- **Original:** 280 milhões bbl
- **Restante:** 55 milhões bbl (2025)
- **Recovery Factor:** 80% (excelente)

**🎯 IMPORTÂNCIA:**
Base para cálculo de reservas e planejamento de produção.

---

### 💧 **BSW (Basic Sediments and Water)**

**🔬 DEFINIÇÃO:**
Percentual de água e sedimentos na produção total.

**⚙️ CÁLCULO:**
```
BSW = (Volume Água / Volume Total) × 100%
```

**🎯 IMPACTO ECONÔMICO:**
- **< 30%:** Operação rentável
- **30-60%:** Margem reduzida
- **> 60%:** Operação antieconômica

---

### ⛽ **GOR (Gas Oil Ratio)**

**🔬 DEFINIÇÃO:**
Volume de gás produzido por barril de óleo (scf/bbl).

**🎯 INDICADORES:**
- **Baixo GOR:** Óleo "morto", pouco gás em solução
- **Alto GOR:** Gás liberando da solução (pressure depletion)
- **GOR crescente:** Declínio normal do reservatório

---

### 🌡️ **Correlação de Andrade (Viscosidade)**

**🔬 DEFINIÇÃO:**
Equação empírica relacionando viscosidade com temperatura.

**📍 IMPLEMENTAÇÃO:** `main.cpp:773-790`

**🔧 FORMA GERAL:**
```
μ = A × exp(B/T)
```
Onde:
- **μ:** Viscosidade (cp)
- **A:** Constante dependente da pressão
- **B:** Energia de ativação
- **T:** Temperatura absoluta (K)

---

### 🔧 **Enhanced Oil Recovery (EOR)**

**🔬 DEFINIÇÃO:**
Métodos para aumentar recuperação além da primária e secundária.

**🎯 MÉTODOS IMPLEMENTADOS:**
- **Thermal EOR:** Injeção de vapor
- **Gas EOR:** Injeção de gás (miscível/imiscível)
- **Chemical EOR:** Não implementado (futuro)

---

## **[G] UNIDADES DE MEDIDA E CONVERSÕES**

### 📏 **SISTEMA DE UNIDADES PETRÓLEO**

#### **PRESSÃO**
- **psi:** Pounds per Square Inch
- **Conversão:** 1 bar = 14.504 psi
- **Faixa típica:** 1000-5000 psi

#### **TEMPERATURA**
- **°C:** Graus Celsius
- **°F:** Graus Fahrenheit
- **Conversão:** °F = (°C × 9/5) + 32

#### **VOLUME**
- **bbl:** Barril americano = 42 galões = 159 litros
- **m³:** Metro cúbico
- **Conversão:** 1 bbl = 0.159 m³

#### **VAZÃO**
- **bopd:** Barrels of Oil Per Day
- **m³/d:** Metros cúbicos por dia
- **Conversão:** 1 bopd = 0.159 m³/d

#### **GAS**
- **scf:** Standard Cubic Feet (condições padrão)
- **m³:** Metros cúbicos nas condições do reservatório
- **scf/bbl:** Razão gás-óleo padrão

#### **VISCOSIDADE**
- **cp:** Centipoise
- **cSt:** Centistokes (viscosidade cinemática)
- **Referência:** Água = 1 cp a 20°C

---

### 🔄 **CONVERSÕES IMPLEMENTADAS**

#### **TEMPERATURA (°C → °F)**
```cpp
double temp_F = temperatura_C * 9.0/5.0 + 32.0;
```

#### **VOLUME (bbl → MM bbl para gráficos)**
```cpp
volumeOleoSeries->append(tempoAtual, reservatorio->volume_oleo_bbl / 1000000.0);
```

#### **TEMPO (segundos → minutos)**
```cpp
double tempo_min = tempo_simulacao_s / 60.0;
```

#### **BSW (razão → percentual)**
```cpp
QString bsw_percent = QString::number(water_oil_ratio * 100, 'f', 1) + "%";
```

---

## 🎓 **REFERÊNCIAS TÉCNICAS**

### 📚 **NORMAS E PADRÕES**
- **NORSOK S-001:** Safety and Working Environment
- **API RP 14C:** Recommended Practice for Analysis, Design, Installation, and Testing of Safety Systems
- **ISO 15544:** Petroleum and natural gas industries - Offshore production installations - Requirements and guidelines for emergency response

### 🔬 **CORRELAÇÕES IMPLEMENTADAS**
- **Andrade:** Viscosidade vs temperatura
- **Standing:** Solubilidade de gás no óleo
- **Vogel:** IPR para fluxo bifásico
- **Darcy:** Lei de Darcy para fluxo em meio poroso

### 📊 **LITERATURA TÉCNICA**
- **Petroleum Engineering Handbook** (SPE)
- **Reservoir Engineering Handbook** (Tarek Ahmed)
- **Production Operations** (Ken Arnold)

---

**📅 Criado:** 30 de Agosto de 2025  
**🔧 Versão:** v1.0.0 - Glossário Completo  
**🎯 Cobertura:** 100% dos termos do simulador  
**📚 Status:** Referência técnica oficial