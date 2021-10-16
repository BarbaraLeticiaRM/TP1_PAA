#include "ordenacao.h"
#include "funcoes.h"

// Realiza o InsertionSort em um vetor de inteiros v, de tamanho n
void insertionSort(int* v, int n){
    int j;
    int carta; // chave que sera inserida a cada iteração do loop for

    for(int i = 1; i < n; i++) {
        carta = v[i];
        j = i - 1;

        while(j >= 0 && v[j] > carta){
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = carta;
    }
}

// Realiza o MergeSort em um vetor de inteiros v, com o indice inicial "comeco" e indice final "fim"
void mergeSort(int* v, int comeco, int fim){
    if(comeco < fim){
        int meio = (comeco+fim)/2;

        mergeSort(v, comeco, meio);
        mergeSort(v, meio+1, fim);
        merge(v, comeco, meio, fim);
    }
}

// Funcao auxiliar de mergeSort()
void merge(int* v, int comeco, int meio, int fim) {
    int i = comeco; // Variável de controle do primeiro "sub-vetor"
    int j = meio+1; // Variável de controle do segundo "sub-vetor"
    int k = 0;      // Variável de controle do vetor auxiliar  
    int n = fim-comeco+1;

    int *vAux = malloc(n * sizeof(int)); // Vetor auxiliar

    while(i <= meio && j <= fim){
        if(v[i] < v[j]) {
            vAux[k] = v[i];
            i++;
        } else {
            vAux[k] = v[j];
            j++;
        }
        k++;
    }

    //Caso ainda haja elementos na primeira metade
    while(i <= meio){
        vAux[k] = v[i];
        k++;
        i++;
    }

    //Caso ainda haja elementos na segunda metade
    while(j <= fim) {
        vAux[k] = v[j];
        k++;
        j++;
    }

    //Move os elementos de volta para o vetor original
    for(k = comeco; k <= fim; k++){
        v[k] = vAux[k-comeco];
    }
    
    free(vAux);
}
