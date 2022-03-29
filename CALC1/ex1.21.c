#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    int sucessor;
    int antecessor;

    printf("Forneca um numero inteiro: ");
    scanf("%d", &num);

    sucessor = num+1;
    antecessor = num-1;

    printf("Sucessor de %d: %d\n", num, sucessor);
    printf("Antecessor de %d: %d", num, antecessor);

    return 0;
}
