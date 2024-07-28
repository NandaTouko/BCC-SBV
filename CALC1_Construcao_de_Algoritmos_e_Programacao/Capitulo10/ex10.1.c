#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

int compararData(const Data *d1, const Data *d2);
void imprimirData(const Data *data);

int main(){
  Data d1;
  Data d2;
  int comparacao;

  printf("Data 1\n");
  printf("    dia: ");
  scanf("%d", &d1.dia);
  printf("    mes: ");
  scanf("%d", &d1.mes);
  printf("    ano: ");
  scanf("%d", &d1.ano);

  printf("Data 2\n");
  printf("    dia: ");
  scanf("%d", &d2.dia);
  printf("    mes: ");
  scanf("%d", &d2.mes);
  printf("    ano: ");
  scanf("%d", &d2.ano);

  comparacao = compararData(&d1, &d2);

  // strcat(char *destino, const char *fonte) concatena destino em fonte

  if(comparacao <= 0){
    imprimirData(&d1);
    printf(" <= ");
    imprimirData(&d2);
  }else if(comparacao == 1){
    imprimirData(&d2);
    printf(" <= ");
    imprimirData(&d1);
  }

  return 0;
}

// d1 < d2 = -1; d1 > d2 = 1; d1 == d2 = 0;
int compararData(const Data *d1, const Data *d2){
  if(d1->ano == d2->ano){
    if(d1->mes == d2->mes){
      if(d1->dia == d2->dia){
        return 0;
      }else{
        if(d1->dia > d2->dia){
          return 1;
        }else{
          return -1;
        }
      }
    }else{
      if(d1->mes > d2->mes){
        return 1;
      }else{
        return -1;
      }
    }
  }else{
    if(d1->ano > d2->ano){
      return 1;
    }else{
      return -1;
    }
  }
}

void imprimirData(const Data *data){
  printf("%02d/%02d/%04d", data->dia, data->mes, data->ano);
}