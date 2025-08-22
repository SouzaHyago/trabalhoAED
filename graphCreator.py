import pandas as pd
import matplotlib.pyplot as plt

#Lê o arquivo csv 
df = pd.read_csv("tempos.csv")

# Limpeza de espaços nos nomes das colunas/strings
df.columns = [c.strip() for c in df.columns]
if 'Funcao' in df.columns:
    df['Funcao'] = df['Funcao'].astype(str).str.strip()

# Agregar por média (caso você tenha várias execuções por (Funcao,Tamanho)) ===
agg = (df.groupby(['Funcao', 'Tamanho'], as_index=False)
         .agg(Tempo=('Tempo', 'mean')))

# Colunas derivadas
agg['Tempo_ms'] = agg['Tempo'] * 1000.0
agg['Tempo_us'] = agg['Tempo'] * 1_000_000.0

# Ordenar por tamanho para linhas contínuas
agg = agg.sort_values(['Funcao', 'Tamanho'])

# Gráfico em milissegundos (escala linear)
plt.figure(figsize=(10, 6))
for funcao, grupo in agg.groupby('Funcao'):
    plt.plot(grupo['Tamanho'], grupo['Tempo_ms'], marker='o', label=funcao)
plt.title("Tempo médio por função (ms, escala linear)")
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Tempo (ms)")
plt.legend()
plt.grid(True, which='both', linestyle='--', alpha=0.5)
plt.tight_layout()
plt.savefig("graficos/grafico_ms.png", dpi=160)
plt.close()

# Gráfico em segundos (escala logarítmica no eixo Y)
plt.figure(figsize=(10, 6))
for funcao, grupo in agg.groupby('Funcao'):
    plt.plot(grupo['Tamanho'], grupo['Tempo'], marker='o', label=funcao)
plt.yscale("log")
plt.title("Tempo médio por função (s, escala log)")
plt.xlabel("Tamanho do vetor (n)")
plt.ylabel("Tempo (s) [log]")
plt.legend()
plt.grid(True, which='both', linestyle='--', alpha=0.5)
plt.tight_layout()
plt.savefig("graficos/grafico_log.png", dpi=160)
plt.close()

print("Gráficos salvos: grafico_ms.png e grafico_log.png em /graficos")
