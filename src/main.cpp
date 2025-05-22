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

    int levelStartTime = 0;
    int levelEndTime = 0;
    int bonusPoints = 0;
    int level;
    int totalScore = 0;

    std::string map1file = LoadFileText("resources/Maps/Map_1.txt");
    std::string map2file = LoadFileText("resources/Maps/Map_2.txt");
    std::string map3file = LoadFileText("resources/Maps/Map_3.txt");
    std::string map4file = LoadFileText("resources/Maps/Map_4.txt");
    std::string map5file = LoadFileText("resources/Maps/Map_5.txt");
    std::string map6file = LoadFileText("resources/Maps/Map_6.txt");
    std::string map7file = LoadFileText("resources/Maps/Map_7.txt");
    std::string map8file = LoadFileText("resources/Maps/Map_8.txt");
    std::string map9file = LoadFileText("resources/Maps/Map_9.txt");
    std::string map10file = LoadFileText("resources/Maps/Map_10.txt");
    std::string map11file = LoadFileText("resources/Maps/Map_11.txt");
    std::string map12file = LoadFileText("resources/Maps/Map_12.txt");
    std::string map13file = LoadFileText("resources/Maps/Map_13.txt");
    std::string map14file = LoadFileText("resources/Maps/Map_14.txt");
    std::string map15file = LoadFileText("resources/Maps/Map_15.txt");
    std::string map16file = LoadFileText("resources/Maps/Map_16.txt");


    Rectangle borderTop = Rectangle{ 88, 80, 624, 10 };
    Rectangle borderBottom = Rectangle{ 88, 810, 624, 10 };
    Rectangle borderLeft = Rectangle{ 78, 90, 10, 720 };
    Rectangle borderRight = Rectangle{ 712, 90, 10, 720 };
    Rectangle border{88, 90, 624, 720};
    Texture2D imgPengo = LoadTexture("resources/Graphics/Pengo_sprites/Pengo_down_1.png");
    Texture2D ice_block = LoadTexture("resources/Graphics/ice_block.png");
    Texture2D levelCntImage = LoadTexture("resources/Graphics/level_cnt.png");
    Texture2D lifeImage = LoadTexture("resources/Graphics/Pengo_life.png");
    Texture2D imgSnobee = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_down_1.png");
    Texture2D levelCntImage2 = LoadTexture("resources/Graphics/level cnt.png"); //se tiene que cambiar por el sprite del pinguino con el 5


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

    /*Pengo pengo{ border, &map };*/
    /*map.pengo = &pengo;*/


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
        totalScore = map1->GetScore() + map2->GetScore() + map3->GetScore() + map4->GetScore() + map5->GetScore() + map6->GetScore() + map7->GetScore() + map8->GetScore() + map9->GetScore() + map10->GetScore() + map11->GetScore() + map12->GetScore() + map13->GetScore() + map14->GetScore() + map15->GetScore() + map16->GetScore();

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
                levelStartTime = GetTime();
                currentScreen = LEVEL1;
            }
        }break;
        case LEVEL1:
        {
            UpdateMusicStream(Main_BGM);
            level = 1;

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            for (int i = 0; i < map1->lives; ++i) {
                if (map1->lives == 2) {
                    DrawTextureV(lifeImage, lifePosition1, WHITE);
                }
                if (map1->lives == 3) {
                    DrawTextureV(lifeImage, lifePosition1, WHITE);
                    DrawTextureV(lifeImage, lifePosition2, WHITE);
                }
                if (map1->lives == 4) {
                    DrawTextureV(lifeImage, lifePosition1, WHITE);
                    DrawTextureV(lifeImage, lifePosition2, WHITE);
                    DrawTextureV(lifeImage, lifePosition3, WHITE);
                }
                if (map1->lives == 5) {
                    DrawTextureV(lifeImage, lifePosition1, WHITE);
                    DrawTextureV(lifeImage, lifePosition2, WHITE);
                    DrawTextureV(lifeImage, lifePosition3, WHITE);
                    DrawTextureV(lifeImage, lifePosition4, WHITE);
                }
            }

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);

            

        }break;
        case LEVEL2:
        {
            UpdateMusicStream(Main_BGM);
            level = 2;

            /*bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            bool isAColliding = CheckCollisionRecs(snoBee.GetRect(), borderTop);*/

            for (int i = 0; i < map2->lives; ++i) {
                if (map2->lives == 2) {
                    DrawTextureV(lifeImage, lifePosition1, WHITE);
                }
                if (map2->lives == 3) {
                    DrawTextureV(lifeImage, lifePosition1, WHITE);
                    DrawTextureV(lifeImage, lifePosition2, WHITE);
                }
                if (map2->lives == 4) {
                    DrawTextureV(lifeImage, lifePosition1, WHITE);
                    DrawTextureV(lifeImage, lifePosition2, WHITE);
                    DrawTextureV(lifeImage, lifePosition3, WHITE);
                }
                if (map2->lives == 5) {
                    DrawTextureV(lifeImage, lifePosition1, WHITE);
                    DrawTextureV(lifeImage, lifePosition2, WHITE);
                    DrawTextureV(lifeImage, lifePosition3, WHITE);
                    DrawTextureV(lifeImage, lifePosition4, WHITE);
                }
            }

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition2, WHITE);
        }break;
        case POINTS:
        {

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
                map1 = new Map{ border, map1file, imgSnobee, imgPengo, ice_block };
                delete map2;
                map2 = new Map{ border, map2file, imgSnobee, imgPengo, ice_block };
                delete map3;
                map3 = new Map{ border, map3file, imgSnobee, imgPengo, ice_block };
                delete map4;
                map4 = new Map{ border, map4file, imgSnobee, imgPengo, ice_block };
                delete map5;
                map5 = new Map{ border, map5file, imgSnobee, imgPengo, ice_block };
                delete map6;
                map6 = new Map{ border, map6file, imgSnobee, imgPengo, ice_block };
                delete map7;
                map7 = new Map{ border, map7file, imgSnobee, imgPengo, ice_block };
                delete map8;
                map8 = new Map{ border, map8file, imgSnobee, imgPengo, ice_block };
                delete map9;
                map9 = new Map{ border, map9file, imgSnobee, imgPengo, ice_block };
                delete map10;
                map10 = new Map{ border, map10file, imgSnobee, imgPengo, ice_block };
                delete map11;
                map11 = new Map{ border, map11file, imgSnobee, imgPengo, ice_block };
                delete map12;
                map12 = new Map{ border, map12file, imgSnobee, imgPengo, ice_block };
                delete map13;
                map13 = new Map{ border, map13file, imgSnobee, imgPengo, ice_block };
                delete map14;
                map14 = new Map{ border, map14file, imgSnobee, imgPengo, ice_block };
                delete map15;
                map15 = new Map{ border, map15file, imgSnobee, imgPengo, ice_block };
                delete map16;
                map16 = new Map{ border, map16file, imgSnobee, imgPengo, ice_block };
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
            DrawText("PENGO PROTOTYPE", 66, 50, 40, LIGHTGRAY);
            DrawText("Project 1, Video game design and development, CITM", 125, 220, 20, GRAY);
            DrawText("Team members: Sofia Barja, Clara Sanchez, Yin Ye", 133, 270, 20, GRAY);
            DrawText("Github accounts: sofia-221b, Valkyn22, Renyi03", 150, 320, 20, GRAY);
            DrawText("Tutors: Aleix Cots, Alejandro Paris", 205, 370, 20, GRAY);
        } break;
        case TITLE:
        {
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
                map1->addScore(bonusPoints);
                totalScore += bonusPoints;
                map1->nextLevel = false;
                currentScreen = POINTS;
            }
            
            
            
            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  1"), 88, 850, 30, WHITE);

            if (IsKeyPressed(KEY_N)) {
                currentScreen = LEVEL2;
            }

        } break;
        case LEVEL2:
        {
            map2->Draw();

            if (map2->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map2->nextLevel == true) {
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
                map2->addScore(bonusPoints);
                totalScore += bonusPoints;
                map2->nextLevel = false;
                currentScreen = LEVEL3;
            }


            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  2"), 88, 850, 30, WHITE);

            if (IsKeyPressed(KEY_N)) {
                currentScreen = LEVEL3;
            }

        } break;
        case LEVEL3:
        {
            map3->Draw();

            if (map3->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map3->nextLevel == true) {
                map3->nextLevel = false;
                currentScreen = LEVEL4;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  3"), 88, 850, 30, WHITE);

            if (IsKeyPressed(KEY_N)) {
                currentScreen = LEVEL4;
            }
        } break;
        case LEVEL4:
        {
            map4->Draw();

            if (map4->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map4->nextLevel == true) {
                map4->nextLevel = false;
                currentScreen = LEVEL5;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  4"), 88, 850, 30, WHITE);

            if (IsKeyPressed(KEY_N)) {
                currentScreen = LEVEL5;
            }
        } break;
        case LEVEL5:
        {
            map5->Draw();

            if (map5->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map5->nextLevel == true) {
                map5->nextLevel = false;
                currentScreen = LEVEL6;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  5"), 88, 850, 30, WHITE);

            if (IsKeyPressed(KEY_N)) {
                currentScreen = LEVEL6;
            }
        } break;
        case LEVEL6:
        {
            map6->Draw();

            if (map6->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map6->nextLevel == true) {
                map6->nextLevel = false;
                currentScreen = LEVEL7;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  6"), 88, 850, 30, WHITE);

            if (IsKeyPressed(KEY_N)) {
                currentScreen = LEVEL7;
            }
        } break;
        case LEVEL7:
        {
            map7->Draw();

            if (map7->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map7->nextLevel == true) {
                map7->nextLevel = false;
                currentScreen = LEVEL8;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  7"), 88, 850, 30, WHITE);

            if (IsKeyPressed(KEY_N)) {
                currentScreen = LEVEL8;
            }
        } break;
        case LEVEL8:
        {
            map8->Draw();

            if (map8->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map8->nextLevel == true) {
                map8->nextLevel = false;
                currentScreen = LEVEL9;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  8"), 88, 850, 30, WHITE);

            if (IsKeyPressed(KEY_N)) {
                currentScreen = LEVEL9;
            }
        } break;
        case LEVEL9:
        {
            map9->Draw();

            if (map9->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map9->nextLevel == true) {
                map9->nextLevel = false;
                currentScreen = LEVEL10;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  9"), 88, 850, 30, WHITE);

            if (IsKeyPressed(KEY_N)) {
                currentScreen = LEVEL10;
            }
        } break;
        case LEVEL10:
        {
            map10->Draw();

            if (map10->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map10->nextLevel == true) {
                map10->nextLevel = false;
                currentScreen = LEVEL11;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  10"), 88, 850, 30, WHITE);

            if (IsKeyPressed(KEY_N)) {
                currentScreen = LEVEL11;
            }
        } break;
        case LEVEL11:
        {
            map11->Draw();

            if (map11->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map11->nextLevel == true) {
                map11->nextLevel = false;
                currentScreen = LEVEL12;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  11"), 88, 850, 30, WHITE);

            if (IsKeyPressed(KEY_N)) {
                currentScreen = LEVEL12;
            }
        } break;
        case LEVEL12:
        {
            map12->Draw();

            if (map12->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map12->nextLevel == true) {
                map12->nextLevel = false;
                currentScreen = LEVEL13;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  12"), 88, 850, 30, WHITE);

            if (IsKeyPressed(KEY_N)) {
                currentScreen = LEVEL13;
            }

        } break;
        case LEVEL13:
        {
            map13->Draw();

            if (map13->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map13->nextLevel == true) {
                map13->nextLevel = false;
                currentScreen = LEVEL14;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  13"), 88, 850, 30, WHITE);

            if (IsKeyPressed(KEY_N)) {
                currentScreen = LEVEL14;
            }
        } break;
        case LEVEL14:
        {
            map14->Draw();

            if (map14->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map14->nextLevel == true) {
                map14->nextLevel = false;
                currentScreen = LEVEL15;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  14"), 88, 850, 30, WHITE);

            if (IsKeyPressed(KEY_N)) {
                currentScreen = LEVEL15;
            }
        } break;
        case LEVEL15:
        {
            map15->Draw();

            if (map15->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map15->nextLevel == true) {
                map15->nextLevel = false;
                currentScreen = LEVEL16;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  15"), 88, 850, 30, WHITE);

            if (IsKeyPressed(KEY_N)) {
                currentScreen = LEVEL16;
            }
        } break;
        case LEVEL16:
        {
            map16->Draw();

            if (map16->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map16->nextLevel == true) {
                map16->nextLevel = false;
                currentScreen = GAMEOVER;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  16"), 88, 850, 30, WHITE);

            if (IsKeyPressed(KEY_N)) {
                currentScreen = GAMEOVER;
            }
        } break;


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
        } break;

        case GAMEOVER:
        {
            totalScore = 0;

            DrawRectangle(0, 0, 800, 900, BLUE);
            DrawText("GAME OVER", 20, 20, 40, DARKBLUE);
            DrawText("PRESS ENTER or TAP to JUMP to TITLE SCREEN", 120, 220, 20, DARKBLUE);
        }
        default: break;
        }
        EndDrawing();
    } 

    UnloadMusicStream(Main_BGM);
    UnloadTexture(imgPengo);
    UnloadTexture(imgSnobee);
    UnloadTexture(ice_block);
    UnloadTexture(levelCntImage);
    UnloadTexture(lifeImage);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

