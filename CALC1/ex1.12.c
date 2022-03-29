#include <stdio.h>
#include <stdlib.h>

int main() {
    float num;

    printf("Entre com um valor qualquer: ");
    scanf("%f", &num);

    printf("%f\n", num);
    printf("%.2f\n", num);
    printf("%.3f", num);

    return 0;
}
