#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;

    printf("Forneca um numero menor ou igual a zero: ");
    scanf("%d", &num);

    if(num <= 0){
        for(int i = 0; i >= num; i--){
            printf("%d ", i);
        }
    }else{
        printf("Valor incorreto (positivo)");
    }

    return 0;
}
