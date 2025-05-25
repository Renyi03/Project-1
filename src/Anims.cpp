#include "Anims.hpp"

void Anims::loadTextures()
{
	imgPengoLeft = LoadTexture("resources/Graphics/Pengo_sprites/Pengo_left.png");
	imgPengoRight = LoadTexture("resources/Graphics/Pengo_sprites/Pengo_right.png");
	imgPengoUp = LoadTexture("resources/Graphics/Pengo_sprites/Pengo_up.png");
	imgPengoDown = LoadTexture("resources/Graphics/Pengo_sprites/Pengo_down.png");
	imgPengoPushLeft = LoadTexture("resources/Graphics/Pengo_sprites/Pengo_push_left.png");
	imgPengoPushRight = LoadTexture("resources/Graphics/Pengo_sprites/Pengo_push_right.png");
	imgPengoPushUp = LoadTexture("resources/Graphics/Pengo_sprites/Pengo_push_up.png");
	imgPengoPushDown = LoadTexture("resources/Graphics/Pengo_sprites/Pengo_push_down.png");

	imgSnobeeLeft = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_left");
	imgSnobeeRight = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_right");
	imgSnobeeUp = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_up");
	imgSnobeeDown = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_down");
	imgSnobeeBreakLeft = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_break_left");
	imgSnobeeBreakRight = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_break_right");
	imgSnobeeBreakUp = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_break_up");
	imgSnobeeBreakDown = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_break_down");
	imgSnobeeStunned = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_stunned");

	imgBorderLeft = LoadTexture("resources/Graphics/Border_left_shaking");
	imgBorderRight = LoadTexture("resources/Graphics/Border_right_shaking");
	imgBorderTop = LoadTexture("resources/Graphics/Border_top_shaking");
	imgBorderBottom = LoadTexture("resources/Graphics/Border_bottom_shaking");
}

void Anims::unloadTextures()
{
	UnloadTexture(imgPengoLeft);
	UnloadTexture(imgPengoRight);
	UnloadTexture(imgPengoUp);
	UnloadTexture(imgPengoDown);
	UnloadTexture(imgPengoPushLeft);
	UnloadTexture(imgPengoPushRight);
	UnloadTexture(imgPengoPushUp);
	UnloadTexture(imgPengoPushDown);

	UnloadTexture(imgSnobeeLeft);
	UnloadTexture(imgSnobeeRight);
	UnloadTexture(imgSnobeeUp);
	UnloadTexture(imgSnobeeDown);
	UnloadTexture(imgSnobeeBreakLeft);
	UnloadTexture(imgSnobeeBreakRight);
	UnloadTexture(imgSnobeeBreakUp);
	UnloadTexture(imgSnobeeBreakDown);
	UnloadTexture(imgSnobeeStunned);

	UnloadTexture(imgBorderLeft);
	UnloadTexture(imgBorderRight);
	UnloadTexture(imgBorderTop);
	UnloadTexture(imgBorderBottom);
}
