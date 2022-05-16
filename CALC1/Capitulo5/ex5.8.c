#include <stdio.h>
#include <stdlib.h>

int main() {
  int num;

  printf("Numero entre 1 e 100: ");
  scanf("%d", &num);

  if(num >= 1 && num <= 100){
    for(int i = 0; i < num; i++){
      printf("%3d ", 1);
      for(int j = 0; j < num; j++){
        printf("%3d ", i+1);
      }

      printf("\n");
    }
  }else{
    printf("Numero incorreto!");
  }

  return 0;
}