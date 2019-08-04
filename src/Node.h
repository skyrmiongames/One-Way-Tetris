#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "enums.h"
#include "textures.h"
#include "GridMaker.h"

/*
 * Single square with collision
 */

class Node : public sf::Sprite
{
private:
	//Node variables
	sf::Vector2i size;
	int color;

public:
	//Random static variables
	static Texture *texture;

	//Reset node
	set(sf::Vector2i size = sf::Vector2i(16, 16), int color);

	//Calculate rotation
	sf::Vector2i rotate(bool clockwise, sf::Vector2i origin);
};