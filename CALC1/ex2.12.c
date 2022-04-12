#include <stdio.h>
#include <stdlib.h>

int main() {
    int homem1;
    int homem2;
    int mulher1;
    int mulher2;
    int soma;
    int produto;

    printf("Idade Homem 1: ");
    scanf("%d", &homem1);

    printf("Idade Homem 2: ");
    scanf("%d", &homem2);

    printf("Idade Mulher 1: ");
    scanf("%d", &mulher1);

    printf("Idade Mulher 2: ");
    scanf("%d", &mulher2);

    // Homem 1 + velho e mulher 2 + nova
    if(homem1 > homem2 && mulher1 > mulher2){
        soma = homem1 + mulher2;
        produto = homem2 * mulher1;
    }else if(homem1 > homem2 && mulher2 > mulher1){
        soma = homem1 + mulher1;
        produto = homem2 * mulher2;
    }else if(homem2 > homem1 && mulher1 > mulher2){
        soma = homem2 + mulher2;
        produto = homem1 * mulher1;
    }else{
        soma = homem2 + mulher1;
        produto = homem1 * mulher2;
    }

    printf("Idade homem mais velho + idade mulher mais nova: %d\n", soma);
    printf("Idade homem mais novo * idade mulher mais velha: %d", produto);

    return 0;
}
