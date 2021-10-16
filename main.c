#include "funcoes.h"
#include "ordenacao.h"

#define TAMANHO_VETOR 1000000

int main(){
    Analise a;
    iniciarTempo(&a);

    srand(time(NULL)); // seed aleatória

    int* teste = criaVetorAleatorio(TAMANHO_VETOR);
    printf("Vetor teste:\n");
    //imprimeVetor(teste, TAMANHO_VETOR);
    printf("\n");

    //int* teste2 = clonaVetor(teste, TAMANHO_VETOR);
    //printf("Vetor teste 2:\n");
    //imprimeVetor(teste2, TAMANHO_VETOR);
    //printf("\n");

    printf("Aplicando o InsertionSort em teste.\n");
    insertionSort(teste, TAMANHO_VETOR);
    //imprimeVetor(teste, TAMANHO_VETOR);

    //printf("\nAplicando o MergeSort em teste 2.\n");
    //mergeSort(teste2, 0, TAMANHO_VETOR-1);
    //imprimeVetor(teste2, TAMANHO_VETOR);

    free(teste);
    //free(teste2);

    finalizarTempo(&a);
    double tempo = getDeltaTempo(&a);
    printf("\ntempo em milisegundos: %lf\n", tempo*1000);
    printf("tempo em segundos: %lf\n", tempo);
    printf("tempo em minutos: %lf\n", tempo/60);
    printf("tempo em horas: %lf\n", tempo/3600);

    return 0;
}