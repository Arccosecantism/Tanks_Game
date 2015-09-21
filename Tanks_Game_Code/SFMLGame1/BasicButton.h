#pragma once
#include "MenuElement.h"

class BasicButton : public MenuElement
{


public:

	
	
	BasicButton(sf::Vector2f fposition, ResourceGroup& fResourceGroup,

					std::string ftextName, sf::Color ftextColor,

					sf::Vector2f fspriteSize,	sf::Vector2f ftextSize);
				
				
	void update();
	
	void update(MouseData& fmouseData);
	
	void draw(sf::RenderWindow& frenderWindow);
	
	

	//void setResources(ResourceGroup& rgroup);
	
	/*void setTextSize(int fsize);
	
	void setTextColor(sf::Color fcolor);
	
	void setTextString(std::string fstring);
	
	void setPosition(sf::Vector2f fposition);
	
	void setSpriteSize(sf::Vector2f  fsize);*/
	
	
	
	int getButtonState();

private:
	
	void updateButtonState(MouseData& fmousedata);
	
	
	std::vector<sf::Sprite> buttonStateSprites;

	sf::Text buttonText; 

	//sf::soundBuffer soundFX[2];
	
	sf::Vector2f textSize;

	std::string buttonString;
	
	sf::Vector2f spriteSize;
	
	int buttonState;





	sf::Vector2f extremeCorners[2];
	
	sf::Vector2f halfDimensions;



	int lastMouseHeld;

	
	
	enum buttonStatePossibilities {Unheld, Hovered, Held, Unheld_Pressed, Hovered_Pressed, Held_Pressed, States_Number = 6, Clicked, Released};
	
	

	
};

