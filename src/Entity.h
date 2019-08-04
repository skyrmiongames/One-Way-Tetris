#pragma once

#include "Node.h"
#include "enums.h"
#include "GridMaker.h"

#include <math.h>


class Entity : public Node {

public:
	Entity(
		CollisionLayer _layer = ENEMY,
		sf::Vector2i _size = sf::Vector2i(10, 16),
		double _speed = 1.0,
	) : Node(_layer, _size), speed(_speed)
	{
		
	}

	~Entity() {}

	bool move(
		Direction dir = DOWN,
		float distance = 16,
	) {
		int xOffset = 0;
		int yOffset = 0;

		switch(dir) {
			case LEFT:
				xOffset = -1;
				break;
			case RIGHT:
				xOffset = -1;
				break;
			case DOWN:
				yOffset = 1;
				break;
		}

		sf::Vector2f target(getPosition().x + xOffset, getPosition().y + yOffset);
		TileType targetType = GridMaker::check_tile(target);

		if (targetType != EMPTY) {
			setPosition(sf::Vector2f(target.x, target.y));
			return true;
		}
		return false;
	}

	// virtual void update() {};

protected:
	double speed;
};