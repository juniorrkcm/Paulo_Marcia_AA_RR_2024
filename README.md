# Paulo_Marcia_AA_RR_2024
# Fibonacci Algorithms

Este repositório contém duas implementações para calcular a sequência de Fibonacci:
1. Um algoritmo iterativo simples usando a biblioteca GMP para manipulação de números grandes.
2. Um algoritmo otimizado usando a abordagem de dividir para conquistar com representação matricial, também utilizando a biblioteca GMP.

## Pré-requisitos

Antes de executar qualquer código, você precisará instalar a biblioteca GMP, que permite a manipulação de números grandes.

### Instalação da Biblioteca GMP

#### No Windows (usando MSYS2)

Baixe e instale o MSYS2 do site oficial: [MSYS2](https://www.msys2.org/).

Abra o terminal **MSYS2 MSYS** e execute:

```bash
pacman -Syu
```

Se o terminal fechar, reabra-o e execute novamente:

```bash
pacman -Su
```
#### No Linux 

Abra o terminal e execute:

```bash
sudo apt-get update
sudo apt-get install libgmp-dev
```

### Compilação dos Algoritmos

##### Algoritmo Iterativo Simples

Navegue até o diretório do projeto e compile o código:

```bash
cd path/to/your/repository
gcc fibonacci.c -o fibonacci -lgmp
```

##### Algoritmo de Dividir para Conquistar com Representação Matricial

Navegue até o diretório do projeto e compile o código:

```bash
cd path/to/your/repository
gcc fibonacci_melhorado.c -o fibonacci_melhorado -lgmp
```

#### Execução dos Algoritmos

##### Executando o Algoritmo Iterativo Simples

Após compilar o código, execute o programa para calcular o n-ésimo termo da sequência de Fibonacci:

```bash
./fibonacci
```

O programa executará 5 entradas específicas determinadas no código.

##### Executando o Algoritmo de Dividir para Conquistar

Após compilar o código, execute o programa para calcular o n-ésimo termo da sequência de Fibonacci usando a abordagem matricial:

```bash
./fibonacci_melhorado
```

### Arquivos csv
Ambos os algoritmos não só medem o tempo de execução, mas também salvam os resultados da sequência de Fibonacci para cada entrada em arquivos CSV separados. Isso permite uma análise mais detalhada dos resultados e do desempenho.

### Visualização dos Resultados

Para visualizar os resultados de desempenho, você pode plotar um gráfico usando Python e Matplotlib.

Instale o Pandas e Matplotlib:

```bash
pip install pandas matplotlib
```

#### Abra três terminais e execute os scripts em Python para plotar o gráficos:

No primeiro terminal:

```bash
python plot1.py
```

No segundo terminal:

```bash
python plot2.py
```

No terceiro terminal:

```bash
python interativeVSmatrix_plot.py
```



