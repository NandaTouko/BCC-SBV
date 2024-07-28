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
#include <math.h>
#include <string.h>

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
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Simulação da Bolinha"
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
typedef struct Bolinha {
    Vector2 pos;
    Vector2 vel;
    int raio;
    Color cor;
    bool arrastando;
} Bolinha;

typedef struct GameWorld {
    Bolinha *bolinha;
} GameWorld;


/*---------------------------------------------
 * Global variables.
 --------------------------------------------*/
GameWorld gw;
Bolinha bolinha;

Vector2 posMouse;
Vector2 offset;
Vector2 posAnterior;

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
void drawBolinha( const Bolinha *bolinha );

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
    float delta = GetFrameTime();
    float atrito = 1;
    float elasticidade = 0.9;
    float gravidade = 10;

    Bolinha *bolinha = gw->bolinha;
    posMouse = GetMousePosition();
    
    if(!bolinha->arrastando){
        // Vai aumentar a vel. em 5 pixel por seg
        bolinha->pos.x += bolinha->vel.x * delta;
        bolinha->pos.y += bolinha->vel.y * delta;

        if(bolinha->pos.x + bolinha->raio > GetScreenWidth()) {
            bolinha->pos.x = GetScreenWidth() - bolinha->raio;
            bolinha->vel.x = -bolinha->vel.x * elasticidade;
        } else if(bolinha->pos.x - bolinha->raio < 0) {
            bolinha->pos.x = bolinha->raio;
            bolinha->vel.x = -bolinha->vel.x * elasticidade;
        }

        if(bolinha->pos.y + bolinha->raio > GetScreenHeight()) {
            bolinha->pos.y = GetScreenHeight() - bolinha->raio;
            bolinha->vel.y = -bolinha->vel.y * elasticidade;
        } else if(bolinha->pos.y - bolinha->raio < 0) {
            bolinha->pos.y = bolinha->raio;
            bolinha->vel.y = -bolinha->vel.y * elasticidade;
        }
        
        bolinha->vel.x = bolinha->vel.x * atrito;
        bolinha->vel.y = bolinha->vel.y * atrito + gravidade;
    } else {
        bolinha->pos.x = posMouse.x - offset.x;
        bolinha->pos.y = posMouse.y - offset.y;
    }

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        float c1 = bolinha->pos.x - posMouse.x;
        float c2 = bolinha->pos.y - posMouse.y;

        if(c1*c1 + c2*c2 <= bolinha->raio * bolinha->raio){
            bolinha->arrastando = true;
            offset.x = posMouse.x - bolinha->pos.x;
            offset.y = posMouse.y - bolinha->pos.y;
        }
    } else if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && bolinha->arrastando) {
        bolinha->arrastando = false;
        bolinha->vel.x = (bolinha->pos.x - posAnterior.x) * 100;
        bolinha->vel.y = (bolinha->pos.y - posAnterior.y) * 100;
    }

    posAnterior = bolinha->pos;
}

void draw( const GameWorld *gw ) {

    BeginDrawing();
    ClearBackground( WHITE );

    drawBolinha(gw->bolinha);
    
    EndDrawing();

}

void drawBolinha(const Bolinha *bolinha) {
    DrawCircle(bolinha->pos.x, bolinha->pos.y, bolinha->raio, bolinha->cor);
}

void createGameWorld( void ) {

    printf( "creating game world...\n" );

    bolinha = (Bolinha) {
        .pos = {
            .x = GetScreenWidth()/2,
            .y = GetScreenHeight()/2
        },
        .vel = {
            .x = 200,
            .y = 200
        },
        .raio = 50,
        .cor = BLUE,
        .arrastando = false
    };

    gw = (GameWorld) {
        .bolinha = &bolinha
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