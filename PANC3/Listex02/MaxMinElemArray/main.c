#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void main()
{
	int tamArray;
	int *array;

	printf("Tamanho do Array: ");
	scanf("%d", &tamArray);

	array = (int *)malloc(tamArray * sizeof(int));

	popularArray(array, tamArray);

	maxMin1(array, tamArray);
	maxMin2(array, tamArray);
	maxMin3(array, tamArray);
}