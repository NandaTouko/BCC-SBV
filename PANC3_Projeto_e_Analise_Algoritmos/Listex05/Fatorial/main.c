#include <stdio.h>
#include <stdlib.h>
#include "fatorial.h"

void main()
{
	int numFatorar;

	printf("Digite um número para ser fatorado: ");
	scanf("%d", &numFatorar);

	printf("Resultado por Fatorial Recursiva: %ld\n", fatorialRecursivo(numFatorar));
	printf("Resultado por Fatorial Iterativo: %ld\n", fatorialIterativo(numFatorar));
}