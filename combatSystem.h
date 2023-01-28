void fight(unit attacker , unit defender){
    if (attacker.type == defender.weak)
        defender.hp -= attacker.atk * 2 - defender.def;
    else
        defender.hp -= attacker.atk - defender.def;

    if (defender.hp <= 0)
        defender.alive = 0;
}

int inRange(unit unit, cell** map){
    //get unit's position
    int x = unit.pos.x;
    int y = unit.pos.y;


    //check if there is an enemy in range
    for(int i = unit.pos.x - unit.range; i <= unit.pos.x + unit.range; i++){
            for(int j = unit.pos.y - unit.range; j <= unit.pos.y + unit.range; j++){
                if (i == x && j == y)
                    continue;
                if(map[i][j].unit != NULL && map[i][j].unit->team != unit.team && map[i][j].unit->alive == 1){
                    Beep(523, 100);
                    return 1;
            }
        }
    }
    return 0;
}

void displayRange(unit unit, cell** map){
    //get unit's position
    int x = unit.pos.x;
    int y = unit.pos.y;

    //get unit's range
    int range = unit.range;

    //display range
    for(int i = unit.pos.x - unit.range; i <= unit.pos.x + unit.range; i++){
            for(int j = unit.pos.y - unit.range; j <= unit.pos.y + unit.range; j++){
                if(map[i][j].symbol != '#' && map[i][j].symbol != 'A' && map[i][j].symbol != 'E' && map[i][j].symbol != 'H' && map[i][j].symbol != 'K' && map[i][j].symbol != 'S' && map[i][j].symbol != 'C'){
                    map[i][j].symbol = 'R' ;
                }
            }
    }
}