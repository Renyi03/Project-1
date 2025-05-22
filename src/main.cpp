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
#include <iostream>
using namespace std;

typedef enum GameScreen { INITIAL, TITLE, LEVEL1, LEVEL2, GAMEOVER, POINTS } GameScreen;

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

    std::string map1file = LoadFileText("resources/Map_1.txt");
    std::string map2file = LoadFileText("resources/Map_2.txt");

    Rectangle borderTop = Rectangle{ 88, 80, 624, 10 };
    Rectangle borderBottom = Rectangle{ 88, 810, 624, 10 };
    Rectangle borderLeft = Rectangle{ 78, 90, 10, 720 };
    Rectangle borderRight = Rectangle{ 712, 90, 10, 720 };
    Rectangle border{88, 90, 624, 720};
    Map* map1 = new Map{ border, map1file };
    Map* map2 = new Map{ border, map2file };
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

    srand(time(NULL));
 
    GameScreen currentScreen = INITIAL;

    Music Main_BGM = LoadMusicStream("resources/Pengo_Music/Main_BGM_(Popcorn).wav");

    //PlayMusicStream(Main_BGM);

    //Game Loop

    while (WindowShouldClose() == false) {

        totalScore = map1->GetScore() + map2->GetScore();

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
            level = 0;
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
            DrawTextureV(lifeImage, lifePosition1, WHITE);
            DrawTextureV(lifeImage, lifePosition2, WHITE);
            DrawTextureV(lifeImage, lifePosition3, WHITE);
            DrawTextureV(lifeImage, lifePosition4, WHITE);
        }break;
        case GAMEOVER:
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                delete map1;
                map1 = new Map{ border, map1file };
                delete map2;
                map2 = new Map{ border, map2file };
                map1->gameOver = false;
                map2->gameOver = false;
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
                currentScreen = POINTS;
            }

            DrawText(TextFormat("1P"), 120, 2, 30, BLUE);
            DrawText(TextFormat("%i", totalScore), 260, 2, 30, WHITE);
            DrawText(TextFormat("ACT  2"), 88, 850, 30, WHITE);
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
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

