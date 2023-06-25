#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

/* Função: geraArrayAleatorio() - Gerar numeros inteiros aleatorios para um array de tamanho n */
void geraArrayAleatorio(int arrayOriginal[], int n) {
    int valor;

    srand( time(NULL) );
    for(int i=0; i< n; i++) {
        valor = rand() % 100;
        arrayOriginal[i] = valor;
    }
}

/* Função: imprimeArray() - Imprime os n números inteiros de um array */
void imprimeArray(int arrayA[], int n) {
    printf("\n ");
    for(int i=0; i<n; i++) {
        printf(" %d", arrayA[i]);
    }
}

/* Função: copiaValoresArray() - Copia os valores do Array Original para um Array Temporario,
                                 com o objetivo de nao perder os valores originais na ordenacao */
void copiaValoresArray(int arrayOriginal[], int arrayA[], int n) {
    for(int i=0; i<n; i++) {
        arrayA[i] = arrayOriginal[i];
    }
}

/*Função: insertionSort() - Método de ordenação de arrays de valores inteiros com base no
                            Algoritmo do Insertion Sort (Ordenacao Direta)  */
void insertionSort(int arrayA[], int n) {
    int i, j, chave;
    for (i=1; i<n; i++) {
        chave = arrayA[i];
        j = i - 1;
        while((chave < arrayA[j]) && (j>=0)) {
            arrayA[j+1] = arrayA[j];
            j = j-1;
        }
        arrayA[j+1] = chave;
    }
}

/*Função: insertionSortAlternativo() - Método de ordenação de arrays de valores inteiros com base no
                            Algoritmo do Insertion Sort Alternativo (Ordenacao Direta)  */
void insertionSortAlternativo(int arrayA[], int n) {
    for(int i=1; i<n; i++) {
        for(int j=i; j>0; j--) {
            numComparacoesIS++;
            if(arrayA[j] < arrayA[j-1]) {
                numTrocasIS++;
                int chave = arrayA[j-1];
                arrayA[j-1] = arrayA[j];
                arrayA[j] = chave;
            }
        }
    }
}

/*Função: insertionSortStepByStep() - Método de ordenação de arrays de valores inteiros com base no
                            Algoritmo do Insertion Sort (Ordenacao Direta), mostrando a ordenação
                            passo a passo */
void insertionSortStepByStep(int arrayA[], int n) {
    int i, j, chave;
    for (i=1; i<n; i++) {
        chave = arrayA[i];
        printf(" - %d", chave);
        j = i - 1;
        while((chave < arrayA[j]) && (j>=0)) {
            arrayA[j+1] = arrayA[j];
            j = j-1;
        }
        arrayA[j+1] = chave;
        imprimeArray(arrayA, n);
    }
}

/*Função: MergeSortRecursivo() - Método de ordenção de arrays de valores inteiros com base no
                        Algoritmo do MergeSort/Intercala */

void MergeSortRecursivo(int arrayA[], int n, int inicio, int fim)
{
    int meio;
    if (inicio < fim ) {
        numComparacoesMS++;
        meio = (inicio + fim) / 2;
        MergeSortRecursivo(arrayA, n, inicio, meio);
        MergeSortRecursivo(arrayA, n, meio + 1, fim);
        IntercalaSemSentinela(arrayA, n, inicio, meio, fim);
    }
}

/*Função: IntercalaSemSentinela() - Método de Auxiliar ao Algoritmo do MergeSort/Intercala
                        que realiza a etapa da combinação */
void IntercalaSemSentinela(int arrayA[], int n, int inicio, int meio, int fim) {
    int i, j;
    int Aux[n];


    for(i=inicio; i<=meio; i++) {
        Aux[i] = arrayA[i];
    }

    for(j=meio+1; j<=fim; j++) {
        Aux[fim+meio+1-j] = arrayA[j];
    }

    i=inicio;
    j=fim;

    for(int k=inicio; k<=fim; k++) {
        numTrocasMS++;
        if(Aux[i] <= Aux[j]) {
            arrayA[k] = Aux[i];
            i++;
        } else {
            arrayA[k] = Aux[j];
            j--;
        }
    }
}

/*Função: MergeSortRecursivoStepByStep() - Método de ordenção de arrays de valores inteiros com base no
                        Algoritmo do MergeSort/Intercala, mostrando a ordenação passo a passo */
