void initPlacement(cell** map, player* player1, player* player2){
    player1->army[0].pos.x = 1;
    player1->army[0].pos.y = 1;;
    map[player1->army[0].pos.x][player1->army[0].pos.y].unit = &player1->army[0];

    player2->army[0].pos.x = 14;
    player2->army[0].pos.y = 14;
    map[player2->army[0].pos.x][player2->army[0].pos.y].unit =  &player2->army[0];
}