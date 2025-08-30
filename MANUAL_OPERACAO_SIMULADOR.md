# 🎮 MANUAL DE OPERAÇÃO - SIMULADOR DE RESERVATÓRIO PETROLÍFERO ATS-7B

## 📋 ÍNDICE DE CONTEÚDO

- **[1] INTRODUÇÃO E PRIMEIROS PASSOS**
- **[2] INTERFACE DO USUÁRIO - SCADA PROFISSIONAL**
- **[3] MONITORAMENTO DE PARÂMETROS**
- **[4] SISTEMA DE ALERTAS E SIRENES**
- **[5] OPERAÇÕES E INTERVENÇÕES**
- **[6] RESOLUÇÃO DE PROBLEMAS**
- **[7] CENÁRIOS OPERACIONAIS PRÁTICOS**
- **[8] EXPORTAÇÃO E RELATÓRIOS**
- **[9] BOAS PRÁTICAS E SEGURANÇA**
- **[10] TROUBLESHOOTING**

---

## **[1] INTRODUÇÃO E PRIMEIROS PASSOS**

### 🎯 **O QUE É O SIMULADOR ATS-7B?**

O **Simulador de Reservatório Petrolífero ATS-7B** é uma ferramenta educacional e de treinamento que replica fielmente as operações de um campo de petróleo real. Desenvolvido com base em dados históricos e correlações da indústria, permite que estudantes e profissionais pratiquem operações críticas sem riscos reais.

### ⚡ **INSTALAÇÃO E EXECUÇÃO**

#### **PASSO 1: Build do Sistema**
```bash
# SEMPRE execute na pasta correta
cd /home/wolf/Documentos/desenvolvimento/reservatorio-01
rm -rf build
mkdir build
cd build
cmake ..
make
```

#### **PASSO 2: Executar o Simulador**
```bash
# Execute SEMPRE dentro da pasta build
./reservatorio_01
```

⚠️ **IMPORTANTE:** O build deve SEMPRE ser feito na pasta `/build/`. Nunca execute na raiz do projeto.

### 🎵 **PRIMEIRO TESTE - SISTEMA DE ÁUDIO**

**⏰ AOS 10-11 SEGUNDOS:** O sistema emitirá um teste de áudio automático:
- **Som:** 400 Hz seguido de 600 Hz
- **Log:** "Platform Audio System: Operacional"
- **Status:** ✅ Sistema pronto para operar

Se não ouvir o som, verifique:
1. Volume do sistema operacional
2. Conexão de alto-falantes
3. Permissões do ALSA/PulseAudio

---

## **[2] INTERFACE DO USUÁRIO - SCADA PROFISSIONAL**

### 📊 **LAYOUT PRINCIPAL**

A interface segue padrões industriais SCADA com 4 seções principais:

#### **🕐 ÁREA DE TEMPO (Superior Direita)**
```
🕐 14:32:18          ← Hora atual do sistema
⏱️ 02:15:42          ← Tempo de operação (HH:MM:SS)
```

#### **📈 INDICADORES NUMÉRICOS (Esquerda)**
```
🚢 Vazão: 22,000.00 bopd     [Produção de óleo]
🌡️ Pressão: 2,850.00 psi     [Pressão do reservatório] 
🛢️ Volume: 55,000,000 bbl    [Óleo restante]
🌡️ Temperatura: 92.0°C       [Temperatura da formação]
🌯 Viscosidade: 2.8 cp       [Resistência ao fluxo]
⛽ GOR: 420.0 scf/bbl        [Razão gás-óleo]
💧 WOR: 23.0%                [Corte de água]
```

#### **📊 GRÁFICOS EM TEMPO REAL (Centro)**
- **7 gráficos simultâneos** mostrando tendências
- **Controle de periodicidade:** 1min até 1 dia
- **Limitação:** 500 pontos por série (performance)

#### **🎛️ CONTROLES DE INTERVENÇÃO (Direita)**
```
💧 Injeção de Água      🔥 Injeção de Vapor
⛽ Injeção de Gás       ⚖️ Válvula de Alívio  
🔥 Sistema Aquecimento  🚀 Estimulação Poço
```

