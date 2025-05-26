#pragma once
#include <raylib.h>
class Map;
class SnoBee;
class Anims;

class Pengo {
public:
	Pengo(Anims* anims, Rectangle screenBorder, Map* map, Sound S_Push_Outside_Walls); //Constructor
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
	Sound Push_Outside_Walls;
	Anims* animations;
	int leftFramesCtr, rightFramesCtr, upFramesCtr, downFramesCtr, pushLeftFramesCtr, pushRightFramesCtr, pushUpFramesCtr, pushDownFramesCtr;
	int currentLeftX, currentRightX, currentUpX, currentDownX, currentPushLeftX, currentPushRightX, currentPushUpX, currentPushDownX;
	Rectangle leftFrameRec, rightFrameRec, upFrameRec, downFrameRec, pushLeftFrameRec, pushRightFrameRec, pushUpFrameRec, pushDownFrameRec;
	int pengoDirection; //1 - left, 2 - right, 3 - up, 4 - down
	bool isPushing;
	bool isPushAnimationPlaying;
	float pushAnimationTimer;
	float pushAnimationDuration;
protected:
	Vector2 position, targetPosition, startPosition;
	Vector2 respawnPosition = { 376, 378 };
	float amount;
	float speed;
	Rectangle border, borderRight, borderLeft, borderTop, borderBottom;
	float stunTimer = 0;
	float stunDuration = 2.5;
};