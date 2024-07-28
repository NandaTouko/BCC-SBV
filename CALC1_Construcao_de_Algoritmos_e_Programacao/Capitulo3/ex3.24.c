#include <stdio.h>
#include <stdlib.h>

int main() {
    int idade;
    int menor21 = 0;
    int maior50 = 0;
    int qtdIdade = 1;

    do{
        printf("Idade da pessoa %02d: ", qtdIdade++);
        scanf("%d", &idade);

        if(idade < 21 && idade > 0){
            menor21++;
        }else if(idade > 50){
            maior50++;
        }
    }while(idade >= 0);

    printf("Total de pessoas menores de 21 anos: %d\n", menor21);
    printf("Total de pessoas com mais de 50 anos: %d", maior50);

    return 0;
}
