#include <stdio.h>
#include <stdlib.h>
#include "busca.h"

void popularArray(int array[], int tamArray)
{
	printf("Preencha o array com números ordenados!\n");

	for (int i = 0; i < tamArray; i++)
	{
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
	}
}

int buscaBinaria(int busca, int array[], int inicio, int fim)
{
	int meio = (inicio + fim) / 2;

	if (array[meio] == busca)
	{
		return meio;
	}

	if (inicio >= fim)
	{
		return -1; // Não encontrado
	}
	else
	{
		if (array[meio] < busca)
		{
			buscaBinaria(busca, array, (meio + 1), fim);
		}
		else
		{
			buscaBinaria(busca, array, inicio, (meio - 1));
		}
	}
}