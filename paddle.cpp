#include "paddle.h"

Paddle::Paddle(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) :
	Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY)
{}

void Paddle::moveUp() {
	this->_y = this->_y - 0.1f * 15;
}


