#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} Ponto;

typedef struct {
  Ponto superiorEsquerdo;
  Ponto inferiorDireito;
} Retangulo;

Retangulo novoRetangulo(const Ponto *sEsq, const Ponto *iDir);
Ponto obterCentro(const Retangulo *r);
void imprimirRetangulo(const Retangulo *r);

int main() {
  Ponto sEsq;
  Ponto iDir;
  Retangulo r;
  Ponto pC;

  printf("Ponto superior esquerdo\n");
  printf("    x: ");
  scanf("%d", &sEsq.x);
  printf("    y: ");
  scanf("%d", &sEsq.y);

  printf("Ponto inferior direito\n");
  printf("    x: ");
  scanf("%d", &iDir.x);
  printf("    y: ");
  scanf("%d", &iDir.y);

  r = novoRetangulo(&sEsq, &iDir);
  pC = obterCentro(&r);

  imprimirRetangulo(&r);

  printf("Centro: (%+02d, %+02d)", pC.x, pC.y);

  return 0;
}

Retangulo novoRetangulo(const Ponto *sEsq, const Ponto *iDir){
  Retangulo r;

  r.superiorEsquerdo = *sEsq;
  r.inferiorDireito = *iDir;

  return r;
}

Ponto obterCentro(const Retangulo *r){
  Ponto centro;

  centro.x = (r->superiorEsquerdo.x + r->inferiorDireito.x)/2;
  centro.y = (r->superiorEsquerdo.y + r->inferiorDireito.y)/2;

  return centro;
}

void imprimirRetangulo(const Retangulo *r){
  printf("(%+02d, %+02d) =====|\n", r->superiorEsquerdo.x, r->superiorEsquerdo.y);
  printf("|               |\n");
  printf("|               |\n");
  printf("|===== (%+02d, %+02d)\n", r->inferiorDireito.x, r->inferiorDireito.y);
}