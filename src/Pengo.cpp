#include "Pengo.hpp"
#include <raylib.h>
#include <algorithm>
#include <raymath.h>
#include <iostream>
#include "Map.hpp"
#include "Block.hpp"
#include "SnoBee.hpp"
using namespace std;

Pengo::Pengo(Rectangle screenBorder, Map* map, Texture2D img, Sound S_Push_Outside_Walls)
{
    borderTop = Rectangle{ 88, 80, 624, 10 };
    borderBottom = Rectangle{ 88, 810, 624, 10 };
    borderLeft = Rectangle{ 78, 90, 10, 720 };
    borderRight = Rectangle{ 712, 90, 10, 720 };
    image = img;
    Push_Outside_Walls = S_Push_Outside_Walls;
    position.x = 376;
    position.y = 378;
    targetPosition = position;
    speed = 1;
    border = screenBorder;
    currentMap = map;
    stunTimer = 0;
    stunDuration = 2.5;
}

Pengo::~Pengo()
{
}

void Pengo::Draw() {
	DrawTextureV(image, position, WHITE);
}

void Pengo::Update() {
    for (auto& snobees : currentMap->GetSnoBees()) { //This will have checked every snobee of the vector of snobees every time there is a snobe.anything
        if (position.x == targetPosition.x && position.y == targetPosition.y) {
            if (IsKeyDown(KEY_RIGHT)) { //Actions when moving right, pressing the RIGHT key

                bool isBlock{};
                Vector2 v{ position.x + 48, position.y };
                auto& blocks = currentMap->GetBlocks();
                for (int i = 0; i < blocks.size(); ++i) {
                    auto& b = blocks[i];
                    if (b.isActive == true && b.rect.x == v.x && b.rect.y == v.y) { //If Pengo collides with a block
                        isBlock = true;
                        Vector2 v2{ position.x + 96, position.y };
                        bool isBlockAdjacent{};
                        for (int j = 0; j < blocks.size(); ++j) {
                            auto& b2 = blocks[j];
                            if ((b2.isActive == true && b2.rect.x == v2.x && b2.rect.y == v2.y) || (b.rect.x + image.width > borderRight.x - 48)) { //Checks if the block has another block behind, to decide if it will be moved or destroyed
                                isBlockAdjacent = true;
                                b.isActive = false; //Destroys the block
                                PlaySound(b.iceBlock_Destroyed);
                                currentMap->addScore(30); //Adds 30 points to the score for breaking a block
                                break;
                            }
                        }
                        if (!isBlockAdjacent) {
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
                if (position.x + image.width > borderRight.x - 48) { //When next to a border, if you try to trespass it (pressing the moving key again), Pengo will push the wall, and will not be able to pass through the border
                    position.x = borderRight.x - image.width;
                    targetPosition = position;
                    PlaySound(Push_Outside_Walls);

                    if (snobees.currentPosition.x + image.width == borderRight.x && position.x + image.width > borderRight.x - 48) { //If there is a snobee touching the border at the time of pushing the wall, the snobee will be stunned for a few seconds
                        snobees.isStunned = true;
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
                    if (b.isActive == true && b.rect.x == v.x && b.rect.y == v.y) { //If Pengo collides with a block
                        isBlock = true;
                        Vector2 v2{ position.x - 96, position.y };
                        bool isBlockAdjacent{};
                        for (int j = 0; j < blocks.size(); ++j) {
                            auto& b2 = blocks[j];
                            if ((b2.isActive == true && b2.rect.x == v2.x && b2.rect.y == v2.y) || (b.rect.x - 48 < borderLeft.x + borderLeft.width)) { //Checks if the block has another block behind, to decide if it will be moved or destroyed
                                isBlockAdjacent = true;
                                b.isActive = false; //Destroys the block
                                PlaySound(b.iceBlock_Destroyed);
                                currentMap->addScore(30); //Adds 30 points to the score for breaking a block
                                break;
                            }
                        }
                        if (!isBlockAdjacent) {
                            bool blockCollision = CheckCollisionRecs(b.rect, snobees.GetRect());
                            b.direction = Block::MovingDirection::left; //Move the block
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
                if (position.x - 48 < borderLeft.x + borderLeft.width) { //When next to a border, if you try to trespass it (pressing the moving key again), Pengo will push the wall, and will not be able to pass through the border
                    position.x = borderLeft.x + borderLeft.width;
                    targetPosition = position;
                    PlaySound(Push_Outside_Walls);

                    if (snobees.currentPosition.x == borderLeft.x + borderLeft.width && position.x - 48 < borderLeft.x + borderLeft.width) { //If there is a snobee touching the border at the time of pushing the wall, the snobee will be stunned for a few seconds
                        snobees.isStunned = true;
                        PlaySound(snobees.Snow_Bee_Stunned);

                        stunTimer = stunDuration;
                    }                   
                }
            }

            else if (IsKeyDown(KEY_UP)) { //Actions when moving upwards, pressing the UP key

                bool isBlock{};
                Vector2 v{ position.x, position.y - 48 };
                auto& blocks = currentMap->GetBlocks();
                for (int i = 0; i < blocks.size(); ++i) {
                    auto& b = blocks[i];
                    if (b.isActive == true && b.rect.x == v.x && b.rect.y == v.y) { //If Pengo collides with a block
                        isBlock = true;
                        Vector2 v2{ position.x, position.y - 96 };
                        bool isBlockAdjacent{};
                        for (int j = 0; j < blocks.size(); ++j) {
                            auto& b2 = blocks[j];
                            if ((b2.isActive == true && b2.rect.x == v2.x && b2.rect.y == v2.y) || (b.rect.y <= borderTop.y - borderTop.height + 48)) { //Checks if the block has another block behind, to decide if it will be moved or destroyed
                                isBlockAdjacent = true;
                                b.isActive = false; //Destroys the block
                                currentMap->addScore(30); //Adds 30 points to the score for breaking a block
                                PlaySound(b.iceBlock_Destroyed);
                                break;
                            }
                        }
                        if (!isBlockAdjacent) {
                            bool blockCollision = CheckCollisionRecs(b.rect, snobees.GetRect());
                            b.direction = Block::MovingDirection::up; //Move the block
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
                if (position.y <= borderTop.y - borderTop.height + 48) { //When next to a border, if you try to trespass it (pressing the moving key again), Pengo will push the wall, and will not be able to pass through the border
                    position.y = borderTop.y + borderTop.height;
                    targetPosition.y = position.y;
                    targetPosition.x = position.x;
                    PlaySound(Push_Outside_Walls);

                    if (snobees.currentPosition.y == borderTop.y + borderTop.height && position.y <= borderTop.y - borderTop.height + 48) { //If there is a snobee touching the border at the time of pushing the wall, the snobee will be stunned for a few seconds
                        snobees.isStunned = true;
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
                    if (b.isActive == true && b.rect.x == v.x && b.rect.y == v.y) { //If Pengo collides with a block
                        isBlock = true;
                        Vector2 v2{ position.x, position.y + 96 };
                        bool isBlockAdjacent{};
                        for (int j = 0; j < blocks.size(); ++j) {
                            auto& b2 = blocks[j];
                            if ((b2.isActive == true && b2.rect.x == v2.x && b2.rect.y == v2.y) || (b.rect.y + image.height >= borderBottom.y)) { //Checks if the block has another block behind, to decide if it will be moved or destroyed
                                isBlockAdjacent = true;
                                b.isActive = false; //Destroys the block
                                PlaySound(b.iceBlock_Destroyed);
                                currentMap->addScore(30); //Adds 30 points to the score for breaking a block
                                break;
                            }
                        }
                        if (!isBlockAdjacent) { 
                            bool blockCollision = CheckCollisionRecs(b.rect, snobees.GetRect());
                            b.direction = Block::MovingDirection::down; //Move the block
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
                if (position.y + image.height >= borderBottom.y) { //When next to a border, if you try to trespass it (pressing the moving key again), Pengo will push the wall, and will not be able to pass through the border
                    position.y = borderBottom.y - image.height;
                    targetPosition.y = position.y;
                    targetPosition.x = position.x;
                    PlaySound(Push_Outside_Walls);

                    if (snobees.currentPosition.y + image.height == borderBottom.y && position.y + image.height >= borderBottom.y) { //If there is a snobee touching the border at the time of pushing the wall, the snobee will be stunned for a few seconds
                        snobees.isStunned = true;
                        PlaySound(snobees.Snow_Bee_Stunned);

                        stunTimer = stunDuration;
                    }                   
                }
            }            
        }
        else { //Sets the speed of Pengo
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
    return Rectangle{position.x, position.y, float(image.width), float(image.height)};
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