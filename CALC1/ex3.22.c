#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    int maior = 0;

    printf("N1: ");
    scanf("%d", &n1);

    maior = (maior > n1) ? maior : n1;

    printf("N2: ");
    scanf("%d", &n2);

    maior = (maior > n2) ? maior : n2;

    printf("N3: ");
    scanf("%d", &n3);

    maior = (maior > n3) ? maior : n3;

    printf("N4: ");
    scanf("%d", &n4);

    maior = (maior > n4) ? maior : n4;

    printf("N5: ");
    scanf("%d", &n5);

    maior = (maior > n5) ? maior : n5;

    if(n1 <= 0 || n2 <= 0 || n3 <= 0 || n4 <= 0 || n5 <= 0){
        printf("Forneca apenas numeros positivos.");
    }else{
        for(int i = maior; i > 0; i--){
            printf("%04d  ", i);

            (i <= n1) ? printf("*") : printf(" ");
            (i <= n2) ? printf("*") : printf(" ");
            (i <= n3) ? printf("*") : printf(" ");
            (i <= n4) ? printf("*") : printf(" ");
            (i <= n5) ? printf("*") : printf(" ");

            printf("\n");
        }
    }

    return 0;
}
