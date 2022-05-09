#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    int fatorial = 1;

    printf("Numero: ");
    scanf("%d", &num);

    if(num > 0){
        for(int i = num; i > 0; i--){
            fatorial *= i;
        }

        printf("%d! = %d", num, fatorial);
    }else{
        printf("Nao ha fatorial de numero negativo.");
    }

    return 0;
}
