#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    int maiorNum = 0;
    int menorNum = 0;

    do{
        printf("Entre com um valor: ");
        scanf("%d", &num);

        if(maiorNum < num){
            maiorNum = num;

            if(menorNum == 0){
                menorNum = num;
            }
        }

        if(menorNum > num && num >= 0){
            menorNum = num;
        }
    }while(num >= 0);

    printf("Menor numero: %d\n", menorNum);
    printf("Maior numero: %d", maiorNum);

    return 0;
}
