#include <stdio.h>
#include <stdlib.h>

int main() {
    float peso;
    float media;
    float pesosMais60 = 0;
    float maisPesado = 0;
    int qtdMais60 = 0;
    int pessoa = 1;

    do{
        printf("Entre com o peso da pessoa %02d: ", pessoa++);
        scanf("%f", &peso);

        if(maisPesado < peso){
            maisPesado = peso;
        }

        if(peso > 60){
            pesosMais60 += peso;
            qtdMais60++;
        }
    }while(peso >= 0);

    media = pesosMais60/qtdMais60;

    printf("Media dos pesos acima de 60kg: %.2f\n", (media > 0) ? media : 0);
    printf("A pessoa mais pesada possui %.2fkg", maisPesado);

    return 0;
}
