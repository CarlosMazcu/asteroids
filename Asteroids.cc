#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define _USE_MATH_DEFINES

#include "esat\window.h"
#include "esat\draw.h"
#include "esat\input.h"
#include "esat\time.h"
#include "esat\sprite.h"
#include "esat\math.h"
#include "esat_extra\imgui.h"
#include "./resources/code/common.cc"
#include "./resources/code/FondoInterfaz.cc"
#include "./resources/code/Draw_asteroids.cc"
#include "./resources/code/ship2.cc"
#include "./resources/code/highscore.cc"
#include "./resources/code/save.cc"

void CheckFile()
{
    if ((regist = fopen("./Resources/files/registros", "rb+")) == NULL)
    {
        printf("Error, no existe fichero.\n");
        regist = fopen("./Resources/files/registros", "wb+");
    }
}

int NumberUsers(){
    fseek(regist, 0, SEEK_END);
    return ftell(regist)/kUserSize;
}

void SaveData(TUser *u)
{
    //  GUARDAR datos registro
    fwrite(&(u->id), sizeof(u->id), 1, regist);
    fwrite(u->nickname, 20 * sizeof(char), 1, regist);
    fwrite(u->password, 20 * sizeof(char), 1, regist);
    fwrite(u->name, 20 * sizeof(char), 1, regist);
    fwrite(u->surname, 20 * sizeof(char), 1, regist);
    fwrite(&(u->credits), sizeof(u->credits), 1, regist);
    fwrite((u->birthday + 0), sizeof(int), 1, regist);
    fwrite((u->birthday + 1), sizeof(int), 1, regist);
    fwrite((u->birthday + 2), sizeof(int), 1, regist);
    fwrite(u->country, 20 * sizeof(char), 1, regist);
    fwrite(u->province, 20 * sizeof(char), 1, regist);
    fwrite(u->mail, 50 * sizeof(char), 1, regist);

    printf("\n DATOS GUARDADOS CON EXITO.\n");
}

void ReadUserData(TUser *u)
{
    fread(&(u->id), sizeof(u->id), 1, regist);
    fread(u->nickname, 20 * sizeof(char), 1, regist);
    fread(u->password, 20 * sizeof(char), 1, regist);
    fread(u->name, 20 * sizeof(char), 1, regist);
    fread(u->surname, 20 * sizeof(char), 1, regist);
    fread(&(u->credits), sizeof(u->credits), 1, regist);
    fread((u->birthday + 0), sizeof(int), 1, regist);
    fread((u->birthday + 1), sizeof(int), 1, regist);
    fread((u->birthday + 2), sizeof(int), 1, regist);
    fread(u->country, 20 * sizeof(char), 1, regist);
    fread(u->province, 20 * sizeof(char), 1, regist);
    fread(u->mail, 50 * sizeof(char), 1, regist);
}

void AsignMemoryUser(TUser *u){
    u->birthday = (int *)calloc(3, sizeof(int));
    u->name = (char *)calloc(20, sizeof(char));
    u->nickname = (char *)calloc(20, sizeof(char));
    u->surname = (char *)calloc(20, sizeof(char));
    u->password = (char *)calloc(20, sizeof(char));
    u->repeatpassword = (char *)calloc(20, sizeof(char));
    u->province = (char *)calloc(20, sizeof(char));
    u->country = (char *)calloc(20, sizeof(char));
    u->mail = (char *)calloc(50, sizeof(char));
}

void InitMainMenu()
{
    
    AsignMemoryUser(&user);
    CheckFile();
    CheckSaveFile();
    /* printf("%d\n", NumberUsers()); */

    user.credits = 5;
    

    g_user = (char *)calloc(20, sizeof(char));
    g_password = (char *)calloc(20, sizeof(char));
    crt = (char *)calloc(24, sizeof(char));
    not_user = (char *)calloc(22, sizeof(char));

    *(not_user + 0) = 'U';
    *(not_user + 1) = 'S';
    *(not_user + 2) = 'U';
    *(not_user + 3) = 'A';
    *(not_user + 4) = 'R';
    *(not_user + 5) = 'I';
    *(not_user + 6) = 'O';
    *(not_user + 7) = ' ';
    *(not_user + 8) = 'N';
    *(not_user + 9) = 'O';
    *(not_user + 10) = ' ';
    *(not_user + 11) = 'E';
    *(not_user + 12) = 'N';
    *(not_user + 13) = 'C';
    *(not_user + 14) = 'O';
    *(not_user + 15) = 'N';
    *(not_user + 16) = 'T';
    *(not_user + 17) = 'R';
    *(not_user + 18) = 'A';
    *(not_user + 19) = 'D';
    *(not_user + 20) = 'O';
    *(not_user + 21) = '\0';

    
    InitFondo();
    InitPointsAsteroids();

    keys = esat::SpriteFromFile("./Resources/keyboard.png");
    arrows = esat::SubSprite(keys, 0, 0, 41, 13);
    spacebar = esat::SubSprite(keys, 0, 14, 41, 15);
    g_key = esat::SubSprite(keys, 0, 31, 19, 15);
    up_key = esat::SubSprite(keys, 0, 48, 19, 13);
    esat_logo = esat::SpriteFromFile("./Resources/r2.png");
    esat::DrawSetTextFont("./Resources/Bold.otf");


    *(crt + 0) = 'C';
    *(crt + 1) = 'R';
    *(crt + 2) = 'E';
    *(crt + 3) = 'D';
    *(crt + 4) = 'I';
    *(crt + 5) = 'T';
    *(crt + 6) = 'O';
    *(crt + 7) = 'S';
    *(crt + 8) = ' ';
    *(crt + 9) = ' ';
    *(crt + 10) = 'I';
    *(crt + 11) = 'N';
    *(crt + 12) = 'S';
    *(crt + 13) = 'U';
    *(crt + 14) = 'F';
    *(crt + 15) = 'I';
    *(crt + 16) = 'C';
    *(crt + 17) = 'I';
    *(crt + 18) = 'E';
    *(crt + 19) = 'N';
    *(crt + 20) = 'T';
    *(crt + 21) = 'E';
    *(crt + 22) = 'S';
    *(crt + 23) = '\0';
   

    swap = 0;
}

