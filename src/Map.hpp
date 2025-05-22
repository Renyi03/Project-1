#pragma once
#include <raylib.h>
#include <vector>
#include<string>
using namespace std;
class Pengo;
class Block;
class SnoBee;

class Map {

public:
	Map(Rectangle border, string map, Texture2D imgSnobee, Texture2D imgPengo, Texture2D imgIceBlock);
	~Map();
	void Draw();
	std::vector<Block>& GetBlocks();
	std::vector<SnoBee>& GetSnoBees();
	vector<SnoBee>SnoBees;
	Pengo* pengo;
	int GetScore() const;
	void addScore(int value);
	int snobeesDefeated;
	bool nextLevel;
	bool gameOver;
	int lives;
private:
	int score = 0;
	Texture2D ice_block;
	int speed;
	Rectangle border;
	string map;
	std::vector<int> matrix;
	std::vector<Block>blocks;
};