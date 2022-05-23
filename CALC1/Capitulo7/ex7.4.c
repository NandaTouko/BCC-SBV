#include <stdio.h>
#include <stdlib.h>

int lePositivo(int i);
int somatorio(int parada);

int main() {
    int valor[5];

    for(int i = 0; i < 5; i++){
        valor[i] = lePositivo(i);
    }

    for(int i = 0; i < 5; i++){
        printf("Somatorio de 1 a %d: %d\n", valor[i], somatorio(valor[i]));
    }

    return 0;
}

int lePositivo(int i){
    int num;

    printf("n[%d]: ", i);
    scanf("%d", &num);

    while(num < 0){
        printf("Entre com um valor positivo: ");
        scanf("%d", &num);
    }

    return num;
}

int somatorio(int parada){
    int somatorio = 0;

    for(int i = 1; i <=  parada; i++){
        somatorio += i;
    }

    return somatorio;
}
