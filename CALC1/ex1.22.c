#include <stdio.h>
#include <stdlib.h>

int main() {
    float vProd;
    float preco;

    printf("Valor do produto: ");
    scanf("%f", &vProd);

    preco = vProd - (vProd*0.09);

    printf("Preco de venda com 9%% de desconto: %.2f", preco);

    return 0;
}
