#include <stdio.h>
#include <stdlib.h>

int main() {
  int d[100][100] = { 0 }; // comecei tudo com 0
  int num;

  printf("Numero entre 1 e 100: ");
  scanf("%d", &num);

  if(num >= 1 && num <= 100){
    for(int c = 0; c <= num/2; c++){
        for(int i = 0+c; i < num-c; i++){
            for(int j = 0+c; j < num-c; j++){
                d[i][j]++; // incrementa cada posição
            }
        }
    }

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            printf("%3d", d[i][j]);
        }

        printf("\n");
    }
  }else{
    printf("Numero incorreto!");
  }


  return 0;
}
