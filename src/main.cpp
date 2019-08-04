//SFML headers
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <thread>

//Game headers


//X11 multithreading on linux
#include <X11/Xlib.h>

bool running = true;

void renderingThread(Player *player, TileMap *map) {
	sf::RenderWindow window(sf::VideoMode(1200, 800), "One Way Tetris");

    //Run rendering loop
	while(window.isOpen()) {
		//Check event updates
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Draw base map
		window.clear();
		window.draw(*map);

		//Draw general nodes
		UpdateList::draw(window);

		//Confirm changes
		window.display();
	}

	running = false;
}

int main() {
	bool testMode = false;

	//Start game window
	XInitThreads();
	
	sf::Clock clock;

	//Set texture loader
	Textures *mainTextures = new Textures();
	Node::textures = mainTextures;

	//Mode variables
	NodeSpawner *spawner = new FullSpawner();
	std::string file = "resources/maps/full_map.txt";
	sf::Vector2f startPos = sf::Vector2f(456, 480);

	//Load base tile map
	GridMaker::build_grid(file);
	TileMap map;
    if (!map.load("resources/tiles/TileMap_Enviro.png", sf::Vector2u(16, 16), GridMaker::index_grid(), GridMaker::WIDTH, GridMaker::HEIGHT))
        return -1;

	//Set frame rate manager
	double nextFrame = 0;

	//Start rendering thread
	std::thread rendering(renderingThread, player, &map);

    //Run main window
	while (running) {
		//Manage frame rate
		if(clock.getElapsedTime().asSeconds() >= nextFrame) {
			//Next update time
			nextFrame = clock.getElapsedTime().asSeconds() + .001;

			
		}
	}

	return 0;
}