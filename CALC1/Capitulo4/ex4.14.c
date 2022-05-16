#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(){
  int array[N];
  int cont = 0;

  for(int i = 0; i < N; i++){
    printf("array[%d]: ", i);
    scanf("%d", &array[i]);
  }

  for(int i = 0; i < N; i++){
    if(array[i]%2 == 1){
      printf("array[%d] = %d\n", cont, array[i]);
      cont++;
    }
  }

  return 0;
}