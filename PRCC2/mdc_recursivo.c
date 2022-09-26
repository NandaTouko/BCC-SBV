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
    //Como Fiz
    /*
    if(m%n != 0){
        return mdc(n, m%n);
    }else{
        return n;
    }
    */

    //Como o prof. fez
    if(n==0) return m;
    return mdc(n, m%n);
}
