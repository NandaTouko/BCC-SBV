#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1;
    int n2;
    int n1True;
    int par = 0;

    printf("N1: ");
    scanf("%d", &n1);

    printf("N2: ");
    scanf("%d", &n2);

    n1True = (n1 <= n2) ? n1 : n2;
    n2 = (n1 <= n2) ? n2 : n1;

    for(int i = n1True; i <= n2; i++){
        if(i%2 == 0){
            par++;
        }
    }

    printf("Numeros pares entre %d e %d: %d", n1True, n2, par);

    return 0;
}
