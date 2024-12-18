#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "esat\window.h"
#include "esat\draw.h"
#include "esat\input.h"
#include "esat\time.h"
#include "esat\math.h"
#include "esat_extra\imgui.h"

bool debug = false;
bool viewpass = false;
int credits = 5;
int *birthday;
const int kWindowX = 1200, kWindowY = 1000;
char *buffer1;
char *buffer2;

struct WindowSettings{
    bool welcome, reg;
};

WindowSettings config;

void WindowManager(int n){
    switch (n)
    {
    case 0:
        config.welcome = false;
        config.reg = true;
        break;
    case 1:
        config.welcome = true;
        config.reg = false;
        break;
    default:
        break;
    }
}

void testWindow(){
    ImGui::SetNextWindowSize(ImVec2(600,400));
    ImGui::SetNextWindowPos(ImVec2(100,100));

    ImGui::Begin("test", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    ImGui::Text("test escritura");

    ImGui::Separator();

    ImGui::InputText("name", buffer1, 20,ImGuiInputTextFlags_CharsNoBlank );
    ImGui::Spacing();
    if(viewpass){
        ImGui::InputText("surname", buffer2, 20);
    }else{
        ImGui::InputText("surname", buffer2, 20,ImGuiInputTextFlags_Password);
    }
    ImGui::SameLine();
    ImGui::Checkbox("checkbox", &viewpass);

    if(ImGui::TreeNodeEx("tree", ImGuiTreeNodeFlags_Framed)){
        ImGui::Text("hola");
        ImGui::TextColored(ImVec4(0.0f, 1.0f, 1.0f, 1.0f), "error");
        ImGui::InputInt("credits", &credits, 1, 10);
        ImGui::InputInt3("Birthday", birthday);

        ImGui::DragInt("drag", &credits, 1.0f, 0, 20);
        
        ImGui::TreePop();
    }
    if(ImGui::Button("boton")){
        printf("%d - %d - %d\n", birthday[0], birthday[1], birthday[2]);
        WindowManager(1);

    }
    ImGui::End();
}

void testWindow2(){
    ImGui::SetNextWindowSize(ImVec2(600,400));
    ImGui::SetNextWindowPos(ImVec2(100,100));

    ImGui::Begin("Welcome", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    ImGui::Text("ksdfjgvl");
    ImGui::Separator();

    ImGui::InputText("nombre", buffer1, 20,ImGuiInputTextFlags_CharsNoBlank );

    if(ImGui::Button("boton1")){
        WindowManager(0);
    }
    ImGui::End();
}



void GestionVentanas(){
    if(config.welcome == true){
            testWindow2();
    }else if(config.reg == true){
            testWindow();
        }
}


int esat::main(int argc, char **argv)
{
    srand(time(nullptr));
    double current_time = 0.0;
    double last_time = 0.0;
    double fps = 60.0;

    birthday = (int*)calloc(3, sizeof(int));
    buffer1 = (char*)calloc(20, sizeof(char));
    buffer2 = (char*)calloc(20, sizeof(char));
    config.welcome = true;
    config.reg = false;


    esat::WindowInit(kWindowX, kWindowY);
    esat::WindowSetMouseVisibility(true);

    while (!esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) &&
           esat::WindowIsOpened())
    {
        last_time = esat::Time();
        esat::DrawBegin();
        esat::DrawClear(0, 0, 0);

        if(esat::IsSpecialKeyDown(esat::kSpecialKey_Control)){
            debug ? debug = false : debug = true;
        }
        if(debug){
            ImGui::ShowDemoWindow();
        }

        GestionVentanas();

        esat::DrawEnd();
        esat::WindowFrame();

        do
        {
            current_time = esat::Time();
        } while ((current_time - last_time) <= 1000.0 / fps);
    }


    esat::WindowDestroy();
    return 0;
}