---

## **[3] MONITORAMENTO DE PARÂMETROS**

### 📈 **INTERPRETAÇÃO DOS VALORES**

#### **🚢 VAZÃO DE ÓLEO (bopd)**
```
✅ EXCELENTE:  > 20,000 bopd  (Produção alta)
🟡 BOM:        12,000-20,000  (Produção adequada)
🟠 ATENÇÃO:    8,000-12,000   (Abaixo do ótimo)
🔴 CRÍTICO:    < 8,000 bopd   (Antieconômico)
```

**TENDÊNCIA NORMAL:** Declínio natural de 2-5% ao mês

#### **🌡️ PRESSÃO (psi)**
```
🔴 PERIGO:     > 4,200 psi    (Risco blowout)
🟠 ALTO:       4,000-4,200    (Alerta crítico)
✅ NORMAL:     2,500-4,000    (Operação segura)
🟡 BAIXO:      1,800-2,500    (Atenção)
🔴 CRÍTICO:    < 1,800 psi    (Shutdown)
```

**TENDÊNCIA NORMAL:** Declínio gradual com produção

#### **🌡️ TEMPERATURA (°C)**
```
✅ IDEAL:      85-100°C       (Viscosidade baixa)
🟡 ADEQUADO:   80-85°C        (Ainda operável)
🟠 BAIXO:      60-80°C        (Viscosidade alta)
🔴 CRÍTICO:    < 60°C         (Problemas de fluxo)
```

#### **🌯 VISCOSIDADE (cp)**
```
✅ EXCELENTE:  1.8-3.0 cp     (Fluxo fácil)
🟡 BOM:        3.0-4.5 cp     (Fluxo normal)
🟠 ALTO:       4.5-10 cp      (Resistente)
🔴 CRÍTICO:    > 10 cp        (Quase imóvel)
```

#### **⛽ GOR (scf/bbl)**
```
✅ NORMAL:     300-500        (Gás em solução)
🟡 ELEVADO:    500-600        (Liberando gás)
🟠 ALTO:       600-1,000      (Problema moderado)
🔴 CRÍTICO:    > 1,000        (Excesso de gás)
```

#### **💧 WOR/BSW (%)**
```
✅ EXCELENTE:  < 20%          (Pouca água)
🟡 BOM:        20-30%         (Aceitável)
🟠 MODERADO:   30-40%         (Water coning)
🔴 ALTO:       > 40%          (Antieconômico)
```

### 🎨 **CÓDIGO DE CORES DOS ÍCONES**

- **🟢 VERDE:** Parâmetro dentro da faixa ideal
- **🟡 AMARELO:** Atenção, monitorar de perto
- **🟠 LARANJA:** Problema moderado, intervenção recomendada
- **🔴 VERMELHO:** Situação crítica, ação imediata

---

## **[4] SISTEMA DE ALERTAS E SIRENES**

### 🚨 **HIERARQUIA DE ALERTAS**

#### **🟢 NORMAL**
- **Status:** "OPERAÇÃO NORMAL"
- **Som:** Silêncio (apenas teste inicial)
- **Ação:** Monitoramento de rotina

#### **🟡 ATENÇÃO**
- **Triggers:** BSW > 40%, Temperatura < 80°C
- **Status:** "ATENÇÃO - MONITORAR"
- **Som:** Sirene média (300-800-300 Hz, 2 ciclos)
- **Duração:** ~4.0 segundos
- **Ação:** Análise e planejamento de intervenção

#### **🔴 CRÍTICO**
- **Triggers:** Pressão < 2500 psi, Excesso gás > 15000 m³
- **Status:** "ALERTA CRÍTICO"
- **Som:** Sirene aguda (400-1200-400 Hz, 3 ciclos)
- **Duração:** ~2.4 segundos
- **Ação:** Intervenção imediata obrigatória

