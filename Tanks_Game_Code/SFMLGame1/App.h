#pragma once
#include "IncludeMe.h"

class App
{

public:
	App(sf::RenderWindow& fwindow);
	void setup();
	void doPerFrame();

private:

	void update();
	void draw();
	void getMouseData();
	void getKeyboardData();

	sf::Vector2i mouseData;
	std::vector<int> keys;
	sf::RenderWindow* window;

	sf::CircleShape tryme;


};