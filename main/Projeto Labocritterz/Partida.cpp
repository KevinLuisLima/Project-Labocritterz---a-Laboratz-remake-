#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "Partida.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int fPartida(void){
    float PosicaoParado[12][2],PosicaoEmMovimento[12][2],Largura = 164, Altura = 164,PosicaoTabuleiro[9][2],TravaDoTabuleiro[12][2];
    int TestesDoTabuleiro[9][4],X = 0,Y = 0,TravaCarta[12], CartasDoJogador1[12],CartasDoJogador2[12],NumerosDasCartas[12][4],CasaCheia[9],CartasNoTabuleiro[9];
    bool Colisao = false;
    //seta as posições iniciais (o if aqui é só para eu poder scrolar mais rápido o código)//
    if(X == 0){
        PosicaoParado[0][0] = 41;
        PosicaoParado[0][1] = 185;
        PosicaoParado[1][0] = 41;
        PosicaoParado[1][1] = 352;
        PosicaoParado[2][0] = 41;
        PosicaoParado[2][1] = 519;

        PosicaoParado[3][0] = 209;
        PosicaoParado[3][1] = 185;
        PosicaoParado[4][0] = 209;
        PosicaoParado[4][1] = 352;
        PosicaoParado[5][0] = 209;
        PosicaoParado[5][1] = 519;

        PosicaoParado[6][0] = 907;
        PosicaoParado[6][1] = 185;
        PosicaoParado[7][0] = 907;
        PosicaoParado[7][1] = 352;
        PosicaoParado[8][0] = 907;
        PosicaoParado[8][1] = 519;

        PosicaoParado[9][0] = 911+164;
        PosicaoParado[9][1] = 185;
        PosicaoParado[10][0] = 911+164;
        PosicaoParado[10][1] = 352;
        PosicaoParado[11][0] = 911+164;
        PosicaoParado[11][1] = 519;

        //seta as posições do tabuleiro//
        PosicaoTabuleiro[0][0] = 391;
        PosicaoTabuleiro[0][1] = 185;
        PosicaoTabuleiro[1][0] = 559;
        PosicaoTabuleiro[1][1] = 185;
        PosicaoTabuleiro[2][0] = 726;
        PosicaoTabuleiro[2][1] = 185;

        PosicaoTabuleiro[3][0] = 391;
        PosicaoTabuleiro[3][1] = 352;
        PosicaoTabuleiro[4][0] = 559;
        PosicaoTabuleiro[4][1] = 352;
        PosicaoTabuleiro[5][0] = 726;
        PosicaoTabuleiro[5][1] = 352;

        PosicaoTabuleiro[6][0] = 391;
        PosicaoTabuleiro[6][1] = 519;
        PosicaoTabuleiro[7][0] = 559;
        PosicaoTabuleiro[7][1] = 519;
        PosicaoTabuleiro[8][0] = 726;
        PosicaoTabuleiro[8][1] = 519;

        //seta os números que cada carta tem//
        NumerosDasCartas[0][0] = 1;
        NumerosDasCartas[0][1] = 5;
        NumerosDasCartas[0][2] = 4;
        NumerosDasCartas[0][3] = 0;

        NumerosDasCartas[1][0] = 0;
        NumerosDasCartas[1][1] = 6;
        NumerosDasCartas[1][2] = 2;
        NumerosDasCartas[1][3] = 0;

        NumerosDasCartas[2][0] = 3;
        NumerosDasCartas[2][1] = 3;
        NumerosDasCartas[2][2] = 4;
        NumerosDasCartas[2][3] = 7;

        NumerosDasCartas[3][0] = 5;
        NumerosDasCartas[3][1] = 8;
        NumerosDasCartas[3][2] = 6;
        NumerosDasCartas[3][3] = 0;

        NumerosDasCartas[4][0] = 2;
        NumerosDasCartas[4][1] = 2;
        NumerosDasCartas[4][2] = 3;
        NumerosDasCartas[4][3] = 5;

        NumerosDasCartas[5][0] = 5;
        NumerosDasCartas[5][1] = 9;
        NumerosDasCartas[5][2] = 1;
        NumerosDasCartas[5][3] = 0;

        NumerosDasCartas[6][0] = 0;
        NumerosDasCartas[6][1] = 0;
        NumerosDasCartas[6][2] = 0;
        NumerosDasCartas[6][3] = 0;

        NumerosDasCartas[7][0] = 1;
        NumerosDasCartas[7][1] = 6;
        NumerosDasCartas[7][2] = 2;
        NumerosDasCartas[7][3] = 7;

        NumerosDasCartas[8][0] = 0;
        NumerosDasCartas[8][1] = 10;
        NumerosDasCartas[8][2] = 6;
        NumerosDasCartas[8][3] = 3;

        NumerosDasCartas[9][0] = 7;
        NumerosDasCartas[9][1] = 3;
        NumerosDasCartas[9][2] = 2;
        NumerosDasCartas[9][3] = 5;

        NumerosDasCartas[10][0] = 4;
        NumerosDasCartas[10][1] = 2;
        NumerosDasCartas[10][2] = 7;
        NumerosDasCartas[10][3] = 0;

        NumerosDasCartas[11][0] = 6;
        NumerosDasCartas[11][1] = 0;
        NumerosDasCartas[11][2] = 4;
        NumerosDasCartas[11][3] = 1;
    }

    //Inicializa a lista CasaCheia//
    while(X != 9){
        CasaCheia[X] = 0;
        X += 1;
    }X = 0;

    //Inicializa a lista TravaDoTabuleiro//
    while(X != 12){
        TravaDoTabuleiro[X][Y] = 0;
        if (Y == 1){
            X += 1;
            Y = -1;
        }
        Y += 1;
    }X = 0; Y = 0;
    
    //Inicializa as listas CartasDoJogador//
    while(X != 12){
        if(X < 6){
            CartasDoJogador1[X] = 1;
            CartasDoJogador2[X] = 0;
        }
        if(X >= 6){
            CartasDoJogador1[X] = 0;
            CartasDoJogador2[X] = 1;
        }
        X += 1;
    }X = 0;

    //Inicializa a lista TestesDoTabuleiro//
    while(X != 9){
        TestesDoTabuleiro[X][Y] = 99;
        if(Y == 3){
            X += 1;
            Y = -1;
        }
        Y += 1;
    }X = 0; Y = 0;

    while(X != 12){
        TravaCarta[X] = 0;
        X += 1;
    }X = 0;
    // Coloca as imagens em seus locais de origem//
    while(X != 12){
        PosicaoEmMovimento[X][Y] = PosicaoParado[X][Y];
        if(Y == 1){
            X += 1;
            Y = -1;
        }
        Y += 1;
    }X = 0; Y = 0;

    //Inicializa a lista CartasNoTabuleiro//
    while(X != 9){
        CartasNoTabuleiro[X] = 0;
        X += 1;
    }X = 0;

    Texture2D Fundo = LoadTexture("Imagens/Tela-de-Batalha.png");
    //Texturas das bases//
    Texture2D ImagensBase[12],Imagem1Base = LoadTexture("Imagens/Cartas/Base.png"),Imagem2Base = LoadTexture("Imagens/Cartas/Base.png"),Imagem3Base = LoadTexture("Imagens/Cartas/Base.png"),Imagem4Base = LoadTexture("Imagens/Cartas/Base.png"),Imagem5Base = LoadTexture("Imagens/Cartas/Base.png"),Imagem6Base = LoadTexture("Imagens/Cartas/Base.png"),Imagem7Base = LoadTexture("Imagens/Cartas/Base.png"),Imagem8Base = LoadTexture("Imagens/Cartas/Base.png"),Imagem9Base = LoadTexture("Imagens/Cartas/Base.png"),Imagem10Base = LoadTexture("Imagens/Cartas/Base.png"),Imagem11Base = LoadTexture("Imagens/Cartas/Base.png"),Imagem12Base = LoadTexture("Imagens/Cartas/Base.png");
    //Texturas dos bichos//
    Texture2D ImagensBichos[12],Imagem1Bicho = LoadTexture("Imagens/Cartas/Carta-Arara-Azul.png"),Imagem2Bicho = LoadTexture("Imagens/Cartas/Carta-Boto-Cor-de-Rosa.png"),Imagem3Bicho = LoadTexture("Imagens/Cartas/Carta-Capivara.png"),Imagem4Bicho = LoadTexture("Imagens/Cartas/Carta-Carcara.png"),Imagem5Bicho = LoadTexture("Imagens/Cartas/Carta-Cobra-Coral.png"),Imagem6Bicho = LoadTexture("Imagens/Cartas/Carta-Gamba.png"),Imagem7Bicho = LoadTexture("Imagens/Cartas/Carta-Logo-Guarana.png"),Imagem8Bicho = LoadTexture("Imagens/Cartas/Carta-MLD.png"),Imagem9Bicho = LoadTexture("Imagens/Cartas/Carta-Onca.png"),Imagem10Bicho = LoadTexture("Imagens/Cartas/Carta-Preguica.png"),Imagem11Bicho = LoadTexture("Imagens/Cartas/Carta-Sagui.png"),Imagem12Bicho = LoadTexture("Imagens/Cartas/Carta-Sapo-Cururu.png");
    //Posições das imagens paradas//
    Rectangle PosicoesParadas[12],PosicaoImagemParada1 = {PosicaoParado[0][0],PosicaoParado[0][1],Largura,Altura},PosicaoImagemParada2 = {PosicaoParado[1][0],PosicaoParado[1][1],Largura,Altura},PosicaoImagemParada3 = {PosicaoParado[2][0],PosicaoParado[2][1],Largura,Altura},PosicaoImagemParada4 = {PosicaoParado[3][0],PosicaoParado[3][1],Largura,Altura},PosicaoImagemParada5 = {PosicaoParado[4][0],PosicaoParado[4][1],Largura,Altura},PosicaoImagemParada6 = {PosicaoParado[5][0],PosicaoParado[5][1],Largura,Altura},PosicaoImagemParada7 = {PosicaoParado[6][0],PosicaoParado[6][1],Largura,Altura},PosicaoImagemParada8 = {PosicaoParado[7][0],PosicaoParado[7][1],Largura,Altura},PosicaoImagemParada9 = {PosicaoParado[8][0],PosicaoParado[8][1],Largura,Altura},PosicaoImagemParada10 = {PosicaoParado[9][0],PosicaoParado[9][1],Largura,Altura},PosicaoImagemParada11 = {PosicaoParado[10][0],PosicaoParado[10][1],Largura,Altura},PosicaoImagemParada12 = {PosicaoParado[11][0],PosicaoParado[11][1],Largura,Altura};
    //Posições das imagens paradas no tabuleiro//
    Rectangle PosicoesTabuleiro[12], PosicaoTabuleiro1 = {PosicaoTabuleiro[0][0],PosicaoTabuleiro[0][1],Largura,Altura},PosicaoTabuleiro2 = {PosicaoTabuleiro[1][0],PosicaoTabuleiro[1][1],Largura,Altura},PosicaoTabuleiro3 = {PosicaoTabuleiro[2][0],PosicaoTabuleiro[2][1],Largura,Altura},PosicaoTabuleiro4 = {PosicaoTabuleiro[3][0],PosicaoTabuleiro[3][1],Largura,Altura},PosicaoTabuleiro5 = {PosicaoTabuleiro[4][0],PosicaoTabuleiro[4][1],Largura,Altura},PosicaoTabuleiro6 = {PosicaoTabuleiro[5][0],PosicaoTabuleiro[5][1],Largura,Altura},PosicaoTabuleiro7 = {PosicaoTabuleiro[6][0],PosicaoTabuleiro[6][1],Largura,Altura},PosicaoTabuleiro8 = {PosicaoTabuleiro[7][0],PosicaoTabuleiro[7][1],Largura,Altura},PosicaoTabuleiro9 = {PosicaoTabuleiro[8][0],PosicaoTabuleiro[8][1],Largura,Altura};
    //Carrega a música//
    Music Musica = LoadMusicStream("Sons/sound_musicGame_loop.mp3");
    PlayMusicStream(Musica);
    float TimePlayed = 0;

    //Coloca numa única lista todas as Posições iniciais das cartas para facilitar na escrita do código//
    while(X != 12){
        if(X == 0){
            PosicoesParadas[X] = PosicaoImagemParada1;
        }
        if(X == 1){
            PosicoesParadas[X] = PosicaoImagemParada2;
        }
        if(X == 2){
            PosicoesParadas[X] = PosicaoImagemParada3;
        }
        if(X == 3){
            PosicoesParadas[X] = PosicaoImagemParada4;
        }
        if(X == 4){
            PosicoesParadas[X] = PosicaoImagemParada5;
        }
        if(X == 5){
            PosicoesParadas[X] = PosicaoImagemParada6;
        }
        if(X == 6){
            PosicoesParadas[X] = PosicaoImagemParada7;
        }
        if(X == 7){
            PosicoesParadas[X] = PosicaoImagemParada8;
        }
        if(X == 8){
            PosicoesParadas[X] = PosicaoImagemParada9;
        }
        if(X == 9){
            PosicoesParadas[X] = PosicaoImagemParada10;
        }
        if(X == 10){
            PosicoesParadas[X] = PosicaoImagemParada11;
        }
        if(X == 11){
            PosicoesParadas[X] = PosicaoImagemParada12;
        }
        X += 1;
    }X = 0;
    
    //Coloca numa única lista todas as Posições do tabuleiro para facilitar na escrita do código//
    while(X != 12){
        if(X == 0){
            PosicoesTabuleiro[X] = PosicaoTabuleiro1;
        }
        if(X == 1){
            PosicoesTabuleiro[X] = PosicaoTabuleiro2;
        }
        if(X == 2){
            PosicoesTabuleiro[X] = PosicaoTabuleiro3;
        }
        if(X == 3){
            PosicoesTabuleiro[X] = PosicaoTabuleiro4;
        }
        if(X == 4){
            PosicoesTabuleiro[X] = PosicaoTabuleiro5;
        }
        if(X == 5){
            PosicoesTabuleiro[X] = PosicaoTabuleiro6;
        }
        if(X == 6){
            PosicoesTabuleiro[X] = PosicaoTabuleiro7;
        }
        if(X == 7){
            PosicoesTabuleiro[X] = PosicaoTabuleiro8;
        }
        if(X == 8){
            PosicoesTabuleiro[X] = PosicaoTabuleiro9;
        }
        X +=1;
    }X = 0;

    //Coloca numa única lista todas as texturas das bases das cartas para facilitar na escrita do código//
    while(X != 12){
        if(X == 0){
            ImagensBase[X] = Imagem1Base;
        }
        if(X == 1){
            ImagensBase[X] = Imagem2Base;
        }
        if(X == 2){
            ImagensBase[X] = Imagem3Base;
        }
        if(X == 3){
            ImagensBase[X] = Imagem4Base;
        }
        if(X == 4){
            ImagensBase[X] = Imagem5Base;
        }
        if(X == 5){
            ImagensBase[X] = Imagem6Base;
        }
        if(X == 6){
            ImagensBase[X] = Imagem7Base;
        }
        if(X == 7){
            ImagensBase[X] = Imagem8Base;
        }
        if(X == 8){
            ImagensBase[X] = Imagem9Base;
        }
        if(X == 9){
            ImagensBase[X] = Imagem10Base;
        }
        if(X == 10){
            ImagensBase[X] = Imagem11Base;
        }
        if(X == 11){
            ImagensBase[X] = Imagem12Base;
        }
        X += 1;
    }X = 0;

    //Coloca numa única lista todas as texturas dos animais para facilitar na escrita do código//
    while(X != 12){
        if(X == 0){
            ImagensBichos[X] = Imagem1Bicho;
        }
        if(X == 1){
            ImagensBichos[X] = Imagem2Bicho;
        }
        if(X == 2){
            ImagensBichos[X] = Imagem3Bicho;
        }
        if(X == 3){
            ImagensBichos[X] = Imagem4Bicho;
        }
        if(X == 4){
            ImagensBichos[X] = Imagem5Bicho;
        }
        if(X == 5){
            ImagensBichos[X] = Imagem6Bicho;
        }
        if(X == 6){
            ImagensBichos[X] = Imagem7Bicho;
        }
        if(X == 7){
            ImagensBichos[X] = Imagem8Bicho;
        }
        if(X == 8){
            ImagensBichos[X] = Imagem9Bicho;
        }
        if(X == 9){
            ImagensBichos[X] = Imagem10Bicho;
        }
        if(X == 10){
            ImagensBichos[X] = Imagem11Bicho;
        }
        if(X == 11){
            ImagensBichos[X] = Imagem12Bicho;
        }
        X += 1;
    }X = 0;
    
    // Loop principal do jogo //
    while(!WindowShouldClose())
    {
        UpdateMusicStream(Musica);
        //Testa hitbox para pegar uma carta//
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            Vector2 PosicaoMouse = GetMousePosition();
            while(X != 12){
                Colisao = CheckCollisionPointRec(PosicaoMouse, PosicoesParadas[X]);
                if(Colisao){
                    if(TravaDoTabuleiro[X][0] == 0){
                        TravaCarta[X] = 1;
                        PosicaoEmMovimento[X][0] = (float)GetMouseX()-82;
                        PosicaoEmMovimento[X][1] = (float)GetMouseY()-82;
                    }
                }
                X += 1;
            }
        }X = 0; Y = 0;

        //Mantém a carta presa ao mouse enquanto ele não é solto//
        while(X != 12){
            if(TravaDoTabuleiro[X][0] == 0){
                if(TravaCarta[X] == 1){
                    PosicaoEmMovimento[X][0] = (float)GetMouseX()-82;
                    PosicaoEmMovimento[X][1] = (float)GetMouseY()-82;
                }
            }
            X += 1;
        }X = 0;

        //Checa se uma carta foi arrastada até o tabuleiro e testa se ela pode ser atrelada àquela casa que ela foi solta//
        int RealizarVirada = 0;
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
            Vector2 PosicaoMouse = GetMousePosition();
            while(X != 12){
                if(TravaCarta[X] == 1){
                    while(Y != 9){
                        Colisao = CheckCollisionPointRec(PosicaoMouse, PosicoesTabuleiro[Y]);
                        if(Colisao){
                            if(CasaCheia[Y] == 0){
                                TravaDoTabuleiro[X][0] = PosicaoTabuleiro[Y][0];
                                TravaDoTabuleiro[X][1] = PosicaoTabuleiro[Y][1];
                                TestesDoTabuleiro[Y][0] = NumerosDasCartas[X][0];
                                TestesDoTabuleiro[Y][1] = NumerosDasCartas[X][1];
                                TestesDoTabuleiro[Y][2] = NumerosDasCartas[X][2];
                                TestesDoTabuleiro[Y][3] = NumerosDasCartas[X][3];
                                CartasNoTabuleiro[Y] = X;
                                TravaCarta[X] = 0;
                                CasaCheia[Y] = 1;
                                RealizarVirada = 1;
                            }
                        }
                        if(!Colisao){
                            TravaCarta[X] = 0;
                        }
                        Y += 1;
                    }
                }
                X += 1;
            }
        }X = 0; Y = 0;

        //Trava as cartas nas posições do tabuleiro//
        while(X != 12){
            if(TravaDoTabuleiro[X][0] != 0){
                PosicaoEmMovimento[X][0] = TravaDoTabuleiro[X][0];
                PosicaoEmMovimento[X][1] = TravaDoTabuleiro[X][1];
            }
            X += 1;
        }X = 0;

        //Relaliza os testes das cartas para virar elas//
        while(X != 9){// X = onde a carta está no tabuleiro
            if(CasaCheia[X] == 1){//checa se tem uma carta no tabuleiro
                if(RealizarVirada == 1){//faz com que o teste de virar carta só seja executado uma vez
                    if(X == 0){//primeira posição do tabuleiro
                        if(TestesDoTabuleiro[X][1] > TestesDoTabuleiro[1][3]){//verifica qual carta está à direita
                            if(CartasNoTabuleiro[X] != 0){//verifical qual é a carta que está naquela posição
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+1]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X+1]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+1]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X+1]] = 1;
                                }
                            }
                        }
                        if(TestesDoTabuleiro[X][2] > TestesDoTabuleiro[3][0]){//verifica qual carta está abaixo
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+3]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X+3]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+3]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X+3]] = 1;
                                }
                            }

                        }
                    }

                    if(X == 1){//segunda posição
                        if(TestesDoTabuleiro[X][1] > TestesDoTabuleiro[2][3]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+1]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X+1]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+1]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X+1]] = 1;
                                }
                            }
                        }
                        if(TestesDoTabuleiro[X][2] > TestesDoTabuleiro[4][0]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+3]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X+3]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+3]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X+3]] = 1;
                                }
                            }   
                        }
                        if(TestesDoTabuleiro[X][3] > TestesDoTabuleiro[0][1]){//verifica qual carta está à esquerda
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-1]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X-1]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-1]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X-1]] = 1;
                                }
                            }
                        }
                    }

                    if(X == 2){//terceira posição
                        if(TestesDoTabuleiro[X][2] > TestesDoTabuleiro[5][0]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+3]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X+3]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+3]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X+3]] = 1;
                                }
                            }
                        }
                        if(TestesDoTabuleiro[X][3] > TestesDoTabuleiro[1][1]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-1]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X-1]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-1]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X-1]] = 1;
                                }
                            }
                        }
                    }
                    if(X == 3){//quarta posição
                        if(TestesDoTabuleiro[X][0] > TestesDoTabuleiro[0][2]){//verifica qual carta está acima
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-3]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X-3]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-3]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X-3]] = 1;
                                }
                            }
                        }
                        if(TestesDoTabuleiro[X][1] > TestesDoTabuleiro[4][3]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+1]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X+1]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+1]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X+1]] = 1;
                                }
                            } 
                        }
                        if(TestesDoTabuleiro[X][2] > TestesDoTabuleiro[6][0]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+3]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X+3]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+3]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X+3]] = 1;
                                }
                            }
                        }
                    }
                    if(X == 4){//quinta posição
                        if(TestesDoTabuleiro[X][0] > TestesDoTabuleiro[1][2]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-3]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X-3]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-3]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X-3]] = 1;
                                }
                            }
                        }
                        if(TestesDoTabuleiro[X][1] > TestesDoTabuleiro[5][3]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+1]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X+1]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+1]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X+1]] = 1;
                                }
                            }
                        }
                        if(TestesDoTabuleiro[X][2] > TestesDoTabuleiro[8][0]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+3]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X+3]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+3]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X+3]] = 1;
                                }
                            }
                        }
                        if(TestesDoTabuleiro[X][3] > TestesDoTabuleiro[3][1]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-1]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X-1]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-1]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X-1]] = 1;
                                }
                            }
                        }
                    }
                    if(X == 5){//sexta posição
                        if(TestesDoTabuleiro[X][0] > TestesDoTabuleiro[2][2]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-3]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X-3]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-3]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X-3]] = 1;
                                }
                            }
                        }
                        if(TestesDoTabuleiro[X][2] > TestesDoTabuleiro[8][0]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+3]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X+3]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+3]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X+3]] = 1;
                                }
                            }      
                        }
                        if(TestesDoTabuleiro[X][3] > TestesDoTabuleiro[4][1]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-1]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X-1]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-1]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X-1]] = 1;
                                }
                            }
                        }
                    }

                    if(X == 6){//sétima posição
                        if(TestesDoTabuleiro[X][0] > TestesDoTabuleiro[3][2]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-3]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X-3]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-3]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X-3]] = 1;
                                }
                            }
                        }
                        if(TestesDoTabuleiro[X][1] > TestesDoTabuleiro[7][3]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+1]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X+1]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+1]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X+1]] = 1;
                                }
                            }
                        }
                    }

                    if(X == 7){//Oitava posição
                        if(TestesDoTabuleiro[X][0] > TestesDoTabuleiro[2][2]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-3]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X-3]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-3]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X-3]] = 1;
                                }
                            }
                        }
                        if(TestesDoTabuleiro[X][1] > TestesDoTabuleiro[8][3]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+1]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X+1]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X+1]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X+1]] = 1;
                                }
                            } 
                        }
                        if(TestesDoTabuleiro[X][3] > TestesDoTabuleiro[6][1]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-1]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X-1]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-1]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X-1]] = 1;
                                }
                            }
                        }
                    }

                    if(X == 8){
                        if(TestesDoTabuleiro[X][0] > TestesDoTabuleiro[5][2]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-3]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X-3]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-3]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X-3]] = 1;
                                }
                            }
                        }
                        if(TestesDoTabuleiro[X][3] > TestesDoTabuleiro[7][1]){
                            if(CartasNoTabuleiro[X] != 0){
                                if(CartasDoJogador1[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-1]] = 1;
                                    CartasDoJogador2[CartasNoTabuleiro[X-1]] = 0;
                                }
                                if(CartasDoJogador2[CartasNoTabuleiro[X]] == 1){
                                    CartasDoJogador1[CartasNoTabuleiro[X-1]] = 0;
                                    CartasDoJogador2[CartasNoTabuleiro[X-1]] = 1;
                                }
                            }    
                        }
                    }
                }
            }
            X += 1;
        }X = 0; Y = 0;

        //volta as cartas pra posição inicial se elas foram soltas em outro lugar da tela senão as posições do tabuleiro//
        while(X != 12){
            if(TravaCarta[X] == 0){
                if(TravaDoTabuleiro[X][0] == 0){
                    PosicaoEmMovimento[X][0] = PosicaoParado[X][0];
                    PosicaoEmMovimento[X][1] = PosicaoParado[X][1];
                }
            }
            X += 1;
        }X = 0;

        BeginDrawing();
        DrawTexture(Fundo, 0, 0, WHITE);
        ClearBackground(RAYWHITE);

        //Desenha o fundo das cartas//
        while(X != 12){
            if(CartasDoJogador1[X] == 1){
                DrawTexture(ImagensBase[X],PosicaoEmMovimento[X][Y],PosicaoEmMovimento[X][Y+1],GREEN); 
            }
            if(CartasDoJogador2[X] == 1){
                DrawTexture(ImagensBase[X],PosicaoEmMovimento[X][Y],PosicaoEmMovimento[X][Y+1],RED);
            }
            X += 1;
        }X = 0;

        //Desenha os bichos das cartas//
        while(X != 12){
            DrawTexture(ImagensBichos[X],PosicaoEmMovimento[X][Y],PosicaoEmMovimento[X][Y+1],WHITE);
            X += 1;
        }X = 0;

        //Escreve o placar//
        if(Y == 0){
            int Placar[2]; Placar[0] = 0; Placar[1] = 0;
            while(X != 12){
                if(CartasDoJogador1[X] == 1){
                    Placar[0] += 1;
                }
                if(CartasDoJogador2[X] == 1){
                    Placar[1] += 1;
                }
                X += 1;
            }X = 0;
            if(Placar[0] == 0){
                DrawText("0",435,54,100,RAYWHITE);
            }
            if(Placar[0] == 1){
                DrawText("1",435,54,100,RAYWHITE);
            }
            if(Placar[0] == 2){
                DrawText("2",435,54,100,RAYWHITE);
            }
            if(Placar[0] == 3){
                DrawText("3",435,54,100,RAYWHITE);
            }
            if(Placar[0] == 4){
                DrawText("4",435,54,100,RAYWHITE);
            }
            if(Placar[0] == 5){
                DrawText("5",435,54,100,RAYWHITE);
            }
            if(Placar[0] == 6){
                DrawText("6",435,54,100,RAYWHITE);
            }
            if(Placar[0] == 7){
                DrawText("7",435,54,100,RAYWHITE);
            }
            if(Placar[0] == 8){
                DrawText("8",435,54,100,RAYWHITE);
            }
            if(Placar[0] == 9){
                DrawText("9",435,54,100,RAYWHITE);
            }

            if(Placar[1] == 0){
                DrawText("0",802,54,100,RAYWHITE);
            }
            if(Placar[1] == 1){
                DrawText("1",802,54,100,RAYWHITE);
            }
            if(Placar[1] == 2){
                DrawText("2",802,54,100,RAYWHITE);
            }
            if(Placar[1] == 3){
                DrawText("3",802,54,100,RAYWHITE);
            }
            if(Placar[1] == 4){
                DrawText("4",802,54,100,RAYWHITE);
            }
            if(Placar[1] == 5){
                DrawText("5",802,54,100,RAYWHITE);
            }
            if(Placar[1] == 6){
                DrawText("6",802,54,100,RAYWHITE);
            }
            if(Placar[1] == 7){
                DrawText("7",802,54,100,RAYWHITE);
            }
            if(Placar[1] == 8){
                DrawText("8",802,54,100,RAYWHITE);
            }
            if(Placar[1] == 9){
                DrawText("9",802,54,100,RAYWHITE);
            }
        }
        
        //Escreve o número dos bichos//
        float Lados[4][2], Z[2];
        Lados[0][0] = 79;
        Lados[0][1] = 8;

        Lados[1][0] = 130;
        Lados[1][1] = 69;

        Lados[2][0] = 79;
        Lados[2][1] = 130;

        Lados[3][0] = 17;
        Lados[3][1] = 69;

        while(X != 12){
            while(Y != 4){
                if(Y == 0){
                    Z[0] = Lados[0][0];
                    Z[1] = Lados[0][1];
                }
                if(Y == 1){
                    Z[0] = Lados[1][0];
                    Z[1] = Lados[1][1];
                }
                if(Y == 2){
                    Z[0] = Lados[2][0];
                    Z[1] = Lados[2][1];
                }
                if(Y == 3){
                    Z[0] = Lados[3][0];
                    Z[1] = Lados[3][1];
                }

                if(NumerosDasCartas[X][Y] == 0){
                    DrawText("0",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                }
                if(NumerosDasCartas[X][Y] == 1){
                    DrawText("1",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                }
                if(NumerosDasCartas[X][Y] == 2){
                    DrawText("2",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                }
                if(NumerosDasCartas[X][Y] == 3){
                    DrawText("3",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                }
                if(NumerosDasCartas[X][Y] == 4){
                    DrawText("4",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                }
                if(NumerosDasCartas[X][Y] == 5){
                    DrawText("5",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                }
                if(NumerosDasCartas[X][Y] == 6){
                    DrawText("6",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                }
                if(NumerosDasCartas[X][Y] == 7){
                    DrawText("7",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                }
                if(NumerosDasCartas[X][Y] == 8){
                    DrawText("8",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                }
                if(NumerosDasCartas[X][Y] == 9){
                    DrawText("9",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                }
                if(NumerosDasCartas[X][Y] == 10){
                    DrawText("10",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                }
                
                Y += 1;
            }Y = 0;
            X += 1;
        }X = 0;Y = 0;

        //Desenha a carta sendo segurada por cima das outras//
        while(X != 12){
            if(TravaCarta[X] == 1){
                if(CartasDoJogador1[X] == 1){
                DrawTexture(ImagensBase[X],PosicaoEmMovimento[X][Y],PosicaoEmMovimento[X][Y+1],GREEN); 
            }
            if(CartasDoJogador2[X] == 1){
                DrawTexture(ImagensBase[X],PosicaoEmMovimento[X][Y],PosicaoEmMovimento[X][Y+1],RED);
            }
            DrawTexture(ImagensBichos[X],PosicaoEmMovimento[X][Y],PosicaoEmMovimento[X][Y+1],WHITE);
            while(Y != 4){
                    if(Y == 0){
                        Z[0] = Lados[0][0];
                        Z[1] = Lados[0][1];
                    }
                    if(Y == 1){
                        Z[0] = Lados[1][0];
                        Z[1] = Lados[1][1];
                    }
                    if(Y == 2){
                        Z[0] = Lados[2][0];
                        Z[1] = Lados[2][1];
                    }
                    if(Y == 3){
                        Z[0] = Lados[3][0];
                        Z[1] = Lados[3][1];
                    }

                    if(NumerosDasCartas[X][Y] == 0){
                        DrawText("0",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                    }
                    if(NumerosDasCartas[X][Y] == 1){
                        DrawText("1",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                    }
                    if(NumerosDasCartas[X][Y] == 2){
                        DrawText("2",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                    }
                    if(NumerosDasCartas[X][Y] == 3){
                        DrawText("3",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                    }
                    if(NumerosDasCartas[X][Y] == 4){
                        DrawText("4",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                    }
                    if(NumerosDasCartas[X][Y] == 5){
                        DrawText("5",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                    }
                    if(NumerosDasCartas[X][Y] == 6){
                        DrawText("6",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                    }
                    if(NumerosDasCartas[X][Y] == 7){
                        DrawText("7",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                    }
                    if(NumerosDasCartas[X][Y] == 8){
                        DrawText("8",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                    }
                    if(NumerosDasCartas[X][Y] == 9){
                        DrawText("9",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                    }
                    if(NumerosDasCartas[X][Y] == 10){
                        DrawText("10",PosicaoEmMovimento[X][0]+Z[0],PosicaoEmMovimento[X][1]+Z[1],30,GRAY);
                    }
                    Y += 1;
                }Y = 0;
            }
            X += 1;
        }X = 0;

        EndDrawing();

        TimePlayed = GetMusicTimePlayed(Musica)/GetMusicTimeLength(Musica);
        if(TimePlayed > 1){
            TimePlayed = 1;
        }
    }
    UnloadMusicStream(Musica);

    return 0;
}
