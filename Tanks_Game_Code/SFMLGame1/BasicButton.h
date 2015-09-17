#pragma once
#include "MenuElement.h"

class BasicButton: public MenuElement
{
public:

	BasicButton();
	void update();
	void update(MouseData& fmouseData);
	void draw(sf::RenderWindow& frenderWindow);
	void setTextures(ResourceGroup& rgroup);
	int getButtonState();

private:

	void updateButtonState(MouseData& fmousedata);
	
	
	sf::Sprite buttonStateSprites[6];
	sf::Text buttonText; 
	//sf::soundBuffer soundFX[2];
	
	std::string buttonString;
	sf::Color textColor;
	int textSize;
	
	int buttonState;
	
	
	
	enum buttonStatePossibilities {Unheld, Hovered, Held, Unheld_Pressed, Hovered_Pressed, Held_Pressed, Clicked, Released};
	
};

