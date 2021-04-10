#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
/*Melhor caso O(nlogn)
/Pior caso ) n²
/Não altera posições de dados iguais
/Desvantagem: escolha do pivo*/

int dividir (int *vetor, int esq, int dir){
    int aux;
    int cont = esq;

    for (int i = esq+1; i <= dir; i++){

        if(vetor[i] < vetor[esq]){
            cont++;
            aux = vetor[i];
            vetor[i] = vetor[cont];
            vetor[cont] = aux;
        }
    }
    aux = vetor[esq];
    vetor[esq] = vetor[cont];
    vetor[cont] =  aux;

    return cont;
}

void quick (int v[], int esq, int dir){
    int pos;
    if (esq < dir){
        pos = dividir (v,esq,dir);
        quick(v,esq,pos-1);
        quick(v,pos+1,dir);
    }
}

int main (){
    int *vetor, tamanho;

    printf("Digite o numero de termos: ");
    scanf("%d", &tamanho);
    vetor = (int*)malloc(tamanho*sizeof(int));

    if (vetor==NULL){
        printf("Erro: Nao ha espaco para alocar a memoria");
    }
    
    printf("Digite os numeros e pressione Enter\n");
    for (int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }

    printf("Valores na ordem atual\n");
    for(int i = 0; i < tamanho; i++){
        printf("%3d", vetor[i]);
    }

    quick(vetor,0,tamanho);

    printf("\n");
    printf("Valores ordenados\n");
    for(int i = 0; i < tamanho; i++){
        printf("%3d", vetor[i]);
    }
    free(vetor);
    return 0;
}