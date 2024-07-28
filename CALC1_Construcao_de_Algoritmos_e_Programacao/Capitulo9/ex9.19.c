#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substring(char *recorte, const char *origem, int inicio, int fim);

int main(){
  char origem[41];
  char recorte[41];
  int inicio;
  int fim;

  printf("String: ");
  fgets(origem, 41, stdin);

  origem[strlen(origem)-1] = '\0';

  printf("Inicio: ");
  scanf("%d", &inicio);

  printf("Fim: ");
  scanf("%d", &fim);

  substring(recorte, origem, inicio, fim);

  return 0;
}

void substring(char *recorte, const char *origem, int inicio, int fim){
  int tamanho = strlen(origem);
  int c = 0;

  if(inicio >= tamanho || fim > tamanho || fim < inicio){
    printf("Recorte: %s", origem);
  }else{
    for(int i = inicio; i < fim; i++){
      recorte[c] = origem[i];
      c++;
    }

    recorte[c] = '\0';

    printf("Recorte: %s", recorte);
  }
}