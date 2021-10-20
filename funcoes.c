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

// Retorna a média de um vetor de double, com tamanho n
double calculaMedia(double* v, int n){
    double soma = 0;

    for(int i = 0; i < n; i++){
        soma += v[i];
    }

    if(n == 0)
        return 0;
    else
        return soma / n;
}

// Retorna o desvio padrão de um vetor de double, com tamanho n
double calculaDesvioPadrao(double* v, int n){
    double media = calculaMedia(v, n);
    double somatorio = 0;

    for(int i = 0; i < n; i++){
        somatorio += pow((v[i] - media), 2);
    }

    if(n == 0)
        return 0;
    else
        return sqrt(somatorio / (n - 1) );
}

// Executa um teste estatistico T em um vetor de double, de tamanho n, e sendo T a constante que se encontra
// na tabela
void testeEstatisticoT(double* v, int n, double T, int* resultado, double* limite1, double* limite2){
    double media = calculaMedia(v, n);
    double desvioPadrao = calculaDesvioPadrao(v, n);
    *limite1 = media - T * (desvioPadrao / sqrt(n));
    *limite2 = media + T * (desvioPadrao / sqrt(n));

    // Não há diferença estatística
    if(*limite1 <= 0 && *limite2 > 0)
        *resultado = 0;
    // Há diferença estatística, caso o teste for pareado, o primeiro vetor tem pior desempenho
    else if(*limite1 > 0 && *limite2 > 0)
        *resultado = -1;
    // Há diferença estatística, caso o teste for pareado, o primeiro vetor tem melhor desempenho
    else
        *resultado = 1;
}