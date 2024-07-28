#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirCaixa(const char *str);

int main() {
  char string[41];

  printf("String: ");
  fgets(string, 41, stdin);

  string[strlen(string)-1] = '\0';

  imprimirCaixa(string);

  return 0;
}

void imprimirCaixa(const char *str){
  int tamanho = strlen(str);

  for(int i = 0; i < 3; i++){
    if(i%2 == 0){
      printf("++=");
    }else{
      printf("||");
    }

    for(int j = 0; j < tamanho; j++){
      if(i%2 == 0){
        printf("=");
      }else{
        if(j == 0){
          printf(" ");
        }
        
        printf("%c", str[j]);

        if(j == tamanho-1){
          printf(" ");
        }
      }
    }

    if(i%2 == 0){
      printf("=++");
    }else{
      printf("||");
    }

    printf("\n");
  }
}