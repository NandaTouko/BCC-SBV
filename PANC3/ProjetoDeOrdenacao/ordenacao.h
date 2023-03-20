#ifndef ORDENACAO_H_
#define ORDENACAO_H_

void gerandoArrayAleatorio(int arrayOriginal[], int n);
void imprimeArray(int arrayOriginal[], int n);
void insertionSort(int arrayOriginal[], int n);
void insertionSortAlternativo(int arrayOriginal[], int n);
void copiaValoresEntreArrays(int arrayOriginal[], int arrayA[], int n);
void mergeSortRecursivoSS(int arrayA[], int inicio, int fim, int n);
void intercalaSemSentinela(int arrayA[], int inicio, int meio, int fim, int n);
void mergeSortRecursivoCS(int arrayA[], int inicio, int fim);
void intercalaComSentinela(int arrayA[], int inicio, int meio, int fim);

// TO DO
void insertionSortDecrescente(int arrayOriginal[], int n);
void mergeSortRecursivoSSDecrescente(int arrayA[], int inicio, int fim, int n);
void intercalaSemSentinelaDecrescente(int arrayA[], int inicio, int meio, int fim, int n);

#endif // ORDENACAO_H
