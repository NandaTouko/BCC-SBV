#include <stdio.h>
#include <time.h>

#define TAM 100000

void dinamica();
void estatica();

int main() {
    dinamica();
    estatica();
    return 0;
}

void dinamica() {
    int array[TAM];
    clock_t inicio, fim;

    inicio = clock();

    for(int i = 0; i < TAM; i++){
        array[i] = i*2;
    }

    fim = clock();

    double tempo = (double)(fim-inicio)/CLOCKS_PER_SEC;

    printf("Tempo dinamico: %.5lf", tempo);
}

void estatica() {
    static int array[TAM];
    clock_t inicio, fim;

    inicio = clock();

    for(int i = 0; i < TAM; i++){
        array[i] = i*2;
    }

    fim = clock();

    double tempo = (double)(fim-inicio)/CLOCKS_PER_SEC;

    printf("\nTempo estatico: %.5lf", tempo);
}
