#include "Shape.h"

/*
 * Collection of squares
 */

//Normal move squares
bool Shape::move(Direction dir) {
	if(dir == CLOCK || dir == COUNTER)
		return rotate(dir == CLOCK)
	return linear(dir);
}

//Move in linear direction
bool Shape::linear(Direction dir) {
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
	for(Node *n : parts) {
		sf::Vector2i target = n.getPosition() + offset;
		if(GridMaker::check_tile(target) != EMPTY)
			return false;
	}

	//Move all parts
	for(Node *n : parts)
		n.setPosition(n.getPosition() + offset);
	
	//Move origin
	setPosition(getPosition() + offset);
	return false;
}

//Rotate
bool Shape::rotate(bool clockwise) {

}

//Set node locations
void Shape::generate(Shape shape, sf::Vector2i position) {
	setPosition(position);
}

//Lock nodes to grid
void Shape::lock() {
	for(Node *n : parts)
		GridMaker::set_tile(n->getPosition(), color + '0');
}

// virtual void update() {};

void Shape::drawParts(sf::RenderWindow &window){
	for(Node *n : parts)
		window.draw(*n);
}