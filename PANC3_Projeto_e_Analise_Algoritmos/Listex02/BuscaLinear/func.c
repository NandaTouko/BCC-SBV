#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarArrayAleatorio(int array[], int tamArray)
{
  srand(time(NULL));

  for (int i = 0; i < tamArray; i++)
  {
    array[i] = rand() % 100;
  }
}

void imprimeArray(int array[], int tamArray)
{
  for (int i = 0; i < tamArray; i++)
  {
    printf("%d ", array[i]);
  }
}

void encontrarPosicao(int array[], int tamArray, int valBusca)
{
  for (int i = 0; i < tamArray; i++)
  {
    if (array[i] == valBusca)
    {
      printf("O valor %d foi encontrado na posicao %d\n", valBusca, (i + 1));
      return;
    }
  }

  printf("Valor nao encontrado no array!\n");
}