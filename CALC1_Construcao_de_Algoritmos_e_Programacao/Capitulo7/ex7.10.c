#include <stdio.h>
#include <stdlib.h>

int calculaDigito(int n);

int main() {
  int num;

  printf("Numero: ");
  scanf("%d", &num);

  if(num <= 9999 && num >= 1){
    printf("Digito verificador de %d: %d", num, calculaDigito(num));
  }

  return 0;
}

int calculaDigito(int n) {
  int mil = n/1000;
  int cem = (n%1000)/100;
  int dez = ((n%1000)%100)/10;
  int uni = ((n%1000)%100)%10;
  int conta = 0;

  conta = (mil*5) + (cem*4) + (dez*3) + (uni*2);

  conta = conta%11;
  conta = 11 - conta;

  if(conta == 10 || conta == 11){
    return 0;
  }else{
    return conta;
  }
}