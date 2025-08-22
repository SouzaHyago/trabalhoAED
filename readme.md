# [![Linguagem C](https://img.shields.io/badge/linguagem-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language)) [![Linguagem Python](https://img.shields.io/badge/linguagem-Python-yellow.svg)](https://www.python.org/)


guia para compilar o projeto, executar os testes e gerar os gráficos de desempenho.

**Você precisará de um compilador C (como o GCC) e do Python 3 instalados.**

1.  **Instale as bibliotecas Python necessárias:**
    ```bash
    pip3 install matplotlib seaborn pandas
    ```

2.  **Compile o código de teste:**
    ```bash
    gcc testes.c -o testes
    ```
    *No Linux ou macOS, pode ser necessário dar permissão de execução:* `chmod +x testes`

3.  **Execute os testes para gerar os dados:**
    Este comando irá rodar os benchmarks e salvar os resultados no arquivo `tempos.csv`.
    ```bash
    # Linux / macOS
    ./testes > tempos.csv

    # Windows
    testes.exe > tempos.csv
    ```

4.  **Gere os gráficos:**
    O script Python irá ler o `tempos.csv` e salvar as imagens na pasta `graficos/`.
    ```bash
    python3 graphCreator.py
    ```
Pronto! Seus gráficos de análise de desempenho estão na pasta `graficos/`.

## Como Funciona

O projeto é dividido em componentes com responsabilidades claras:

* **`main.c`**: Onde você deve implementar os algoritmos principais que deseja analisar.
* **`testes.c`**: Um ambiente preparado para chamar suas funções de `main.c`, medir o tempo de execução com diferentes entradas e imprimir os resultados em formato CSV.
* **`graphCreator.py`**: Lê o `tempos.csv` gerado pela etapa de testes e utiliza `matplotlib` e `seaborn` para criar visualizações de dados, salvando-as como arquivos de imagem.

