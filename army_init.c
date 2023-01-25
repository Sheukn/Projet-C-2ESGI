struct position {
    int x; // x coordinate
    int y; // y coordinate
};

struct unit{
    int type; // 0 = knight | 1 = archer | 2 = horseman | 3 = catapult | 4 = spearman 
    struct position pos; // position of the unit
    int hp; // health points
    int atk; // attack points
    int def; // defense points 
    int weak; // weak againsts 0 = knight | 1 = archer | 2 = horseman | 3 = catapult | 4 = spearman   
    int speed; // speed of the unit
    int range; // range of the unit
};

struct player{
    int id; // 1 = player1 | 2 = player2
    int remaining_units; 
    struct unit unit[10]; // 2 knights | 2 archers | 2 horseman | 2 catapults | 2 spearman
};

struct player player1; 
struct player player2;

void init_player1(){
    player1.id = 1;
    player1.remaining_units = 10;
    for(int i = 0; i < 10; i++){
        if(i < 2){ // knight
            player1.unit[i].type = 0;
            player1.unit[i].pos.x = 0;
            player1.unit[i].pos.y = 0;
            player1.unit[i].hp = 100;
            player1.unit[i].atk = 10;
            player1.unit[i].def = 10;
            player1.unit[i].weak = 1;  // weak against archer
            player1.unit[i].speed = 10;
            player1.unit[i].range = 1;
        }
        else if (i < 4){ // archer
            player1.unit[i].type = 1;
            player1.unit[i].pos.x = 0;
            player1.unit[i].pos.y = 0;
            player1.unit[i].hp = 100;
            player1.unit[i].atk = 10;
            player1.unit[i].def = 10;
            player1.unit[i].weak = 2; // weak against horseman
            player1.unit[i].speed = 10;
            player1.unit[i].range = 2;
        }   
        else if (i < 6){ // horseman
            player1.unit[i].type = 2;
            player1.unit[i].pos.x = 0;
            player1.unit[i].pos.y = 0;
            player1.unit[i].hp = 100;
            player1.unit[i].atk = 10;
            player1.unit[i].def = 10;
            player1.unit[i].weak = 4; // weak against spearman
            player1.unit[i].speed = 10;
            player1.unit[i].range = 1;
        }
        else if (i < 8){ // catapult
            player1.unit[i].type = 3;
            player1.unit[i].pos.x = 0;
            player1.unit[i].pos.y = 0;
            player1.unit[i].hp = 100;
            player1.unit[i].atk = 10;
            player1.unit[i].def = 10;
            player1.unit[i].weak = 2; // weak against horseman
            player1.unit[i].speed = 10;
            player1.unit[i].range = 3;
        }
        else{ // spearman
            player1.unit[i].type = 4;
            player1.unit[i].pos.x = 0;
            player1.unit[i].pos.y = 0;
            player1.unit[i].hp = 100;
            player1.unit[i].atk = 10;
            player1.unit[i].def = 10;
            player1.unit[i].weak = 1; // weak against archer
            player1.unit[i].speed = 10;
            player1.unit[i].range = 1;
        }
        
    }
}


//Same as init_player1 but for player2

void init_player2(){
    player2.id = 2;
    player2.remaining_units = 10;
    for(int i = 0; i < 10; i++){
        if(i < 2){ // knight
            player2.unit[i].type = 0;
            player2.unit[i].pos.x = 0;
            player2.unit[i].pos.y = 0;
            player2.unit[i].hp = 100;
            player2.unit[i].atk = 10;
            player2.unit[i].def = 10;
            player2.unit[i].weak = 1; // weak against archer
            player2.unit[i].speed = 3;
            player2.unit[i].range = 1;
        }
        else if (i < 4){ // archer
            player2.unit[i].type = 1;
            player2.unit[i].pos.x = 0;
            player2.unit[i].pos.y = 0;
            player2.unit[i].hp = 100;
            player2.unit[i].atk = 10;
            player2.unit[i].def = 10;
            player2.unit[i].weak = 2; // weak against horseman
            player2.unit[i].speed = 3;
            player2.unit[i].range = 2;
        }   
        else if (i < 6){ // horseman
            player2.unit[i].type = 2;
            player2.unit[i].pos.x = 0;
            player2.unit[i].pos.y = 0;
            player2.unit[i].hp = 100;
            player2.unit[i].atk = 10;
            player2.unit[i].def = 10;
            player2.unit[i].weak = 4; // weak against spearman
            player2.unit[i].speed = 5;
            player2.unit[i].range = 1;
        }
        else if (i < 8){ // catapult
            player2.unit[i].type = 3;
            player2.unit[i].pos.x = 0;
            player2.unit[i].pos.y = 0;
            player2.unit[i].hp = 100;
            player2.unit[i].atk = 10;
            player2.unit[i].def = 10;
            player2.unit[i].weak = 2; // weak against horseman
            player2.unit[i].speed = 2;
            player2.unit[i].range = 3;
        }
        else{ // spearman
            player2.unit[i].type = 4;
            player2.unit[i].pos.x = 0;
            player2.unit[i].pos.y = 0;
            player2.unit[i].hp = 100;
            player2.unit[i].atk = 10;
            player2.unit[i].def = 10;
            player2.unit[i].weak = 1; // weak against archer
            player2.unit[i].speed = 4;
            player2.unit[i].range = 1;
        }
    }
}