#include "Map.hpp"
#include <raylib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


Map::Map()
{
    ice_block = LoadTexture("resources/Graphics/ice block.png");

    std::string map = LoadFileText("resources/Map_1.txt");

    for (int i = 0; i < map.size(); ++i) {
        auto ch = map[i];


        switch (ch) {
        case '0':
            matrix.push_back(0);
            break;
        case '\n':
            matrix.push_back(-1);
            break;
        case '1':
            matrix.push_back(1);
            break;


        }
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
}

