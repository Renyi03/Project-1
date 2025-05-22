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

    Vector2 levelCntPosition6;
    levelCntPosition6.x = 320;
    levelCntPosition6.y = 850;
    Vector2 levelCntPosition7;
    levelCntPosition7.x = 320;
    levelCntPosition7.y = 850;
    Vector2 levelCntPosition8;
    levelCntPosition8.x = 320;
    levelCntPosition8.y = 850;
    Vector2 levelCntPosition9;
    levelCntPosition9.x = 320;
    levelCntPosition9.y = 850;

    Vector2 levelCntPosition11;
    levelCntPosition11.x = 320;
    levelCntPosition11.y = 850;
    Vector2 levelCntPosition12;
    levelCntPosition12.x = 320;
    levelCntPosition12.y = 850;
    Vector2 levelCntPosition13;
    levelCntPosition13.x = 320;
    levelCntPosition13.y = 850;
    Vector2 levelCntPosition14;
    levelCntPosition14.x = 320;
    levelCntPosition14.y = 850;

    Vector2 levelCntPosition16;
    levelCntPosition16.x = 320;
    levelCntPosition16.y = 850;


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

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition2, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition3, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition4, WHITE);
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
            DrawTextureV(levelCntImage, levelCntPosition2, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition3, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition4, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition6, WHITE);
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
            DrawTextureV(levelCntImage, levelCntPosition3, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition4, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition6, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition7, WHITE);
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
            DrawTextureV(levelCntImage, levelCntPosition4, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition6, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition7, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition8, WHITE);
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
            DrawTextureV(levelCntImage, levelCntPosition6, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition7, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition8, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition9, WHITE);
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

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition2, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition3, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition4, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition6, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition7, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition8, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition9, WHITE);
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
            DrawTextureV(levelCntImage, levelCntPosition2, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition3, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition4, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition6, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition7, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition8, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition9, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition10, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition11, WHITE);
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
            DrawTextureV(levelCntImage, levelCntPosition3, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition4, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition6, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition7, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition8, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition9, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition10, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition11, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition12, WHITE);
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
            DrawTextureV(levelCntImage, levelCntPosition4, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition6, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition7, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition8, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition9, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition10, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition11, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition12, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition13, WHITE);
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
            DrawTextureV(levelCntImage, levelCntPosition6, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition7, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition8, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition9, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition10, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition11, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition12, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition13, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition14, WHITE);
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

            DrawTextureV(levelCntImage, levelCntPosition1, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition2, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition3, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition4, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition6, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition7, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition8, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition9, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition10, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition11, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition12, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition13, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition14, WHITE);
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
            DrawTextureV(levelCntImage, levelCntPosition2, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition3, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition4, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition5, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition6, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition7, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition8, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition9, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition10, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition11, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition12, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition13, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition14, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition15, WHITE);
            DrawTextureV(levelCntImage, levelCntPosition16, WHITE);
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
            map2->Draw();

            if (map2->gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (map2->nextLevel == true) {
                map2->nextLevel = false;
                currentScreen = LEVEL3;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", map2->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  2"), 88, 850, 30, WHITE);
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
            DrawText(TextFormat("%i", map3->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  3"), 88, 850, 30, WHITE);
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
            DrawText(TextFormat("%i", map4->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  4"), 88, 850, 30, WHITE);
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
            DrawText(TextFormat("%i", map5->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  5"), 88, 850, 30, WHITE);
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
            DrawText(TextFormat("%i", map6->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  6"), 88, 850, 30, WHITE);
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
            DrawText(TextFormat("%i", map7->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  7"), 88, 850, 30, WHITE);
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
            DrawText(TextFormat("%i", map8->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  8"), 88, 850, 30, WHITE);
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
            DrawText(TextFormat("%i", map9->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  9"), 88, 850, 30, WHITE);
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
            DrawText(TextFormat("%i", map10->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  10"), 88, 850, 30, WHITE);
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
            DrawText(TextFormat("%i", map11->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  11"), 88, 850, 30, WHITE);
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
            DrawText(TextFormat("%i", map12->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  12"), 88, 850, 30, WHITE);
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
            DrawText(TextFormat("%i", map13->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  13"), 88, 850, 30, WHITE);
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
            DrawText(TextFormat("%i", map14->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  14"), 88, 850, 30, WHITE);
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
            DrawText(TextFormat("%i", map15->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  15"), 88, 850, 30, WHITE);
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
            DrawText(TextFormat("%i", map16->GetScore()), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  16"), 88, 850, 30, WHITE);
        } break;
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

