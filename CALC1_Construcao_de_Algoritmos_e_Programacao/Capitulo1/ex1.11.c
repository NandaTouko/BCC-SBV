#include <stdio.h>
#include <stdlib.h>

int main() {
    int dMaior;
    int dMenor;
    int area;

    printf("Valor da diagonal maior: ");
    scanf("%d", &dMaior);

    printf("Valor da diagonal menor: ");
    scanf("%d", &dMenor);

    area = (dMaior * dMenor)/2;

    printf("Area = %d", area);

    return 0;
}
