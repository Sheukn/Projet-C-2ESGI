void attack(unit attacker , unit target){
    if (attacker.type == target.weak)
        target.hp -= attacker.atk * 2 - target.def;
    else
        target.hp -= attacker.atk - target.def;

    if (target.hp <= 0)
        target.alive = 0;
}

int isTargetable(unit* attacker, unit* target){
    //check if there is an enemy in range
    int x = (target->pos.x - attacker->pos.x);
    int y = (target->pos.y - attacker->pos.y);
    double distance = sqrt(x*x + y*y);

    if(distance <= attacker->range)
        return 1;
    return 0;
}

void displayRange(unit* unit, cell** map, SDL_Surface* window){ 
    //display range
    SDL_Surface * attackRangeSquare = IMG_Load("./ressources/redsquare.png");
    SDL_Rect squarePos;
    for(int i = unit->pos.x - unit->range; i <= unit->pos.x + unit->range; i++){
            for(int j = unit->pos.y - unit->range; j <= unit->pos.y + unit->range; j++){
                double distance = sqrt((i-unit->pos.x)*(i-unit->pos.x) + (j-unit->pos.y)*(j-unit->pos.y));
                if(distance <= unit->range){
                    squarePos.x = i * 64;
                    squarePos.y = j * 64;
                    SDL_BlitSurface(attackRangeSquare, NULL, window, &squarePos);

                }
            }
    }
    SDL_FreeSurface(attackRangeSquare);
    SDL_Flip(window);
    return;
}


void resetSpeed(unit* unit){
    switch(unit->symbol){
        case 'K':
        case 'A':
            unit->speed = 3;
            break;
        
        case 'S':
            unit->speed = 4;
            break;

        case 'C':
            unit->speed = 1;
            break;
        
        case 'H':
            unit->speed = 5;
            break;
    }
}