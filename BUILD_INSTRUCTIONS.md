# 🚨 INSTRUÇÕES DE BUILD - IMPORTANTE

## ⚠️ PROCESSO OBRIGATÓRIO DE BUILD:

O projeto **DEVE** ser compilado e executado dentro da pasta `build`. 

### 📋 COMANDOS CORRETOS:

```bash
rm -rf build
mkdir build
cd build
cmake ..
make
./reservatorio_01
```

### ❌ ERROS COMUNS A EVITAR:

1. **NÃO compile na raiz do projeto**
2. **NÃO execute `make` fora da pasta build**
3. **NÃO deixe arquivos de build na raiz**

### 🔧 ESTRUTURA DE DIRETÓRIOS:

```
reservatorio-01/
├── main.cpp
├── CMakeLists.txt
├── BUILD_INSTRUCTIONS.md
└── build/                    ← Build acontece AQUI
    ├── CMakeFiles/
    ├── Makefile
    └── reservatorio_01       ← Executável fica AQUI
```

### 📝 NOTAS IMPORTANTES:

- Este processo foi definido pelo usuário
- É a **terceira vez** que este erro acontece
- **SEMPRE** usar a pasta build para compilação
- **NUNCA** alterar este processo sem autorização

### 🎯 PROCESSO DE DESENVOLVIMENTO:

1. Fazer alterações no `main.cpp`
2. Entrar na pasta build: `cd build`
3. Recompilar: `make`
4. Executar: `./reservatorio_01`

---
**DOCUMENTADO PARA NÃO ESQUECER NOVAMENTE** 📌