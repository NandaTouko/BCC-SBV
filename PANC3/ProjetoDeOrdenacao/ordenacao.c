#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

// Funcao gerandoArrayAleatorio(): Define numeros aleatorios de 0 a 100 para um array especifico
void gerandoArrayAleatorio(int arrayOriginal[], int n) {
    srand(time(NULL));

    for(int i = 0; i < n; i++){
        arrayOriginal[i] = rand() % 100;
    }
}

// Funcao imprimeArray(): imprime os n elementos de um array
void imprimeArray(int arrayOriginal[], int n) {
    for(int i = 0; i < n; i++){
        printf(" %d", arrayOriginal[i]);
    }
}

// Funcao insertionSort(): Ordena um array especifico aplicando o metodo de ordenacao por insercao
void insertionSort(int arrayOriginal[], int n) {
    int i, j, chave;

    for(j = 1; j < n; j++){
        chave = arrayOriginal[j];
        i = j - 1;

        while((i >= 0) && (arrayOriginal[i] > chave)){
            arrayOriginal[i+1] = arrayOriginal[i];
            i--;
        }

        arrayOriginal[i+1] = chave;
    }
}

/*
    Função insertionSortAlternativo(): ordena o array especificando
    o metodo de ordenação por inserção com dois for
*/
void insertionSortAlternativo(int arrayOriginal[], int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            if(arrayOriginal[j] < arrayOriginal[j-1]){
                int chave = arrayOriginal[j-1];
                arrayOriginal[j-1] = arrayOriginal[j];
                arrayOriginal[j] = chave;
            }
        }
    }
}

/*
    Funcao copiaValoresEntreArrays(): copia valores inteiros entre arrays
*/
void copiaValoresEntreArrays(int arrayOriginal[], int arrayA[], int n){
    for(int i = 0; i < n; i++){
        arrayA[i] = arrayOriginal[i];
    }
}

/*
    Funcao mergeSortRecursivoSS(): Ordena array especifico utilizando o
    merge sort recursivo com paradigma da divisao e conquista
*/
void mergeSortRecursivoSS(int arrayA[], int inicio, int fim, int n){
    int meio;

    if(inicio < fim){
        meio = (inicio + fim)/2;
        mergeSortRecursivoSS(arrayA, inicio, meio, n);
        mergeSortRecursivoSS(arrayA, (meio+1), fim, n);
        intercalaSemSentinela(arrayA, inicio, meio, fim, n);
    }
}

/*
    Funcao intercalaSemSentinela(): Metodo auxiliar do merge sort para realizar
    a intercalacao de valores
*/
void intercalaSemSentinela(int arrayA[], int inicio, int meio, int fim, int n){
    int i, j;
    int *arrayB;

    arrayB = (int *) malloc(n * sizeof(int));

    for(i = inicio; i <= meio; i++){
        arrayB[i] = arrayA[i];
    }

    for(j = (meio+1); j <= fim; j++){
        arrayB[fim+meio+1-j] = arrayA[j];
    }

    i = inicio;
    j = fim;

    for(int k = inicio; k <= fim; k++){
        if(arrayB[i] <= arrayB[j]){
            arrayA[k] = arrayB[i];
            i++;
        }else{
            arrayA[k] = arrayB[j];
            j--;
        }
    }

    free(arrayB);
}

/*
    Funcao mergeSortRecursivoCS(): Ordena array especifico utilizando o
    merge sort recursivo com paradigma da divisao e conquista, utilizando o intercala com sentinela
*/
void mergeSortRecursivoCS(int arrayA[], int inicio, int fim){
    int meio;

    if(inicio < fim){
        meio = (inicio + fim)/2;
        mergeSortRecursivoCS(arrayA, inicio, meio);
        mergeSortRecursivoCS(arrayA, (meio+1), fim);
        intercalaComSentinela(arrayA, inicio, meio, fim);
    }
}
/*
    Função intercalaComSentinela(): Método auxiliar do nosso merge sort com sentinela para realizar a
    etapa de combinação, intercalando os valores utilizando sentinela
*/
void intercalaComSentinela(int arrayA[], int inicio, int meio, int fim){
    int n1, n2, i, j;

    n1 = meio - inicio + 1;
    n2 = fim - meio;

    int *L, *R;
    L = (int *) malloc(n1 + 1 * sizeof(int));
    R = (int *) malloc(n2 + 1 * sizeof(int));

    for(i = 0; i < n1; i++){
        L[i] = arrayA[inicio+i];
    }
    for(j = 0; j < n2; j++){
        R[j] = arrayA[meio+1+j];
    }

    L[n1] = 30000;
    R[n2] = 30000;

    i = 0;
    j = 0;

    for(int k = inicio; k <= fim; k++){
        if(L[i] <= R[j]){
            arrayA[k] = L[i];
            i++;
        }else{
            arrayA[k] = R[j];
            j++;
        }
    }

    free(L);
    free(R);
}

void insertionSortDecrescente(int arrayOriginal[], int n){
    int i, j, chave;

    for(j = 1; j < n; j++){
        chave = arrayOriginal[j];
        i = j - 1;

        while((i >= 0) && (arrayOriginal[i] < chave)){
            arrayOriginal[i+1] = arrayOriginal[i];
            i--;
        }

        arrayOriginal[i+1] = chave;
    }
}


void mergeSortRecursivoSSDecrescente(int arrayA[], int inicio, int fim, int n) {
    int meio;

    if(inicio < fim){
        meio = (inicio + fim)/2;
        mergeSortRecursivoSSDecrescente(arrayA, inicio, meio, n);
        mergeSortRecursivoSSDecrescente(arrayA, (meio+1), fim, n);
        intercalaSemSentinelaDecrescente(arrayA, inicio, meio, fim, n);
    }
}

void intercalaSemSentinelaDecrescente(int arrayA[], int inicio, int meio, int fim, int n){
    int i, j;
    int *arrayB;

    arrayB = (int *) malloc(n * sizeof(int));

    for(i = inicio; i <= meio; i++){
        arrayB[i] = arrayA[i];
    }

    for(j = (meio+1); j <= fim; j++){
        arrayB[fim+meio+1-j] = arrayA[j];
    }

    i = inicio;
    j = fim;

    for(int k = inicio; k <= fim; k++){
        if(arrayB[i] > arrayB[j]){
            arrayA[k] = arrayB[i];
            i++;
        }else{
            arrayA[k] = arrayB[j];
            j--;
        }
    }

    free(arrayB);
}
