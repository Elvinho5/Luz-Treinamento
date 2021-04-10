#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//------------------------ estrutura do nó e da árvore ----------------------------------
typedef struct No{   
    int valor;
    struct No *proximo,*anterior;
}No;

typedef struct Arvore{   
    No* raiz;
    int tamanho;
}Arvore;

//----------------------------- funções de inserção -----------------------------
No* inserirnovo (No *raiz, int valor){
    if (raiz == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->valor = valor;
        novo->anterior = NULL;
        novo->proximo = NULL;
        return novo;
    }
    else{
        if(valor<raiz->valor){
            raiz->anterior = inserirnovo(raiz->anterior,valor);
        }
        if(valor>raiz->valor){
            raiz->proximo = inserirnovo(raiz->proximo, valor);
        }
        return raiz;
    }
}
//----------------------------------- remover nó ------------------------------------
No* remover (No *raiz, int valor){
    if (raiz == NULL){
        printf("Valor nao encontrado");
        return NULL;
    }
    else{
        if(raiz->valor == valor){
            if(raiz->anterior == NULL && raiz->proximo == NULL){
                free(raiz);
                return(NULL); //remover os nós que não tem ligações com esq ou dir
            }
            else{  
                if(raiz->anterior == NULL || raiz->proximo == NULL){ //remover nós que tem uma ligação
                    No *aux;
                    if(raiz->anterior != NULL){
                        aux = raiz->anterior;
                    }
                    else{
                        aux = raiz->proximo;
                    }
                    free(raiz);
                    return aux;
                }
                else{//remover um nó que tem 2 ligações
                    No *aux = raiz->anterior;
                    while(aux->proximo != NULL){
                        aux = aux->proximo;
                    }
                    raiz->valor = aux->valor;
                    aux->valor = valor;
                    raiz->anterior = remover(raiz->anterior,valor);
                    return raiz;
                }
            }
        }
        else{
            if(valor < raiz->valor){
                raiz->anterior = remover(raiz->anterior,valor);
            }
            else{
                raiz->proximo = remover(raiz->proximo,valor);
            }
            return raiz;
        }
    }
}
//--------------------------- tamanho da minha árvore -----------------------------
int tamanho (No *raiz){
    if (raiz == NULL){
        return 0;
    }
    else{
        return 1 + tamanho(raiz->anterior) + tamanho(raiz->proximo);    
    }
}
//---------------------------- buscar um valor na árvore -------------------------
int buscar(No *raiz, int valor){
    if(raiz == NULL){
        return -1;
    }
    else{
        if(raiz->valor == valor){
            return raiz->valor;
        }
        else{
            if (valor < raiz->valor){
                return buscar(raiz->anterior, valor);
            }
            else{
                return buscar(raiz->proximo,valor);
            }
        }
    }
}
//--------------------------- imprimir a árvore completa ----------------------------
void imprimir (No *raiz){
    if (raiz != NULL){
        imprimir(raiz->anterior);
        printf("  %d", raiz->valor);
        imprimir(raiz->proximo);
    }
}
//-------------------------------------MAIN---------------------------------------------
int main (){
    int opcao, valor;
    No *raiz = NULL;

    do{
        printf(" 1 - Inserir\n 2 - Imprimir\n 3 - Buscar\n 4 - Remover\n 0 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido\n");
            scanf("%d", &valor);
            raiz = inserirnovo(raiz,valor);
            break;
        case 2:
            printf("Impressao da arvore\n");
            imprimir(raiz);
            printf("\n");
            printf("O tamanho da arvore é %d\n", tamanho(raiz));
            printf("\n");
            break;
        case 3:
            printf("Digite o valor a ser buscado\n");
            scanf("%d",&valor);
            printf("O resultado da busca foi %d\n", buscar(raiz,valor));
            printf("\n");
            break;
        case 4:
            printf("Digite o valor a ser removido\n");
            scanf("%d",&valor);
            raiz = remover(raiz,valor);
            printf("\n");
            break;
        case 0:
            printf("Finalizando...");
            printf("\n");
            break;
        default:
            printf("Opção Inválida\n");
            break;
        }
    }while(opcao != 0);
    return 0;
}

