#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"

void hanoi(int num, int origem, int destino, int auxiliar)
{
	if (num > 0)
	{
		hanoi(num - 1, origem, auxiliar, destino);
		mover(origem, destino);
		hanoi(num - 1, auxiliar, destino, origem);
	}
}

void mover(int origem, int destino)
{
	printf("Mover disco da Torre %d para a Torre %d\n", origem, destino);
}