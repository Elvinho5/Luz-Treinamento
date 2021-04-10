#include<stdio.h>
#include<stdlib.h>
/*Melhor e pior caso O(N²) => ele passa n² vezes pelo programa
Ineficientes para grandes conjuntos de dados
Estável => Não muda posições de dados iguais*/

void ordenar (int *vetor, int tamanho){
    int menor, aux;

    for(int i = 0; i < tamanho; i++){
        menor = i;
        for (int j = i+1; j < tamanho; j++){
            if (vetor[menor] > vetor [j]){
                menor = j;
            }
        }
        if (i!=menor){
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}

int main() {
    int *vetor, tamanho;

    printf("Digite o numero de termos: ");
    scanf("%d", &tamanho);
    vetor = (int*)malloc(tamanho*sizeof(int));

    if (vetor == NULL){
        printf("Erro: Nao ha espaco para a alocacao de memoria");
    }

    printf("Digite os numeros\n");
    for (int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }

    printf("Valores na ordem atual\n");
    for(int i = 0; i < tamanho; i++){
        printf("%3d", vetor[i]);
    }

    ordenar(vetor,tamanho);

    printf("\n");
    printf("Os valores ordenados\n");
    for (int i = 0; i < tamanho; i++){
        printf("%3d", vetor[i]);
    }

    free(vetor);
    return 0;
}

