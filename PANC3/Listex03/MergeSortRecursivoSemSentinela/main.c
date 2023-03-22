#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void main()
{
	int *array;
	int tamArray;

	printf("Tamanho do Array: ");
	scanf("%d", &tamArray);

	array = (int *)malloc(tamArray * sizeof(int));

	gerarArrayAleatorio(array, tamArray);

	printf("\nOrdenacao");
	printf("\nArray Desord.[] = ");
	imprimeArray(array, tamArray);

	mergeSortRecursivo(array, 0, (tamArray - 1), tamArray);
}