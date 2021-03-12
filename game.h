#pragma once

#include "paddle.h"
#include "ball.h"
#include "input.h"

class Graphics;

class Game {
public:
	Game();
	~Game();
private:
	void gameLoop();
	void draw(Graphics& graphics);
	void update();
	void handleInputs(Input& input);
	Paddle _paddleLeft;
	Paddle _paddleRight;
	Ball _ball;
};