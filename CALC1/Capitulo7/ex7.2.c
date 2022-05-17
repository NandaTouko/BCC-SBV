#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float areaCirculo(float raio);
float circunferenciaCirculo(float raio);

int main(){
    float raio;

    printf("Raio: ");
    scanf("%f", &raio);

    printf("Area = %.2f\n", areaCirculo(raio));
    printf("Circunferencia = %.2f", circunferenciaCirculo(raio));

    return 0;
}

float areaCirculo(float raio){
    return acos(-1) * pow(raio, 2); // acos(-1) é o valor de PI
}

float circunferenciaCirculo(float raio){
    return 2 * acos(-1) * raio;
}
