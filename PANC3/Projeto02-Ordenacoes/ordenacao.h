/* Variaveis Globais */
int *arrayOriginal; //Array Original a ser ordenado
int *arrayA;        //Array Temporario para Manipulacao - Para nao perder dados originais
int n;              //Tamanho do Array a ser  ordenado
int numComparacoesIS,
    numTrocasIS,
    numComparacoesMS,
    numTrocasMS,
    numComparacoesOB,
    numTrocasOB,
    numComparacoesSS,
    numTrocasSS,
    numComparacoesBS,
    numTrocasBS,
    numComparacoesShakeS,
    numTrocasShakeS,
    numComparacoesCS,
    numTrocasCS,
    numComparacoesQS,
    numTrocasQS,
    numComparacoesSelS,
    numTrocasSelS,
    numComparacoesHS,
    numTrocasHS,
    numComparacoesRS,
    numTrocasRS;

/* Prototipos de Funcoes */
void geraArrayAleatorio(int arrayOriginal[], int n);
void imprimeArray(int arrayA[], int n);
void copiaValoresArray(int arrayOriginal[], int arrayA[], int n);
void insertionSort(int arrayA[], int n);
void insertionSortAlternativo(int arrayA[], int n);
void insertionSortStepByStep(int arrayA[], int n);
void MergeSortRecursivo(int arrayA[], int n, int inicio, int fim);
void IntercalaSemSentinela(int arrayA[], int n, int inicio, int meio, int fim);
void MergeSortRecursivoStepByStep(int arrayA[], int n, int inicio, int fim);
void OrdenaBinaria(int arrayA[], int n);
void OrdenaBinariaStepByStep(int arrayA[], int n);
void ShellSort(int arrayA[], int inc, int segCorrente, int n);
void ShellSortStepByStep(int arrayA[], int inc, int segCorrente, int n);
void BubbleSort(int arrayA[], int n);
void BubbleSortStepByStep(int arrayA[], int n);
void ShakeSort(int arrayA[], int n);
void ShakeSortSetpByStep(int arrayA[], int n);
void CombSort(int arrayA[], int n);
void CombSortStepByStep(int arrayA[], int n);
void QuickSort(int arrayA[], int inicio, int fim);
void QuickSortStepByStep(int arrayA[], int inicio, int fim, int n);
void SelectSort(int arrayA[], int n);
void SelectSortStepByStep(int arrayA[], int n);
void HeapSort(int arrayA[], int n);
void HeapSortStepByStep(int arrayA[], int n);
void RadixSort(int arrayA[], int n);
void RadixSortStepByStep(int arrayA[], int n);
void MMZSort(int arrayA[], int n);
