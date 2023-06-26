#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

/* Função: geraArrayAleatorio() - Gerar numeros inteiros aleatorios para um array de tamanho n */
void geraArrayAleatorio(int arrayOriginal[], int n)
{
    int valor;

    srand( time(NULL) );
    for(int i=0; i< n; i++)
    {
        valor = rand() % 100;
        arrayOriginal[i] = valor;
    }
}

/* Função: imprimeArray() - Imprime os n números inteiros de um array */
void imprimeArray(int arrayA[], int n)
{
    printf("\n ");
    for(int i=0; i<n; i++)
    {
        printf(" %d", arrayA[i]);
    }
}

/* Função: copiaValoresArray() - Copia os valores do Array Original para um Array Temporario,
                                 com o objetivo de nao perder os valores originais na ordenacao */
void copiaValoresArray(int arrayOriginal[], int arrayA[], int n)
{
    for(int i=0; i<n; i++)
    {
        arrayA[i] = arrayOriginal[i];
    }
}

/*Função: insertionSort() - Método de ordenação de arrays de valores inteiros com base no
                            Algoritmo do Insertion Sort (Ordenacao Direta)  */
void insertionSort(int arrayA[], int n)
{
    int i, j, chave;
    for (i=1; i<n; i++)
    {
        chave = arrayA[i];
        j = i - 1;
        while((chave < arrayA[j]) && (j>=0))
        {
            arrayA[j+1] = arrayA[j];
            j = j-1;
        }
        arrayA[j+1] = chave;
    }
}

/*Função: insertionSortAlternativo() - Método de ordenação de arrays de valores inteiros com base no
                            Algoritmo do Insertion Sort Alternativo (Ordenacao Direta)  */
void insertionSortAlternativo(int arrayA[], int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=i; j>0; j--)
        {
            numComparacoesIS++;
            if(arrayA[j] < arrayA[j-1])
            {
                numTrocasIS++;
                int chave = arrayA[j-1];
                arrayA[j-1] = arrayA[j];
                arrayA[j] = chave;
            }
        }
    }
}

/*Função: insertionSortStepByStep() - Método de ordenação de arrays de valores inteiros com base no
                            Algoritmo do Insertion Sort (Ordenacao Direta), mostrando a ordenação
                            passo a passo */
void insertionSortStepByStep(int arrayA[], int n)
{
    int i, j, chave;
    for (i=1; i<n; i++)
    {
        chave = arrayA[i];
        printf(" - %d", chave);
        j = i - 1;
        while((chave < arrayA[j]) && (j>=0))
        {
            arrayA[j+1] = arrayA[j];
            j = j-1;
        }
        arrayA[j+1] = chave;
        imprimeArray(arrayA, n);
    }
}

/*Função: MergeSortRecursivo() - Método de ordenção de arrays de valores inteiros com base no
                        Algoritmo do MergeSort/Intercala */

void MergeSortRecursivo(int arrayA[], int n, int inicio, int fim)
{
    int meio;
    if (inicio < fim )
    {
        numComparacoesMS++;
        meio = (inicio + fim) / 2;
        MergeSortRecursivo(arrayA, n, inicio, meio);
        MergeSortRecursivo(arrayA, n, meio + 1, fim);
        IntercalaSemSentinela(arrayA, n, inicio, meio, fim);
    }
}

/*Função: IntercalaSemSentinela() - Método de Auxiliar ao Algoritmo do MergeSort/Intercala
                        que realiza a etapa da combinação */
void IntercalaSemSentinela(int arrayA[], int n, int inicio, int meio, int fim)
{
    int i, j;
    int Aux[n];


    for(i=inicio; i<=meio; i++)
    {
        Aux[i] = arrayA[i];
    }

    for(j=meio+1; j<=fim; j++)
    {
        Aux[fim+meio+1-j] = arrayA[j];
    }

    i=inicio;
    j=fim;

    for(int k=inicio; k<=fim; k++)
    {
        numTrocasMS++;
        if(Aux[i] <= Aux[j])
        {
            arrayA[k] = Aux[i];
            i++;
        }
        else
        {
            arrayA[k] = Aux[j];
            j--;
        }
    }
}

