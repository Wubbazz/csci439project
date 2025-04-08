#include <iostream>
#include <SDL2/SDL.h>
#include <unistd.h>
#include <vector>
#include "tokenizer.h"
#include "shape.h"
#include "circle.h"

SDL_Window* window;
SDL_Renderer* renderer;
bool isRunning = true;
int lastFrametime = 0;
int width;
int height;

bool initialize(int height, int width);

void getInput();

void update(std::vector<Shape*> &shapes);

void render(std::vector<Shape*> &shapes);

void cleanUp(std::vector<Shape*> &shapes);

/**************************Main****************************************/
int main() {
	std::vector<Shape*> objs;
	if(tokenize(objs, width, height) != -1) {
		initialize(height, width);
		while (isRunning) {
			getInput();
			update(objs);
			render(objs);
		}
		cleanUp(objs);
	}
	return 0;
}
/**************************implementations*****************************/

bool initialize(int height, int width) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "ERROR: Could not initilize SDL" << std::endl;
		return false;
	}
	window = SDL_CreateWindow("CoolWindow", 
							0,
							0,
							width,
							height,
							SDL_WINDOW_SHOWN
							);
	if (!window) {
		std::cerr << "ERROR: Could not initilize SDL Window" << std::endl;
		return false;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		std::cerr << "ERROR: Could not initilize SDL Renderer" << std::endl;
		return false;
	}	
	return true;
}

void getInput() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			isRunning = false;
		}
	}
}

void update(std::vector<Shape*> &shapes) {
	float deltaTime = (SDL_GetTicks() - lastFrametime)/1000.0f;
	lastFrametime = SDL_GetTicks();
	std::cout << deltaTime << std::endl;
	for (Shape* sp : shapes) {
		sp->isCollidingWindow(width, height);
		sp->updateShapePosition(deltaTime);
	}
}

void render(std::vector<Shape*> &shapes) {
	SDL_SetRenderDrawColor(renderer, 245, 238, 220, 255);
	SDL_RenderClear(renderer);
	/*		
	SDL_Rect rect = { 50, 100, 200, 200};
	SDL_SetRenderDrawColor(renderer, 0,0,0,255);
	SDL_RenderFillRect(renderer, &rect);	
    int radius = 50;
		
	for (int y = -radius; y <= radius; ++y) {
        int x = static_cast<int>(sqrt(radius * radius - y * y));
        SDL_RenderDrawLine(renderer, centerX - x, centerY + y, centerX + x, centerY + y);
    }
	*/	
	for (int i = 0; i < (int) shapes.size(); i++) {
		shapes[i]->renderShape(renderer);
	}

	SDL_RenderPresent(renderer);
	//centerX += 1;
	//centerY += 1;
}

void cleanUp(std::vector<Shape*> &shapes) {
	for (int i = 0; i < (int)shapes.size(); i++) {
		delete shapes[i];
	}
	shapes.clear();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
