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
	Sound Ice_Block_Destroyed;
	Sound Push_Ice_Block;
	Sound Block_Stopped;

	Block(Rectangle r) {
		rect = r;
		isActive = true;
		direction = none;
	}
};