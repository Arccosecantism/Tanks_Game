#pragma once
#include "IncludeMe.h"

class App
{

public:

	App(sf::RenderWindow& fwindow);		//constructor; it needs a renderWindow
	void setup();						//setup all objects
	void doPerFrame();					//calls other functions to do every cycle

private:

	void update();						//update all objects
	void draw();						//draw all objects
	void getMouseData();				//gets mouse data
	void getKeyboardData();				//gets keyboard data

	sf::Vector2i mousePosition;			//where the mouse is
	int mouseDataHelpers[2][2];			//gives the mouseData. This is needed to know if a button transitions from being unheld to held
	//unheld is not pressing any buttons, pressed is the first frame when the a button is pressed, held is when you hold a button, 
	//and clicked is when you release a button
	enum mouseDataCases { UNHELD = 0, PRESSED = 1, HELD = 2, CLICKED = 3};
	sf::Vector2i mouseData;				//holds a left andright button value



	std::vector<int> keys;				//



	sf::RenderWindow* window;			//


};