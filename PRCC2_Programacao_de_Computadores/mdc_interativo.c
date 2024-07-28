#include <stdio.h>
#include <stdlib.h>

int mdc(int m, int n);

int main() {
    int dividendo;
    int divisor;

    printf("Dividendo: ");
    scanf("%d", &dividendo);

    printf("Divisor: ");
    scanf("%d", &divisor);

    printf("Maximo divisor comum: %d", mdc(dividendo, divisor));

    return 0;
}

int mdc(int m, int n){
    int r;
    do{
        r = m%n;
        m = n;
        n = r;
    } while(r != 0);

    return m;
}
