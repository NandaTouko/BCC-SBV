#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"

void main()
{
	int qtdDiscos;

	printf("Digite a quantidade de discos a ser aplicado: ");
	scanf("%d", &qtdDiscos);

	hanoi(qtdDiscos, 1, 3, 2);
}