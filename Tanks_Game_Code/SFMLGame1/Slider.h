#pragma once
#include "MenuToolsInclude.h"

class Slider : public MenuElement
{
public:
	Slider(	sf::Texture* bgTexture, sf::Texture* fnotchTexture, sf::Vector2f bgDimensions, sf::Vector2f fnotchDimensions,
			BasicButton fsliderButton, sf::Vector2f fposition, double* fVariable, double fmaxBound, double fminBound, double fstartVal);
	~Slider();

private:

	BasicButton sliderButton;

	MenuSprite backgroundSprite;

	MenuSprite notchSprite;
};