void CleanUser(TUser *u){
    free(u->birthday);
    u->birthday = nullptr;
    free(u->name);
    u->name = nullptr;
    free(u->surname);
    u->surname = nullptr;
    free(u->password);
    u->password = nullptr;
    free(u->repeatpassword);
    u->repeatpassword = nullptr;
    free(u->nickname);
    u->nickname = nullptr;
    free(u->province);
    u->province = nullptr;
    free(u->country);
    u->country = nullptr;
    free(u->mail);
    u->mail = nullptr;
}

void LoadUser(int aux_id){
    fseek(regist, aux_id * kUserSize, SEEK_SET);
    ReadUserData(&user);
}

int UpdateFile(TUser *us){
    if(us == nullptr){
        return kErrorCode_nullptr;
    }
    if(regist == nullptr){
        CheckFile();
    }
    fseek(regist,(us->id * kUserSize), SEEK_SET);
    SaveData(us);
    fclose(regist);
    CheckFile();
    return kErrorCode_ok;
}

void EnterAdminMode(){
    int n_users = NumberUsers();
    fseek(regist, 0, SEEK_SET);
    aux_user = (TUser *)malloc(n_users * kUserSize);
    for(int i = 0; i < n_users; i++){
        AsignMemoryUser(aux_user + i);
        ReadUserData(aux_user + i);
    }
}

void ExitAdminMode(){
    int n_users = NumberUsers();
    for(int i = 0; i < n_users; i++){
        CleanUser(aux_user + i);
    }
    free(aux_user);
    aux_user = nullptr;
}

void InitGame(){
    InitPlayer();
    InitFigures();
    InitEntities();
    //
    assert(user.surname != nullptr);
    cont_init_asteroids = 0;
    if(hardcore){
        level = 5;
    }else{
        level = 0;
    }
    asteroids_screen = 0;
    esat::DrawSetTextFont("./Resources/Bold.otf");
    ship_lives = esat::SpriteFromFile("./Resources/ship.png");
}

void AutoUser(){
    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Shift)){
        *(g_user + 0) = 'c';
        *(g_user + 1) = 'a';
        *(g_user + 2) = 'r';
        *(g_user + 3) = 'l';
        *(g_user + 4) = 'o';
        *(g_user + 5) = 's';
        *(g_user + 6) = 'm';
        *(g_user + 7) = 'a';
        *(g_user + 8) = 'z';
        *(g_user + 9) = 'c';
        *(g_user + 10) = 'u';
        *(g_user + 11) = '\0';


        *(g_password + 0) = '1';
        *(g_password + 1) = '2';
        *(g_password + 2) = '3';
        *(g_password + 3) = '4';
        *(g_password + 4) = '5';
        *(g_password + 5) = '6';
        *(g_password + 6) = '\0';
       /* swap = 1; */

    }
}

void AutoAdmin(){
        *(g_user + 0) = 'a';
        *(g_user + 1) = 'd';
        *(g_user + 2) = 'm';
        *(g_user + 3) = 'i';
        *(g_user + 4) = 'n';
        *(g_user + 5) = '\0';


        *(g_password + 0) = 'a';
        *(g_password + 1) = '1';
        *(g_password + 2) = '2';
        *(g_password + 3) = '3';
        *(g_password + 4) = '4';
        *(g_password + 5) = '5';
        *(g_password + 6) = '6';
        *(g_password + 7) = '\0';

}

