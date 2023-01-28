int isReachable(unit unit, char** map){
    //get unit's position
    int x = unit.pos.x;
    int y = unit.pos.y;

    //get unit's range
    int range = unit.range;

    //check if there is an enemy in range of the unit all around it
    for(int i = 0; i <= range; i++){
        if(map[x + i][y] == 'E' || map[x - i][y] == 'E' || map[x][y + i] == 'E' || map[x][y - i] == 'E'){
            printf("Enemy in range\n");
            return 1;
        }
    }

    //if range is 2 or more, check if there is an enemy in range of the unit diagonally
    if(range >= 2){
        for(int i = 0; i <= range; i++){
            if(map[x + i][y + i] == 'E' || map[x - i][y - i] == 'E' || map[x + i][y - i] == 'E' || map[x - i][y + i] == 'E'){
                printf("Enemy in range\n");
                return 1;
            }
        }
    }
    printf("No enemy in range\n");
    return 0;
}