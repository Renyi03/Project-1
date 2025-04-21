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

    Texture2D lifeImage = LoadTexture("resources/Graphics/Pengo life 1.png");
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
            // TODO: Draw GAMEPLAY screen here!
            map1->Draw();

            if (gameOver == true) {
                currentScreen = GAMEOVER;
            }
        } break;
        case LEVEL2:
        {
            // TODO: Draw GAMEPLAY screen here!
            map2->Draw();

            if (gameOver == true) {
                currentScreen = GAMEOVER;
            }
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

