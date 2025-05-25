#pragma once
#include <raylib.h>

class Anims {
public:
	Texture2D imgPengoLeft;
	Texture2D imgPengoRight;
	Texture2D imgPengoUp;
	Texture2D imgPengoDown;
	Texture2D imgPengoPushLeft;
	Texture2D imgPengoPushRight;
	Texture2D imgPengoPushUp;
	Texture2D imgPengoPushDown;

	Texture2D imgSnobeeLeft;
	Texture2D imgSnobeeRight;
	Texture2D imgSnobeeUp;
	Texture2D imgSnobeeDown;
	Texture2D imgSnobeeBreakLeft;
	Texture2D imgSnobeeBreakRight;
	Texture2D imgSnobeeBreakUp;
	Texture2D imgSnobeeBreakDown;
	Texture2D imgSnobeeStunned;

	Texture2D imgBorderLeft;
	Texture2D imgBorderRight;
	Texture2D imgBorderTop;
	Texture2D imgBorderBottom;

	void loadTextures();
	void unloadTextures();
};