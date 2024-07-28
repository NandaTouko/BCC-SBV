/**
 * @file utils.c
 * @author Prof. Dr. David Buzatto
 * @brief Utilitary functions implementation.
 *
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "raylib.h"
#include "utils.h"
#include "GameWorld.h"

double toRadians(double degrees)
{
    return degrees * PI / 180.0;
}

double toDegrees(double radians)
{
    return radians * 180.0 / PI;
}

void topDown(int *array, int inicio, int fim, int *arrayCopia, int tamanho)
{
    int meio;
    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;
        topDown(array, inicio, meio, arrayCopia, tamanho);
        topDown(array, meio + 1, fim, arrayCopia, tamanho);
        merge(array, inicio, meio, fim, arrayCopia);
    }

    printArray(array, tamanho);
    // drawGameWorld(array, tamanho);
}

void merge(int *array, int inicio, int meio, int fim, int *arrayCopia)
{
    int i = inicio;
    int j = meio + 1;

    for (int k = inicio; k <= fim; k++)
    {
        arrayCopia[k] = array[k];
    }

    for (int k = inicio; k <= fim; k++)
    {
        if (i > meio)
        {
            array[k] = arrayCopia[j++];
        }
        else if (j > fim)
        {
            array[k] = arrayCopia[i++];
        }
        else if (arrayCopia[j] < arrayCopia[i])
        {
            array[k] = arrayCopia[j++];
        }
        else
        {
            array[k] = arrayCopia[i++];
        }
    }
}

void printArray(int *array, int tamanho)
{
    printf("\n ");
    for (int i = 0; i < tamanho; i++)
    {
        printf(" %d", array[i]);
    }

    drawGameWorld(array, tamanho);
}