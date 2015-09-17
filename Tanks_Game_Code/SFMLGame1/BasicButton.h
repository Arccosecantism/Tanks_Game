#pragma once
#include "MenuElement.h"

class BasicButton: public menuElement
{
public:

	void update();
	void update(MouseData& fmouseData);
	void draw(sf::RenderWindow& frenderWindow);

private:
	
	sf::Texture* buttonStateTextures[6];
	sf::Font* buttonFont; 
	//sf::soundBuffer soundFX[2]
	int buttonState;
	
	enum buttonStatePossibilities {Unheld, Hovered, Held, Unheld_Pressed, Hovered_Pressed, Held_Pressed, Clicked, Released};
	
};

