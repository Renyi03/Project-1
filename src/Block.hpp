#pragma once
#include <raylib.h>

class Block {
public:
	enum MovingDirection {
		none = 0, up = 1, down = 2, left = 3, right = 4
	};
	Rectangle rect;
	bool isActive;
	MovingDirection direction;
	Block(Rectangle r) {
		rect = r;
		isActive = true;
		direction = none;
	}
};