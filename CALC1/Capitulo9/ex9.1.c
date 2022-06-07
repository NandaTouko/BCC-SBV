#include <stdio.h>
#include <stdlib.h>
#include <string.h> // converte strings em números, como strlen()
// #include <ctype.h> biblioteca para usar funções de manipulação de caracteres, como tolower()

int main() {
    char str[41];

    printf("String: ");
    fgets(str, 41, stdin); // (string que recebe o conteudo, tamanho, dispositivo de entrada( stdin = teclado ))

    str[strlen(str)-1] = "\0"; // tirar o pulo de linha que o buffer coloca

    for(int i = 0; i < 4; i++){

    }

    return 0;
}
