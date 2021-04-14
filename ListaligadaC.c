#include<stdio.h>
#include<stdlib.h>

/*criando o meu nó, ou seja, o que vai ligar as póximas posiçoes da minha lista, com os respectivos valores e também qual será o próximo nó da lista*/
typedef struct No{      
    int valor;
    struct No *direita;  
}No;

/*criando a minha lista que tem nós para o inicio e fim de tudo e um valor que será o seu tamanho*/
typedef struct Lista{
    No *inicio, *fim;
    int tamanho;
}Lista;

Lista criarlista(){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->tamanho = 0;

    return *lista;
}
/*------------------------inserindo novos valores no começo ou no fim da lista--------------*/
void inserirnoinicio (Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    if (lista->inicio == NULL){
        novo->direita = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    }
    else{
    novo->direita = lista->inicio;
    lista->inicio = novo;
    }
    lista->tamanho++;
}

void inserirnofim (Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->direita = NULL;

    if (lista->inicio == NULL){ /* se a minha lista estiver vazia*/
        lista->inicio = novo;
        lista->fim = novo;
    }
    else{
        lista->fim->direita = novo;
        lista->fim =  novo;
    }
    lista->tamanho++;
}

/*--------------------------remover elementos da lista-----------------------------*/
void removerinicio (Lista *lista){
    No *inicio = lista->inicio;
    No *aremover = NULL;

    if (inicio == NULL){
        printf("Lista Vazia");
    }

    if(inicio != NULL){ /*remover se for o primeiro elemento*/
        aremover = lista->inicio;
        lista->inicio = aremover->direita;
        if (lista->inicio == NULL){
            lista->fim = NULL;
        }
    }
    if(aremover){
        free(aremover);
        lista->tamanho--;
    }
}

void removerfim (Lista *lista){
    No *novo = lista->inicio;
    No *antes = NULL;

    if (lista->inicio == NULL){
        printf("Lista Vazia");
    }
    while(novo->direita != NULL){
        antes = novo;
        novo = novo->direita;
    }
    if(novo == lista->inicio){
        lista->inicio = novo->direita;
    }
    else{
        antes->direita = novo->direita;
    }
    free(novo);
    lista->tamanho--;
}

void remover (Lista *lista, int valor){
    No *inicio = lista->inicio;
    No *aremover = NULL;

    if(inicio != NULL && lista->inicio->valor == valor){ /*remover se for o primeiro elemento*/
        aremover = lista->inicio;
        lista->inicio = aremover->direita;
        if (lista->inicio == NULL){
            lista->fim = NULL;
        }
    }
    else{                                               /*remover se for o do meio ou o último*/
            while(inicio !=NULL && inicio->direita !=NULL && inicio->direita->valor != valor){
                inicio = inicio->direita;
            }
            if (inicio->valor != valor){
                printf("O valor não existe na lista\n");
            }
            if (inicio !=NULL && inicio->direita !=NULL){
                aremover = inicio->direita;
                inicio->direita = aremover->direita;
                if (inicio->direita == NULL){
                    lista->fim = inicio;
                }
            }
    }
    if(aremover){
        free(aremover);
        lista->tamanho--;
    }
}
/*----------------------------------------------imprimindo a lista------------------------*/
void imprimirlista (Lista *lista){
    No *inicio = lista->inicio;
    while(inicio != NULL){
        printf("%d ", inicio->valor);
        inicio = inicio->direita;
    }
    printf("\n\n");
}
void imprimirlistatamanho (Lista *lista){
    No *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tamanho);
}
void imprimircompleto (Lista *lista){
    No *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tamanho);
    while(inicio != NULL){
        printf("%d ", inicio->valor);
        inicio = inicio->direita;
    }
    printf("\n\n");
}
/*-----------------------------------------------main---------------------------------------*/
int main(){
    Lista listaprincipal = criarlista();
    int opcao, valor;

    do {
        printf("1 - Inserir no inicio\n2 - Inserir no fim \n3 - Remover do Inicio\n4 - Remover do fim\n5 - Remover algum valor específico\n6 - Quantidade de valores na lista\n7 - Lista completa\n8 - Imprimir Completo\n0 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                printf("Digite o numero a ser inserido\n");
                scanf("%d", &valor);
                inserirnoinicio(&listaprincipal, valor);
                printf("\n");
                break;
            case 2:
                printf("Digite o numero a ser inserido\n");
                scanf("%d", &valor);
                inserirnofim(&listaprincipal, valor);
                printf("\n");
                break;
            case 3:
                removerinicio(&listaprincipal);
                printf("\n");
                break;
            case 4:
                removerfim(&listaprincipal);
                printf("\n");
                break;
            case 5:
                printf("Digite o numero a ser removido\n");
                scanf("%d", &valor);
                remover(&listaprincipal, valor);
                printf("\n");
                break;
            case 6:
                printf("O tamanho da lista\n");
                imprimirlistatamanho(&listaprincipal);
                printf("\n");
                break;
            case 7:
                printf("Lista\n");
                imprimirlista(&listaprincipal);
                printf("\n");
                break;
            case 8:
                printf("Informacoes da lista\n");
                imprimircompleto(&listaprincipal);
                printf("\n");
                break;
            case 0:
                printf("Finalizando\n");
                break;
            default:
                printf("Opcao Invalida\n");
                break;
        }
    }while(opcao!=0);
return 0;
}