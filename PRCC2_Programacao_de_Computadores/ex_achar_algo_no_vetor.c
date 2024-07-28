#include <stdio.h>
#include <stdlib.h>

#define N 5

int encontrar(int *array, int buscar);

int main(){
    int array[N];
    int buscar;
    int retorno;

    for(int i = 0; i < N; i++){
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    printf("\nBuscar por: ");
    scanf("%d", &buscar);

    retorno = encontrar(array, buscar);

    if(retorno == -1){
        printf("Valor nao encontrado!");
    }else{
        printf("Valor encontrado na posicao %d", retorno);
    }

    return 0;
}

int encontrar(int *array, int buscar) {
    for(int i = 0; i < N; i++){
        if(array[i] == buscar){
            return i;
        }
    }

    return -1;
}
