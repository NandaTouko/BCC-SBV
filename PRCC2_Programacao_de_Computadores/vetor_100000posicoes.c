#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

int main() {
    int array[N];
    time_t inicio, fim;

    time(&inicio);
    srand(time(NULL));

    printf("Array: ");
    for(int i = 0; i < N; i++){
        array[i] = rand()%N;
        printf("%d;\n", array[i]);
    }

    time(&fim);
    double tempo = (double)(fim-inicio);

    printf("\nTempo: %lf", tempo);

    return 0;
}
