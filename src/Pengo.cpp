#include "Pengo.hpp"
#include <raylib.h>
#include <algorithm>
#include <raymath.h>
#include <iostream>
#include "Map.hpp"
#include "Block.hpp"
#include "SnoBee.hpp"
#include "Anims.hpp"
using namespace std;

Pengo::Pengo(Anims* anims, Rectangle screenBorder, Map* map, Sound S_Push_Outside_Walls)
{
    borderTop = Rectangle{ 88, 80, 624, 10 };
    borderBottom = Rectangle{ 88, 810, 624, 10 };
    borderLeft = Rectangle{ 78, 90, 10, 720 };
    borderRight = Rectangle{ 712, 90, 10, 720 };
    Push_Outside_Walls = S_Push_Outside_Walls;
    wallLeftFrameCtr = 0;
    wallRightFrameCtr = 0;
    wallUpFrameCtr = 0;
    wallDownFrameCtr = 0;
    wallCurrentLeftX = 0;
    wallCurrentRightX = 0;
    wallCurrentUpX = 0;
    wallCurrentDownX = 0;
    wallLeftFrameRec = { 0, 0, 20, 720 };
    wallRightFrameRec = { 0, 0, 20, 720 };
    wallUpFrameRec = { 0, 0, 1248, 10 };
    wallDownFrameRec = { 0, 0, 1248, 10 };
    position.x = 376;
    position.y = 378;
    targetPosition = position;
    speed = 1;
    border = screenBorder;
    currentMap = map;
    stunTimer = 0;
    stunDuration = 2.5;
    animations = anims;
    pengoDirection = 4;
    isPushing = false;
    leftFramesCtr = 0;
    rightFramesCtr = 0;
    upFramesCtr = 0;
    downFramesCtr = 0;
    pushLeftFramesCtr = 0;
    pushRightFramesCtr = 0;
    pushUpFramesCtr = 0;
    pushDownFramesCtr = 0;
    currentLeftX = 0;
    currentRightX = 0;
    currentUpX = 0;
    currentDownX = 0;
    currentPushLeftX = 0;
    currentPushRightX = 0;
    currentPushUpX = 0;
    currentPushDownX = 0;
    leftFrameRec = { 0, 0, 48, 48 };
    rightFrameRec = { 0, 0, 48, 48 };
    upFrameRec = { 0, 0, 48, 48 };
    downFrameRec = { 0, 0, 48, 48 };
    pushLeftFrameRec = { 0, 0, 48, 48 };
    pushRightFrameRec = { 0, 0, 48, 48 };
    pushUpFrameRec = { 0, 0, 48, 48 };
    pushDownFrameRec = { 0, 0, 48, 48 };
    isPushAnimationPlaying = false;
    pushAnimationTimer = 0.2f;
    pushAnimationDuration = 0.2f;
}

Pengo::~Pengo()
{
}

