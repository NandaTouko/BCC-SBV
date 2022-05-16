#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(){
  int array[N];
  int array2[N-1];

  for(int i = 0; i < N; i++){
    printf("array[%d]: ", i);
    scanf("%d", &array[i]);

    if(i > 0){
      array2[i-1] = array[i];
    }
  }

  for(int i = 0; i < N-1; i++){
    printf("array[%d] = %d\n", i, array2[i]);
  }

  return 0;
}