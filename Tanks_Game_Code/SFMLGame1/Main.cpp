
#include "App.h"

int main()																//the main function
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");	//creates a renderwindow that draws everything 

	window.setFramerateLimit(60);

	App myApp(window);													//declare an App by giving it a renderWidow

	myApp.setup();														//setup the App


	while (window.isOpen())												//the main loop
	{
		sf::Event event;												//creates an event
		while (window.pollEvent(event))									//polls the event
		{
			myApp.checkEvents(event);									//event checking is in the App
		}

		window.clear();													//clear everything that has been drawn

		myApp.doPerFrame();												//run the doPerFrame funtion on App (updates, draws, etc.)

		window.display();												//display everything that has been drawn
	}

	return 0;															//returns 0
}