#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool saoAmigos(int n1, int n2);
int lePositivo(int n, int i);

int main() {
  int n1[5];
  int n2[5];

  for(int i = 0; i < 5; i++){
    n1[i] = lePositivo(1, i);
    n2[i] = lePositivo(2, i);
  }

  for(int i = 0; i < 5; i++){
    printf("%d e %d ", n1[i], n2[i]);

    if(saoAmigos(n1[i], n2[i])){
      printf("sao amigos\n");
    }else{
      printf("nao sao amigos\n");
    }
  }

  return 0;
}

bool saoAmigos(int n1, int n2){
  int divisoresN1 = 0;
  int divisoresN2 = 0;

  for(int i = 1; i < n1; i++){
    if(n1%i == 0){
      divisoresN1+=i;
    }
  }

  for(int i = 1; i < n2; i++){
    if(n2%i == 0){
      divisoresN2+=i;
    }
  }

  if(divisoresN1 == divisoresN2){
    return true;
  }else{
    return false;
  }
}

int lePositivo(int n, int i){
  int num;

  printf("n%d[%d]: ", n, i);
  scanf("%d", &num);

  while(num < 0){
    printf("Entre com um valor positivo: ");
    scanf("%d", &num);
  }

  return num;
}