#include "raylib.h"

int main(void)
{
    int ballX = 400;
    int ballY = 400;
    InitWindow(800, 800, "El mejor juego de proyecto 1: An indescribable emptiness");
    SetTargetFPS(60);

    //Game Loop

    while (WindowShouldClose() == false) {

        // 1. Event handling
        if (IsKeyDown(KEY_RIGHT)) {
            ballX += 3;
        }

        else if (IsKeyDown(KEY_LEFT)) {
            ballX -= 3;
        }

        else if (IsKeyDown(KEY_UP)) {
            ballY -= 3;
        }

        else if (IsKeyDown(KEY_DOWN)) {
            ballY += 3;
        }

        // 2. Update positions


        // 3. Drawingggggg

        BeginDrawing();
        ClearBackground(BLACK);

        DrawRectangleLines(88, 40, 624, 720, BLUE);

        DrawCircle(ballX, ballY, 20, RED);

        EndDrawing();

        // 4. Collisions


    }

    CloseWindow();


    return 0;
}