void MergeSortRecursivoStepByStep(int arrayA[], int n, int inicio, int fim)
{
    int meio;
    if (inicio < fim ) {
        meio = (inicio + fim) / 2;
        MergeSortRecursivoStepByStep(arrayA, n, inicio, meio);
        MergeSortRecursivoStepByStep(arrayA, n, meio + 1, fim);
        IntercalaSemSentinela(arrayA, n, inicio, meio, fim);
    }
    imprimeArray(arrayA, n);
}

/*Função: OrdenaBinaria() - Insere os núumeros em ordem no array por pesquisa binaria. */
void OrdenaBinaria(int arrayA[], int n)
{
    //Variaveis Locais
    int i, j;
    int m, x;
    int L, R;

    for(i=1; i< n; i++)
    {
        x = arrayA[i];

        //Busca do ponto R, para insercao de x
        L = 0;
        R = i;
        while (L < R)
        {
            numComparacoesOB++;
            m = (L + R)/2;
            if (x >= arrayA[m]) L = m+1;
            else R = m;
        }

        //Fazendo a Movimentacao para a Insercao no ponto R
        for(j=i; j>L; j=j-1)
        {
            arrayA[j] = arrayA[j-1];
            numTrocasOB++;
        }


        //Inserindo x na posicao de R de Vet[]
        arrayA[R] = x;
    }
}

/*Função: OrdenaBinariaStepByStep() - Insere os números em ordem no array por pesquisa binaria,
mostrando a ordenação passo a passo */
void OrdenaBinariaStepByStep(int arrayA[], int n) {
    //Variaveis Locais
    int i, j;
    int m, x;
    int L, R;

    for(i=1; i< n; i++)
    {
        x = arrayA[i];
        printf("  -  %d", x);

        //Busca do ponto R, para insercao de x
        L = 0;
        R = i;
        while (L < R)
        {
            m = (L + R)/2;
            if (x >= arrayA[m]) L = m+1;
            else R = m;
        }

        //Fazendo a Movimentacao para a Insercao no ponto R
        for(j=i; j>L; j=j-1)
        {
            arrayA[j] = arrayA[j-1];
        }


        //Inserindo x na posicao de R de Vet[]
        arrayA[R] = x;
        imprimeArray(arrayA, n);
    }
}

/*Função: ShellSort() - Insere os números em ordem no array por shell sort */
void ShellSort(int arrayA[], int inc, int segCorrente, int n) {
    int i, j, x, k;

    for(i = (segCorrente + inc); i < n; i += inc) {
        k = segCorrente;
        j = i - inc;
        x = arrayA[i];

        while(j >= segCorrente && k == segCorrente){
            numComparacoesSS++;
            if(x < arrayA[j]){
                numTrocasSS++;
                arrayA[j+inc] = arrayA[j];
                j = j - inc;
            } else {
                k = j + inc;
            }
        }

        arrayA[k] = x;
    }
}

/*Função: ShellSortStepByStep() - Insere os números em ordem no array por shell sort,
mostrando passo a passo */
void ShellSortStepByStep(int arrayA[], int inc, int segCorrente, int n) {
    int i, j, x, k;

    printf("\nSegmento %d: %d", segCorrente, arrayA[segCorrente]);

    for(i = (segCorrente + inc); i < n; i += inc) {
        k = segCorrente;
        j = i - inc;
        x = arrayA[i];

        printf(", %d", arrayA[i]);

        while(j >= segCorrente && k == segCorrente){
            if(x < arrayA[j]){
                arrayA[j+inc] = arrayA[j];
                j = j - inc;
            } else {
                k = j + inc;
            }
        }

        arrayA[k] = x;
    }
}

/*Função: BubbleSort() - Insere os números em ordem no array por bubble sort */
void BubbleSort(int arrayA[], int n) {
    int aux, i, j;

    for(j = n-1; j >= 1; j--){
        for(i = 0; i < j; i++){
            numComparacoesBS++;
            if(arrayA[i] > arrayA[i+1]){
                numTrocasBS++;
                aux = arrayA[i];
                arrayA[i] = arrayA[i+1];
                arrayA[i+1] = aux;
            }
        }
    }
}

/*Função: BubbleSortStepByStep() - Insere os números em ordem no array por bubble sort,
mostrando passo a passo */
void BubbleSortStepByStep(int arrayA[], int n) {
    int aux, i, j;

    imprimeArray(arrayA, n);

    for(j = n-1; j >= 1; j--){
        for(i = 0; i < j; i++){
            if(arrayA[i] > arrayA[i+1]){
                aux = arrayA[i];
                arrayA[i] = arrayA[i+1];
                arrayA[i+1] = aux;
                imprimeArray(arrayA, n);
            }
        }
    }
}