/*Função: MergeSortRecursivoStepByStep() - Método de ordenção de arrays de valores inteiros com base no
                        Algoritmo do MergeSort/Intercala, mostrando a ordenação passo a passo */
void MergeSortRecursivoStepByStep(int arrayA[], int n, int inicio, int fim)
{
    int meio;
    if (inicio < fim )
    {
        meio = (inicio + fim) / 2;
        MergeSortRecursivoStepByStep(arrayA, n, inicio, meio);
        MergeSortRecursivoStepByStep(arrayA, n, meio + 1, fim);
        IntercalaSemSentinela(arrayA, n, inicio, meio, fim);
    }
    imprimeArray(arrayA, n);
}

/*Função: OrdenaBinaria() - Insere os núumeros em ordem no array por pesquisa binaria. */
void OrdenaBinaria(int arrayA[], int n)
{
    //Variaveis Locais
    int i, j;
    int m, x;
    int L, R;

    for(i=1; i< n; i++)
    {
        x = arrayA[i];

        //Busca do ponto R, para insercao de x
        L = 0;
        R = i;
        while (L < R)
        {
            numComparacoesOB++;
            m = (L + R)/2;
            if (x >= arrayA[m]) L = m+1;
            else R = m;
        }

        //Fazendo a Movimentacao para a Insercao no ponto R
        for(j=i; j>L; j=j-1)
        {
            arrayA[j] = arrayA[j-1];
            numTrocasOB++;
        }


        //Inserindo x na posicao de R de Vet[]
        arrayA[R] = x;
    }
}

/*Função: OrdenaBinariaStepByStep() - Insere os números em ordem no array por pesquisa binaria,
mostrando a ordenação passo a passo */
void OrdenaBinariaStepByStep(int arrayA[], int n)
{
    //Variaveis Locais
    int i, j;
    int m, x;
    int L, R;

    for(i=1; i< n; i++)
    {
        x = arrayA[i];
        printf("  -  %d", x);

        //Busca do ponto R, para insercao de x
        L = 0;
        R = i;
        while (L < R)
        {
            m = (L + R)/2;
            if (x >= arrayA[m]) L = m+1;
            else R = m;
        }

        //Fazendo a Movimentacao para a Insercao no ponto R
        for(j=i; j>L; j=j-1)
        {
            arrayA[j] = arrayA[j-1];
        }


        //Inserindo x na posicao de R de Vet[]
        arrayA[R] = x;
        imprimeArray(arrayA, n);
    }
}

/*Função: ShellSort() - Insere os números em ordem no array por shell sort */
void ShellSort(int arrayA[], int inc, int segCorrente, int n)
{
    int i, j, x, k;

    for(i = (segCorrente + inc); i < n; i += inc)
    {
        k = segCorrente;
        j = i - inc;
        x = arrayA[i];

        while(j >= segCorrente && k == segCorrente)
        {
            numComparacoesSS++;
            if(x < arrayA[j])
            {
                numTrocasSS++;
                arrayA[j+inc] = arrayA[j];
                j = j - inc;
            }
            else
            {
                k = j + inc;
            }
        }

        arrayA[k] = x;
    }
}

/*Função: ShellSortStepByStep() - Insere os números em ordem no array por shell sort,
mostrando passo a passo */
void ShellSortStepByStep(int arrayA[], int inc, int segCorrente, int n)
{
    int i, j, x, k;

    printf("\nSegmento %d: %d", segCorrente, arrayA[segCorrente]);

    for(i = (segCorrente + inc); i < n; i += inc)
    {
        k = segCorrente;
        j = i - inc;
        x = arrayA[i];

        printf(", %d", arrayA[i]);

        while(j >= segCorrente && k == segCorrente)
        {
            if(x < arrayA[j])
            {
                arrayA[j+inc] = arrayA[j];
                j = j - inc;
            }
            else
            {
                k = j + inc;
            }
        }

        arrayA[k] = x;
    }
}

