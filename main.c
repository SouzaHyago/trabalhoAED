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
void buscaSequencial(int arr[],int length,int s){

    //percorre a lista até encontrar o valor solicitado
    for (int i = 0; i < length; i++){
        if (arr[i] == s){
            printf("Sim\n");
            return;
        }
        
    }
    
}


//Busca Binária Iterativa no vetor de entrada.
void buscaBinariaRecursiva(int arr[], int inicio,int fim,int n){

    
    int meio = (inicio + fim)/2;

    //1° caso base.]
    if (arr[meio] == n){
        printf( "sim\n");
        return;
    }

    //2° caso base. Se fim < inicio é porque toda a lista foi percorrida e nada foi encontrado
    if(fim < inicio){
        printf( "Não\n");
        return;
    }
    

    
    if(arr[meio] > n){
        buscaBinariaRecursiva(arr,inicio,meio-1,n);//Pega a metade esquerda da lista
    }else{
        buscaBinariaRecursiva(arr,meio+1,fim,n);//Pega metade direita da lista
    }
}


//Busca Binária Iterativa no vetor de entrada.
void buscaBinariaIterativa(int arr[], int inicio, int fim, int n){
    
    //o while irá rodar até entrar em um caso base
    while(1){

        int meio = (inicio + fim) / 2;

        if(arr[meio] == n){
            printf("SIM\n");
            return;
        }
        if(fim < inicio){
            printf("Não\n");
            return;
        }

        if (n < arr[meio]){
            fim = meio - 1;//Pegar a metade esquerda da lista
        }else{
            inicio = meio + 1;//Pegar a metade direita da lista
        }
        
    }
}
#pragma endregion

#pragma region funcoes_de_realizacao_de_testes //para facilitar os testes e calculos

double teste_inverter(int qtdExecucoes,int tamanhoVetor){

    clock_t t;//clock_t vem da biblioteca time.h e facilita o cálculo do tempo  
    double media = 0;
    
    for (int i = 0; i < qtdExecucoes; i++){
        
        int n = tamanhoVetor, *arr = NULL;
        arr = realloc(arr,n * sizeof(int));//Realocando memória
        
        //Adicionando valores aleatorios de 0 a 10 x vezes
        for (int j = 0; j < n; j++){
            arr[j] = rand() % 10;
        }
        
        t = clock();//clock() calcula a quantidade de ticks desde o inicio do programa.
        inverter(arr,0,n);
        t = clock()-t; //agora é só fazer a diferença entre o tempo de fim - inicio da função.
        
        media += ((double)t)/CLOCKS_PER_SEC;//faço o cast de t pra double e divido pela constante CLOCK_PER_SEC

        //CLOCKS_PER_SEC é uma constante com a quantidade de "ticks" por segundo
        printf("exec: %d - %f\n",i,((double)t)/CLOCKS_PER_SEC);
    }

    return media/qtdExecucoes;//Calculo a média de tempo para n execucoes
            
}

#pragma endregion

int main(){

    int n, op, s,*arr = NULL;
    clock_t t;

    while (op != 5){

        scanf("%d",&op);

        switch (op){

        case 1://inversão da ordem **Esta opção está chamando a funcção que faz os teste de tempo de inversao**

            scanf("%d%d",&s,&n);            
            double media = teste_inverter(s,n);//teste_inverter(int qtdExecucoes,tamanhoVetor)
            printf("a media para %d execucoes é: %f\n",s,media);
            break;

        case 2://Busca Sequencial

            scanf("%d",&n);//Recebendo o tamanho do vetor
            scanf("%d",&s);//Valor a ser encontrado
            arr = realloc(arr,n * sizeof(int));//Realocando memória

            for (int i = 0; i < n; i++){
                arr[i] = i;//adicionando valores de forma ordenada
            }

            buscaSequencial(arr,n-1,s);//n-1 para já passar o final do vetor de maneira correta
            break;

        case 3://Busca binária iterativa no vetor de entrada

            scanf("%d",&n);//Recebendo o tamanho do vetor
            scanf("%d",&s);//Valor a ser encontrado

            arr = realloc(arr,n * sizeof(int));//Realocando memória

            for (int i = 0; i < n; i++){
                arr[i] = i;//adicionando valores de forma ordenada
            }
            

            buscaBinariaIterativa(arr,0,n-1,s);//n-1 para já passar o final do vetor de maneira correta
            break;
                    
        case 4://Busca binária Recursiva no vetor de entrada

            scanf("%d",&n);//Recebendo o tamanho do vetor
            scanf("%d",&s);//Valor a ser encontrado

            arr = realloc(arr,n * sizeof(int));//Realocando memória

            for (int i = 0; i < n; i++){
                arr[i] = i;//Adicionando Valores de forma ordenada
            }
           
            buscaBinariaRecursiva(arr,0,n-1,s);//n-1 para já passar o final do vetor de maneira correta
            break;

        default:
            break;
        }

    }
    


    return 0;

}