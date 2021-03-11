#include <SDL.h>
#include "game.h"
#include "graphics.h"
#include "paddle.h"
#include "input.h"

#include <iostream>


Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
	const int FPS = 60;
	const int frameMS = 1000 / FPS;
	SDL_Event event;
	Input input;
	Graphics graphics;
	Paddle paddle1 = Paddle(graphics, "assets/paddle.png", 0, 0, 16, 110, 0, 0);
	paddle1.draw(graphics);
	graphics.flip();

	int lastUpdateTime = SDL_GetTicks();

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
		if (input.isKeyHeld(SDL_SCANCODE_UP)) {
			paddle1.moveUp();
		}

		graphics.clear();
		paddle1.draw(graphics);
		graphics.flip();

		int endTime = SDL_GetTicks();
		int deltaTime = endTime - lastUpdateTime;
		int delay = frameMS - deltaTime;

		if(delay>0)
			SDL_Delay(delay);
		lastUpdateTime = SDL_GetTicks();
		
	}
}