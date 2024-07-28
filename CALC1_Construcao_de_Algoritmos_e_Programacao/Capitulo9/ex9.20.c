#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool contem(const char *fonte, const char *aPesquisar);

int main() {
  char fonte[41];
  char aPesquisar[41];

  printf("String fonte: ");
  fgets(fonte, 41, stdin);

  fonte[strlen(fonte)-1] = '\0';

  printf("String a pesquisar: ");
  fgets(aPesquisar, 41, stdin);

  aPesquisar[strlen(aPesquisar)-1] = '\0';

  printf("\"%s\" ", aPesquisar);

  if(contem(fonte, aPesquisar)){
    printf("esta contida em \"%s\"", fonte);
  }else{
    printf("nao esta contida em \"%s\"", fonte);
  }

  return 0;
}

bool contem(const char *fonte, const char *aPesquisar){
  int tamanhoFonte = strlen(fonte);
  int tamanhoPesquisar = strlen(aPesquisar);
  int qtdIgual = 0;

  for(int i = 0; i < tamanhoFonte; i++){
    if(fonte[i] == aPesquisar[0]){
      for(int j = 0; j < tamanhoPesquisar; j++){
        if(fonte[i+j] == aPesquisar[j]){
          qtdIgual++;
        }
      }
    }
  }

  if(tamanhoPesquisar == qtdIgual){
    return true;
  }else{
    return false;
  }
}