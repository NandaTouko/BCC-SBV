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

    for(int i = 0; i < tamanho; i++){
        printf("%s\n", nome);
    }


    return 0;
}
