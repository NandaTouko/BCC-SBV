#include <stdio.h>
#include <stdlib.h>

float maiorNumero(float n1, float n2);

int main() {
  float n1[5];
  float n2[5];
  int cont = 0;
  float resultado;

  do{
    printf("n1[%d]: ", cont);
    scanf("%f", &n1[cont]);

    if(n1[cont] < 0){
      printf("Entre com um valor positivo!\n");
    }else{
      printf("n2[%d]: ", cont);
      scanf("%f", &n2[cont]);

      if(n2[cont] < 0){
        do {
          printf("Entre com um valor positivo!\n");
          printf("n2[%d]: ", cont);
          scanf("%f", &n2[cont]);
        }while(n2[cont] < 0);

        cont++;
      }else{
        cont++;
      }
    }    
  }while(cont < 5);

  for(int i = 0; i < 5; i++){
    printf("%.2f, %.2f: ", n1[i], n2[i]);

    resultado = maiorNumero(n1[i], n2[i]);

    if(resultado == -1){
      printf("Eles sao iguais\n");
    }else{
      printf("O maior valor e %.2f\n", resultado);
    }
  }

  return 0;
}

float maiorNumero(float n1, float n2){
  if(n1 > n2){
    return n1;
  }else if(n1 == n2){
    return -1;
  }else{
    return n2;
  }
}