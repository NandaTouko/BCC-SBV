#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(){
    int array[N];
    int num;

    for(int i = 0; i < N; i++){
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    printf("Buscar por: ");
    scanf("%d", &num);

    for(int i = 0; i < N; i++){
        if(array[i] == num){
            printf("Indice %d: ACHEI\n", i);
        }else{
            printf("Indice %d: NAO ACHEI\n", i);
        }
    }

    return 0;
}
