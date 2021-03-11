#include "paddle.h"

namespace paddle_constants {
	const float SPEED = 5;
}

Paddle::Paddle(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) :
	Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY),
	_dy(0)
{}

Paddle::Paddle(){}

void Paddle::moveUp() {
	this->_dy = -paddle_constants::SPEED;
}

void Paddle::moveDown() {
	this->_dy = paddle_constants::SPEED;
}

void Paddle::update(float elapsedTime) {
	//this->_y = this->_y + this->_dy * elapsedTime;
	this->_y = this->_y + this->_dy;
}

void Paddle::stopMoving() {
	this->_dy = 0;
}

