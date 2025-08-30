# ✅ CHECKLIST DE TESTES CRÍTICOS - SIMULADOR RESERVATORIO-01

## 🚨 TESTES OBRIGATÓRIOS ANTES DE QUALQUER RELEASE

### 🏗️ **TESTE 1: BUILD SYSTEM (CRÍTICO)**

#### ✅ Processo de Build Obrigatório:
```bash
# DEVE SEMPRE FUNCIONAR - SEM EXCEÇÕES
rm -rf build
mkdir build  
cd build
cmake ..
make
./reservatorio_01
```

#### 🔍 Validações Build:
- [ ] CMake encontra todas as dependências Qt5
- [ ] Makefile é gerado corretamente na pasta build/
- [ ] Compilação sem warnings críticos
- [ ] Executável criado em build/reservatorio_01
- [ ] Nenhum arquivo de build na raiz do projeto

#### ❌ Falhas NÃO Aceitáveis:
- Build na raiz do projeto
- CMake não encontrando Qt5
- Makefile não gerado
- Executável na pasta errada

---

### 🧮 **TESTE 2: CÁLCULOS FÍSICOS (CRÍTICO)**

#### ✅ Valores de Inicialização:
```cpp
// VALORES INICIAIS CORRETOS - NÃO PODEM SER ALTERADOS
pressao_psi(2850.0),              // ✅ Pressão inicial correta
temperatura_C(92.0),              // ✅ Temperatura geotérmica  
vazao_oleo_bopd(1247.8),         // ✅ Vazão operacional típica
volume_oleo_bbl(125000.0),       // ✅ OOIP restante realístico
gas_oil_ratio(420.0),            // ✅ GOR normal para campo
water_oil_ratio(0.23),           // ✅ 23% BSW típico
viscosidade_oleo_cp(2.8),        // ✅ Viscosidade normal
```

#### 🔍 Validações de Cálculo:
- [ ] **Pressão:** Sempre entre 1800-4500 psi (limites de segurança)
- [ ] **Temperatura:** Sempre entre 60-120°C (geotermicamente realista)  
- [ ] **Vazão:** Declínio natural <5% por ciclo
- [ ] **Volume:** Nunca negativo, decresce com produção
- [ ] **GOR:** Aumenta com queda de pressão (físicamente correto)
- [ ] **WOR:** Aumenta com tempo (water coning natural)
- [ ] **Viscosidade:** Correlação correta com temperatura

#### ❌ Falhas NÃO Aceitáveis:
- Pressão negativa ou >5000 psi
- Temperatura <0°C ou >150°C  
- Vazão aumentando sem intervenção
- Volume de óleo negativo
- GOR diminuindo com queda de pressão
- Viscosidade incorreta vs temperatura

---

### ⚙️ **TESTE 3: SISTEMA DE INTERVENÇÕES (CRÍTICO)**

#### ✅ Injeção de Água:
```bash
# TESTE: Injetar 1000 bbl de água a 60°C
# RESULTADO ESPERADO: Pressão deve AUMENTAR
# CÁLCULO: ΔP ≈ +50-100 psi (dependendo das condições)
```
- [ ] Pressão aumenta após injeção
- [ ] Volume de água incrementado corretamente  
- [ ] Temperatura do reservatório influenciada
- [ ] Log de ação registrado corretamente

#### ✅ Injeção de Gás:
```bash
# TESTE: Injetar 5000 m³ de gás
# RESULTADO ESPERADO: GOR deve DIMINUIR, pressão AUMENTAR  
```
- [ ] GOR diminui (gás livre reduzido)
- [ ] Pressão aumenta (support pressure)
- [ ] Volume de gás corretamente ajustado

#### ✅ Injeção de Vapor:
```bash
# TESTE: Injetar vapor por 300s
# RESULTADO ESPERADO: Temperatura e viscosidade alteradas
```
- [ ] Temperatura aumenta significativamente
- [ ] Viscosidade diminui (correlação Andrade)
- [ ] Recuperação térmica simulada

#### ✅ Válvula de Alívio:
```bash
# TESTE: Ativar com pressão >4000 psi  
# RESULTADO ESPERADO: Pressão reduzida para ~3500 psi
```
- [ ] Pressão reduzida em 30% do excesso
- [ ] Nunca reduz abaixo de 3500 psi
- [ ] Log de segurança registrado

