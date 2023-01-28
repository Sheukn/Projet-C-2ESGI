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

    // Create map 50x50 with ' ' as empty space
    cell **map;
    map = malloc(sizeof(cell) * 50);
    for(int i = 0; i < 50; i++){
        map[i] = malloc(sizeof(cell) * 50);
        for(int j = 0; j < 50; j++){
            map[i][j].symbol = ' ';
            map[i][j].unit = NULL;
        }
    }

    //Create walls '#'
    for(int i = 0; i < 50; i++){
        map[i][0].symbol = '#';
        map[i][49].symbol = '#';
        map[0][i].symbol = '#';
        map[49][i].symbol = '#';
    }

    initPlacement(map, player1, player2);

    int currentUnit = 0;
    int turn = 0;

    while(1){
        
        if(turn % 2 == 0)            displayRange(player1->army[currentUnit % 10], map);
        else                         displayRange(player2->army[currentUnit % 10], map);
        
        for(int i = 0; i < 50; i++){
            for(int j = 0; j < 50; j++){
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
        for(int i = 0; i < 50; i++){
            for(int j = 0; j < 50; j++){
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
    }
