#include "funcoes.h"

using namespace std;

int main(){
    srand(time(NULL)); // seed aleatória

    int* teste = criaVetorAleatorio(100);
    imprimeVetor(teste, 100);

    cout << endl;
    int* teste2 = clonaVetor(teste, 100);
    imprimeVetor(teste2, 100);

    cout << "depois da alteracao:" << endl << endl;
    teste[0] = 99999;
    imprimeVetor(teste, 100);
    cout << endl;
    imprimeVetor(teste2, 100);

    delete [] teste;
    delete [] teste2;

    return 0;
}