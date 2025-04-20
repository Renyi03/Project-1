#pragma once
#include <raylib.h>
#include <vector>
class Pengo;
class Block;
class SnoBee;

class Map {

public:
	Map(Rectangle border);
	~Map();
	void Draw();
	std::vector<Block>& GetBlocks();
	Pengo* pengo;
	SnoBee* snoBee;
private:
	Texture2D ice_block;
	int speed;
	Rectangle border;
	std::vector<int> matrix;
	std::vector<Block>blocks;
};

