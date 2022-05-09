#include <stdio.h>
#include <stdlib.h>

int main(){
    int lado;
    float medLado;
    float conta;

    printf("Entre com a quantidade de lados: ");
    scanf("%d", &lado);

    printf("Entre com a medida do lado: ");
    scanf("%f", &medLado);

    switch(lado){
        case 3:
            conta = 3 * medLado;
            printf("TRIANGULO de perimetro %.2f", conta);
            break;
        case 4:
            conta = medLado*medLado;
            printf("QUADRADO de area %.2f", conta);
	    break;
	case 5:
	    printf("PENTAGONO");
	    break;
	default:
	    printf("Poligono nao identificado");
	    break;

    }

    return 0;
}
