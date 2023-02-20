void moveUnit(cell** map, unit* unit, SDL_Surface* window, cursor cursor, int turn){
    SDL_Event move;
    SDL_Rect screenPos;
    SDL_Rect oldPos;
    bool notMoved;
    while (unit->speed > 0){
        SDL_WaitEvent(&move);
        screenPos.x = unit->pos.x * 64;
        screenPos.y = unit->pos.y * 64;
        notMoved = true;
        switch(move.type){
            case SDL_KEYDOWN:
                switch(move.key.keysym.sym){
                    case SDLK_UP:
                        if(map[unit->pos.x][unit->pos.y - 1].type != '#' && map[unit->pos.x][unit->pos.y - 1].type != 'M' && map[unit->pos.x][unit->pos.y - 1].unit == NULL){
                            if(unit->type == 3 && map[unit->pos.x][unit->pos.y - 1].type == 'F'){
                                break;
                            }
                            map[unit->pos.x][unit->pos.y].unit = NULL;
                            unit->pos.y -= 1;
                            notMoved = false;
                            if(cursor.pos.y > 0)
                                cursor.pos.y -= 1;
                            
                        }
                        if((map[unit->pos.x][unit->pos.y].type == 'F' && unit->type == 2) && !notMoved)
                            unit->speed -= 2;
                        else if (!notMoved)
                            unit->speed -= 1;
                        break;
                    case SDLK_DOWN:
                        if(map[unit->pos.x][unit->pos.y + 1].type != '#' && map[unit->pos.x][unit->pos.y + 1].type != 'M' && map[unit->pos.x][unit->pos.y + 1].unit == NULL){
                            if(unit->type == 3 && map[unit->pos.x][unit->pos.y - 1].type == 'F'){
                                break;
                            }
                            map[unit->pos.x][unit->pos.y].unit = NULL;
                            unit->pos.y += 1;
                            notMoved = false;
                            if(cursor.pos.y < 15)
                                cursor.pos.y += 1;
                        }
                        if((map[unit->pos.x][unit->pos.y].type == 'F' && unit->type == 2) && !notMoved)
                            unit->speed -= 2;
                        else if (!notMoved)
                            unit->speed -= 1;
                        break;
                    case SDLK_LEFT:
                        if(map[unit->pos.x - 1][unit->pos.y].type != '#' && map[unit->pos.x - 1][unit->pos.y].type != 'M' && map[unit->pos.x - 1][unit->pos.y].unit == NULL){
                            if(unit->type == 3 && map[unit->pos.x][unit->pos.y - 1].type == 'F'){
                                break;
                            }
                            map[unit->pos.x][unit->pos.y].unit = NULL;
                            unit->pos.x -= 1;
                            notMoved = false;
                            if(cursor.pos.x > 0)
                                cursor.pos.x -= 1;
                        }
                        if((map[unit->pos.x][unit->pos.y].type == 'F' && unit->type == 2) && !notMoved)
                            unit->speed -= 2;
                        else if (!notMoved)
                            unit->speed -= 1;
                        break;
                    case SDLK_RIGHT:
                        if(map[unit->pos.x + 1][unit->pos.y].type != '#' && map[unit->pos.x + 1][unit->pos.y].type != 'M' && map[unit->pos.x + 1][unit->pos.y].unit == NULL){
                            if(unit->type == 3 && map[unit->pos.x][unit->pos.y - 1].type == 'F'){
                                break;
                            }
                            map[unit->pos.x][unit->pos.y].unit = NULL;
                            unit->pos.x += 1;
                            notMoved = false;
                            if(cursor.pos.x < 15)
                                cursor.pos.x += 1;
                        }
                        if((map[unit->pos.x][unit->pos.y].type == 'F' && unit->type == 2) && !notMoved)
                            unit->speed -= 2;
                        else if (!notMoved)
                            unit->speed -= 1;
                        break;
                     case SDLK_SPACE:
                        unit->speed = 0;
                        map[unit->pos.x][unit->pos.y].unit->hasMoved = true;
                        return;
                }
                map[unit->pos.x][unit->pos.y].unit = unit;
                SDL_Rect cursorPos;
                cursorPos.x = cursor.pos.x * 64;
                cursorPos.y = cursor.pos.y * 64;
                mapActualization(map, window, cursorPos, turn);


                /*oldPos.x = screenPos.x;
                oldPos.y = screenPos.y;
                if(map[oldPos.x / 64][oldPos.y / 64].type == '-'){
                    SDL_BlitSurface(grass_image, NULL, window, &oldPos);
                }
                else if(map[oldPos.x / 64][oldPos.y / 64].type == 'F'){
                    SDL_BlitSurface(forest_image, NULL, window, &oldPos);
                }
                map[unit->pos.x][unit->pos.y].unit = unit;
                screenPos.x = unit->pos.x * 64;
                screenPos.y = unit->pos.y * 64;
                SDL_BlitSurface(sprite, NULL, window, &screenPos);
                SDL_Flip(window);*/
        }
    }
    map[unit->pos.x][unit->pos.y].unit->hasMoved = true;
    return;
}
