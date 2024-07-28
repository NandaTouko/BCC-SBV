#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sentenca[41];
    int tamanho;

    printf("Sentenca: ");
    fgets(sentenca, 41, stdin);

    sentenca[strlen(sentenca) - 1] = '\0';
    tamanho = strlen(sentenca);

    for(int i = 0; i < tamanho; i++){
        if(i%2 == 0){
            if(sentenca[i] == ' '){
                printf("' '");
            }else{
                printf("%c", sentenca[i]);
            }

            if(i < tamanho-2){
                printf(", ");
            }
        }
    }

    return 0;
}
