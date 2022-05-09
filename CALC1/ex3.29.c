#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int n1;
  int n2;
  int div = 0;
  char yesOrNo;

  do{
    printf("N1: ");
    scanf("%d", &n1);

    printf("N2: ");
    scanf("%d", &n2);

    if(n2 == 0){
      while(n2 == 0){
        printf("Nao existe divisao inteira por zero. \n");

        printf("Entre novamente com o N2: ");
        scanf("%d", &n2);
      };
    }

    div = n1/n2;

    printf("%d / %d = %d \n", n1, n2, div);

    printf("Voce deseja realizar outro calculo? (S/N): ");
    scanf(" %c", &yesOrNo);
  }while(yesOrNo == 'S');

  return 0;
}