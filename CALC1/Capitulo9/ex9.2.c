#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[41];
    int tamanho;

    printf("Sentenca: ");
    fgets(str, 41, stdin);

    str[strlen(str)-1] = '\0';
    tamanho = strlen(str);

    printf("Primeiro caractere: %c\n", str[0]);
    printf("Ultimo caractere: %c\n", str[tamanho-1]);
    printf("Numero de caracteres: %i", tamanho);

    return 0;
}
