#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "order.h"

int numOperacoes = 0;

void gerarArrayAleatorio(int array[], int tamArray)
{
  srand(time(NULL));

  for (int i = 0; i < tamArray; i++)
  {
    array[i] = rand() % 100;
  }
}

void imprimirArray(int array[], int tamArray)
{
  for (int i = 0; i < tamArray; i++)
  {
    printf(" %d", array[i]);
  }
}

void insertionSortRevert(int array[], int tamArray)
{
  int key, i;

  for (int j = 1; j < tamArray; j++)
  {
    numOperacoes++;

    key = array[j];
    i = j - 1;

    while ((i >= 0) && (array[i] < key))
    {
      numOperacoes++;

      array[i + 1] = array[i];
      i--;
    }

    array[i + 1] = key;

    printf("  Array Ord. Decrescente[] = ");
    imprimirArray(array, tamArray);
    printf(" - %d\n", key);
  }
}