/*Função: BubbleSort() - Insere os números em ordem no array por bubble sort */
void BubbleSort(int arrayA[], int n)
{
    int aux, i, j;

    for(j = n-1; j >= 1; j--)
    {
        for(i = 0; i < j; i++)
        {
            numComparacoesBS++;
            if(arrayA[i] > arrayA[i+1])
            {
                numTrocasBS++;
                aux = arrayA[i];
                arrayA[i] = arrayA[i+1];
                arrayA[i+1] = aux;
            }
        }
    }
}

/*Função: BubbleSortStepByStep() - Insere os números em ordem no array por bubble sort,
mostrando passo a passo */
void BubbleSortStepByStep(int arrayA[], int n)
{
    int aux, i, j;

    imprimeArray(arrayA, n);

    for(j = n-1; j >= 1; j--)
    {
        for(i = 0; i < j; i++)
        {
            if(arrayA[i] > arrayA[i+1])
            {
                aux = arrayA[i];
                arrayA[i] = arrayA[i+1];
                arrayA[i+1] = aux;
                imprimeArray(arrayA, n);
            }
        }
    }
}

/*Função: ShakeSort() - Ordena a sequencia de numeros pelo metodo de ordenacao
por agitacao de chaves, tambem chamado Shake Sort */
void ShakeSort(int arrayA[], int n)
{
    int L = 0;
    int R = n - 1;
    int k = n - 1;
    int j;
    int x;

    do
    {
        for (j = L; j < R; j++)
        {
            numComparacoesShakeS++;
            if (arrayA[j] > arrayA[j + 1])
            {
                numTrocasShakeS++;
                x = arrayA[j];
                arrayA[j] = arrayA[j + 1];
                arrayA[j + 1] = x;
                k = j;
            }
        }

        R = k;

        for (j = R; j > L; j--)
        {
            numComparacoesShakeS++;
            if (arrayA[j - 1] > arrayA[j])
            {
                numTrocasShakeS++;
                x = arrayA[j - 1];
                arrayA[j - 1] = arrayA[j];
                arrayA[j] = x;
                k = j;
            }
        }

        L = k;
    }
    while (L < R);
}

void ShakeSortSetpByStep(int arrayA[], int n)
{
    int L = 0;
    int R = n - 1;
    int k = n - 1;
    int j;
    int x;

    do
    {
        for (j = L; j < R; j++)
        {
            if (arrayA[j] > arrayA[j + 1])
            {
                x = arrayA[j];
                arrayA[j] = arrayA[j + 1];
                arrayA[j + 1] = x;
                k = j;
                imprimeArray(arrayA, n);
            }
        }

        R = k;

        for (j = R; j > L; j--)
        {
            if (arrayA[j - 1] > arrayA[j])
            {
                x = arrayA[j - 1];
                arrayA[j - 1] = arrayA[j];
                arrayA[j] = x;
                k = j;
                imprimeArray(arrayA, n);
            }
        }

        L = k;
    }
    while (L < R);
}

/*Função: CombSort() - Ordena a sequencia de numeros pelo metodo de ordenacao
conhecido como CombSort */
void CombSort(int arrayA[], int n)
{
    double h = n;
    int x, i, Troca;

    do
    {
        h = h / 1.3;

        if ((h == 9) || (h == 10))
        {
            h = 11;
        }

        Troca = 0;

        for (i = 0; i < (n - h); i++)
        {
            numComparacoesCS++;

            if (arrayA[i] > arrayA[i + (int)h])
            {
                numTrocasCS++;

                x = arrayA[i];
                arrayA[i] = arrayA[i + (int)h];
                arrayA[i + (int)h] = x;
                Troca = 1;
            }
        }
    }
    while ((Troca == 1) || (h >= 1));
}