#### **🚨 EMERGÊNCIA**
- **Triggers:** Shutdown automático acionado
- **Status:** "EMERGÊNCIA - SHUTDOWN"
- **Som:** Sirene evacuação (200-1500-200 Hz, 4 ciclos)
- **Duração:** ~5.2 segundos
- **Ação:** Parada total, investigação completa

### 🔊 **INTERPRETAÇÃO DOS SONS**

#### **SIRENE TIPO BOMBEIRO - CRÍTICA**
```
🎵 Padrão: UUUUUU-uuuuuu-UUUUUU (3x)
🎯 Situação: Pressão baixa, excesso de gás
💡 Ação: "Algo está errado e precisa ser corrigido AGORA"
```

#### **SIRENE TIPO AMBULÂNCIA - ATENÇÃO**
```
🎵 Padrão: uuuUUU-uuuUUU (2x, mais lenta)
🎯 Situação: BSW alto, temperatura baixa
💡 Ação: "Situação deteriorando, planeje intervenção"
```

#### **SIRENE EVACUAÇÃO - EMERGÊNCIA**
```
🎵 Padrão: uuuUUUUUUuuu (4x, muito rápida)
🎯 Situação: Sistema em shutdown automático
💡 Ação: "Pare tudo e investigue imediatamente"
```

---

## **[5] OPERAÇÕES E INTERVENÇÕES**

### 💧 **INJEÇÃO DE ÁGUA**

#### **QUANDO USAR:**
- Pressão caindo rapidamente (< 2800 psi)
- Declínio de produção acelerado
- Manutenção preventiva de pressão

#### **COMO OPERAR:**
1. **Clique:** Botão "💧 Injeção de Água"
2. **Volume:** Digite valor recomendado (geralmente 15.000-25.000 bbl/dia)
3. **Temperatura:** Recomendado 60°C (padrão)
4. **Confirme:** Pressione "Injetar"

#### **RESULTADOS ESPERADOS:**
- **Pressão:** Aumento de 50-150 psi
- **Produção:** Estabilização ou leve aumento
- **Tempo:** Efeito em 1-2 ciclos de atualização

#### **⚠️ CUIDADOS:**
- Volume muito alto → Water breakthrough
- Temperatura inadequada → Choque térmico
- Qualidade da água → Incompatibilidade

### ⛽ **INJEÇÃO DE GÁS**

#### **QUANDO USAR:**
- GOR muito baixo (< 300 scf/bbl)
- Pressão em declínio natural
- Necessidade de gas lift

#### **COMO OPERAR:**
1. **Clique:** Botão "⛽ Injeção de Gás"
2. **Volume:** 8.000-15.000 m³/dia típico
3. **Densidade:** 0.8 (padrão gás natural)
4. **Confirme:** Pressione "Injetar"

#### **RESULTADOS ESPERADOS:**
- **Pressão:** Aumento sustentado
- **GOR:** Redução (gás vai para solução)
- **Vazão:** Possível aumento (gas lift effect)

### 🔥 **INJEÇÃO DE VAPOR**

#### **QUANDO USAR:**
- Viscosidade muito alta (> 4 cp)
- Temperatura baixa (< 85°C)
- Recuperação térmica de óleo pesado

#### **COMO OPERAR:**
1. **Clique:** Botão "🔥 Injeção de Vapor"
2. **Tempo:** 300-600 segundos típico
3. **Confirme:** Pressione "Injetar"

#### **RESULTADOS ESPERADOS:**
- **Temperatura:** Aumento significativo (+10-20°C)
- **Viscosidade:** Redução drástica (-30-50%)
- **Mobilidade:** Melhora substancial do fluxo

### ⚖️ **VÁLVULA DE ALÍVIO**

#### **QUANDO USAR:**
- Pressão > 4000 psi
- Risco iminente de blowout
- Emergência de sobrepressão

#### **CONFIGURAÇÃO PADRÃO:**
- **Pressão abertura:** 3500 psi
- **Taxa alívio:** 20%
- **Ação:** Automática quando necessário

