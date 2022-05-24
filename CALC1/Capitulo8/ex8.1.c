#include <stdio.h>
#include <stdlib.h>

// void nao retorna nada
void somatorioMedia(float a[], int n, float *somatorio, float *media); // a[] = float *a => todo array é um ponteiro disfarçado

int main(){
    float valores[10];
    float s;
    float m;

    for(int i = 0; i < 10; i++){
        printf("n[%d]: ", i);
        scanf("%f", &valores[i]);
    }

    somatorioMedia(valores, 10, &s, &m);

    printf("Somatorio: %.2f\n", s);
    printf("Media: %.2f", m);

    return 0;
}

void somatorioMedia(float a[], int n, float *somatorio, float *media){
    *somatorio = 0;

    for(int i = 0; i < n; i++){
        *somatorio = *somatorio + a[i];
    }

    *media = *somatorio/n;
}
