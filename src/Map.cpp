#include "Map.hpp"
#include "Block.hpp"
#include <raylib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include "Pengo.hpp"
#include "Block.hpp"
using namespace std;


Map::Map()
{
    ice_block = LoadTexture("resources/Graphics/ice block.png");

    std::string map = LoadFileText("resources/Map_1.txt");

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
            
            blocks.push_back(Block{ Rectangle{88 + col * 24, 40 + row * 48, 48, 48} });

            /*DrawRectangleLinesEx(GetRectMap(), 3, BLUE);*/
               
            
            
            break;


        }
        ++col;
        std::cout << matrix[matrix.size() - 1];
    }
}

Map::~Map()
{
	UnloadTexture(ice_block);
}

void Map::Draw() {
    Vector2 map_iceblock_position;
    map_iceblock_position.x = 88;
    map_iceblock_position.y = 40;

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

    /*if (b.rect.x + image.width > borderRight.x - 48) {
        b.direction = Block::MovingDirection::none;
        b.rect.x = borderRight.x - image.width;
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
                    }
                    else {
                        b.direction = Block::MovingDirection::none;
                    }
                    break;
                case Block::MovingDirection::left:
                    if (b.rect.x >= borderLeft.x + borderLeft.width + step) {
                        blockTargetPosition.x -= 48;
                        displacement.x -= step;
                    }
                    else {
                        b.direction = Block::MovingDirection::none;
                    }
                    break;
                case Block::MovingDirection::up:
                    if (b.rect.y >= borderTop.y + borderTop.height + step) {
                        blockTargetPosition.y -= 48;
                        displacement.y -= 3;
                    }
                    else {
                        b.direction = Block::MovingDirection::none;
                    }                   
                    break;
                case Block::MovingDirection::down:
                    if (b.rect.y + b.rect.height <= borderBottom.y - step) {
                        blockTargetPosition.y += 48;
                        displacement.y += 3;
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
                }
                else {
                    b.direction = Block::MovingDirection::none;
                }
            }
            DrawTextureV(ice_block, { b.rect.x, b.rect.y }, WHITE);
            /*DrawRectangle(b.rect.x, b.rect.y, b.rect.width, b.rect.height, YELLOW);*/
        }
    }
}

std::vector<Block>& Map::GetBlocks()
{
    return blocks;
}



//Rectangle Map::GetRectMap()
//{
//    return Rectangle{ (50 + row * 80), (98 + col * 80), float(ice_block.width), float(ice_block.height) };
//    return Rectangle();
//}

