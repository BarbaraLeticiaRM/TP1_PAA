#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cria e retorna um vetor de tamanho n, formado por inteiros aleatórios
int* criaVetorAleatorio(int n);

// Imprime todos os valores de um vetor de inteiros de tamanho n
void imprimeVetor(int* v, int n);

// Cria e retorna um vetor de tamanho n, formado pelos inteiros contidos no vetor "origem"
int* clonaVetor(int* origem, int n);

typedef struct analise{
    clock_t tempoInicial;
    clock_t tempoFinal;
    double deltaTempo;
}Analise;

void iniciarTempo(Analise* a);
void finalizarTempo(Analise* a);
double getDeltaTempo(Analise* a);

#endif