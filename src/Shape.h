#pragma once

#include "Node.h"
#include "enums.h"

#include <math.h>
#include <vector>

/*
 * Collection of squares
 */

class Shape: Node {
public:
	Shape() {}
	~Shape() {}

	//Movement
	bool move(Direction dir = DOWN);
	bool linear(Direction dir = DOWN);
	bool rotate(bool clockwise);

	//Start + end
	void generate(Shape shape);
	void lock();

	void drawParts(sf::RenderWindow &window);

protected:
	int speed = 16;
	std::vector<Node *> parts;
};