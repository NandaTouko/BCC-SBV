#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    int array[100][100];
    int conta;

    printf("Numero entre 1 e 100: ");
    scanf("%d", &num);

    if(num >= 1 && num <= 100){
        for(int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
                conta = (j - i) < 0 ? -(j - i) : (j - i);
                array[i][j] = conta + 1;

                printf("%3d", array[i][j]);
            }

            printf("\n");
        }
    }else{
        printf("Numero incorreto!");
    }

    return 0;
}
