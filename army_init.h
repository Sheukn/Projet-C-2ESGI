void init_player(player* player, int id){
    player->id = id;
    player->remaining_units = 7;
    player->army = malloc(sizeof(unit) * 7);
    for(int i = 0; i < 7; i++){
        if(i < 2){  // Knights
            player->army[i].team = id;
            player->army[i].type = 0;
            player->army[i].hp = 1;
            player->army[i].atk = 40;
            player->army[i].def = 25;
            player->army[i].weak = 1; // Weak against archer
            player->army[i].speed = 50;
            player->army[i].range = 1;
            player->army[i].symbol = 'K';
            player->army[i].alive = 1;
            player->army[i].hasMoved = false;
            player->army[i].hasAttacked = false;
        }


        else if(i < 4){ // Archers
            player->army[i].team = id;
            player->army[i].type = 1;
            player->army[i].hp = 1;
            player->army[i].atk = 30;
            player->army[i].def = 1;
            player->army[i].weak = 2; // Weak against horseman
            player->army[i].speed = 3;
            player->army[i].range = 2;
            player->army[i].symbol = 'A';
            player->army[i].alive = 1;
            player->army[i].hasMoved = false;
            player->army[i].hasAttacked = false;
        } 


        else if(i < 5){ // Horseman
            player->army[i].team = id;
            player->army[i].type = 2;
            player->army[i].hp = 1;
            player->army[i].atk = 40;
            player->army[i].def = 20;
            player->army[i].weak = 4; // Weak against spearman
            player->army[i].speed = 5;
            player->army[i].range = 1;
            player->army[i].symbol = 'H';
            player->army[i].alive = 1;
            player->army[i].hasMoved = false;
            player->army[i].hasAttacked = false;
        } 


        else if(i < 6){ // Catapults
            player->army[i].team = id;
            player->army[i].type = 3;
            player->army[i].hp = 1;
            player->army[i].atk = 65;
            player->army[i].def = 0;
            player->army[i].weak = 2; // Weak against horseman
            player->army[i].speed = 2;
            player->army[i].range = 3;
            player->army[i].symbol = 'C';
            player->army[i].alive = 1;
            player->army[i].hasMoved = false;
            player->army[i].hasAttacked = false;
        } 
        else { // Spearman
            player->army[i].team = id;
            player->army[i].type = 4;
            player->army[i].hp = 1;
            player->army[i].atk = 35;
            player->army[i].def = 20;
            player->army[i].weak = 1; // Weak against archer
            player->army[i].speed = 4;
            player->army[i].range = 1;
            player->army[i].symbol = 'S';
            player->army[i].alive = 1;
            player->army[i].hasMoved = false;
            player->army[i].hasAttacked = false;
        }
    }
}