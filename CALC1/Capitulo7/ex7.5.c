#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool ehPar(int n);
bool ehDivisivel(int dividendo, int divisor);

int main() {
  int n1[5];
  int n2[5];
  bool par;
  bool divisor;

  for(int i = 0; i < 5; i++){
    printf("n1[%d]: ", i);
    scanf("%d", &n1[i]);

    printf("n2[%d]: ", i);
    scanf("%d", &n2[i]);
  }

  for(int i = 0; i < 5; i++){
    par = ehPar(n1[i]);
    divisor = ehDivisivel(n1[i], n2[i]);

    if(par){
      printf("%d eh par e %d ", n1[i], n1[i]);
    }else{
      printf("%d eh impar e %d ", n1[i], n1[i]);
    }

    if(divisor){
      printf("eh divisivel por %d\n", n2[i]);
    }else{
      printf("nao eh divisivel por %d\n", n2[i]);
    }
  }

  return 0;
}

bool ehPar(int n){
  if(n%2 == 0){
    return true;
  }else{
    return false;
  }
}

bool ehDivisivel(int dividendo, int divisor){
  if(dividendo%divisor == 0){
    return true;
  }else{
    return false;
  }
}