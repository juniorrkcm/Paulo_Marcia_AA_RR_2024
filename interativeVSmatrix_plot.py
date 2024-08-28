import matplotlib.pyplot as plt
import pandas as pd

# Leia os dados do arquivo CSV para o algoritmo iterativo simples
data_iterative = pd.read_csv('fibonacci_times_interativo.csv')
data_iterative['Terms'] = data_iterative['Terms'].astype(int)

# Leia os dados do arquivo CSV para o algoritmo de dividir para conquistar com matriz
data_matrix = pd.read_csv('fibonacci_times_matrix.csv')
data_matrix['Terms'] = data_matrix['Terms'].astype(int)

# Crie o gráfico de linha para comparação
plt.figure(figsize=(15, 9))

# Plot do algoritmo iterativo simples
plt.plot(data_iterative['Terms'], data_iterative['ExecutionTime'], marker='o', linestyle='-', color='b', label='Iterative Algorithm')

# Plot do algoritmo de dividir para conquistar com matriz
plt.plot(data_matrix['Terms'], data_matrix['ExecutionTime'], marker='o', linestyle='-', color='r', label='Matrix Exponentiation Algorithm')

# Configurações do gráfico
plt.xscale('log')  # Usando escala logarítmica para melhor visualização
plt.xlabel('Number of Terms (log scale)')
plt.ylabel('Execution Time (seconds)')
plt.title('Execution Time of Fibonacci Calculation: Iterative vs Matrix Exponentiation')
plt.grid(True)
plt.legend()

# Exibe o gráfico
plt.show()
