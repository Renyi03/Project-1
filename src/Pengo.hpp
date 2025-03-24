#pragma once
#include <raylib.h>



class Pengo {

public:
	Pengo(Rectangle screenBorder);
	~Pengo();
	void Draw();
	void Update();
	Rectangle GetRect();
	void DrawHitbox(bool isColliding);
private:
	Texture2D image;
	Vector2 position, target_position, start_position;
	float amount;
	int speed;
	Rectangle border;
};

