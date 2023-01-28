#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include "struct.h"
#include "army_init.h"
#include "canAttack.h"	

int main()
{

    // Initialize the army
    player* player1;
    player1 = malloc(sizeof(player));
    init_player(player1, 1);

    // Create grid 20x20 with ' ' as empty space
    char **grid;
    grid = malloc(sizeof(char*) * 20);
    for(int i = 0; i < 20; i++){
        grid[i] = malloc(sizeof(char) * 20);
        for(int j = 0; j < 20; j++){
            grid[i][j] = ' ';
        }
    }


    //Create walls '#'
    for(int i = 0; i < 20; i++){
        grid[i][0] = '#';
        grid[i][19] = '#';
        grid[0][i] = '#';
        grid[19][i] = '#';
    }


    // Place the unit
    player1->army[0].pos.x = 3;
    player1->army[0].pos.y = 3;
    grid[player1->army[0].pos.x][player1->army[0].pos.y] = 'A';
    printf("Player 1's first unit's x position: %d\n", player1->army[0].pos.x);
    printf("Player 1's first unit's y position: %d\n", player1->army[0].pos.y);

    



    //place the enemy
    grid[5][5] = 'E';
    grid[10][10] = 'E';
    grid[1][1] = 'E';

   


    while(1){
        
        // Print the unit's range all around it in the grid
        for(int i = player1->army[0].pos.x - player1->army[0].range; i <= player1->army[0].pos.x + player1->army[0].range; i++){
            for(int j = player1->army[0].pos.y - player1->army[0].range; j <= player1->army[0].pos.y + player1->army[0].range; j++){
                if(grid[i][j] != '#' && grid[i][j] != 'A' && grid[i][j] != 'E'){
                    grid[i][j] = 'R';
                }
            }
        }
        // Print the grid
        printf("Player 1's first unit's range: %d\n", player1->army[0].range);
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 20; j++){
                printf("%c ", grid[i][j]);
            }
            printf("\n");
        }
        


        switch(getch()){
            case 'a':
                if(grid[player1->army[0].pos.x][player1->army[0].pos.y - 1] == ' ' || grid[player1->army[0].pos.x][player1->army[0].pos.y - 1] == 'R'){
                    grid[player1->army[0].pos.x][player1->army[0].pos.y] = ' ';
                    player1->army[0].pos.y -= 1;
                    grid[player1->army[0].pos.x][player1->army[0].pos.y] = 'A';
                    
                }
                break;
            case 'd':
                if(grid[player1->army[0].pos.x][player1->army[0].pos.y + 1] == ' ' || grid[player1->army[0].pos.x][player1->army[0].pos.y + 1] == 'R'){
                    grid[player1->army[0].pos.x][player1->army[0].pos.y] = ' ';
                    player1->army[0].pos.y += 1;
                    grid[player1->army[0].pos.x][player1->army[0].pos.y] = 'A';
                }
                break;
            case 'w':
                if(grid[player1->army[0].pos.x - 1][player1->army[0].pos.y] == ' ' || grid[player1->army[0].pos.x - 1][player1->army[0].pos.y] == 'R'){
                    grid[player1->army[0].pos.x][player1->army[0].pos.y] = ' ';
                    player1->army[0].pos.x -= 1;
                    grid[player1->army[0].pos.x][player1->army[0].pos.y] = 'A';
                }
                break;
            case 's':
                if(grid[player1->army[0].pos.x + 1][player1->army[0].pos.y] == ' ' || grid[player1->army[0].pos.x + 1][player1->army[0].pos.y] == 'R'){
                    grid[player1->army[0].pos.x][player1->army[0].pos.y] = ' ';
                    player1->army[0].pos.x += 1;
                    grid[player1->army[0].pos.x][player1->army[0].pos.y] = 'A';
                }
                break;
            case 'q':
                free(player1->army);
                free(player1);
                free(grid);
                return 0;
        }
        // Clear the range
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 20; j++){
                if(grid[i][j] == 'R'){
                    grid[i][j] = ' ';
                }
            }
        }
        system("cls");
        isReachable(player1->army[0], grid);
    }
}