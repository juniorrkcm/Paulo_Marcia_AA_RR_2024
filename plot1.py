import matplotlib.pyplot as plt
import pandas as pd

# Leia os dados do arquivo CSVa
data = pd.read_csv('fibonacci_times_interativo.csv')

# Converta a coluna 'Terms' para um tipo de dado inteiro
data['Terms'] = data['Terms'].astype(int)

# Crie o gráfico de linha
plt.figure(figsize=(10, 6))
plt.plot(data['Terms'], data['ExecutionTime'], marker='o', linestyle='-', color='b')
plt.xlabel('Number of Terms')
plt.ylabel('Execution Time (seconds)')
plt.title('Execution Time of Fibonacci Calculation vs Number of Terms')
plt.grid(True)

# Exibe o gráfico
plt.show()
