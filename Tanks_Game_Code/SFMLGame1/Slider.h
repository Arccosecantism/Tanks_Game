#pragma once
#include "MenuToolsInclude.h"

class Slider : public MenuElement											//think volume slider
{
public:
	Slider(	sf::Texture* bgTexture, sf::Texture* fnotchTexture, sf::Texture* sbTexture, sf::Vector2f bgDimensions, sf::Vector2f fnotchDimensions,
			sf::Vector2f sbDimensions, sf::Vector2f fposition, double& fVariable, double fminBound, double fmaxBound, double fstartVal	);
																			//huge constuctor
	~Slider();																//destructor


	//inherited virtual
	void update();

	void update(MouseData& fmouseData);

	void draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition);

	void resetMD();

private:
	
	void updateElements();													//updates the sliderButton, backgroundSprite, and notchSprite

	void updateSliderState(MouseData& fmouseData);							//updates whether slider is being held down

	double inNotch(double fpos);											//returns the entered value but has a min and a max relative to the notch


	MenuSprite sliderButton;												//the button that you can slide around

	MenuSprite backgroundSprite;											//the background sprite

	MenuSprite notchSprite;													//the notch the butotn slider moves around in

	double* affectedNumber;													//the number that the slider affects
		
	double bounds[2];														//the bounds of the notch

	double scalingFactor;													//the scaling factor from the position of the slider button to the affected number


	sf::Vector2f lastDrawPosition;											//the last position the slider was being draw at -- useful for mouse collision

	sf::Vector2f extremeCorners[2];											//the top left and bottom right corners of the button slider

	int lastHeld;															//an ad hoc trinary bool; determines if the mouse was last held on the sliderbutton, off the slider butgton, or not held at all 
};

