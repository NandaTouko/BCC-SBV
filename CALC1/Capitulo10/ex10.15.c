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
bool intercepta(const Retangulo *r1, const Retangulo *r2);
bool contem(const Retangulo *r, const Ponto *p);

int main() {
  Ponto sEsq[2];
  Ponto iDir[2];
  Retangulo r[2];

  for(int i = 0; i < 2; i++){
    printf("Retangulo %d\n", i+1);

    printf("Ponto superior esquerdo\n");
    printf("    x: ");
    scanf("%d", &sEsq[i].x);
    printf("    y: ");
    scanf("%d", &sEsq[i].y);

    printf("Ponto inferior direito\n");
    printf("    x: ");
    scanf("%d", &iDir[i].x);
    printf("    y: ");
    scanf("%d", &iDir[i].y);

    r[i] = novoRetangulo(&sEsq[i], &iDir[i]);
  }

  if(intercepta(&r[0], &r[1])){
    printf("Os retangulos se interceptam!");
  }else{
    printf("Os retangulos nao se interceptam!");
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

bool intercepta(const Retangulo *r1, const Retangulo *r2){
  if(contem(r1, &r2->inferiorDireito)){
    return 1;
  }else if(contem(r1, &r2->superiorEsquerdo)){
    return 1;
  }else if(contem(r2, &r1->inferiorDireito)){
    return 1;
  }else if(contem(r2, &r1->superiorEsquerdo)){
    return 1;
  }

  return 0;
}