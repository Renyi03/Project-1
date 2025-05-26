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
    position.x = 376;
    position.y = 378;
    target_position = position;
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
            DrawTextureRec(animations->imgPengoLeft, leftFrameRec, { position.x, position.y }, WHITE);
        }
        else if (isPushAnimationPlaying) {
            pushAnimationTimer -= GetFrameTime();
            if (pushAnimationTimer <= 0.0f) {
                isPushAnimationPlaying = false;
                pushAnimationTimer = pushAnimationDuration;
            }
            if (isPushing) {
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
            }
            return;
        }
        else if (isPushing) {
            isPushAnimationPlaying = true;
            pushAnimationTimer = pushAnimationDuration;

            if (pengoDirection == 1 && isPushing) {
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
            }
            isPushing = false;
            return;
        }           
    }
    else if (IsKeyDown(KEY_LEFT)) {

    }
    else if (IsKeyDown(KEY_LEFT)) {

    }
    else if (IsKeyDown(KEY_LEFT)) {

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
    for (auto& snobees : currentMap->GetSnoBees()) {
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
                            if ((b2.isActive == true && b2.rect.x == v2.x && b2.rect.y == v2.y) || (b.rect.x + 48 > borderRight.x - 48)) {
                                isPushing = true;
                                isBlockAdjacent = true;
                                b.isActive = false;
                                PlaySound(b.Ice_Block_Destroyed);
                                currentMap->addScore(30);
                                break;
                            }
                        }
                        if (!isBlockAdjacent) {
                            isPushing = true;
                            bool blockCollision = CheckCollisionRecs(b.rect, snobees.GetRect());
                            b.direction = Block::MovingDirection::right;
                            PlaySound(b.Push_Ice_Block);
                            if (blockCollision == true) {
                                snobees.isActive = false;
                                PlaySound(snobees.Snow_Bee_Squashed);
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
                if (position.x + 48 > borderRight.x - 48) {
                    isPushing = true;
                    position.x = borderRight.x - 48;
                    target_position = position;
                    PlaySound(Push_Outside_Walls);

                    if (snobees.current_position.x + 48 == borderRight.x && position.x + 48 > borderRight.x - 48) {
                        snobees.isStunned = true;
                        PlaySound(snobees.Snow_Bee_Stunned);

                        stunTimer = stunDuration;
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
                                isPushing = true;
                                isBlockAdjacent = true;
                                b.isActive = false;
                                PlaySound(b.Ice_Block_Destroyed);
                                currentMap->addScore(30);
                                break;
                            }
                        }
                        if (!isBlockAdjacent) {
                            bool blockCollision = CheckCollisionRecs(b.rect, snobees.GetRect());
                            isPushing = true;
                            b.direction = Block::MovingDirection::left;
                            PlaySound(b.Push_Ice_Block);
                            if (blockCollision == true) {
                                snobees.isActive = false;
                                PlaySound(snobees.Snow_Bee_Squashed);
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
                    isPushing = true;
                    position.x = borderLeft.x + borderLeft.width;
                    target_position = position;
                    PlaySound(Push_Outside_Walls);

                    if (snobees.current_position.x == borderLeft.x + borderLeft.width && position.x - 48 < borderLeft.x + borderLeft.width) {
                        snobees.isStunned = true;
                        PlaySound(snobees.Snow_Bee_Stunned);

                        stunTimer = stunDuration;
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
                                isPushing = true;
                                isBlockAdjacent = true;
                                b.isActive = false;
                                currentMap->addScore(30);
                                PlaySound(b.Ice_Block_Destroyed);
                                break;
                            }
                        }
                        if (!isBlockAdjacent) {
                            isPushing = true;
                            bool blockCollision = CheckCollisionRecs(b.rect, snobees.GetRect());
                            b.direction = Block::MovingDirection::up;
                            PlaySound(b.Push_Ice_Block);
                            if (blockCollision == true) {
                                snobees.isActive = false;
                                PlaySound(snobees.Snow_Bee_Squashed);
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
                    isPushing = true;
                    position.y = borderTop.y + borderTop.height;
                    target_position.y = position.y;
                    target_position.x = position.x;
                    PlaySound(Push_Outside_Walls);

                    if (snobees.current_position.y == borderTop.y + borderTop.height && position.y <= borderTop.y - borderTop.height + 48) {
                        snobees.isStunned = true;
                        PlaySound(snobees.Snow_Bee_Stunned);

                        stunTimer = stunDuration;
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
                        Vector2 v2{ position.x, position.y + 96 };
                        bool isBlockAdjacent{};
                        for (int j = 0; j < blocks.size(); ++j) {
                            auto& b2 = blocks[j];
                            if ((b2.isActive == true && b2.rect.x == v2.x && b2.rect.y == v2.y) || (b.rect.y + 48 >= borderBottom.y)) {
                                isPushing = true;
                                isBlockAdjacent = true;
                                b.isActive = false;
                                PlaySound(b.Ice_Block_Destroyed);
                                currentMap->addScore(30);
                                break;
                            }
                        }
                        if (!isBlockAdjacent) {
                            isPushing = true;
                            bool blockCollision = CheckCollisionRecs(b.rect, snobees.GetRect());
                            b.direction = Block::MovingDirection::down;
                            PlaySound(b.Push_Ice_Block);
                            if (blockCollision == true) {
                                snobees.isActive = false;
                                PlaySound(snobees.Snow_Bee_Squashed);
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
                if (position.y + 48 >= borderBottom.y) {
                    isPushing = true;
                    position.y = borderBottom.y - 48;
                    target_position.y = position.y;
                    target_position.x = position.x;
                    PlaySound(Push_Outside_Walls);

                    if (snobees.current_position.y + 48 == borderBottom.y && position.y + 48 >= borderBottom.y) {
                        snobees.isStunned = true;
                        PlaySound(snobees.Snow_Bee_Stunned);

                        stunTimer = stunDuration;
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
        if (snobees.isStunned) {
            stunTimer -= GetFrameTime();
            cout << " " << stunTimer << endl;
            if (stunTimer <= 0) {
                stunTimer = 0;
                snobees.isStunned = false;
            }
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
    return Rectangle{position.x, position.y, float(48), float(48)};
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