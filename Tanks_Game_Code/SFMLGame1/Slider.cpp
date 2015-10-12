#include "Slider.h"


Slider::Slider(	sf::Texture* bgTexture, sf::Texture* fnotchTexture, sf::Vector2f bgDimensions, sf::Vector2f fnotchDimensions,
				BasicButton& fsliderButton, sf::Vector2f fposition, double* fVariable, double fmaxBound, double fminBound, double fstartVal)
{
	position = fposition;

	resetsOnMD = true;

	requiresMouseData = true;															

	isHidden = false;

	recordMousePos = false;



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

	scalingFactor = (bounds[1] - bounds[0]) / notchSprite.getGlobalDimensions().y;
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


	if (recordMousePos)
	{
		double movePosx = inNotch(fmouseData.getMousePosition().x - position.x);

		double movePosy = notchSprite.getPosition().y;

		sliderButton.setPosition(sf::Vector2f(movePosx, movePosy));

		*affectedNumber = bounds[0] + scalingFactor * (movePosx - bounds[0]);

	}


}

void Slider::draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition)
{

	position += drawPosition;



	backgroundSprite.draw(frenderWindow, position);

	notchSprite.draw(frenderWindow, position);

	sliderButton.draw(frenderWindow, position);



	position -= drawPosition;

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

double Slider::inNotch(double a)
{
	double returnMe = a;


	double maxVal = notchSprite.getPosition().x - notchSprite.getGlobalDimensions().x / 2;

	double minVal = notchSprite.getPosition().x + notchSprite.getGlobalDimensions().x / 2;


	if (a < minVal)
	{
		returnMe = minVal;
	}

	else if (a > maxVal)
	{
		returnMe = maxVal;
	}

	return returnMe;
}