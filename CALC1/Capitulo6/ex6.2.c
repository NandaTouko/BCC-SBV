#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  float base;
  float exp;

  printf("Base: ");
  scanf("%f", &base);

  printf("Expoente: ");
  scanf("%f", &exp);

  printf("%.2f ^ %.2f = %.2f", base, exp, pow(base, exp));

  return 0;
}