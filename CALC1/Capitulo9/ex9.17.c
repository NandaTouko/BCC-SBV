#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarPalavras(const char *str);

int main() {
  char frase[41];

  printf("Frase: ");
  fgets(frase, 41, stdin);

  printf("Quantidade de palavras: %d", contarPalavras(frase));

  return 0;
}

int contarPalavras(const char *str){
  int tamanho = strlen(str);
  int contPalavras = 1;

  for(int i = 0; i < tamanho; i++){
    if(str[i] == ' '){
      contPalavras++;
    }
  }

  return contPalavras;
}