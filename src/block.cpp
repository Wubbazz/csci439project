#include "block.h"

void Block::renderShape(SDL_Renderer* renderer) {
	SDL_Rect rect = { static_cast<int>(xPosition), static_cast<int>(yPosition), size, size};
	SDL_SetRenderDrawColor(renderer, 39, 84, 138, 255);
	SDL_RenderFillRect(renderer, &rect);	
}

void Block::updateShapePosition(float deltaTime) {
	xPosition += xVelocity * deltaTime;	
}

void Block::setSize(int squareSize) {
	size = squareSize;
}
void Block::isCollidingWindow(int width, int height) {
	if (xPosition + size >= width) {
		xVelocity *= -1;
	}
	if (xPosition <= 0) {
		xVelocity *= -1;
	}
	if (yPosition < height) {
		// still working on this
	}
}
