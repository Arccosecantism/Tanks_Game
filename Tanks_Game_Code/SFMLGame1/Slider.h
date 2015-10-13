#pragma once
#include "MenuToolsInclude.h"

class Slider : public MenuElement
{
public:
	Slider(	sf::Texture* bgTexture, sf::Texture* fnotchTexture, sf::Texture* sbTexture, sf::Vector2f bgDimensions, sf::Vector2f fnotchDimensions,
			sf::Vector2f sbDimensions, sf::Vector2f fposition, double& fVariable, double fminBound, double fmaxBound, double fstartVal	);
	~Slider();


	void update();

	void update(MouseData& fmouseData);

	void draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition);

	void resetMD();

private:
	
	void updateElements();

	void updateSliderState(MouseData& fmouseData);

	double inNotch(double fpos);


	MenuSprite sliderButton;

	MenuSprite backgroundSprite;

	MenuSprite notchSprite;

	double* affectedNumber;

	double bounds[2];

	double scalingFactor;

	bool recordMousePos;


	sf::Vector2f lastDrawPosition;

	sf::Vector2f extremeCorners[2];

	int lastHeld;
};

