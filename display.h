void cellInformationActualization(SDL_Surface* window, SDL_Rect cursorPos, cell** map){

    TTF_Init();
    SDL_Surface * grass_image = SDL_LoadBMP("./ressources/grass.bmp");
    SDL_Surface * ocean_image = SDL_LoadBMP("./ressources/ocean.bmp");
    SDL_Surface * forest_image = SDL_LoadBMP("./ressources/forest.bmp");
    SDL_Surface * knight_image = IMG_Load("./ressources/knight.png");
    SDL_Surface * archer_image = IMG_Load("./ressources/archer.png");
    SDL_Surface * catapult_image = IMG_Load("./ressources/catapult.png");
    SDL_Surface * spearman_image = IMG_Load("./ressources/spearman.png");
    SDL_Surface * cursor_image = IMG_Load("./ressources/cursor.png");

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

    if(map[(cursorPos.x)/64][(cursorPos.y)/64].unit){
        TTF_Init();
        TTF_Font* fontUsed = TTF_OpenFont("./font/font.ttf", 30);
        SDL_Rect textRect;
        SDL_Color white = {255, 255, 255};
        char classe[9];
        char vie[20] = "Vie : ";
        char attaque[20] = "Attaque : ";
        char defense[20] = "Defense : ";
        char deplacement[20] = "Deplacement : ";
        char buffer[100];

        sprintf(buffer, "%d", map[(cursorPos.x)/64][(cursorPos.y)/64].unit->hp);
        strcat(vie,buffer);
        SDL_Surface * message = TTF_RenderText_Solid(fontUsed, vie, white);
        textRect.x = 1100;
        textRect.y = 500;
        textRect.w = 300;
        textRect.h = 150;
        SDL_BlitSurface(message, NULL, window, &textRect);


        sprintf(buffer, "%d", map[(cursorPos.x)/64][(cursorPos.y)/64].unit->atk);
        strcat(attaque,buffer);
        message = TTF_RenderText_Solid(fontUsed, attaque, white);
        textRect.x = 1100;
        textRect.y = 550;
        textRect.w = 300;
        textRect.h = 150;
        SDL_BlitSurface(message, NULL, window, &textRect);


        sprintf(buffer, "%d", map[(cursorPos.x)/64][(cursorPos.y)/64].unit->def);
        strcat(defense,buffer);
        message = TTF_RenderText_Solid(fontUsed, defense, white);
        textRect.x = 1100;
        textRect.y = 600;
        textRect.w = 300;
        textRect.h = 150;
        SDL_BlitSurface(message, NULL, window, &textRect);


        sprintf(buffer, "%d", map[(cursorPos.x)/64][(cursorPos.y)/64].unit->speed);
        strcat(deplacement,buffer);
        message = TTF_RenderText_Solid(fontUsed, deplacement, white);
        textRect.x = 1100;
        textRect.y = 650;
        textRect.w = 300;
        textRect.h = 150;


        SDL_BlitSurface(message, NULL, window, &textRect);

        textRect.x = 1100;
        textRect.y = 400;
        textRect.w = 300;
        textRect.h = 150;
        if(map[(cursorPos.x)/64][(cursorPos.y)/64].unit->type == 0){
            message = TTF_RenderText_Solid(fontUsed, "Chevalier", white);

            SDL_BlitSurface(message, NULL, window, &textRect);


            SDL_Rect unitRect;
            unitRect.x = 1150;
            unitRect.y = 300;
            unitRect.w = 64;
            unitRect.h = 64;

            SDL_BlitSurface(knight_image, NULL, window, &unitRect);
            TTF_CloseFont(fontUsed);
            SDL_FreeSurface(message);
        }

    }

    SDL_Flip(window);
    SDL_FreeSurface(grass_image);
    SDL_FreeSurface(ocean_image);
    SDL_FreeSurface(forest_image);
    SDL_FreeSurface(knight_image);
    SDL_FreeSurface(archer_image);
    SDL_FreeSurface(catapult_image);
    SDL_FreeSurface(spearman_image);
    SDL_FreeSurface(cursor_image);
    return;



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
    SDL_FreeSurface(grass_image);
    SDL_FreeSurface(ocean_image);
    SDL_FreeSurface(forest_image);
    SDL_FreeSurface(knight_image);
    SDL_FreeSurface(archer_image);
    SDL_FreeSurface(catapult_image);
    SDL_FreeSurface(spearman_image);
    SDL_FreeSurface(cursor_image);
    return;
}
