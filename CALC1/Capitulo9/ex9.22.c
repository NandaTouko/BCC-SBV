#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirDireita(const char *str);

int main() {
  char string[41];

  printf("String: ");
  fgets(string, 41, stdin);

  string[strlen(string)-1] = '\0';

  imprimirDireita(string);

  return 0;
}

void imprimirDireita(const char *str) {
  int tamanho = strlen(str);
  int buracoEmBraco = 80-tamanho;
  int cont = 0;

  for(int i = 0; i < 80; i++){
    if(i >= buracoEmBraco){
      printf("%c", str[cont]);
      cont++;
    }else{
      printf(" ");
    }
  }
}