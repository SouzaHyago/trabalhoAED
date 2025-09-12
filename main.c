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


int main(){
    clock_t t;

    int n; //tamanho do vetor
    scanf("%d", &n); 

    int *arr = malloc (sizeof(int) * n); //o vetor
    for (int i = 0; i < n; i++){
      scanf("%d", &arr[i]); //recebendo os valores de arr
    }

    int op; //comando do menu
    do {
      scanf("%d", &op);

      switch (op){
        case 1:
            inverter(arr, 0, n - 1);
            for (int i = 0; i < n; i++){
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 2:{
            int p; //valor procurado
            scanf("%d", &p);
            if (buscaSequencial(arr, n, p) == 1){
                printf("SIM\n");
            } else {
                printf("NAO\n");
            }
            break;
        }
        case 3: {
            int p; //valor procurado
            scanf("%d", &p);
            if (buscaBinariaIterativa(arr, 0, n - 1, p) == 1){
                printf("SIM\n");
            } else {
                printf("NAO\n");
            }
            break;
        }
        case 4: {
            int p; //valor procurado
            scanf("%d", &p);
            if (buscaBinariaRecursiva(arr, 0, n - 1, p) == 1){
                printf("SIM\n");
            } else {
                printf("NAO\n");
            }
            break;
        }
        default:
            break;
      }
    } while (op != 5);
    
    free(arr);
    return 0;
}