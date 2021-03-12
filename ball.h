#pragma once
#include "sprite.h"

class Ball : public Sprite{
public:
	Ball();
	Ball(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
private:
	float _dy, _dx;
};