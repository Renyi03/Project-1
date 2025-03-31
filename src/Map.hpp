#pragma once
#include <raylib.h>
#include <vector>
#include <Block.hpp>
#include <Pengo.hpp>

class Map{

public:
	Map();
	~Map();
	void Draw();
	/*Rectangle GetRectMap();*/

private:
	Texture2D ice_block;
	int speed;
	Rectangle border;
	std::vector<int> matrix;
	std::vector<Block>blocks;
};

