#include "ball.h"

Ball::Ball() {}

Ball::Ball(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) :
	Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY),
	_dx(10),
	_dy(0)
{}

void Ball::update(Paddle paddleLeft, Paddle paddleRight) {

	if (this->collides(paddleRight)) {
		this->_dx = -this->_dx * 1.03;
	}

	this->_x += this->_dx;
	this->_y += this->_dy;
}

bool Ball::collides(Paddle paddle) {
	SDL_Rect ballRectangle = this->getRectangle();
	SDL_Rect paddleRectangle = paddle.getRectangle();

	int ballLeft = ballRectangle.x;
	int ballRight = ballRectangle.x + ballRectangle.w;
	int ballTop = ballRectangle.y;
	int ballBottom = ballRectangle.y + ballRectangle.h;

	int paddleLeft = paddleRectangle.x;
	int paddleRight = paddleRectangle.x + paddleRectangle.w;
	int paddleTop = paddleRectangle.y;
	int paddleBottom = paddleRectangle.y + paddleRectangle.h;

	if (ballBottom <= paddleTop || ballTop >= paddleBottom || ballRight <= paddleLeft || ballLeft >= paddleRight)
		return false;

	return true;

}