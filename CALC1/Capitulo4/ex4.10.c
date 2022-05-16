#include <stdio.h>
#include <stdlib.h>

#define N 5

int main() {
  int array[N];
  int arrayCopia[N];
  int num;
  int cont = 0;

  for(int i = 0; i < N; i++){
    printf("array[%d]: ", i);
    scanf("%d", &array[i]);
  }

  printf("Copiar maiores que: ");
  scanf("%d", &num);

  for(int i = 0; i < N; i++){
    if(array[i] > num){
      arrayCopia[cont] = array[i];
      cont++;
    }
  }

  if(cont == 0){
    printf("Nao houve copia!");
  }else{
    for(int i = 0; i < cont; i++){
      printf("arrayCopia[%d] = %d\n", i, arrayCopia[i]);
    }
  }

  return 0;
}