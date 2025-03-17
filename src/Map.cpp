#include "Map.hpp"
#include <raylib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


Map::Map()
{
    position.x = 400;
    position.y = 400;
    speed = 5;


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
        std::cout << matrix[matrix.size()-1];
    }
}

Map::~Map()
{
	UnloadTexture(image);
}

void Map::Draw() {
	DrawTextureV(image, position, WHITE);
}