void WindowManager(int n)
{
    switch (n)
    {
    case 0:
        config.welcome = true;
        config.login = false;
        config.signup = false;
        config.ctrls = false;
        config.crdts = false;
        config.usr = false;
        config.admin = false;
        config.admin_signup = false;
        config.edit_user_for_admin = false;
        config.game_over = false;
        break;
    case 1:
        config.welcome = false;
        config.login = true;
        config.signup = false;
        config.ctrls = false;
        config.crdts = false;
        config.usr = false;
        config.admin = false;
        config.admin_signup = false;
        config.edit_user_for_admin = false;
        config.game_over = false;
        break;
    case 2:
        config.welcome = false;
        config.login = false;
        config.signup = true;
        config.ctrls = false;
        config.crdts = false;
        config.usr = false;
        config.admin = false;
        config.admin_signup = false;
        config.edit_user_for_admin = false;
        config.game_over = false;
        break;
    case 3:
        config.welcome = false;
        config.login = false;
        config.signup = false;
        config.ctrls = true;
        config.crdts = false;
        config.usr = false;
        config.admin = false;
        config.admin_signup = false;
        config.edit_user_for_admin = false;
        config.game_over = false;
        break;
    case 4:
        config.welcome = false;
        config.login = false;
        config.signup = false;
        config.ctrls = false;
        config.crdts = true;
        config.usr = false;
        config.admin = false;
        config.admin_signup = false;
        config.game_over = false;
        config.edit_user_for_admin = false;
        break;
    case 5:
        config.welcome = false;
        config.login = false;
        config.signup = false;
        config.ctrls = false;
        config.crdts = false;
        config.usr = false;
        config.admin = true;
        config.admin_signup = false;
        config.game_over = false;
        config.edit_user_for_admin = false;
        break;
    case 6:
        config.welcome = false;
        config.login = false;
        config.signup = false;
        config.ctrls = false;
        config.crdts = false;
        config.usr = true;
        config.admin = false;
        config.admin_signup = false;
        config.edit_user_for_admin = false;
        config.game_over = false;
        break;
    case 7:
        config.welcome = false;
        config.login = false;
        config.signup = false;
        config.ctrls = false;
        config.crdts = false;
        config.usr = false;
        config.admin = false;
        config.admin_signup = true;
        config.game_over = false;
        config.edit_user_for_admin = false;
        break;
    case 8:
        config.welcome = false;
        config.login = false;
        config.signup = false;
        config.ctrls = false;
        config.crdts = false;
        config.usr = false;
        config.admin = false;
        config.admin_signup = false;
        config.edit_user_for_admin = true;
        config.game_over = false;
        
        break;
    case 9:
        config.welcome = false;
        config.login = false;
        config.signup = false;
        config.ctrls = false;
        config.crdts = false;
        config.usr = false;
        config.admin = false;
        config.admin_signup = false;
        config.edit_user_for_admin = false;
        config.game_over = true;

        break;
    
    default:
        break;
    }
}

void DeleteUser(int aux_id){
    int n_users = NumberUsers();
    fclose(regist);
    fopen("./Resources/files/registros", "wb+");
    for(int i = 0; i < n_users ; i++){
        if(i != aux_id){
            ((aux_user + i)->id) = (ftell(regist) / kUserSize); 
            SaveData(aux_user + i);
        }
    }
}

void UserWindow()
{
    ImGui::SetNextWindowSize(ImVec2(330, 400));
    ImGui::SetNextWindowPos(ImVec2(250, 200));
    ImGui::Begin(user.nickname, nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);
    ImGui::Spacing();
    ImGui::Text("Nickname: ");
    ImGui::SameLine();
    ImGui::Text(user.nickname);
    ImGui::Spacing();
    ImGui::Text("Name: ");
    ImGui::SameLine();
    ImGui::Text(user.name);
    ImGui::Spacing();
    ImGui::Text("Surname: ");
    ImGui::SameLine();
    ImGui::Text(user.surname);
    ImGui::Spacing();
    ImGui::Text("Mail: ");
    ImGui::SameLine();
    ImGui::Text(user.mail);
    ImGui::Spacing();
    ImGui::Text("Country: ");
    ImGui::SameLine();
    ImGui::Text(user.country);
    ImGui::Spacing();
    ImGui::Text("Province: ");
    ImGui::SameLine();
    ImGui::Text(user.province);
    ImGui::Spacing();
    ImGui::Text("Credits: ");
    ImGui::SameLine();
    ImGui::Text("%d", user.credits);
    ImGui::Spacing();
    ImGui::Separator();
    if (ImGui::Button("Play 1P"))
    {
        if(user.credits > 0){
            multiplayer = false;
            hardcore = false;
            user.credits--;
            UpdateFile(&user);
            swap = 1;
        }
    }
    ImGui::SameLine();
    if (ImGui::Button("Play 2P"))
    {
        if(user.credits > 0){
            multiplayer = true;
            hardcore = false;
            user.credits--;
            UpdateFile(&user);
            swap = 1;

        }

    }
    ImGui::SameLine();
    if (ImGui::Button("Hardcore 1P"))
    {
        if(user.credits > 0){
            multiplayer = false;
            hardcore = true;
            user.credits--;
            UpdateFile(&user);
            swap = 1;
        }
    }
    ImGui::SameLine();
    if (ImGui::Button("Hardcore 2P"))
    {
        if(user.credits > 0){
            multiplayer = true;
            hardcore = true;
            user.credits--;
            UpdateFile(&user);
            swap = 1;
        }
    }
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::Spacing();
    if (save_file != NULL)
    {
        ImGui::SameLine(0.0f, 90.0f);
        if (ImGui::Button("Load Game", ImVec2(100.0f, 20.0f)))
        {
            user.credits--;
            UpdateFile(&user);
            data_save = true;
            fclose(save_file);
            swap = 1;
        }
    }
    for(int i = 0; i < 38; i++){
        ImGui::Spacing();
    }

    ImGui::SameLine(0.0f, 90.0f);
    if (ImGui::Button("Return", ImVec2(100.0f, 20.0f)))
    {
        *(g_user + 0)= '\0';
        *(g_password + 0) = '\0';
        WindowManager(0);
    }
    if(user.credits <= 0){
        esat::DrawSetFillColor(255,10,10);
        esat::DrawSetTextSize(40.0f);
        esat::DrawText(170, 450, crt);
    }
    ImGui::End();
}

