#include <stdlib.h>
#include <time.h>
#include "ball.h"
#include "globals.h"


Ball::Ball() {}

Ball::Ball(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) :
	Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY),
	_dx(10),
	_dy(0)
{}

void Ball::update(Paddle& paddleLeft, Paddle& paddleRight) {
	srand(time(NULL));
	int ySpeed = rand() % 21 - 10;

	if (this->collides(paddleRight)) {
		this->_x = paddleRight.getRectangle().x - 20;
		this->_dx = -this->_dx * 1.03;
		this->_dy = ySpeed;
	}

	if (this->collides(paddleLeft)) {
		this->_x = paddleLeft.getRectangle().x + 20;
		this->_dx = -this->_dx * 1.03;
		this->_dy = ySpeed;
	}

	if (this->_y + this->getRectangle().h >= globals::SCREEN_HEIGHT) {
		this->_dy = -this->_dy;
	}

	if (this->_y <= 0) {
		this->_dy = -this->_dy;
	}

	if (this->_x < 0 || this->_x + this->getRectangle().w > globals::SCREEN_WIDTH) {
		this->_x = globals::SCREEN_WIDTH / 2 - this->getRectangle().w / 2;
		this->_y = globals::SCREEN_HEIGHT / 2 - this->getRectangle().h / 2;
		this->_dx = 0;
		this->_dy = 0;
		paddleLeft.setPosition(20, globals::SCREEN_HEIGHT / 2 - globals::PADDLE_HEIGHT / 2);
		paddleRight.setPosition(globals::SCREEN_WIDTH - (20 + globals::PADDLE_WIDTH), globals::SCREEN_HEIGHT / 2 - globals::PADDLE_HEIGHT / 2);
	}

	this->_x += this->_dx;
	this->_y += this->_dy;
}

bool Ball::collides(Paddle& paddle) {
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