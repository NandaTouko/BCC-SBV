/**
 * @file main.c
 * @author Prof. Dr. David Buzatto
 * @brief Main function and logic for the game. Base template for game
 * development in C using Raylib (https://www.raylib.com/).
 * 
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/*---------------------------------------------
 * Library headers.
 --------------------------------------------*/
#include <raylib.h>
//#include <raymath.h>

//#define RAYGUI_IMPLEMENTATION
//#include <raygui.h>
//#undef RAYGUI_IMPLEMENTATION

/*---------------------------------------------
 * Project headers.
 --------------------------------------------*/
#include <utils.h>

/*---------------------------------------------
 * Macros. 
 --------------------------------------------*/
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450
#define WINDOW_TITLE "Quadrado Latino"
#define WINDOW_TARGET_FPS 60
#define WINDOW_ANTIALIASING
//#define WINDOW_RESIZABLE
//#define WINDOW_FULL_SCREEN
//#define WINDOW_UNDECORATED
//#define WINDOW_ALWAYS_ON_TOP
//#define WINDOW_ALWAYS_RUN
//#define WINDOW_INIT_AUDIO
#define LINHAS 4
#define COLUNAS 4

/*--------------------------------------------
 * Constants. 
 -------------------------------------------*/


/*---------------------------------------------
 * Custom types (enums, structs, unions etc.).
 --------------------------------------------*/
typedef struct GameWorld {
    int dummy;
} GameWorld;


/*---------------------------------------------
 * Global variables.
 --------------------------------------------*/
GameWorld gw;

char labirinto[LINHAS][COLUNAS] = {
    {'B', '-', '-', 'D'},
    {'-', 'D', 'B', '-'},
    {'-', 'C', 'D', '-'},
    {'D', '-', '-', 'C'},
};

char opcoesLetras[LINHAS] = {'A', 'B', 'C', 'D'};

/*---------------------------------------------
 * Function prototypes. 
 --------------------------------------------*/
/**
 * @brief Reads user input and updates the state of the game.
 * @param gw GameWorld struct pointer.
 */
void inputAndUpdate( GameWorld *gw );

/**
 * @brief Draws the state of the game.
 * @param gw GameWorld struct pointer.
 */
void draw( const GameWorld *gw );

/**
 * @brief Create the global Game World object and all of its dependecies.
 */
void createGameWorld( void );

/**
 * @brief Destroy the global Game World object and all of its dependencies.
 */
void destroyGameWorld( void );

/**
 * @brief Load game resources like images, textures, sounds,
 * fonts, shaders etc.
 */
void loadResources( void );

/**
 * @brief Unload the once loaded game resources.
 */
void unloadResources( void );

int main( void ) {

    #ifdef WINDOW_ANTIALIASING
        SetConfigFlags( FLAG_MSAA_4X_HINT );
    #endif

    #ifdef WINDOW_RESIZABLE
        SetConfigFlags( FLAG_WINDOW_RESIZABLE );
    #endif

    #ifdef WINDOW_FULL_SCREEN
        SetConfigFlags( FLAG_FULLSCREEN_MODE );
    #endif

    #ifdef WINDOW_UNDECORATED
        SetConfigFlags( FLAG_WINDOW_UNDECORATED );
    #endif

    #ifdef WINDOW_ALWAYS_ON_TOP
        SetConfigFlags( FLAG_WINDOW_TOPMOST );
    #endif

    #ifdef WINDOW_ALWAYS_RUN
        SetConfigFlags( FLAG_WINDOW_ALWAYS_RUN );
    #endif

    InitWindow( WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE );
    #ifdef WINDOW_INIT_AUDIO
        InitAudioDevice();
    #endif
    SetTargetFPS( WINDOW_TARGET_FPS );    

    loadResources();
    createGameWorld();
    while ( !WindowShouldClose() ) {
        inputAndUpdate( &gw );
        draw( &gw );
    }
    unloadResources();
    destroyGameWorld();

    #ifdef WINDOW_INIT_AUDIO
        CloseAudioDevice();
    #endif
    CloseWindow();
    return 0;

}

void inputAndUpdate( GameWorld *gw ) {

}

bool selecionarLetra(int linha, int coluna, int letra);
bool backtrack(int linha, int coluna);

void draw( const GameWorld *gw ) {

    BeginDrawing();
    ClearBackground( WHITE );

    const int largQuadrado = 80;

    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
            if(labirinto[i][j] != '-') {
                DrawText(TextFormat("%c", labirinto[i][j]), (j * largQuadrado) + 20, (i * largQuadrado) + 20, 40, BLACK);
            }

            DrawRectangleLines(j * largQuadrado, i * largQuadrado, largQuadrado, largQuadrado, PURPLE);
        }
    }

    EndDrawing();

}

void createGameWorld( void ) {

    printf( "creating game world...\n" );

    gw = (GameWorld) {
        .dummy = 0
    };

    if (backtrack(0, 0)) {
        for(int i = 0; i < LINHAS; i++){
            for(int j = 0; j < COLUNAS; j++){
                printf("%c\t", labirinto[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Não foi possível encontrar uma solução!\n");
    }
}

void destroyGameWorld( void ) {
    printf( "destroying game world...\n" );
}

void loadResources( void ) {
    printf( "loading resources...\n" );
}

void unloadResources( void ) {
    printf( "unloading resources...\n" );
}

bool backtrack(int linha, int coluna) {
    if (linha == LINHAS) {
        return true; // Todas as linhas foram preenchidas
    }
    
    if (coluna == COLUNAS) {
        return backtrack(linha + 1, 0); // Preencher próxima linha
    }

    if (labirinto[linha][coluna] != '-') {
        return backtrack(linha, coluna + 1); // Já preenchido, passar para próxima coluna
    }

    for (int i = 0; i < LINHAS; i++) {
        if (selecionarLetra(linha, coluna, opcoesLetras[i])) {
            labirinto[linha][coluna] = opcoesLetras[i];

            if (backtrack(linha, coluna + 1)) {
                return true; // Encontrou solução
            }

            labirinto[linha][coluna] = '-'; // Não encontrou solução, desfazer escolha
        }
    }

    return false; // Nenhuma letra serve nesta posição
}

bool selecionarLetra(int linha, int coluna, int letra) {
    for(int i = 0; i < LINHAS; i++){
        if((labirinto[i][coluna] == letra || labirinto[linha][i] == letra) && (i != linha || i != coluna)){
            return false;
        }
    }

    return true;
}