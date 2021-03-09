#include "input.h"

void Input::beginNewFrame() {
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

void Input::keyDownEvent(const SDL_Scancode& key) {
	this->_pressedKeys[key] = true;
	this->_heldKeys[key] = true;
}

void Input::keyUpEvent(const SDL_Scancode& key) {
	this->_releasedKeys[key] = true;
	this->_heldKeys[key] = false;
}

bool Input::wasKeyPressed(const SDL_Scancode& key) {
	return this->_pressedKeys[key];
}

bool Input::wasKeyReleased(const SDL_Scancode& key) {
	return this->_releasedKeys[key];
}

bool Input::isKeyHeld(const SDL_Scancode& key) {
	return this->_heldKeys[key];
}