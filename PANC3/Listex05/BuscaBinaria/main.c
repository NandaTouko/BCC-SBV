#include <stdio.h>
#include <stdlib.h>
#include "busca.h"

void main()
{
	int tamArray;
	int *array;
	int busca;
	int posicao;

	printf("Tamanho do Array: ");
	scanf("%d", &tamArray);

	array = (int *)malloc(tamArray * sizeof(int));

	popularArray(array, tamArray);

	printf("Valor a ser buscado: ");
	scanf("%d", &busca);

	posicao = buscaBinaria(busca, array, 0, (tamArray - 1));

	if (posicao < 0)
	{
		printf("Valor não encontrado!\n");
	}
	else
	{
		printf("Valor encontrado na posicao %d!\n", posicao);
	}
}