#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "enums.h"
#include "textures.h"

/*
 * Created by Stuart Irwin on 4/13/2019.
 * Sprite with collision
 */

class Node : public sf::Sprite
{
private:
	//Node variables
	sf::Vector2i size;
	bool deleted = false;

public:
	//Random static variables
	static Textures *textures;

	//Node constructors
	Node(sf::Vector2i size = sf::Vector2i(16, 16));

	//Base getters
	sf::Vector2i get_size();

	//Proper deletion procedure
	bool get_delete();
	void set_delete();
	virtual ~Node();

	//Entity implementation
	virtual void update(double time);
};