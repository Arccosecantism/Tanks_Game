
#include "App.h"

int main()
{



	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");



	App myApp(window);
	myApp.setup();


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			myApp.checkEvents(event);
		}

		window.clear();

		myApp.doPerFrame();

		window.display();
	}

	return 0;
}