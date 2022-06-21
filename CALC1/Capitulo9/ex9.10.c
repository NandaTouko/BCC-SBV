#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanho(const char *str);

int main() {
  char frase[41];

  printf("Frase: ");
  fgets(frase, 41, stdin);

  frase[strlen(frase)-1] = '\0';

  printf("%d caractere(s)!", tamanho(frase));

  return 0;
}

int tamanho(const char *str){
  int cont = 0;

  while(str[cont] != '\0'){
    cont++;
  }

  return cont;
}