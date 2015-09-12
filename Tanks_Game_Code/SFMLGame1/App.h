#pragma once
#include "IncludeMe.h"

class App
{

public:

	App(sf::RenderWindow& fwindow);							//constructor; it needs a renderWindow
	void setup();											//setup all objects
	void doPerFrame();										//calls other functions to do every cycle
	void checkEvents(sf::Event& fevent);					//checks important events like mouse data


private:

	void update();											//update all objects
	void draw();											//draw all objects
	void getKeyboardData();									//gets keyboard data
	void resetMouseData();									//resets mouse data



	sf::Vector2i mouseData;									//holds a left and right button value
	sf::Vector2i mousePosition;								//where the mouse is
		
	enum mouseDataCases { UNHELD = 0, PRESSED = 1, HELD = 2, RELEASED = 3 };	
															/*unheld is not pressing any buttons, pressed is the first frame 
															when the a button is pressed, held is when you hold a button, 
															and released is when you release a button*/


	

	std::vector<int> keys;									//



	sf::RenderWindow* window;								//pointer to a render window


};