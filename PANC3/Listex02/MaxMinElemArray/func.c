#include <stdio.h>
#include <stdlib.h>

void popularArray(int array[], int tamArray)
{
  for (int i = 0; i < tamArray; i++)
  {
    printf("Valor para a posicao %d: ", (i + 1));
    scanf("%d", &array[i]);
  }
}

void maxMin1(int array[], int tamArray)
{
  int max = array[0];
  int min = array[0];
  int numOp1 = 0;

  for (int i = 1; i < tamArray; i++)
  {
    numOp1++;
    if (array[i] > max)
    {
      max = array[i];
    }

    numOp1++;
    if (array[i] < min)
    {
      min = array[i];
    }
  }

  printf("maxMin1() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", max, min, numOp1);
}

void maxMin2(int array[], int tamArray)
{
  int max = array[0];
  int min = array[0];
  int numOp2 = 0;

  for (int i = 1; i < tamArray; i++)
  {
    numOp2++;

    if (array[i] > max)
    {
      max = array[i];
    }
    else if (array[i] < min)
    {
      min = array[i];
    }
  }

  printf("maxMin2() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", max, min, numOp2);
}

void maxMin3(int array[], int tamArray)
{
  if (tamArray % 2 != 0)
  {
    array[tamArray + 1] = array[tamArray];
    tamArray++;
  }

  int max = array[0];
  int min = array[1];
  int tamMenosUm = tamArray - 1;
  int numOp3 = 0;

  numOp3++;

  if (array[0] < array[1])
  {
    max = array[1];
    min = array[0];
  }

  for (int i = 2; i < tamMenosUm; i += 2)
  {
    numOp3++;

    if (array[i] > array[i + 1])
    {
      numOp3++;

      if (array[i] > max)
      {
        max = array[i];
      }

      numOp3++;

      if (array[i + 1] < min)
      {
        min = array[i + 1];
      }
    }
    else
    {
      numOp3++;

      if (array[i] < min)
      {
        min = array[i];
      }

      numOp3++;

      if (array[i + 1] > max)
      {
        max = array[i + 1];
      }
    }
  }

  printf("maxMin3() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", max, min, numOp3);
}