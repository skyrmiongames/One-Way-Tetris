#pragma once
#define PI 3.14159265

/*
 * Created by Stuart Irwin on 4/13/2019.
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

enum Shape {
	LINE,
	SQUARE,
	CROSS,
	LEFT,
	RIGHT
};