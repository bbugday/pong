#include <SDL.h>
#include "game.h"
#include "graphics.h"
#include "sprite.h"
#include "input.h"

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
	SDL_Event event;
	Input input;
	Graphics graphics;
	Sprite sprite1 = Sprite(graphics, "assets/paddle.png", 0, 0, 16, 110, 0, 0);
	sprite1.draw(graphics);
	graphics.flip();
	while (true) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (!event.key.repeat) {
					input.keyDownEvent(event.key.keysym.scancode);
				}
			}
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event.key.keysym.scancode);
			}
			else if (event.type == SDL_QUIT) {
				return;
			}
		}
	}
}