#### ✅ Sistema de Aquecimento:
```bash
# TESTE: Ativar com temperatura <80°C
# RESULTADO ESPERADO: Aquecimento gradual até 90°C
```
- [ ] Temperatura aumenta 50% da diferença
- [ ] Viscosidade recalculada automaticamente
- [ ] Não ultrapassa limites físicos

#### ✅ Estimulação de Poço:
```bash  
# TESTE: Ativar com vazão <500 bopd
# RESULTADO ESPERADO: Incremento de 100 bopd
```
- [ ] Vazão aumentada em exatamente 100 bopd
- [ ] Não quebra leis físicas do reservatório

#### ❌ Falhas NÃO Aceitáveis:
- Intervenção sem efeito nos parâmetros
- Efeito contrário ao esperado (ex: injeção água diminui pressão)
- Valores não-físicos após intervenção
- Intervenção funcionando durante emergência

---

### 🚨 **TESTE 4: SISTEMA DE ALERTAS (CRÍTICO)**

#### ✅ Limites de Alerta Corretos:
```cpp
// LIMITES CRÍTICOS - NÃO PODEM SER ALTERADOS
LIMITE_PRESSAO_CRITICO_MIN = 1800.0;   // psi
LIMITE_PRESSAO_CRITICO_MAX = 4500.0;   // psi
LIMITE_VISCOSIDADE_CRITICO = 20.0;     // cp  
LIMITE_GAS_CRITICO = 25000.0;          // m³
LIMITE_WOR_CRITICO = 0.95;             // 95%
LIMITE_GOR_CRITICO = 2000.0;           // scf/bbl
```

#### 🔍 Validações de Alerta:
- [ ] **Pressão Baixa:** Alerta crítico <2500 psi, shutdown <1800 psi
- [ ] **Pressão Alta:** Alerta crítico >4000 psi, shutdown >4500 psi
- [ ] **Excesso Gás:** Alerta crítico >15000 m³, shutdown >25000 m³
- [ ] **BSW Alto:** Alerta atenção >40%, crítico >60%
- [ ] **GOR Alto:** Alerta atenção >1000, crítico >1500 scf/bbl
- [ ] **Viscosidade:** Alerta atenção >10 cp, crítico >20 cp

#### ✅ Comportamento de Emergência:
```bash
# TESTE: Forçar shutdown automático
# RESULTADO ESPERADO: vazao_oleo_bopd = 0.0, em_emergencia = true
```
- [ ] Shutdown automático quando limites críticos ultrapassados
- [ ] Vazão zerrada imediatamente
- [ ] Flag em_emergencia = true  
- [ ] Intervenções bloqueadas durante emergência
- [ ] Motivo detalhado de shutdown registrado

#### ❌ Falhas NÃO Aceitáveis:
- Alerta sem causa ou com valores normais  
- Shutdown não funcionando nos limites críticos
- Produção continuando durante emergência
- Intervenções permitidas em emergência

---

### 🔊 **TESTE 5: SISTEMA DE ÁUDIO (CRÍTICO)**

#### ✅ Teste de Inicialização:
```bash
# AOS 10-11 SEGUNDOS: Deve tocar teste de áudio
# SOM: 400 Hz seguido de 600 Hz  
# LOG: "Platform Audio System: Operacional"
```
- [ ] Som de teste audível aos 10-11s
- [ ] Log de confirmação aparece
- [ ] Sistema inicializado sem falhas

#### ✅ Sirene Crítica:
```bash
# TRIGGER: Problema crítico (pressão baixa, excesso gás)
# SOM: Sweep 400-1200-400 Hz (3 ciclos rápidos)
# DURAÇÃO: ~2.4 segundos total
```
- [ ] Som tipo bombeiro - sweep audível
- [ ] 3 ciclos completos executados  
- [ ] Frequências 400→1200→400 Hz detectáveis
- [ ] Log "FIRE DEPT SIREN: CRITICO pattern emitted"

#### ✅ Sirene Atenção:
```bash
# TRIGGER: Problema moderado (BSW alto, temperatura baixa)  
# SOM: Sweep 300-800-300 Hz (2 ciclos médios)
# DURAÇÃO: ~4.0 segundos total
```
- [ ] Som mais grave que crítico
- [ ] 2 ciclos completos executados
- [ ] Frequências 300→800→300 Hz detectáveis

