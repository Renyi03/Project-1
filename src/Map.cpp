#include "Map.hpp"
#include "Block.hpp"
#include <raylib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include "Pengo.hpp"
#include "Block.hpp"
#include "SnoBee.hpp"
using namespace std;

Map::Map(Rectangle border, string map, Texture2D imgSnobee, Texture2D imgPengo, Texture2D imgIceBlock, Sound S_Snow_Bee_Squashed, Sound S_Snow_Bee_Stunned, Sound S_Touch_Snow_Bee, Sound S_Push_Outside_Walls, Sound S_Ice_Block_Destroyed, Sound S_Push_Ice_Block, Sound S_Block_Stopped)
{
    Snow_Bee_Squashed = S_Snow_Bee_Squashed;
    Snow_Bee_Stunned = S_Snow_Bee_Stunned;
    Touch_Snow_Bee = S_Touch_Snow_Bee;
    Push_Outside_Walls = S_Push_Outside_Walls;
    Ice_Block_Destroyed = S_Ice_Block_Destroyed;
    Push_Ice_Block = S_Push_Ice_Block;
    Block_Stopped = S_Block_Stopped;

    gameOver = false;
    isMapUsed = false;

    ice_block = imgIceBlock;
    snobeesDefeated = 0;

    vector<Vector2>SpawnPositions = { //Vector that contains the position of all snobees
        {232, 282}, {328, 282}, {184, 474}, {184, 666}
    };
    
    for (auto &v : SpawnPositions) { //Creates a vector to contain all the snobees, using the positions of previous vector, "SpawnPositions"
        auto& s = SnoBee{ border, this, v, imgSnobee, S_Snow_Bee_Squashed, S_Snow_Bee_Stunned };
        SnoBees.push_back(s);
    }

    pengo = new Pengo{ border, this, imgPengo, S_Push_Outside_Walls }; //Creates a Pengo
    
    lives = 5; //Initial number of lives, resetted at the beginning of each level

    float row{};
    float col{};

    for (int i = 0; i < map.size(); ++i) { //Creates a map, according to the data in the .txt files
        auto ch = map[i];
        switch (ch) {
        case '0':
            matrix.push_back(0);
            break;
        case '\n':
            matrix.push_back(-1);
            col = -1;
            ++row;
            break;
        case '1':
            matrix.push_back(1);           
            blocks.push_back(Block{ Rectangle{88 + col * 24, 90 + row * 48, 48, 48}, S_Ice_Block_Destroyed, S_Push_Ice_Block, S_Block_Stopped });
            break;
        }
        ++col;
        std::cout << matrix[matrix.size() - 1];
    }
}

Map::~Map() //Destructor to reset pengo
{
    delete pengo;
    pengo = nullptr;
}

void Map::Draw() {
    pengo->Update();
    pengo->Draw();
    

    for (auto& snobee : GetSnoBees()) { //Draws every snobee contained in the vector of snobees
        Vector2 map_iceblock_position;
        map_iceblock_position.x = 88;
        map_iceblock_position.y = 90;
        if (snobee.isActive) {
            snobee.Update();
            snobee.Draw();
        }

        bool hasCollided = false;

        //Losing lives
        if (snobee.isActive && CheckCollisionRecs(pengo->GetRect(), snobee.GetRect())) {
            if (!hasCollided && snobee.isStunned == false) {
                --lives;
                hasCollided = true;
                cout << lives << " ";

                if (lives > 0) {
                    pengo->resetPosition();
                }
                else {
                    gameOver = true;
                }
            }
            if (snobee.isStunned) {
                snobee.isActive = false;
                addScore(100);
                snobeesDefeated++;
                PlaySound(Touch_Snow_Bee);
                if (snobeesDefeated >= 4) {
                    nextLevel = true;
                }
            }

        }
        else {
            hasCollided = false;
        }


        for (auto& b : blocks) { //Iterates over each element (blocks) of the map
            if (b.isActive) {
                if (b.direction != Block::MovingDirection::none) {
                    auto& borderRight = pengo->GetBorderRight();
                    auto& borderLeft = pengo->GetBorderLeft();
                    auto& borderTop = pengo->GetBorderTop();
                    auto& borderBottom = pengo->GetBorderBottom();

                    Vector2 blockTargetPosition{ b.rect.x, b.rect.y };
                    Vector2 displacement{ blockTargetPosition };
                    float step{ 1 }; 
                    switch (b.direction) {
                    case Block::MovingDirection::right: //Movement of the blocks
                        if (b.rect.x + b.rect.width <= borderRight.x - step) {
                            blockTargetPosition.x += 48;
                            displacement.x += step;
                            PlaySound(b.Block_Stopped);
                        }
                        else {
                            b.direction = Block::MovingDirection::none;
                        }
                        break;
                    case Block::MovingDirection::left: //Movement of the blocks
                        if (b.rect.x >= borderLeft.x + borderLeft.width + step) {
                            blockTargetPosition.x -= 48;
                            displacement.x -= step;
                            PlaySound(b.Block_Stopped);
                        }
                        else {
                            b.direction = Block::MovingDirection::none;
                        }
                        break;
                    case Block::MovingDirection::up: //Movement of the blocks
                        if (b.rect.y >= borderTop.y + borderTop.height + step) {
                            blockTargetPosition.y -= 48;
                            displacement.y -= step;
                            PlaySound(b.Block_Stopped);
                        }
                        else {
                            b.direction = Block::MovingDirection::none;
                        }
                        break;
                    case Block::MovingDirection::down: //Movement of the blocks
                        if (b.rect.y + b.rect.height <= borderBottom.y - step) {
                            blockTargetPosition.y += 48;
                            displacement.y += step;
                            PlaySound(b.Block_Stopped);
                        }
                        else {
                            b.direction = Block::MovingDirection::none;
                        }
                        break;
                    }
                    bool isBlock{};

                    for (int i = 0; i < blocks.size(); ++i) {
                        auto& b2 = blocks[i];
                        if (b2.isActive == true && b2.rect.x == blockTargetPosition.x && b2.rect.y == blockTargetPosition.y) {
                            isBlock = true; //Sets isBlock to true for every block in the map
                            break;
                        }
                    }

                    if (!isBlock) {
                        b.rect.x = displacement.x;
                        b.rect.y = displacement.y;
                         
                        if (snobee.isActive && CheckCollisionRecs(b.rect, snobee.GetRect())) { //Defeat a snobee by squashing it with a block
                            snobee.isActive = false;
                            snobeesDefeated++;
                            PlaySound(snobee.Snow_Bee_Squashed);
                            if (snobeesDefeated >= 4) {
                                nextLevel = true;
                            }

                            PlaySound(b.Ice_Block_Destroyed);
                            addScore(400);
                        }
                    }
                    else {
                        b.direction = Block::MovingDirection::none;
                    }                   
                }
                DrawTextureV(ice_block, { b.rect.x, b.rect.y }, WHITE);
            }
        }
    }
}

std::vector<Block>& Map::GetBlocks() //Get all the blocks contained in the map
{
    return blocks;
}

int Map::GetScore() const { //Get the score accumulated
    return score;
}

void Map::addScore(int value) //Add points to the score
{
    score += value;
}

std::vector<SnoBee>& Map::GetSnoBees() //Get the vector of snobees
{
    return SnoBees;
}