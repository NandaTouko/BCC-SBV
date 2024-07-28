#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void tornarMaiuscula(char *str);

int main(){
  char frase[41];

  printf("Frase: ");
  fgets(frase, 41, stdin);

  frase[strlen(frase)-1] = '\0';

  tornarMaiuscula(frase);

  printf("%s", frase);

  return 0;
}

void tornarMaiuscula(char *str){
  int tamanho = strlen(str);

  for(int i = 0; i < tamanho; i++){
    if(islower(str[i])){
      str[i] = toupper(str[i]);
    }
  }
}