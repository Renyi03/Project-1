#pragma once
#include <raylib.h>

class Pengo {

public:
	Pengo();
	~Pengo();
	void Draw();
	void Update();
private:
	Texture2D image;
	Vector2 position;
	int speed;
};
