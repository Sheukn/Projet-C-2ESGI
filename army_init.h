void init_player(player* player, int id){
    player->id = id;
    player->remaining_units = 10;
    player->army = malloc(sizeof(unit) * 10);

    player->army[0].team = id;
    player->army[0].type = 2;
    player->army[0].hp = 100;
    player->army[0].atk = 10;
    player->army[0].def = 5;
    player->army[0].weak = 4; // Weak against spearman
    player->army[0].speed = 5;
    player->army[0].range = 1;
    player->army[0].symbol = 'H';
    player->army[0].alive = 1;
    player->army[0].hasMoved = false;
    
    
    /*for(int i = 0; i < 10; i++){
        if(i < 2){ 
            player->army[i].team = id;
            player->army[i].type = 0;
            player->army[i].hp = 100;
            player->army[i].atk = 20;
            player->army[i].def = 10;
            player->army[i].weak = 1; // Weak against archer
            player->army[i].speed = 3;
            player->army[i].range = 1;
            player->army[i].symbol = 'K';
            player->army[i].alive = 1;
        } // Knights
        else if(i < 4){
            player->army[i].team = id;
            player->army[i].type = 1;
            player->army[i].hp = 100;
            player->army[i].atk = 20;
            player->army[i].def = 5;
            player->army[i].weak = 2; // Weak against horseman
            player->army[i].speed = 3;
            player->army[i].range = 2;
            player->army[i].symbol = 'A';
            player->army[i].alive = 1;
        } // Archers
        else if(i < 6){
            player->army[i].team = id;
            player->army[i].type = 2;
            player->army[i].hp = 100;
            player->army[i].atk = 10;
            player->army[i].def = 5;
            player->army[i].weak = 4; // Weak against spearman
            player->army[i].speed = 5;
            player->army[i].range = 1;
            player->army[i].symbol = 'H';
            player->army[i].alive = 1;
        } // Horseman
        else if(i < 8){
            player->army[i].team = id;
            player->army[i].type = 3;
            player->army[i].hp = 100;
            player->army[i].atk = 10;
            player->army[i].def = 5;
            player->army[i].weak = 2; // Weak against horseman
            player->army[i].speed = 1;
            player->army[i].range = 5;
            player->army[i].symbol = 'C';
            player->army[i].alive = 1;
        } // Catapults
        else {
            player->army[i].team = id;
            player->army[i].type = 4;
            player->army[i].hp = 100;
            player->army[i].atk = 10;
            player->army[i].def = 5;
            player->army[i].weak = 1; // Weak against archer
            player->army[i].speed = 4;
            player->army[i].range = 1;
            player->army[i].symbol = 'S';
            player->army[i].alive = 1;
        } // Spearman
    }*/
}