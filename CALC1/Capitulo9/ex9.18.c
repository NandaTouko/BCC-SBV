#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool ehPalindromo(const char *str);

int main() {
  char string[41];

  printf("String: ");
  fgets(string, 41, stdin);

  string[strlen(string)-1] = '\0';

  printf("\"%s\" ", string);

  if(ehPalindromo(string)){
    printf("eh um palindromo!");
  }else{
    printf("nao eh um palindromo!");
  }

  return 0;
}

bool ehPalindromo(const char *str){
  int tamanho = strlen(str);

  for(int i = 0; i < tamanho; i++){
    if(tolower(str[i]) != tolower(str[(tamanho-1)-i])){
      return false;
    }
  }

  return true;
}