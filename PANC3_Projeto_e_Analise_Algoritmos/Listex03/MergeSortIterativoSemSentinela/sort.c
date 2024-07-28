#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

void gerarArrayAleatorio(int array[], int tamArray)
{
	srand(time(NULL));

	for (int i = 0; i < tamArray; i++)
	{
		array[i] = rand() % 100;
	}
}

void mergeSortIterativo(int array[], int tamArray)
{
	int b = 1;

	while (b < tamArray)
	{
		int inicio = 0;

		while ((inicio + b) < tamArray)
		{
			int fim = inicio + 2 * b;

			if (fim > tamArray)
				fim = tamArray;

			intercalaSemSentinela(array, inicio, (inicio + b), fim, tamArray);

			inicio = inicio + 2 * b;
		}

		b = 2 * b;
	}
}

void intercalaSemSentinela(int array[], int inicio, int meio, int fim, int tamArray)
{
	int *array2;
	array2 = (int *)malloc(tamArray * sizeof(int));

	for (int i = inicio; i <= meio; i++)
	{
		array2[i] = array[i];
	}

	for (int j = (meio + 1); j <= fim; j++)
	{
		array2[fim + meio + 1 - j] = array[j];
	}

	int i = inicio;
	int j = fim;

	for (int k = inicio; k <= fim; k++)
	{
		printf("\nArray Ord.[] = ");
		imprimeArray(array, tamArray);

		if (array2[i] <= array2[j])
		{
			array[k] = array2[i];
			i++;
		}
		else
		{
			array[k] = array2[j];
			j--;
		}
	}
}

void imprimeArray(int array[], int tamArray)
{
	for (int i = 0; i < tamArray; i++)
	{
		printf("%d ", array[i]);
	}
}