void cellInformationActualization(SDL_Surface* window, SDL_Rect cursorPos, cell** map, int turn){

    TTF_Init();
    SDL_Surface * knight_blue_image = IMG_Load("./ressources/KnightBlue.png");
    SDL_Surface * knight_red_image = IMG_Load("./ressources/KnightRed.png");
    SDL_Surface * archer_blue_image = IMG_Load("./ressources/ArcherBlue.png");
    SDL_Surface * archer_grey_image = IMG_Load("./ressources/ArcherGrey.png");
    SDL_Surface * archer_red_image = IMG_Load("./ressources/ArcherRed.png");
    SDL_Surface * horsemen_blue_image = IMG_Load("./ressources/CavalierBlue.png");
    SDL_Surface * horsemen_grey_image = IMG_Load("./ressources/CavalierGrey.png");
    SDL_Surface * horsemen_red_image = IMG_Load("./ressources/CavalierRed.png");
    SDL_Surface * catapult_blue_image = IMG_Load("./ressources/CatapulteBlue.png");
    SDL_Surface * catapult_red_image = IMG_Load("./ressources/CatapulteRed.png");
    SDL_Surface * pikemen_blue_image = IMG_Load("./ressources/LancierBlue.png");
    SDL_Surface * pikemen_red_image = IMG_Load("./ressources/LancierRed.png");

    SDL_Surface * plain_paysage = IMG_Load("./ressources/PlainPaysage.jpg");
    SDL_Surface * ocean_paysage = IMG_Load("./ressources/OceanPaysage.png");
    SDL_Surface * forest_paysage = IMG_Load("./ressources/ForestPaysage.png");
    SDL_Surface * mountain_paysage = IMG_Load("./ressources/MountainPaysage.png");
    SDL_Surface * castle_paysage = IMG_Load("./ressources/CastlePaysage.png");



    SDL_Rect cadre;
    cadre.x = 1024;
    cadre.y = 0;
    cadre.w = 376;
    cadre.h = 1024;
    if (turn == 1){
        SDL_FillRect(window, &cadre, SDL_MapRGB(window->format, 0, 0, 196));
    }
    else{
        SDL_FillRect(window, &cadre, SDL_MapRGB(window->format, 196, 0, 0));
    }

    SDL_Rect rectangle;
    rectangle.x = 1030;
    rectangle.y = 6;
    rectangle.w = 364;
    rectangle.h = 1012;
    SDL_FillRect(window, &rectangle, SDL_MapRGB(window->format, 0, 0, 0));

    SDL_Rect paysage;
    paysage.x = 1036;
    paysage.y = 12;
    paysage.w = 352;
    paysage.h = 180;
    switch (map[(cursorPos.x)/64][(cursorPos.y)/64].type)
    {
    case ('-'):
        SDL_BlitSurface(plain_paysage, NULL, window, &paysage);
        break;
    case ('#'):
        SDL_BlitSurface(ocean_paysage, NULL, window, &paysage);
        break;
    case ('F'):
        SDL_BlitSurface(forest_paysage, NULL, window, &paysage);
        break;
    case ('M'):
        SDL_BlitSurface(mountain_paysage, NULL, window, &paysage);
        break;
    case ('Y'):
    case ('Z'):
        SDL_BlitSurface(castle_paysage, NULL, window, &paysage);
        break;
    }

    if(map[(cursorPos.x)/64][(cursorPos.y)/64].unit){
        TTF_Init();
        TTF_Font* fontUsed = TTF_OpenFont("./font/font.ttf", 30);
        SDL_Rect textRect;
        SDL_Color white = {255, 255, 255};
        SDL_Color blue = {0, 0, 196};
        SDL_Color red = {196, 0, 0};
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

        SDL_Rect unitRect;
        unitRect.x = 1150;
        unitRect.y = 300;
        unitRect.w = 64;
        unitRect.h = 64;

        switch (map[(cursorPos.x)/64][(cursorPos.y)/64].unit->type){
        case 0:
            if(map[(cursorPos.x)/64][(cursorPos.y)/64].unit->team == 1){
                message = TTF_RenderText_Solid(fontUsed, "Homme d'armes", blue);
                SDL_BlitSurface(knight_blue_image, NULL, window, &unitRect);
            }
            else{
                message = TTF_RenderText_Solid(fontUsed, "Homme d'armes", red);
                SDL_BlitSurface(knight_red_image, NULL, window, &unitRect);
            }
            break;
        case 1:
            if(map[(cursorPos.x)/64][(cursorPos.y)/64].unit->team == 1){
                message = TTF_RenderText_Solid(fontUsed, "Archer", blue);
                SDL_BlitSurface(archer_blue_image, NULL, window, &unitRect);
            }
            else{
                message = TTF_RenderText_Solid(fontUsed, "Archer", red);
                SDL_BlitSurface(archer_red_image, NULL, window, &unitRect);
            }
            break;
        case 2:
            if(map[(cursorPos.x)/64][(cursorPos.y)/64].unit->team == 1){
                message = TTF_RenderText_Solid(fontUsed, "Cavalier", blue);
                SDL_BlitSurface(horsemen_blue_image, NULL, window, &unitRect);
            }
            else{
                message = TTF_RenderText_Solid(fontUsed, "Cavalier", red);
                SDL_BlitSurface(horsemen_red_image, NULL, window, &unitRect);
            }
            break;

        case 3:
            if(map[(cursorPos.x)/64][(cursorPos.y)/64].unit->team == 1){
                message = TTF_RenderText_Solid(fontUsed, "Catapulte", blue);
                SDL_BlitSurface(catapult_blue_image, NULL, window, &unitRect);
            }
            else{
                message = TTF_RenderText_Solid(fontUsed, "Catapulte", red);
                SDL_BlitSurface(catapult_red_image, NULL, window, &unitRect);
            }
            break;
        
        case 4:
            if(map[(cursorPos.x)/64][(cursorPos.y)/64].unit->team == 1){
                message = TTF_RenderText_Solid(fontUsed, "Piquier", blue);
                SDL_BlitSurface(pikemen_blue_image, NULL, window, &unitRect);
            }
            else{
                message = TTF_RenderText_Solid(fontUsed, "Piquier", red);
                SDL_BlitSurface(pikemen_red_image, NULL, window, &unitRect);
            }
            
            break;
        }

        SDL_BlitSurface(message, NULL, window, &textRect);
        TTF_CloseFont(fontUsed);
        SDL_FreeSurface(message);
    }

    SDL_Flip(window);
    SDL_FreeSurface(knight_blue_image);
    SDL_FreeSurface(knight_red_image);
    SDL_FreeSurface(archer_blue_image);
    SDL_FreeSurface(archer_red_image);
    SDL_FreeSurface(horsemen_blue_image);
    SDL_FreeSurface(horsemen_red_image);
    SDL_FreeSurface(catapult_blue_image);
    SDL_FreeSurface(catapult_red_image);
    SDL_FreeSurface(pikemen_blue_image);
    SDL_FreeSurface(pikemen_red_image);
    SDL_FreeSurface(plain_paysage);
    SDL_FreeSurface(ocean_paysage);
    SDL_FreeSurface(forest_paysage);
    SDL_FreeSurface(mountain_paysage);
    return;



}
void mapActualization(cell** map, SDL_Surface* window, SDL_Rect cursorPos, int turn){
    SDL_Surface * grass_image = SDL_LoadBMP("./ressources/grass.bmp");
    SDL_Surface * ocean_image = SDL_LoadBMP("./ressources/ocean.bmp");
    SDL_Surface * mountain_image = IMG_Load("./ressources/mountain.png");
    SDL_Surface * forest_image = IMG_Load("./ressources/tree.png");
    SDL_Surface * castle_image = IMG_Load("./ressources/castle.png");
    SDL_Surface * knight_blue_image = IMG_Load("./ressources/KnightBlue.png");
    SDL_Surface * knight_grey_image = IMG_Load("./ressources/KnightGrey.png");
    SDL_Surface * knight_red_image = IMG_Load("./ressources/KnightRed.png");
    SDL_Surface * castle_blue_image = IMG_Load("./ressources/bluecastle.png");
    SDL_Surface * castle_red_image = IMG_Load("./ressources/redcastle.png");
    SDL_Surface * archer_blue_image = IMG_Load("./ressources/ArcherBlue.png");
    SDL_Surface * archer_grey_image = IMG_Load("./ressources/ArcherGrey.png");
    SDL_Surface * archer_red_image = IMG_Load("./ressources/ArcherRed.png");
    SDL_Surface * catapult_blue_image = IMG_Load("./ressources/CatapulteBlue.png");
    SDL_Surface * catapult_grey_image = IMG_Load("./ressources/CatapulteGrey.png");
    SDL_Surface * catapult_red_image = IMG_Load("./ressources/CatapulteRed.png");
    SDL_Surface * horsemen_blue_image = IMG_Load("./ressources/CavalierBlue.png");
    SDL_Surface * horsemen_grey_image = IMG_Load("./ressources/CavalierGrey.png");
    SDL_Surface * horsemen_red_image = IMG_Load("./ressources/CavalierRed.png");
    SDL_Surface * pikemen_blue_image = IMG_Load("./ressources/LancierBlue.png");
    SDL_Surface * pikemen_grey_image = IMG_Load("./ressources/LancierGrey.png");
    SDL_Surface * pikemen_red_image = IMG_Load("./ressources/LancierRed.png");
    SDL_Surface * cursor_image = IMG_Load("./ressources/cursor.png");
    SDL_Rect screenPos;
    for (int i = 0; i < 16; i++){
        for (int j = 0; j < 16; j++){

            screenPos.x = i * 64;
            screenPos.y = j * 64;
            if (map[i][j].type == '-')
                SDL_BlitSurface(grass_image, NULL, window, &screenPos);

            else if (map[i][j].type == '#')
                SDL_BlitSurface(ocean_image, NULL, window, &screenPos);

            else if (map[i][j].type == 'F')
                SDL_BlitSurface(forest_image, NULL, window, &screenPos);

            else if (map[i][j].type == 'M')
                SDL_BlitSurface(mountain_image, NULL, window, &screenPos);

            else if (map[i][j].type == 'Y')
                SDL_BlitSurface(castle_blue_image, NULL, window, &screenPos);

            else if (map[i][j].type == 'Z')
                SDL_BlitSurface(castle_red_image, NULL, window, &screenPos);

            if (map[i][j].unit)
            {
                switch (map[i][j].unit->type){
                case 0:
                if (map[i][j].unit->hasAttacked){
                    SDL_BlitSurface(knight_grey_image, NULL, window, &screenPos); 
                }
                else if(map[i][j].unit->team == 1){
                    SDL_BlitSurface(knight_blue_image, NULL, window, &screenPos);
                }
                else{
                    SDL_BlitSurface(knight_red_image, NULL, window, &screenPos);
                }
                break;


                case 1:
                if (map[i][j].unit->hasAttacked){
                    SDL_BlitSurface(archer_grey_image, NULL, window, &screenPos); 
                }
                else if(map[i][j].unit->team == 1){
                    SDL_BlitSurface(archer_blue_image, NULL, window, &screenPos);
                }
                else{
                    SDL_BlitSurface(archer_red_image, NULL, window, &screenPos);
                }
                break;

                case 2:
                if (map[i][j].unit->hasAttacked){
                    SDL_BlitSurface(horsemen_grey_image, NULL, window, &screenPos); 
                }
                else if(map[i][j].unit->team == 1){
                    SDL_BlitSurface(horsemen_blue_image, NULL, window, &screenPos);
                }
                else{
                    SDL_BlitSurface(horsemen_red_image, NULL, window, &screenPos);
                }
                break;

                case 3:
                    if (map[i][j].unit->hasAttacked){
                    SDL_BlitSurface(catapult_grey_image, NULL, window, &screenPos); 
                }
                else if(map[i][j].unit->team == 1){
                    SDL_BlitSurface(catapult_blue_image, NULL, window, &screenPos);
                }
                else{
                    SDL_BlitSurface(catapult_red_image, NULL, window, &screenPos);
                }
                break;
                case 4:
                    if (map[i][j].unit->hasAttacked){
                    SDL_BlitSurface(pikemen_grey_image, NULL, window, &screenPos); 
                }
                else if(map[i][j].unit->team == 1){
                    SDL_BlitSurface(pikemen_blue_image, NULL, window, &screenPos);
                }
                else{
                    SDL_BlitSurface(pikemen_red_image, NULL, window, &screenPos);
                }
                break;
                }
            }
        }
    }
    SDL_BlitSurface(cursor_image, NULL, window, &cursorPos);
    cellInformationActualization(window, cursorPos, map, turn);
    SDL_Flip(window);
    SDL_FreeSurface(grass_image);
    SDL_FreeSurface(ocean_image);
    SDL_FreeSurface(forest_image);
    SDL_FreeSurface(mountain_image);
    SDL_FreeSurface(castle_blue_image);
    SDL_FreeSurface(castle_red_image);
    SDL_FreeSurface(knight_blue_image);
    SDL_FreeSurface(knight_grey_image);
    SDL_FreeSurface(knight_red_image);
    SDL_FreeSurface(archer_grey_image);
    SDL_FreeSurface(archer_blue_image);
    SDL_FreeSurface(archer_red_image);
    SDL_FreeSurface(horsemen_grey_image);
    SDL_FreeSurface(horsemen_blue_image);
    SDL_FreeSurface(horsemen_red_image);
    SDL_FreeSurface(catapult_blue_image);
    SDL_FreeSurface(catapult_grey_image);
    SDL_FreeSurface(catapult_red_image);
    SDL_FreeSurface(pikemen_blue_image);
    SDL_FreeSurface(pikemen_grey_image);
    SDL_FreeSurface(pikemen_red_image);
    SDL_FreeSurface(cursor_image);
    return;
}

void victory(player* winner, SDL_Surface* window){
        TTF_Init();
        TTF_Font* fontUsed = TTF_OpenFont("./font/font.ttf", 30);
        SDL_Rect textRect;

        SDL_Color blue = {0, 0, 196};
        SDL_Color red = {196, 0, 0};

        textRect.x = 1100;
        textRect.y = 750;
        textRect.w = 300;
        textRect.h = 150;

        if(winner->id == 1){
            SDL_Surface * message = TTF_RenderText_Solid(fontUsed, "Blue wins", blue);
            SDL_BlitSurface(message, NULL, window, &textRect);
            //sleep(3);
        }
        else{
            SDL_Surface * message = TTF_RenderText_Solid(fontUsed, "Red wins", red);
            SDL_BlitSurface(message, NULL, window, &textRect);
            //sleep(3);
        }
        SDL_Flip(window);
        SDL_Delay(5000);
        SDL_FreeSurface(window);
        TTF_CloseFont(fontUsed);
        return;
    }
