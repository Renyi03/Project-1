#include "SnoBee.hpp"
#include <iostream>
#include <cstdlib> //To do the random movement
#include "Pengo.hpp"
#include <raylib.h>
#include <algorithm>
#include <raymath.h>
#include <iostream>
#include "Anims.hpp"
#include "Map.hpp"
#include "Block.hpp"
using namespace std;

SnoBee::SnoBee(Anims* anims, Rectangle screenBorder, Map* map, Vector2 position, Sound S_Snow_Bee_Squashed, Sound S_Snow_Bee_Stunned)
{
    Snow_Bee_Squashed = S_Snow_Bee_Squashed;
    Snow_Bee_Stunned = S_Snow_Bee_Stunned;

	borderTop = Rectangle{ 88, 80, 624, 10 };
	borderBottom = Rectangle{ 88, 810, 624, 10 };
	borderLeft = Rectangle{ 78, 90, 10, 720 };
	borderRight = Rectangle{ 712, 90, 10, 720 };
	targetPosition = position;
    currentPosition = position;
	speed = 3;
	border = screenBorder;
	currentMap = map;
    isActive = true;
    isStunned = false;
    breakingMode = false;
    breakCooldown = 0.0f;
    animations = anims;

    leftFramesCtr = 0;
    rightFramesCtr = 0;
    upFramesCtr = 0;
    downFramesCtr = 0;
    stunFramesCtr = 0;
    breakLeftFramesCtr = 0;
    breakRightFramesCtr = 0;
    breakUpFramesCtr = 0;
    breakDownFramesCtr = 0;

    currentLeftX = 0;
    currentRightX = 0;
    currentUpX = 0;
    currentDownX = 0;
    currentStunX = 0;
    currentBreakLeftX = 0;
    currentBreakRightX = 0;
    currentBreakUpX = 0;
    currentBreakDownX = 0;

    leftFrameRec = { 0, 0, 48, 48 };
    rightFrameRec = { 0, 0, 48, 48 };
    upFrameRec = { 0, 0, 48, 48 };
    downFrameRec = { 0, 0, 48, 48 };
    stunFrameRec = { 0, 0, 48, 48 };
    breakLeftFrameRec = { 0, 0, 48, 48 };
    breakRightFrameRec = { 0, 0, 48, 48 };
    breakUpFrameRec = { 0, 0, 48, 48 };
    breakDownFrameRec = { 0, 0, 48, 48 };
}

SnoBee::~SnoBee()
{
}

