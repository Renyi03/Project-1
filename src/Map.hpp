#pragma once
#include <raylib.h>
#include <vector>
#include <Block.hpp>

class Map {

public:
	Map();
	~Map();
	void Draw();

private:
	Texture2D ice_block;
	int speed;
	Rectangle border;
	std::vector<int> matrix;
	std::
};

