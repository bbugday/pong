#include "text.h"
#include <iostream>

std::map<std::string, TTF_Font*> Text::fonts = {};

Text::Text(const std::string& fontPath, SDL_Color color) :
	_font(loadFont(fontPath)),
	_textColor(color)
{
	TTF_Init();
}

void Text::loadFromRenderedText(SDL_Renderer* renderer, std::string textureText) {
	SDL_Surface* textSurface = TTF_RenderText_Solid(_font, textureText.c_str(), _textColor);
	if (textSurface == NULL) {
		std::cout << "textsurface is null" << std::endl;
		return;
	}
	this->_texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	this->_width = textSurface->w;
	this->_height = textSurface->h;
	SDL_FreeSurface(textSurface);
}

TTF_Font* Text::loadFont(const std::string& filePath) {
	//if (Text::fonts.count(filePath) == 0)
	//	Text::fonts[filePath] = TTF_OpenFont(filePath.c_str(), 28);
	//if (Text::fonts[filePath] == NULL) {
	//	std::cout << "font is null";
	//}
	//return Text::fonts[filePath];
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("assets/fonts/roboto-l-i.ttf", 16);
	if (!font) {
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
	}
	return font;
}

void Text::setFont(const std::string& fontPath) {
	this->_font = loadFont(fontPath);
}

void Text::draw(SDL_Renderer* renderer, Graphics& graphics) {
	//SDL_RenderCopy(renderer, _texture, NULL, destinationRect);
	SDL_Rect s = { 0, 0, this->_width, this->_height };
	graphics.blitSurface(this->_texture, &s, &s);
}


