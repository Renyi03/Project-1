#pragma once
#include <raylib.h>
#include <vector>
class Map;

class SnoBee {
public:
	SnoBee(Rectangle screenBorder, Map* map, Vector2 position, Texture2D img);
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
	bool isStunned;
	Vector2 current_position, position, target_position, start_position;
protected:
	Texture2D image;
	float amount;
	int speed;
	Rectangle border, borderRight, borderLeft, borderTop, borderBottom;
};
