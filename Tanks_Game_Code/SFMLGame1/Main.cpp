
#include "IncludeMe.h"
#include "App.h"

int main()
{



	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");



	App myApp(window);
	myApp.setup();


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		myApp.doPerFrame();

		window.display();
	}

	return 0;
}