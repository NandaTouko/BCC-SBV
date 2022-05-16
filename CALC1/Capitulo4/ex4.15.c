#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5

int main() {
  int array1[N];
  int array2[N];
  int arrayInterseccao[N];
  int cont = 0;
  int naoTem = true;

  printf("Forneca os valores do primeiro array: \n");

  for(int i = 0; i < N; i++){
    printf("\tarray1[%d]: ", i);
    scanf("%d", &array1[i]);
  }

  printf("Forneca os valores do segundo array: \n");

  for(int i = 0; i < N; i++){
    printf("\tarray2[%d]: ", i);
    scanf("%d", &array2[i]);
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(array1[i] == array2[j]){
        if(cont > 0){
          for(int k = 0; k < cont; k++){
            if(array1[i] == arrayInterseccao[k]){
              naoTem = false;
            }
          }
        }

        if(naoTem){
          arrayInterseccao[cont] = array1[i];
          cont++;
        }
      }
      
      naoTem = true;
    }
  }

  if(cont == 0){
    printf("Nao ha interseccao entre os elementos dos dois arrays fornecidos!");
  }else{
    for(int i = 0; i < cont; i++){
      printf("arrayInterseccao[%d] = %d\n", i, arrayInterseccao[i]);
    }
  }

  return 0;
}