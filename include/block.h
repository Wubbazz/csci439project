#include "shape.h"

class Block : public Shape {
	public:
		void renderShape(SDL_Renderer* renderer);
		void updateShapePosition(float deltaTime);
		void isCollidingWindow(int width, int height);
		void setSize(int squareSize);
	private:
		int size;
		float xVelocity = 100.0f;
};
