#include<stdio.h>
#include<stdlib.h>

/*--------------------------------Definindo a estrutura do nó e da fila--------------------*/
typedef struct No
{
    int valor;
    struct No *proximo;
}No;

typedef struct Fila
{
    No *inicio,*fim;
    int tamanho;
}Fila;

Fila criarfial(){
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;

    return *fila;
}
/*---------------------------------------inserindo valroes---------------------------*/
void inserir (Fila *fila, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo ->valor = valor;
    novo->proximo = NULL;

    if(fila->inicio == NULL){
        fila->inicio = novo;
        fila->fim = novo;
    }
    else{
        fila->fim->proximo = novo;  /*Inserindo no final da fila*/
        fila->fim = novo;
    }
    fila->tamanho++;
}
/*-------------------------------------removendo valores da fila-------------------------*/
void remover(Fila *fila){
    No *inicio = fila->inicio;
    No *aremover = NULL;

    if (fila->inicio != NULL){
        aremover = fila->inicio;
        fila->inicio = aremover->proximo;   /*sempre o primeiro a entrar é o primeiro a sair*/
        if(fila->inicio == NULL){
            fila->fim = NULL;
        }
    }
    if(aremover){
        free(aremover);
        fila->tamanho--;
    }
}
/*------------------------------------------------mostrar a fila--------------------*/
void imprimir (Fila *fila){
    No *inicio = fila->inicio;
    printf("O tamanho da fila e: %d\n", fila->tamanho);
    while(inicio != NULL){
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}
/*-------------------------------------------Principal--------------------------------*/
int main (){
    Fila filaprincipal = criarfial();
    int opcao, valor;

    do {
        printf(" 1 - Inserir\n 2 - Imprimir a fila\n 3 - Remover elemento\n 0 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o numero a ser inserido\n");
            scanf("%d", &valor);
            inserir(&filaprincipal, valor);
            break;
        case 2:
            imprimir(&filaprincipal);
            break;
        case 3:
            remover(&filaprincipal);
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