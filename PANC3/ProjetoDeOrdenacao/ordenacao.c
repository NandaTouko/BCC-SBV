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
    Funcao mergeSortRecursivo(): Ordena array especifico utilizando o
    merge sort recursivo com paradigma da divisao e conquista
*/
void mergeSortRecursivo(int arrayA[], int inicio, int fim){
}

/*
    Funcao intercalaSemSentinela(): Metodo auxiliar do merge sort para realizar
    a intercalacao de valores
*/
void intercalaSemSentinela(int arrayA[], int inicio, int meio, int fim){
}

