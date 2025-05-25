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

SnoBee::SnoBee(Rectangle screenBorder, Map* map, Vector2 position, Texture2D img, Sound S_Snow_Bee_Squashed, Sound S_Snow_Bee_Stunned)
{
    Snow_Bee_Squashed = S_Snow_Bee_Squashed;
    Snow_Bee_Stunned = S_Snow_Bee_Stunned;

	borderTop = Rectangle{ 88, 80, 624, 10 };
	borderBottom = Rectangle{ 88, 810, 624, 10 };
	borderLeft = Rectangle{ 78, 90, 10, 720 };
	borderRight = Rectangle{ 712, 90, 10, 720 };
    image = img;
	targetPosition = position;
    currentPosition = position;
	speed = 3;
	border = screenBorder;
	currentMap = map;
    isActive = true;
    isStunned = false;
    breakingMode = false;
    breakCooldown = 0.0f;
}

SnoBee::~SnoBee()
{
}

int SnoBee::countSurroundingBlocks() { //Function for letting the snobees know how many blocks they have arround them
    auto& blocks = currentMap->GetBlocks();
    int ctr = 0;
    Vector2 directions[4] = { {48, 0}, {-48, 0}, {0, -48}, {0, 48} }; //Right, left, up, down directions
    for (auto& d : directions) {
        for (auto& b : blocks) {
            if (b.isActive && b.rect.x == currentPosition.x + d.x && b.rect.y == currentPosition.y + d.y) {
                ctr++;
            }
        }
    }
    return ctr;
}


void SnoBee::Draw() {
    if (isActive == true) {
       DrawTextureV(image, currentPosition, WHITE);
    }
}

