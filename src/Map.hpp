#pragma once
#include <raylib.h>
#include <vector>


class Map {

public:
	Map();
	~Map();
	void Draw();

private:
	Texture2D image;
	Vector2 position;
	int speed;
	Rectangle border;
	std::vector<int> matrix;
};

