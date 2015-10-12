#pragma once
#include "MenuToolsInclude.h"

class Slider : public MenuElement
{
public:
	Slider(	sf::Texture* bgTexture, sf::Texture* fnotchTexture, sf::Vector2f bgDimensions, sf::Vector2f fnotchDimensions,
			BasicButton& fsliderButton, sf::Vector2f fposition, double* fVariable, double fmaxBound, double fminBound, double fstartVal);
	~Slider();


	void update();

	void update(MouseData& fmouseData);

	void draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition);

	void resetMD();

private:

	static void switchRecordMousePos(void* fslider);

	void callSwitchRecordMousePos();
	

	double inNotch(double fpos);


	BasicButton sliderButton;

	MenuSprite backgroundSprite;

	MenuSprite notchSprite;

	double* affectedNumber;

	double bounds[2];

	double scalingFactor;

	bool recordMousePos;
};