void WelcomeWindow()
{
    ImGui::SetNextWindowSize(ImVec2(300, 400));
    ImGui::SetNextWindowPos(ImVec2(250, 230));

    ImGui::Begin("WELCOME TO ASTEROIDS", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);

    ImGui::Spacing();
    ImGui::SameLine(0.0f, 90.0f);
    if (ImGui::Button("LogIn", ImVec2(100.0f, 20.0f)))
    {
        WindowManager(1);
    }
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::SameLine(0.0f, 90.0f);
    if (ImGui::Button("SingUp", ImVec2(100.0f, 20.0f)))
    {
        WindowManager(2);
    }
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::SameLine(0.0f, 90.0f);
    if (ImGui::Button("Controls", ImVec2(100.0f, 20.0f)))
    {
        WindowManager(3);
    }
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::SameLine(0.0f, 90.0f);
    if (ImGui::Button("Credits", ImVec2(100.0f, 20.0f)))
    {
        WindowManager(4);
    }
    for(int i = 0; i < 45; i++){
        ImGui::Spacing();
    }
    ImGui::SameLine(0.0f, 90.0f);

    if (ImGui::Button("Exit", ImVec2(100.0f, 20.0f)))
    {
        exit_game = true;
    }

    DrawAsteroid1(UpdateBase2(520, 239), knPoints_asteroid1);
    DrawAsteroid2(UpdateBase2(520, 267), knPoints_asteroid2);
    DrawAsteroid3(UpdateBase2(520, 295), knPoints_asteroid3);
    DrawAsteroid4(UpdateBase2(520, 327), knPoints_asteroid4);
    ImGui::End();
}

void GameOverWindow()
{
    ImGui::SetNextWindowSize(ImVec2(300, 300));
    ImGui::SetNextWindowPos(ImVec2(250, 220));

    ImGui::Begin("GAME OVER", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar| ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground);
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::SameLine(10.0f, 120.0f);
    ImGui::Text("GAME OVER");
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::SameLine(-25.0f, 90.0f);
    ImGui::Text("YOUR SHIP HAS BEEN DESTROYED");
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();    
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::SameLine(10.0f, 100.0f);
    if (ImGui::Button("Exit", ImVec2(100.0f, 20.0f)) || esat::IsSpecialKeyDown(esat::kSpecialKey_Backspace))
    {
        WindowManager(0);
    }

    ImGui::End();
    esat::DrawSprite(esat_logo, 400, 405);
}

void ResetUser(TUser *user1)
{
    *((user1->nickname) + 0) = '\0';
    *((user1->name) + 0) = '\0';
    *((user1->surname) + 0) = '\0';
    *((user1->password) + 0) = '\0';
    *((user1->repeatpassword) + 0) = '\0';
    *((user1->country) + 0) = '\0';
    *((user1->mail) + 0) = '\0';
    *((user1->province)) = '\0';
    *((user1->birthday) + 0) = 0;
    *((user1->birthday) + 1) = 0;
    *((user1->birthday) + 2) = 0;
}

bool UserExist(char *us, char *pass)
{
    fseek(regist, 0, SEEK_END);
    int size = ftell(regist);
    fseek(regist, 0, SEEK_SET);
    while (ftell(regist) < size)
    {
        ReadUserData(&user);
        if (strcmp(us, user.nickname) == 0 && strcmp(pass, user.password) == 0)
        {
            return true;
        }
    }
    return false;
}

void AdminWindow()
{
    ImGui::SetNextWindowSize(ImVec2(300,500));
    ImGui::SetNextWindowPos(ImVec2(250, 180));

    ImGui::Begin("ADMIN MODE", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground);
    
    int n_users = NumberUsers();
    for(int i = 0; i < n_users; i++){
        ImGui::RadioButton((aux_user + i)->nickname, &user_id_for_admin, (aux_user + i)->id);
        ImGui::SameLine();
        ImGui::Text("%s  %s  %d", (aux_user + i)->name,(aux_user + i)->surname,(aux_user + i)->credits);
    }
    printf("%d\n", user_id_for_admin);
    
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    if (ImGui::Button("Add User"))
    {
        ResetUser(&user);
        ExitAdminMode();
        WindowManager(7);
    }
    ImGui::SameLine();
    if(ImGui::Button("Edit User")){
        LoadUser(user_id_for_admin);
        ExitAdminMode();
        WindowManager(8);
    }
    
    ImGui::SameLine();
    if(ImGui::Button("Delete User")){
        DeleteUser(user_id_for_admin);
        ExitAdminMode();
        EnterAdminMode();
    }

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    if (ImGui::Button("Return")|| esat::IsSpecialKeyDown(esat::kSpecialKey_Backspace))
    {
        ExitAdminMode();
        WindowManager(0);
        *(g_user + 0) = '\0';
        *(g_password + 0) = '\0';
        user.credits = 5;
    }

    ImGui::End();
}

int ValidateLoginData(char *user, char *pass)
{
    if (strlen(user) <= 0)
    {
        return kErrorCode_Invalid_g_user;
    }
    if (strlen(pass) <= 0)
    {
        return kErrorCode_Invalid_g_password;
    }

    return kErrorCode_ok;
}

