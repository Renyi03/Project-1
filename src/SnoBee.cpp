#include "SnoBee.hpp"
#include <iostream>
#include <cstdlib> //To do the random movement
#include "Pengo.hpp"
#include <raylib.h>
#include <algorithm>
#include <raymath.h>
#include <iostream>
#include "Map.hpp"
#include "Block.hpp"
using namespace std;

SnoBee::SnoBee(Rectangle screenBorder, Map* map, Vector2 position)
{
	borderTop = Rectangle{ 88, 80, 624, 10 };
	borderBottom = Rectangle{ 88, 810, 624, 10 };
	borderLeft = Rectangle{ 78, 90, 10, 720 };
	borderRight = Rectangle{ 712, 90, 10, 720 };
	image = LoadTexture("resources/Graphics/Snobee.png");
	target_position = position;
    current_position = position;
	speed = 3;
	border = screenBorder;
	currentMap = map;
    isActive = true;
}

SnoBee::~SnoBee()
{
	UnloadTexture(image);
}

void SnoBee::Draw() {
    if (isActive == true) {
        DrawTextureV(image, current_position, WHITE);
    }
}

void SnoBee::Update() {
    if (!isActive) {
        return;
    }

	if (current_position.x == target_position.x && current_position.y == target_position.y) {
		int direction = rand() % 4 + 1;

		switch (direction) {
        case Block::MovingDirection::up: {

            bool isABlock{};
            Vector2 v3{ current_position.x, current_position.y - 48 };
            auto& blocks = currentMap->GetBlocks();
            for (int i = 0; i < blocks.size(); ++i) {
                auto& blck = blocks[i];
                if (blck.isActive == true && blck.rect.x == v3.x && blck.rect.y == v3.y) {
                    isABlock = true;
                    Vector2 v4{ current_position.x, current_position.y - 96 };
                    bool isABlockAdjacent{};
                    /*blck.isActive = false;*/ //ESTO SE VOLVERÁ A USAR!!!! para que rompa bloques
                    /*for (int j = 0; j < blocks.size(); ++j) {
                        auto& blck2 = blocks[j];
                        if ((blck2.isActive == true && blck2.rect.x == v4.x && blck2.rect.y == v4.y) || (blck.rect.y <= borderTop.y - borderTop.height + 48)) {
                            isABlockAdjacent = true;
                            
                            break;
                        }
                    }*/
                    /*if (!isABlockAdjacent) {
                        blck.direction = Block::MovingDirection::up;
                    }*/
                    break;
                }
            }

            if (!isABlock) {
                target_position.x = v3.x;
                target_position.y = v3.y;
            }

            start_position = current_position;
            amount = 0;
            if (current_position.y <= borderTop.y - borderTop.height + 48) {
                current_position.y = borderTop.y + borderTop.height;
                target_position.y = current_position.y;
                target_position.x = current_position.x;
            }
            break;
        }
        
        case Block::MovingDirection::down:{
			
            bool isABlock{};
            Vector2 v3{ current_position.x, current_position.y + 48 };
            auto& blocks = currentMap->GetBlocks();
            for (int i = 0; i < blocks.size(); ++i) {
                auto& blck = blocks[i];
                if (blck.isActive == true && blck.rect.x == v3.x && blck.rect.y == v3.y) {
                    isABlock = true;
                    Vector2 v4{ current_position.x, current_position.y + 96 };
                    bool isABlockAdjacent{};
                    /*blck.isActive = false;*/
                    /*for (int j = 0; j < blocks.size(); ++j) {
                        auto& blck2 = blocks[j];
                        if ((blck2.isActive == true && blck2.rect.x == v4.x && blck2.rect.y == v4.y) || (blck.rect.y + image.height >= borderBottom.y)) {
                            isABlockAdjacent = true;
                           
                            break;
                        }
                    }
                    /*if (!isABlockAdjacent) {
                        blck.direction = Block::MovingDirection::down;
                    }*/
                    break;
                }
            }

            if (!isABlock) {
                target_position.x = v3.x;
                target_position.y = v3.y;
            }

            start_position = current_position;
            amount = 0;
            if (current_position.y + image.height >= borderBottom.y) {
                current_position.y = borderBottom.y - image.height;
                target_position.y = current_position.y;
                target_position.x = current_position.x;
            }
			break;
        }
        case Block::MovingDirection::left:{
			
            bool isABlock{};
            Vector2 v3{ current_position.x - 48, current_position.y };
            auto& blocks = currentMap->GetBlocks();
            for (int i = 0; i < blocks.size(); ++i) {
                auto& blck = blocks[i];
                if (blck.isActive == true && blck.rect.x == v3.x && blck.rect.y == v3.y) {
                    isABlock = true;
                    Vector2 v4{ current_position.x - 96, current_position.y };
                    bool isABlockAdjacent{};
                   /* blck.isActive = false;*/
                    /*for (int j = 0; j < blocks.size(); ++j) {
                        auto& blck2 = blocks[j];
                        if ((blck2.isActive == true && blck2.rect.x == v4.x && blck2.rect.y == v4.y) || (blck.rect.x - 48 < borderLeft.x + borderLeft.width)) {
                            isABlockAdjacent = true;
                            
                            break;
                        }
                    }*/
                    /*if (!isABlockAdjacent) {
                        blck.direction = Block::MovingDirection::left;
                    }*/
                    break;
                }
            }

            if (!isABlock) {
                target_position.x = v3.x;
                target_position.y = v3.y;
            }

            start_position = current_position;
            amount = 0;
            if (current_position.x - 48 < borderLeft.x + borderLeft.width) {
                current_position.x = borderLeft.x + borderLeft.width;
                target_position = current_position;
            }
			break;
        }
        case Block::MovingDirection::right:{
			
            bool isABlock{};
            Vector2 v3{ current_position.x + 48, current_position.y };
            auto& blocks = currentMap->GetBlocks();
            for (int i = 0; i < blocks.size(); ++i) {
                auto& blck = blocks[i];
                if (blck.isActive == true && blck.rect.x == v3.x && blck.rect.y == v3.y) {
                    isABlock = true;
                    Vector2 v4{ current_position.x + 96, current_position.y };
                    bool isABlockAdjacent{};
                    /*blck.isActive = false;*/
                    /*for (int j = 0; j < blocks.size(); ++j) {
                        auto& blck2 = blocks[j];
                        if ((blck2.isActive == true && blck2.rect.x == v4.x && blck2.rect.y == v4.y) || (blck.rect.x + image.width > borderRight.x - 48)) {
                            isABlockAdjacent = true;
                            
                            break;
                        }
                    }*/
                    /*if (!isABlockAdjacent) {
                        blck.direction = Block::MovingDirection::right;
                    }*/

                    break;
                }
            }

            if (!isABlock) {
                target_position.x = v3.x;
                target_position.y = v3.y;
            }

            start_position = current_position;
            amount = 0;
            if (current_position.x + image.width > borderRight.x - 48) {
                current_position.x = borderRight.x - image.width;
                target_position = current_position;
            }
			break;
        }		
        }
    }
    else {
        float s = speed * GetFrameTime();
        amount += s;
        current_position = Vector2Lerp(start_position, target_position, amount);
        if (amount >= 1) {
            current_position = target_position;
        }
    }
}

Rectangle SnoBee::GetRect()
{
    if (!isActive) {
        return Rectangle{ 0, 0, 0, 0 };
    }
    return Rectangle{ current_position.x, current_position.y, float(image.width), float(image.height) };
}

void SnoBee::DrawHitbox(bool isColliding)
{
    Color outlineColor = isColliding ? RED : WHITE;
    DrawRectangleLinesEx(GetRect(), 3, outlineColor);
}

const Rectangle& SnoBee::GetBorderRight() const
{
    return borderRight;
}

const Rectangle& SnoBee::GetBorderLeft() const
{
    return borderLeft;
}

const Rectangle& SnoBee::GetBorderTop() const
{
    return borderTop;
}

const Rectangle& SnoBee::GetBorderBottom() const
{
    return borderBottom;
}