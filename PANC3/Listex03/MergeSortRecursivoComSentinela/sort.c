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

void mergeSortRecursivo(int array[], int inicio, int fim, int tamArray)
{
	if (inicio < fim)
	{
		int meio = (inicio + fim) / 2;
		mergeSortRecursivo(array, inicio, meio, tamArray);
		mergeSortRecursivo(array, (meio + 1), fim, tamArray);
		intercalaComSentinela(array, inicio, meio, fim, tamArray);
	}
}

void intercalaComSentinela(int array[], int inicio, int meio, int fim, int tamArray)
{
	int n1 = meio - inicio + 1;
	int n2 = fim - meio;
	int *L, *R;

	L = (int *)malloc(n1 * sizeof(int));
	R = (int *)malloc(n2 * sizeof(int));

	for (int i = 0; i < n1; i++)
	{
		L[i] = array[inicio + i];
	}

	for (int j = 0; j < n2; j++)
	{
		R[j] = array[meio + j + 1];
	}

	L[n1] = 30000;
	R[n2] = 30000;

	int i = 0;
	int j = 0;

	for (int k = inicio; k <= fim; k++)
	{
		printf("\nArray Ord.[] = ");
		imprimeArray(array, tamArray);

		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
	}

	free(L);
	free(R);
}

void imprimeArray(int array[], int tamArray)
{
	for (int i = 0; i < tamArray; i++)
	{
		printf("%d ", array[i]);
	}
}