#include<stdio.h>
#include<stdlib.h>

/*---------------------------------Definindo a estrutura do nó e pilha-------------------*/
typedef struct No
{
    int valor;
    struct No *proximo;
}No;

typedef struct Pilha
{
    No *inicio,*fim;
    int tamanho;
}Pilha;

Pilha criarpilha(){
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->inicio = NULL;
    pilha->fim = NULL;
    pilha->tamanho = 0;

    return *pilha;
}

/*--------------------------------------inserindo valroes--------------------------------*/
void inserir (Pilha *pilha, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo ->valor = valor;
    novo->proximo = NULL;

    if(pilha->inicio == NULL){
        pilha->inicio = novo;
        pilha->fim = novo;
    }
    else{
        novo->proximo = pilha->inicio;          /*inserindo por cima da pilha*/
        pilha->inicio = novo;
    }
    pilha->tamanho++;
}

/*----------------------------------removendo valores da pilha----------------------------*/
void remover(Pilha *pilha){
    No *inicio = pilha->inicio;
    No *aremover = NULL;

    if (pilha->inicio != NULL){
        aremover = pilha->inicio;
        pilha->inicio = aremover->proximo;       
        if(pilha->inicio == NULL){
            pilha->fim = NULL;
        }
    }
    if(aremover){
        free(aremover);
        pilha->tamanho--;
    }
}

/*-------------------------------------mostrar a pilha------------------------------*/
void imprimir (Pilha *fila){
    No *inicio = fila->inicio;
    printf("O tamanho da fila e: %d\n", fila->tamanho);
    while(inicio != NULL){
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}
/*---------------------------------------Principal---------------------------------------*/
int main (){
    Pilha pilhaprincipal = criarpilha();
    int opcao, valor;

    do {
        printf(" 1 - Inserir\n 2 - Imprimir a fila\n 3 - Remover elemento\n 0 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o numero a ser inserido\n");
            scanf("%d", &valor);
            inserir(&pilhaprincipal, valor);
            break;
        case 2:
            imprimir(&pilhaprincipal);
            break;
        case 3:
            remover(&pilhaprincipal);
            break;
        case 0:
            printf("Finalizando");
            break;
        default:
            printf("Opcao Invalida");
        }
    }while(opcao!=0);
return 0;
}