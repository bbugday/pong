#pragma once
#include <map>
#include <SDL_ttf.h>
#include <string>
#include <SDL.h>
#include "graphics.h"

class Text {
public:
	Text(const std::string& fontPath, SDL_Color color);
	void loadFromRenderedText(SDL_Renderer* renderer, std::string textureText);
	void draw(SDL_Renderer* renderer, Graphics& graphics);
	TTF_Font* loadFont(const std::string& filePath);
	void setFont(const std::string& fontPath);
	static std::map<std::string, TTF_Font*> fonts;
private:
	TTF_Font* _font;
	SDL_Texture* _texture;
	SDL_Color _textColor;
	int _width;
	int _height;
};