#### ✅ Sirene Evacuação:
```bash
# TRIGGER: Shutdown automático / emergência total
# SOM: Sweep 200-1500-200 Hz (4 ciclos ultra-rápidos)
# DURAÇÃO: ~5.2 segundos total  
```
- [ ] Som mais intenso e rápido
- [ ] 4 ciclos completos executados
- [ ] Faixa completa 200-1500 Hz coberta

#### ❌ Falhas NÃO Aceitáveis:
- Ausência de som quando deveria tocar
- Som errado para o tipo de alerta
- Sistema de áudio travando interface
- Sirene tocando sem motivo

---

### 🕐 **TESTE 6: SISTEMA DE TEMPO (CRÍTICO)**

#### ✅ Relógio em Tempo Real:
```bash
# POSIÇÃO: Lado direito do logo "Aggressive Oil Club"
# FORMATO: 🕐 HH:MM:SS (ex: 🕐 14:32:18)  
# ATUALIZAÇÃO: A cada 1 segundo
```
- [ ] Hora atual mostrada corretamente
- [ ] Formato HH:MM:SS respeitado
- [ ] Atualização visível a cada segundo
- [ ] Ícone 🕐 presente

#### ✅ Contador de Operação:
```bash
# POSIÇÃO: Abaixo do relógio atual
# FORMATO: ⏱️ HH:MM:SS (ex: ⏱️ 02:15:42)
# FUNÇÃO: Tempo desde inicialização
```
- [ ] Contador inicia em 00:00:00
- [ ] Incrementa corretamente a cada segundo
- [ ] Não reseta durante operação
- [ ] Ícone ⏱️ presente

