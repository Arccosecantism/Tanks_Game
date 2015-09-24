#pragma once
#include "MenuElement.h"

class BasicButton : public MenuElement										//BasicButton is a menuElement that is a button with states based on mouse logic and with text.
{


public:
	
	BasicButton(sf::Vector2f fposition, ResourceGroup& fResourceGroup,		//Quite a long constructor, these thing define a BasicButton.
																			//You need position, a resourceGroup, a string for the text,
					std::string ftextName, sf::Color ftextColor,			//a color for the text, a size for the sprites, and a
																			//size for the text
					sf::Vector2f fspriteSize,	sf::Vector2f ftextSize);	//-----------------
				

	//-------------------------------------------
	//Virtual Functions that were inherited

	void update();															//necessary update inherited from MenuElement with an empty update vitrtual function
	
	void update(MouseData& fmouseData);										//this is the update used because it requires mouse data to determine button states
	
	void draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition);	//drawing something requires a renderwindow and a position to draw at

	//------------------------------------------



	void setRelativeSpritePosition(sf::Vector2f fpos);			//set the sprite position relative to the button poisiton. It's a bit weird but generalized

	void moveRelativeSpritePosition(sf::Vector2f fvel);			//change the sprite position releative to the button position



	void setRelativeTextPosition(sf::Vector2f fpos);						//set the Text position releative to the button position

	void moveRelativeTextPosition(sf::Vector2f fvel);						//change the text position releative to the button position


	int getButtonState();													//returns the state of the BasicButton
	
	

	//void setResources(ResourceGroup& rgroup);
	
	/*void setTextSize(int fsize);
	
	void setTextColor(sf::Color fcolor);
	
	void setTextString(std::string fstring);
	
	void setPosition(sf::Vector2f fposition);
	
	void setSpriteSize(sf::Vector2f  fsize);*/
	
	
	



private:
	

	void updateButtonState(MouseData& fmousedata);							//using mouse data, finds the current state of the button -- yes, click logic
	
	
	std::vector<sf::Sprite> buttonStateSprites;								//vector of sprites; 1 for each of the buttton states

	sf::Text buttonText;													//Text (which is an sf:: object) for the button NOT A STRING

	//sf::soundBuffer soundFX[2];											//will be soundbuffers
	
	sf::Vector2f textSize;													//the size of the text in terms of height and width

	sf::Vector2f spriteSize;												//the size of all the sprites in terms of height and width
	
	


	sf::Vector2f extremeCorners[2];											//a click logic helper; the top-left and bottom-right corners.
	
	int lastMouseHeld;														//a click logic helper; determines if the mouse was pressed down and held off of or on the button



	int buttonState;														//which state the BasicButton is in
	
	enum buttonStatePossibilities {Unheld, Hovered, Held, Unheld_Pressed, Hovered_Pressed, Held_Pressed, States_Number = 6, Clicked, Released};
																			//the '8' states of the button. States_Namber is just an index, and Clicked and Released are 
																			//one-frame states that dont have separate sprites
};

