#include "Pengo.hpp"
#include<raylib.h>
#include <algorithm>


Pengo::Pengo()
{
    image = LoadTexture("Graphics/Pengo front.png");
    position.x = 400;
    position.y = 400;
    speed = 5;
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
    }

    else if (IsKeyDown(KEY_LEFT)) {
        position.x -= speed;
        position.x = std::max(position.x, );
    }

    else if (IsKeyDown(KEY_UP)) {
        position.y -= speed;
    }

    else if (IsKeyDown(KEY_DOWN)) {
        position.y += speed;
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
