#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1;
    int n2;
    int n1True;
    int contM2 = 0;
    int contM3 = 0;
    int contM4 = 0;

    printf("N1: ");
    scanf("%d", &n1);

    printf("N2: ");
    scanf("%d", &n2);

    n1True = (n1 <= n2) ? n1 : n2;
    n2 = (n1 <= n2) ? n2 : n1;

    for(int i = n1True; i <= n2; i++){
        if(i%2 == 0){
            contM2++;
        }

        if(i%3 == 0){
            contM3++;
        }

        if(i%4 == 0){
            contM4++;
        }
    }

    printf("Multiplos de 2: %d\n", contM2);
    printf("Multiplos de 3: %d\n", contM3);
    printf("Multiplos de 4: %d\n", contM4);

    return 0;
}
