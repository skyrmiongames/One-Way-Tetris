#include "GridMaker.h"

/*
 * Generates and stores main tilemap
 */

//Static variables
char GridMaker::tiles[HEIGHT][WIDTH];
int GridMaker::indexes[HEIGHT * WIDTH];

//Convert file to char[][]
void GridMaker::build_grid(std::string file) {
	//Get map file
	std::ifstream mapFile(file);

	//Set line variables
	int i = 0;
	std::string line;

	//Read file by line
	while(std::getline(mapFile, line)) {
		//Copy string
		for(int j = 0; line[j] != '\0'; j++)
			tiles[i][j] = line[j];

		i++;
	}
}

//Convert char[][] to int[][]
int* GridMaker::index_grid() {
	//Loop through tiles
	for(int y = 0; y < HEIGHT; y++)
		for(int x = 0; x < WIDTH; x++) {
			//Get tile texture index
			indexes[x + y * WIDTH] = index_tile(tiles[y][x]);
		}

	return indexes;
}

//Get integer index of tile texture
int GridMaker::index_tile(char c) {
	switch(c) {
		case '.':
			return 1;
		case '#':
			return 0;
		case '1':
			return 3;
		case '2':
			return 4;
		case '3':
			return 5;
		case '4':
			return 5;
		default:
			return 2;
	}
}

//Get tile char from grid
char GridMaker::get_tile(sf::Vector2f position) {
	int x = position.x / 16;
	int y = position.y / 16;

	return tiles[y][x];
}

//Get tile phase from grid
TileType GridMaker::check_tile(sf::Vector2f position) {
	char c = get_tile(position);

	switch(c) {
		case '#':
			return WALL;
		case '.':
			return EMPTY;
		default:
			return BLOCK;
	}
}

//Set tile properties
void GridMaker::set_tile(sf::Vector2f position, char value) {
	int x = position.x / 16;
	int y = position.y / 16;

	tiles[y][x] = value;
}