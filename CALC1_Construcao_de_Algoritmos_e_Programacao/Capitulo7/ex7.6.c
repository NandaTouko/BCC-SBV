#include <stdio.h>
#include <stdlib.h>

int lePositivo(int i);
int somaDivisores(int dividendo);

int main() {
  int valor[5];

  for(int i = 0; i < 5; i++){
    valor[i] = lePositivo(i);
  }

  for(int i = 0; i < 5; i++){
    printf("Soma dos divisores de %d: %d\n", valor[i], somaDivisores(valor[i]));
  }

  return 0;
}

int lePositivo(int i){
  int num;

  printf("n[%d]: ", i);
  scanf("%d", &num);

  while(num < 0){
      printf("Entre com um valor positivo: ");
      scanf("%d", &num);
  }

  return num;
}

int somaDivisores(int dividendo){
  int soma = 0;

  for(int i = 1; i < dividendo; i++){
    if(dividendo%i == 0){
      soma += i;
    }
  }

  return soma;
}