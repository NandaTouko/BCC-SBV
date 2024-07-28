#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

void main()
{
	int num;

	printf("Digite um numero: ");
	scanf("%d", &num);

	printf("Resultado por Fibonacci Recursivo: %d\n", fibonacciRecursivo(num));
	printf("Resultado por Fibonacci Iterativo: %d\n", fibonacciIterativo(num));
}