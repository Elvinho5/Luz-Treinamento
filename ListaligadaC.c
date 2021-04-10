#include<stdio.h>
#include<stdlib.h>

/*criando o meu nó, ou seja, o que vai ligar as póximas posiçoes da minha lista, com os respectivos valores e também qual será o próximo nó da lista*/
typedef struct No{      
    int valor;
    struct No *proximo;  
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
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    }
    else{
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    }
    lista->tamanho++;
}

void inserirnofim (Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (lista->inicio == NULL){ /* se a minha lista estiver vazia*/
        lista->inicio = novo;
        lista->fim = novo;
    }
    else{
        lista->fim->proximo = novo;
        lista->fim =  novo;
    }
    lista->tamanho++;
}

/*--------------------------remover elementos da lista-----------------------------*/
void removerinicio (Lista *lista){
    No *inicio = lista->inicio;
    No *aremover = NULL;

    if(inicio != NULL){ /*remover se for o primeiro elemento*/
        aremover = lista->inicio;
        lista->inicio = aremover->proximo;
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
    No *inicio = lista->inicio;
    No *aremover = NULL;

    while(inicio !=NULL && inicio->proximo !=NULL){
        inicio = inicio->proximo;
    }
    if(inicio !=NULL && inicio->proximo !=NULL){
        aremover = inicio->proximo;
        inicio->proximo = aremover->proximo;
        if (inicio->proximo == NULL){
            lista->fim = inicio;
        }
    }
    if(aremover){
        free(aremover);
        lista->tamanho--;
    }

}
void remover (Lista *lista, int valor){
    No *inicio = lista->inicio;
    No *aremover = NULL;

    if(inicio != NULL && lista->inicio->valor == valor){ /*remover se for o primeiro elemento*/
        aremover = lista->inicio;
        lista->inicio = aremover->proximo;
        if (lista->inicio == NULL){
            lista->fim = NULL;
        }
    }
    else{                                               /*remover se for o do meio ou o último*/
            while(inicio !=NULL && inicio->proximo !=NULL && inicio->proximo->valor != valor){
                inicio = inicio->proximo;
            }
            if (inicio !=NULL && inicio->proximo !=NULL){
                aremover = inicio->proximo;
                inicio->proximo = aremover->proximo;
                if (inicio->proximo == NULL){
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
        inicio = inicio->proximo;
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
        inicio = inicio->proximo;
    }
    printf("\n\n");
}
/*-----------------------------------------------main---------------------------------------*/
int main(){
    Lista listaprincipal = criarlista();
    int opcao, valor;



    do {
        printf(" 1 - Inserir no inicio\n 2 - Inserir no fim \n 3 - Remover do Inicio\n 4 - Remover do fim\n 5 - Remover algum valor específico\n 6 - Quantidade de valores na lista\n 7 - Lista completa\n 8 - Imprimir Completo\n 0 - Sair\n");
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

        case 4:
            removerfim(&listaprincipal);
            printf("\n");

        case 5:
            printf("Digite o numero a ser removido\n");
            scanf("%d", &valor);
            remover(&listaprincipal, valor);
            printf("\n");
            break;

        case 6:
            imprimirlistatamanho(&listaprincipal);
            printf("\n");
            break;

        case 7:
            imprimirlista(&listaprincipal);
            printf("\n");
            break;

        case 8:
            imprimircompleto(&listaprincipal);
            printf("\n");

        case 0:
            printf("Finalizando");
            printf("\n");
            break;
            
        default:
            printf("Opcao Invalida");
            printf("\n");
        }
    }while(opcao!=0);
return 0;
}