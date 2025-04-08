#include "circle.h"

void Circle::renderShape(SDL_Renderer* renderer) {	
	SDL_SetRenderDrawColor(renderer, 221, 168, 83, 255);

	for (int y = -radius; y <= radius; ++y) {
        int x = static_cast<int>(sqrt(radius * radius - y * y));
        SDL_RenderDrawLine(renderer, static_cast<int>(xPosition) - x, static_cast<int>(yPosition) + y, static_cast<int>(xPosition) + x, static_cast<int>(yPosition) + y);
    }
}

void Circle::updateShapePosition(float deltaTime) {
	xPosition += xVelocity * deltaTime;
	yPosition += yVelocity * deltaTime;
	std::cout << xPosition << ":" << yPosition << std::endl;
}

void Circle::setRadius(int rad) {
	radius = rad;
}

void Circle::flipXVelocity() {
	xVelocity *= -1;
}

void Circle::flipYVelocity() {
	yVelocity *= -1;
}
void Circle::isCollidingWindow(int width, int height) {
	if (xPosition + radius > width) {
		flipXVelocity();
	}
	if (yPosition + radius > height) {
		flipYVelocity();
	}
	if (xPosition - radius < 0) {
		flipXVelocity();
	}
	if (yPosition - radius < 0) {
		flipYVelocity();
	}
}

