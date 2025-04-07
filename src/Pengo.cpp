#include "Pengo.hpp"
#include<raylib.h>
#include <algorithm>
#include <raymath.h>


Pengo::Pengo(Rectangle screenBorder, Map* map)
{
    image = LoadTexture("resources/Graphics/Pengo front.png");
    position.x = 376;
    position.y = 328;
    target_position = position;
    speed = 2;
    border = screenBorder;
    currentMap = map;
}

Pengo::~Pengo()
{
	UnloadTexture(image);
}

void Pengo::Draw() {
	DrawTextureV(image, position, WHITE);
}

void Pengo::Update() {
    
    
    if (position.x == target_position.x && position.y == target_position.y) {
        if (IsKeyDown(KEY_RIGHT)) {
            bool isBlock{};
            Vector2 v{ position.x + 48, position.y };
            auto& blocks = currentMap->GetBlocks();
            for (int i = 0; i < blocks.size(); ++i) {
                auto& b = blocks[i];
                if (b.rect.x == v.x && b.rect.y == v.y) {
                    isBlock = true;
                    break;
                }
            }

            if (!isBlock) {
                target_position.x = v.x;
                target_position.y = v.y;
            }

            start_position = position;
            amount = 0;
            
        }

        else if (IsKeyDown(KEY_LEFT)) {
            target_position.x = position.x - 48;
            target_position.y = position.y;
            start_position = position;
            amount = 0;
            
        }

        else if (IsKeyDown(KEY_UP)) {
            target_position.y = position.y - 48;
            target_position.x = position.x;
            start_position = position;
            amount = 0;
            
        }

        else if (IsKeyDown(KEY_DOWN)) {
            target_position.y = position.y + 48;
            target_position.x = position.x;
            start_position = position;
            amount = 0;
         
        }
    }

    else {
        float s = speed * GetFrameTime();
        amount += s;
        position = Vector2Lerp(start_position, target_position, amount);
        if (amount >= 1) {
            position = target_position;
        }
        if (position.y + image.height > border.y + border.height) {
            position.y = border.y + border.height - image.height;
            target_position.y = position.y;
        }
        if (position.y < border.y) {
            position.y = border.y;
            target_position.y = position.y;
        }
        if (position.x < border.x) {
            position.x = border.x;
            target_position.x = position.x;
        }
        if (position.x + image.width > border.x + border.width) {
            position.x = border.x + border.width - image.width;
            target_position.x = position.x;
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
