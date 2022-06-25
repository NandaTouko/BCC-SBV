#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarOcorrencias(const char *str, char c);

int main(){
  char caractere;
  char frase[10][41];
  char termino[] = "fim";
  int i = 0;
  int ocorrencias;
  int comparacao = 1;

  printf("Caractere: ");
  scanf(" %c", &caractere);

  do{
    printf("Frase: ");
    fgets(frase[i], 41, stdin);

    frase[i][strlen(frase[i])-1] = '\0';

    i++;

    comparacao = strcmp(frase[i], termino);
  }while(comparacao != 0);

  // printf("%s", termino);

  // while(strcmp(frase[i], termino) != 0){
  //   i++;

  //   printf("Frase: ");
  //   fgets(frase[i], 41, stdin);

  //   frase[i][strlen(frase[i])-1] = '\0';
  // }

  for(int c = 0; c < i; c++){
    ocorrencias = contarOcorrencias(frase[c], caractere);
    printf("\"%s\" tem %d ocorrencia(s) do caractere '%c'\n", frase[c], ocorrencias, caractere);
  }

  return 0;
}

int contarOcorrencias(const char *str, char c){
  int tamanho = strlen(str);
  int cont = 0;

  for(int i = 0; i < tamanho; i++){
    if(str[i] == c){
      cont++;
    }
  }

  return cont;
}