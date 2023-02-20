void loadMap(cell** map){
    FILE* mapFile;
    mapFile = fopen("map", "r");

    if(mapFile == NULL)
        printf("Error: map file not found");

    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            map[j][i].type = fgetc(mapFile);
            map[j][i].unit = NULL;
        }
        fgetc(mapFile);
    }

    fclose(mapFile);

}