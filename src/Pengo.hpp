#pragma once
#include <raylib.h>
class Map;
class SnoBee;

class Pengo {
public:
	Pengo(Rectangle screenBorder, Map* map, Texture2D img);
	~Pengo();
	void Draw();
	void Update();
	Rectangle GetRect();
	void DrawHitbox(bool isColliding);
	Map* currentMap;
	const Rectangle& GetBorderRight() const;
	const Rectangle& GetBorderLeft() const;
	const Rectangle& GetBorderTop() const;
	const Rectangle& GetBorderBottom() const;
	void resetPosition();
protected:
	Texture2D image;
	Vector2 position, target_position, start_position;
	Vector2 respawn_position = { 376, 378 };
	float amount;
	int speed;
	Rectangle border, borderRight, borderLeft, borderTop, borderBottom;
};


