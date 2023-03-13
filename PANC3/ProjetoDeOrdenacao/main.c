#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

// Variaveis globais
int n;              // Tamanho do Array
int *arrayOriginal; // Array gerado automaticamente

int main()
{
    printf("Projeto de Algoritmos para Ordenacao\n");
    printf("Entre com o tamanho (n) do Array: ");
    scanf("%d", &n);

    arrayOriginal = (int *)malloc(n * sizeof(int));

    // Gerando n�meros aleatorios para o array original
    gerandoArrayAleatorio(arrayOriginal, n);

    // Imprimindo o Array Original
    printf("Array Original[%d]:", n);
    imprimeArray(arrayOriginal, n);

    // Ordenando pelo m�todo de insertion sort
    insertionSort(arrayOriginal, n);
    printf("\nArray Ordenado[%d]:", n);
    imprimeArray(arrayOriginal, n);

    return 0;
}
