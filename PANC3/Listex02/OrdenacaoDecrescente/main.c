#include <stdio.h>
#include <stdlib.h>
#include "order.h"

void main()
{
  int tamArray;
  int *array;

  printf("Tamanho do Array: ");
  scanf("%d", &tamArray);

  array = (int *)malloc(tamArray * sizeof(int));

  gerarArrayAleatorio(array, tamArray);

  printf("Ordenacao\n");
  printf("  Array Desord.[] = ");
  imprimirArray(array, tamArray);
  printf("\n");

  insertionSortRevert(array, tamArray);

  printf("  Array Ord.[] = ");
  imprimirArray(array, tamArray);

  printf("\n  Numero de Operacoes para Ordenacao: %d\n", numOperacoes);
}