void SnoBee::Update() {
    if (!isActive) {
        return;
    }

    if (breakCooldown > 0.0f) {
        breakCooldown -= GetFrameTime();
    }

    if (!isStunned) { //The snobee will do all this only if it is not stunned. If it is stunned, it will not do anything
        if (currentPosition.x == targetPosition.x && currentPosition.y == targetPosition.y) {
            auto i = countSurroundingBlocks();
            if (!breakingMode && i >= 3) { //If the snobee is surrounded by 3 blocks or more, it will enter the breaking mode state
                breakingMode = true;
            }
            int direction = rand() % 4 + 1;

            switch (direction) {
            case Block::MovingDirection::up: { //Actions when moving upwards

                bool isABlock{};
                Vector2 v3{ currentPosition.x, currentPosition.y - 48 };
                auto& blocks = currentMap->GetBlocks();
                for (int i = 0; i < blocks.size(); ++i) {
                    auto& blck = blocks[i];
                    if (blck.isActive == true && blck.rect.x == v3.x && blck.rect.y == v3.y) { //Perform only for an active block next to the snobee
                        isABlock = true;
                        if (breakingMode == true && breakCooldown <= 0.0f) {
                            if ((rand() % 4 + 1) == 1) { //There is a 25% chance of breaking a block if the snobee is in breaking mode state
                                breakCooldown = 3.0f;
                                blck.isActive = false;
                            }
                        }
                        break;
                    }
                }

                if (!isABlock) { //Move to the next position if there is not a block
                    targetPosition.x = v3.x;
                    targetPosition.y = v3.y;
                }

                startPosition = currentPosition;
                amount = 0;
                if (currentPosition.y <= borderTop.y - borderTop.height + 48) {  //Make the snobee unable of trespassing a border
                    currentPosition.y = borderTop.y + borderTop.height;
                    targetPosition.y = currentPosition.y;
                    targetPosition.x = currentPosition.x;
                }
                break;
            }

            case Block::MovingDirection::down: { //Actions when moving downwards

                bool isABlock{};
                Vector2 v3{ currentPosition.x, currentPosition.y + 48 };
                auto& blocks = currentMap->GetBlocks();
                for (int i = 0; i < blocks.size(); ++i) {
                    auto& blck = blocks[i];
                    if (blck.isActive == true && blck.rect.x == v3.x && blck.rect.y == v3.y) { //Perform only for an active block next to the snobee
                        isABlock = true;
                        if (breakingMode == true && breakCooldown <= 0.0f) {
                            if ((rand() % 4 + 1) == 1) { //There is a 25% chance of breaking a block if the snobee is in breaking mode state
                                breakCooldown = 3.0f;
                                blck.isActive = false;
                            }
                        }
                        break;
                    }
                }

                if (!isABlock) { //Move to the next position if there is not a block
                    targetPosition.x = v3.x;
                    targetPosition.y = v3.y;
                }

                startPosition = currentPosition;
                amount = 0;
                if (currentPosition.y + image.height >= borderBottom.y) { //Make the snobee unable of trespassing a border
                    currentPosition.y = borderBottom.y - image.height;
                    targetPosition.y = currentPosition.y;
                    targetPosition.x = currentPosition.x;
                }
                break;
            }
            case Block::MovingDirection::left: { //Actions when moving left

                bool isABlock{};
                Vector2 v3{ currentPosition.x - 48, currentPosition.y };
                auto& blocks = currentMap->GetBlocks();
                for (int i = 0; i < blocks.size(); ++i) {
                    auto& blck = blocks[i];
                    if (blck.isActive == true && blck.rect.x == v3.x && blck.rect.y == v3.y) { //Perform only for an active block next to the snobee
                        isABlock = true;
                        if (breakingMode == true && breakCooldown <= 0.0f) {
                            if ((rand() % 4 + 1) == 1) { //There is a 25% chance of breaking a block if the snobee is in breaking mode state
                                breakCooldown = 3.0f;
                                blck.isActive = false;
                            }
                        }
                        break;
                    }
                }

                if (!isABlock) { //Move to the next position if there is not a block
                    targetPosition.x = v3.x;
                    targetPosition.y = v3.y;
                }

                startPosition = currentPosition;
                amount = 0;
                if (currentPosition.x - 48 < borderLeft.x + borderLeft.width) { //Make the snobee unable of trespassing a border
                    currentPosition.x = borderLeft.x + borderLeft.width;
                    targetPosition = currentPosition;
                }
                break;
            }
            case Block::MovingDirection::right: { //Actions when moving right

                bool isABlock{};
                Vector2 v3{ currentPosition.x + 48, currentPosition.y };
                auto& blocks = currentMap->GetBlocks();
                for (int i = 0; i < blocks.size(); ++i) {
                    auto& blck = blocks[i];
                    if (blck.isActive == true && blck.rect.x == v3.x && blck.rect.y == v3.y) { //Perform only for an active block next to the snobee
                        isABlock = true;
                        if (breakingMode == true && breakCooldown <= 0.0f) {
                            if ((rand() % 4 + 1) == 1) { //There is a 25% chance of breaking a block if the snobee is in breaking mode state
                                breakCooldown = 3.0f;
                                blck.isActive = false;
                            }
                        }
                        break;
                    }
                }

                if (!isABlock) { //Move to the next position if there is not a block
                    targetPosition.x = v3.x;
                    targetPosition.y = v3.y;
                }

                startPosition = currentPosition;
                amount = 0;
                if (currentPosition.x + image.width > borderRight.x - 48) { //Make the snobee unable of trespassing a border
                    currentPosition.x = borderRight.x - image.width;
                    targetPosition = currentPosition;
                }
                break;
            }
            }
        }
        else { //Set the movment speed of the snobee
            float s = speed * GetFrameTime();
            amount += s;
            currentPosition = Vector2Lerp(startPosition, targetPosition, amount);
            if (amount >= 1) {
                currentPosition = targetPosition;
            }
        }
    }
}

Rectangle SnoBee::GetRect() //Get the position of a snobee
{
    if (!isActive) { //When a snobee is defeated, its position and size will set to 0
        return Rectangle{ 0, 0, 0, 0 };
    }
    return Rectangle{ currentPosition.x, currentPosition.y, float(image.width), float(image.height) };
}

void SnoBee::DrawHitbox(bool isColliding) //Draw the witbox of a snobee, red if colliding, white if not (only for debugging, not activated in the actual game)
{
    Color outlineColor = isColliding ? RED : WHITE;
    DrawRectangleLinesEx(GetRect(), 3, outlineColor);
}

const Rectangle& SnoBee::GetBorderRight() const //Get the right side of a snobee
{
    return borderRight;
}

const Rectangle& SnoBee::GetBorderLeft() const //Get the left side of a snobee
{
    return borderLeft;
}

const Rectangle& SnoBee::GetBorderTop() const //Get the top side of a snobee
{
    return borderTop;
}

const Rectangle& SnoBee::GetBorderBottom() const //Get the bottom side of a snobee
{
    return borderBottom;
}