void LoginWindow()
{
    
    ImGui::SetNextWindowSize(ImVec2(320, 150));
    ImGui::SetNextWindowPos(ImVec2(250, 200));

    ImGui::Begin("LogIn", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground);
    ImGui::InputText("Nickname", g_user, 20, ImGuiInputTextFlags_CharsNoBlank);
    
    ImGui::Spacing();
    if (viewpass)
    {
        ImGui::InputText("Password", g_password, 20);
    }
    else
    {
        ImGui::InputText("Password", g_password, 20, ImGuiInputTextFlags_Password);
    }
    ImGui::SameLine();
    ImGui::Checkbox("", &viewpass);
    
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
    if (ImGui::Button("Submit") || esat::IsSpecialKeyDown(esat::kSpecialKey_Enter))
    {
        
        /* printf("%s  %d\n", g_user, strlen(g_user));
        printf("%s  %d\n", g_password, strlen(g_password)); */

        if (strcmp(g_user, "admin") == 0 && strcmp(g_password, "a123456") == 0)
        {
            dont_user = false;
            printf("admin mode\n");
            EnterAdminMode();
            // VENTANA ADMINISTRADOR
            WindowManager(5);
        }
        else if (UserExist(g_user, g_password))
        {
            dont_user = false;
            printf("Usuario encontrado\n");
            WindowManager(6);
        }
        else
        {
            dont_user = true;
            printf("Usuario no encontrado\n");
            int ErrorCode = ValidateLoginData(g_user, g_password);
            switch (ErrorCode)
            {
            case kErrorCode_Invalid_g_user:
                e_codes.wrongg_user = true;
                break;
            case kErrorCode_Invalid_g_password:
                e_codes.wrongg_password = true;
                break;
            case kErrorCode_ok:
                e_codes.wrongg_password = false;
                e_codes.wrongg_user = false;
                break;
            default:e_codes.wrongg_password = true;
                break;
            }
        }
    }
    ImGui::SameLine();
    if (ImGui::Button("Clear"))
    {
        *(g_user + 0) = '\0';
        *(g_password + 0) = '\0';
    }
    ImGui::SameLine();
    if (e_codes.wrongg_password == true)
    {
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "Error Wrong Password");
    }
    
    ImGui::Spacing();
    ImGui::Spacing();
    if (ImGui::Button("Return"))
    {
        WindowManager(0);
        *(g_user + 0) = '\0';
        *(g_password + 0) = '\0';
    }
    ImGui::SameLine();
    if (e_codes.wrongg_user == true)
    {
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "Error Wrong User");
    }
    /* AutoUser(); */
    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Alt)){
        AutoAdmin();
    }
    ImGui::End();
    if(dont_user == true){
        esat::DrawSetFillColor(255, 10, 10);
        esat::DrawSetTextSize(40.0f);
        esat::DrawText(190, 450, not_user);
    }
    
}

void PauseWindow(){
    ImGui::SetNextWindowSize(ImVec2(200, 160));
    ImGui::SetNextWindowPos(ImVec2(300, 200));

    ImGui::Begin("PAUSE", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);

    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::SameLine(0.0f, 45.0f);
    if (ImGui::Button("RETURN GAME", ImVec2(100.0f, 20.0f)))
    {
        pause = false;
    }
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::SameLine(0.0f, 45.0f);
    if (ImGui::Button("MAIN MENU", ImVec2(100.0f, 20.0f)))
    {
        WindowManager(0);
        swap = 3;
        pause = false;
    }
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::SameLine(0.0f, 45.0f);

    if(ImGui::Button("SAVE", ImVec2(100.0f, 20.0f))){
        SaveDataofGame();
    }
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::SameLine(0.0f, 45.0f);
    if (ImGui::Button("EXIT", ImVec2(100.0f, 20.0f)))
    {
        exit_game = true;
    }
    esat::DrawSprite(esat_logo, 390, 405);
    ImGui::End();
}

int ValidateSignUpData(TUser user)
{
    if (strlen(user.name) <= 0)
    {
        return kErrorCode_Invalid_Name;
    }
    if (*(user.birthday + 0) > 31 || *(user.birthday + 1) > 12 || *(user.birthday + 2) > 2022,
        *(user.birthday + 0) <= 0 || *(user.birthday + 1) <= 0 || *(user.birthday + 2) <= 0)
    {
        return kErrorCode_Invalid_Birthday;
    }
    if (strcmp(user.password, user.repeatpassword) != 0)
    {
        return kErrorCode_NotSamePassword;
    }
    if (strlen(user.surname) <= 0)
    {
        return kErrorCode_Invalid_Surname;
    }
    if (strlen(user.nickname) <= 0)
    {
        return kErrorCode_Invalid_NickName;
    }
    if (strlen(user.mail) <= 0)
    {
        return kErrorCode_Invalid_Mail;
    }
    if (strlen(user.country) <= 0)
    {
        return kErrorCode_Invalid_Country;
    }
    if (strlen(user.province) <= 0)
    {
        return kErrorCode_Invalid_Province;
    }
    if (strlen(user.password) <= 0)
    {
        return kErrorCode_Invalid_Password;
    }
    if (strlen(user.repeatpassword) <= 0)
    {
        return kErrorCode_Invalid_Password;
    }
    return kErrorCode_ok;
}

