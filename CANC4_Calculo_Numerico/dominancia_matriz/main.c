// Amanda Moreira (BV3024679) e João V. R. Maciel (BV3015505)

// Inclusão de bibliotecas úteis para o trabalho
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int dimensao;

	// Requisição ao usuário da dimensão da matriz e o armazenamento da mesma
	printf("Dimensao da matriz quadratica: ");
	scanf("%d", &dimensao);

	// Cria uma matriz com a dimensão passada pelo usuário
	// e um array que gardará os valores da diagonal principal
	int matriz[dimensao][dimensao];
	int diagonal[dimensao];

	// Pede o valor de cada posição da matriz ao usuário
	for (int i = 0; i < dimensao; i++)
	{
		for (int j = 0; j < dimensao; j++)
		{
			printf("%d X %d: ", i, j);
			scanf("%d", &matriz[i][j]);

			if (i == j)
			{
				// Já salva no array de diagonais o valor em módulo
				diagonal[i] = fabs(matriz[i][j]);
			}
		}
	}

	int somaLinha = 0;
	int diagonalDominante = 0;
	int diagonalEstritamenteDominante = 0;

	for (int i = 0; i < dimensao; i++)
	{
		for (int j = 0; j < dimensao; j++)
		{
			// Se não for um valor da diagonal principal, soma
			if (i != j)
			{
				somaLinha += matriz[i][j];
			}

			// Quando estiver na última coluna da linha entra aqui
			if (j == dimensao - 1)
			{
				// Se o valor da diagonal daquela linha for MAIOR que a soma da linha,
				// incrementa a variável diagonalEstritamenteDominante
				if (diagonal[i] > fabs(somaLinha))
				{
					diagonalEstritamenteDominante++;
				}

				// Se o valor da diagonal daquela linha for IGUAL a soma da linha,
				// incrementa a variável diagonalDominante
				else if (diagonal[i] == fabs(somaLinha))
				{
					diagonalDominante++;
				}

				// Zera a variável somaLinha para não interferir nas outras linhas
				somaLinha = 0;
			}
		}
	}

	// Calcula a soma da diagonalEstritamenteDominante com a
	// diagonalDominante para futuras comparações
	int total = diagonalEstritamenteDominante + diagonalDominante;

	// Se o total for igual a dimensão fornecida pelo usuário, significa
	// que a soma da linha sempre foi menor ou igual a diagonal principal
	if (total == dimensao)
	{
		// Se o valor da diagonalEstritamenteDominante for igual a dimensao
		// significa que as diagonais principais foram sempre maiores
		if (diagonalEstritamenteDominante == dimensao)
		{
			printf("Eh estritamente diagonal dominante!");
		}

		// Se não, significa que a soma de alguma linha foi igual
		// a diagonal pricipal daquela linha
		else
		{
			printf("Eh diagonal dominante!");
		}
	}

	// Alguma diagonal principal era menor que a soma da linha
	else
	{
		printf("Nao eh diagonal dominante!");
	}
}