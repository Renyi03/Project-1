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
	Map(Rectangle border, string map, Texture2D imgSnobee, Texture2D imgPengo, Texture2D imgIceBlock, Sound S_Snow_Bee_Squashed, Sound S_Snow_Bee_Stunned, Sound S_Touch_Snow_Bee, Sound S_Push_Outside_Walls, Sound S_Ice_Block_Destroyed, Sound S_Push_Ice_Block, Sound S_Block_Stopped);
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
	Sound Snow_Bee_Squashed;
	Sound Snow_Bee_Stunned;
	Sound Touch_Snow_Bee;
	Sound Push_Outside_Walls;
	Sound Ice_Block_Destroyed;
	Sound Push_Ice_Block;
	Sound Block_Stopped;
private:
	int score = 0;
	Texture2D ice_block;
	int speed;
	Rectangle border;
	string map;
	std::vector<int> matrix;
	std::vector<Block>blocks;
};