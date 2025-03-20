#include "Pengo.hpp"
#include<raylib.h>
#include <algorithm>


Pengo::Pengo(Rectangle screenBorder)
{
    image = LoadTexture("resources/Graphics/Pengo front.png");
    position.x = 376;
    position.y = 328;
    speed = 96;
    border = screenBorder;
}

Pengo::~Pengo()
{
	UnloadTexture(image);
}

void Pengo::Draw() {
	DrawTextureV(image, position, WHITE);
}

void Pengo::Update() {
    float s = speed * GetFrameTime();
    
    if (position.x == target_position.x && position.y == target_position.y) {
        if (IsKeyDown(KEY_RIGHT)) {
            target_position.x = position.x + 48;
            target_position.y = position.y;
            if (position.x + image.width > border.x + border.width) {
                position.x = border.x + border.width - image.width;
            }
        }

        else if (IsKeyDown(KEY_LEFT)) {
            target_position.x = position.x - 48;
            target_position.y = position.y;
            if (position.x < border.x) {
                position.x = border.x;
            }
        }

        else if (IsKeyDown(KEY_UP)) {
            target_position.y = position.y + 48;
            target_position.x = position.x;
            if (position.y < border.y) {
                position.y = border.y;
            }
        }

        else if (IsKeyDown(KEY_DOWN)) {
            target_position.y = position.y - 48;
            target_position.x = position.x;
            if (position.y + image.height > border.y + border.height) {
                position.y = border.y + border.height - image.height;
            }
        }
    }
    else {

    }
}

Rectangle Pengo::GetRect()
{
    return Rectangle{position.x, position.y, float(image.width), float(image.height)};
}

void Pengo::DrawHitbox(bool isColliding)
{
    Color outlineColor = isColliding ? RED : WHITE;
    DrawRectangleLinesEx(GetRect(), 3, outlineColor);
}
