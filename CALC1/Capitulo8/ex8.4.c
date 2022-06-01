#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void decompoeData(int diaDoAno, int ano, int *mes, int *dia);
bool ehBissexto(int ano);

int main(){
    int diaDoAno;
    int ano;
    int mes;
    int dia;

    printf("Dia do ano: ");
    scanf("%d", &diaDoAno);

    printf("Ano: ");
    scanf("%d", &ano);

    decompoeData(diaDoAno, ano, &mes, &dia);

    printf("O dia %d do ano %d cai no dia %d do mes %d.", diaDoAno, ano, dia, mes);

    return 0;
}

void decompoeData(int diaDoAno, int ano, int *mes, int *dia){
    int meses[12] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
    int soma = 0;

    if(ehBissexto(ano)){
        meses[1] = 29;
    }

    for(int i = 0; i < 12; i++){
        soma += meses[i];

        if(soma >= diaDoAno){
            *mes = i+1;
            *dia = meses[i] - (soma - diaDoAno);
            break;
        }
    }
}

bool ehBissexto(int ano){
    if((ano%400 == 0 || ano%4 == 0) && ano%100 != 0){
        return true;
    }else{
        return false;
    }
}
