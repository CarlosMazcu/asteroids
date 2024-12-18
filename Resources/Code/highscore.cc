
int RankingScore(){
    int n;
    assert(highscore_file != nullptr);

    fseek(highscore_file, 0, SEEK_END);
    n = ftell(highscore_file)/kHighscoreSize;
    return n;
}


void ReadScore(THighscore *hs){
    fread(&hs->highscore, sizeof(int), 1, highscore_file);
    fread(hs->user, sizeof(char) * 64, 1, highscore_file);
}


void LoadScore(THighscore hs){
    fwrite(&hs.highscore, sizeof(int), 1, highscore_file);
    fwrite(hs.user, sizeof(char) * 64, 1, highscore_file);
}

void CheckHighscoreFile(){
    if ((highscore_file = fopen("./Resources/files/highscore", "rb+")) == NULL)
    {
        printf("Error, no existe fichero.\n");
        highscore_file = fopen("./highscore", "wb+");
    }
}


void InitHighscore(THighscore *hs){
    hs->highscore = 0;
    hs->user = (char*)calloc(64, sizeof(char));
}

//algoritmo de ordenación
void BubbleSort(THighscore *aux_hs, int n_elements){
    THighscore temp;
    InitHighscore(&temp);
    for(int i = 0; i < n_elements - 1; i++){
        for(int j = 0; j < n_elements - i - 1; j++){
            if(((aux_hs + j)->highscore) < ((aux_hs + (j + 1))->highscore)){
                temp.highscore = (aux_hs + j)->highscore;
                temp.user = (aux_hs + j)->user;

                (aux_hs + j)->highscore = ((aux_hs + (j + 1))->highscore);
                (aux_hs + j)->user = ((aux_hs + (j + 1))->user);

                ((aux_hs + (j + 1))->highscore) = temp.highscore;
                ((aux_hs + (j + 1))->user) = temp.user;
            }
        }
    }
    free((temp.user));
}



void SortHighScoreFile(){
    int n = RankingScore();
    THighscore *aux_highscore;
    aux_highscore = (THighscore*)calloc(n, kHighscoreSize);
    fseek(highscore_file, 0,SEEK_SET);
    for(int i = 0; i < n; i++){
        InitHighscore((aux_highscore + i));
        ReadScore((aux_highscore + i));
    }

    //printeo de debug
    for(int i = 0; i < n; i++){
        printf("%s     %d\n",(aux_highscore + i)->user, (aux_highscore + i)->highscore);
    }
    BubbleSort(aux_highscore, n);
    //suma de créditos
    for(int i = 0; i < 10; i++){
        if(strcmp((aux_highscore + i)->user, user.nickname) == 0){
            user.credits += 5;
        }
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%s     %d\n",(aux_highscore + i)->user, (aux_highscore + i)->highscore);
    }
    fclose(highscore_file);
    highscore_file = fopen("./Resources/files/highscore", "wb+");
    for(int i = 0; i < 10; i++){
        LoadScore(*(aux_highscore + i));
    }
    fclose(highscore_file);
    CheckHighscoreFile();
    free(aux_highscore);
}

int UpdateHighScoreFile(THighscore *hs){
    if(hs == nullptr){

        return kErrorCode_nullptr;
    }
    if(highscore_file == nullptr){
        CheckHighscoreFile();
    }
    fseek(highscore_file,0, SEEK_END);
    LoadScore(*hs);
    SortHighScoreFile();
    fclose(highscore_file);
    CheckHighscoreFile();
    return kErrorCode_ok;
}



void ShowHighScore(){
    ImGui::SetNextWindowSize(ImVec2(200, 200));
    ImGui::SetNextWindowPos(ImVec2(20,540));
    ImGui::Begin("Button", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove 
                                    | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar);
    if (ImGui::Button("PLAY", ImVec2(100.0f, 20.0f)))
    {
        swap = 2;
    }
    ImGui::SameLine();
    ImGui::End();
    if (esat::IsSpecialKeyDown(esat::kSpecialKey_Enter) ||
        esat::IsSpecialKeyDown(esat::kSpecialKey_Space))
    {
        swap = 2;
    }
    
    float x = 30.0f, y = 50.0f;
    if(highscore_file == nullptr){}
    int n = RankingScore();
    assert(highscore_file != nullptr);
    if(n == 0){
        return;
    }
    char *aux_string;
    aux_string = (char*)calloc(128, sizeof(char));
    fseek(highscore_file, 0, SEEK_SET);
    esat::DrawSetTextSize(35.0f);
    esat::DrawSetFillColor(255,255,255);
    

    for(int i = 0; i < n; i++){
        ReadScore(&aux_hs);
        sprintf_s(aux_string, 128, "%d/  %s   -   %d  Pts.", (i + 1), aux_hs.user, aux_hs.highscore);
        esat::DrawText(x, y + (50.0f * i), aux_string);
    }
    free(aux_string);
    aux_string = nullptr;
    /* esat::DrawSprite(esat_logo, 750,530); */
    int animation = 0;
    if(animation_cont > 30 && animation_cont < 60){animation = 1;}
    if(animation_cont > 60 && animation_cont < 90){animation = 2;}
    if(animation_cont > 90 && animation_cont < 120){animation = 3;}

    if(animation_cont >= 120){
        animation_cont = 0;
    }


    for(int i  = 0; i < animation; i++){
        esat::DrawSprite(ship_lives, (30 * i) + 160, 540);
    }
    if(multiplayer){
        for(int i  = 0; i < animation; i++){
        esat::DrawSprite(ship_lives, (30 * i) + 360, 540);
    }
    }
    animation_cont++;
}

void GetPlayerScore(){
    if(multiplayer){
        if((player + 0)->score >= (player + 1)->score){
            aux_hs.highscore = (player + 0)->score;
            sprintf_s(aux_hs.user, 64, "%s", user.nickname);
        }
        else
        {
            aux_hs.highscore = (player + 1)->score;
            sprintf_s(aux_hs.user, 64, "%s", user.nickname);
        }
    }else{
        aux_hs.highscore = (player + 0)->score;
        sprintf_s(aux_hs.user, 64, "%s", user.nickname);
    }
    
    UpdateHighScoreFile(&aux_hs);

}

void CleanHighScore(){
    
}