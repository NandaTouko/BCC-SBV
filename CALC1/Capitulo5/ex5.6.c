#include <stdio.h>
#include <stdlib.h>

#define I 2
#define J 3

int main() {
  int m[I][J];
  int mT[I][J];

  for(int i = 0; i < I; i++){
    for(int j = 0; j < J; j++){
      printf("array[%d][%d]: ", i, j);
      scanf("%d", &m[i][j]);

      mT[j][i] = m[i][j];
    }
  }

  printf("M:\n");

  for(int i = 0; i < I; i++){
    for(int j = 0; j < J; j++){
      printf("%03d", m[i][j]);

      if(j != 2){
        printf(" ");
      }
    }

    printf("\n");
  }

  printf("\nMt:\n");

  for(int i = 0; i < J; i++){
    for(int j = 0; j < I; j++){
      printf("%03d", mT[i][j]);

      if(j != 1){
        printf(" ");
      }
    }

    printf("\n");
  }

  return 0;
}