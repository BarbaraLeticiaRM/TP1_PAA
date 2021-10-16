#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdio.h>
#include <stdlib.h>

// InsertionSort
void insertionSort(int* v, int n);

// Realiza o MergeSort em um vetor de inteiros v, com o indice inicial "comeco" e indice final "fim"
void mergeSort(int* v, int comeco, int fim);
void merge(int* v, int comeco, int meio, int fim);

// RadixSort

#endif