#include "Pengo.hpp"
#include<raylib.h>



Pengo::Pengo()
{
	image = LoadTexture("Graphics/Pengo front.png");
	position.x = 400;
	position.y = 400;
	speed = 10;
}

Pengo::~Pengo() 
{
	UnloadTexture(image);
}

void Pengo::Draw() {
	DrawTextureV(image, position, WHITE);
}

void Pengo::Update() {
	
}