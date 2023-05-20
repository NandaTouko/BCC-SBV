#include <stdio.h>
#include <stdlib.h>
#include "exponencial.h"

int calcularExponencial(int expoente)
{
	if (expoente > 0)
	{
		return 2 * calcularExponencial(expoente - 1);
	}
	else
	{
		return 1;
	}
}