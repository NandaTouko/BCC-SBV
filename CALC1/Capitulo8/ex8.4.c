#include <stdio.h>
#include <stdlib.h>

void decompoeData(int diaDoAno, int ano, int *mes, int *dia);

int main(){
    int diaDoAno;
    int ano;
    int mes;
    int dia;

    printf("Dia do ano: ");
    scanf("%d", &diaDoAno);

    printf("Ano: ");
    scanf("%d", &ano);

    return 0;
}
