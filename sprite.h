#pragma once

#include "graphics.h"
#include <SDL.h>

class Sprite {
public:
	Sprite();
	Sprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
	~Sprite();
	void draw(Graphics& graphics);
	float _scale;
protected:
	float _x, _y;
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;
private:
};