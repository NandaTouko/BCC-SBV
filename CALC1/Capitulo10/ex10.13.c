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
void mover(Retangulo *r, int x, int y);
void imprimirRetangulo(const Retangulo *r);

int main() {
  Ponto sEsq;
  Ponto iDir;
  Retangulo r;
  int x;
  int y;

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

  printf("Mover em x: ");
  scanf("%d", &x);

  printf("Mover em y: ");
  scanf("%d", &y);

  r = novoRetangulo(&sEsq, &iDir);

  printf("Retangulo original:\n");
  imprimirRetangulo(&r);

  mover(&r, x, y);

  printf("Retangulo movido:\n");
  imprimirRetangulo(&r);

  return 0;
}

Retangulo novoRetangulo(const Ponto *sEsq, const Ponto *iDir){
  Retangulo r;

  r.superiorEsquerdo = *sEsq;
  r.inferiorDireito = *iDir;

  return r;
}

void mover(Retangulo *r, int x, int y){
  r->inferiorDireito.x += x;
  r->superiorEsquerdo.x += x;

  r->inferiorDireito.y += y;
  r->superiorEsquerdo.y += y;
}

void imprimirRetangulo(const Retangulo *r){
  printf("(%+02d, %+02d) =====|\n", r->superiorEsquerdo.x, r->superiorEsquerdo.y);
  printf("|               |\n");
  printf("|               |\n");
  printf("|===== (%+02d, %+02d)\n", r->inferiorDireito.x, r->inferiorDireito.y);
}