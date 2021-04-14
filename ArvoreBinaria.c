#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//------------------------ estrutura do nó e da árvore ----------------------------------
typedef struct No{   
    int valor;
    struct No *direita,*esquerda;
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
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    else{
        if(valor<raiz->valor){
            raiz->esquerda = inserirnovo(raiz->esquerda,valor);
        }
        if(valor>raiz->valor){
            raiz->direita = inserirnovo(raiz->direita, valor);
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
            if(raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                return(NULL); //remover os nós que não tem ligações com esq ou dir
            }
            else{  
                if(raiz->esquerda == NULL || raiz->direita == NULL){ //remover nós que tem uma ligação
                    No *aux;
                    if(raiz->esquerda != NULL){
                        aux = raiz->esquerda;
                    }
                    else{
                        aux = raiz->direita;
                    }
                    free(raiz);
                    return aux;
                }
                else{//remover um nó que tem 2 ligações
                    No *aux = raiz->esquerda;
                    while(aux->direita != NULL){
                        aux = aux->direita;
                    }
                    raiz->valor = aux->valor;
                    aux->valor = valor;
                    raiz->esquerda = remover(raiz->esquerda,valor);
                    return raiz;
                }
            }
        }
        else{
            if(valor < raiz->valor){
                raiz->esquerda = remover(raiz->esquerda,valor);
            }
            else{
                raiz->direita = remover(raiz->direita,valor);
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
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);    
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
                return buscar(raiz->esquerda, valor);
            }
            else{
                return buscar(raiz->direita,valor);
            }
        }
    }
}
//--------------------------- imprimir a árvore completa ----------------------------
void imprimir (No *raiz){
    if (raiz != NULL){
        imprimir(raiz->esquerda);
        printf("  %d", raiz->valor);
        imprimir(raiz->direita);
    }
}


void imprimirpre (No *raiz){
    if (raiz != NULL){
        printf("  %d", raiz->valor);
        imprimirpre (raiz->esquerda);
        imprimirpre (raiz->direita);
    }
}

void imprimirpos (No *raiz){
    if (raiz != NULL){
        imprimirpos (raiz->direita);
        imprimirpos (raiz->esquerda);
        printf("  %d", raiz->valor);
    }

}
//-------------------------------------MAIN---------------------------------------------
int main (){
    int opcao, valor;
    No *raiz = NULL;

    do{
        printf(" 1 - Inserir\n 2 - Imprimir\n 3 - Buscar\n 4 - Remover\n 5 - Imprimir Pre Oredem\n 6 - Imprimir Pos Ordem\n 7 - Limpar Arvore\n 0 - Sair\n");
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
            printf("O tamanho da arvore e %d\n", tamanho(raiz));
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
        case 5:
            printf("Impressao da arvore pre ordem\n");
            imprimirpre(raiz);
            printf("\n");
            break;
        case 6:
            printf("Impressao da arvore pos ordem\n");
            imprimirpos(raiz);
            printf("\n");
            break;
        case 7:
            printf("Raiz vazia");
            free(raiz);
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

