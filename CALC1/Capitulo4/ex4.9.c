#include <stdio.h>
#include <stdlib.h>

#define N 5

int main() {
  int array[N];
  int arrayInv[N];
  int cont = 4;

  for(int i = 0; i < N; i++){
    printf("array[%d]: ", i);
    scanf("%d", &array[i]);
  }

  for(int i = 0; i < N; i++){
    arrayInv[i] = array[cont];
    cont--;

    printf("arrayInv[%d] = %d\n", i, arrayInv[i]);
  }

  return 0;
}