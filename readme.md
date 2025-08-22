# Organização do Projeto

Este repositório está organizado em dois arquivos principais:

- **[`main.c`](main.c)**  
  Contém a implementação das funções principais (da 1 a 4), seguindo, sempre que possível, o padrão de entrada e saída exigido pelo **RunCodes**.

- **[`testes.c`](testes.c)**  
  Contém funções de teste, como `teste_inverter()`, e é usado para gerar dados de desempenho das funções principais em formato CSV, para posterior análise gráfica.

---

## Gerando os dados para análise

# 1. Compilar o arquivo de testes
gcc testes.c -o testes

# 2. Rodar o programa e salvar os resultados em CSV
# Linux
./testes > tempos.csv

# Windows (CMD ou PowerShell)
testes.exe > tempos.csv

# 3. Criar a pasta de gráficos
mkdir graficos

# 4. Instalar Python 3
# Fedora
sudo dnf install python3
# Ubuntu/Debian
sudo apt install python3

# 5. Instalar bibliotecas Python necessárias
pip3 install matplotlib seaborn pandas

# 6. Rodar o script para gerar gráficos
# Linux
python3 graphCreator.py
# Windows
python graphCreator.py

# 7. Garantir permissão de execução no Linux
chmod +x testes

Recomendações de gráficos

# Linear → para detalhes próximos
# Logarítmico → para comparar ordens de grandeza (milissegundos vs segundos)

Estrutura final dos arquivos

/trabalhoAED
│
├─ main.c
├─ testes.c
├─ graphCreator.py
├─ tempos.csv       # gerado pelo testes.c
└─ graficos/        # pasta onde os gráficos serão salvos

