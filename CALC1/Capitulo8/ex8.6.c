#include <stdio.h>
#include <stdlib.h>

void produtoInterno(const float *a1, const float *a2, float *pi, int n);

int main() {
  float a1[5];
  float a2[5];
  float pi[5];

  for(int i = 0; i < 5; i++){
    printf("a1[%d]: ", i);
    scanf("%f", &a1[i]);
  }

  for(int i = 0; i < 5; i++){
    printf("a2[%d]: ", i);
    scanf("%f", &a2[i]);
  }

  produtoInterno(a1, a2, pi, 5);

  return 0;
}

void produtoInterno(const float *a1, const float *a2, float *pi, int n){
  for(int i = 0; i < n; i++){
    pi[i] = a1[i] * a2[i];
    printf("%.2f x %.2f = %.2f\n", a1[i], a2[i], pi[i]);
  }
}