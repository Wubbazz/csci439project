#pragma once
#include <SDL2/SDL.h>
#include <iostream>
class Shape {
	public:
		void setPosition(int xpos, int ypos);
		virtual void renderShape(SDL_Renderer* renderer) = 0;
		virtual void updateShapePosition(float deltaTime) = 0;
		virtual void isCollidingWindow(int width, int height) = 0;
		virtual ~Shape() {}
	protected:
		float xPosition;
		float yPosition;
};

