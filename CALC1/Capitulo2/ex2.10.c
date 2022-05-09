#include <stdio.h>
#include <stdlib.h>

int main() {
	float a;
	float b;
	float c;
	float aAB;
	float aAC;
	float aBC;

	printf("a: ");
	scanf("%f", &a);

	printf("b: ");
	scanf("%f", &b);

	printf("c: ");
	scanf("%f", &c);

	aAB = (a - b) > 0 ? (a - b) : -(a - b);
	aAC = (a - c) > 0 ? (a - c) : -(a - c);
	aBC = (b - c) > 0 ? (b - c) : -(b - c);

	if((aAB < c && c < (a + b)) &&
	   (aAC < b && b < (a + c)) &&
	   (aBC < a && a < (b + c))) {
		if(a == b && b == c){
			printf("Triangulo EQUILATERO");
		}else if(a != b && b != c && c != a){
			printf("Triangulo ESCALENO");
		}else{
			printf("Triangulo ISOSCELES");
		}
	}else{
		printf("As medidas fornecidas dos lados nao representam um triangulo valido!");
	}

	return 0;
}

