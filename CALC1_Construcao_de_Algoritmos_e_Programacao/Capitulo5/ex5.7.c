#include <stdio.h>
#include <stdlib.h>

#define I 3
#define J 2

int main() {
  int a[I][J];
  int b[J][I];
  int aXb[I][I];
  int aux = 0;

  for(int i = 0; i < I; i++){
    for(int j = 0; j < J; j++){
      printf("array1[%d][%d]: ", i, j);
      scanf("%d", &a[i][j]);
    }
  }

  for(int i = 0; i < J; i++){
    for(int j = 0; j < I; j++){
      printf("array2[%d][%d]: ", i, j);
      scanf("%d", &b[i][j]);
    }
  }

  for(int i = 0; i < I; i++){
    for(int j = 0; j < I; j++){
      for(int k = 0; k < J; k++){
        aux += a[i][k] * b[k][j];
      }

      aXb[i][j] = aux;
      aux = 0;
    }
  }

  printf("A x B =\n");

  for(int i = 0; i < I; i++){
    for(int j = 0; j < I; j++){
      printf("%03d", aXb[i][j]);

      if(j != 2){
        printf(" ");
      }
    }

    printf("\n");
  }

  return 0;
}