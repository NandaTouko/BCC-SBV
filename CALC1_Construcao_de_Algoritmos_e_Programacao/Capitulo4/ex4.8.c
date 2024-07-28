#include <stdio.h>
#include <stdlib.h>

#define N 5

int main() {
  int array[N];
  int contPar = 0;
  int contImpar = 0;

  for(int i = 0; i < N; i++){
    printf("array[%d]: ", i);
    scanf("%d", &array[i]);
  }

  printf("Numeros pares:");

  for(int i = 0; i < N; i++){
    if(array[i]%2 == 0){
      printf(" %d", array[i]);
      contPar++;
    }
  }

  contPar == 0 ? printf(" nao ha.\n") : printf(".\n");

  printf("Numeros impares:");

  for(int i = 0; i < N; i++){
    if(array[i]%2 != 0){
      printf(" %d", array[i]);
      contImpar++;
    }
  }

  contImpar == 0 ? printf(" nao ha.") : printf(".");

  return 0;
}