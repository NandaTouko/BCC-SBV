#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int horas;
  int minutos;
  int segundos;
} Hora;

Hora gerarHora(int qtdSegundos);
void imprimirHora(const Hora *hora);

int main() {
  int segundos;
  Hora h;

  printf("Segundos: ");
  scanf("%d", &segundos);

  h = gerarHora(segundos);
  imprimirHora(&h);

  return 0;
}

Hora gerarHora(int qtdSegundos){
  Hora h1;

  h1.horas = qtdSegundos/3600;
  h1.minutos = (qtdSegundos%3600)/60;
  h1.segundos = (qtdSegundos%3600)%60;

  return h1;
}

void imprimirHora(const Hora *hora){
  printf("Hora correspondente: %02d:%02d:%02d", hora->horas, hora->minutos, hora->segundos);
}