#include <stdio.h>
#include <stdlib.h>

int main() {
  int elem;
  int num;

  do{
    printf("Quantidade de elementos (1 a 9): ");
    scanf("%d", &elem);

    if(elem > 9){
      printf("Quantidade incorreta, forneca novamente!\n");
    }
  }while(elem > 9);

  int array[elem];
  int array2[elem+1];

  for(int i = 0; i < elem; i++){
    printf("array[%d]: ", i);
    scanf("%d", &array[i]);
  }

  printf("Valor que sera inserido: ");
  scanf("%d", &num);

  array2[0] = num;

  for(int i = 0; i < elem; i++){
    array2[i+1] = array[i];
  }

  for(int i = 0; i < elem+1; i++){
    printf("array[%d]: %d\n", i, array2[i]);
  }

  return 0;
}