#include "Map.hpp"
#include "Block.hpp"
#include <raylib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <Pengo.hpp>
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

    for (int i = 0; i < matrix.size(); ++i) {
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
    }

    for (auto& b : blocks) {
        DrawRectangle(b.rect.x, b.rect.y, b.rect.width, b.rect.height, YELLOW);
    }
}

const std::vector<Block>& Map::GetBlocks()
{
    return blocks;
}

//Rectangle Map::GetRectMap()
//{
//    return Rectangle{ (50 + row * 80), (98 + col * 80), float(ice_block.width), float(ice_block.height) };
//    return Rectangle();
//}

