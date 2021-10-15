#include "funcoes.h"

// Cria e retorna um vetor de inteiros de tamanho n
int* criaVetorAleatorio(int n){
    int* vector = new int[n];

    for(int i=0; i<n; i++){
        vector[i] = 1+(rand() % (n-1)); // valores entre 1 e n-1
    }

    return vector;
}

// Imprime todos os valores de um vetor de inteiros de tamanho n
void imprimeVetor(int* v, int n){
    int quebraLinha = 0;

    for(int i=0; i<n; i++){
        cout << v[i] << " ";

        quebraLinha++;
        if(quebraLinha >= 25){
            cout << endl;
            quebraLinha = 0;
        }
    }
}

// Cria e retorna um vetor de tamanho n, formado pelos inteiros contidos no vetor "origem"
int* clonaVetor(int* origem, int n){
    int* vector = new int[n];

    for(int i=0; i<n; i++){
        vector[i] = origem[i];
    }

    return vector;
}