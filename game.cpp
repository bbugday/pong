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
	this->_paddleLeft = Paddle(graphics, "assets/paddle.png", 0, 0, 16, 110, 0, 0);
	
	int lastUpdateTime = SDL_GetTicks();
	int deltaTime = 0;

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
			_paddleLeft.moveUp();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_DOWN)) {
			_paddleLeft.moveDown();
		}
		if (!input.isKeyHeld(SDL_SCANCODE_UP) && !input.isKeyHeld(SDL_SCANCODE_DOWN)) {
			this->_paddleLeft.stopMoving();
		}

		int endTime = SDL_GetTicks();
		deltaTime = endTime - lastUpdateTime;
		this->update(deltaTime);
		int delay = frameMS - deltaTime;
		if (delay > 0)
			SDL_Delay(delay);
		this->draw(graphics);
		lastUpdateTime = SDL_GetTicks();
	}
}

void Game::draw(Graphics& graphics) {
	graphics.clear();
	this->_paddleLeft.draw(graphics);
	graphics.flip();
}

void Game::update(int elapsedTime) {
	this->_paddleLeft.update(elapsedTime);
}