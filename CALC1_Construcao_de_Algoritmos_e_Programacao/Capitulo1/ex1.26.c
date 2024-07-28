#include <stdio.h>
#include <stdlib.h>

int main() {
    float tC;
    float tF;

    printf("Temperatura em graus Celsius: ");
    scanf("%f", &tC);

    tF = (1.8*tC) + 32;

    printf("%.2f graus Celsius correspondem a %.2f graus Fahrenheit", tC, tF);

    return 0;
}
