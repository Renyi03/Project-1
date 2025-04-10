#include "Pengo.hpp"
#include<raylib.h>
#include <algorithm>
#include <raymath.h>


Pengo::Pengo(Rectangle screenBorder, Map* map)
{
    borderTop = Rectangle{ 88, 30, 624, 10 };
    borderBottom = Rectangle{ 88, 760, 624, 10 };
    borderLeft = Rectangle{ 78, 40, 10, 720 };
    borderRight = Rectangle{ 712, 40, 10, 720 };
    image = LoadTexture("resources/Graphics/Pengo front.png");
    position.x = 376;
    position.y = 328;
    target_position = position;
    speed = 2;
    speed = 10;
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
<<<<<<< Updated upstream

            

            if (position.x + image.width + 48 > border.x + border.width) {
                position.x = border.x - image.width;
=======
            if (position.x + image.width > borderRight.x - 48) {
                position.x = borderRight.x - image.width;
>>>>>>> Stashed changes
                target_position = position;
                
            }
        }

        else if (IsKeyDown(KEY_LEFT)) {
            target_position.y = position.y;
            bool isBlock{};
            Vector2 v{ position.x - 48, position.y };
            std::cout << v.x << " ; " << v.y << std::endl;
            auto& blocks = currentMap->GetBlocks();
            for (int i = 0; i < blocks.size(); ++i) {
                auto& b = blocks[i];
                if (i == blocks.size() - 2) {
                    std::cout << b.rect.x << " ; " << b.rect.y << std::endl;
                }
                
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
<<<<<<< Updated upstream

            

            if (position.x - 48 < border.x) {
                position.x = border.x;
=======
            if (position.x - 48 < borderLeft.x + borderLeft.width) {
                position.x = borderLeft.x + borderLeft.width;
>>>>>>> Stashed changes
                target_position = position;
            }
        }

        else if (IsKeyDown(KEY_UP)) {
            Vector2 v{ position.x, position.y - 48 };
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
<<<<<<< Updated upstream

            if (position.y < border.y) {
                position.y = border.y;
                target_position.y = position.y - 48;
=======
            if (position.y <= borderTop.y - borderTop.height + 48) {
                position.y = borderTop.y + borderTop.height;
                target_position.y = position.y;
>>>>>>> Stashed changes
                target_position.x = position.x;
            }
        }

        else if (IsKeyDown(KEY_DOWN)) {
            
            bool isBlock{};
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
<<<<<<< Updated upstream

            if (position.y + image.height > border.y + border.height + 48) {
                position.y = border.y + border.height - image.height;
                target_position.y = position.y + 48;
=======
            if (position.y + image.height >= borderBottom.y) {
                position.y = borderBottom.y - image.height;
                target_position.y = position.y;
>>>>>>> Stashed changes
                target_position.x = position.x;
            }
        }
    }

    

    else {
        float s = speed * GetFrameTime();
        amount += s;
        position = Vector2Lerp(start_position, target_position, amount);
        if (amount >= 1) {
            position = target_position;
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
