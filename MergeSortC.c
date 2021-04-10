#include<stdio.h>
#include<stdlib.h>

/*Melhor e Pior  caso O(nlogn)
Não altera ordem dos dados iguais
Desvantagem: recursivo e usa um vetor auxiliar durante a ordenação, assim consumindo mais memória*/

void merge (int *vetororiginal, int *vetorordenado, int inicio, int fim){
    if (fim <= inicio){
        return;
    }
    int meio = (inicio+fim)/2;
    merge(vetororiginal,vetorordenado,inicio,meio);
    merge(vetororiginal,vetorordenado,meio+1,fim);

    int ladoesq = inicio;
    int ladodir = meio + 1;

    for (int j = inicio; j <= fim; j++){
        if(ladoesq == meio+1){
            vetorordenado[j] = vetororiginal[ladodir];
            ladodir++;
        }else if (ladodir == fim + 1){
            vetorordenado[j] = vetororiginal[ladoesq];
            ladoesq++;
        }else if (vetororiginal[ladoesq] < vetororiginal[ladodir]){
            vetorordenado[j] = vetororiginal[ladoesq];
            ladoesq++;
        }else {
            vetorordenado[j] = vetororiginal[ladodir];
            ladodir++;
        }
    }
    for(int j = inicio; j <= fim; j++){
        vetororiginal[j] = vetorordenado[j];
    }
    free(vetorordenado);
}
int main(){
    int *vetororiginal, *vetorordenado, tamanho;

    printf("Escreva o numero de termos\n");
    scanf("%d", &tamanho);
    vetororiginal = (int*)malloc(tamanho*sizeof(int));
    vetorordenado = (int*)malloc(tamanho*sizeof(int));

    printf("Digite os numeros\n");
    for (int i = 0; i < tamanho; i++){
        scanf("%d", &vetororiginal[i]);
    }

    printf("A ordem atual dos numeros e\n");
    for (int i = 0; i < tamanho; i++){
        printf("%3d", vetororiginal[i]);
    }

    merge (vetororiginal, vetorordenado, 0, tamanho-1);

    printf("\nOs numeros ordenados sao\n");
    for(int i = 0; i < tamanho; i++){
        printf("%3d", vetororiginal[i]);
    }
    free(vetororiginal);
    return 0;

}