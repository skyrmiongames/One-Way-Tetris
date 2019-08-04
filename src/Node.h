#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "enums.h"
#include "GridMaker.h"

/*
 * Single square with collision
 */

class Node : public sf::Sprite
{
protected:
	//Node variables
	sf::Vector2i size;
	int color;

public:
	//Random static variables
	static sf::Texture *texture;

	//Reset node
	void set(int color, sf::Vector2i size = sf::Vector2i(16, 16));

	//Calculate rotation
	sf::Vector2i rotate(bool clockwise, sf::Vector2i origin);
};