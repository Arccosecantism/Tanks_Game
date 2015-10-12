#include "Slider.h"


Slider::Slider(	sf::Texture* bgTexture, sf::Texture* fnotchTexture, sf::Vector2f bgDimensions, sf::Vector2f fnotchDimensions,
				BasicButton& fsliderButton, sf::Vector2f fposition, double* fVariable, double fmaxBound, double fminBound, double fstartVal)
{
	position = fposition;

	resetsOnMD = true;

	requiresMouseData = true;															

	isHidden = false;

	recordMousePos = 0;



	backgroundSprite.setup(bgTexture, sf::Vector2f(0, 0), bgDimensions);

	notchSprite.setup(fnotchTexture, sf::Vector2f(0, 0), fnotchDimensions);

	sliderButton = fsliderButton;

	sliderButton.setPosition(sf::Vector2f(0, 0));



	sliderButton.addFunctionToDoOnButtonState(switchRecordMousePos, this, 4);

	sliderButton.addFunctionToDoOnButtonState(switchRecordMousePos, this, 5);

	sliderButton.addFunctionToDoOnButtonState(switchRecordMousePos, this, 10);

	sliderButton.addFunctionToDoOnButtonState(switchRecordMousePos, this, 11);



	affectedNumber = fVariable;

	bounds[0] = fminBound;

	bounds[1] = fmaxBound;

	*affectedNumber = fstartVal;
}


Slider::~Slider()
{
}


void Slider::update()
{

}

void Slider::update(MouseData& fmouseData)
{
	backgroundSprite.update();

	notchSprite.update();

	sliderButton.update(fmouseData);

	if (sliderButton.getButtonState() == 2 || sliderButton.getButtonState() == 5)
	{

	}
	

}

void Slider::draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition)
{

}

void Slider::resetMD()
{
	sliderButton.resetMD();
}

void Slider::switchRecordMousePos(void* fslider)
{
	Slider* tmpThis = static_cast<Slider*>(fslider);
	tmpThis->callSwitchRecordMousePos();
}

void Slider::callSwitchRecordMousePos()
{
	recordMousePos = !recordMousePos;
}