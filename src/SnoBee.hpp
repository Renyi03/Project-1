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
	bool IsActiveRight(Vector2 position);
	bool IsActiveLeft(Vector2 position);
	bool IsActiveUp(Vector2 position);
	bool IsActiveDown(Vector2 position);
	bool IsSurrounded();
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
	Vector2 position, target_position, start_position;
	float amount;
	int speed;
	Rectangle border, borderRight, borderLeft, borderTop, borderBottom;
};
