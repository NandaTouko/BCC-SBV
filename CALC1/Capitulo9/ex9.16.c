#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void removerLetra(char *str, char c);

int main(){
  char frase[41];
  char caractere;

  printf("Frase: ");
  fgets(frase, 41, stdin);

  printf("Caractere: ");
  scanf(" %c", &caractere);

  removerLetra(frase, caractere);

  return 0;
}

void removerLetra(char *str, char c){
  int tamanho = strlen(str);
  char novaFrase[41];
  char caractere[2] = { toupper(c), tolower(c) };
  int cont = 0;

  for(int i = 0; i < tamanho; i++){
    if(str[i] != caractere[0] && str[i] != caractere[1]){
      novaFrase[cont] = str[i];
      cont++;
    }
  }

  novaFrase[cont] = '\0';

  printf("%s", novaFrase);
}