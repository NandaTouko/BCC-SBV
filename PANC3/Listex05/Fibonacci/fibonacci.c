#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

int fibonacciRecursivo(int num)
{
	if (num < 2)
	{
		return 1;
	}
	else
	{
		return fibonacciRecursivo(num - 1) + fibonacciRecursivo(num - 2);
	}
}

int fibonacciIterativo(int num)
{
	int i = 1;
	int fib = 1;
	int anterior = 0;

	while (i <= num)
	{
		int temp = fib;
		fib += anterior;
		anterior = temp;
		i++;
	}

	return fib;
}