### 🔥 **SISTEMA DE AQUECIMENTO**

#### **QUANDO USAR:**
- Temperatura < 80°C
- Viscosidade > 4 cp
- Prevenção de parafinação

#### **CONFIGURAÇÃO:**
- **Temperatura alvo:** 90°C
- **Potência:** 150 kW
- **Ação:** Gradual, 50% da diferença por ciclo

### 🚀 **ESTIMULAÇÃO DE POÇO**

#### **QUANDO USAR:**
- Vazão < 12.000 bopd com pressão OK
- Produtividade reduzida
- Skin damage suspeito

#### **CONFIGURAÇÃO:**
- **Incremento garantido:** +100 bopd
- **Aplicação:** Instantânea
- **Duração:** Permanente (até próxima intervenção)

---

## **[6] RESOLUÇÃO DE PROBLEMAS**

### 🔧 **DIAGNÓSTICO POR SINTOMAS**

#### **🚨 PROBLEMA: "PRODUÇÃO CAINDO RAPIDAMENTE"**

**📋 CHECKLIST DIAGNÓSTICO:**
```
✅ Verificar pressão atual vs histórico
✅ Analisar tendência de declínio (>5%/mês = problema)
✅ Avaliar BSW (water breakthrough?)
✅ Conferir GOR (gas coning?)
✅ Temperatura e viscosidade OK?
```

**🎯 SOLUÇÕES PRIORIZADAS:**
1. **Se pressão baixa:** Injeção de água
2. **Se BSW alto súbito:** Investigar water coning
3. **Se GOR alto súbito:** Considerar gas coning
4. **Se viscosidade alta:** Sistema de aquecimento

#### **🚨 PROBLEMA: "PRESSÃO MUITO BAIXA" (< 2500 psi)**

**🔊 ALERTA:** Sirene crítica ativada!

**⚡ AÇÃO IMEDIATA:**
```
PASSO 1: Avaliar taxa de declínio
├─ Rápida (>50 psi/dia) → Vazamento ou influxo água
├─ Normal (5-10 psi/dia) → Depleção natural
└─ Muito lenta → Problema de medição

PASSO 2: Aplicar solução
├─ Injeção de água (volume alto: 20.000+ bbl/dia)
├─ Reduzir produção temporariamente
└─ Monitorar resposta em 2-3 ciclos
```

#### **🚨 PROBLEMA: "EXCESSO DE GÁS" (> 15.000 m³)**

**🔊 ALERTA:** Sirene crítica + risco gas-lock!

**⚡ AÇÃO IMEDIATA:**
```
PASSO 1: Ativar liberação de gás
├─ Usar sistema de flare/queima
├─ Reduzir pressão de cabeça
└─ NÃO injetar mais gás!

PASSO 2: Investigar causa
├─ Gas coning (GOR alto súbito)
├─ Pressão muito baixa (gás saindo de solução)
└─ Injeção inadequada de gás
```

#### **🚨 PROBLEMA: "TEMPERATURA BAIXA" (< 80°C)**

**🔊 ALERTA:** Sirene atenção (viscosidade subindo)

**⚡ SOLUÇÕES:**
1. **Ativar Sistema Aquecimento** (90°C, 150kW)
2. **Injeção de Vapor** (300-600 segundos)
3. **Monitorar viscosidade** (deve cair)

#### **🚨 PROBLEMA: "BSW MUITO ALTO" (> 40%)**

**🔊 ALERTA:** Sirene atenção (water breakthrough)

**⚡ ANÁLISE:**
```
BSW 40-60%: Ainda operável, mas margem baixa
├─ Reduzir vazão de produção
├─ Otimizar estratégia de injeção água
└─ Monitorar tendência

BSW > 60%: Operação antieconômica
├─ Considerar workover
├─ Avaliar shut-in temporário
└─ Revisar completação
```

### ⚠️ **SHUTDOWN AUTOMÁTICO - EMERGÊNCIA**

