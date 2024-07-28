#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int x;
  int y;
} Ponto;

typedef struct {
  Ponto superiorEsquerdo;
  Ponto inferiorDireito;
} Retangulo;

Retangulo novoRetangulo(const Ponto *sEsq, const Ponto *iDir);
bool contem(const Retangulo *r, const Ponto *p);

int main() {
  Ponto sEsq;
  Ponto iDir;
  Retangulo r;
  Ponto p[5];

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

  printf("Pontos\n");
  for(int i = 0; i < 5; i++){
    printf("  Ponto %d\n", i+1);
    printf("    x: ");
    scanf("%d", &p[i].x);

    printf("    y: ");
    scanf("%d", &p[i].y);
  }

  r = novoRetangulo(&sEsq, &iDir);

  for(int i = 0; i < 5; i++){
    printf("(%+02d, %+02d): ", p[i].x, p[i].y);

    if(contem(&r, &p[i])){
      printf("contido!\n");
    }else{
      printf("nao contido!\n");
    }
  }

  return 0;
}

Retangulo novoRetangulo(const Ponto *sEsq, const Ponto *iDir){
  Retangulo r;

  r.superiorEsquerdo = *sEsq;
  r.inferiorDireito = *iDir;

  return r;
}

bool contem(const Retangulo *r, const Ponto *p){
  if(
    (p->x >= r->superiorEsquerdo.x && p->x <= r->inferiorDireito.x) &&
    (p->y <= r->superiorEsquerdo.y && p->y >= r->inferiorDireito.y)
  ){
    return 1;
  }

  return 0;
}