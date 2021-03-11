#pragma once

#include "paddle.h"

class Graphics;

class Game {
public:
	Game();
	~Game();
private:
	void gameLoop();
	void draw(Graphics& graphics);
	void update(int elapsedTime);
	Paddle _paddleLeft;
};