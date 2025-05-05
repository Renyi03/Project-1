#pragma once
#include <raylib.h>
class Map;

class SnoBee {
public:
	SnoBee(Rectangle screenBorder, Map* map, Vector2 position);
	~SnoBee();
	void Draw();
	void Update();
	Rectangle GetRect();
	void DrawHitbox(bool isColliding);
	Map* currentMap;
	const Rectangle& GetBorderRight() const;
	const Rectangle& GetBorderLeft() const;
	const Rectangle& GetBorderTop() const;
	const Rectangle& GetBorderBottom() const;
	bool isActive;
	int score = 0;
protected:
	Texture2D image;
	Vector2 current_position, target_position, start_position;
	float amount;
	int speed;
	Rectangle border, borderRight, borderLeft, borderTop, borderBottom;
};