void CombSortStepByStep(int arrayA[], int n)
{
    double h = n;
    int x, i, Troca;

    do
    {
        h = h / 1.3;

        if ((h == 9) || (h == 10))
        {
            h = 11;
        }

        Troca = 0;

        for (i = 0; i < (n - h); i++)
        {
            if (arrayA[i] > arrayA[i + (int)h])
            {
                x = arrayA[i];
                arrayA[i] = arrayA[i + (int)h];
                arrayA[i + (int)h] = x;
                Troca = 1;
                imprimeArray(arrayA, n);
            }
        }
    }
    while ((Troca == 1) || (h >= 1));
}

/*Função: QuickSort() - Ordena, de forma recursiva, a sequencia de numeros pelo metodo de ordenacao
por particao e troca */
void QuickSort(int arrayA[], int inicio, int fim)
{
    int pivo, aux, i, j, meio;
    i = inicio;
    j = fim;
    meio = (int)((i + j) / 2);
    pivo = arrayA[meio];

    do
    {
        while (arrayA[i] < pivo)
        {
            i = i + 1;
            numComparacoesQS++;
        }

        while (arrayA[j] > pivo)
        {
            j = j - 1;
            numComparacoesQS++;
        }

        if (i <= j)
        {
            aux = arrayA[i];
            arrayA[i] = arrayA[j];
            arrayA[j] = aux;
            i = i + 1;
            j = j - 1;
            numTrocasQS++;
        }
    }
    while (j > i);

    if (inicio < j)
        QuickSort(arrayA, inicio, j);

    if (i < fim)
        QuickSort(arrayA, i, fim);
}

void QuickSortStepByStep(int arrayA[], int inicio, int fim, int n)
{
    int pivo, aux, i, j, meio;
    i = inicio;
    j = fim;
    meio = (int)((i + j) / 2);
    pivo = arrayA[meio];

    do
    {
        while (arrayA[i] < pivo)
        {
            i = i + 1;
        }

        while (arrayA[j] > pivo)
        {
            j = j - 1;
        }

        if (i <= j)
        {
            aux = arrayA[i];
            arrayA[i] = arrayA[j];
            arrayA[j] = aux;
            i = i + 1;
            j = j - 1;
            imprimeArray(arrayA, n);
        }
    }
    while (j > i);

    if (inicio < j)
        QuickSortStepByStep(arrayA, inicio, j, n);

    if (i < fim)
        QuickSortStepByStep(arrayA, i, fim, n);
}

/*Função: SelectSort() - Ordena aplicando o método da família de classificacao por selecao */
void SelectSort(int arrayA[], int n)
{
    int i, j, k, x, Comp;

    for(i = 0; i < (n-1); i++)
    {
        Comp = 0;
        k = i;
        x = arrayA[i];

        for(j = i+1; j < n; j++)
        {
            numComparacoesSelS++;

            if(arrayA[j] < x)
            {
                k = j;
                x = arrayA[k];
                Comp = 1;
            }
        }

        numComparacoesSelS++;
        if(Comp == 1)
        {
            numTrocasSelS++;
            arrayA[k] = arrayA[i];
            arrayA[i] = x;
        }
    }
}

void SelectSortStepByStep(int arrayA[], int n)
{
    int i, j, k, x, Comp;

    for(i = 0; i < (n-1); i++)
    {
        Comp = 0;
        k = i;
        x = arrayA[i];

        for(j = i+1; j < n; j++)
        {
            if(arrayA[j] < x)
            {
                k = j;
                x = arrayA[k];
                Comp = 1;
            }
        }

        if(Comp == 1)
        {
            arrayA[k] = arrayA[i];
            arrayA[i] = x;
            imprimeArray(arrayA, n);
        }
    }
}

/*Função: HeapSort() - Ordena aplicando o método da família de classificacao por selecao */
void HeapSort(int arrayA[], int n)
{
    int L, R, x;

    L = n/2+1;
    R = n-1;

    while(L > 0)
    {
        L--;
        Heap(L, R, arrayA);
    }

    while(R > 0)
    {
        numTrocasHS++;
        x = arrayA[0];
        arrayA[0] = arrayA[R];
        arrayA[R] = x;
        R--;
        Heap(L, R, arrayA);
    }
}

