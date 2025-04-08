#include "block.h"

void Block::renderShape(SDL_Renderer* renderer) {
	SDL_Rect rect = { xPosition, yPosition, size, size};
	SDL_SetRenderDrawColor(renderer, 39, 84, 138, 255);
	SDL_RenderFillRect(renderer, &rect);	
}

void Block::updateShapePosition(float deltaTime) {
}

void Block::setSize(int squareSize) {
	size = squareSize;
}
void Block::isCollidingWindow(int width, int height) {
}
