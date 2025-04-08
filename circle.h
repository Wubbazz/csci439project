#include "shape.h"

class Circle : public Shape {
	public:
		void renderShape(SDL_Renderer* renderer);
		void updateShapePosition(float deltaTime);
		void isCollidingWindow(int width, int height);
		void setRadius(int rad);
		void flipXVelocity();
		void flipYVelocity();
	private:
		int radius;
		float xVelocity = 200.0f;
		float yVelocity = 200.0f;
};
