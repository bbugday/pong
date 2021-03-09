#pragma once
#include <SDL.h>
#include <map>

class Input {
public:
	void beginNewFrame();
	void keyUpEvent(const SDL_Scancode& key);
	void keyDownEvent(const SDL_Scancode& key);

	bool wasKeyPressed(const SDL_Scancode& key);
	bool wasKeyReleased(const SDL_Scancode& key);
	bool isKeyHeld(const SDL_Scancode& key);
private:
	std::map<SDL_Scancode, bool> _heldKeys;
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;
};