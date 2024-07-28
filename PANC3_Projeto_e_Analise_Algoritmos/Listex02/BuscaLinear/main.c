#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void main()
{
  int tamArray;
  int *array;
  int valBusca;

  printf("Tamanho do Array: ");
  scanf("%d", &tamArray);

  array = (int *)malloc(tamArray * sizeof(int));

  gerarArrayAleatorio(array, tamArray);

  printf("  Array Gerado = ");
  imprimeArray(array, tamArray);

  printf("\nValor inteiro a ser buscado: ");
  scanf("%d", &valBusca);

  encontrarPosicao(array, tamArray, valBusca);
}