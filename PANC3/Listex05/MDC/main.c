#include <stdio.h>
#include <stdlib.h>
#include "mdc.h"

void main()
{
	int a;
	int b;

	printf("Valor do número A: ");
	scanf("%d", &a);

	printf("Valor do número B: ");
	scanf("%d", &b);

	printf("O MDC entre %d e %d eh %d\n", a, b, mdc(a, b));
}