#include <iostream>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "Partida.h"

using namespace std;

void fResultados(){

}

int main(){

    const int screenWidth = 1280;
    const int screenHeight = 720;

    cout << "Hello World" << endl;

    InitWindow(screenWidth, screenHeight, "Labocritterz - Um remake de Laboratz!");
    InitAudioDevice();
    SetTargetFPS(60);

    float PosicaoBotaoX = 490, PosicaoBotaoY = 420,Largura = 300, Altura = 80;
    float PosicaoBotao2X = 490, PosicaoBotao2Y = 575;
    float PosicaoBotao3X = 490, PosicaoBotao3Y = 495;
    bool Colisao, Fechar = false;

    Texture2D Fundo = LoadTexture("Imagens/Tela-de-Menu.png");
    Rectangle BotaoIniciarPartida = {PosicaoBotaoX,PosicaoBotaoY,Largura,Altura},BotaoFecharJogo = {PosicaoBotao2X,PosicaoBotao2Y,Largura,Altura},BotaoResultados = {PosicaoBotao3X,PosicaoBotao3Y,Largura,Altura};
    Vector2 PosicaoMouse;
    Music Musica1 = LoadMusicStream("Sons/sound_musicMenu_loop.mp3");
    PlayMusicStream(Musica1);
    float TimePlayed = 0;

    while(Fechar == false){
        UpdateMusicStream(Musica1);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            PosicaoMouse = GetMousePosition();
            Colisao = CheckCollisionPointRec(PosicaoMouse, BotaoIniciarPartida);
            if(Colisao){
                fPartida();
                StopMusicStream(Musica1);
                PlayMusicStream(Musica1);
            }
            Colisao = CheckCollisionPointRec(PosicaoMouse, BotaoFecharJogo);
            if(Colisao){
                Fechar = true;
            }
            Colisao = CheckCollisionPointRec(PosicaoMouse, BotaoResultados);
            if(Colisao){
                fResultados();
            }
        }
        if(WindowShouldClose() == true){
            Fechar = true;
        }

        BeginDrawing();
        DrawTexture(Fundo, 0, 0, WHITE);

        ClearBackground(RAYWHITE);

        EndDrawing();

        TimePlayed = GetMusicTimePlayed(Musica1)/GetMusicTimeLength(Musica1);
        if(TimePlayed > 1){
            TimePlayed = 1;
        }
    }
    UnloadMusicStream(Musica1);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}