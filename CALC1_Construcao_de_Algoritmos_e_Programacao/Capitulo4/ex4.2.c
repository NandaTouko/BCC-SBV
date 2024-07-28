#include <stdio.h>
#include <stdlib.h>

#define N 5

int main() {
    int array[N];
    int arrayMult[N];
    int num;

    for(int i = 0; i < N; i++){
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    printf("Multiplicar por: ");
    scanf("%d", &num);

    for(int i = 0; i < N; i++){
        arrayMult[i] = array[i] * num;
        printf("arrayMult[%d] = %d\n", i, arrayMult[i]);
    }
    return 0;
}
