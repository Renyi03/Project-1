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

typedef enum GameScreen { INITIAL, TITLE, LEVEL1, LEVEL2, GAMEOVER, POINTS } GameScreen;
bool gameOver = false;
bool nextLevel = false;
int lives = 5;

int main(void)
{
    InitWindow(800, 800, "El mejor juego de proyecto 1: An indescribable emptiness");
    InitAudioDevice();
    SetTargetFPS(60);

    std::string map1file = LoadFileText("resources/Map_1.txt");
    std::string map2file = LoadFileText("resources/Map_2.txt");

    Rectangle borderTop = Rectangle{ 88, 30, 624, 10 };
    Rectangle borderBottom = Rectangle{ 88, 760, 624, 10 };
    Rectangle borderLeft = Rectangle{ 78, 40, 10, 720 };
    Rectangle borderRight = Rectangle{ 712, 40, 10, 720 };
    Rectangle border{88, 40, 624, 720};
    Map* map1 = new Map{ border, map1file };
    Map* map2 = new Map{ border, map2file };
    /*Pengo pengo{ border, &map };*/
    /*map.pengo = &pengo;*/

    Texture2D lifeImage = LoadTexture("resources/Graphics/Pengo_life.png");

    Vector2 lifePosition1;
    lifePosition1.x = 15;
    lifePosition1.y = 38;

    Vector2 lifePosition2;
    lifePosition2.x = 15;
    lifePosition2.y = 86;

    Vector2 lifePosition3;
    lifePosition3.x = 15;
    lifePosition3.y = 134;

    Vector2 lifePosition4;
    lifePosition4.x = 15;
    lifePosition4.y = 182;


    Texture2D levelCntImage = LoadTexture("resources/Graphics/level cnt.png");
    Vector2 levelCntPosition;
    levelCntPosition.x = 15;
    levelCntPosition.y = 700;

    srand(time(NULL));
 
    GameScreen currentScreen = INITIAL;

    Music Main_BGM = LoadMusicStream("resources/Pengo_Music/Main_BGM_(Popcorn).wav");

    PlayMusicStream(Main_BGM);

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
            DrawTextureV(levelCntImage, levelCntPosition, WHITE);

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
            DrawTextureV(levelCntImage, levelCntPosition, WHITE);
        }break;
        case GAMEOVER:
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {

                delete map1;
                map1 = new Map{ border, map1file };
                delete map2;
                map2 = new Map{ border, map2file };
                gameOver = false;
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
            DrawRectangle(0, 0, 800, 800, BLUE);
            DrawText("TITLE SCREEN", 20, 20, 40, DARKBLUE);
            DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKBLUE);

        } break;
        case LEVEL1:
        {
            map1->Draw();

            if (gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (nextLevel == true) {
                nextLevel = false;
                currentScreen = LEVEL2;
            }
            DrawTextureV(levelCntImage, levelCntPosition, WHITE);

            DrawText(TextFormat("1P"), 30, 2, 20, BLUE);
            DrawText(TextFormat("%i", map1->GetScore()), 200, 2, 20, WHITE);
        } break;
        case LEVEL2:
        {
            map2->Draw();

            if (gameOver == true) {
                currentScreen = GAMEOVER;
            }

            if (nextLevel == true) {
                nextLevel = false;
                currentScreen = GAMEOVER;
            }

            DrawTextureV(levelCntImage, levelCntPosition, WHITE);

            DrawText(TextFormat("1P"), 30, 2, 20, BLUE);
            DrawText(TextFormat("%i", map2->GetScore()), 200, 2, 20, WHITE);
        } break;
        case GAMEOVER:
        {
            DrawRectangle(0, 0, 800, 800, BLUE);
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

