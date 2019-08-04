#include "Node.h"

/*
 * Single square with collision
 */

//static variable reference thing
sf::Texture *Node::texture;

//Base constructor
void Node::set(int color, sf::Vector2i size) {
	this->size = size;

	setTextureRect(sf::IntRect (16 * color, 16, 16 * color + 16, 32));
	setOrigin(size.x / 2, size.y / 2);
}

//Get rotated position
sf::Vector2i Node::rotate(bool clockwise, sf::Vector2i origin) {
	return sf::Vector2i();
}