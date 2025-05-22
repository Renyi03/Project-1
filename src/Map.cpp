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

Map::Map(Rectangle border, string map)
{
    snoBee = new SnoBee{ border, this };
    pengo = new Pengo{ border, this, snoBee }; //this: referencia al objeto de la clase (en este caso, el mapa)
    
    ice_block = LoadTexture("resources/Graphics/ice block.png");
    lives = 5;

    float row{};
    float col{};

    for (int i = 0; i < map.size(); ++i) {
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
            blocks.push_back(Block{ Rectangle{88 + col * 24, 90 + row * 48, 48, 48} });
            break;
        }
        ++col;
        std::cout << matrix[matrix.size() - 1];
    }
}

Map::~Map()
{
    delete pengo;
    delete snoBee; 
    pengo = nullptr;
    snoBee = nullptr;
	UnloadTexture(ice_block);
}

void Map::Draw() {
    Vector2 map_iceblock_position;
    map_iceblock_position.x = 88;
    map_iceblock_position.y = 90;
    pengo->Update();
    if (snoBee->isActive) {
        snoBee->Update();
        snoBee->Draw();
    }

    bool hasCollided = false;

    //losing lives
    if (snoBee->isActive && CheckCollisionRecs(pengo->GetRect(), snoBee->GetRect())) {
        
        if (snoBee->isStunned && CheckCollisionRecs(pengo->GetRect(), snoBee->GetRect())) {
            snoBee->isActive = false;
            nextLevel = true;
        }

        if (!hasCollided) {
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
    }
    else {
        hasCollided = false;
    }

    pengo->Draw();

    //crear un map::Update()

    /*pengo.DrawHitbox(isColliding);
    snoBee.DrawHitbox(isAColliding);*/


   /* for (int i = 0; i < matrix.size(); ++i) {
        auto ch = matrix[i];
        if (ch == 0) {
            map_iceblock_position.x += 48;
        }
        else if (ch == 1) {
            DrawTextureV(ice_block, map_iceblock_position, WHITE);

            map_iceblock_position.x += 48;
        }
        else if (ch == -1) {
            map_iceblock_position.y += 48;
            map_iceblock_position.x = 88;
        }
    }*/

    for (auto& b : blocks) { //iterates over each element inside the vector internally
        if (b.isActive) {
            if (b.direction != Block::MovingDirection::none) {
                auto& borderRight = pengo->GetBorderRight();
                auto& borderLeft = pengo->GetBorderLeft();
                auto& borderTop = pengo->GetBorderTop();
                auto& borderBottom = pengo->GetBorderBottom();

                Vector2 blockTargetPosition{ b.rect.x, b.rect.y };
                Vector2 displacement{ blockTargetPosition };
                float step{ 3 }; //another way of declaring a variable
                switch (b.direction) {
                case Block::MovingDirection::right:
                    if (b.rect.x + b.rect.width <= borderRight.x - step) {
                        blockTargetPosition.x += 48;
                        displacement.x += step;
                        PlaySound(b.Block_Stopped);
                    }
                    else {
                        b.direction = Block::MovingDirection::none;
                    }
                    break;
                case Block::MovingDirection::left:
                    if (b.rect.x >= borderLeft.x + borderLeft.width + step) {
                        blockTargetPosition.x -= 48;
                        displacement.x -= step;
                        PlaySound(b.Block_Stopped);
                    }
                    else {
                        b.direction = Block::MovingDirection::none;
                    }
                    break;
                case Block::MovingDirection::up:
                    if (b.rect.y >= borderTop.y + borderTop.height + step) {
                        blockTargetPosition.y -= 48;
                        displacement.y -= 3;
                        PlaySound(b.Block_Stopped);
                    }
                    else {
                        b.direction = Block::MovingDirection::none;
                    }                   
                    break;
                case Block::MovingDirection::down:
                    if (b.rect.y + b.rect.height <= borderBottom.y - step) {
                        blockTargetPosition.y += 48;
                        displacement.y += 3;
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
                        isBlock = true;
                        break;
                    }
                }

                if (!isBlock) {
                    b.rect.x = displacement.x;
                    b.rect.y = displacement.y;
                    if (snoBee->isActive && CheckCollisionRecs(b.rect, snoBee->GetRect())) {
                        snoBee->isActive = false;
                        nextLevel = true;
                        b.direction = Block::MovingDirection::none;
                        PlaySound(b.Ice_Block_Destroyed);
                        snoBee->score += 400;
                    }
                }
                else {
                    b.direction = Block::MovingDirection::none;
                }
                if (snoBee->isActive == false) {
                    gameOver = true;
                }
            }
            DrawTextureV(ice_block, { b.rect.x, b.rect.y }, WHITE);
        }
    }
}


std::vector<Block>& Map::GetBlocks()
{
    return blocks;
}

int Map::GetScore() const {
<<<<<<< Updated upstream
    return snoBee->score;
=======
    return score;
}

void Map::addScore(int value)
{
    score += value;
}

std::vector<SnoBee>& Map::GetSnoBees()
{
    return SnoBees;
>>>>>>> Stashed changes
}

//Rectangle Map::GetRectMap()
//{
//    return Rectangle{ (50 + row * 80), (98 + col * 80), float(ice_block.width), float(ice_block.height) };
//    return Rectangle();
//}

