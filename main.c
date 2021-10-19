#include "funcoes.h"
#include "ordenacao.h"

#define TAMANHO_VETOR 100000
#define T 2.093

int main(){
    srand(time(NULL)); // seed aleatória

    int resultado;
    double media, limite1, limite2;
    Analise a;

    // Vetores para armazenar o tempo gasto de cada algoritmo em cada instancia
    double temposInsertion[20];
    double temposMerge[20];
    double temposRadix[20];

    // 20 instâncias sendo geradas
    for(int instancia = 0; instancia < 20; instancia++){
        // Criando 3 vetores de inteiros aleatórios
        int* v = criaVetorAleatorio(TAMANHO_VETOR);
        int* v2 = clonaVetor(v, TAMANHO_VETOR);
        int* v3 = clonaVetor(v, TAMANHO_VETOR);

        // Executando InsertionSort
        iniciarTempo(&a);
        insertionSort(v, TAMANHO_VETOR);
        finalizarTempo(&a);
        temposInsertion[instancia] = (getDeltaTempo(&a) * 1000);

        // Executando MergeSort
        iniciarTempo(&a);
        mergeSort(v2, 0, TAMANHO_VETOR-1);
        finalizarTempo(&a);
        temposMerge[instancia] = (getDeltaTempo(&a) * 1000);

        // Executando RadixSort
        iniciarTempo(&a);
        radixSort(v3, TAMANHO_VETOR);
        finalizarTempo(&a);
        temposRadix[instancia] = (getDeltaTempo(&a) * 1000);

        free(v);
        free(v2);
        free(v3);
    }

    // Imprimindo os dados do InsertionSort
    media = calculaMedia(temposInsertion, 20);
    testeEstatisticoT(temposInsertion, 20, T, &resultado, &limite1, &limite2);
    printf("Dados do InsertionSort:\n");
    printf("  > Media do tempo: %.4lf milisegundos\n", media*1000);
    printf("  > Intervalo de Confianca: ( %.4lf , %.4lf )\n\n", limite1, limite2);

    // Imprimindo os dados do MergeSort
    media = calculaMedia(temposMerge, 20);
    testeEstatisticoT(temposMerge, 20, T, &resultado, &limite1, &limite2);
    printf("Dados do MergeSort:\n");
    printf("  > Media do tempo: %.4lf milisegundos\n", media*1000);
    printf("  > Intervalo de Confianca: ( %.4lf , %.4lf )\n\n", limite1, limite2);

    // Imprimindo os dados do RadixSort
    media = calculaMedia(temposRadix, 20);
    testeEstatisticoT(temposRadix, 20, T, &resultado, &limite1, &limite2);
    printf("Dados do RadixSort:\n");
    printf("  > Media do tempo: %.4lf milisegundos\n", media*1000);
    printf("  > Intervalo de Confianca: ( %.4lf , %.4lf )\n\n", limite1, limite2);

    // Vetor para armazenar as diferenças
    double* diferenca = malloc(20 * sizeof(double));

    // Comparando o InsertionSort com o MergeSort
    for(int i=0; i<20; i++){
        diferenca[i] = temposInsertion[i] - temposMerge[i];
    }
    testeEstatisticoT(diferenca, 20, T, &resultado, &limite1, &limite2);
    if(resultado == 0){
        printf("Nao ha diferenca estatistica entre o InsertionSort e o MergeSort.\n");
    }
    else if(resultado && calculaMedia(temposInsertion, 20) < calculaMedia(temposMerge, 20)){
        printf("O InsertionSort tem desempenho melhor do que o MergeSort.\n");
    }
    else{
        printf("O InsertionSort tem desempenho pior do que o MergeSort.\n");
    }

    // Comparando o InsertionSort com o RadixSort
    for(int i=0; i<20; i++){
        diferenca[i] = temposInsertion[i] - temposRadix[i];
    }
    testeEstatisticoT(diferenca, 20, T, &resultado, &limite1, &limite2);
    if(resultado == 0){
        printf("Nao ha diferenca estatistica entre o InsertionSort e o RadixSort.\n");
    }
    else if(resultado && calculaMedia(temposInsertion, 20) < calculaMedia(temposRadix, 20)){
        printf("O InsertionSort tem desempenho melhor do que o RadixSort.\n");
    }
    else{
        printf("O InsertionSort tem desempenho pior do que o RadixSort.\n");
    }

    // Comparando o MergeSort com o RadixSort
    for(int i=0; i<20; i++){
        diferenca[i] = temposMerge[i] - temposRadix[i];
    }
    testeEstatisticoT(diferenca, 20, T, &resultado, &limite1, &limite2);
    if(resultado == 0){
        printf("Nao ha diferenca estatistica entre o MergeSort e o RadixSort.\n");
    }
    else if(resultado && calculaMedia(temposInsertion, 20) < calculaMedia(temposRadix, 20)){
        printf("O MergeSort tem desempenho melhor do que o RadixSort.\n");
    }
    else{
        printf("O MergeSort tem desempenho pior do que o RadixSort.\n");
    }

    free(diferenca);

    return 0;
}