#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

int main()
{
    numComparacoesIS = 0,
    numTrocasIS = 0,
    numComparacoesMS = 0,
    numTrocasMS = 0,
    numComparacoesOB = 0,
    numTrocasOB = 0,
    numComparacoesSS = 0,
    numTrocasSS = 0,
    numComparacoesBS = 0,
    numTrocasBS = 0;

    printf("\n Algoritmos de Ordenacoes: \n");

    //Solicitacao do Tamanho do Array e Alocacao Dinamica da Memoria dos Arrays
    printf("\n Entre com o tamanho (n) do Array: ");
    scanf("%d", &n);
    arrayOriginal = (int*) malloc(n * sizeof(int));
    arrayA = (int*) malloc(n * sizeof(int));

    //Gerando Array com Valores Aleatorios
    geraArrayAleatorio(arrayOriginal, n);

    //Imprimindo Array Gerado Aleatoriamente
    printf("\n Array Original Gerado Aleatoriamente: \n");
    imprimeArray(arrayOriginal, n);

    //Copiando Valor do Array Original para um Array Temporario
    copiaValoresArray(arrayOriginal, arrayA, n);

    //Ordenando Array utilizando o Insertion Sort
    printf("\n\n Ordenando o Array - Insertion Sort(): \n");
    imprimeArray(arrayA, n);
    insertionSort(arrayA, n);
    imprimeArray(arrayA, n);

    //Ordenando Array utilizando o Insertion Sort Alternativo
    printf("\n\n Ordenando o Array - Insertion Sort Alternativo: \n");
    copiaValoresArray(arrayOriginal, arrayA, n);
    imprimeArray(arrayA, n);
    insertionSortAlternativo(arrayA, n);
    imprimeArray(arrayA, n);

    //Ordenando Array utilizando o MergeSort sem Sentinela
    printf("\n\n Ordenando o Array - MergeSort sem Sentinela: \n");
    copiaValoresArray(arrayOriginal, arrayA, n);
    imprimeArray(arrayA, n);
    MergeSortRecursivo(arrayA, n, 0, n-1);
    imprimeArray(arrayA, n);

    //Ordenando Array utilizando a Ordenação Binária
    printf("\n\n Ordenando o Array - Ordenacao Binaria: \n");
    copiaValoresArray(arrayOriginal, arrayA, n);
    imprimeArray(arrayA, n);
    OrdenaBinaria(arrayA, n);
    imprimeArray(arrayA, n);
    //OrdenaBinariaStepByStep(arrayA, n);

    //Ordenando Array utilizando Shell Short
    printf("\n\n Ordenando o Array - Shell Sort: \n");
    copiaValoresArray(arrayOriginal, arrayA, n);
    imprimeArray(arrayA, n);

    for(int i=2; i >= 0; i--){
        int inc = (int)pow(2.0, i);
        for(int segCorrente = 0; segCorrente < inc; segCorrente++){
            ShellSort(arrayA, inc, segCorrente, n);
        }
    }

    imprimeArray(arrayA, n);

    /*
    // Passo a Passo
    for(int i=2; i >= 0; i--){
        int inc = (int)pow(2.0, i);

        printf("\nCom %d Segmentos: ", inc);
        for(int segCorrente = 0; segCorrente < inc; segCorrente++){
            ShellSortStepByStep(arrayA, inc, segCorrente, n);

        }

        printf("\nOrdenado: ");
        imprimeArray(arrayA, n);
    }
    */

    //Ordenando Array utilizando Bubble Sort
    printf("\n\n Ordenando o Array - Bubble Sort: \n");
    copiaValoresArray(arrayOriginal, arrayA, n);
    imprimeArray(arrayA, n);
    BubbleSort(arrayA, n);
    imprimeArray(arrayA, n);
    //BubbleSortStepByStep(arrayA, n);

    //Impressao do Numero de Comparacoes e Trocas dos Algoritmos de Ordenação
    printf("\n\n Analise dos Algoritmos de Ordenacao");
    printf("\n\t\t Comparacoes \t Trocas");
    printf("\n IS\t\t %d \t\t %d", numComparacoesIS, numTrocasIS);
    printf("\n MS\t\t %d \t\t %d", numComparacoesMS, numTrocasMS);
    printf("\n OB\t\t %d \t\t %d", numComparacoesOB, numTrocasOB);
    printf("\n SS\t\t %d \t\t %d", numComparacoesSS, numTrocasSS);
    printf("\n BS\t\t %d \t\t %d\n\n", numComparacoesBS, numTrocasBS);

    return 0;
}
