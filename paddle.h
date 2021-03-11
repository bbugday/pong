#pragma once

#include "sprite.h"

class Paddle : public Sprite {
public:
	Paddle();
	Paddle(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
	void moveUp();
	void moveDown();
	void update(float elapsedTime);
	void stopMoving();
private:
	float _dy;
};