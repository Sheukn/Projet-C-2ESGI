void cellInformationActualization(SDL_Surface* window, SDL_Rect cursorPos, cell** map){

    SDL_Rect cadre;
    cadre.x = 1024;
    cadre.y = 0;
    cadre.w = 376;
    cadre.h = 1024;
    SDL_FillRect(window, &cadre, SDL_MapRGB(window->format, 0, 0, 196));

    SDL_Rect rectangle;
    rectangle.x = 1030;
    rectangle.y = 6;
    rectangle.w = 364;
    rectangle.h = 1012;
    SDL_FillRect(window, &rectangle, SDL_MapRGB(window->format, 0, 0, 0));
    SDL_Flip(window);

}
void mapActualization(cell** map, SDL_Surface* window, SDL_Rect cursorPos){
    SDL_Surface * grass_image = SDL_LoadBMP("./ressources/grass.bmp");
    SDL_Surface * ocean_image = SDL_LoadBMP("./ressources/ocean.bmp");
    SDL_Surface * forest_image = SDL_LoadBMP("./ressources/forest.bmp");
    SDL_Surface * knight_image = IMG_Load("./ressources/knight.png");
    SDL_Surface * archer_image = IMG_Load("./ressources/archer.png");
    SDL_Surface * catapult_image = IMG_Load("./ressources/catapult.png");
    SDL_Surface * spearman_image = IMG_Load("./ressources/spearman.png");
    SDL_Surface * cursor_image = IMG_Load("./ressources/cursor.png");
    SDL_Rect screenPos;
    for (int i = 0; i < 16; i++){
        for (int j = 0; j < 16; j++){

            screenPos.x = i * 64;
            screenPos.y = j * 64;
            if (map[i][j].type == '-')
            {
                SDL_BlitSurface(grass_image, NULL, window, &screenPos);
            }
            else if (map[i][j].type == '#')
            {
                SDL_BlitSurface(ocean_image, NULL, window, &screenPos);
            }

            else if (map[i][j].type == 'F')
            {
                SDL_BlitSurface(forest_image, NULL, window, &screenPos);
            }
            if (map[i][j].unit)
            {
                if (map[i][j].unit->type == 0)
                {
                    SDL_BlitSurface(knight_image, NULL, window, &screenPos);
                }

                switch (map[i][j].unit->type){
                case 0:
                    SDL_BlitSurface(knight_image, NULL, window, &screenPos);
                    break;
                case 1:
                    SDL_BlitSurface(archer_image, NULL, window, &screenPos);
                    break;
                // case 2:
                //     SDL_BlitSurface(knight_image, NULL, window, &screenPos);
                //     break;
                case 3:
                    SDL_BlitSurface(catapult_image, NULL, window, &screenPos);
                    break;
                case 4:
                    SDL_BlitSurface(spearman_image, NULL, window, &screenPos);
                    break;
                }
            }
        }
    }
    SDL_BlitSurface(cursor_image, NULL, window, &cursorPos);
    cellInformationActualization(window, cursorPos, map);
    SDL_Flip(window);
    return;
}
