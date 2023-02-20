void initPlacement(cell** map, player* player1, player* player2){

    //PLAYER 1 UNIT

    player1->army[0].pos.x = 6;
    player1->army[0].pos.y = 1;
    map[player1->army[0].pos.x][player1->army[0].pos.y].unit = &player1->army[0];

    player1->army[1].pos.x = 2;
    player1->army[1].pos.y = 3;
    map[player1->army[1].pos.x][player1->army[1].pos.y].unit = &player1->army[1];

    player1->army[2].pos.x = 4;
    player1->army[2].pos.y = 3;
    map[player1->army[2].pos.x][player1->army[2].pos.y].unit = &player1->army[2];

    player1->army[3].pos.x = 2;
    player1->army[3].pos.y = 2;
    map[player1->army[3].pos.x][player1->army[3].pos.y].unit = &player1->army[3];

    player1->army[4].pos.x = 2;
    player1->army[4].pos.y = 5;
    map[player1->army[4].pos.x][player1->army[4].pos.y].unit = &player1->army[4];

    player1->army[5].pos.x = 4;
    player1->army[5].pos.y = 1;
    map[player1->army[5].pos.x][player1->army[5].pos.y].unit = &player1->army[5];

    player1->army[6].pos.x = 3;
    player1->army[6].pos.y = 2;
    map[player1->army[6].pos.x][player1->army[6].pos.y].unit = &player1->army[6];


    //PLAYER 2 UNIT


    player2->army[0].pos.x = 9;
    player2->army[0].pos.y = 14;
    map[player2->army[0].pos.x][player2->army[0].pos.y].unit = &player2->army[0];

    player2->army[1].pos.x = 13;
    player2->army[1].pos.y = 12;
    map[player2->army[1].pos.x][player2->army[1].pos.y].unit = &player2->army[1];

    player2->army[2].pos.x = 11;
    player2->army[2].pos.y = 12;
    map[player2->army[2].pos.x][player2->army[2].pos.y].unit = &player2->army[2];

    player2->army[3].pos.x = 13;
    player2->army[3].pos.y = 13;
    map[player2->army[3].pos.x][player2->army[3].pos.y].unit = &player2->army[3];

    player2->army[4].pos.x = 13;
    player2->army[4].pos.y = 10;
    map[player2->army[4].pos.x][player2->army[4].pos.y].unit = &player2->army[4];

    player2->army[5].pos.x = 11;
    player2->army[5].pos.y = 14;
    map[player2->army[5].pos.x][player2->army[5].pos.y].unit = &player2->army[5];

    player2->army[6].pos.x = 12;
    player2->army[6].pos.y = 13;
    map[player2->army[6].pos.x][player2->army[6].pos.y].unit = &player2->army[6];

}