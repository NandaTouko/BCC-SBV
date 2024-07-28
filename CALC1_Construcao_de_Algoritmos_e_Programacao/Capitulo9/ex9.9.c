#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverter(char *destino, const char *origem);

int main() {
  char string[41];
  char invertida[41];

  printf("String: ");
  fgets(string, 41, stdin);

  string[strlen(string)-1] = '\0';

  inverter(invertida, string);

  printf("Invertida: %s", invertida);

  return 0;
}

void inverter(char *destino, const char *origem){
  int tamanho;
  tamanho = strlen(origem);

  for(int i = tamanho; i > 0; i--){
    destino[i-1] = origem[tamanho-i];
  }

  destino[tamanho] = '\0';
}