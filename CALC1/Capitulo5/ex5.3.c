#include <stdio.h>
#include <stdlib.h>

#define I 3
#define J 4

int main() {
    int array[I][J];
    int arrayMult[I][J];
    int num;

    for(int i = 0; i < I; i++){
        for(int j = 0; j < J; j++){
            printf("array[%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    printf("Multiplicar por: ");
    scanf("%d", &num);

    printf("arrayMult:\n");
    for(int i = 0; i < I; i++){
        for(int j = 0; j < J; j++){
            arrayMult[i][j] = array[i][j] * num;
            printf("%03d", arrayMult[i][j]);

            if(j != 3){
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}
