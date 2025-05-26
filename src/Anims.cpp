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

	imgSnobeeLeft = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_left.png");
	imgSnobeeRight = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_right.png");
	imgSnobeeUp = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_up.png");
	imgSnobeeDown = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_down.png");
	imgSnobeeBreakLeft = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_break_left.png");
	imgSnobeeBreakRight = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_break_right.png");
	imgSnobeeBreakUp = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_break_up.png");
	imgSnobeeBreakDown = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_break_down.png");
	imgSnobeeStunned = LoadTexture("resources/Graphics/Snobee_sprites/Snobee_stunned.png");

	imgBorderLeft = LoadTexture("resources/Graphics/Border_left_shaking.png");
	imgBorderRight = LoadTexture("resources/Graphics/Border_right_shaking.png");
	imgBorderTop = LoadTexture("resources/Graphics/Border_top_shaking.png");
	imgBorderBottom = LoadTexture("resources/Graphics/Border_bottom_shaking.png");
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
