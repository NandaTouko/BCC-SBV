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
#define WINDOW_TITLE "Window Title"
#define WINDOW_TARGET_FPS 60
#define WINDOW_ANTIALIASING
//#define WINDOW_RESIZABLE
//#define WINDOW_FULL_SCREEN
//#define WINDOW_UNDECORATED
//#define WINDOW_ALWAYS_ON_TOP
//#define WINDOW_ALWAYS_RUN
//#define WINDOW_INIT_AUDIO

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

void draw( const GameWorld *gw ) {

    BeginDrawing();
    ClearBackground( WHITE );

    /*
        Definir cor diferente:
            (Color) { r = 0, g = 100, b = 100, a = 255} OU
            GetColor(0x00FF00FF)
    */

    DrawCircle(400, 100, 60, BROWN); // Cabeça
    DrawCircle(380, 85, 10, DARKBROWN); // Olho Esquerdo
    DrawCircle(420, 85, 10, DARKBROWN); // Olho Direito
    DrawCircle(400, 135, 6, PURPLE); // Boca
    DrawRectangle(360, 160, 80, 90, GREEN); // Corpo
    DrawRectangle(360, 251, 35, 50, BROWN); // Perna Esquerda
    DrawRectangle(405, 251, 35, 50, BROWN); // Perna Direita

    EndDrawing();

}

void createGameWorld( void ) {

    printf( "creating game world...\n" );

    gw = (GameWorld) {
        .dummy = 0
    };

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