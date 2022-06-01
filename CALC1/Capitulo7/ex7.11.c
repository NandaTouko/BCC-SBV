#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int obtemNumero(int n);
int obtemDigito(int n);
int calculaDigito(int n);
bool numeroCorreto(int dig, int digCalc);

int main() {
  int num;
  int dig;
  int numSDig;
  int digCalc;

  printf("Numero: ");
  scanf("%d", &num);

  if(num >= 10 && num <= 99999){
    dig = obtemDigito(num);
    numSDig = obtemNumero(num);
    digCalc = calculaDigito(numSDig);

    printf("Numero completo: %d\n", num);
    printf("Numero: %d\n", numSDig);
    printf("Digito: %d\n", dig);
    printf("Digito calculado: %d\n", digCalc);

    if(numeroCorreto(dig, digCalc)){
      printf("O numero fornecido esta correto!");
    }else{
      printf("O numero fornecido esta incorreto!");
    }
  }

  return 0;
}

int obtemNumero(int n) {
  return n/10;
}

int obtemDigito(int n) {
  return ((n%1000)%100)%10;
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

bool numeroCorreto(int dig, int digCalc) {
  if(dig == digCalc){
    return true;
  }else{
    return false;
  }
}