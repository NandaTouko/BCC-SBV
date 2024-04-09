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

// variáveis globais
float acumulador;
float aguardarPor;
int valor;

GameWorld* createGameWorld( void ) {

    GameWorld *gw = (GameWorld*) malloc( sizeof( GameWorld ) );

    gw->dummy = 0;


    acumulador = 0;
    aguardarPor = 0.5;
    valor = 0;

    return gw;

}

void destroyGameWorld( GameWorld *gw ) {
    free( gw );
}

void inputAndUpdateGameWorld( GameWorld *gw ) {

    acumulador += GetFrameTime();
    if ( acumulador >= aguardarPor ) {
        valor++;
        acumulador = 0;
    }

}

void drawGameWorld( GameWorld *gw ) {

    BeginDrawing();
    ClearBackground( WHITE );

    DrawText( TextFormat( "valor: %d", valor ), 100, 100, 40, BLACK );

    EndDrawing();

}