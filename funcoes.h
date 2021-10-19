#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

// Retorna a média de um vetor de double, com tamanho n
double calculaMedia(double* v, int n);

// Retorna o desvio padrão de um vetor de double, com tamanho n
double calculaDesvioPadrao(double* v, int n);

// Executa um teste estatistico T em um vetor de double, de tamanho n, e sendo T a constante que se encontra
// na tabela
void testeEstatisticoT(double* v, int n, double T, int* resultado, double* limite1, double* limite2);

#endif