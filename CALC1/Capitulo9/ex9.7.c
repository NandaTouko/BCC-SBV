#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char par1[5][41];
    char par2[5][41];
    int comparacao;

    for(int i = 0; i < 5; i++){
        printf("Par %i, palavra 1: ", i);
        fgets(par1[i], 41, stdin);

        par1[i][strlen(par1[i])-1] = '\0';

        printf("Par %i, palavra 2: ", i);
        fgets(par2[i], 41, stdin);

        par2[i][strlen(par2[i])-1] = '\0';
    }

    for(int i = 0; i < 5; i++){
        comparacao = strcmp(par1[i], par2[i]);

        printf("%s - %s: ", par1[i], par2[i]);

        if(comparacao < 0){ //str1 vem primeiro
            printf("ORDEM CRESCENTE\n");
        }else if(comparacao == 0){
            printf("IGUAIS\n");
        }else{
            printf("ORDEM DECRESCENTE\n");
        }
    }

    return 0;
}
