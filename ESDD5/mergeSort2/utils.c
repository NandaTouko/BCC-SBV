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

void topDown(int inicio, int fim, GameWorld* gw)
{
    int meio;
    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;
        topDown(inicio, meio, gw);
        topDown(meio + 1, fim, gw);
        merge(inicio, meio, fim, gw);
    }

    // printArray(gw->array, gw->tamanho);
}

void merge(int inicio, int meio, int fim, GameWorld* gw)
{
    int i = inicio;
    int j = meio + 1;

    for (int k = inicio; k <= fim; k++)
    {
        gw->copias[gw->maxCopias].copia[k] = gw->array[k];
    }

    for (int k = inicio; k <= fim; k++)
    {
        if (i > meio)
        {
           gw->array[k] = gw->copias[gw->maxCopias].copia[j++];
        }
        else if (j > fim)
        {
           gw->array[k] = gw->copias[gw->maxCopias].copia[i++];
        }
        else if (gw->copias[gw->maxCopias].copia[j] < gw->copias[gw->maxCopias].copia[i])
        {
           gw->array[k] = gw->copias[gw->maxCopias].copia[j++];
        }
        else
        {
           gw->array[k] = gw->copias[gw->maxCopias].copia[i++];
        }
    }

    gw->maxCopias++;
}

void printArray(int *array, int tamanho)
{
    printf("\n ");
    for (int i = 0; i < tamanho; i++)
    {
        printf(" %d", array[i]);
    }
}