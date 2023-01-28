int isReachable(unit unit, char** map){
    //get unit's position
    int x = unit.pos.x;
    int y = unit.pos.y;

    //get unit's range
    int range = unit.range;

    //check if there is an enemy in range
    for(int i = x - range; i <= x + range; i++){
        for(int j = y - range; j <= y + range; j++){
            if(map[i][j] == 'E'){
                printf("Enemy in range\n");
                return 1;
            }
        }
    }

    printf("No enemy in range\n");
    return 0;
}