void Pengo::Draw() {
    if (IsKeyDown(KEY_LEFT)) {
        pengoDirection = 1;
        if (!isPushing) {
            leftFramesCtr++;
            if (leftFramesCtr > 12) {
                leftFramesCtr = 0;
                if (currentLeftX == 0) {
                    currentLeftX = 1;
                }
                else if (currentLeftX == 1) {
                    currentLeftX = 0;
                }
            }
            leftFrameRec.x = currentLeftX * 48;
            DrawTextureRec(animations->imgPengoLeft, leftFrameRec, { position.x, position.y }, WHITE);
        }
        else if (isPushAnimationPlaying) {
            pushAnimationTimer -= GetFrameTime();
            if (pushAnimationTimer <= 0.0f) {
                isPushAnimationPlaying = false;
                pushAnimationTimer = pushAnimationDuration;
            }
            pushLeftFramesCtr++;
            if (pushLeftFramesCtr > 12) {
                pushLeftFramesCtr = 0;
                if (currentPushLeftX == 0) {
                    currentPushLeftX = 1;
                }
                else if (currentPushLeftX == 1) {
                    currentPushLeftX = 0;
                }
          
            }
            pushLeftFrameRec.x = currentPushLeftX * 48;
            DrawTextureRec(animations->imgPengoPushLeft, pushLeftFrameRec, { position.x, position.y }, WHITE);
            return;
        }
        else if (isPushing) {
            isPushAnimationPlaying = true;
            pushAnimationTimer = pushAnimationDuration;
            pushLeftFramesCtr++;
            if (pushLeftFramesCtr > 12) {
                pushLeftFramesCtr = 0;
                if (currentPushLeftX == 0) {
                    currentPushLeftX = 1;
                }
                else if (currentPushLeftX == 1) {
                    currentPushLeftX = 0;
                }
            }
            pushLeftFrameRec.x = currentPushLeftX * 48;
            DrawTextureRec(animations->imgPengoPushLeft, pushLeftFrameRec, { position.x, position.y }, WHITE);
            isPushing = false;
            return;
        }           
    }
    else if (IsKeyDown(KEY_RIGHT)) {
        pengoDirection = 2;
        if (!isPushing) {
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
            DrawTextureRec(animations->imgPengoRight, rightFrameRec, { position.x, position.y }, WHITE);
        }
        else if (isPushAnimationPlaying) {
            pushAnimationTimer -= GetFrameTime();
            if (pushAnimationTimer <= 0.0f) {
                isPushAnimationPlaying = false;
                pushAnimationTimer = pushAnimationDuration;
            }
            pushRightFramesCtr++;
            if (pushRightFramesCtr > 12) {
                pushRightFramesCtr = 0;
                if (currentPushRightX == 0) {
                    currentPushRightX = 1;
                }
                else if (currentPushRightX == 1) {
                    currentPushRightX = 0;
                }
            }
            pushRightFrameRec.x = currentPushRightX * 48;
            DrawTextureRec(animations->imgPengoPushRight, pushRightFrameRec, { position.x, position.y }, WHITE);
            return;
        }
        else if (isPushing) {
            isPushAnimationPlaying = true;
            pushAnimationTimer = pushAnimationDuration;

            pushRightFramesCtr++;
            if (pushRightFramesCtr > 12) {
                pushRightFramesCtr = 0;
                if (currentPushRightX == 0) {
                    currentPushRightX = 1;
                }
                else if (currentPushRightX == 1) {
                    currentPushRightX = 0;
                }
            }
            pushRightFrameRec.x = currentPushRightX * 48;
            DrawTextureRec(animations->imgPengoPushRight, pushRightFrameRec, { position.x, position.y }, WHITE);
            isPushing = false;
            return;
        }

    }
    else if (IsKeyDown(KEY_UP)) {
        pengoDirection = 3;
        if (!isPushing) {
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
            DrawTextureRec(animations->imgPengoUp, upFrameRec, { position.x, position.y }, WHITE);
        }
        else if (isPushAnimationPlaying) {
            pushAnimationTimer -= GetFrameTime();
            if (pushAnimationTimer <= 0.0f) {
                isPushAnimationPlaying = false;
                pushAnimationTimer = pushAnimationDuration;
            }
            pushUpFramesCtr++;
            if (pushUpFramesCtr > 12) {
                pushUpFramesCtr = 0;
                if (currentPushUpX == 0) {
                    currentPushUpX = 1;
                }
                else if (currentPushUpX == 1) {
                    currentPushUpX = 0;
                }
            }
            pushUpFrameRec.x = currentPushUpX * 48;
            DrawTextureRec(animations->imgPengoPushUp, pushUpFrameRec, { position.x, position.y }, WHITE);
            return;
        }
        else if (isPushing) {
            isPushAnimationPlaying = true;
            pushAnimationTimer = pushAnimationDuration;
            pushUpFramesCtr++;
            if (pushUpFramesCtr > 12) {
                pushUpFramesCtr = 0;
                if (currentPushUpX == 0) {
                    currentPushUpX = 1;
                }
                else if (currentPushUpX == 1) {
                    currentPushUpX = 0;
                }
            }
            pushUpFrameRec.x = currentPushUpX * 48;
            DrawTextureRec(animations->imgPengoPushUp, pushUpFrameRec, { position.x, position.y }, WHITE);
            isPushing = false;
            return;
        }
    }
    else if (IsKeyDown(KEY_DOWN)) {
        pengoDirection = 4;
        if (!isPushing) {
            downFramesCtr++;
            if (downFramesCtr > 10) {
                downFramesCtr = 0;
                if (currentDownX == 0) {
                    currentDownX = 1;
                }
                else if (currentDownX == 1) {
                    currentDownX = 0;
                }
            }
            downFrameRec.x = currentDownX * 48;
            DrawTextureRec(animations->imgPengoDown, downFrameRec, { position.x, position.y }, WHITE);

        }
        else if (isPushAnimationPlaying) {
            pushDownFramesCtr++;
            if (pushDownFramesCtr > 12) {
                pushDownFramesCtr = 0;
                if (currentPushDownX == 0) {
                    currentPushDownX = 1;
                }
                else if (currentPushDownX == 1) {
                    currentPushDownX = 0;
                }
            }
            pushDownFrameRec.x = currentPushDownX * 48;
            DrawTextureRec(animations->imgPengoPushDown, pushDownFrameRec, { position.x, position.y }, WHITE);
            return;
        }
        else if (isPushing) {
            pushDownFramesCtr++;
            if (pushDownFramesCtr > 12) {
                pushDownFramesCtr = 0;
                if (currentPushDownX == 0) {
                    currentPushDownX = 1;
                }
                else if (currentPushDownX == 1) {
                    currentPushDownX = 0;
                }
            }
            pushDownFrameRec.x = currentPushDownX * 48;
            DrawTextureRec(animations->imgPengoPushDown, pushDownFrameRec, { position.x, position.y }, WHITE);
            isPushing = false;
            return;
        }
    }    
    else {
        if (pengoDirection == 1) {
            leftFrameRec.x = 48;
            DrawTextureRec(animations->imgPengoLeft, leftFrameRec, { position.x, position.y }, WHITE);
        }
        else if (pengoDirection == 2) {
            rightFrameRec.x = 48;
            DrawTextureRec(animations->imgPengoRight, rightFrameRec, { position.x, position.y }, WHITE);
        }
        else if (pengoDirection == 3) {
            upFrameRec.x = 0;
            DrawTextureRec(animations->imgPengoUp, upFrameRec, { position.x, position.y }, WHITE);
        }
        else if (pengoDirection == 4) {
            downFrameRec.x = 0;
            DrawTextureRec(animations->imgPengoDown, downFrameRec, { position.x, position.y }, WHITE);
        }
    }
}

