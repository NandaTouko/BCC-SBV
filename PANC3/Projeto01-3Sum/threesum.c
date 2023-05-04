#include <stdio.h>
#include <stdlib.h>
#include "threesum.h"

int qtdOperacoes3SumFB = 0;
int qtdOperacoes3SumMelhorado = 0;
int for1 = 0;
int for2 = 0;
int for3 = 0;

/* treeSumForcaBruta(): */
void treeSumForcaBruta(int A[], int n)
{
    int cont = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = (i + 1); j < n; j++)
        {
            for (int k = (j + 1); k < n; k++)
            {
                qtdOperacoes3SumFB++;

                if ((A[i] + A[j] + A[k]) == 0)
                {
                    cont++;
                    printf("\n %d Tripla Encontrada: [%d, %d, %d]", cont, A[i], A[j], A[k]);
                }
            }
        }
    }

    printf("\n Total Triplas Encontradas Pela Forca Bruta: %d", cont);
}

/* treeSumMelhorado(): */
void treeSumMelhorado(int A[], int n)
{
    int cont = 0;

    for (int i = 0; i < n; i++)
    {
        qtdOperacoes3SumMelhorado++;

        for (int j = (i + 1); j < n; j++)
        {
            qtdOperacoes3SumMelhorado++;

            int c = -(A[i]) - (A[j]);

            int rBusca = BuscaBinaria(c, A, (j + 1), (n - 1));

            if (rBusca >= 0)
            {
                cont++;
                printf("\n %d Tripla Encontrada: [%d, %d, %d]", cont, A[i], A[j], c);
            }
        }
    }
}

/* BuscaBinaria(): */
int BuscaBinaria(int x, int A[], int inicio, int fim)
{
    int meio = (inicio + fim) / 2;

    if (inicio > fim)
    {
        return -1;
    }

    if (A[meio] == x)
    {
        return meio;
    }
    else
    {
        qtdOperacoes3SumMelhorado++;

        if (x > A[meio])
        {
            return BuscaBinaria(x, A, (meio + 1), fim);
        }
        else
        {
            return BuscaBinaria(x, A, inicio, (meio - 1));
        }
    }
}

/* MergeSortRecursivo(): */
void MergeSortRecursivo(int A[], int inicio, int fim, int n)
{
    int meio;

    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;
        MergeSortRecursivo(A, inicio, meio, n);
        MergeSortRecursivo(A, (meio + 1), fim, n);
        IntercalaSemSentinela(A, inicio, meio, fim, n);
    }
}

/* IntercalaSemSentinela(): */
void IntercalaSemSentinela(int A[], int inicio, int meio, int fim, int n)
{
    int i, j;
    int *B;

    B = (int *)malloc(n * sizeof(int));

    for (i = inicio; i <= meio; i++)
    {
        B[i] = A[i];
    }

    for (j = (meio + 1); j <= fim; j++)
    {
        B[fim + meio + 1 - j] = A[j];
    }

    i = inicio;
    j = fim;

    for (int k = inicio; k <= fim; k++)
    {
        if (B[i] <= B[j])
        {
            A[k] = B[i];
            i++;
        }
        else
        {
            A[k] = B[j];
            j--;
        }
    }

    free(B);
}

/* ImprimeArray(): */
void ImprimeArray(int A[], char Msg[], int n)
{
    printf("\n %s = ", Msg);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

/* ImprimeQtdOperacoes():  */
void ImprimeQtdOperacoes()
{
    printf("\n Quantidade de Operações - 3SUM - Forca Bruta: %d\n", qtdOperacoes3SumFB);
    printf(" Quantidade de Operações - 3SUM - Melhorado: %d\n", qtdOperacoes3SumMelhorado);
}
