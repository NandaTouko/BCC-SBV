#include <stdio.h>
#include <stdlib.h>

int main() {
    float bMaior;
    float bMenor;
    float altura;
    float area;

    printf("Valor da base maior: ");
    scanf("%f", &bMaior);

    printf("Valor da base menor: ");
    scanf("%f", &bMenor);

    printf("Valor da altura: ");
    scanf("%f", &altura);

    area = ((bMaior+bMenor)*altura)/2;

    printf("Area = %.2f", area);

    return 0;
}
