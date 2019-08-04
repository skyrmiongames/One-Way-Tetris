#include "Node.h"

/*
 * Created by Stuart Irwin on 4/16/2019.
 * Sprite with collision
 */

//static variable reference thing
Textures *Node::textures;

//Base constructor
Node::Node(sf::Vector2i size) {
	this->layer = layer;
	this->size = size;

	setOrigin(size.x / 2, size.y / 2);
}

//Get collision size
sf::Vector2i Node::get_size() {
	return size;
}

//Get collision layer
CollisionLayer Node::get_layer() {
	return layer;
}

//Check for deletion mark
bool Node::get_delete() {
	return deleted;
}

//Mark for deletion
void Node::set_delete() {
	deleted = true;
}
Node::~Node() {}

//Define virtual placeholders
void Node::update(double time) {}