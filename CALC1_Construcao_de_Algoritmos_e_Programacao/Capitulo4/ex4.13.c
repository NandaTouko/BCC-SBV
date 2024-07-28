#include <stdio.h>
#include <stdlib.h>

#define N 10

int main() {
  int array[N];
  int posicao;
  int cont = 0;

  for(int i = 0; i < N; i++){
    printf("array[%d]: ", i);
    scanf("%d", &array[i]);
  }

  do{
    printf("Posicao a ser removida (0 a 9): ");
    scanf("%d", &posicao);

    if(posicao > 9){
      printf("Posicao invalida, forneca novamente!\n");
    }
  }while(posicao > 9);

  for(int i = 0; i < N; i++){
    if(i != posicao){
      printf("array[%d] = %d\n", cont, array[i]);
      cont++;
    }
  }

  return 0;
}