int SnoBee::countSurroundingBlocks() { //Function for letting the snobees know how many blocks they have arround them
    auto& blocks = currentMap->GetBlocks();
    int ctr = 0;
    Vector2 directions[4] = { {48, 0}, {-48, 0}, {0, -48}, {0, 48} }; //Right, left, up, down
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
    if (breakingMode == true) { //Breaking mode
        if (direction == 3) { //Breaking mode left
            breakLeftFramesCtr++;
            if (breakLeftFramesCtr > 10) {
                breakLeftFramesCtr = 0;
                if (currentBreakLeftX == 0) {
                    currentBreakLeftX = 1;
                }
                else if (currentBreakLeftX == 1) {
                    currentBreakLeftX = 0;
                }
            }
            breakLeftFrameRec.x = currentBreakLeftX * 48;
            DrawTextureRec(animations->imgSnobeeBreakLeft, breakLeftFrameRec, { currentPosition.x, currentPosition.y }, WHITE);

        }
        else if (direction == 4) { //Breaking mode right
            breakRightFramesCtr++;
            if (breakRightFramesCtr > 10) {
                breakRightFramesCtr = 0;
                if (currentBreakRightX == 0) {
                    currentBreakRightX = 1;
                }
                else if (currentBreakRightX == 1) {
                    currentBreakRightX = 0;
                }
            }
            breakRightFrameRec.x = currentBreakRightX * 48;
            DrawTextureRec(animations->imgSnobeeBreakRight, breakRightFrameRec, { currentPosition.x, currentPosition.y }, WHITE);
        }
        else if (direction == 1) { //Breaking mode up
            breakUpFramesCtr++;
            if (breakUpFramesCtr > 10) {
                breakUpFramesCtr = 0;
                if (currentBreakUpX == 0) {
                    currentBreakUpX = 1;
                }
                else if (currentBreakUpX == 1) {
                    currentBreakUpX = 0;
                }
            }
            breakUpFrameRec.x = currentBreakUpX * 48;
            DrawTextureRec(animations->imgSnobeeBreakUp, breakUpFrameRec, { currentPosition.x, currentPosition.y }, WHITE);
        }
        else if (direction == 2) { //Breaking mode down
            breakDownFramesCtr++;
            if (breakDownFramesCtr > 5) {
                breakDownFramesCtr = 0;
                if (currentBreakDownX == 0) {
                    currentBreakDownX = 1;
                }
                else if (currentBreakDownX == 1) {
                    currentBreakDownX = 0;
                }
            }
            breakDownFrameRec.x = currentBreakDownX * 48;
            DrawTextureRec(animations->imgSnobeeBreakDown, breakDownFrameRec, { currentPosition.x, currentPosition.y }, WHITE);
        }
        else if (direction == 0) { //Stunned while breaking
            stunFramesCtr++;
            if (stunFramesCtr > 10) {
                stunFramesCtr = 0;
                if (currentStunX == 0) {
                    currentStunX = 1;
                }
                else if (currentStunX == 1) {
                    currentStunX = 0;
                }
            }
            stunFrameRec.x = currentStunX * 48;
            DrawTextureRec(animations->imgSnobeeStunned, stunFrameRec, { currentPosition.x, currentPosition.y }, WHITE);
        }
    }

    else { //Not breaking mode
        if (direction == 3) { //Moving left
            leftFramesCtr++;
            if (leftFramesCtr > 10) {
                leftFramesCtr = 0;
                if (currentLeftX == 0) {
                    currentLeftX = 1;
                }
                else if (currentLeftX == 1) {
                    currentLeftX = 0;
                }
            }
            leftFrameRec.x = currentLeftX * 48;
            DrawTextureRec(animations->imgSnobeeLeft, leftFrameRec, { currentPosition.x, currentPosition.y }, WHITE);

        }
        else if (direction == 4) { //Moving right
            rightFramesCtr++;
            if (rightFramesCtr > 10) {
                rightFramesCtr = 0;
                if (currentRightX == 0) {
                    currentRightX = 1;
                }
                else if (currentRightX == 1) {
                    currentRightX = 0;
                }
            }
            rightFrameRec.x = currentRightX * 48;
            DrawTextureRec(animations->imgSnobeeRight, rightFrameRec, { currentPosition.x, currentPosition.y }, WHITE);
        }
        else if (direction == 1) { //Moving up
            upFramesCtr++;
            if (upFramesCtr > 10) {
                upFramesCtr = 0;
                if (currentUpX == 0) {
                    currentUpX = 1;
                }
                else if (currentUpX == 1) {
                    currentUpX = 0;
                }
            }
            upFrameRec.x = currentUpX * 48;
            DrawTextureRec(animations->imgSnobeeUp, upFrameRec, { currentPosition.x, currentPosition.y }, WHITE);
        }
        else if (direction == 2) { //Moving down
            downFramesCtr++;
            if (downFramesCtr > 5) {
                downFramesCtr = 0;
                if (currentDownX == 0) {
                    currentDownX = 1;
                }
                else if (currentDownX == 1) {
                    currentDownX = 0;
                }
            }
            downFrameRec.x = currentDownX * 48;
            DrawTextureRec(animations->imgSnobeeDown, downFrameRec, { currentPosition.x, currentPosition.y }, WHITE);
        }
        else if (direction == 0) { //Stunned
            stunFramesCtr++;
            if (stunFramesCtr > 10) {
                stunFramesCtr = 0;
                if (currentStunX == 0) {
                    currentStunX = 1;
                }
                else if (currentStunX == 1) {
                    currentStunX = 0;
                }
            }
            stunFrameRec.x = currentStunX * 48;
            DrawTextureRec(animations->imgSnobeeStunned, stunFrameRec, { currentPosition.x, currentPosition.y }, WHITE);
        }
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
            auto surroundingBlocks = countSurroundingBlocks();
            if (!breakingMode && surroundingBlocks >= 3) { //If the snobee is surrounded by 3 blocks or more, it will enter the breaking mode state
                breakingMode = true;
            }
            direction = rand() % 4 + 1; //Random movement of the snobees

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

                if (currentPosition.y + 48 >= borderBottom.y) { //Make the snobee unable of trespassing a border
                    currentPosition.y = borderBottom.y - 48;
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
                if (currentPosition.x + 48 > borderRight.x - 48) { //Make the snobee unable of trespassing a border
                    currentPosition.x = borderRight.x - 48;
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
    return Rectangle{ currentPosition.x, currentPosition.y, float(48), float(48) };
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