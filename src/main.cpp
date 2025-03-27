#include "raylib.h"
#include "Pengo.hpp"
#include "Map.hpp"

typedef enum GameScreen { INITIAL, TITLE, GAMEPLAY, POINTS } GameScreen;

int main(void)
{
    InitWindow(800, 800, "El mejor juego de proyecto 1: An indescribable emptiness");
    SetTargetFPS(60);

    
    Rectangle borderTop = Rectangle{ 88, 30, 624, 10 };
    Rectangle borderBottom = Rectangle{ 88, 760, 624, 10 };
    Rectangle borderLeft = Rectangle{ 78, 40, 10, 720 };
    Rectangle borderRight = Rectangle{ 712, 40, 10, 720 };
    Rectangle border{88, 40, 624, 720};
    Pengo pengo{border};
    Map map{};

    
    GameScreen currentScreen = INITIAL;

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
            pengo.Update();
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
            DrawText("PENGO PROTOTYPE", 20, 20, 40, LIGHTGRAY);
            DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);

        } break;
        case TITLE:
        {
            // TODO: Draw TITLE screen here!
            DrawRectangle(0, 0, 800, 800, GREEN);
            DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
            DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);

        } break;
        default: break;
        }
         

        
        

        EndDrawing();


    }

    CloseWindow();


    return 0;
}

