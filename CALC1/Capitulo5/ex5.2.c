#include <stdio.h>
#include <stdlib.h>

#define J 3
#define I 3

int main() {
    int array1[I][J];
    int array2[I][J];
    int soma[I][J];

    for(int i = 0; i < I; i++){
        for(int j = 0; j < J; j++){
            printf("array1[%d][%d]: ", i, j);
            scanf("%d", &array1[i][j]);
        }
    }

    for(int i = 0; i < I; i++){
        for(int j = 0; j < J; j++){
            printf("array2[%d][%d]: ", i, j);
            scanf("%d", &array2[i][j]);
        }
    }

    for(int i = 0; i < I; i++){
        for(int j = 0; j < J; j++){
            soma[i][j] = array1[i][j] + array2[i][j];
        }
    }

    printf("array1:       array2:       arraySoma:\n");

    for(int i = 0; i < I; i++){
        for(int j = 0; j < J; j++){
            printf("%03d ", array1[i][j]);
        }

        (i == 1) ? printf("+ ") : printf("  ");

        for(int j = 0; j < J; j++){
            printf("%03d ", array2[i][j]);
        }

        (i == 1) ? printf("= ") : printf("  ");

        for(int j = 0; j < J; j++){
            printf("%03d", soma[i][j]);

            if(j != 2){
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}
