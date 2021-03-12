#include "ball.h"

Ball::Ball() {}

Ball::Ball(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) :
	Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY)
{}