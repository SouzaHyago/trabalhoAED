# Organização do Projeto

Este repositório está organizado em dois arquivos principais:

- **[`main.c`](main.c)**  
  Contém a implementação das funções principais (da 1 a 4), seguindo, sempre que possível, o padrão de entrada e saída exigido pelo **RunCodes**.

- **[`testes.c`](testes.c)**  
  Contém funções de teste, como `teste_inverter()`, e é usado para gerar dados de desempenho das funções principais em formato CSV, para posterior análise gráfica.

---

## Gerando os dados para análise

### 1. Compilar o arquivo de testes

No Linux ou Windows (Git Bash ou CMD):

```bash
gcc testes.c -o testes

2. Rodar o programa e salvar os resultados em CSV

Linux:

./testes > tempos.csv

Windows (CMD ou PowerShell):

testes.exe > tempos.csv

    O arquivo tempos.csv será criado na mesma pasta e contém os tempos de execução das funções para diferentes tamanhos de vetor.

Gerando gráficos com Python
1. Instalar Python 3

Linux:

# Fedora
sudo dnf install python3

# Ubuntu/Debian
sudo apt install python3

Windows:
Baixe e instale o Python 3 em python.org

.

    Certifique-se de marcar a opção Add Python to PATH durante a instalação.

2. Instalar bibliotecas necessárias

pip3 install matplotlib seaborn pandas

    No Windows, você pode usar pip em vez de pip3, dependendo da instalação.

3. Rodar o script para gerar gráficos

Linux:

python3 graphCreator.py

Windows:

python graphCreator.py

    O script lê o arquivo tempos.csv e gera gráficos de tempo de execução.
    Todas as imagens geradas serão salvas na pasta /graficos.

4. Criar a pasta de gráficos

mkdir graficos

5. Recomendações de gráficos

    Linear → para detalhes próximos.

    Logarítmico → para comparação de ordens de grandeza (útil quando os tempos variam muito, ex: milissegundos vs segundos).

Estrutura final dos arquivos

/trabalhoAED
│
├─ main.c
├─ testes.c
├─ graphCreator.py
├─ tempos.csv       # gerado pelo testes.c
└─ graficos/        # pasta onde os gráficos serão salvos

Dicas importantes

    Sempre crie o CSV antes de gerar os gráficos.

    No Windows, rode o CMD ou PowerShell na pasta do projeto.

    No Linux, garanta que os arquivos tenham permissão de execução:

chmod +x testes
