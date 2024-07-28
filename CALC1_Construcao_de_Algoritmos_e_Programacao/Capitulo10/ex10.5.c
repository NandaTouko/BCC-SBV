#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float numerador;
  float denominador;
} Fracao;

Fracao somar(const Fracao *f1, const Fracao *f2);
Fracao subtrair(const Fracao *f1, const Fracao *f2);
Fracao multiplicar(const Fracao *f1, const Fracao *f2);
Fracao dividir(const Fracao *f1, const Fracao *f2);
void imprimirFracao(const Fracao *f);

int main(){
  Fracao f[2];
  Fracao resultado[4];
  char operadores[4] = { '+', '-', '*', '/' };

  for(int i = 0; i < 2; i++){
    printf("Fracao %d\n", i+1);
    printf("    Numerador: ");
    scanf("%f", &f[i].numerador);

    printf("    Denominador: ");
    scanf("%f", &f[i].denominador);
  }

  resultado[0] = somar(&f[0], &f[1]);
  resultado[1] = subtrair(&f[0], &f[1]);
  resultado[2] = multiplicar(&f[0], &f[1]);
  resultado[3] = dividir(&f[0], &f[1]);

  for(int i = 0; i < 4; i++){
    printf("%.2f/%.2f %c %.2f/%.2f = %.2f/%.2f\n", 
    f[0].numerador, f[0].denominador, operadores[i], f[1].numerador, f[1].denominador, resultado[i].numerador, resultado[i].denominador);
  }

  return 0;
}

Fracao somar(const Fracao *f1, const Fracao *f2){
  Fracao r;

  if(f1->denominador != f2->denominador){
    r.denominador = f1->denominador * f2->denominador;
    r.numerador = ((r.denominador/f1->denominador)*f1->numerador) + ((r.denominador/f2->denominador)*f2->numerador);
  }else{
    r.denominador = f1->denominador;
    r.numerador = f1->numerador + f2->numerador;
  }

  return r;
}

Fracao subtrair(const Fracao *f1, const Fracao *f2){
  Fracao r;

  if(f1->denominador != f2->denominador){
    r.denominador = f1->denominador * f2->denominador;
    r.numerador = ((r.denominador/f1->denominador)*f1->numerador) - ((r.denominador/f2->denominador)*f2->numerador);
  }else{
    r.denominador = f1->denominador;
    r.numerador = f1->numerador - f2->numerador;
  }

  return r;
}

Fracao multiplicar(const Fracao *f1, const Fracao *f2){
  Fracao r;

  r.numerador = f1->numerador * f2->numerador;
  r.denominador = f1->denominador * f2->denominador;

  return r;
}

Fracao dividir(const Fracao *f1, const Fracao *f2){
  Fracao r;

  r.numerador = f1->numerador * f2->denominador;
  r.denominador = f1->denominador * f2->numerador;

  return r;
}