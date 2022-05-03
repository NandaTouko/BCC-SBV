#include <stdio.h>
#include <stdlib.h>

int main() {
    float somatorio = 0;
    float nota;

    printf("Forneca a nota de 10 alunos: \n");

    for(int i = 1; i <= 10; i++){
        printf("Nota %02d: ", i);
        scanf("%f", &nota);

        somatorio += nota;
    }

    printf("A media aritmetica das dez notas e: %.2f", somatorio/10);

    return 0;
}
