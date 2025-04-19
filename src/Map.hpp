#pragma once
#include <raylib.h>
#include <vector>
class Pengo;
class Block;

class Map{

public:
	Map();
	~Map();
	void Draw();
	std::vector<Block>& GetBlocks();
	Pengo* pengo;
private:
	Texture2D ice_block;
	int speed;
	Rectangle border;
	std::vector<int> matrix;
	std::vector<Block>blocks;
};

