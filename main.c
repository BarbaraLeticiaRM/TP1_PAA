#include "funcoes.h"
#include "ordenacao.h"

int main(){
    Analise a;
    iniciarTempo(&a);

    srand(time(NULL)); // seed aleatória

    int* teste = criaVetorAleatorio(100);
    imprimeVetor(teste, 100);

    printf("\n");
    int* teste2 = clonaVetor(teste, 100);
    imprimeVetor(teste2, 100);

    printf("depois da alteracao:\n\n");
    teste[0] = 99999;
    imprimeVetor(teste, 100);
    printf("\n");
    imprimeVetor(teste2, 100);

    free(teste);
    free(teste2);

    while(1){
        if(getchar())
            break;
    }

    finalizarTempo(&a);
    double tempo = getDeltaTempo(&a);
    printf("tempo em ms: %lf\n", tempo);
    printf("tempo em s: %lf\n", tempo/1000);

    return 0;
}