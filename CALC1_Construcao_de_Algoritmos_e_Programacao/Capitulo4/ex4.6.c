#include <stdio.h>
#include <stdlib.h>

#define N 5

int main() {
  int array[N];
  int indices[N];
  int num;
  int cont = 0;

  for(int i = 0; i < N; i++){
    printf("array[%d]: ", i);
    scanf("%d", &array[i]);
  }

  printf("Buscar por: ");
  scanf("%d", &num);

  for(int i = 0; i < N; i++){
    if(num == array[i]){
      indices[cont] = i;
      cont++;
    }
  }

  if(cont == 0){
    printf("O array nao contem o valor %d.", num);
  }else{
    if(cont > 1){
      printf("O valor %d foi encontrado nos indices ", num);
    }else{
      printf("O valor %d foi encontrado no indice ", num);
    }

    for(int i = 0; i < cont; i++){
      printf("%d", indices[i]);

      if(i == cont-2){
        printf(" e ");
      }else if(i < cont-2){
        printf(", ");
      }
    }

    printf(" do array.");
  }

  return 0;
}