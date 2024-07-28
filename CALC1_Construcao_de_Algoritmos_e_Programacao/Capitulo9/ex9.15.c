#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void tornarMinuscula(char *str);

int main(){
  char frase[41];

  printf("Frase: ");
  fgets(frase, 41, stdin);

  frase[strlen(frase)-1] = '\0';

  tornarMinuscula(frase);

  printf("%s", frase);

  return 0;
}

void tornarMinuscula(char *str){
  int tamanho = strlen(str);

  for(int i = 0; i < tamanho; i++){
    if(isupper(str[i])){
      str[i] = tolower(str[i]);
    }
  }
}