#pragma once
#include <vector>
#include "shape.h"

const int windowScaler = 50;

enum TokenType {
	Invalid = -1, 
	C,
	B,
};

struct Token {
	TokenType ttype;
	int xPos;
	int yPos;
};

int tokenize(std::vector<Shape*> &shapes, int &width, int &height);
