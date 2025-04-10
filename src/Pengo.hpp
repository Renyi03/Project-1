#pragma once
#include <raylib.h>
#include <Map.hpp>


class Pengo {

public:
	Pengo(Rectangle screenBorder, Map *map);
	~Pengo();
	void Draw();
	void Update();
	Rectangle GetRect();
	void DrawHitbox(bool isColliding);
	Map *currentMap;
protected:
	Texture2D image;
	Vector2 position, target_position, start_position;
	float amount;
	int speed;
	Rectangle border, borderRight, borderLeft, borderTop, borderBottom;
};

