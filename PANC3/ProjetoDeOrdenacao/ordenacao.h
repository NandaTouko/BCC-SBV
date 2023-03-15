#ifndef ORDENACAO_H_
#define ORDENACAO_H_

void gerandoArrayAleatorio(int arrayOriginal[], int n);
void imprimeArray(int arrayOriginal[], int n);
void insertionSort(int arrayOriginal[], int n);
void insertionSortAlternativo(int arrayOriginal[], int n);
void copiaValoresEntreArrays(int arrayOriginal[], int arrayA[], int n);
void mergeSortRecursivo(int arrayA[], int inicio, int fim);
void intercalaSemSentinela(int arrayA[], int inicio, int meio, int fim);

#endif // ORDENACAO_H
