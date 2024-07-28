#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

// Variaveis globais
int n;              // Tamanho do Array
int *arrayOriginal; // Array gerado automaticamente
int *arrayA; // Array temporario utilizado para não perder os dados do array original

int main()
{
    printf("Projeto de Algoritmos para Ordenacao\n");
    printf("Entre com o tamanho (n) do Array: ");
    scanf("%d", &n);

    arrayOriginal = (int *)malloc(n * sizeof(int));
    arrayA = (int *)malloc(n * sizeof(int));

    // Gerando n�meros aleatorios para o array original
    gerandoArrayAleatorio(arrayOriginal, n);

    // Imprimindo o Array Original
    printf("Array Original Gerado[%d]:", n);
    imprimeArray(arrayOriginal, n);

    // Ordenando pelo metodo de insertion sort
    printf("\n\nOrdenacao por InsertionSort: ");
    printf("\nArray Original[%d]:", n);
    imprimeArray(arrayOriginal, n);
    copiaValoresEntreArrays(arrayOriginal, arrayA, n);
    insertionSort(arrayA, n);
    printf("\nArray Ordenado[%d]:", n);
    imprimeArray(arrayA, n);

    // Ordenando pelo metodo de insertion alternativo
    printf("\n\nOrdenacao por InsertionSort Alternativo: ");
    printf("\nArray Original[%d]:", n);
    imprimeArray(arrayOriginal, n);
    copiaValoresEntreArrays(arrayOriginal, arrayA, n);
    insertionSortAlternativo(arrayA, n);
    printf("\nArray Ordenado[%d]:", n);
    imprimeArray(arrayA, n);

    // Ordenando pelo metodo de Merge Sort sem sentinela
    printf("\n\nOrdenacao por MergeSort Sem Sentinela: ");
    printf("\nArray Original[%d]:", n);
    imprimeArray(arrayOriginal, n);
    copiaValoresEntreArrays(arrayOriginal, arrayA, n);
    mergeSortRecursivoSS(arrayA, 0, n-1, n);
    printf("\nArray Ordenado[%d]:", n);
    imprimeArray(arrayA, n);

    // Ordenando pelo metodo de Merge Sort com sentinela
    printf("\n\nOrdenacao por MergeSort Com Sentinela: ");
    printf("\nArray Original[%d]:", n);
    imprimeArray(arrayOriginal, n);
    copiaValoresEntreArrays(arrayOriginal, arrayA, n);
    mergeSortRecursivoCS(arrayA, 0, n-1);
    printf("\nArray Ordenado[%d]:", n);
    imprimeArray(arrayA, n);

    // Ordenando pelo metodo de insertion sort decrescente
    printf("\n\nOrdenacao por Insertion Sort Decrescente: ");
    printf("\nArray Original[%d]:", n);
    imprimeArray(arrayOriginal, n);
    copiaValoresEntreArrays(arrayOriginal, arrayA, n);
    insertionSortDecrescente(arrayA, n);
    printf("\nArray Decrescente[%d]:", n);
    imprimeArray(arrayA, n);

    // Ordenando pelo metodo de Merge Sort sem sentinela decrescente
    printf("\n\nOrdenacao por Merge Sort Sem Sentinela Decrescente: ");
    printf("\nArray Original[%d]:", n);
    imprimeArray(arrayOriginal, n);
    copiaValoresEntreArrays(arrayOriginal, arrayA, n);
    mergeSortRecursivoSSDecrescente(arrayA, 0, n-1, n);
    printf("\nArray Decrescente[%d]:", n);
    imprimeArray(arrayA, n);

    return 0;
}