void SignUpWindow(int mode = 0)
{

    ImGui::SetNextWindowSize(ImVec2(500, 360));
    ImGui::SetNextWindowPos(ImVec2(150, 150));
    

    ImGui::Begin("SignUp", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground);
    ImGui::InputText("Name", user.name, 20, ImGuiInputTextFlags_CharsNoBlank);
    if (e_codes.wrongname == true)
    {
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "Error");
    }
    ImGui::Spacing();
    ImGui::InputText("Surname", user.surname, 20, ImGuiInputTextFlags_CharsNoBlank);
    if (e_codes.wrongsurname == true)
    {
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "Error");
    }
    ImGui::Spacing();
    ImGui::InputText("Nickname", user.nickname, 20, ImGuiInputTextFlags_CharsNoBlank);
    if (e_codes.wrongnickname == true)
    {
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "Error");
    }
    ImGui::Spacing();
    if (viewpass)
    {
        ImGui::InputText("Password", user.password, 20);
    }
    else
    {
        ImGui::InputText("Password", user.password, 20, ImGuiInputTextFlags_Password);
    }
    ImGui::SameLine();
    ImGui::Checkbox(" ", &viewpass);
    if (e_codes.wrongpassword == true)
    {
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "Error");
    }
    ImGui::Spacing();

    if(mode == 0){
        if (viewpass)
        {
            ImGui::InputText("Repeat Password", user.repeatpassword, 20);
        }
        else
        {
            ImGui::InputText("Repeat Password", user.repeatpassword, 20, ImGuiInputTextFlags_Password);
        }
        ImGui::SameLine();
        ImGui::Checkbox("", &viewpass);
        ImGui::Spacing();
    }
    else if (mode == 1 || mode == 2)
    {
        strcpy(user.repeatpassword, user.password);
    }

    ImGui::InputInt3("Birthday", user.birthday);
    if (e_codes.wrongbirthday == true)
    {
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "Error");
    }
    ImGui::Spacing();
    ImGui::InputText("E-mail", user.mail, 50, ImGuiInputTextFlags_CharsNoBlank);
    if (e_codes.wrongmail == true)
    {
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "Error");
    }
    ImGui::Spacing();
    ImGui::InputText("Province", user.province, 20, ImGuiInputTextFlags_CharsNoBlank);
    if (e_codes.wrongprovince == true)
    {
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "Error");
    }
    ImGui::Spacing();
    ImGui::InputText("Country", user.country, 20, ImGuiInputTextFlags_CharsNoBlank);
    if (e_codes.wrongcountry == true)
    {
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "Error");
    }
    ImGui::Spacing();
    if(mode == 1 || mode == 2){
        ImGui::InputInt("Credits", &user.credits);
    }
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
    if (ImGui::Button("Submit") || esat::IsSpecialKeyDown(esat::kSpecialKey_Enter))
    {
        int ErrorCode = ValidateSignUpData(user);
        switch (ErrorCode)
        {
        case kErrorCode_ok:
            
            if(mode != 2){
                fseek(regist, 0, SEEK_END);
                user.id = ftell(regist) / kUserSize;
            }else{
                fseek(regist, user.id * kUserSize, SEEK_SET);
            }

            SaveData(&user);
            ResetUser(&user);

            if(mode == 1 || mode == 2){
                EnterAdminMode();
                WindowManager(5);
            }
            if(mode == 0){
                WindowManager(0);
                user.credits = 5;
            }

            break;
        case kErrorCode_Invalid_Name:
            e_codes.wrongname = true;
            break;
        case kErrorCode_NotSamePassword:
            e_codes.wrongpassword = true;
            break;
        case kErrorCode_Invalid_Birthday:
            e_codes.wrongbirthday = true;
            break;
        case kErrorCode_Invalid_Surname:
            e_codes.wrongsurname = true;
            break;
        case kErrorCode_Invalid_NickName:
            e_codes.wrongnickname = true;
            break;
        case kErrorCode_Invalid_Password:
            e_codes.wrongpassword = true;
            break;
        case kErrorCode_Invalid_Province:
            e_codes.wrongprovince = true;
            break;
        case kErrorCode_Invalid_Country:
            e_codes.wrongcountry = true;
            break;
        case kErrorCode_Invalid_Mail:
            e_codes.wrongmail = true;
            break;
        default:
            break;
        }
    }
    ImGui::SameLine();
    if (ImGui::Button("Clear"))
    {
        ResetUser(&user);
    }
    ImGui::Spacing();
    ImGui::Spacing();
    if (ImGui::Button("Return"))
    {
        ResetUser(&user);
        if (mode == 1 || mode == 2)
        {
            EnterAdminMode();
            WindowManager(5);
        }
        if (mode == 0)
        {
            WindowManager(0);
        }
    }

    ImGui::End();
}

void ControlsWindow()
{
    ImGui::SetNextWindowSize(ImVec2(300, 250));
    ImGui::SetNextWindowPos(ImVec2(250, 200));

    ImGui::Begin("Controls", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground);
    ImGui::Spacing();
    ImGui::Spacing();

    ImGui::Text("Ship Direction");
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Text("Acceleration");
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Text("Shooting");
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Text("HyperSpace");
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
    if (ImGui::Button("Return") || esat::IsSpecialKeyDown(esat::kSpecialKey_Backspace))
    {
        WindowManager(0);
    }
    esat::DrawSprite(arrows, 400, 236);
    esat::DrawSprite(spacebar, 400, 300);
    esat::DrawSprite(g_key, 400, 335);
    esat::DrawSprite(up_key, 400, 270);

    ImGui::End();
}

void GameOver(){

    if (multiplayer){
        if ((player + 1)->lives <= 0)
        {
            WindowManager(9);
            swap = 3;

        }
    }
    if (!multiplayer)
    {
        if ((player + 0)->lives <= 0)
        {
            WindowManager(9);
            swap = 3;
        }
    }
}

