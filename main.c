#include <stdio.h>
#include <stdlib.h>
//#include <SDL2/SDL.h>
#include "struct.h"
#include "detectionTest.h"
#include "army_init.h"



int main(int argc, char *argv[])
{
    player player1 = init_player1();
    player player2 = init_player2();
    isReachable(&player1.army[5]);
}