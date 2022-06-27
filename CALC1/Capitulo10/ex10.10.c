#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int vermelho;
  int verde;
  int azul;
} Cor;

Cor novaCor(int vermelho, int verde, int azul);
Cor clarear(const Cor *c);
void setVermelho(Cor *c, int vermelho);
void setVerde(Cor *c, int verde);
void setAzul(Cor *c, int azul);

int main() {
  Cor c;
  Cor cN;
  Cor cE;
  Cor cEN;

  printf("Vermelho: ");
  scanf("%d", &c.vermelho);

  printf("Verde: ");
  scanf("%d", &c.verde);

  printf("Azul: ");
  scanf("%d", &c.azul);

  cN = novaCor(c.vermelho, c.verde, c.azul);

  printf("Cor: rgb( %d, %d, %d )\n", cN.vermelho, cN.verde, cN.azul);

  cE = clarear(&cN);
  cEN = novaCor(cE.vermelho, cE.verde, cE.azul);

  printf("Cor clareada: rgb( %d, %d, %d )", cEN.vermelho, cEN.verde, cEN.azul);

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

Cor clarear(const Cor *c) {
  Cor cE;
  Cor cN;

  if(c->vermelho == 0 && c->verde == 0 && c->azul == 0){
    cN.vermelho = 3;
    cN.verde = 3;
    cN.azul = 3;

    return cN;
  }
  
  if(
    (c->vermelho > 0 && c->vermelho < 3) ||
    (c->verde > 0 && c->verde < 3) ||
    (c->azul > 0 && c->azul < 3)
  ){
    if(c->vermelho > 0 && c->vermelho < 3){
      cE.vermelho = 3;
    }
    
    if(c->verde > 0 && c->verde < 3){
      cE.verde = 3;
    }

    if(c->azul > 0 && c->azul < 3){
      cE.azul = 3;
    }
  }else{
    cE.vermelho = c->vermelho;
    cE.verde = c->verde;
    cE.azul = c->azul;
  }

  cN.vermelho = cE.vermelho/0.7;
  cN.verde = cE.verde/0.7;
  cN.azul = cE.azul/0.7;

  return cN;
}