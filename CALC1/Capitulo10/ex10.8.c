#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int vermelho;
  int verde;
  int azul;
} Cor;

Cor novaCor(int vermelho, int verde, int azul);
void setVermelho(Cor *c, int vermelho);
void setVerde(Cor *c, int verde);
void setAzul(Cor *c, int azul);

int main() {
  Cor c;
  Cor cN;
  Cor cNova;
  Cor cNova1;

  printf("Vermelho: ");
  scanf("%d", &c.vermelho);

  printf("Verde: ");
  scanf("%d", &c.verde);

  printf("Azul: ");
  scanf("%d", &c.azul);

  printf("Novo Vermelho: ");
  scanf("%d", &cN.vermelho);

  printf("Novo Verde: ");
  scanf("%d", &cN.verde);

  printf("Novo Azul: ");
  scanf("%d", &cN.azul);

  cNova = novaCor(c.vermelho, c.verde, c.azul);
  cNova1 = novaCor(cN.vermelho, cN.verde, cN.azul);

  printf("Cor: rgb( %d, %d, %d )\n", cNova.vermelho, cNova.verde, cNova.azul);
  printf("Cor alterada: rgb( %d, %d, %d )", cNova1.vermelho, cNova1.verde, cNova1.azul);

  return 0;
}

Cor novaCor(int vermelho, int verde, int azul){
  Cor c1;

  if(vermelho < 0){
    setVermelho(&c1, 0);
  }else if(vermelho > 255){
    setVermelho(&c1, 255);
  }else{
    setVermelho(&c1, vermelho);
  }

  if(verde < 0){
    setVerde(&c1, 0);
  }else if(verde > 255){
    setVerde(&c1, 255);
  }else{
    setVerde(&c1, verde);
  }

  if(azul < 0){
    setAzul(&c1, 0);
  }else if(azul > 255){
    setAzul(&c1, 255);
  }else{
    setAzul(&c1, azul);
  }

  return c1;
}

void setVermelho(Cor *c, int vermelho) {
  c->vermelho = vermelho;
}

void setVerde(Cor *c, int verde) {
  c->verde = verde;
}

void setAzul(Cor *c, int azul) {
  c->azul = azul;
}