#### **QUANDO ACONTECE:**
- Pressão < 1650 psi OU > 4200 psi
- Viscosidade > 4.5 cp
- Excesso gás > 15.000 m³
- BSW > 35% OU GOR > 600 scf/bbl

#### **O QUE FAZER:**
```
🚨 RESPOSTA À EMERGÊNCIA:

PASSO 1: AVALIAR SITUAÇÃO
├─ Ler mensagem de shutdown detalhada
├─ Identificar parâmetro que causou parada
└─ Avaliar tendência que levou ao problema

PASSO 2: CORRIGIR CAUSA RAIZ
├─ Aplicar intervenção específica apropriada
├─ Aguardar estabilização (2-3 ciclos)
└─ Confirmar parâmetros dentro dos limites

PASSO 3: REINICIAR OPERAÇÃO
├─ Sistema sai automaticamente de emergência
├─ Produção retoma quando parâmetros OK
└─ Monitorar de perto por 10-15 minutos
```

---

## **[7] CENÁRIOS OPERACIONAIS PRÁTICOS**

### 🎓 **CENÁRIO 1: OPERAÇÃO DE ROTINA**

**📋 SITUAÇÃO INICIAL:**
```
🚢 Vazão: 22.000 bopd    ✅ Excelente
🌡️ Pressão: 2.850 psi   ✅ Normal
🌯 Viscosidade: 2.8 cp   ✅ Baixa
💧 BSW: 23%             ✅ Aceitável
```

**🎯 OBJETIVOS:**
- Manter produção > 20.000 bopd
- Evitar declínio > 5% ao mês
- BSW estável < 30%
- Pressão > 2.500 psi

**📈 AÇÕES PREVENTIVAS:**
1. **Monitoramento:** Verificar gráficos a cada 30min
2. **Manutenção de Pressão:** Injeção água quando < 2.800 psi
3. **Controle Térmico:** Aquecimento se temperatura < 85°C

### 🎓 **CENÁRIO 2: DECLÍNIO ACELERADO**

**📋 SITUAÇÃO EMERGENTE:**
```
🚢 Vazão: 18.500 bopd    🟡 Caindo 15%/mês
🌡️ Pressão: 2.600 psi   🟡 Baixa, caindo
💧 BSW: 32%             🟠 Subindo
⛽ GOR: 480 scf/bbl     🟡 Aumentando
```

**🔊 ALERTAS:** Sirene atenção ativada

**⚡ PLANO DE AÇÃO:**
```
FASE 1: ESTABILIZAÇÃO (0-2 horas)
├─ Injeção água: 20.000 bbl/dia @ 60°C
├─ Monitorar resposta de pressão
└─ Aguardar estabilização BSW

FASE 2: OTIMIZAÇÃO (2-8 horas)
├─ Ajustar volume injeção conforme resposta
├─ Se temperatura < 85°C → aquecimento
└─ Avaliar necessidade estimulação

FASE 3: MONITORAMENTO (8-24 horas)
├─ Confirmar estabilização tendências
├─ Produção alvo: > 19.000 bopd
└─ BSW estável < 35%
```

### 🎓 **CENÁRIO 3: EMERGÊNCIA CRÍTICA**

**📋 SITUAÇÃO CRÍTICA:**
```
🚢 Vazão: 8.500 bopd     🔴 Antieconômica
🌡️ Pressão: 2.200 psi   🔴 Crítica
🌯 Viscosidade: 4.8 cp   🔴 Muito alta
💧 BSW: 45%             🔴 Antieconômica
```

**🔊 ALERTAS:** Sirene crítica + múltiplos alarmes

**🚨 RESPOSTA DE EMERGÊNCIA:**
```
MINUTO 0-5: AVALIAÇÃO RÁPIDA
├─ Confirmar leituras em múltiplos pontos
├─ Descartar falsos alarmes
└─ Identificar causa primária

MINUTO 5-15: INTERVENÇÃO MÚLTIPLA
├─ Injeção água: 25.000 bbl/dia (máxima)
├─ Sistema aquecimento: 90°C, 150kW
├─ Injeção vapor: 600 segundos
└─ Estimulação: +100 bopd garantido

MINUTO 15-60: MONITORAMENTO INTENSIVO
├─ Verificar resposta a cada 5 minutos
├─ Ajustar intervenções conforme resposta
└─ Preparar para possível shutdown
```

