#include <stdio.h>
#include <stdlib.h>

#define N 5

int main() {
  int array[N];
  int array2[N];
  int arraySoma[N];

  printf("Forneca os valores do primeiro array: \n");

  for(int i = 0; i < N; i++){
    printf("\tarray1[%d]: ", i);
    scanf("%d", &array[i]);
  }

  printf("\nForneca os valores do segundo array: \n");

  for(int i = 0; i < N; i++){
    printf("\tarray2[%d]: ", i);
    scanf("%d", &array2[i]);
  }

  for(int i = 0; i < N; i++){
    arraySoma[i] = array[i] + array2[i];
    printf("arraySoma[%d] = %d\n", i, arraySoma[i]);
  }

  return 0;
}