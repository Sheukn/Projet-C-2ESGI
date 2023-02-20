void attack(unit* attacker , unit* target){
    if (attacker->type == target->weak)
        target->hp -= attacker->atk * 2 - target->def;
    else
        target->hp -= attacker->atk - target->def;

    if (target->hp <= 0)
        target->alive = 0;
}

int isTargetable(unit* attacker, unit* target){

    if(attacker->team == target->team){
        return 0;
    }

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
                if(i == unit->pos.x && j == unit->pos.y){
                    continue;
                }
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
            unit->hasMoved = false;
            unit->hasAttacked = false;
            break;
        
        case 'S':
            unit->speed = 4;
            unit->hasMoved = false;
            unit->hasAttacked = false;
            break;

        case 'C':
            unit->speed = 2;
            unit->hasMoved = false;
            unit->hasAttacked = false;
            break;
        
        case 'H':
            unit->speed = 5;
            unit->hasMoved = false;
            unit->hasAttacked = false;
            break;
    }
}

void attackEvent(unit* attacker, SDL_Surface* window, cell** map, cursor cursorTarget, int turn){

    SDL_Event selectTarget;
    cursorTarget.pos.x = attacker->pos.x;
    cursorTarget.pos.y = attacker->pos.y;
    //SDL_Surface * target_image = IMG_Load("./ressources/cursor.png");
    SDL_Rect squarePos;
    squarePos.x = cursorTarget.pos.x * 64;
    squarePos.y = cursorTarget.pos.y * 64;


        while (attacker->hasAttacked == false){
            displayRange(map[attacker->pos.x][attacker->pos.y].unit, map, window);
            SDL_WaitEvent(&selectTarget);
            switch (selectTarget.type){
                case SDL_KEYDOWN:
                    switch (selectTarget.key.keysym.sym){
                        case SDLK_DOWN:
                            if(cursorTarget.pos.y < 15)
                                cursorTarget.pos.y += 1;
                            break;
                        case SDLK_UP:
                            if(cursorTarget.pos.y > 0)
                                cursorTarget.pos.y -= 1;
                            break;
                        case SDLK_LEFT:
                            if(cursorTarget.pos.x > 0)
                                cursorTarget.pos.x -= 1;
                            break;
                        case SDLK_RIGHT:
                            if(cursorTarget.pos.x < 15)
                                cursorTarget.pos.x += 1;
                            break;
                        case SDLK_a:
                            if(cursorTarget.pos.x == attacker->pos.x && cursorTarget.pos.y == attacker->pos.y){
                                attacker->hasAttacked = true;
                                attacker->hasMoved = true;
                                return;
                            }
                            else if(map[cursorTarget.pos.x][cursorTarget.pos.y].unit){
                                if(isTargetable(attacker, map[cursorTarget.pos.x][cursorTarget.pos.y].unit)){
                                    attack(attacker, map[cursorTarget.pos.x][cursorTarget.pos.y].unit);
                                    attacker->hasAttacked = true;
                                    attacker->hasMoved = true;
                                    return;
                                }
                            }
                    }
            
            }
            squarePos.x = cursorTarget.pos.x * 64;
            squarePos.y = cursorTarget.pos.y * 64;
        mapActualization(map, window, squarePos, turn);
        }
    }