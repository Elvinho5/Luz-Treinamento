#include<stdio.h>
#include<stdlib.h>
/*Melhor caso O(N) => ele passa uma vez pelo programa
Pior caso O(N²) => ele passa n² vezes pelo programa
Eficientes para conjuntos pequenos de dados
Estável => Não muda posições de dados iguais
Ordena dados a medida que os recebe*/

void ordenar (int *vetor, int tamanho){
    int i, j, aux;
    for(i = 1; i < tamanho; i++){ //ordenando por inserção
        aux = vetor[i];
        for (j = i-1; j>=0 && aux < vetor[j]; j--){
            vetor[j+1] = vetor[j];
        }
        vetor[j+1] = aux;
    }
}


int main() {
    int *vetor,tamanho, aux;

    printf("Digite a quantidade de termos da sua sequencia: ");
    scanf("%d", &tamanho);
    vetor = (int*)malloc(tamanho*sizeof(int));

    if (vetor == NULL){
        printf("Erro: Não ha espaço separado para a memória");
    }

    printf("Digite cada numero e pressione Enter\n");
    for (int i=0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }

    printf("Sequencia atual dos numeros\n");
    for(int i = 0; i < tamanho; i++){
        printf("%3d", vetor[i]);
    }

    ordenar(vetor,tamanho);

    printf("\n");
    printf("Sequencia ordenada\n");
    for(int i = 0; i < tamanho; i++){
        printf("%3d",vetor[i]);
    }
    free(vetor);
    return 0;
}