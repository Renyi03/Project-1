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
	int countSurroundingBlocks();
	Map* currentMap;
	const Rectangle& GetBorderRight() const;
	const Rectangle& GetBorderLeft() const;
	const Rectangle& GetBorderTop() const;
	const Rectangle& GetBorderBottom() const;
	bool isActive;
	bool isStunned;
	bool breakingMode;
	float breakCooldown;
	Vector2 current_position, position, target_position, start_position;
	Sound Snow_Bee_Squashed = LoadSound("resources/Pengo_Music/Snow-Bee_Squashed.wav");
	Sound Snow_Bee_Stunned = LoadSound("resources/Pengo_Music/Snow-Bee_Stunned.wav");
protected:
	Texture2D image;
	float amount;
	int speed;
	Rectangle border, borderRight, borderLeft, borderTop, borderBottom;
};