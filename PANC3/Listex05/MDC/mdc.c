#include <stdio.h>
#include <stdlib.h>
#include "mdc.h"

int mdc(int a, int b)
{
	int resto = a % b;

	if (resto > 0)
	{
		return mdc(b, resto);
	}
	else
	{
		return b;
	}
}