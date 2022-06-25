#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirCentralizado(const char *str);

int main() {
  char string[41];

  printf("String: ");
  fgets(string, 41, stdin);

  string[strlen(string)-1] = '\0';

  imprimirCentralizado(string);

  return 0;
}

void imprimirCentralizado(const char *str) {
  int tamanho = strlen(str);
  int metadeTerminal = (80-tamanho)/2;
  int cont = 0;

  for(int i = 0; i < 80; i++){
    if(i >= metadeTerminal && cont < tamanho){
      printf("%c", str[cont]);
      cont++;
    }else{
      printf(" ");
    }
  }
}