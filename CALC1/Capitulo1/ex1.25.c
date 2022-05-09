#include <stdio.h>
#include <stdlib.h>

int main() {
    float tF;
    float tC;

    printf("Temperatura em graus Fahrenheit: ");
    scanf("%f", &tF);

    tC = (tF-32)/1.8;

    printf("%.2f graus Fahrenheit correspondem a %.2f graus Celsius", tF, tC);

    return 0;
}
