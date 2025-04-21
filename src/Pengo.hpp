#pragma once
#include <raylib.h>
class Map;
class Map2;

class Pengo {

public:
	Pengo(Rectangle screenBorder, Map *map);
	Pengo(Rectangle screenBorder, Map2* map2);
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

