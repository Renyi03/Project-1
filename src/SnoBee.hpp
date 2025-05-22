#pragma once
#include <raylib.h>
class Map;

class SnoBee {
public:
	SnoBee(Rectangle screenBorder, Map* map);
	~SnoBee();
	void Draw();
	void Update();
	Rectangle GetRect();
	void DrawHitbox(bool isColliding);
	int countSurroundingBlocks();
	Map* currentMap;
	const Rectangle& GetBorderRight() const;
	const Rectangle& GetBorderLeft() const;
	const Rectangle& GetBorderTop() const;
	const Rectangle& GetBorderBottom() const;
	bool isActive;
	bool breakingMode;
	float breakCooldown;
protected:
	Texture2D image;
	Vector2 position, target_position, start_position;
	float amount;
	int speed;
	Rectangle border, borderRight, borderLeft, borderTop, borderBottom;
};
