#include <stdio.h>
#include <stdlib.h>
#include "fatorial.h"

long fatorialRecursivo(int num)
{
	if (num <= 1)
	{
		return 1;
	}

	return num * fatorialRecursivo(num - 1);
}

long fatorialIterativo(int num)
{
	int fat = 1;

	for (int i = 1; i <= num; i++)
	{
		fat *= i;
	}

	return fat;
}