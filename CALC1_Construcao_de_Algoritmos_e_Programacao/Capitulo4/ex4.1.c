#include <stdio.h>
#include <stdlib.h>

#define N 5

int main() {
    int array[N];
    int arrayCubo[N];

    for(int i = 0; i < N; i++){
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);

        arrayCubo[i] = array[i] * array[i] * array[i];
    }

    for(int i = 0; i < N; i++){
        printf("arrayCubo[%d] = %d\n", i, arrayCubo[i]);
    }

    return 0;
}
