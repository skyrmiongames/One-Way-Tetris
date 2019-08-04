#pragma once
#define PI 3.14159265

/*
 * enums for tiles and collision
 */

enum TileType {
	WALL,
	BLOCK,
	EMPTY
};

enum Direction {
	LEFT,
	CLOCK,
	RIGHT,
	COUNTER,
	DOWN
};

enum ShapeType {
	LINE,
	SQUARE,
	CROSS,
	LEFTL,
	RIGHTL
};