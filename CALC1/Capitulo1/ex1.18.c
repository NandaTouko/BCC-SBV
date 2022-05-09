#include <stdio.h>
#include <stdlib.h>

int main() {
    float dMaior;
    float dMenor;
    float area;

    printf("Valor da diagonal maior: ");
    scanf("%f", &dMaior);

    printf("Valor da diagonal menor: ");
    scanf("%f", &dMenor);

    area = (dMaior*dMenor)/2;

    printf("Area = %.2f", area);

    return 0;
}
