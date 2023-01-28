int moveUnit(char** map, unit* unit){
        switch(getch()){
            case 'a':
                if(map[unit->pos.x][unit->pos.y - 1] == ' ' || map[unit->pos.x][unit->pos.y - 1] == 'R'){
                        map[unit->pos.x][unit->pos.y] = ' ';
                        unit->pos.y -= 1;
                        map[unit->pos.x][unit->pos.y] = unit->symbol;
                }
                break;
            case 'd':
                if(map[unit->pos.x][unit->pos.y + 1] == ' ' || map[unit->pos.x][unit->pos.y + 1] == 'R'){
                        map[unit->pos.x][unit->pos.y] = ' ';
                        unit->pos.y += 1;
                        map[unit->pos.x][unit->pos.y] = unit->symbol;
                }
                break;
            case 'w':
                if(map[unit->pos.x - 1][unit->pos.y] == ' ' || map[unit->pos.x - 1][unit->pos.y] == 'R'){
                        map[unit->pos.x][unit->pos.y] = ' ';
                        unit->pos.x -= 1;
                        map[unit->pos.x][unit->pos.y] = unit->symbol;
                }
                break;
            case 's':
                if(map[unit->pos.x + 1][unit->pos.y] == ' ' || map[unit->pos.x + 1][unit->pos.y] == 'R'){
                        map[unit->pos.x][unit->pos.y] = ' ';
                        unit->pos.x += 1;
                        map[unit->pos.x][unit->pos.y] = unit->symbol;
                    }
                break;

            case ' ':
                return 1;

            case 'q':
                return 2;
            
            case 'n':
                return 3;

        }
}