void Game()
{
////////////////////////// MAIN DEL JUEGO////////////////////////// 
///////////LOCAL VARIABLES//////////
    esat::Vec2 random_pos;
    float random_angle;
    random_pos.x = rand()%800;
    random_pos.y = rand()%600;
    RotateFigure((*global_entities + 0));
    MoveShip((*global_entities + 0));

/////////////INPUT////////////// 
    if (esat::IsKeyDown('P'))
    {
        pause ? pause = false : pause = true;
    }

    if(pause == true){
        PauseWindow();
        for(int i = 0; i < kNEntities; i++){
            (((*(*(global_entities + i))).figure).color.r) = 100;
            (((*(*(global_entities + i))).figure).color.g) = 100;
            (((*(*(global_entities + i))).figure).color.b) = 100;
        }
    }else{
        for(int i = 0; i < kNEntities; i++){
            (((*(*(global_entities + i))).figure).color.r) = 255;
            (((*(*(global_entities + i))).figure).color.g) = 255;
            (((*(*(global_entities + i))).figure).color.b) = 255;
        }
    }

    if (pause == false)
    {
            if (esat::IsSpecialKeyDown(esat::kSpecialKey_Space) && ship.active == true && bool_hyperspace == false)
            {

                SpawnBullet({AddVec2(ship.figure.transform.pos, FloatMultVec2(ship.dir, 12.0f)), {0.0f, 0.0f}, {0.5f, 0.5f}, ship.figure.transform.rotate, 0.0f, {}});
            }
            /////////////////
            // Volver al menú

            if (esat::IsKeyDown('G') && ship.active == true)
            {
                HyperSpace(&(*global_entities + 0)->figure.transform.pos);
            }
            if(esat::IsKeyDown('S')){
                fclose(save_file);
            }

/////////////UPDATE////////////
            while (cont_init_asteroids < (level * 2) + 4)
            {
                random_angle = rand() % 6;
                SpawnAsteroids({{rand() % 2 ? (float)(rand() % 200) + kWindowWidth : ((float)(rand() % 200)) * -1,
                                 (float)(rand() % kWindowHeight)},
                                {0.0f, 0.0f},
                                kBigAsteroid,
                                random_angle,
                                0.0f,
                                {}});
                cont_init_asteroids++;
            }
            UpgradeLevel((player + current_player));

            for (int i = 2; i < (kNEntities - kParticulasPool); i++)
            {
                if ((*(*(global_entities + i))).active)
                {
                MoveEntities(&((*(*(global_entities + i)))));
                }
            }
            for (int i = 0; i < kParticulasPool; i++)
            {
                if (((*(particulas + i))).active)
                {
                MoveEntities(&((*(particulas + i))), 1);
                }
            }

            for (int i = 0; i < kNEntities; i++)
            {
                if ((*(*(global_entities + i))).active)
                {
                Edge(&((*(*(global_entities + i))).figure.transform.pos));
                TransformFunction(&((*(*(global_entities + i))).figure));
                }
            }
            Inmortallity(&ship, 2.5f);
            PowerUpLive();
            GameOver();


            // colision entre nave y asteroides
            CollideShipAsteroid(&ship, 1, game_asteroids, kAsteroidPool, player);

            // colision entre bala y asteroides
            CollideShootAsteroid(shoots, kShootPool, game_asteroids, kAsteroidPool);

            //colision entre nave y ovni
            CollideOvniShip(&ovni, &ship);

            //Colision Bala player y ovni
            CollideShootOvni(shoots, kShootPool, &ovni);

            //colision bala del ovni con la nave
            CollideShoot_of_Ovni_Ship((shoots + (kShootPool - 1)), &ship);

            //colision ovni asteroides
            CollideOvniAsteroids(&ovni, game_asteroids, kAsteroidPool);

            // despawn bullets
            for (int i = 0; i < kShootPool; i++)
            {
                ManageSpawnTimer((shoots + i), 1.5f, 1);
            }
            // despawn particulas
            for (int i = 0; i < kParticulasPool; i++)
            {
                ManageSpawnTimer((particulas + i), 2.0f, 1);
            }
            // respawn nave
            ManageSpawnTimer(&ship, 2.0f, 0);
            //Spawn ovni
            SpawnOvni();
            //Disparo Ovni
            SpawnOvniBullet({ovni.figure.transform.pos, {}, {0.5f, 0.5f}, 0.0f, 0.0f, {}});

    }

/////////////DRAW/////////////
    DrawUi();
    for (int i = 0; i < kNEntities; i++)
        {
            if((*(*(global_entities + i))).active){
                DrawFigure(((*(*(global_entities + i))).figure));
            }
        }
    //MANAGE LIVES



}

void CreditsWindow()
{
    ImGui::SetNextWindowSize(ImVec2(300, 300));
    ImGui::SetNextWindowPos(ImVec2(250, 180));

    ImGui::Begin("Credits", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground);
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::Text("Developed by Carlos Mazcuñán Blanes.");
    ImGui::Text("All rights reserved.©");
    ImGui::SameLine();
    ImGui::Text("        <3");
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::Text("Original Game:");
    ImGui::Text("Arcade Asteroids 1979 by Atari®");
    ImGui::Spacing();
    ImGui::Text("Made in: ESAT.");
    ImGui::Text("Academic end of course project.");
    ImGui::Spacing();
    ImGui::Text("Subject:");
    ImGui::Text("Metodología y Programación.");
    ImGui::Spacing();
    ImGui::Text("Teacher:");
    ImGui::Text("Federico Sanjuan.");
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
    if (ImGui::Button("Return") || esat::IsSpecialKeyDown(esat::kSpecialKey_Backspace))
    {
        WindowManager(0);
    }
    ImGui::End();
    esat::DrawSprite(esat_logo, 500, 365);
}

