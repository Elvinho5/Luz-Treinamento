#include<iostream>

using namespace std;

struct No{
    int valor;
    No *proximo;
};

class Lista{
    private:
        No *inicio,*fim;

    public:
        Lista(){
            inicio = NULL;
            fim = NULL;
        }
//------------------- inserção ------------------------------------
        void inserirnoinicio (int valor){
            No *novo = new No;
            novo->valor = valor;
            novo->proximo = NULL;

            if(inicio == NULL){
                inicio = novo;
                fim = novo;
            }
            else{
                novo->proximo = inicio;
                inicio=novo;
            }
        }
        void inserirnofim (int valor){
            No *novo = new No;
            novo->valor = valor;
            novo->proximo = NULL;

            if (inicio == NULL){
                inicio = novo;
                fim = novo;
            }
            else{
                fim->proximo = novo;
                fim = fim->proximo;
            }
        }
//--------------------------impressão------------------------------
        void imprimir(){
            No *novo;
            novo = inicio;
            while(novo != NULL){
                cout << novo->valor << " ";
                novo = novo->proximo;
            }
        }
//-------------------------remoção ----------------------------------

        void removerprimeiro (){
            No *novo = new No;
            No *aremover = new No;
            novo = inicio;
            aremover = NULL;

            if (inicio == NULL){
                cout << "Lista vazia";
            }
            if (inicio != NULL){
                aremover = inicio;
                novo = aremover->proximo;
                inicio = novo;
                if(inicio == NULL){
                    fim = NULL;
                }
            }
            if(aremover){
                free(aremover);
            }
        }

        void removerultimo (){
            No *novo = new No;
            No *antes = new No;
            novo = inicio;

            if(inicio == NULL){
                cout << "Lista Vazia";
            }
            while (novo->proximo != NULL){
                antes = novo;
                novo = novo->proximo;
            }
            if (novo == inicio){
                inicio = novo->proximo;
            }
            else{
                antes->proximo = novo->proximo;
            }
            free(novo);
        }

        void removernumeroescolhido(int v){
            No *novo = new No;
            No *aremover = new No;
            No *antes = new No;
            novo = inicio;

            if(inicio == NULL){
                cout << "Lista Vazia";
            }
            if (inicio != NULL && inicio->valor == v){
                aremover = inicio;
                novo = aremover->proximo;
                inicio = novo;
                if(novo == NULL){
                    fim = NULL;
                }
                
            }
            else{
                while(novo != NULL && novo->proximo != NULL && novo->proximo->valor != v){
                    antes = novo;
                    novo = novo->proximo;
                }
                if(novo != NULL && novo->proximo != NULL){
                    aremover = novo->proximo;
                    novo->proximo = aremover->proximo;
                    if(novo->proximo == NULL){
                        antes->proximo = novo->proximo;
                    }
                }
            }
            free(aremover);
        }
};

void escolhalista (){
    Lista lista;
    int op, v;

    cout << "\nEscolhida a opcao Lista\n";
    do{
        cout << "Escolha uma das opçoes\n";
        cout << "1 - Inserir no inicio\n2 - Inserir no fim\n3 - Imprimir\n4 - Remover do Inicio\n5 - Remover do fim\n6 - Remover algum valor especifico\n0 - Sair\n";
        cin >> op;

        switch (op)
        {
            case 1:
                cout << "Digite um numero\n ";
                cin >> v;
                lista.inserirnoinicio(v);
                cout << "\n";
                break;
            case 2:
                cout << "Digite um numero\n ";
                cin >> v;
                lista.inserirnofim(v);
                cout << "\n";
                break;
            case 3:
                cout << "A lista completa\n";
                lista.imprimir();
                cout << "\n";
                break;
            case 4:
                cout << "Removido o primeiro numero\n";
                lista.removerprimeiro();
                cout << "\n";
                break;
            case 5:
                cout << "Removido o ultimo numero\n";
                lista.removerultimo();
                cout << "\n";
                break;
            case 6:
                cout << "Digite o valor especifico\n";
                cin >> v;
                lista.removernumeroescolhido(v);
                cout << "\n";
                break;
            case 0:
                cout << "Finalizando...\n";
                break;
            default:
                cout << "Opcao Invalida";
                cout << "\n";
                break;
        }
    }while (op != 0);
}
//-------------------------------Pilha------------------------------------
class Pilha: public Lista{
};

void escolhapilha(){
    Pilha pilha;
    int op, v;

    cout <<"\nEscolhida a opcao Pilha\n";
    do {
        cout << "Escolha uma das opçoes\n";
        cout << "1 - inserir\n2 - Imprimir\n3 - Remover\n0 - Sair\n";
        cin >> op;

        switch (op)
        {
            case 1:
                cout << "Digite o numero\n";
                cin >> v;
                pilha.inserirnoinicio(v);
                cout << "\n";
                break;
            case 2:
                cout << "A pilha completa\n";
                pilha.imprimir();
                cout << "\n";
                break;
            case 3:
                cout << "Numero removido";
                pilha.removerprimeiro();
                cout << "\n";
                break;
            case 0:
                cout << "Finalizando\n";
                break;
            default:
                cout << "Opcao invalida\n";
                break;
        }
    }while(op != 0);
}
//------------------------------Fila--------------------------------------
class Fila: public Lista{
};

void escolhafila(){
    Fila fila;
    int op, v;
    
    cout << "\nEscolhida a opção Fila\n";
    do {
        cout << "Escolha uma das opçoes\n";
        cout << "1 - inserir\n2 - Imprimir\n3 - Remover\n0 - Sair\n";
        cin >> op;

        switch (op)
        {
            case 1:
                cout << "Digite o numero\n";
                cin >> v;
                fila.inserirnofim(v);
                cout << "\n";
                break;
            case 2:
                cout << "A fila completa\n";
                fila.imprimir();
                cout << "\n";
                break;
            case 3:
                cout << "Numero removido";
                fila.removerprimeiro();
                cout << "\n";
                break;
            case 0:
                cout << "Finalizando\n";
                break;
            default:
                cout << "Opcao invalida";
                break;
         }
    }while(op != 0);

}

//--------------------------------------------------------------
int main(){
    int e;

    do{
        cout << "Escolha uma das opcoes\n";
        cout << "1 - Criar uma pilha\n2 - Criar uma fila\n3 - Criar uma lista\n0 - Sair\n";
        cin >> e;

        switch (e)
        {
            case 1:
                escolhapilha();
                cout << "\n";
                break;
            case 2:
                escolhafila();
                cout << "\n";
                break;
            case 3:
                escolhalista();
                cout << "\n";
                break;
            case 0:
                cout << "Finalizando\n";
                break;
            default:
                cout <<"opcao invalida";
                break;
        }
    }while(e !=0);
 return 0;
}
