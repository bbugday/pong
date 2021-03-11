#include "paddle.h"
#include "globals.h"

namespace paddle_constants {
	const float SPEED = 10;
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
	if (this->_y < 0)
		this->_y = 0;
	if (this->_y > globals::SCREEN_HEIGHT - globals::PADDLE_HEIGHT)
		this->_y = globals::SCREEN_HEIGHT - globals::PADDLE_HEIGHT;
}

void Paddle::stopMoving() {
	this->_dy = 0;
}

