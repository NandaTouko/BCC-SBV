#include <stdio.h>
#include <stdlib.h>

int main() {
    int tDesejado;
    int n1 = 0;
    int n2 = 1;
    int auxiliar = 1;

    printf("Termo desejado: ");
    scanf("%d", &tDesejado);

    for(int i = 0; i <= tDesejado; i++){
        if(!(i == 0)){
            auxiliar = n1 + n2;
            n1 = n2;
            n2 = auxiliar;
        }
    }

    printf("Fibonacci de %d e %d", tDesejado, auxiliar);

    return 0;
}