### 🎓 **CENÁRIO 4: RECUPERAÇÃO PÓS-SHUTDOWN**

**📋 SITUAÇÃO PÓS-EMERGÊNCIA:**
```
Status: "EMERGÊNCIA - SHUTDOWN"
Causa: "PRESSÃO CRÍTICA BAIXA: 1580 psi"
Vazão: 0.0 bopd (sistema parado)
```

**🔊 ALERTA:** Sirene evacuação

**🔧 PROCEDIMENTO REINICIALIZAÇÃO:**
```
ETAPA 1: DIAGNÓSTICO (15-30 min)
├─ Análise detalhada da causa do shutdown
├─ Revisão histórico 24h antes da parada
├─ Identificação de fatores contribuintes
└─ Plano de correção específico

ETAPA 2: CORREÇÃO (30-90 min)
├─ Aplicar intervenção para causa raiz
├─ Exemplo: Pressão baixa → Injeção água massiva
├─ Aguardar parâmetros voltarem aos limites
└─ Pressão alvo: > 1800 psi para reiniciar

ETAPA 3: REINICIALIZAÇÃO (5-15 min)
├─ Sistema sai automaticamente de emergência
├─ Produção retoma gradualmente
├─ Monitoramento a cada 2 minutos
└─ Confirmar estabilidade por 1 hora
```

---

## **[8] EXPORTAÇÃO E RELATÓRIOS**

### 📊 **SISTEMA DE CSV AUTOMÁTICO**

#### **📁 LOCALIZAÇÃO:**
```
Arquivo: simulacao_petroleo.csv
Local: /home/wolf/Documentos/desenvolvimento/reservatorio-01/
```

#### **📋 ESTRUTURA DE DADOS:**
```
uuid,data_hora,tempo_min,vazao_oleo_bopd,pressao_psi,
viscosidade_cp,volume_oleo_bbl,temperatura_C,GOR,WOR,
evento_operador,evento_fisica,alerta_tipo
```

#### **🎯 INTERPRETAÇÃO:**
- **UUID:** Identificador único para Kafka streaming
- **data_hora:** Timestamp ISO da coleta
- **tempo_min:** Tempo desde início da simulação
- **Parâmetros físicos:** Valores instantâneos
- **evento_operador:** Última ação manual registrada
- **evento_fisica:** Último evento automático do sistema
- **alerta_tipo:** NORMAL/ATENÇÃO/CRÍTICO/EMERGÊNCIA

#### **💾 EXPORTAÇÃO MANUAL:**
1. **Menu:** Arquivo → Exportar Dados
2. **Formato:** CSV pronto para Excel/BI
3. **Uso:** Análise estatística, machine learning, relatórios

### 📈 **RELATÓRIOS AUTOMÁTICOS**

#### **📊 RELATÓRIO OPERACIONAL DIÁRIO:**
- **Produção acumulada:** Volume total produzido
- **Eficiência:** Percentual do tempo em operação normal
- **Intervenções:** Lista de ações corretivas aplicadas
- **Alertas:** Histórico de situações críticas

#### **📉 ANÁLISE DE TENDÊNCIAS:**
- **Declínio natural:** Taxa de queda da produção
- **Water cut evolution:** Evolução do BSW ao longo do tempo
- **Pressure depletion:** Curva de declínio de pressão
- **Intervention effectiveness:** Eficácia das intervenções

---

## **[9] BOAS PRÁTICAS E SEGURANÇA**

### ✅ **DO'S - PRÁTICAS RECOMENDADAS**

