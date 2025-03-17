#include "Pengo.hpp"
#include<raylib.h>
#include <algorithm>


Pengo::Pengo(Rectangle screenBorder)
{
    image = LoadTexture("resources/Graphics/Pengo front.png");
    position.x = 400;
    position.y = 400;
    speed = 5;
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
    if (IsKeyDown(KEY_RIGHT)) {
        position.x += speed;
        if (position.x + image.width > border.x + border.width) {
            position.x = border.x + border.width - image.width;
        }
    }

    else if (IsKeyDown(KEY_LEFT)) {
        position.x -= speed;
        if (position.x < border.x) {
            position.x = border.x;
        }
    }

    else if (IsKeyDown(KEY_UP)) {
        position.y -= speed;
        if (position.y < border.y) {
            position.y = border.y;
        }
    }

    else if (IsKeyDown(KEY_DOWN)) {
        position.y += speed;
        if (position.y + image.height > border.y + border.height) {
            position.y = border.y + border.height - image.height;
        }
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
