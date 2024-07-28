#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

int diaDoAno(const Data *data);

int main(){
  Data d;

  printf("dia: ");
  scanf("%d", &d.dia);

  printf("mes: ");
  scanf("%d", &d.mes);

  printf("ano: ");
  scanf("%d", &d.ano);

  printf("O dia do ano da data %02d/%02d/%04d eh %d", d.dia, d.mes, d.ano, diaDoAno(&d));

  return 0;
}

int diaDoAno(const Data *data){
  int meses[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int dias = 0;
  int diferenca;

  if((data->ano%4 == 0 || data->ano%400 == 0) && data->ano%100 != 0){
    meses[1] += 1;
  }

  for(int i = 0; i < 12; i++){
    if((i+1) <= data->mes){
      dias += meses[i];
    }else{
      break;
    }
  }

  diferenca = meses[data->mes-1] - data->dia;
  return dias-diferenca;
}