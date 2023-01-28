void init_player(player* player, int id){
    player->id = id;
    player->remaining_units = 10;
    player->army = malloc(sizeof(unit) * 10);
    for(int i = 0; i < 10; i++){
        if(i < 2){ 
            player->army[i].type = 0;
            player->army[i].hp = 100;
            player->army[i].atk = 10;
            player->army[i].def = 10;
            player->army[i].weak = 1; // Weak against archer
            player->army[i].speed = 3;
            player->army[i].range = 1;
        } // Knights
        else if(i < 4){
            player->army[i].type = 1;
            player->army[i].hp = 100;
            player->army[i].atk = 10;
            player->army[i].def = 5;
            player->army[i].weak = 2; // Weak against horseman
            player->army[i].speed = 3;
            player->army[i].range = 2;
        } // Archers
        else if(i < 6){
            player->army[i].type = 2;
            player->army[i].hp = 100;
            player->army[i].atk = 10;
            player->army[i].def = 5;
            player->army[i].weak = 4; // Weak against spearman
            player->army[i].speed = 5;
            player->army[i].range = 1;
        } // Horseman
        else if(i < 8){
            player->army[i].type = 3;
            player->army[i].hp = 100;
            player->army[i].atk = 10;
            player->army[i].def = 5;
            player->army[i].weak = 2; // Weak against horseman
            player->army[i].speed = 2;
            player->army[i].range = 5;
        } // Catapults
        else {
            player->army[i].type = 4;
            player->army[i].hp = 100;
            player->army[i].atk = 10;
            player->army[i].def = 5;
            player->army[i].weak = 1; // Weak against archer
            player->army[i].speed = 2;
            player->army[i].range = 1;
        } // Spearman
    }
}