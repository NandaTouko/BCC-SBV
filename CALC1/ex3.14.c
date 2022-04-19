#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1;
    int n2;
    int n1True;
    int soma = 0;

    printf("N1: ");
    scanf("%d", &n1);

    printf("N2: ");
    scanf("%d", &n2);

    n1True = (n1 <= n2) ? n1 : n2;
    n2 = (n1 <= n2) ? n2 : n1;

    for(int i = n1True; i <= n2; i++){
        soma += i;
    }

    printf("Somatorio entre %d e %d: %d", n1True, n2, soma);

    return 0;
}
