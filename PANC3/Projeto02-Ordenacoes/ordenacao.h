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
    numTrocasBS;

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
