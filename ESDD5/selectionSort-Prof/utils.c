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

double toRadians( double degrees ) {
    return degrees * PI / 180.0;
}

double toDegrees( double radians ) {
    return radians * 180.0 / PI;
}

void ordenar( GameWorld* gw ) {

    int* array = gw->array;
    int tamanho = gw->tamanho;

    for ( int i = 0; i < tamanho-1; i++ ) {
        int min = i;
        for ( int j = i+1; j < tamanho; j++ ) {
            if ( array[min] > array[j] ) {
                min = j;
            }
        }
        for ( int j = 0; j < tamanho; j++ ) {
            gw->copias[i].copia[j] = gw->array[j];
        }
        gw->maxCopias++;
        trocar( array, min, i );
    }

}

void trocar( int* array, int p1, int p2 ) {
    int t = array[p1];
    array[p1] = array[p2];
    array[p2] = t;
}