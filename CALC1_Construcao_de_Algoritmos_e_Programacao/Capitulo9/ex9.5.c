#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char nome[41];
    int tamanho;

    printf("Nome: ");
    fgets(nome, 41, stdin);

    nome[strlen(nome)-1] = '\0';
    tamanho = strlen(nome);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < tamanho; j++){
            printf("%c", nome[j]);
        }

        printf("\n");
    }

    return 0;
}
