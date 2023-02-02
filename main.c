#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
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
    SDL_Window * window ;
    window = SDL_CreateWindow("C Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 1024, 0);
    SDL_Surface * grass_image = SDL_LoadBMP("./src/textures/grass.bmp");
    SDL_Surface * ocean_image = SDL_LoadBMP("./src/textures/ocean.bmp");
    SDL_Surface * knight_image = 0;
    knight_image = IMG_Load("./src/textures/knight.png");
    	
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture * grass_texture = SDL_CreateTextureFromSurface(renderer, grass_image);
    SDL_Texture * ocean_texture = SDL_CreateTextureFromSurface(renderer, ocean_image);
    SDL_Texture * knight_texture = SDL_CreateTextureFromSurface(renderer, knight_image);

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
            map[i][j].symbol = '-';
            map[i][j].unit = NULL;
        }
    }

    //Create walls '#'
    for(int i = 0; i < 16; i++){
        map[i][0].symbol = '#';
        map[i][15].symbol = '#';
        map[0][i].symbol = '#';
        map[15][i].symbol = '#';
    }

    initPlacement(map, player1, player2);

    int currentUnit = 0;
    int turn = 0;

     while (!quit)
    {
        SDL_WaitEvent(&event);
 
        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        }

        for(int i = 0; i < 16; i++){
            for(int j = 0; j < 16; j++){
                SDL_Rect dstrect = { 64*i, 64*j, 64, 64};
                if(map[i][j].symbol == '-'){
                    SDL_RenderCopy(renderer, grass_texture, NULL, &dstrect);
                }
                else if(map[i][j].symbol == '#'){
                    SDL_RenderCopy(renderer, ocean_texture, NULL, &dstrect);
                }
                if(map[i][j].unit != NULL){
                    if(map[i][j].unit->symbol == 'K'){
                        SDL_RenderCopy(renderer, knight_texture, NULL, &dstrect);
                    }
                }
            }
        }

/*
        SDL_Rect dstrect = { 0, 0, 16, 16};
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        //SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
        */
       SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(grass_texture);
    SDL_DestroyTexture(ocean_texture);
    SDL_DestroyTexture(knight_texture);
    SDL_FreeSurface(grass_image);
    SDL_FreeSurface(ocean_image);
    SDL_FreeSurface(knight_image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
 
    return 0;

/*

    initPlacement(map, player1, player2);

    int currentUnit = 0;
    int turn = 0;

    while(1){
        
        if(turn % 2 == 0)            displayRange(player1->army[currentUnit % 10], map);
        else                         displayRange(player2->army[currentUnit % 10], map);
        
        for(int i = 0; i < 16; i++){
            for(int j = 0; j < 16; j++){
                printf("%c ", map[i][j].symbol);
            }
            printf("\n");
        }

        if (turn % 2 == 0){
            switch (moveUnit(map, &player1->army[currentUnit % 10])){
                case 1 : 
                    currentUnit++;
                    break;
                case 2 :
                    return 0;
                case 3 :
                    currentUnit = 0;
                    turn++;
                    break;
            }
            inRange(player1->army[currentUnit % 10], map);
        }
        else{
            switch (moveUnit(map, &player2->army[currentUnit % 10])){
                case 1 : 
                    currentUnit++;
                    break;
                case 2 :
                    return 0;
                case 3 :
                    currentUnit = 0;
                    turn++;
                    break;
            }
            inRange(player1->army[currentUnit % 10], map);
        }

        // Clear the range
        for(int i = 0; i < 16; i++){
            for(int j = 0; j < 16; j++){
                if( map[i][j].symbol == 'R') {
                    map[i][j].symbol = ' ';
                }
            }
        }
        system("cls");  
    }

    free(player1->army);
    free(player1);
    free(player2->army);
    free(player2);
    free(map);

    */
}
