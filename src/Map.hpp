#pragma once
#include <raylib.h>
#include <vector>
#include<string>
using namespace std;
class Anims;
class Pengo;
class Block;
class SnoBee;

class Map {

public:
	Map(Anims* anims, Rectangle border, string map, Texture2D imgIceBlock, Sound S_Snow_Bee_Squashed, Sound S_Snow_Bee_Stunned, Sound S_Touch_Snow_Bee, Sound S_Push_Outside_Walls, Sound S_iceBlock_Destroyed, Sound S_Push_iceBlock, Sound S_Block_Stopped); //Constructor
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
	bool isMapUsed;
	int lives;
	Sound Snow_Bee_Squashed;
	Sound Snow_Bee_Stunned;
	Sound Touch_Snow_Bee;
	Sound Push_Outside_Walls;
	Sound iceBlock_Destroyed;
	Sound Push_iceBlock;
	Sound Block_Stopped;
	Anims* animations;
private:
	int score = 0;
	Texture2D iceBlock;
	int speed;
	Rectangle border;
	string map;
	std::vector<int> matrix;
	std::vector<Block>blocks;
};