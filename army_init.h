player player1; 
player player2;

player init_player1(){
    player1.id = 1;
    player1.remaining_units = 10;
    for(int i = 0; i < 10; i++){
        if(i < 2){ // knight
            player1.army[i].type = 0;
            player1.army[i].pos.x = 0;
            player1.army[i].pos.y = 0;
            player1.army[i].hp = 100;
            player1.army[i].atk = 10;
            player1.army[i].def = 10;
            player1.army[i].weak = 1;  // weak against archer
            player1.army[i].speed = 10;
            player1.army[i].range = 1;
        }
        else if (i < 4){ // archer
            player1.army[i].type = 1;
            player1.army[i].pos.x = 0;
            player1.army[i].pos.y = 0;
            player1.army[i].hp = 100;
            player1.army[i].atk = 10;
            player1.army[i].def = 10;
            player1.army[i].weak = 2; // weak against horseman
            player1.army[i].speed = 10;
            player1.army[i].range = 2;
        }   
        else if (i < 6){ // horseman
            player1.army[i].type = 2;
            player1.army[i].pos.x = 0;
            player1.army[i].pos.y = 0;
            player1.army[i].hp = 100;
            player1.army[i].atk = 10;
            player1.army[i].def = 10;
            player1.army[i].weak = 4; // weak against spearman
            player1.army[i].speed = 10;
            player1.army[i].range = 1;
        }
        else if (i < 8){ // catapult
            player1.army[i].type = 3;
            player1.army[i].pos.x = 0;
            player1.army[i].pos.y = 0;
            player1.army[i].hp = 100;
            player1.army[i].atk = 10;
            player1.army[i].def = 10;
            player1.army[i].weak = 2; // weak against horseman
            player1.army[i].speed = 10;
            player1.army[i].range = 3;
        }
        else{ // spearman
            player1.army[i].type = 4;
            player1.army[i].pos.x = 0;
            player1.army[i].pos.y = 0;
            player1.army[i].hp = 100;
            player1.army[i].atk = 10;
            player1.army[i].def = 10;
            player1.army[i].weak = 1; // weak against archer
            player1.army[i].speed = 10;
            player1.army[i].range = 1;
        }
        
    }
}


//Same as init_player1 but for player2

player init_player2(){
    player2.id = 2;
    player2.remaining_units = 10;
    for(int i = 0; i < 10; i++){
        if(i < 2){ // knight
            player2.army[i].type = 0;
            player2.army[i].pos.x = 0;
            player2.army[i].pos.y = 0;
            player2.army[i].hp = 100;
            player2.army[i].atk = 10;
            player2.army[i].def = 10;
            player2.army[i].weak = 1; // weak against archer
            player2.army[i].speed = 3;
            player2.army[i].range = 1;
        }
        else if (i < 4){ // archer
            player2.army[i].type = 1;
            player2.army[i].pos.x = 0;
            player2.army[i].pos.y = 0;
            player2.army[i].hp = 100;
            player2.army[i].atk = 10;
            player2.army[i].def = 10;
            player2.army[i].weak = 2; // weak against horseman
            player2.army[i].speed = 3;
            player2.army[i].range = 2;
        }   
        else if (i < 6){ // horseman
            player2.army[i].type = 2;
            player2.army[i].pos.x = 0;
            player2.army[i].pos.y = 0;
            player2.army[i].hp = 100;
            player2.army[i].atk = 10;
            player2.army[i].def = 10;
            player2.army[i].weak = 4; // weak against spearman
            player2.army[i].speed = 5;
            player2.army[i].range = 1;
        }
        else if (i < 8){ // catapult
            player2.army[i].type = 3;
            player2.army[i].pos.x = 0;
            player2.army[i].pos.y = 0;
            player2.army[i].hp = 100;
            player2.army[i].atk = 10;
            player2.army[i].def = 10;
            player2.army[i].weak = 2; // weak against horseman
            player2.army[i].speed = 2;
            player2.army[i].range = 3;
        }
        else{ // spearman
            player2.army[i].type = 4;
            player2.army[i].pos.x = 0;
            player2.army[i].pos.y = 0;
            player2.army[i].hp = 100;
            player2.army[i].atk = 10;
            player2.army[i].def = 10;
            player2.army[i].weak = 1; // weak against archer
            player2.army[i].speed = 4;
            player2.army[i].range = 1;
        }
    }
}