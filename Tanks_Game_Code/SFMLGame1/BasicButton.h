#pragma once
#include "MenuElement.h"

class BasicButton: public MenuElement
{
public:

	BasicButton();
	BasicButton(	sf::vector2f fposition,		ResourceGroup& fResourceGroup,
					std::string ftextName,		sf::Color ftextColor,
					double ftextSize, 			double fspriteSize);
				
				
	void update();
	
	void update(MouseData& fmouseData);
	
	void draw(sf::RenderWindow& frenderWindow);
	
	
	
	void setResources(ResourceGroup& rgroup);
	
	void setTextSize(int fsize);
	
	void setTextColor(sf::Color fcolor);
	
	void setTextString(std::string fstring);
	
	void setPosition(sf::vector2f fposition);
	
	void setSpriteSize(double fsize);
	
	
	
	int getButtonState();
	
	

private:


	void setExtremeValues();
	
	void updateButtonState(MouseData& fmousedata);
	
	
	sf::Sprite buttonStateSprites[6];
	sf::Text buttonText; 
	//sf::soundBuffer soundFX[2];
	
	std::string buttonString;
	sf::Color textColor;
	double textSize;
	
	double spriteSize;
	
	int buttonState;
	
	
	
	enum buttonStatePossibilities {Unheld, Hovered, Held, Unheld_Pressed, Hovered_Pressed, Held_Pressed, Clicked, Released};
	
	
	sf::vector2f position;
	
	sf::vector2f extremeCorners[2];
	
};

