#pragma once
#include <raylib.h>
class Map;

class Pengo {

public:
	Pengo(Rectangle screenBorder, Map *map);
	~Pengo();
	void Draw();
	void Update();
	Rectangle GetRect();
	void DrawHitbox(bool isColliding);
	Map *currentMap;
	const Rectangle &GetBorderRight() const;
	const Rectangle &GetBorderLeft() const;
	const Rectangle &GetBorderTop() const;
	const Rectangle &GetBorderBottom() const;
protected:
	Texture2D image;
	Vector2 position, target_position, start_position;
	float amount;
	int speed;
	Rectangle border, borderRight, borderLeft, borderTop, borderBottom;
};

