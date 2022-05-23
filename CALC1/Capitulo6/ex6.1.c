#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  float a;
  float b;
  float c;
  float delta;
  float x1;
  float x2;

  printf("a: ");
  scanf("%f", &a);

  printf("b: ");
  scanf("%f", &b);

  printf("c: ");
  scanf("%f", &c);

  if(a != 0){
    delta = (b*b) - (4 * a * c);

    printf("Delta: %.2f\n", delta);
    if(delta < 0){
      printf("S = {}");
    }else{
      x1 = (-b + sqrt(delta))/ 2*a;
      x2 = (-b - sqrt(delta))/ 2*a;

      if(delta == 0){
        printf("S = {%.2f}", x1);
      }else{
        printf("S = {%.2f, %.2f}", fmin(x1, x2), fmax(x1, x2));
      }
    }
  }else{
    printf("Nao existe equacao do segundo grau!");
  }

  return 0;
}