#pragma once
#include <raylib.h>

class Block {
	
public:
	Rectangle rect;
	Block(Rectangle r) {
		rect = r;
	}
};