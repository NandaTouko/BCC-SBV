#include <stdio.h>
#include <stdlib.h>

int calculaDigito(int n);

int main() {
  int num;

  printf("Numero: ");
  scanf("%d", &num);

  if(num <= 1999 && num >= 1){
    printf("Digito verificador de %d: %d", num, calculaDigito(num));
  }

  return 0;
}

int calculaDigito(int n) {
  
}