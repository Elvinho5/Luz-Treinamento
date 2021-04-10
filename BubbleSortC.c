#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*Melhor caso O(N) => ele passa uma vez pelo programa
Pior caso O(N²) => ele passa n² vezes pelo programa
Não recomendado para grandes conjuntos de dados*/

void organizar (int vetor[],int tamanho){
    int aux, troca;
    troca = 1;
    while (troca == 1){
        troca = 0;
        for (int i = 0; i < tamanho-1; i++){
            if (vetor[i] > vetor[i+1]) {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                troca = 1;
            }
        }
    }

}

int main(){
    int *vetor, tamanho;

    printf("Digite a quantidade de termos da sua sequencia: ");
    scanf("%d", &tamanho);
    vetor = (int*)malloc(tamanho*sizeof(int));

    if (vetor == NULL){
        printf("Erro: Não existe espaço para a memória");
    }

    printf("Digite cada numero e pressione Enter\n");
    for (int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }

    printf("a sequencia atual dos numeros e\n");
    for(int i = 0; i < tamanho; i++){
        printf("%3d", vetor[i]);
    }
    printf("\n");

    organizar(vetor,tamanho);

    printf("A sequencia na ordem e\n");
    
    for(int i=0; i < tamanho; i++){
        printf("%3d",vetor[i]);
    }
    free(vetor);
    return 0;
}