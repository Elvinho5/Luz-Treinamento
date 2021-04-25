#include <iostream>
#include <regex>

using namespace std;

string email;

bool verificaremail(string email){
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email,pattern);
}


int main(){
    system ("cls");
    cout << "Validação de email";
    cout << "Digite o endereço de email\n";
    cin >> email;
    if(verificaremail(email)){
        cout << "O email é válido\n";
    }
    else{
        cout << "O email é inválido\n";
    }


    return 0;
}