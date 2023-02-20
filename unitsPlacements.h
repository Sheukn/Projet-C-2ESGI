void initPlacement(cell** map, player* player1, player* player2){
    player1->army[0].pos.x = 1;
    player1->army[0].pos.y = 1;
    map[player1->army[0].pos.x][player1->army[0].pos.y].unit = &player1->army[0];

    player2->army[0].pos.x = 1;
    player2->army[0].pos.y = 4;
    map[player2->army[0].pos.x][player2->army[0].pos.y].unit = &player2->army[0];
/*
    player1->army[2].pos.x = 4;
    player1->army[2].pos.y = 4;
    map[player1->army[2].pos.x][player1->army[2].pos.y].unit = &player1->army[2];

    player1->army[8].pos.x = 6;
    player1->army[8].pos.y = 6;
    map[player1->army[8].pos.x][player1->army[8].pos.y].unit = &player1->army[8];

    player1->army[9].pos.x = 10;
    player1->army[9].pos.y = 10;
    map[player1->army[9].pos.x][player1->army[9].pos.y].unit = &player1->army[9];

    player2->army[0].pos.x = 14;
    player2->army[0].pos.y = 14;
    map[player2->army[0].pos.x][player2->army[0].pos.y].unit =  &player2->army[0];
*/
    
}