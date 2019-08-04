#pragma once

#include "Node.h"
#include "enums.h"
#include "GridMaker.h"

#include <math.h>

/*
 * Collection of squares
 */

class Entity {
public:
	Entity() {}
	~Entity() {}

	bool move(Direction dir = DOWN) {
		if(dir == CLOCK || dir == COUNTER)
			return rotate(dir == CLOCK)
		return linear(dir);
	}

	//Move in linear direction
	bool linear(Direction dir = DOWN) {
		sf::Vector2i offset();

		//Set linear movement
		switch(dir) {
			case LEFT:
				offset.x = -speed;
				break;
			case RIGHT:
				offset.x = speed;
				break;
			case DOWN:
				offset.y = speed;
				break;
		}

		//Test all parts
		for(int i = 0; i < 4; i++) {
			sf::Vector2i target = nodes[i].getPosition() + offset;
			if(GridMaker::check_tile(target) != EMPTY)
				return false;
		}

		//Move all parts
		for(int j = 0; j < 4; j++)
			nodes[j].setPosition(nodes[i].getPosition() + offset);
		
		//Move origin
		origin.x += xOffset;
		origin.y += yOffset;
		return false;
	}

	//Rotate
	bool rotate(bool clockwise) {

	}

	// virtual void update() {};

protected:
	sf::Vector2i origin;
	int speed = 16;
	Node nodes[4];
};