void initPlacement(cell** map, player* player1, player* player2){
    /*for (int i = 0; i < 10; i++){
        player1->army[i].pos.x = 3 * (i + 1);
        player1->army[i].pos.y = 3;
        map[player1->army[i].pos.x][player1->army[i].pos.y] =  (cell){&player1->army[i] , player1->army[i].symbol};
    
        player2->army[i].pos.x = 50 - 3 * (i + 1);
        player2->army[i].pos.y = 47;
        map[player2->army[i].pos.x][player2->army[i].pos.y] = (cell){&player2->army[i] , player2->army[i].symbol};
    }
    */
    player1->army[0].pos.x = 1;
    player1->army[0].pos.y = 1;
    map[player1->army[0].pos.x][player1->army[0].pos.y] =  (cell){&player1->army[0] , player1->army[0].symbol};

    player2->army[0].pos.x = 14;
    player2->army[0].pos.y = 14;
    map[player2->army[0].pos.x][player2->army[0].pos.y] =  (cell){&player2->army[0] , player2->army[0].symbol};
}