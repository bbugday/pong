#pragma once
#include "sprite.h"
#include "paddle.h"

class Ball : public Sprite{
public:
	Ball();
	Ball(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
	void update(Paddle paddleLeft, Paddle paddleRight);
	bool collides(Paddle paddle);
private:
	float _dy, _dx;
};