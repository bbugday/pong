#include "sprite.h"
#include <SDL.h>

Sprite::Sprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) :
	_x(posX),
	_y(posY),
	_scale(1)
{
	this->_sourceRect.x = sourceX;
	this->_sourceRect.y = sourceY;
	this->_sourceRect.w = width;
	this->_sourceRect.h = height;

	this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
	if (this->_spriteSheet == NULL) {
		printf("Unable to load image");
	}
}

Sprite::Sprite() {}

Sprite::~Sprite() {}

void Sprite::draw(Graphics& graphics) {
	graphics.blitSurface(this->_spriteSheet, &this->_sourceRect, &getRectangle());
}

SDL_Rect Sprite::getRectangle() {
	SDL_Rect rect = { this->_x, this->_y, this->_sourceRect.w * _scale, this->_sourceRect.h * _scale };
	return rect;
}

void Sprite::setPosition(float x, float y) {
	this->_x = x;
	this->_y = y;
}