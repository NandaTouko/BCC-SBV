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
    {'B', 0, 0, 'D'},
    {0, 'D', 'B', 0},
    {0, 'C', 'D', 0},
    {'D', 0, 0, 'C'},
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
bool selecionarLetra(int linha, int coluna, char letter);

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

void draw( const GameWorld *gw ) {

    BeginDrawing();
    ClearBackground( WHITE );

    const int largQuadrado = 80;

    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
            if(labirinto[i][j] != 0) {
                DrawText(TextFormat("%s", &labirinto[i][j]), (largQuadrado * j)/2, (largQuadrado * i)/2, 20, BLACK);
            }

            DrawRectangleLines(largQuadrado * j, largQuadrado * i, largQuadrado, largQuadrado, PURPLE);
        }
    }

    EndDrawing();

}

void createGameWorld( void ) {

    printf( "creating game world...\n" );

    gw = (GameWorld) {
        .dummy = 0
    };

    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){

            if(labirinto[i][j] == 0) {
                for(int i = 0; i < LINHAS; i++){
                    bool resultado = selecionarLetra(i, j, opcoesLetras[i]);
                    printf("%d\n", resultado);

                    if(resultado){
                        printf("LETRA: %c\n", opcoesLetras[i]);
                        labirinto[i][j] = opcoesLetras[i];                        
                        break;
                    }
                }
            }
        }
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

bool selecionarLetra(int linha, int coluna, char letter) {
    for(int j = 0; j < coluna; j++){
        if(labirinto[linha][j] == letter){
            printf("COLUNA: %c - %c\n", labirinto[linha][j], letter);
            return false;
        }
    }

    for(int i = 0; i < linha; i++) {
        if(labirinto[i][coluna] == letter){
            printf("LINHA: %c - %c\n", labirinto[i][coluna], letter);
            return false;
        }
    }

    return true;
}