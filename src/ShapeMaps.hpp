#pragma once

#include <SFML/Graphics.hpp>
#include "enums.h"
#include <map>

using std::pair;

/*
 * Map of each shape and the node positions
 */

class Points {
public:
	sf::Vector2f parts[4];

	Points(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
		parts[0] = sf::Vector2f(x1, x1);
		parts[1] = sf::Vector2f(x2, x2);
		parts[2] = sf::Vector2f(x3, x3);
		parts[3] = sf::Vector2f(x4, x4);
	}

	Points(const Points&) {

	}

	sf::Vector2f get(int i) {
		return parts[i];
	}
};

class ShapeMaps {
public:
	static std::map<ShapeType, Points*> shapes;

	static void build() {
		ShapeMaps::shapes.insert(pair<ShapeType, Points*>(LINE, new Points(
			0, 0, 1, 0, 2, 0, 3, 0
		)));
		ShapeMaps::shapes.insert(pair<ShapeType, Points*>(SQUARE, new Points(
			0, 0, 1, 0, 2, 0, 3, 0
		)));
		ShapeMaps::shapes.insert(pair<ShapeType, Points*>(CROSS, new Points(
			0, 0, 1, 0, 2, 0, 3, 0
		)));
		ShapeMaps::shapes.insert(pair<ShapeType, Points*>(LEFTL, new Points(
			0, 0, 1, 0, 2, 0, 3, 0
		)));
		ShapeMaps::shapes.insert(pair<ShapeType, Points*>(RIGHTL, new Points(
			0, 0, 1, 0, 2, 0, 3, 0
		)));
	}

	static Points *get(ShapeType shape) {
		return shapes[shape];
	}
};
