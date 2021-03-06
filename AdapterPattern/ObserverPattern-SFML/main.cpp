#include "stdafx.h"
#include "Controller.h"


int main()
{

	if (!DIM::font.loadFromFile("Font/arial.ttf")) {
		exit(1);
	}

	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Adapter Pattern");
	window->setFramerateLimit(60);

	Controller *controller = new Controller(window);
	//Year *controller = new Year(window, 2018);
	
	while (window->isOpen())
	{


		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}

			if (event.type == sf::Event::MouseButtonPressed) {
				controller->mousePressed();
			}

			if (event.key.code == sf::Keyboard::Escape) {
				controller->escapePressed();
			}

		}

		window->clear();

		controller->display();

		window->display();
	}

    return 0;
}

