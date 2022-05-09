#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;

    printf("Forneca um numero maior ou igual a zero: ");
    scanf("%d", &num);

    if(num >= 0){
        for(int i = num; i >= 0; i--){
            printf("%d ", i);
        }
    }else{
        printf("Valor incorreto (negativo)");
    }

    return 0;
}
