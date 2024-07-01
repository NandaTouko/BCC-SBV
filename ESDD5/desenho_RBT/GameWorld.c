/**
 * @file GameWorld.h
 * @author Prof. Dr. David Buzatto
 * @brief GameWorld implementation.
 *
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>
#include <stdlib.h>

#include "GameWorld.h"
#include "ResourceManager.h"

#include "raylib.h"
// #include "raymath.h"
// #define RAYGUI_IMPLEMENTATION    // to use raygui, comment these three lines.
// #include "raygui.h"              // other compilation units must only include
// #undef RAYGUI_IMPLEMENTATION     // raygui.h

#include "RBT.h"

/**
 * @brief Creates a dinamically allocated GameWorld struct instance.
 */
GameWorld *createGameWorld(void)
{

    GameWorld *gw = (GameWorld *)malloc(sizeof(GameWorld));

    gw->arvore = newRBT();

    // ASCII seguindo: https://www.ime.usp.br/~kellyrb/mac2166_2015/tabela_ascii.html
    rbtPut(gw->arvore, 77); // M
    rbtPut(gw->arvore, 74); // J
    rbtPut(gw->arvore, 69); // E
    rbtPut(gw->arvore, 67); // C
    rbtPut(gw->arvore, 65); // A
    rbtPut(gw->arvore, 72); // H
    rbtPut(gw->arvore, 76); // L
    rbtPut(gw->arvore, 82); // R
    rbtPut(gw->arvore, 80); // P
    rbtPut(gw->arvore, 88); // X
    rbtPut(gw->arvore, 83); // S

    int currentRank = 0;
    int redNodeCount = 0;
    int maxBlackLevel = 0;

    rbtProcess(gw->arvore->root, &currentRank, 0, &redNodeCount, &maxBlackLevel);

    rbtInOrder(gw->arvore->root);
    printf("\n");

    return gw;
}

/**
 * @brief Destroys a GameWindow object and its dependecies.
 */
void destroyGameWorld(GameWorld *gw)
{
    free(gw);
}

/**
 * @brief Reads user input and updates the state of the game.
 */
void inputAndUpdateGameWorld(GameWorld *gw)
{
}

/**
 * @brief Draws the state of the game.
 */
void drawGameWorld(GameWorld *gw)
{

    BeginDrawing();
    ClearBackground(WHITE);

    rbtDraw(gw->arvore);

    EndDrawing();
}