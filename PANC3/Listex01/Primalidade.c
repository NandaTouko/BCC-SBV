#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ehPrimo(int num);

int numInstrucoes = 0;

int main()
{
  // Para que rand() não assuma um valor constante
  srand(time(NULL));

  int num = (rand() % 100);

  printf("Numero inteiro gerado automaticamente (1-100): %d\n", num);

  if (ehPrimo(num))
  {
    printf("O numero %d eh Primo", num);
  }
  else
  {
    printf("O numero %d NAO eh Primo", num);
  }

  printf(" (Numero de Instruções = %d)\n", numInstrucoes);

  return 0;
}

int ehPrimo(int num)
{
  int metade = num / 2;

  for (int i = 2; i < metade; i++)
  {
    numInstrucoes++;
    if (num % i == 0)
    {
      return 0;
    }
  }

  return 1;
}