#### **🎯 MONITORAMENTO PROATIVO:**
```
✅ Verificar indicadores a cada 15-30 minutos
✅ Monitorar tendências, não apenas valores pontuais
✅ Anotar padrões de comportamento anômalo
✅ Usar gráficos para visualizar trends
✅ Exportar dados regularmente para backup
```

#### **🔧 INTERVENÇÕES PLANEJADAS:**
```
✅ Planejar intervenções com antecedência
✅ Aplicar uma intervenção por vez
✅ Aguardar estabilização antes da próxima ação
✅ Documentar resultados de cada intervenção
✅ Usar valores recomendados como ponto de partida
```

#### **🚨 RESPOSTA A EMERGÊNCIAS:**
```
✅ Reagir imediatamente a sirenes críticas
✅ Ler e entender completamente mensagens de alerta
✅ Aplicar correção na causa raiz, não sintoma
✅ Monitorar intensivamente após intervenções
✅ Manter log detalhado de ações tomadas
```

### ❌ **DON'TS - PRÁTICAS PERIGOSAS**

#### **⚠️ ERROS DE MONITORAMENTO:**
```
❌ Ignorar alertas de atenção (amarelos)
❌ Focar apenas nos valores atuais, sem ver tendências
❌ Deixar o simulador rodando sem supervisão
❌ Confiar apenas nos indicadores visuais
❌ Não fazer backup dos dados periodicamente
```

#### **🚫 ERROS DE INTERVENÇÃO:**
```
❌ Aplicar múltiplas intervenções simultâneas
❌ Usar valores extremos sem justificativa
❌ Intervir sem diagnosticar a causa do problema
❌ Não aguardar estabilização entre ações
❌ Repetir intervenção ineficaz sem análise
```

#### **💥 ERROS CRÍTICOS:**
```
❌ Ignorar shutdown automático
❌ Tentar "burlar" limites de segurança
❌ Intervir durante emergência ativa
❌ Não investigar causa de emergências
❌ Reiniciar sistema sem corrigir problema
```

### 🛡️ **PROTOCOLOS DE SEGURANÇA**

#### **📋 CHECKLIST PRÉ-OPERAÇÃO:**
```
🔍 ANTES DE CADA SESSÃO:
├─ ✅ Sistema de áudio funcionando (teste aos 10s)
├─ ✅ Todos os indicadores inicializando corretamente
├─ ✅ Gráficos atualizando em tempo real
├─ ✅ Controles de intervenção responsivos
└─ ✅ CSV sendo gerado na pasta correta
```

#### **⚡ PROCEDIMENTO DE EMERGÊNCIA:**
```
🚨 EM CASO DE SHUTDOWN:
├─ 1. NÃO PÂNICO - Ler mensagem completa
├─ 2. IDENTIFICAR causa específica do shutdown
├─ 3. APLICAR correção apropriada
├─ 4. AGUARDAR estabilização completa
└─ 5. DOCUMENTAR ocorrência para análise
```

#### **📞 ESCALONAMENTO:**
```
🆘 QUANDO PEDIR AJUDA:
├─ Shutdowns recorrentes (>3 em 1 hora)
├─ Intervenções não surtindo efeito esperado
├─ Comportamento anômalo dos parâmetros
├─ Dúvidas sobre interpretação de alertas
└─ Sistema não respondendo adequadamente
```

---

## **[10] TROUBLESHOOTING**

### 🔧 **PROBLEMAS TÉCNICOS COMUNS**

#### **🔊 PROBLEMA: "NÃO ESCUTO SIRENES"**

**📋 CHECKLIST SOLUÇÃO:**
```
1. ✅ Volume sistema operacional > 50%
2. ✅ Alto-falantes conectados e funcionando
3. ✅ Teste manual: speaker-test -t sine -f 800 -l 1
4. ✅ Permissões ALSA: usuário no grupo audio
5. ✅ PulseAudio ativo: pulseaudio --check -v
```

**🔧 SOLUÇÕES:**
- **Ubuntu/Debian:** `sudo usermod -a -G audio $USER`
- **Teste manual:** `pactl list short sources`
- **Reiniciar audio:** `pulseaudio -k && pulseaudio --start`