#### ✅ Posicionamento Visual:
- [ ] Container de 180x70px ao lado do logo
- [ ] Fonte Courier New monospace
- [ ] Cores: verde (#00FF88) para hora, laranja (#FFA500) para contador
- [ ] Background #1a1a1a com borda #333333

#### ❌ Falhas NÃO Aceitáveis:
- Relógio não atualiza ou está incorreto
- Contador reseta ou não funciona
- Posicionamento fora do local especificado
- Fontes ou cores incorretas

---

### 📊 **TESTE 7: GRÁFICOS EM TEMPO REAL (CRÍTICO)**

#### ✅ Atualização de Dados:
```bash
# PERIODICIDADE PADRÃO: 60 segundos (1 minuto)
# GRÁFICOS: 7 séries de dados simultâneas  
# LIMITE: Máximo 500 pontos por série
```
- [ ] Dados atualizados conforme período selecionado
- [ ] Todos os 7 gráficos funcionando simultaneamente
- [ ] Limitação de 500 pontos funcionando (performance)
- [ ] Seletor de período operacional

#### ✅ Dados Realísticos:
- [ ] **Produção:** Declínio natural visível
- [ ] **Pressão:** Correlação com produção  
- [ ] **Volume:** Diminuição progressiva
- [ ] **Temperatura:** Estabilidade com variações
- [ ] **Viscosidade:** Correlação com temperatura
- [ ] **GOR:** Tendência de aumento com tempo
- [ ] **WOR:** Aumento gradual (water coning)

#### ❌ Falhas NÃO Aceitáveis:
- Gráficos não atualizando
- Dados não-físicos ou impossíveis
- Performance degradada (lag visual)
- Gráficos dessincronizados

---

### 💾 **TESTE 8: EXPORTAÇÃO CSV (CRÍTICO)**

#### ✅ Estrutura do Arquivo:
```csv
# LOCALIZAÇÃO: /home/wolf/Documentos/desenvolvimento/reservatorio-01/simulacao_petroleo.csv
# COLUNAS: 12 campos obrigatórios
# FORMATO: UUID na primeira coluna, data_hora na segunda
```
- [ ] Arquivo criado na raiz do projeto
- [ ] UUID único para cada linha
- [ ] data_hora em formato ISO
- [ ] 12 colunas conforme especificado
- [ ] Dados numéricos com precisão adequada

#### ✅ Conteúdo dos Dados:
- [ ] **UUID:** Formato válido para Kafka
- [ ] **data_hora:** Timestamp correto da coleta
- [ ] **Parâmetros físicos:** Valores atuais do reservatório
- [ ] **ultimo_evento_operador:** Última ação manual registrada
- [ ] **ultimo_evento_fisica:** Último evento automático
- [ ] **tipo_alerta:** Nível de alerta no momento

#### ❌ Falhas NÃO Aceitáveis:
- Arquivo não criado ou local errado
- Dados corrompidos ou inválidos
- Estrutura CSV quebrada
- UUID duplicados

---

### 🎮 **TESTE 9: INTEGRAÇÃO COMPLETA (CRÍTICO)**

#### ✅ Cenário de Teste Completo:
```bash
# SEQUÊNCIA DE TESTE OBRIGATÓRIA:
1. Build correto (rm -rf build && mkdir build && cd build && cmake .. && make)
2. Executar (./reservatorio_01) 
3. Aguardar 11s - confirmar teste de áudio
4. Injetar problema crítico - confirmar sirene + alerta visual
5. Aplicar solução - confirmar correção dos parâmetros  
6. Exportar CSV - confirmar arquivo gerado
7. Verificar gráficos - confirmar atualização visual
8. Testar emergência - confirmar shutdown automático
9. Normalizar - confirmar volta ao normal
10. Fechar aplicação sem erros
```

#### 📋 **Resultado Esperado:**
- [ ] Todos os 10 passos executam sem falhas
- [ ] Sistema responde conforme esperado em cada etapa  
- [ ] Nenhum crash ou erro crítico
- [ ] Performance aceitável (sem lag perceptível)
- [ ] Dados consistentes do início ao fim

#### ❌ Falhas NÃO Aceitáveis:
- Qualquer falha nos 10 passos
- Crash ou erro fatal
- Dados inconsistentes
- Performance inaceitável

---

## 🔧 COMANDOS DE TESTE RÁPIDO

### ⚡ Teste Build (30 segundos):
```bash
cd /home/wolf/Documentos/desenvolvimento/reservatorio-01
rm -rf build && mkdir build && cd build && cmake .. && make && ls -la reservatorio_01
```

### 🎵 Teste Audio (10 segundos):
```bash
speaker-test -t sine -f 800 -l 1 -s 1 > /dev/null 2>&1; echo "Audio OK"
```

### 📊 Teste Cálculos (Inspeção visual):
```bash
./reservatorio_01
# Verificar valores iniciais na interface:
# Pressão: ~2850 psi ✅
# Temperatura: ~92°C ✅  
# Vazão: ~1247 bopd ✅
```

### 💾 Teste CSV (Verificar arquivo):
```bash
ls -la ../simulacao_petroleo.csv && head -3 ../simulacao_petroleo.csv
```

---

## 🚨 CRITÉRIOS DE ACEITAÇÃO

### ✅ **APROVADO SE:**
- [ ] Build 100% funcional na pasta `/build/`
- [ ] Todos os cálculos físicos corretos
- [ ] Sistema de áudio operacional com 3 sirenes diferenciadas
- [ ] Alertas funcionando nos limites corretos
- [ ] Tempo real e contador operacionais
- [ ] Gráficos atualizando corretamente
- [ ] CSV exportado com estrutura correta
- [ ] Integração completa sem falhas

### ❌ **REPROVADO SE:**
- Qualquer falha nos testes críticos
- Build não funciona na pasta correta  
- Cálculos físicos incorretos
- Sistema de áudio não funcional
- Dados inconsistentes ou não-físicos
- Performance inaceitável

---

**📋 ESTE CHECKLIST DEVE SER EXECUTADO COMPLETAMENTE ANTES DE QUALQUER RELEASE**  
**🚨 ZERO TOLERÂNCIA PARA FALHAS NOS TESTES CRÍTICOS**  
**✅ TODOS OS ITENS DEVEM ESTAR MARCADOS ANTES DA APROVAÇÃO**

---

**📅 Criado:** 29 de Agosto de 2025  
**🔧 Versão:** v2.3.0 - Sistema Completo  
**🎯 Cobertura:** 100% das funcionalidades críticas  
**⚠️ Status:** OBRIGATÓRIO para qualquer release