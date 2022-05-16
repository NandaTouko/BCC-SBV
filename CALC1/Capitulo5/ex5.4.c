#include <stdio.h>
#include <stdlib.h>

#define I 2
#define J 2

int main(){
  int array[I][J];
  int det;

  for(int i = 0; i < I; i++){
    for(int j = 0; j < J; j++){
      printf("array[%d][%d]: ", i, j);
      scanf("%d", &array[i][j]);
    }
  }

  det = array[0][0] * array[1][1] - (array[0][1] * array[1][0]);

  printf("Determinante: %d", det);

  return 0;
}