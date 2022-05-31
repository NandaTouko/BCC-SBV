#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5

int lePositivo(char letter, int i);
bool ehTriangulo(int ladoA, int ladoB, int ladoC);
int tipoTriangulo(int ladoA, int ladoB, int ladoC);

int main() {
  int lado1[N];
  int lado2[N];
  int lado3[N];
  int tipoT;

  for(int i = 0; i < N; i++){
    lado1[i] = lePositivo('A', i);
    lado2[i] = lePositivo('B', i);
    lado3[i] = lePositivo('C', i);
  }

  for(int i = 0; i < N; i++){
    printf("Valores %d, %d e %d: ", lado1[i], lado2[i], lado3[i]);

    if(ehTriangulo(lado1[i], lado2[i], lado3[i])){
      tipoT = tipoTriangulo(lado1[i], lado2[i], lado3[i]);

      if(tipoT == 1){
        printf("triangulo equilatero\n");
      }else if(tipoT == 3){
        printf("triangulo escaleno\n");
      }else{
        printf("triangulo isosceles\n");
      }
    }else{
      printf("nao formam um triangulo\n");
    }
  }

  return 0;
}

int lePositivo(char letter, int i){
  int num;

  printf("lado%c[%d]: ", letter, i);
  scanf("%d", &num);

  while(num < 0){
    printf("Entre com um valor positivo: ");
    scanf("%d", &num);
  }

  return num;
}

bool ehTriangulo(int ladoA, int ladoB, int ladoC){
  int aAB;
  int aAC;
  int aBC;

  aAB = (ladoA - ladoB) > 0 ? (ladoA - ladoB) : -(ladoA - ladoB);
	aAC = (ladoA - ladoC) > 0 ? (ladoA - ladoC) : -(ladoA - ladoC);
	aBC = (ladoB - ladoC) > 0 ? (ladoB - ladoC) : -(ladoB - ladoC);

  if(
    (aAB < ladoC && ladoC < (ladoA + ladoB)) &&
    (aAC < ladoB && ladoB < (ladoA + ladoC)) &&
    (aBC < ladoA && ladoA < (ladoB + ladoC))
  ){
    return true;
  }else{
    return false;
  }
}

int tipoTriangulo(int ladoA, int ladoB, int ladoC){
  if(ladoA == ladoB && ladoB == ladoC){
    return 1;
  }else if(ladoA != ladoB && ladoB != ladoC && ladoC != ladoA){
    return 3;
  }else{
    return 2;
  }
}