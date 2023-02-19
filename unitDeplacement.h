int moveUnit(cell** map, unit* unit){
    if (unit->speed > 0){
        SDL_Event move;
        SDL_WaitEvent(&move);
        switch(move.type){
            case SDL_KEYDOWN:
                switch(move.key.keysym.sym){
                    case SDLK_UP:
                        if(map[unit->pos.x][unit->pos.y - 1].type != '#' && map[unit->pos.x][unit->pos.y - 1].type != '^' && map[unit->pos.x][unit->pos.y - 1].unit == NULL){
                            if(unit->type == 3 && map[unit->pos.x][unit->pos.y - 1].type == 'F'){
                                break;
                            }
                            map[unit->pos.x][unit->pos.y].unit = NULL;
                            unit->pos.y -= 1;
                        };
                        break;
                    case SDLK_DOWN:
                        if(map[unit->pos.x][unit->pos.y + 1].type != '#' && map[unit->pos.x][unit->pos.y + 1].type != '^' && map[unit->pos.x][unit->pos.y + 1].unit == NULL){
                            if(unit->type == 3 && map[unit->pos.x][unit->pos.y - 1].type == 'F'){
                                break;
                            }
                            map[unit->pos.x][unit->pos.y].unit = NULL;
                            unit->pos.y += 1;
                        };
                        break;
                    case SDLK_LEFT:
                        if(map[unit->pos.x - 1][unit->pos.y].type != '#' && map[unit->pos.x - 1][unit->pos.y].type != '^' && map[unit->pos.x - 1][unit->pos.y].unit == NULL){
                            if(unit->type == 3 && map[unit->pos.x][unit->pos.y - 1].type == 'F'){
                                break;
                            }
                            map[unit->pos.x][unit->pos.y].unit = NULL;
                            unit->pos.x -= 1;
                        };
                        break;
                    case SDLK_RIGHT:
                        if(map[unit->pos.x + 1][unit->pos.y].type != '#' && map[unit->pos.x + 1][unit->pos.y].type != '^' && map[unit->pos.x + 1][unit->pos.y].unit == NULL){
                            if(unit->type == 3 && map[unit->pos.x][unit->pos.y - 1].type == 'F'){
                                break;
                            }
                            map[unit->pos.x][unit->pos.y].unit = NULL;
                            unit->pos.x += 1;
                        };
                        break;
                }
                map[unit->pos.x][unit->pos.y].unit = unit;
                break;
        }
        if(map[unit->pos.x][unit->pos.y].type == 'F' && unit->type == 2)
            unit->speed -= 2;
        else
            unit->speed -= 1;
    }
}