void HeapSortStepByStep(int arrayA[], int n)
{
    int L, R, x;

    L = n/2+1;
    R = n-1;

    while(L > 0)
    {
        L--;
        Heap(L, R, arrayA);
        imprimeArray(arrayA, n);
    }

    while(R > 0)
    {
        numTrocasHS++;
        x = arrayA[0];
        arrayA[0] = arrayA[R];
        arrayA[R] = x;
        R--;
        Heap(L, R, arrayA);
        imprimeArray(arrayA, n);
    }
}

/*Função: HeapSort() - Auxiliar a funcao HeapSort(), que ajuda a ordenar o array aplicando
o metodo da familia de classificacao por selecao */
void Heap(int L, int R, int arrayA[])
{
    int i, j, x;

    i = L;
    j = 2*L;
    x = arrayA[L];

    numComparacoesHS++;
    if((j < R) && (arrayA[j] < arrayA[j+1]))
    {
        j++;
    }

    while(j <= R && x < arrayA[j])
    {
        numTrocasHS++;
        arrayA[i] = arrayA[j];
        i = j;
        j = 2*j;

        numComparacoesHS++;
        if(j < R && arrayA[j] < arrayA[j+1])
        {
            j++;
        }
    }

    arrayA[i] = x;
}

/*Função: RadixSort() - Funcao que ordena o vetor pelo metodo do radix sort */
void RadixSort(int arrayA[], int n)
{
    int i, b[n], m = 0, exp = 1;

    for(i = 0; i < n; i++)
    {
        numComparacoesRS++;
        if(arrayA[i] > n)
        {
            m = arrayA[i];
        }
    }

    while((m/exp) > 0)
    {
        int bucket[10] = {0};

        for(i = 0; i < n; i++)
        {
            bucket[arrayA[i]/exp%10]++;
        }

        for(i = 1; i < 10; i++)
        {
            bucket[i] += bucket[i-1];
        }

        for(i = (n-1); i >= 0; i--)
        {
            b[--bucket[arrayA[i]/exp%10]] = arrayA[i];
        }

        for(i = 0; i < n; i++)
        {
            numTrocasRS++;
            arrayA[i] = b[i];
        }

        exp *= 10;
    }
}

void RadixSortStepByStep(int arrayA[], int n)
{
    int i, b[n], m = 0, exp = 1;

    for(i = 0; i < n; i++)
    {
        if(arrayA[i] > n)
        {
            m = arrayA[i];
        }
    }

    while((m/exp) > 0)
    {
        int bucket[10] = {0};

        for(i = 0; i < n; i++)
        {
            bucket[arrayA[i]/exp%10]++;
        }

        for(i = 1; i < 10; i++)
        {
            bucket[i] += bucket[i-1];
        }

        for(i = (n-1); i >= 0; i--)
        {
            b[--bucket[arrayA[i]/exp%10]] = arrayA[i];
        }

        for(i = 0; i < n; i++)
        {
            arrayA[i] = b[i];
            imprimeArray(arrayA, n);
        }

        exp *= 10;
    }
}

void MMZSort(int arrayA[], int n) {
  int I[n];
  int P[n];
  int contI = 0;
  int contP = 0;

  for(int i = 0; i < n; i++) {
    if(arrayA[i]%2 == 0) {
      P[contP] = arrayA[i];
      contP++;
    } else {
      I[contI] = arrayA[i];
      contI++;
    }
  }

  insertionSort(P, contP);
  insertionSort(I, contI);

  int posicaoI = 0;
  int posicaoP = 0;

  for(int i = 0; i < n; i++) {
    if(P[posicaoP] < I[posicaoI]) {
      arrayA[i] = P[posicaoP];
      posicaoP++;
    } else {
      arrayA[i] = I[posicaoI];
      posicaoI++;
    }
  }
}
