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
    printf("\n\nOrdenacao por InsertionSort(): ");
    printf("\nArray Original[%d]:", n);
    imprimeArray(arrayOriginal, n);
    copiaValoresEntreArrays(arrayOriginal, arrayA, n);
    insertionSort(arrayA, n);
    printf("\nArray Ordenado[%d]:", n);
    imprimeArray(arrayA, n);

    // Ordenando pelo metodo de insertion alternativo
    printf("\n\nOrdenacao por InsertionSortAlternativo(): ");
    printf("\nArray Original[%d]:", n);
    imprimeArray(arrayOriginal, n);
    copiaValoresEntreArrays(arrayOriginal, arrayA, n);
    insertionSortAlternativo(arrayA, n);
    printf("\nArray Ordenado[%d]:", n);
    imprimeArray(arrayA, n);

    // Ordenando pelo metodo de Merge Sort sem sentinela
    printf("\n\nOrdenacao por MergeSortRecursivo(): ");
    printf("\nArray Original[%d]:", n);
    imprimeArray(arrayOriginal, n);
    copiaValoresEntreArrays(arrayOriginal, arrayA, n);
    mergeSortRecursivo(arrayA, 0, n-1);
    printf("\nArray Ordenado[%d]:", n);
    imprimeArray(arrayA, n);

    return 0;
}
