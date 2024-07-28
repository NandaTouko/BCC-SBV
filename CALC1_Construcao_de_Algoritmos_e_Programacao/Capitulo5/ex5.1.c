#include <stdio.h>
#include <stdlib.h>

#define I 3
#define J 2

int main() {
    int array[I][J];

    for(int i = 0; i < I; i++){
        for(int j = 0; j < J; j++){
            printf("array[%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    for(int i = 0; i < I; i++){
        for(int j = 0; j < J; j++){
            printf("%03d ", array[i][j]);
        }

        printf("\n");
    }

    return 0;
}
