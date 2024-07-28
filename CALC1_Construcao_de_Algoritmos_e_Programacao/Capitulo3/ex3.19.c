#include <stdio.h>
#include <stdlib.h>

int main() {
    for(int i = 0; i < 9; i++){
        if(i < 5){
            for(int j = 0; j <= i; j++){
                printf("*");
            }
        }else{
            for(int k = 9; k > i; k--){
                printf("*");
            } 
        }

        printf("\n");
    }

    return 0;
}
