#include "Shape.h"

/*
 * Collection of squares
 */

std::map<ShapeType, Points*> ShapeMaps::shapes;

//Normal move squares
bool Shape::move(Direction dir) {
	if(dir == CLOCK || dir == COUNTER)
		return rotate(dir == CLOCK);
	return linear(dir);
}

//Move in linear direction
bool Shape::linear(Direction dir) {
	sf::Vector2f offset(0, 0);

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
		default:
			return false;
	}

	//Test all parts
	for(Node *n : parts) {
		sf::Vector2f target = n->getPosition() + offset;
		if(GridMaker::check_tile(target) != EMPTY)
			return false;
	}

	//Move all parts
	for(Node *n : parts)
		n->setPosition(n->getPosition() + offset);
	
	//Move origin
	setPosition(getPosition() + offset);
	return false;
}

//Rotate
bool Shape::rotate(bool clockwise) {
	return false;
}

//Set node locations
void Shape::generate(ShapeType shape, sf::Vector2f position) {
	setPosition(position);

	Points *list = ShapeMaps::shapes[shape];
	int i = 0;

	for(Node *n : parts) {
		n->setPosition(position + list->get(i));
		i++;
	}
}

//Lock nodes to grid
void Shape::lock() {
	for(Node *n : parts)
		GridMaker::set_tile(n->getPosition(), color + '0');
}

void Shape::drawParts(sf::RenderWindow &window){
	for(Node *n : parts)
		window.draw(*n);
}