void GestionVentanas()
{
    if (config.welcome == true)
    {
        WelcomeWindow();
    }
    if (config.login == true)
    {
        LoginWindow();
    }
    if (config.signup == true)
    {
        SignUpWindow();
    }
    if (config.ctrls == true)
    {
        ControlsWindow();
    }
    if (config.crdts == true)
    {
        CreditsWindow();
    }
    if (config.usr == true)
    {
        UserWindow();
    }
    if (config.admin == true)
    {
        AdminWindow();
    }
    if(config.admin_signup == true){
        SignUpWindow(1);
    }
    if(config.edit_user_for_admin == true){
        SignUpWindow(2);
    }
    if(config.game_over == true){
        GameOverWindow();
    }

    Fondo();
}

void CleanMainMenu()
{
    free(g_password);
    g_password = nullptr;
    free(g_user);
    g_user = nullptr;
    free(not_user);
    not_user = nullptr;
    esat::SpriteRelease(white);
    esat::SpriteRelease(logo);
    CleanUpStars();
    
}

void CleanGame(){
    ReleaseFigures();
    CleanAsteroids();
    current_player = 0;
}

void Style(){
    ImVec4* colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_Text]                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_TextDisabled]           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg]               = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
    colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_PopupBg]                = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    colors[ImGuiCol_Border]                 = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
    colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg]                = ImVec4(0.76f, 0.07f, 0.96f, 0.28f);
    colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.69f, 0.40f, 0.71f, 0.45f);
    colors[ImGuiCol_FrameBgActive]          = ImVec4(0.77f, 0.25f, 0.64f, 0.40f);
    colors[ImGuiCol_TitleBg]                = ImVec4(0.32f, 0.31f, 0.32f, 0.60f);
    colors[ImGuiCol_TitleBgActive]          = ImVec4(0.32f, 0.32f, 0.32f, 0.60f);
    colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.32f, 0.31f, 0.32f, 0.60f);
    colors[ImGuiCol_MenuBarBg]              = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
    colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
    colors[ImGuiCol_CheckMark]              = ImVec4(0.51f, 0.93f, 0.56f, 1.00f);
    colors[ImGuiCol_SliderGrab]             = ImVec4(0.62f, 0.28f, 0.67f, 1.00f);
    colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.87f, 0.47f, 0.90f, 1.00f);
    colors[ImGuiCol_Button]                 = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_ButtonHovered]          = ImVec4(0.38f, 0.19f, 0.43f, 1.00f);
    colors[ImGuiCol_ButtonActive]           = ImVec4(0.57f, 0.39f, 0.62f, 1.00f);
    colors[ImGuiCol_Header]                 = ImVec4(0.02f, 0.02f, 0.02f, 0.00f);
    colors[ImGuiCol_HeaderHovered]          = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    colors[ImGuiCol_HeaderActive]           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_Separator]              = ImVec4(1.00f, 1.00f, 1.00f, 0.50f);
    colors[ImGuiCol_SeparatorHovered]       = ImVec4(1.00f, 1.00f, 1.00f, 0.78f);
    colors[ImGuiCol_SeparatorActive]        = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_ResizeGrip]             = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
    colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
    colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
    colors[ImGuiCol_Tab]                    = ImVec4(0.18f, 0.35f, 0.58f, 0.86f);
    colors[ImGuiCol_TabHovered]             = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    colors[ImGuiCol_TabActive]              = ImVec4(0.20f, 0.41f, 0.68f, 1.00f);
    colors[ImGuiCol_TabUnfocused]           = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
    colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
    colors[ImGuiCol_PlotLines]              = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    colors[ImGuiCol_PlotHistogram]          = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
    colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
    colors[ImGuiCol_TableBorderLight]       = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
    colors[ImGuiCol_TableRowBg]             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_TableRowBgAlt]          = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
    colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
    colors[ImGuiCol_DragDropTarget]         = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    colors[ImGuiCol_NavHighlight]           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
}

int esat::main(int argc, char **argv)
{
    srand(time(nullptr));
    double current_time = 0.0;
    double last_time = 0.0;
    double fps = 60.0;
    config.welcome = true;


    esat::WindowInit(kWindowWidth, kWindowHeight);
    esat::WindowSetMouseVisibility(true);
    InitMainMenu();
    CheckFile();
    CheckHighscoreFile();
    InitHighscore(&aux_hs);
    Style();
    ResetUser(&user);
    while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) &&
           esat::WindowIsOpened() && exit_game == false)
    {
        last_time = esat::Time();
        esat::DrawBegin();
        esat::DrawClear(0, 0, 0);
        switch (swap)
        {
        case 0:
        //Menú Principal y gestion de users
            GestionVentanas();
            //TODO quitar esto despues de documentar
            AutoUser();
            break;
        case 1:
        //Limpieza menú anterior e Init del gameplay
            CleanMainMenu();
            InitGame();
            if(data_save){
                ReadDataofGame();
            }
            swap = 10;
            break;
        case 10:
        //gameplay
            ShowHighScore();
            break;
        case 2:
        //gameplay
            Game();
            break;
        case 3:
        //Limpieza gameplay e init del menú principal y gestión de usuarios
            
            GetPlayerScore();
            UpdateFile(&user);
            
            CleanGame();
            
            InitMainMenu();
            
            GestionVentanas();
            ResetUser(&user);
            swap = 0;
            break;
        default:
            break;
        }
        
        esat::DrawEnd();
        esat::WindowFrame();
        g_last_frame = esat::Time();
        do
        {
            current_time = esat::Time();
        } while ((current_time - last_time) <= 1000.0 / fps);
    }
    fclose(regist);
    fclose(highscore_file);
    switch (swap)
    {
    case 0: CleanMainMenu();
        break;
    case 2: CleanGame();
        break;
    default:
        break;
    }
    
    esat::WindowDestroy();
    return 0;
}
