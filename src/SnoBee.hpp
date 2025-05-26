#pragma once
//#include <raylib.h>
#include <vector>
class Map;
//class Anims;
#include "Anims.hpp"

class SnoBee {
public:
	SnoBee(Anims* anims, Rectangle screenBorder, Map* map, Vector2 position, Sound S_Snow_Bee_Squashed, Sound S_Snow_Bee_Stunned); //Constructor
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
	Vector2 currentPosition, position, targetPosition, startPosition;
	Sound Snow_Bee_Squashed;
	Sound Snow_Bee_Stunned;
	Anims* animations;
	int leftFramesCtr, rightFramesCtr, upFramesCtr, downFramesCtr, stunFramesCtr, breakLeftFramesCtr, breakRightFramesCtr, breakUpFramesCtr, breakDownFramesCtr;
	int currentLeftX, currentRightX, currentUpX, currentDownX, currentStunX, currentBreakLeftX, currentBreakRightX, currentBreakUpX, currentBreakDownX;
	Rectangle leftFrameRec, rightFrameRec, upFrameRec, downFrameRec, stunFrameRec, breakLeftFrameRec, breakRightFrameRec, breakUpFrameRec, breakDownFrameRec;
	int direction;
protected:
	float amount;
	int speed;
	Rectangle border, borderRight, borderLeft, borderTop, borderBottom;
};