void Pengo::Update() {
    for (auto& snobees : currentMap->GetSnoBees()) { //This will have checked every snobee of the vector of snobees every time there is a snobe.anything
        if (position.x == targetPosition.x && position.y == targetPosition.y) {
            if (IsKeyDown(KEY_RIGHT)) { //This will have checked every snobee of the vector of snobees every time there is a snobe.anything

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

                            if ((b2.isActive == true && b2.rect.x == v2.x && b2.rect.y == v2.y) || (b.rect.x + 48 > borderRight.x - 48)) { //Checks if the block has another block
                                isPushing = true;
                                isBlockAdjacent = true;
                                b.isActive = false; //Destroys the block
                                PlaySound(b.iceBlock_Destroyed);
                                currentMap->addScore(30); //Adds 30 points to the score for breaking a block
                                break;
                            }
                        }
                        if (!isBlockAdjacent) {
                            isPushing = true;
                            bool blockCollision = CheckCollisionRecs(b.rect, snobees.GetRect());
                            b.direction = Block::MovingDirection::right; //Move the block
                            PlaySound(b.Push_iceBlock);
                            if (blockCollision == true) {
                                snobees.isActive = false; //Squashes any snobee in the trajectory of the block
                                PlaySound(snobees.Snow_Bee_Squashed);
                            }
                        }
                        break;
                    }
                }

                if (!isBlock) { //Moves to the next position if there is not a block
                    targetPosition.x = v.x;
                    targetPosition.y = v.y;
                }

                startPosition = position;
                amount = 0;

                if (position.x + 48 > borderRight.x - 48) { //When next to a border, if you try to trespass it (pressing the moving key again), Pengo will push the wall, and will not be able to pass through the border
                    isPushing = true;
                    position.x = borderRight.x - 48;
                    targetPosition = position;
                    PlaySound(Push_Outside_Walls);

                    if (isPushing) {
                        wallRightFrameCtr++;
                        if (wallRightFrameCtr > 12) {
                            wallRightFrameCtr = 0;
                            if (wallCurrentRightX == 0) {
                                wallCurrentRightX = 1;
                            }
                            else if (wallCurrentRightX == 1) {
                                wallCurrentRightX = 0;
                            }
                        }
                        wallRightFrameRec.x = wallCurrentRightX * 10;
                        DrawTextureRec(animations->imgBorderRight, wallRightFrameRec, { 712, 90 }, WHITE);
                        isPushing = false;
                    }
                    
                    if (snobees.currentPosition.x + 48 == borderRight.x && position.x + 48 > borderRight.x - 48) { //If there is a snobee touching the border at the time of pushing the wall, the snobee will be stunned for a few seconds
                        snobees.isStunned = true;
                        snobees.direction = 0;
                        PlaySound(snobees.Snow_Bee_Stunned);

                        stunTimer = stunDuration;
                    }                
                }
            }

            else if (IsKeyDown(KEY_LEFT)) { //Actions when moving left, pressing the LEFT key

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
                                isPushing = true;
                                isBlockAdjacent = true;
                                b.isActive = false;
                                PlaySound(b.iceBlock_Destroyed);
                                currentMap->addScore(30);
                                break;
                            }
                        }
                        if (!isBlockAdjacent) {
                            bool blockCollision = CheckCollisionRecs(b.rect, snobees.GetRect());
                            isPushing = true;
                            b.direction = Block::MovingDirection::left;
                            PlaySound(b.Push_iceBlock);
                            if (blockCollision == true) {
                                snobees.isActive = false;
                                PlaySound(snobees.Snow_Bee_Squashed);
                            }
                        }
                        break;
                    }
                }

                if (!isBlock) {
                    targetPosition.x = v.x;
                    targetPosition.y = v.y;
                }

                startPosition = position;
                amount = 0;
                if (position.x - 48 < borderLeft.x + borderLeft.width) {
                    isPushing = true;
                    position.x = borderLeft.x + borderLeft.width;
                    targetPosition = position;
                    PlaySound(Push_Outside_Walls);

                    if (isPushing) {
                        wallLeftFrameCtr++;
                        if (wallLeftFrameCtr > 12) {
                            wallLeftFrameCtr = 0;
                            if (wallCurrentLeftX == 0) {
                                wallCurrentLeftX = 1;
                            }
                            else if (wallCurrentLeftX == 1) {
                                wallCurrentLeftX = 0;
                            }
                        }
                        wallLeftFrameRec.x = wallCurrentLeftX * 10;
                        DrawTextureRec(animations->imgBorderLeft, wallLeftFrameRec, { 78, 90 }, WHITE);
                        isPushing = false;
                    }

                    if (snobees.currentPosition.x == borderLeft.x + borderLeft.width && position.x - 48 < borderLeft.x + borderLeft.width) {
                        snobees.isStunned = true;
                        snobees.direction = 0;
                        PlaySound(snobees.Snow_Bee_Stunned);

                        stunTimer = stunDuration;
                    }                   
                }
            }

            else if (IsKeyDown(KEY_UP)) {  //Actions when moving upwards, pressing the UP key

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
                                isPushing = true;
                                isBlockAdjacent = true;
                                b.isActive = false;
                                currentMap->addScore(30);
                                PlaySound(b.iceBlock_Destroyed);
                                break;
                            }
                        }
                        if (!isBlockAdjacent) {
                            isPushing = true;
                            bool blockCollision = CheckCollisionRecs(b.rect, snobees.GetRect());
                            b.direction = Block::MovingDirection::up;
                            PlaySound(b.Push_iceBlock);
                            if (blockCollision == true) {
                                snobees.isActive = false;
                                PlaySound(snobees.Snow_Bee_Squashed);
                            }
                        }
                        break;
                    }
                }

                if (!isBlock) {
                    targetPosition.x = v.x;
                    targetPosition.y = v.y;
                }

                startPosition = position;
                amount = 0;
                if (position.y <= borderTop.y - borderTop.height + 48) {
                    isPushing = true;
                    position.y = borderTop.y + borderTop.height;
                    targetPosition.y = position.y;
                    targetPosition.x = position.x;
                    PlaySound(Push_Outside_Walls);

                    if (isPushing) {
                        wallUpFrameCtr++;
                        if (wallUpFrameCtr > 12) {
                            wallUpFrameCtr = 0;
                            if (wallCurrentUpX == 0) {
                                wallCurrentUpX = 1;
                            }
                            else if (wallCurrentUpX == 1) {
                                wallCurrentUpX = 0;
                            }
                        }
                        wallUpFrameRec.x = wallCurrentUpX * 624;
                        DrawTextureRec(animations->imgBorderTop, wallUpFrameRec, { 88, 80 }, WHITE);
                        isPushing = false;
                    }

                    if (snobees.currentPosition.y == borderTop.y + borderTop.height && position.y <= borderTop.y - borderTop.height + 48) {
                        snobees.isStunned = true;
                        snobees.direction = 0;
                        PlaySound(snobees.Snow_Bee_Stunned);

                        stunTimer = stunDuration;
                    }
                }               
            }

            else if (IsKeyDown(KEY_DOWN)) { //Actions when moving downwards, pressing the DOWN key

                bool isBlock{};
                Vector2 v{ position.x, position.y + 48 };
                auto& blocks = currentMap->GetBlocks();
                for (int i = 0; i < blocks.size(); ++i) {
                    auto& b = blocks[i];
                    if (b.isActive == true && b.rect.x == v.x && b.rect.y == v.y) {
                        isBlock = true;
                        Vector2 v2{ position.x, position.y + 96 };
                        bool isBlockAdjacent{};
                        for (int j = 0; j < blocks.size(); ++j) {
                            auto& b2 = blocks[j];
                            if ((b2.isActive == true && b2.rect.x == v2.x && b2.rect.y == v2.y) || (b.rect.y + 48 >= borderBottom.y)) {
                                isPushing = true;
                                isBlockAdjacent = true;
                                b.isActive = false;
                                PlaySound(b.iceBlock_Destroyed);
                                currentMap->addScore(30);
                                break;
                            }
                        }
                        if (!isBlockAdjacent) {
                            isPushing = true;
                            bool blockCollision = CheckCollisionRecs(b.rect, snobees.GetRect());
                            b.direction = Block::MovingDirection::down;
                            PlaySound(b.Push_iceBlock);
                            if (blockCollision == true) {
                                snobees.isActive = false;
                                PlaySound(snobees.Snow_Bee_Squashed);
                            }
                        }
                        break;
                    }
                }

                if (!isBlock) {
                    targetPosition.x = v.x;
                    targetPosition.y = v.y;
                }

                startPosition = position;
                amount = 0;
                if (position.y + 48 >= borderBottom.y) {
                    isPushing = true;
                    position.y = borderBottom.y - 48;
                    targetPosition.y = position.y;
                    targetPosition.x = position.x;
                    PlaySound(Push_Outside_Walls);

                    if (isPushing) {
                        wallDownFrameCtr++;
                        if (wallDownFrameCtr > 12) {
                            wallDownFrameCtr = 0;
                            if (wallCurrentDownX == 0) {
                                wallCurrentDownX = 1;
                            }
                            else if (wallCurrentDownX == 1) {
                                wallCurrentDownX = 0;
                            }
                        }
                        wallDownFrameRec.x = wallCurrentDownX * 624;
                        DrawTextureRec(animations->imgBorderBottom, wallDownFrameRec, { 88, 810 }, WHITE);
                        isPushing = false;
                    }

                    if (snobees.currentPosition.y + 48 == borderBottom.y && position.y + 48 >= borderBottom.y) {
                        snobees.isStunned = true;
                        snobees.direction = 0;
                        PlaySound(snobees.Snow_Bee_Stunned);

                        stunTimer = stunDuration;
                    }                   
                }
            }            
        }
        else { //Sets the speed of Pengo while moving to the next position
            float s = speed * GetFrameTime();
            amount += s;
            position = Vector2Lerp(startPosition, targetPosition, amount);
            if (amount >= 1) {
                position = targetPosition;
            }
        }
        if (snobees.isStunned) { //Time while the snobee will be stunned
            stunTimer -= GetFrameTime();
            cout << " " << stunTimer << endl;
            if (stunTimer <= 0) {
                stunTimer = 0;
                snobees.isStunned = false;
                snobees.direction = rand() % 4 + 1; //Reactivate random movement of the snobees after being stunned

            }
        }
    }
}

void Pengo::resetPosition() { //Reset the position of Pengo when it dies or the level changes
    position = respawnPosition;
    targetPosition = respawnPosition;
    startPosition = respawnPosition;
}

Rectangle Pengo::GetRect() //Get the position of Pengo
{
    return Rectangle{position.x, position.y, float(48), float(48)};
}

void Pengo::DrawHitbox(bool isColliding) //Draw a hitbox around Pengo, red if there is a collision, white if not (only for debugging, not used in the actual game)
{
    Color outlineColor = isColliding ? RED : WHITE;
    DrawRectangleLinesEx(GetRect(), 3, outlineColor);
}

const Rectangle& Pengo::GetBorderRight() const //Get the right side of Pengo
{
    return borderRight;
}

const Rectangle& Pengo::GetBorderLeft() const //Get the left side of Pengo
{
    return borderLeft;
}

const Rectangle& Pengo::GetBorderTop() const //Get the top side of Pengo
{
    return borderTop;
}

const Rectangle& Pengo::GetBorderBottom() const //Get the bottom side of Pengo
{
    return borderBottom;
}