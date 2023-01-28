int moveUnit(cell** map, unit* unit){
        switch(getch()){
            case 'a':
                if(map[unit->pos.x][unit->pos.y - 1].symbol== ' ' || map[unit->pos.x][unit->pos.y - 1].symbol== 'R'){
                        map[unit->pos.x][unit->pos.y].symbol = ' ';
                        unit->pos.y -= 1;
                        map[unit->pos.x][unit->pos.y].symbol = unit->symbol;
                }
                break;
            case 'd':
                if(map[unit->pos.x][unit->pos.y + 1].symbol== ' ' || map[unit->pos.x][unit->pos.y + 1].symbol== 'R'){
                        map[unit->pos.x][unit->pos.y].symbol = ' ';
                        unit->pos.y += 1;
                        map[unit->pos.x][unit->pos.y].symbol = unit->symbol;
                }
                break;
            case 'w':
                if(map[unit->pos.x - 1][unit->pos.y].symbol == ' ' || map[unit->pos.x - 1][unit->pos.y].symbol == 'R'){
                        map[unit->pos.x][unit->pos.y].symbol = ' ';
                        unit->pos.x -= 1;
                        map[unit->pos.x][unit->pos.y].symbol = unit->symbol;
                }
                break;
            case 's':
                if(map[unit->pos.x + 1][unit->pos.y].symbol == ' ' || map[unit->pos.x + 1][unit->pos.y].symbol == 'R'){
                        map[unit->pos.x][unit->pos.y].symbol = ' ';
                        unit->pos.x += 1;
                        map[unit->pos.x][unit->pos.y].symbol = unit->symbol;
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
