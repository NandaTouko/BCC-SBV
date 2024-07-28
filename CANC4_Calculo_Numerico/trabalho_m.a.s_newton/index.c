// Amanda Moreira (BV3024679) e João V. R. Maciel (BV3015505)

// Inclusão de bibliotecas úteis para o trabalho
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	Assinaturas das funções que serão chamadas pela main
	Como a linguagem C lê o código em ordem, para usar essas funções na main
	teria que declarar elas antes, o que acaba deixando mais difícil de ler o código,
	por isso é melhor assinar as funções, mostrando para o compilador que elas vão existir.
*/
double newton();
double bisseccao(double x, double x1);
double erro(double v1, double v2);

// Variáveis globais
int precisao;
int qtdIteracoesNewton = 0;
int qtdIteracoesBisseccao = 0;

void main()
{
	// Requisição ao usuário da precisão da resposta e o armazenamento da mesma
	printf("Quantas casas de precisão a resposta deve ter? 10^");
	scanf("%d", &precisao);

	// Variáveis que armazenarão as respostas retornadas por cada método
	double resNewton = newton();
	double resBisseccao = bisseccao(0, 1);

	// Demonstração ao usuário da resposta de cada método e
	// da quantidade de iterações feitas por cada um
	printf("Newton: X = %.4lf; Iteracoes = %d;\n", resNewton, qtdIteracoesNewton);
	printf("Bisseccao: X = %.4lf; Iteracoes = %d;\n", resBisseccao, qtdIteracoesBisseccao);
}

// Cálculo do zero da função pelo método de Newton
double newton()
{
	double x;				 // Salvará o resultado anterior
	double x1 = 0.5; // Armazenará o resultado calculado

	// Após a primeira rodada, esse loop continuará até que o
	// erro seja menor que a precisão que o usuário quer
	do
	{
		x = x1;

		// Assim como foi feito no papel, aqui pegamos o X e usamos na função
		// Também calculamos sua derivada
		double resFuncao = pow(x, 3) - (7 * pow(x, 2)) + (14 * x) - 6;
		double resDerivada = (3 * pow(x, 2)) - (14 * x) + 14;

		// Com o que foi feito acima, calculamos o X1
		x1 = x - (resFuncao / resDerivada);

		// Incrementa a quantidade de iterações (variável global)
		qtdIteracoesNewton++;
	} while (erro(x1, x) > pow(10, precisao));

	return x1; // Retorna o último X1 calculado
}

// Cálculo do zero da função pelo método da Bissecção
double bisseccao(double x, double x1)
{
	// Incrementa a quantidade de iterações (variável global)
	qtdIteracoesBisseccao++;

	// Substitui x e x1 na equação
	double resFunX = pow(x, 3) - (7 * pow(x, 2)) + (14 * x) - 6;
	double resFunX1 = pow(x1, 3) - (7 * pow(x1, 2)) + (14 * x1) - 6;

	// Declaração da variável que será usada posteriormente
	double positivoOuNegativo;

	// Calcula a média entre x e x1
	double media = (x + x1) / 2;

	// Substitui a média na equação
	double resFunMedia = pow(media, 3) - (7 * pow(media, 2)) + (14 * media) - 6;

	// Vê se a média deu negativa
	if (resFunMedia < 0)
	{
		// Salva se x ou x1 que resultou em um resultado positivo
		positivoOuNegativo = resFunX > 0 ? x : x1;
	}
	else // Média positiva
	{
		// Salva se x ou x1 que resultou em um resultado negativo
		positivoOuNegativo = resFunX < 0 ? x : x1;
	}

	// Enquanto o erro for maior que a precisão que o usuário quer,
	// essa função se auto chamará
	// Quando o erro for menor que a precisão, o valor da média será retornado.
	if (erro(media, positivoOuNegativo) > pow(10, precisao))
	{
		bisseccao(media, positivoOuNegativo);
	}
	else
	{
		return media;
	}
}

// Função que calcula o erro, usada nas duas funções anteriores
double erro(double v1, double v2)
{
	// "fabs" retorna o módulo daquele valor
	return (fabs(v1 - v2) / fabs(v1));
}