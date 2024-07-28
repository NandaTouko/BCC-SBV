#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int x;
  int y;
} Ponto;

typedef struct {
  Ponto superiorEsquerdo;
  Ponto inferiorDireito;
} Retangulo;

Retangulo novoRetangulo(const Ponto *sEsq, const Ponto *iDir);
int calcularArea(const Retangulo *r);
void imprimirRetangulo(const Retangulo *r);

int main() {
  Ponto sEsq;
  Ponto iDir;
  Retangulo r;
  int area;

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
  area = calcularArea(&r);

  imprimirRetangulo(&r);

  printf("Area: %d", area);

  return 0;
}

Retangulo novoRetangulo(const Ponto *sEsq, const Ponto *iDir){
  Retangulo r;

  r.superiorEsquerdo = *sEsq;
  r.inferiorDireito = *iDir;

  return r;
}

int calcularArea(const Retangulo *r){
  int area;

  area = abs((r->superiorEsquerdo.x - r->inferiorDireito.x)) * 
  abs((r->superiorEsquerdo.y - r->inferiorDireito.y));

  return abs(area);
}

void imprimirRetangulo(const Retangulo *r){
  printf("(%+02d, %+02d) =====|\n", r->superiorEsquerdo.x, r->superiorEsquerdo.y);
  printf("|               |\n");
  printf("|               |\n");
  printf("|===== (%+02d, %+02d)\n", r->inferiorDireito.x, r->inferiorDireito.y);
}