#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>

#include "struct.h"
#include "army_init.h"
#include "unitsPlacements.h"
#include "unitDeplacement.h"
#include "combatSystem.h"


int main(){

    // Initialize the players
    player* player1;
    player1 = malloc(sizeof(player));
    init_player(player1, 1);

    player* player2;
    player2 = malloc(sizeof(player));
    init_player(player2, 2);

    // Create grid 50x50 with ' ' as empty space
    char **grid;
    grid = malloc(sizeof(char*) * 50);
    for(int i = 0; i < 50; i++){
        grid[i] = malloc(sizeof(char) * 50);
        for(int j = 0; j < 50; j++){
            grid[i][j] = ' ';
        }
    }

    //Create walls '#'
    for(int i = 0; i < 50; i++){
        grid[i][0] = '#';
        grid[i][49] = '#';
        grid[0][i] = '#';
        grid[49][i] = '#';
    }

    initPlacement(grid, player1, player2);

    int currentUnit = 0;
    int turn = 0;

    while(1){
        
        if(turn % 2 == 0)            displayRange(player1->army[currentUnit % 10], grid);
        else                         displayRange(player2->army[currentUnit % 10], grid);
        
        for(int i = 0; i < 50; i++){
            for(int j = 0; j < 50; j++){
                printf("%c ", grid[i][j]);
            }
            printf("\n");
        }

        if (turn % 2 == 0){
            switch (moveUnit(grid, &player1->army[currentUnit % 10])){
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
            inRange(player1->army[currentUnit % 10], grid);
        }
        else{
            switch (moveUnit(grid, &player2->army[currentUnit % 10])){
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
            inRange(player1->army[currentUnit % 10], grid);
        }

        // Clear the range
        for(int i = 0; i < 50; i++){
            for(int j = 0; j < 50; j++){
                if(grid[i][j] == 'R'){
                    grid[i][j] = ' ';
                }
            }
        }
        system("cls");  
    }

    free(player1->army);
    free(player1);
    free(player2->army);
    free(player2);
    free(grid);
    }
