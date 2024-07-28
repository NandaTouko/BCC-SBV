#include <stdio.h>
#include <stdlib.h>
#include "exponencial.h"

void main()
{
	int expoente;

	printf("Digite um expoente para a base 2: ");
	scanf("%d", &expoente);

	int resultado = calcularExponencial(abs(expoente));

	if (expoente > 0)
	{
		printf("2^%d = %d\n", expoente, resultado);
	}
	else
	{
		printf("2^%d = 1/%d\n", expoente, resultado);
	}
}