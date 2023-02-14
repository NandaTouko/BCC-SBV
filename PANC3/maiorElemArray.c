#include <stdio.h>
#include <stdlib.h>

int arrayMax(int A[], int n);

// Variaveis Globais
int numInstrucoes = 0;

int main() {
    printf("Maior Elemento do Array: \n");

    int n, *arrayA, maiorElemento;

    printf("Entre com o tamanho do array: ");
    scanf("%d", &n);

    arrayA = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        printf("Entre com o valor para a posicao %d: ", i);
        scanf("%d", &arrayA[i]);
    }

    maiorElemento = arrayMax(arrayA, n);
    printf("O maior elemento eh: %d (Num. Instrucoes: %d)", maiorElemento, numInstrucoes);

    return 0;
}

int arrayMax(int A[], int n) {
    int currentMax = A[0];

    for(int i = 1; i < n; i++){
        numInstrucoes++;
        if(currentMax < A[i]){
            currentMax = A[i];
        }
    }

    return currentMax;
}
