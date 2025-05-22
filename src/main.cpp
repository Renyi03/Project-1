/*
?MIT License


Copyright(c)[year][fullname]


Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :


The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "raylib.h"
#include "Pengo.hpp"
#include "Map.hpp"
#include "Block.hpp"
#include "Pengo.hpp"
#include "SnoBee.hpp"
#include <ctime>
#include <string>
using namespace std;

typedef enum GameScreen { INITIAL, TITLE, LEVEL1, LEVEL2, LEVEL3, LEVEL4, LEVEL5, LEVEL6, LEVEL7, LEVEL8, LEVEL9, LEVEL10, LEVEL11, LEVEL12, LEVEL13, LEVEL14, LEVEL15, LEVEL16, GAMEOVER, POINTS } GameScreen;

int main(void)
{
    InitWindow(800, 900, "El mejor juego de proyecto 1: An indescribable emptiness");
    InitAudioDevice();
    SetTargetFPS(60);

    std::string map1file = LoadFileText("resources/Map_1.txt");
    std::string map2file = LoadFileText("resources/Map_2.txt");
    std::string map3file = LoadFileText("resources/Map_3.txt");
    std::string map4file = LoadFileText("resources/Map_4.txt");
    std::string map5file = LoadFileText("resources/Map_5.txt");
    std::string map6file = LoadFileText("resources/Map_6.txt");
    std::string map7file = LoadFileText("resources/Map_7.txt");
    std::string map8file = LoadFileText("resources/Map_8.txt");
    std::string map9file = LoadFileText("resources/Map_9.txt");
    std::string map10file = LoadFileText("resources/Map_10.txt");
    std::string map11file = LoadFileText("resources/Map_11.txt");
    std::string map12file = LoadFileText("resources/Map_12.txt");
    std::string map13file = LoadFileText("resources/Map_13.txt");
    std::string map14file = LoadFileText("resources/Map_14.txt");
    std::string map15file = LoadFileText("resources/Map_15.txt");
    std::string map16file = LoadFileText("resources/Map_16.txt");


    Rectangle borderTop = Rectangle{ 88, 80, 624, 10 };
    Rectangle borderBottom = Rectangle{ 88, 810, 624, 10 };
    Rectangle borderLeft = Rectangle{ 78, 90, 10, 720 };
    Rectangle borderRight = Rectangle{ 712, 90, 10, 720 };
    Rectangle border{88, 90, 624, 720};
<<<<<<< Updated upstream
    Map* map1 = new Map{ border, map1file };
    Map* map2 = new Map{ border, map2file };
    Map* map3 = new Map{ border, map3file };
    Map* map4 = new Map{ border, map4file };
    Map* map5 = new Map{ border, map5file };
    Map* map6 = new Map{ border, map6file };
    Map* map7 = new Map{ border, map7file };
    Map* map8 = new Map{ border, map8file };
    Map* map9 = new Map{ border, map9file };
    Map* map10 = new Map{ border, map10file };
    Map* map11 = new Map{ border, map11file };
    Map* map12 = new Map{ border, map12file };
    Map* map13 = new Map{ border, map13file };
    Map* map14 = new Map{ border, map14file };
    Map* map15 = new Map{ border, map15file };
    Map* map16 = new Map{ border, map16file };
=======
    Texture2D imgPengo = LoadTexture("resources/Graphics/Pengo_sprites/Pengo_down_1.png");
    Texture2D ice_block = LoadTexture("resources/Graphics/ice_block.png");
    Texture2D levelCntImage = LoadTexture("resources/Graphics/level_cnt.png");
    Texture2D lifeImage = LoadTexture("resources/Graphics/Pengo_life.png");
    Texture2D imgSnobee = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_down_1.png");
    Texture2D levelCntImage2 = LoadTexture("resources/Graphics/level cnt.png"); //se tiene que cambiar por el sprite del pinguino con el 5

    Map* map;
    Map* map1 = new Map{ border, map1file, imgSnobee, imgPengo, ice_block };
    Map* map2 = new Map{ border, map2file, imgSnobee, imgPengo, ice_block };
    Map* map3 = new Map{ border, map3file, imgSnobee, imgPengo, ice_block };
    Map* map4 = new Map{ border, map4file, imgSnobee, imgPengo, ice_block };
    Map* map5 = new Map{ border, map5file, imgSnobee, imgPengo, ice_block };
    Map* map6 = new Map{ border, map6file, imgSnobee, imgPengo, ice_block };
    Map* map7 = new Map{ border, map7file, imgSnobee, imgPengo, ice_block };
    Map* map8 = new Map{ border, map8file, imgSnobee, imgPengo, ice_block };
    Map* map9 = new Map{ border, map9file, imgSnobee, imgPengo, ice_block };
    Map* map10 = new Map{ border, map10file, imgSnobee, imgPengo, ice_block };
    Map* map11 = new Map{ border, map11file, imgSnobee, imgPengo, ice_block };
    Map* map12 = new Map{ border, map12file, imgSnobee, imgPengo, ice_block };
    Map* map13 = new Map{ border, map13file, imgSnobee, imgPengo, ice_block };
    Map* map14 = new Map{ border, map14file, imgSnobee, imgPengo, ice_block };
    Map* map15 = new Map{ border, map15file, imgSnobee, imgPengo, ice_block };
    Map* map16 = new Map{ border, map16file, imgSnobee, imgPengo, ice_block };

    map1->gameOver = false;
    map2->gameOver = false;
    map3->gameOver = false;
    map4->gameOver = false;
    map5->gameOver = false;
    map6->gameOver = false;
    map7->gameOver = false;
    map8->gameOver = false;
    map9->gameOver = false;
    map10->gameOver = false;
    map11->gameOver = false;
    map12->gameOver = false;
    map13->gameOver = false;
    map14->gameOver = false;
    map15->gameOver = false;
    map16->gameOver = false;

>>>>>>> Stashed changes
    /*Pengo pengo{ border, &map };*/
    /*map.pengo = &pengo;*/

    Texture2D lifeImage = LoadTexture("resources/Graphics/Pengo_life.png");

    Vector2 lifePosition1;
    lifePosition1.x = 88;
    lifePosition1.y = 30;

    Vector2 lifePosition2;
    lifePosition2.x = 136;
    lifePosition2.y = 30;

    Vector2 lifePosition3;
    lifePosition3.x = 184;
    lifePosition3.y = 30;

    Vector2 lifePosition4;
    lifePosition4.x = 232;
    lifePosition4.y = 30;


    Texture2D levelCntImage = LoadTexture("resources/Graphics/level cnt.png");
    Vector2 levelCntPosition1;
    levelCntPosition1.x = 220;
    levelCntPosition1.y = 850;
    Vector2 levelCntPosition2;
    levelCntPosition2.x = 270;
    levelCntPosition2.y = 850;
    Vector2 levelCntPosition3;
    levelCntPosition3.x = 320;
    levelCntPosition3.y = 850;
    Vector2 levelCntPosition4;
    levelCntPosition4.x = 370;
    levelCntPosition4.y = 850;


    Texture2D levelCntImage2 = LoadTexture("resources/Graphics/level cnt.png");
    Vector2 levelCntPosition5;
    levelCntPosition5.x = 572;
    levelCntPosition5.y = 30;
    Vector2 levelCntPosition10;
    levelCntPosition10.x = 622;
    levelCntPosition10.y = 30;
    Vector2 levelCntPosition15;
    levelCntPosition15.x = 672;
    levelCntPosition15.y = 30;



    srand(time(NULL));
 
    GameScreen currentScreen = INITIAL;

    Music Main_BGM = LoadMusicStream("resources/Pengo_Music/Main_BGM_(Popcorn).wav");

    //PlayMusicStream(Main_BGM);

    //Game Loop

    while (WindowShouldClose() == false) {

        switch (currentScreen) {

        case INITIAL:
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                currentScreen = TITLE;
            }
        }break;
        case TITLE:
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                currentScreen = LEVEL1;
            }
        }break;
        case LEVEL1:
        {
            UpdateMusicStream(Main_BGM);

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
        }break;
        case LEVEL2:
        {
            UpdateMusicStream(Main_BGM);

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

<<<<<<< Updated upstream
=======
            for (int i = 0; i < map->lives; ++i) {
                if (map->lives == 2) {
                    DrawTextureV(lifeImage, lifePosition1, WHITE);
                }
                if (map->lives == 3) {
                    DrawTextureV(lifeImage, lifePosition1, WHITE);
                    DrawTextureV(lifeImage, lifePosition2, WHITE);
                }
                if (map->lives == 4) {
                    DrawTextureV(lifeImage, lifePosition1, WHITE);
                    DrawTextureV(lifeImage, lifePosition2, WHITE);
                    DrawTextureV(lifeImage, lifePosition3, WHITE);
                }
                if (map->lives == 5) {
                    DrawTextureV(lifeImage, lifePosition1, WHITE);
                    DrawTextureV(lifeImage, lifePosition2, WHITE);
                    DrawTextureV(lifeImage, lifePosition3, WHITE);
                    DrawTextureV(lifeImage, lifePosition4, WHITE);
                }
            }

>>>>>>> Stashed changes
            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition2, WHITE);
        }break;
        case LEVEL3:
        {
            UpdateMusicStream(Main_BGM);

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition2, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition3, WHITE);
        }break;
        case LEVEL4:
        {
            UpdateMusicStream(Main_BGM);

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition2, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition3, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition4, WHITE);
        }break;
        case LEVEL5:
        {
            UpdateMusicStream(Main_BGM);

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);

            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);

        }break;
        case LEVEL6:
        {
            UpdateMusicStream(Main_BGM);

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);

        }break;
        case LEVEL7:
        {
            UpdateMusicStream(Main_BGM);

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);


            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition2, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);

        }break;
        case LEVEL8:
        {
            UpdateMusicStream(Main_BGM);

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition2, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition3, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);

        }break;
        case LEVEL9:
        {
            UpdateMusicStream(Main_BGM);

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition2, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition3, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition4, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);

        }break;
        case LEVEL10:
        {
            UpdateMusicStream(Main_BGM);

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);

            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition10, WHITE);
        }break;
        case LEVEL11:
        {
            UpdateMusicStream(Main_BGM);

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition10, WHITE);
        }break;
        case LEVEL12:
        {
            UpdateMusicStream(Main_BGM);

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition2, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition10, WHITE);
        }break;
        case LEVEL13:
        {
            UpdateMusicStream(Main_BGM);

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition2, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition3, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition10, WHITE);
        }break;
        case LEVEL14:
        {
            UpdateMusicStream(Main_BGM);

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition2, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition3, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition4, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition10, WHITE);
        }break;
        case LEVEL15:
        {
            UpdateMusicStream(Main_BGM);

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);

            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition10, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition15, WHITE);
        }break;
        case LEVEL16:
        {
            UpdateMusicStream(Main_BGM);

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition10, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition15, WHITE);
        }break;
        case GAMEOVER:
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {

                delete map1;
                map1 = new Map{ border, map1file };
                delete map2;
                map2 = new Map{ border, map2file };
                delete map3;
                map3 = new Map{ border, map3file };
                delete map4;
                map4 = new Map{ border, map4file };
                delete map5;
                map5 = new Map{ border, map5file };
                delete map6;
                map6 = new Map{ border, map6file };
                delete map7;
                map7 = new Map{ border, map7file };
                delete map8;
                map8 = new Map{ border, map8file };
                delete map9;
                map9 = new Map{ border, map9file };
                delete map10;
                map10 = new Map{ border, map10file };
                delete map11;
                map11 = new Map{ border, map11file };
                delete map12;
                map12 = new Map{ border, map12file };
                delete map13;
                map13 = new Map{ border, map13file };
                delete map14;
                map14 = new Map{ border, map14file };
                delete map15;
                map15 = new Map{ border, map15file };
                delete map16;
                map16 = new Map{ border, map16file };
                map1->gameOver = false;
                map2->gameOver = false;
                map3->gameOver = false;
                map4->gameOver = false;
                map5->gameOver = false;
                map6->gameOver = false;
                map7->gameOver = false;
                map8->gameOver = false;
                map9->gameOver = false;
                map10->gameOver = false;
                map11->gameOver = false;
                map12->gameOver = false;
                map13->gameOver = false;
                map14->gameOver = false;
                map15->gameOver = false;
                map16->gameOver = false;
                currentScreen = TITLE;
            }
        }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        switch (currentScreen)
        {
        case INITIAL:
        {
            // TODO: Draw LOGO screen here!
            DrawText("PENGO PROTOTYPE", 66, 50, 40, LIGHTGRAY);
            DrawText("Project 1, Video game design and development, CITM", 125, 220, 20, GRAY);
            DrawText("Team members: Sofia Barja, Clara Sanchez, Yin Ye", 133, 270, 20, GRAY);
            DrawText("Github accounts: sofia-221b, Valkyn22, Renyi03", 150, 320, 20, GRAY);
            DrawText("Tutors: Aleix Cots, Alejandro Paris", 205, 370, 20, GRAY);
        } break;
        case TITLE:
        {
            // TODO: Draw TITLE screen here!
            DrawRectangle(0, 0, 800, 900, BLUE);
            DrawText("TITLE SCREEN", 20, 20, 40, DARKBLUE);
            DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKBLUE);

        } break;
        case LEVEL1:
        {
            map1->Draw();

            if (map1->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map1->nextLevel == true) {
                map1->nextLevel = false;
                currentScreen = LEVEL2;
            }
            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map1->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  1"), 88, 850, 30, WHITE);

        } break;
        case LEVEL2:
        {
            map->Draw();

            if (map->gameOver == true) {
                currentScreen = GAMEOVER;
            }

<<<<<<< Updated upstream
            if (map2->nextLevel == true) {
                map2->nextLevel = false;
=======
            if (map->nextLevel == true) {
                levelEndTime = GetTime();
                int timeSpent = levelEndTime - levelStartTime;
                if (timeSpent < 20) {
                    bonusPoints = 5000;
                }
                else if (timeSpent < 30) {
                    bonusPoints = 2000;
                }
                else if (timeSpent < 40) {
                    bonusPoints = 1000;
                }
                else if (timeSpent < 50) {
                    bonusPoints = 500;
                }
                else if (timeSpent < 60) {
                    bonusPoints = 10;
                }
                map->addScore(bonusPoints);
                totalScore += bonusPoints;
                map->nextLevel = false;
>>>>>>> Stashed changes
                currentScreen = LEVEL3;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map2->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  2"), 88, 850, 30, WHITE);
        } break;
        case LEVEL3:
        {
            map->Draw();

            if (map->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map->nextLevel == true) {
                map->nextLevel = false;
                currentScreen = LEVEL4;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map3->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  3"), 88, 850, 30, WHITE);
        } break;
        case LEVEL4:
        {
            map->Draw();

            if (map->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map->nextLevel == true) {
                map->nextLevel = false;
                currentScreen = LEVEL5;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map4->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  4"), 88, 850, 30, WHITE);
        } break;
        case LEVEL5:
        {
            map->Draw();

            if (map->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map->nextLevel == true) {
                map->nextLevel = false;
                currentScreen = LEVEL6;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map5->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  5"), 88, 850, 30, WHITE);
        } break;
        case LEVEL6:
        {
            map->Draw();

            if (map->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map->nextLevel == true) {
                map->nextLevel = false;
                currentScreen = LEVEL7;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map6->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  6"), 88, 850, 30, WHITE);
        } break;
        case LEVEL7:
        {
            map->Draw();

            if (map->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map->nextLevel == true) {
                map->nextLevel = false;
                currentScreen = LEVEL8;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map7->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  7"), 88, 850, 30, WHITE);
        } break;
        case LEVEL8:
        {
            map->Draw();

            if (map->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map->nextLevel == true) {
                map->nextLevel = false;
                currentScreen = LEVEL9;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map8->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  8"), 88, 850, 30, WHITE);
        } break;
        case LEVEL9:
        {
            map->Draw();

            if (map->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map->nextLevel == true) {
                map->nextLevel = false;
                currentScreen = LEVEL10;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map9->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  9"), 88, 850, 30, WHITE);
        } break;
        case LEVEL10:
        {
            map->Draw();

            if (map->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map->nextLevel == true) {
                map->nextLevel = false;
                currentScreen = LEVEL11;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map10->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  10"), 88, 850, 30, WHITE);
        } break;
        case LEVEL11:
        {
            map->Draw();

            if (map->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map->nextLevel == true) {
                map->nextLevel = false;
                currentScreen = LEVEL12;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map11->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  11"), 88, 850, 30, WHITE);
        } break;
        case LEVEL12:
        {
            map->Draw();

            if (map->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map->nextLevel == true) {
                map->nextLevel = false;
                currentScreen = LEVEL13;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map12->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  12"), 88, 850, 30, WHITE);
        } break;
        case LEVEL13:
        {
            map->Draw();

            if (map->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map->nextLevel == true) {
                map->nextLevel = false;
                currentScreen = LEVEL14;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map13->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  13"), 88, 850, 30, WHITE);
        } break;
        case LEVEL14:
        {
            map->Draw();

            if (map->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map->nextLevel == true) {
                map->nextLevel = false;
                currentScreen = LEVEL15;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map14->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  14"), 88, 850, 30, WHITE);
        } break;
        case LEVEL15:
        {
            map->Draw();

            if (map->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map->nextLevel == true) {
                map->nextLevel = false;
                currentScreen = LEVEL16;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map15->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  15"), 88, 850, 30, WHITE);
        } break;
        case LEVEL16:
        {
            map->Draw();

            if (map->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map->nextLevel == true) {
                map->nextLevel = false;
                currentScreen = GAMEOVER;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map16->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  16"), 88, 850, 30, WHITE);
        } break;
<<<<<<< Updated upstream
=======


        case POINTS:
        {
            DrawRectangle(0, 0, 800, 900, BLACK);
            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("GAME TIME %d SECONDS", levelEndTime - levelStartTime), 200, 160, 30, YELLOW);
            DrawText("FROM 00 TO 19  5000 PTS", 200, 260, 30, BLUE);
            DrawText("FROM 20 TO 29  2000 PTS", 200, 360, 30, BLUE);
            DrawText("FROM 30 TO 39  1000 PTS", 200, 460, 30, BLUE);
            DrawText("FROM 40 TO 49  500 PTS", 200, 560, 30, BLUE);
            DrawText("FROM 50 TO 59  10 PTS", 200, 660, 30, BLUE);
            DrawText("60 AND OVER   NO BONUS", 200, 760, 30, YELLOW);
            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                if (level == 1) {
                    levelStartTime = GetTime();
                    currentScreen = LEVEL2;
                }
                else if (level == 2) {
                    currentScreen = GAMEOVER;
                }
            }
            
                int num_map = GetRandomValue(2, 16);
                
                if (num_map == 2) {
                    map = map2;
                }
                else if (num_map == 3) {
                    map = map3;
                }
                else if (num_map == 4) {
                    map = map4;
                }
                else if (num_map == 5) {
                    map = map5;
                }
                else if (num_map == 6) {
                    map = map6;
                }
                else if (num_map == 7) {
                    map = map7;
                }
                else if (num_map == 8) {
                    map = map8;
                }
                else if (num_map == 9) {
                    map = map9;
                }
                else if (num_map == 10) {
                    map = map10;
                }
                else if (num_map == 11) {
                    map = map11;
                }
                else if (num_map == 12) {
                    map = map12;
                }
                else if (num_map == 13) {
                    map = map13;
                }
                else if (num_map == 14) {
                    map = map14;
                }
                else if (num_map == 15) {
                    map = map15;
                }
                else if (num_map == 16) {
                    map = map16;
                }
            
        } break;

>>>>>>> Stashed changes
        case GAMEOVER:
        {
            DrawRectangle(0, 0, 800, 900, BLUE);
            DrawText("GAME OVER", 20, 20, 40, DARKBLUE);
            DrawText("PRESS ENTER or TAP to JUMP to TITLE SCREEN", 120, 220, 20, DARKBLUE);
        }
        default: break;
        }
        EndDrawing();
    } 

    UnloadMusicStream(Main_BGM);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

