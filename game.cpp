#include <SDL.h>
#include "game.h"
#include "graphics.h"
#include "paddle.h"
#include "input.h"
#include "globals.h"
#include "ball.h"


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
	this->_ball = Ball(graphics, "assets/ball.png", 0, 0, globals::BALL_WIDTH, globals::BALL_HEIGHT,
		globals::SCREEN_WIDTH / 2 - globals::BALL_WIDTH / 2, globals::SCREEN_HEIGHT / 2 - globals::BALL_HEIGHT / 2);
	this->_paddleLeft = Paddle(graphics, "assets/paddle.png", 0, 0, globals::PADDLE_WIDTH, globals::PADDLE_HEIGHT, 20, 
		globals::SCREEN_HEIGHT/2 - globals::PADDLE_HEIGHT/2);
	this->_paddleRight = Paddle(graphics, "assets/paddle.png", 0, 0, globals::PADDLE_WIDTH, globals::PADDLE_HEIGHT,
		globals::SCREEN_WIDTH - (20 + globals::PADDLE_WIDTH), globals::SCREEN_HEIGHT / 2 - globals::PADDLE_HEIGHT / 2);
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

		this->handleInputs(input);

		int endTime = SDL_GetTicks();
		deltaTime = endTime - lastUpdateTime;
		this->update();
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
	this->_paddleRight.draw(graphics);
	this->_ball.draw(graphics);
	graphics.flip();
}

void Game::update() {
	this->_paddleLeft.update();
	this->_paddleRight.update();
	this->_ball.update(_paddleLeft, _paddleRight);
	this->handleGoal();
}

void Game::handleInputs(Input& input) {
	if (input.isKeyHeld(SDL_SCANCODE_UP)) {
		_paddleRight.moveUp();
	}
	else if (input.isKeyHeld(SDL_SCANCODE_DOWN)) {
		_paddleRight.moveDown();
	}
	if (!input.isKeyHeld(SDL_SCANCODE_UP) && !input.isKeyHeld(SDL_SCANCODE_DOWN)) {
		this->_paddleRight.stopMoving();
	}

	if (input.isKeyHeld(SDL_SCANCODE_W)) {
		_paddleLeft.moveUp();
	}
	else if (input.isKeyHeld(SDL_SCANCODE_S)) {
		_paddleLeft.moveDown();
	}
	if (!input.isKeyHeld(SDL_SCANCODE_W) && !input.isKeyHeld(SDL_SCANCODE_S)) {
		this->_paddleLeft.stopMoving();
	}
}

void Game::handleGoal() {
	SDL_Rect ballRect = _ball.getRectangle();

	if (ballRect.x + ballRect.w <= 0) {
		resetPositions();
		_ball.setSpeed(-10, 0);
		SDL_Delay(100);
	}
	else if (ballRect.x >= globals::SCREEN_WIDTH) {
		resetPositions();
		_ball.setSpeed(10, 0);
		SDL_Delay(100);
	}
}

void Game::resetPositions() {
	_ball.setPosition(globals::SCREEN_WIDTH / 2 - globals::BALL_WIDTH / 2, globals::SCREEN_HEIGHT / 2 - globals::BALL_HEIGHT / 2);
	_paddleLeft.setPosition(20, globals::SCREEN_HEIGHT / 2 - globals::PADDLE_HEIGHT / 2);
	_paddleRight.setPosition(globals::SCREEN_WIDTH - (20 + globals::PADDLE_WIDTH), globals::SCREEN_HEIGHT / 2 - globals::PADDLE_HEIGHT / 2);
}