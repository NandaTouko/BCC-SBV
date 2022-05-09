#include <stdio.h>
#include <stdlib.h>

int main() {
    int anoNasc;
    int anoAtual;
    int idade;

    printf("Ano de nascimento: ");
    scanf("%d", &anoNasc);

    printf("Ano atual: ");
    scanf("%d", &anoAtual);

    idade = anoAtual - anoNasc;

    printf("Idade aproximada: %d anos", idade);

    return 0;
}
