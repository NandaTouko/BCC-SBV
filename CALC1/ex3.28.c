#include <stdio.h>
#include <stdlib.h>

int main() {
	float saldoInicial;
	float deposito = 0;
	float saque = 0;
	int operacao;

	printf("Saldo inicial: ");
	scanf("%f", &saldoInicial);

	printf("Operacoes: \n");
	printf("\t 1) Deposito; \n");
	printf("\t 2) Saque; \n");
	printf("\t 3) Fim; \n");

	do {
		printf("Operacao desejada: ");
		scanf("%d", &operacao);

		switch (operacao) {
		case 1:
			printf("Valor a depositar: ");
			scanf("%f", &deposito);

			saldoInicial += deposito;

			break;
		case 2:
			printf("Valor a sacar: ");
			scanf("%f", &saque);

			saldoInicial -= saque;

			break;
		case 3:
			break;
		default:
			printf("Operacao invalida.");
			break;
		}
	} while (operacao != 3);

	if (saldoInicial == 0) {
		printf("Saldo final: R$%.2f\n", saldoInicial);
		printf("Sem saldo.");
	}else if (saldoInicial < 0){
		printf("Saldo final: -R$%.2f\n", saldoInicial*-1);
		printf("Conta devedora.");
	}else{
		printf("Conta preferencial.");
	}

	return 0;
}
