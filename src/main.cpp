#include "raylib.h"
#include "Pengo.hpp"
#include "Map.hpp"
#include "Block.hpp"
#include "SnoBee.hpp"
#include <ctime>

typedef enum GameScreen { INITIAL, TITLE, GAMEPLAY, POINTS } GameScreen;

int main(void)
{
    InitWindow(800, 800, "El mejor juego de proyecto 1: An indescribable emptiness");
    InitAudioDevice();
    SetTargetFPS(60);

    
    Rectangle borderTop = Rectangle{ 88, 30, 624, 10 };
    Rectangle borderBottom = Rectangle{ 88, 760, 624, 10 };
    Rectangle borderLeft = Rectangle{ 78, 40, 10, 720 };
    Rectangle borderRight = Rectangle{ 712, 40, 10, 720 };
    Rectangle border{88, 40, 624, 720};
    Map map{};
    Pengo pengo{border, &map};
    map.pengo = &pengo;
    SnoBee snoBee{ border, &map };
    map.snoBee = &snoBee;

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
        } break;
        case TITLE:
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                currentScreen = GAMEPLAY;
            }
        } break;
        case GAMEPLAY:
        {
            UpdateMusicStream(Main_BGM);
            pengo.Update();
            snoBee.Update();
            bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
            BeginDrawing();
            ClearBackground(BLACK);

            DrawRectangleLinesEx(borderTop, 10, BLUE);
            DrawRectangleLinesEx(borderBottom, 10, BLUE);
            DrawRectangleLinesEx(borderLeft, 10, BLUE);
            DrawRectangleLinesEx(borderRight, 10, BLUE);

            pengo.Draw();
            map.Draw();
            pengo.DrawHitbox(isColliding);
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
        default: break;
        }

        EndDrawing();
    }

    UnloadMusicStream(Main_BGM);
    CloseAudioDevice();

    CloseWindow();


    return 0;
}

