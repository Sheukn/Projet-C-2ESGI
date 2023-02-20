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
                    //Beep(523, 100);
                    return 1;
            }
        }
    }
    return 0;
}

void displayRange(unit* unit, cell** map, SDL_Surface* window){ 
    //display range
    SDL_Surface * attackRangeSquare = IMG_Load("./ressources/redsquare.png");
    SDL_Rect squarePos;
    for(int i = unit->pos.x - unit->range; i <= unit->pos.x + unit->range; i++){
            for(int j = unit->pos.y - unit->range; j <= unit->pos.y + unit->range; j++){
                double distance = sqrt((i-unit->pos.x)*(i-unit->pos.x) + (j-unit->pos.y)*(j-unit->pos.y));
                if(distance < unit->range){
                    squarePos.x = i * 64;
                    squarePos.y = j * 64;
                    SDL_BlitSurface(attackRangeSquare, NULL, window, &squarePos);

                }
            }
    }
    SDL_Flip(window);
    return;
}