#### **📊 PROBLEMA: "GRÁFICOS NÃO ATUALIZAM"**

**🔍 DIAGNÓSTICO:**
```
1. Verificar seletor de periodicidade (não está em "Pausado")
2. Confirmar dados novos sendo gerados no CSV
3. Verificar se atingiu limite de 500 pontos
4. Usar botão "Limpar Gráficos" para resetar
```

#### **💾 PROBLEMA: "CSV NÃO É GERADO"**

**🔍 POSSÍVEIS CAUSAS:**
```
1. Permissões de escrita na pasta do projeto
2. Disco cheio ou sem espaço
3. Sistema de arquivos read-only
4. Pasta do projeto em local protegido
```

**🔧 SOLUÇÃO:**
```bash
# Verificar permissões
ls -la ../simulacao_petroleo.csv

# Verificar espaço em disco  
df -h .

# Testar escrita manual
echo "test" > ../teste.txt && rm ../teste.txt
```

#### **⚙️ PROBLEMA: "BUILD FALHA"**

**🔍 ERROS COMUNS:**
```
1. CMake não encontra Qt5
   └─ Instalar: sudo apt install qtbase5-dev qtcharts5-dev

2. Compilação em pasta errada
   └─ SEMPRE usar: mkdir build && cd build && cmake ..

3. Permissões inadequadas
   └─ Verificar: ls -la /home/wolf/Documentos/
```

### 🎯 **PERFORMANCE E OTIMIZAÇÃO**

#### **⚡ MELHORAR RESPONSIVIDADE:**
```
1. 🔧 Reduzir periodicidade gráficos (5min → 1min)
2. 🔧 Limpar gráficos periodicamente (botão limpar)
3. 🔧 Fechar outras aplicações pesadas
4. 🔧 Aumentar RAM se disponível < 4GB
```

#### **💾 REDUZIR USO DE DISCO:**
```
1. 📁 Arquivar CSVs antigos periodicamente
2. 📁 Usar compressão: gzip simulacao_petroleo.csv
3. 📁 Implementar rotação automática de logs
```

### 📚 **RECURSOS ADICIONAIS**

#### **📖 DOCUMENTAÇÃO:**
- **GLOSSARIO_COMPLETO_SIMULADOR.md:** Termos técnicos
- **DOCUMENTACAO_COMPLETA.md:** Arquitetura do sistema
- **TESTING_CHECKLIST.md:** Procedimentos de teste

#### **🆘 SUPORTE:**
- **Issues:** https://github.com/anthropics/claude-code/issues
- **Logs:** Disponíveis na interface durante execução
- **Debug:** Ativar modo verbose para diagnósticos

---

## 🎓 **CERTIFICAÇÃO DE COMPETÊNCIA**

### ✅ **NÍVEL BÁSICO - OPERADOR**
```
□ Inicializar sistema corretamente
□ Interpretar todos os indicadores numéricos
□ Reconhecer e responder a alertas básicos
□ Aplicar intervenções simples (água, aquecimento)
□ Exportar dados e gerar relatórios básicos
```

### ✅ **NÍVEL INTERMEDIÁRIO - TÉCNICO**
```
□ Diagnosticar problemas complexos
□ Aplicar múltiplas intervenções coordenadas
□ Gerenciar situações de emergência
□ Analisar tendências e prever problemas
□ Otimizar performance operacional
```

### ✅ **NÍVEL AVANÇADO - ESPECIALISTA**
```
□ Desenvolver estratégias de longo prazo
□ Modificar parâmetros avançados
□ Treinar outros operadores
□ Implementar melhorias no sistema
□ Conduzir análises de root cause
```

---

**📅 Criado:** 30 de Agosto de 2025  
**🔧 Versão:** v1.0.0 - Manual Completo de Operação  
**🎯 Público:** Estudantes, Operadores, Técnicos  
**📚 Status:** Manual oficial de treinamento  
**🏆 Certificação:** Documento habilitador para operação**