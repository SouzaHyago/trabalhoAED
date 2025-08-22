//Hyago Souza - Nusp: 16907348 | Juan Jacomassi - Nusp: 16878037 | Karen Nanamy Kamo - Nusp: 15495932

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#pragma region funcoes_principais //Apenas para organizar a vizualização do código

//inversão da ordem do vetor de entrada
void inverter(int arr[], int inicio,int fim){
    
    //Caso Base. Se fim <= inicio, não há mais elementos há serem trocados
    if(fim <= inicio){
        return;
    }

    //troca o primeiro elemento com o último
    int temp = arr[inicio];
    arr[inicio] = arr[fim];
    arr[fim] = temp;

    //garante a troca do 2° com o penúltimo, 3° com o antipenultimo e etc.
    inverter(arr,inicio+1,fim-1);

}


//Busca Sequencial no vetor de entrada.
int buscaSequencial(int arr[],int length,int s){

    //percorre a lista até encontrar o valor solicitado
    for (int i = 0; i < length; i++){
        if (arr[i] == s){
            return 1;
        }
        
    }
    return 0;
    
}


//Busca Binária Iterativa no vetor de entrada.
int buscaBinariaRecursiva(int arr[], int inicio,int fim,int n){

    if(fim < inicio) return 0;//1° caso base.

    int meio = (inicio + fim)/2;
    if (arr[meio] == n)return 1;//2° caso base. Se fim < inicio é porque toda a lista foi percorrida e nada foi encontrado

    
    if(arr[meio] > n){
        return buscaBinariaRecursiva(arr,inicio,meio-1,n);//Pega a metade esquerda da lista
    }else{
        return buscaBinariaRecursiva(arr,meio+1,fim,n);//Pega metade direita da lista
    }
}


//Busca Binária Iterativa no vetor de entrada.
int buscaBinariaIterativa(int arr[], int inicio, int fim, int n){
    
    //o while irá rodar até entrar em um caso base
    while(inicio <= fim){

        int meio = (inicio + fim) / 2;

        if(arr[meio] == n) return 1;


        if (n < arr[meio]){
            fim = meio - 1;//Pegar a metade esquerda da lista
        }else{
            inicio = meio + 1;//Pegar a metade direita da lista
        }
        
    }
    return 0;
}
#pragma endregion

#pragma region funcoes_de_realizacao_de_testes //para facilitar os testes e calculos

double teste_inverter(int qtdExecucoes,int tamanhoVetor){

    clock_t t;//clock_t vem da biblioteca time.h e facilita o cálculo do tempo  
    double media = 0;
    
    for (int i = 0; i < qtdExecucoes; i++){
        
        int *arr = malloc(tamanhoVetor * sizeof(int));//Realocando memória
        
        //Adicionando valores aleatorios de 0 a 10 x vezes
        for (int j = 0; j < tamanhoVetor; j++){
            arr[j] = rand() % 10;
        }
        
        t = clock();//clock() calcula a quantidade de ticks desde o inicio do programa.
        inverter(arr,0,tamanhoVetor-1);
        t = clock()-t; //agora é só fazer a diferença entre o tempo de fim - inicio da função.
        
        
        //CLOCKS_PER_SEC é uma constante com a quantidade de "ticks" por segundo
        media += ((double)t)/CLOCKS_PER_SEC;//faço o cast de t pra double e divido pela constante CLOCK_PER_SEC
        
        free(arr);
        
    }
    printf("inverter, %d, %f\n",tamanhoVetor,media/qtdExecucoes);

    return media/qtdExecucoes;//Calculo a média de tempo para n execucoes
            
}

void teste_buscaSequencial(int qtdExecucoes, int n){
    clock_t t;//clock_t vem da biblioteca time.h e facilita o cálculo do tempo  
    double media = 0;
    
    for (int i = 0; i < qtdExecucoes; i++){
        int *arr = malloc(n * sizeof(int));//Realocando memória
        for (int j = 0; j < n; j++){
            arr[j] = j;
        }
        t = clock();//clock() calcula a quantidade de ticks desde o inicio do programa.
        buscaSequencial(arr,0,n-1);
        t = clock()-t; //agora é só fazer a diferença entre o tempo de fim - inicio da função.

        media += ((double)t)/CLOCKS_PER_SEC;//faço o cast de t pra double e divido pela constante CLOCK_PER_SEC

        //CLOCKS_PER_SEC é uma constante com a quantidade de "ticks" por segundo
        
        free(arr);
    }
    printf("Busca_Sequencial, %d, %f\n",n,media/qtdExecucoes);
}



#pragma endregion

int main(){

    int tamanhos[] = {10, 100, 1000, 5000};
    int qtdExecucoes = 120;

    printf("Funcao,Tamanho,Tempo\n"); // Cabeçalho CSV

    for(int i = 0; i < 4; i++){
        int n = tamanhos[i];
        teste_inverter(qtdExecucoes, n);
        teste_buscaSequencial(qtdExecucoes, n);
        //teste_buscaBinariaIterativa(qtdExecucoes, n);
        //teste_buscaBinariaRecursiva(qtdExecucoes, n);
    }

    return 0;

}