#include <stdio.h>
#include <stdlib.h>

int main() {
    float num;
    float conta;

    printf("Entre com um valor: ");
    scanf("%f", &num);

    if(num > 20){
        conta = num/2;
        printf("A metade de %.2f e %.2f", num, conta);
    }else{
        conta = num*3;
        printf("O triplo de %.2f e %.2f", num, conta);
    }

    return 0;
}
