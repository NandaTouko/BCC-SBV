#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool ehPrimo(int n);

int main() {
  for(int i = 1; i <= 20; i++){
    printf("%d: ", i);

    if(ehPrimo(i)){
      printf("eh primo\n");
    }else{
      printf("nao eh primo\n");
    }
  }

  return 0;
}

bool ehPrimo(int n){
  int cont = 0;

  for(int i = 1; i <= 20; i++){
    if(n%i == 0){
      cont++;
    }
  }

  if(cont == 2){
    return true;
  }else{
    return false;
  }
}