#include <SFML/Graphics.hpp>
#include "util.h"
#include "BodySystem.h"

//---------------------------------------------------------------------
// Orbital Simulator
// This program currently runs an N-body simulation using a basic
// brute force algorithm and renders the bodies onto the screen. Future
// additions include an implementation of the Barnes-Hut algorithm,
// generation of large-N systems, and path trajectory/maneuver
// calculations. See the README for more info.
//---------------------------------------------------------------------
int main()
{
	sf::RenderWindow window(sf::VideoMode(orbutil::SCREEN_WIDTH, orbutil::SCREEN_HEIGHT), "Orbit Simulator");
	sf::Clock clock;
	sf::Time timeSinceLastUpdate;

	BodySystem system;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
		}

		timeSinceLastUpdate = clock.restart();
		system.update(timeSinceLastUpdate);

		window.clear();
		window.draw(system);
		window.display();
	}

	return 0;
}