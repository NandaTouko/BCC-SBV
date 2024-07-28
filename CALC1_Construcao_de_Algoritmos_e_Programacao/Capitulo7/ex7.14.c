#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void imprimeDuplaClassificada(int n1, int n2, bool emOrdemCrescente);

int main() {
  int n1[5];
  int n2[5];

  for(int i = 0; i < 5; i++){
    printf("n1[%d]: ", i);
    scanf("%d", &n1[i]);

    printf("n2[%d]: ", i);
    scanf("%d", &n2[i]);
  }

  for(int i = 0; i < 5; i++){
    printf("%d e %d: ", n1[i], n2[i]);
    imprimeDuplaClassificada(n1[i], n2[i], (i%2 == 0) ? true : false);
  }

  return 0;
}

void imprimeDuplaClassificada(int n1, int n2, bool emOrdemCrescente){
  if(emOrdemCrescente){
    n1 <= n2 ? printf("%d <= %d\n", n1, n2) : printf("%d <= %d\n", n2, n1);
  }else{
    n1 >= n2 ? printf("%d >= %d\n", n1, n2) : printf("%d >= %d\n", n2, n1);
  }
}