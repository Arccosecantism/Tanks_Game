#pragma once
#include "MainMenu.h"
#include "Player.h"
#include "HitBoxInclude.h"
#include "GameMap.h"

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



	void setupResourceManager();							//adds files to generalResourceManager



	MouseData mouseInfo;									//THE ONLY mouse data. it gets sent around a lot, but it gets updated in App.cpp
		



	enum mouseInfoCases { UNHELD = 0, PRESSED = 1, HELD = 2, RELEASED = 3 };	
															/*unheld is not pressing any buttons, pressed is the first frame 
															when the a button is pressed, held is when you hold a button, 
															and released is when you release a button*/


	

	std::vector<int> keys;									//vector of pressed keys, stored as the key index



	sf::RenderWindow* window;								//pointer to a render window

	ResourceManager generalResourceManager;					//the ResourceManager for everything in the App, which is almost everything


	//MainMenu startingMenu;									//The MAinMenu for the program
	

	Player testPlayer;
	ConvexHitBox testor;
	GameMap GMtest;


};