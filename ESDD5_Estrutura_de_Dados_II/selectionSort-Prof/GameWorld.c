/**
 * @file GameWorld.h
 * @author Prof. Dr. David Buzatto
 * @brief GameWorld implementation.
 * 
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
//#include "raymath.h"
//#define RAYGUI_IMPLEMENTATION
//#include "raygui.h"
//#undef RAYGUI_IMPLEMENTATION

#include "GameWorld.h"
#include "ResourceManager.h"
#include "utils.h"
#include "CopiaArray.h"

GameWorld* createGameWorld( void ) {

    GameWorld *gw = (GameWorld*) malloc( sizeof( GameWorld ) );
    gw->tamanho = 50;
    gw->array = (int*) malloc( sizeof( int ) * gw->tamanho );
    gw->copias = (CopiaArray*) malloc( sizeof( CopiaArray ) * gw->tamanho );
    gw->acumulador = 0;
    gw->aguardar = .1;
    gw->copiaAtual = 0;
    gw->maxCopias = 0;

    for ( int i = 0; i < gw->tamanho; i++ ) {
        gw->array[i] = i + 1;
        gw->copias[i].tamanho = gw->tamanho;
        gw->copias[i].copia = (int*) malloc( sizeof(int) * gw->tamanho );
        for ( int j = 0; j < gw->tamanho; j++ ) {
            gw->copias[i].copia[j] = 0;
        }
    }

    for ( int i = 0; i < gw->tamanho; i++ ) {
        int p = GetRandomValue( 0, gw->tamanho - 1 );
        int t = gw->array[i];
        gw->array[i] = gw->array[p];
        gw->array[p] = t;
    }

    ordenar( gw );

    return gw;

}

void destroyGameWorld( GameWorld *gw ) {
    free( gw->array );
    for ( int i = 0; i < gw->tamanho; i++ ) {
        free( gw->copias[i].copia );
    }
    free( gw->copias );
    free( gw );
}

void inputAndUpdateGameWorld( GameWorld *gw ) {

    gw->acumulador += GetFrameTime();
    if ( gw->acumulador >= gw->aguardar ) {
        gw->acumulador = 0;
        if ( gw->copiaAtual < gw->maxCopias - 1 ) {
            gw->copiaAtual++;
        }
        
    }

}

void drawGameWorld( GameWorld *gw ) {

    BeginDrawing();
    ClearBackground( WHITE );

    int margem = 20;
    int largura = 10;
    int espacamento = 5;
    int iniY = GetScreenHeight() - margem;

    int tamanho = gw->copias[gw->copiaAtual].tamanho;
    int* array = gw->copias[gw->copiaAtual].copia;

    for ( int i = 0; i < tamanho; i++ ) {
        int altura = array[i] * 4;
        DrawRectangle( 
            margem + ( largura + espacamento ) * i, 
            iniY - altura, 
            largura, 
            altura,
            BLUE );
    }

    EndDrawing();

}