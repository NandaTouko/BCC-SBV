#include <stdio.h>
#include <stdlib.h>

int maxElemArray(int array[], int tamArray);

int numInstrucoes = 0;

int main()
{
	printf("Ex01 - Maximo Elemento De Um Array\n");

	int tamArray;
	int *array;

	printf("Tamanho do array: ");
	scanf("%d", &tamArray);

	array = (int *)malloc(tamArray * sizeof(int));

	printf("Forneca valores as posicoes:\n");

	for (int i = 0; i < tamArray; i++)
	{
		printf("array[%d]: ", i);
		scanf("%d", &array[i]);
	}

	printf("Máximo Elemento: %d\n", maxElemArray(array, tamArray));
	printf("Numero de Instrucoes: %d\n", numInstrucoes);

	return 0;
}

int maxElemArray(int array[], int tamArray)
{
	int maior = array[0];

	for (int i = 1; i < tamArray; i++)
	{
		numInstrucoes++;
		if (maior < array[i])
		{
			maior = array[i];
		}
	}

	return maior;
}