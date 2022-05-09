#include <stdio.h>
#include <stdlib.h>

int main() {
    for(int i = 0; i < 5; i++){
        for(int j = 0; j <= i; j++){
            printf("*");
        }

        printf("\n");
    }

    printf("\n");

    for(int k = 5; k > 0; k--){
        for(int l = 0; l < k; l++){
            printf("*");
        }

        printf("\n");
    }

    printf("\n");

    for(int m = 5; m > 0; m--){
        for(int n = 0; n < (m-1); n++){
            printf(" ");
        }

        for(int o = 5; o > (m-1); o--){
            printf("*");
        } 

        printf("\n");
    }

    printf("\n");

    for(int p = 0; p < 5; p++){
        for(int r = (p-1); r >= 0; r--){
            printf(" ");
        }

        for(int q = 4; q > (p-1); q--){
            printf("*");
        }


        printf("\n");
    }

    return 0;
}
