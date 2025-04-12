#include <iostream>
#include <string>
#include "tokenizer.h"
#include "circle.h"
#include "block.h"

int tokenize(std::vector<Shape*> &shapes, int &width, int &height) {
	char nextChar;
	int topBorderCount = 0;
	nextChar = std::cin.get();
	while(nextChar == '-') {
		nextChar = std::cin.get();
		topBorderCount++;
	}
	if (nextChar != '\n') {
		std::cout << "Error: " << "\"" << nextChar << "\"" << " is not a valid border key" << std::endl;
		return -1;
	}
	// Get the next starting char
	nextChar = std::cin.get();
	int currentXPos = 1;
	int currentYPos = 1;
	while (nextChar == ' ' || nextChar == '\n' || nextChar == 'c' || nextChar == 'b') {
		if (nextChar == '\n') {
			currentYPos++;
			currentXPos = 0;
		}
		if (nextChar == 'c') {
			Circle* circle = new Circle();
			circle->setRadius(35);
			circle->setPosition(currentXPos * windowScaler, currentYPos * windowScaler);
			shapes.push_back(circle);
		}
		if (nextChar == 'b') {
			Block* block = new Block();
			block->setSize(75);
			block->setPosition(currentXPos * windowScaler, currentYPos * windowScaler);
			shapes.push_back(block);
		}
		nextChar = std::cin.get();
		currentXPos++;
	}
	if (nextChar != '-') {
		std::cout << "Error: Not a valid keyword at position: x:" << currentXPos << " y:" << currentYPos << std::endl;
		return -1;
	}
	int bottomBorderCount = 0;
	while(nextChar == '-') {
		nextChar = std::cin.get();
		bottomBorderCount++;
	}
	if (bottomBorderCount != topBorderCount) {
		std::cout << "Error: Border count not matching" << std::endl;
		std::cout << topBorderCount << ":" << bottomBorderCount << std::endl;
		return -1;
	}
	width = topBorderCount * windowScaler;
	height = currentYPos * windowScaler * 2;	
	return 0;
}
