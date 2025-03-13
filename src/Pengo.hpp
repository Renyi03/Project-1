#pragma once
#include <raylib.h>



class Pengo {

public:
	Pengo(Rectangle border) : Border{ border } {};
	~Pengo();
	void Draw();
	void Update();
	Rectangle GetRect();
	void DrawHitbox(bool isColliding);
private:
	Texture2D image;
	Vector2 position;
	int speed;
	Rectangle Border;
};

