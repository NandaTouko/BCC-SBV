#include <stdio.h>
#include <stdlib.h>

int main() {
    float num = 0;
    float somatorio = 0;
    float media = 0;
    int qtd = 0;

    while(num >= 0){
        printf("Entre com um valor: ");
        scanf("%f", &num);

        if(num > 0){
            somatorio += num;
            qtd++;
        }
    }

    printf("Somatorio: %.2f\n", somatorio);
    printf("Media: %.2f\n", (somatorio/qtd) >= 0 ? somatorio/qtd : 0);
    printf("Quantidade: %d", qtd);

    return 0;
}
