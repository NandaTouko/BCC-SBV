#include <stdio.h>
#include <stdlib.h>

int main() {
    float lado;
    float perimetro;
    float area;

    printf("Valor do lado: ");
    scanf("%f", &lado);

    perimetro = 4 * lado;
    area = lado * lado;

    printf("Perimetro = %.2f\n", perimetro);
    printf("Area = %.2f", area);

    return 0;
}
