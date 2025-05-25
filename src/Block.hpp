#pragma once
#include <raylib.h>

class Block {
public:
	enum MovingDirection { //Possible directions
		none = 0, up = 1, down = 2, left = 3, right = 4
	};
	Rectangle rect;
	bool isActive;
	MovingDirection direction;
	Sound iceBlock_Destroyed;
	Sound Push_iceBlock;
	Sound Block_Stopped;

	Block(Rectangle r, Sound S_iceBlock_Destroyed, Sound S_Push_iceBlock, Sound S_Block_Stopped) { //Constructor
		iceBlock_Destroyed = S_iceBlock_Destroyed;
		Push_iceBlock = S_Push_iceBlock;
		Block_Stopped = S_Block_Stopped;
		rect = r;
		isActive = true;
		direction = none;
	}
};