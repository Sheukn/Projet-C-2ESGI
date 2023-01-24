#include <stdio.h>

struct position {
    int x; // x coordinate
    int y; // y coordinate
};

struct unit{
    int id; // 0 = gunners | 1 = rocketeers | 2 = tanks | 3 = planes
    struct position pos; // position of the unit
    int hp; // health points
    int atk; // attack points
    int def; // defense points 
    int weak; // weak against 0 = gunners | 1 = rocketeers | 2 = tanks | 3 = planes   
    int speed; // speed of the unit
    int range; // range of the unit
};

struct player{
    int id; // 1 = player1 | 2 = player2
    int remaining_units; 
    struct unit unit[8]; // 2 gunners | 2 rocketeers | 2 tanks | 2 planes
};

struct player player1; 
struct player player2;

void init_player1(){
    player1.id = 1;
    player1.remaining_units = 8;
    for(int i = 0; i < 8; i++){
        if(i < 2){ // 2 gunners
            player1.unit[i].id = 0; 
            player1.unit[i].pos.x = 0;
            player1.unit[i].pos.y = 0;
            player1.unit[i].hp = 100;
            player1.unit[i].atk = 10;
            player1.unit[i].def = 5;
            player1.unit[i].weak = 3; // weak against planes
            player1.unit[i].speed = 3;
            player1.unit[i].range = 1;
        }
        else if(i < 4){ // 2 rocketeers
            player1.unit[i].id = 1;
            player1.unit[i].pos.x = 0;
            player1.unit[i].pos.y = 0;
            player1.unit[i].hp = 100;
            player1.unit[i].atk = 20;
            player1.unit[i].def = 10;
            player1.unit[i].weak = 0; // weak against gunners
            player1.unit[i].speed = 2;
            player1.unit[i].range = 2;
        }
        else if(i < 6){ // 2 tanks
            player1.unit[i].id = 2;
            player1.unit[i].pos.x = 0;
            player1.unit[i].pos.y = 0;
            player1.unit[i].hp = 100;
            player1.unit[i].atk = 30;
            player1.unit[i].def = 15;
            player1.unit[i].weak = 1; // weak against rocketeers
            player1.unit[i].speed = 5;
            player1.unit[i].range = 1;
        }
        else{ // 2 planes
            player1.unit[i].id = 3;
            player1.unit[i].pos.x = 0;
            player1.unit[i].pos.y = 0;
            player1.unit[i].hp = 100;
            player1.unit[i].atk = 40;
            player1.unit[i].def = 20;
            player1.unit[i].weak = 2; // weak against tanks
            player1.unit[i].speed = 10;
            player1.unit[i].range = 1;
        }
    }
}

void init_player2(){ 
    player2.id = 2;
    player2.remaining_units = 8;
    for(int i = 0; i < 8; i++){
        if(i < 2){ // 2 gunners
            player2.unit[i].id = 0;
            player2.unit[i].pos.x = 0;
            player2.unit[i].pos.y = 0;
            player2.unit[i].hp = 100;
            player2.unit[i].atk = 10;
            player2.unit[i].def = 5;
            player2.unit[i].weak = 3;
        }
        else if(i < 4){ // 2 rocketeers
            player2.unit[i].id = 1;
            player2.unit[i].pos.x = 0;
            player2.unit[i].pos.y = 0;
            player2.unit[i].hp = 100;
            player2.unit[i].atk = 20;
            player2.unit[i].def = 10;
            player2.unit[i].weak = 0;
        }
        else if(i < 6){ // 2 tanks
            player2.unit[i].id = 2;
            player2.unit[i].pos.x = 0;
            player2.unit[i].pos.y = 0;
            player2.unit[i].hp = 100;
            player2.unit[i].atk = 30;
            player2.unit[i].def = 15;
            player2.unit[i].weak = 1;
        }
        else{ // 2 planes
            player2.unit[i].id = 3;
            player2.unit[i].pos.x = 0;
            player2.unit[i].pos.y = 0;
            player2.unit[i].hp = 100;
            player2.unit[i].atk = 40;
            player2.unit[i].def = 20;
            player2.unit[i].weak = 2;
        }
    }
}



