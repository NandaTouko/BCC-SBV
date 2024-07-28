#include <stdio.h>
#include <stdlib.h>

int main() {
    float precoAula;
    int qtdAula;
    float perINSS;
    float salBruto;
    float salLiquido;

    printf("Valor da hora/aula: ");
    scanf("%f", &precoAula);

    printf("Quantidade de aulas: ");
    scanf("%d", &qtdAula);

    printf("Porcentagem de desconto do INSS: ");
    scanf("%f", &perINSS);

    salBruto = precoAula * qtdAula;
    salLiquido = salBruto - (salBruto * (perINSS/100));

    printf("Salario Liquido: %.2f", salLiquido);

    return 0;
}
