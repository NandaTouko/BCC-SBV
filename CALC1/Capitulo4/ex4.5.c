#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(){
    int array[N];
    int num;
    int contador = 0;

    for(int i = 0; i < N; i++){
        printf("array[%d]: ");
        scanf("%d", &array[i]);
    }

    printf("Buscar por: ");
    scanf("%d", &num);

    for(int i = 0; i < N; i++){
        if(array[i] == num){
            contador++;
        }
    }

    if(contador > 1){
        printf("O array contem %d ocorrencias do valor %d.", contador, num);
    }else if(contador == 0){
        printf("O array nao contem o valor %d.", num);
    }else{
        printf("O array contem %d ocorrencia do valor %d.", contador, num);
    }

    return 0;
}
