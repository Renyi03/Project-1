#include "Pengo.hpp"
#include <raylib.h>
#include <algorithm>
#include <raymath.h>
#include <iostream>
#include "Map.hpp"
#include "Block.hpp"
#include "SnoBee.hpp"
using namespace std;

Pengo::Pengo(Rectangle screenBorder, Map* map, SnoBee* snobee)
{
    borderTop = Rectangle{ 88, 80, 624, 10 };
    borderBottom = Rectangle{ 88, 810, 624, 10 };
    borderLeft = Rectangle{ 78, 90, 10, 720 };
    borderRight = Rectangle{ 712, 90, 10, 720 };
    image = LoadTexture("resources/Graphics/Pengo front.png");
    position.x = 376;
    position.y = 378;
    target_position = position;
    speed = 3;
    border = screenBorder;
    currentMap = map;
    snoBee = snobee;
    timer = 4;
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
                if (b.isActive == true && b.rect.x == v.x && b.rect.y == v.y) {
                    isBlock = true;
                    Vector2 v2{ position.x + 96, position.y };
                    bool isBlockAdjacent{};
                    for (int j = 0; j < blocks.size(); ++j) {
                        auto& b2 = blocks[j];
                        if ((b2.isActive == true && b2.rect.x == v2.x && b2.rect.y == v2.y) || (b.rect.x + image.width > borderRight.x - 48)) {
                            isBlockAdjacent = true;
                            b.isActive = false;
                            PlaySound(b.Ice_Block_Destroyed);
                            break;
                        }                       
                    }
                    if (!isBlockAdjacent) {
                        bool blockCollision = CheckCollisionRecs(b.rect, snoBee->GetRect());
                        b.direction = Block::MovingDirection::right;
                        PlaySound(b.Push_Ice_Block);
                        if (blockCollision == true) {
                            snoBee->isActive = false;
                        }
                    }                   
                    break;
                }
            }

            if (!isBlock) {
                target_position.x = v.x;
                target_position.y = v.y;
            }

            start_position = position;
            amount = 0;
            if (position.x + image.width > borderRight.x - 48) {
                position.x = borderRight.x - image.width;
                target_position = position;

                if (snoBee->position.x + image.width == borderRight.x && position.x + image.width > borderRight.x - 48) {
                    snoBee->isStunned = true;
                }
            }
            
        }

        else if (IsKeyDown(KEY_LEFT)) {

            bool isBlock{};
            Vector2 v{ position.x - 48, position.y };
            auto& blocks = currentMap->GetBlocks();
            for (int i = 0; i < blocks.size(); ++i) {
                auto& b = blocks[i];
                if (b.isActive == true && b.rect.x == v.x && b.rect.y == v.y) {
                    isBlock = true;
                    Vector2 v2{ position.x - 96, position.y };
                    bool isBlockAdjacent{};
                    for (int j = 0; j < blocks.size(); ++j) {
                        auto& b2 = blocks[j];
                        if ((b2.isActive == true && b2.rect.x == v2.x && b2.rect.y == v2.y) || (b.rect.x - 48 < borderLeft.x + borderLeft.width)) {
                            isBlockAdjacent = true;
                            b.isActive = false;
                            PlaySound(b.Ice_Block_Destroyed);
                            break;
                        }
                    }
                    if (!isBlockAdjacent) {
                        bool blockCollision = CheckCollisionRecs(b.rect, snoBee->GetRect());
                        b.direction = Block::MovingDirection::left;
                        PlaySound(b.Push_Ice_Block);
                        if (blockCollision == true) {
                            snoBee->isActive = false;
                        }
                    }
                    break;
                }
            }

            if (!isBlock) {
                target_position.x = v.x;
                target_position.y = v.y;
            }


            start_position = position;
            amount = 0;
            if (position.x - 48 < borderLeft.x + borderLeft.width) {
                position.x = borderLeft.x + borderLeft.width;
                target_position = position;

                if (snoBee->position.x == borderLeft.x + borderLeft.width && position.x - 48 < borderLeft.x + borderLeft.width) {
                    snoBee->isStunned = true;
                    
                }
            }
        }

        else if (IsKeyDown(KEY_UP)) {

            bool isBlock{};
            Vector2 v{ position.x, position.y - 48 };
            auto& blocks = currentMap->GetBlocks();
            for (int i = 0; i < blocks.size(); ++i) {
                auto& b = blocks[i];
                if (b.isActive == true && b.rect.x == v.x && b.rect.y == v.y) {
                    isBlock = true;
                    Vector2 v2{ position.x, position.y - 96 };
                    bool isBlockAdjacent{};
                    for (int j = 0; j < blocks.size(); ++j) {
                        auto& b2 = blocks[j];
                        if ((b2.isActive == true && b2.rect.x == v2.x && b2.rect.y == v2.y) || (b.rect.y <= borderTop.y - borderTop.height + 48)) {
                            isBlockAdjacent = true;
                            b.isActive = false;
                            PlaySound(b.Ice_Block_Destroyed);
                            break;
                        }
                    }
                    if (!isBlockAdjacent) {
                        bool blockCollision = CheckCollisionRecs(b.rect, snoBee->GetRect());
                        b.direction = Block::MovingDirection::up;
                        PlaySound(b.Push_Ice_Block);
                        if (blockCollision == true) {
                            snoBee->isActive = false;
                        }
                    }
                    break;
                }
            }

            if (!isBlock) {
                target_position.x = v.x;
                target_position.y = v.y;
            }


            start_position = position;
            amount = 0;
            if (position.y <= borderTop.y - borderTop.height + 48) {
                position.y = borderTop.y + borderTop.height;
                target_position.y = position.y;
                target_position.x = position.x;

                if (snoBee->position.y == borderTop.y + borderTop.height && position.y <= borderTop.y - borderTop.height + 48) {
                    snoBee->isStunned = true;
                }
            }
        }

        else if (IsKeyDown(KEY_DOWN)) {

            bool isBlock{};
            Vector2 v{ position.x, position.y + 48 };
            auto& blocks = currentMap->GetBlocks();
            for (int i = 0; i < blocks.size(); ++i) {
                auto& b = blocks[i];
                if (b.isActive == true && b.rect.x == v.x && b.rect.y == v.y) {
                    isBlock = true;
                    Vector2 v2{ position.x, position.y + 96};
                    bool isBlockAdjacent{};
                    for (int j = 0; j < blocks.size(); ++j) {
                        auto& b2 = blocks[j];
                        if ((b2.isActive == true && b2.rect.x == v2.x && b2.rect.y == v2.y) || (b.rect.y + image.height >= borderBottom.y)) {
                            isBlockAdjacent = true;
                            b.isActive = false;
                            PlaySound(b.Ice_Block_Destroyed);
                            break;
                        }
                    }
                    if (!isBlockAdjacent) {
                        bool blockCollision = CheckCollisionRecs(b.rect, snoBee->GetRect());
                        b.direction = Block::MovingDirection::down;
                        PlaySound(b.Push_Ice_Block);
                        if (blockCollision == true) {
                            snoBee->isActive = false;
                        }
                    }
                    break;
                }
            }

            if (!isBlock) {
                target_position.x = v.x;
                target_position.y = v.y;
            }


            start_position = position;
            amount = 0;
            if (position.y + image.height >= borderBottom.y) {
                position.y = borderBottom.y - image.height;
                target_position.y = position.y;
                target_position.x = position.x;

                if (snoBee->position.y + image.height == borderBottom.y && position.y + image.height >= borderBottom.y) {
                    snoBee->isStunned = true;
                }
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

void Pengo::resetPosition() {
    position = respawn_position;
    target_position = respawn_position;
    start_position = respawn_position;
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

const Rectangle& Pengo::GetBorderRight() const
{
    return borderRight;
}

const Rectangle& Pengo::GetBorderLeft() const
{
    return borderLeft;
}

const Rectangle& Pengo::GetBorderTop() const
{
    return borderTop;
}

const Rectangle& Pengo::GetBorderBottom() const
{
    return borderBottom;
}