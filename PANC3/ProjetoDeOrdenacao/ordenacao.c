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
