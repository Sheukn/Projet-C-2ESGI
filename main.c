#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "struct.h"
#include "army_init.h"
#include "display.h"
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
    window = SDL_SetVideoMode(1400, 1024, 32, SDL_HWSURFACE);

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

    //Create forest 'F'
    map[2][1].type = 'F';
    map[2][2].type = 'F';
    
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
                    case SDLK_SPACE:
                        if(map[cursor.pos.x][cursor.pos.y].unit){
                            moveUnit(map, map[cursor.pos.x][cursor.pos.y].unit, window, cursor);
                        }
                        break;

                }         
        }
        cursorPos.x = cursor.pos.x * 64;
        cursorPos.y = cursor.pos.y * 64;

        //moveUnit(map, &player1->army[0]);
        mapActualization(map, window, cursorPos);
        cellInformationActualization(window, cursorPos, map);
    }

    SDL_FreeSurface(window);
    SDL_Quit();
    free(map);
 
    return 0;
}
