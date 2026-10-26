# Cadastro de Equipamentos - Laboratorio de Informatica

**Nome:** Maria Eduarda Dantas

Programa em C, executado no terminal, para cadastrar e consultar os
equipamentos de um laboratorio de informatica. Os dados ficam gravados em um
arquivo de texto (`equipamentos.txt`).

## Funcionalidades

- **Cadastrar equipamento**: solicita nome, codigo de identificacao e localizacao.
- **Listar equipamentos**: le o arquivo e exibe todos os registros na tela.
- **Sair**: encerra o programa.

Os registros existentes sao preservados a cada novo cadastro, pois o arquivo e
aberto no modo `"a"` (append).

## Estrutura do repositorio

```
.
├── cadastro_equipamentos.c   # codigo-fonte
├── equipamentos.txt          # exemplo de arquivo de dados
└── README.md                 # este arquivo
```

## Requisitos

- Compilador C (GCC, MinGW ou Clang)

## Como compilar e executar

### Linux / macOS

```bash
gcc cadastro_equipamentos.c -o cadastro_equipamentos
./cadastro_equipamentos
```

### Windows (MinGW / GCC)

```bash
gcc cadastro_equipamentos.c -o cadastro_equipamentos.exe
cadastro_equipamentos.exe
```

> Alternativa: abra o arquivo `.c` em uma IDE como Code::Blocks ou Dev-C++ e
> use a opcao Compilar e Executar.

## Exemplo de uso

```
=== LABORATORIO DE INFORMATICA ===
1 - Cadastrar equipamento
2 - Listar equipamentos
3 - Sair
Escolha uma opcao: 1

--- Cadastrar equipamento ---
Nome do equipamento : Notebook Lenovo
Codigo de identificacao: LAB-005
Localizacao          : Laboratorio 3
Equipamento cadastrado com sucesso!
```

## Formato do arquivo `equipamentos.txt`

Um registro por linha, com os campos separados por ponto e virgula:

```
nome;codigo;localizacao
```

Exemplo:

```
Computador Dell OptiPlex;LAB-001;Laboratorio 1 - Bancada A
Monitor LG 24 polegadas;LAB-002;Laboratorio 1 - Bancada A
```

O arquivo e criado automaticamente no primeiro cadastro, na pasta onde o
programa e executado. Se o usuario digitar `;` em algum campo, o programa o
substitui por `,` para nao quebrar o formato.

## Funcoes de arquivo utilizadas

| Funcao      | Uso                                                        |
|-------------|------------------------------------------------------------|
| `fopen()`   | Abre o arquivo em `"a"` (cadastro) e `"r"` (listagem)      |
| `fprintf()` | Grava cada equipamento no arquivo                          |
| `fgets()`   | Le as linhas do arquivo e tambem as entradas do teclado    |
| `fclose()`  | Fecha o arquivo apos o uso                                 |
