#include "raylib.h"
#include "Pengo.hpp"
#include "Map.hpp"

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

    //Game Loop

    while (WindowShouldClose() == false) {

        pengo.Update();
        bool isColliding = CheckCollisionRecs(pengo.GetRect(), borderTop);
        BeginDrawing();
        ClearBackground(BLACK);

        DrawRectangleLinesEx(borderTop, 10, BLUE);
        DrawRectangleLinesEx(borderBottom, 10, BLUE);
        DrawRectangleLinesEx(borderLeft, 10, BLUE);
        DrawRectangleLinesEx(borderRight, 10, BLUE);

        pengo.Draw();
        
        pengo.DrawHitbox(isColliding);
        

        EndDrawing();


    }

    CloseWindow();


    return 0;
}

