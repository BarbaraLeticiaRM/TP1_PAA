#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>
#include <cstdlib>

using namespace std;

// Cria e retorna um vetor de tamanho n, formado por inteiros aleatórios
int* criaVetorAleatorio(int n);

// Imprime todos os valores de um vetor de inteiros de tamanho n
void imprimeVetor(int* v, int n);

// Cria e retorna um vetor de tamanho n, formado pelos inteiros contidos no vetor "origem"
int* clonaVetor(int* origem, int n);

#endif