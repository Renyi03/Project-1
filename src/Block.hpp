#pragma once
#include <raylib.h>

class Block {
	Rectangle rect;
public:
	Block(Rectangle r) {
		rect = r;
	}
};