#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenarArray(int array[], int tamArray);
void imprimeArray(int array[], int tamArray);

int numInstrucoes = 0;

int main()
{
  int tamArray;
  int *array;

  printf("Tamanho do Array: ");
  scanf("%d", &tamArray);

  array = (int *)malloc(tamArray * sizeof(int));

  printf("Array Aleatório: ");

  // Para que rand() não assuma um valor constante
  srand(time(NULL));

  for (int i = 1; i <= tamArray; i++)
  {
    array[i] = rand() % 100;
    printf("%d ", array[i]);
  }

  ordenarArray(array, tamArray);
  printf("\nNumero de Operacoes para ordenacao: %d\n", numInstrucoes);

  return 0;
}

void ordenarArray(int array[], int tamArray)
{
  int chave, i;

  printf("\nOrdenacao\n");
  for (int j = 2; j <= tamArray; j++)
  {
    numInstrucoes++;

    chave = array[j];
    i = j - 1;

    while (i >= 1 && array[i] > chave)
    {
      numInstrucoes++;

      array[i + 1] = array[i];
      i = i - 1;
    }

    array[i + 1] = chave;

    printf("\tArray Desord. [] = ");
    imprimeArray(array, tamArray);
    printf("- %d\n", chave);
  }

  printf("\tArray Ord.    [] = ");
  imprimeArray(array, tamArray);
}

void imprimeArray(int array[], int tamArray)
{
  for (int i = 1; i <= tamArray; i++)
  {
    printf("%d ", array[i]);
  }
}