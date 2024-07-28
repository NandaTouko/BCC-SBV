#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int contarOcorrencias(const char *str, char c);

int main(){
  char frase[41];
  char vogais[6] = { 'a', 'e', 'i', 'o', 'u' };
  int cont;

  printf("Frase: ");
  fgets(frase, 41, stdin);

  frase[strlen(frase)-1] = '\0';

  for(int i = 0; i < 5; i++){
    cont = contarOcorrencias(frase, vogais[i]);

    printf("%c/%c: %d\n", toupper(vogais[i]), vogais[i], cont);
  }

  return 0;
}

int contarOcorrencias(const char *str, char c) {
  int tamanho = strlen(str);
  int ocorrencias = 0;

  for(int i = 0; i < tamanho; i++){
    if(tolower(str[i]) == c){
      ocorrencias++;
    }
  }

  return ocorrencias;
}