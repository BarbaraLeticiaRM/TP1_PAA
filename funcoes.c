#include "funcoes.h"

// Cria e retorna um vetor de inteiros de tamanho n
int* criaVetorAleatorio(int n){
    int* vector = malloc(n * sizeof(int));

    for(int i=0; i<n; i++){
        vector[i] = 1+(rand() % (n-1)); // valores entre 1 e n-1
    }

    return vector;
}

// Imprime todos os valores de um vetor de inteiros de tamanho n
void imprimeVetor(int* v, int n){
    int quebraLinha = 0;

    for(int i=0; i<n; i++){
        printf("%d ",v[i]);

        quebraLinha++;
        if(quebraLinha >= 25){
            printf("\n");
            quebraLinha = 0;
        }
    }
}

// Cria e retorna um vetor de tamanho n, formado pelos inteiros contidos no vetor "origem"
int* clonaVetor(int* origem, int n){
    int* vector = malloc(n * sizeof(int));

    for(int i=0; i<n; i++){
        vector[i] = origem[i];
    }

    return vector;
}

void iniciarTempo(Analise* a){
    a->tempoInicial = clock();
}

void finalizarTempo(Analise* a){
    a->tempoFinal = clock();
    
    a->deltaTempo = (double)(a->tempoFinal - a->tempoInicial) / CLOCKS_PER_SEC;
}

double getDeltaTempo(Analise* a){
    return a->deltaTempo;
}