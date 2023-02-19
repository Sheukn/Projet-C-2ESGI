#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "struct.h"
#include "army_init.h"
#include "unitsPlacements.h"
#include "unitDeplacement.h"
#include "combatSystem.h"

int main(int argc, char *argv[]){

    //SDL Initialisation
    bool quit = false;
    SDL_Event event;
    int Init;
    Init = SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface * window ;
    window = SDL_SetVideoMode(1024, 1024, 32, SDL_HWSURFACE);
    SDL_Surface * grass_image = SDL_LoadBMP("./ressources/grass.bmp");
    SDL_Surface * ocean_image = SDL_LoadBMP("./ressources/ocean.bmp");
    SDL_Surface * knight_image = IMG_Load("./ressources/knight.png");
    SDL_Surface * archer_image = IMG_Load("./ressources/archer.png");
    SDL_Surface * catapult_image = IMG_Load("./ressources/catapult.png");
    SDL_Surface * spearman_image = IMG_Load("./ressources/spearman.png");
    SDL_Surface * tree_image = IMG_Load("./ressources/tree.png");
    SDL_Surface * cursor_image = IMG_Load("./ressources/cursor.png");

    SDL_Rect position;
    //position.x = (window->w - knight_image->w) / 2;
    //position.y = (window->h - knight_image->h) / 2;


    //SDL_BlitSurface(knight_image, NULL, window, &position);
    //SDL_Flip(window);
    
    // Initialize the players
    player* player1;
    player1 = malloc(sizeof(player));
    init_player(player1, 1);

    player* player2;
    player2 = malloc(sizeof(player));
    init_player(player2, 2);

    // Create map 16x16 with '-' as empty space
    cell **map;
    map = malloc(sizeof(cell) * 16);
    for(int i = 0; i < 16; i++){
        map[i] = malloc(sizeof(cell) * 16);
        for(int j = 0; j < 16; j++){
            map[i][j].type = '-';
            map[i][j].unit = NULL;
        }
    }

    //Create walls '#'
    for(int i = 0; i < 16; i++){
        map[i][0].type = '#';
        map[i][15].type = '#';
        map[0][i].type = '#';
        map[15][i].type = '#';
    }
    
    //Initialize cursor

    cursor cursor;
    cursor.pos.x = 1;
    cursor.pos.y = 1;

    SDL_Rect cursorPos;

    //cursor.pos = {1,1};

    

    initPlacement(map, player1, player2);

    int currentUnit = 0;
    int turn = 0;

    while (!quit)
    {
        SDL_WaitEvent(&event);
 
        switch (event.type){
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym){
                    case SDLK_DOWN:
                        if(cursor.pos.y < 15)
                            cursor.pos.y += 1;
                        break;
                    case SDLK_UP:
                        if(cursor.pos.y > 0)
                            cursor.pos.y -= 1;
                        break;
                    case SDLK_LEFT:
                        if(cursor.pos.x > 0)
                            cursor.pos.x -= 1;
                        break;
                    case SDLK_RIGHT:
                        if(cursor.pos.x < 15)
                            cursor.pos.x += 1;
                        break;
                }         
        }
        cursorPos.x = cursor.pos.x * 64;
        cursorPos.y = cursor.pos.y * 64;

        moveUnit(map, &player1->army[0]);
        SDL_Rect screenPos;
        for(int i = 0; i < 16; i++){
            for(int j = 0; j < 16; j++){
                
                screenPos.x = i * 64;
                screenPos.y = j * 64;
                if(map[i][j].type == '-'){
                    SDL_BlitSurface(grass_image, NULL, window, &screenPos);
                    
                }
                if(map[i][j].type == '#'){
                    SDL_BlitSurface(ocean_image, NULL, window, &screenPos);
                    
                }
                if(map[i][j].unit != NULL){
                    if(map[i][j].unit->type == 0){
                        SDL_BlitSurface(knight_image, NULL, window, &screenPos);
                        
                    }

                    switch(map[i][j].unit->type){
                        case 0:
                            SDL_BlitSurface(knight_image, NULL, window, &screenPos);
                            break;
                        case 1:
                            SDL_BlitSurface(archer_image, NULL, window, &screenPos);
                            break;
                        // case 2: 
                        //     SDL_BlitSurface(knight_image, NULL, window, &screenPos);
                        //     break;
                        case 3:
                            SDL_BlitSurface(catapult_image, NULL, window, &screenPos);
                            break;
                        case 4: 
                            SDL_BlitSurface(spearman_image, NULL, window, &screenPos);
                            break;
                    }
                }
            }
        }
        SDL_BlitSurface(cursor_image, NULL, window, &cursorPos);
        SDL_Flip(window);
    }

    SDL_FreeSurface(window);
    SDL_Quit();
    free(map);
 
    return 0;
}