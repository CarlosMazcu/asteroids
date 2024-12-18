void CheckSaveFile(){
    if ((save_file = fopen("./Resources/files/savefile", "rb+")) == NULL)
    {
        printf("Error, no existe fichero.\n");
    }
}

void SaveDataofGame(){
    save_file = fopen("./Resources/files/savefile", "wb+");
    //level
    fwrite(&level, sizeof(int), 1, save_file);
    //bool modo juego
    fwrite(&multiplayer, sizeof(bool), 1, save_file);
    //bool modo juego
    fwrite(&hardcore, sizeof(bool), 1, save_file);
    //current player
    fwrite(&current_player, sizeof(int), 1, save_file);
    //player.points
    fwrite(&(player + 0)->score, sizeof(int), 1, save_file);
    //player.lives
    fwrite(&(player + 0)->lives, sizeof(int), 1, save_file);
    if(multiplayer){
        //player.points
        fwrite(&(player + 1)->score, sizeof(int), 1, save_file);
        //player.lives
        fwrite(&(player + 1)->lives, sizeof(int), 1, save_file);
    }
    fclose(save_file);

}

void ReadDataofGame(){
    save_file = fopen("./Resources/files/savefile", "rb+");
    //level
    fread(&level, sizeof(int), 1, save_file);
    //bool modo juego
    fread(&multiplayer, sizeof(bool), 1, save_file);
    //bool modo juego
    fread(&hardcore, sizeof(bool), 1, save_file);
    //current player
    fread(&current_player, sizeof(int), 1, save_file);
    //player.points
    fread(&(player + 0)->score, sizeof(int), 1, save_file);
    //player.lives
    fread(&(player + 0)->lives, sizeof(int), 1, save_file);
    if(multiplayer){
        //player.points
        fread(&(player + 1)->score, sizeof(int), 1, save_file);
        //player.lives
        fread(&(player + 1)->lives, sizeof(int), 1, save_file);
    }
    fclose(save_file);

}