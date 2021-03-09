#include <SDL.h>
#undef main
#include "game.h"

int main(int argc, const char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	Game game;
	return 0;
}