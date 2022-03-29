#include <stdio.h>
#include <stdlib.h>

int main() {
    int bMaior;
    int bMenor;
    int altura;
    int area;

    printf("Valor da base maior: ");
    scanf("%d", &bMaior);

    printf("Valor da base menor: ");
    scanf("%d", &bMenor);

    printf("Valor da altura: ");
    scanf("%d", &altura);

    area = ((bMaior*bMenor)) * altura;
}
