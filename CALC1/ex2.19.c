#include <stdio.h>
#include <stdlib.h>

int main(){
    float tC;
    float tF;
    char op;

    printf("Escolha uma operacao de acordo com o menu: \n");
    printf("\t C) Celsius -> Fahrenheit; \n");
    printf("\t F) Fahrenheit -> Celsius \n");

    printf("Opcao: ");
    scanf(" %c", &op);

    switch(op){
        case 'C':
            printf("Entre com a temperatura em graus Celsius: ");
            scanf("%f", &tC);

            tF = 1.8 * tC + 32;

            printf("%.2f graus Celsius correspondem a %.2f graus Fahrenheit", tC, tF);

            break;
        case 'F':
            printf("Entre com a temperatura em graus Fahrenheit: ");
            scanf("%f", &tF);

            tC = (tF - 32)/1.8;

            printf("%.2f graus Fahrenheit correspondem a %.2f graus Celsius", tF, tC);

            break;
        default:
            printf("Opcao invalida!");
            break;
    }

    return 0;
}
