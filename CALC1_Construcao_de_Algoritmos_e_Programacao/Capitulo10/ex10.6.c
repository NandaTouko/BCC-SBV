#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int vermelho;
  int verde;
  int azul;
} Cor;

Cor novaCor(int vermelho, int verde, int azul);
void imprimirCor(const Cor *c);

int main(){
  Cor c;
  Cor cN;

  printf("Vermelho: ");
  scanf("%d", &c.vermelho);

  printf("Verde: ");
  scanf("%d", &c.verde);

  printf("Azul: ");
  scanf("%d", &c.azul);

  cN = novaCor(c.vermelho, c.verde, c.azul);
  imprimirCor(&cN);

  return 0;
}

Cor novaCor(int vermelho, int verde, int azul){
  Cor c1;

  if(vermelho < 0){
    c1.vermelho = 0;
  }else if(vermelho > 255){
    c1.vermelho = 255;
  }else{
    c1.vermelho = vermelho;
  }

  if(verde < 0){
    c1.verde = 0;
  }else if(verde > 255){
    c1.verde = 255;
  }else{
    c1.verde = verde;
  }

  if(azul < 0){
    c1.azul = 0;
  }else if(azul > 255){
    c1.azul = 255;
  }else{
    c1.azul = azul;
  }

  return c1;
}

void imprimirCor(const Cor *c){
  printf("Cor: rgb( %d, %d, %d )", c->vermelho, c->verde, c->azul);
}