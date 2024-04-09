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
// #include "raymath.h"
// #define RAYGUI_IMPLEMENTATION
// #include "raygui.h"
// #undef RAYGUI_IMPLEMENTATION

#include "GameWorld.h"
#include "ResourceManager.h"
#include "utils.h"

GameWorld *createGameWorld(void)
{

    GameWorld *gw = (GameWorld *)malloc(sizeof(GameWorld));
    gw->tamanho = 49;
    gw->array = (int *)malloc(sizeof(int) * gw->tamanho);
    gw->arrayCopia = (int *)malloc(sizeof(int) * gw->tamanho);

    for (int i = 0; i < gw->tamanho; i++)
    {
        gw->array[i] = GetRandomValue(1, 100);
        // printf("%d ", gw->array[i]);
    }

    topDown(gw->array, 0, gw->tamanho - 1, gw->arrayCopia, gw->tamanho);
    drawGameWorld(gw->array, gw->tamanho);

    return gw;
}

void destroyGameWorld(GameWorld *gw)
{
    free(gw);
}

void inputAndUpdateGameWorld(GameWorld *gw)
{
}

void drawGameWorld(int *array, int tamanho)
{

    BeginDrawing();
    ClearBackground(WHITE);

    int margem = 20;
    int largura = 10;
    int espacamento = 5;
    int iniY = GetScreenHeight() - margem;

    for (int i = 0; i < tamanho; i++)
    {
        int altura = array[i] * 4;
        DrawRectangle(
            margem + (largura + espacamento) * i,
            iniY - altura,
            largura,
            altura,
            BLUE);
    }

    EndDrawing();
}