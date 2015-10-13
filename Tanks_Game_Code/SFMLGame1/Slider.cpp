#include "Slider.h"


Slider::Slider(	sf::Texture* bgTexture, sf::Texture* fnotchTexture, sf::Texture* sbTexture, sf::Vector2f bgDimensions, sf::Vector2f fnotchDimensions,
				sf::Vector2f sbDimensions, sf::Vector2f fposition, double& fVariable, double fminBound, double fmaxBound, double fstartVal	)
{
	position = fposition;

	resetsOnMD = false;

	requiresMouseData = true;															

	isHidden = false;

	recordMousePos = false;

	lastHeld = 0;

	lastDrawPosition = sf::Vector2f(0, 0);









	backgroundSprite.setup(bgTexture, sf::Vector2f(0, 0), bgDimensions);

	notchSprite.setup(fnotchTexture, sf::Vector2f(0, 0), fnotchDimensions);

	sliderButton.setup(sbTexture, sf::Vector2f(0, 0), sbDimensions);

	for (int i = 0; i < 2; i++)															//cycle through extreme corner indices
	{
		extremeCorners[i] = sf::Vector2f(sliderButton.getPosition().x + (2 * i - 1) * sbDimensions.x / 2, sliderButton.getPosition().y + (2 * i - 1) * sbDimensions.y / 2);
		//set the extreme corner position; note: f: x -> (2x - 1) maps 0 to -1 and 1 to 1
	}

	



	affectedNumber = &fVariable;

	bounds[0] = fminBound;

	bounds[1] = fmaxBound;

	*affectedNumber = fstartVal;

	scalingFactor = (bounds[1] - bounds[0]) / notchSprite.getGlobalDimensions().x;

	sliderButton.setPosition(sf::Vector2f((fstartVal - bounds[0]) / scalingFactor - notchSprite.getGlobalDimensions().x / 2 + bounds[0], 0));
}


Slider::~Slider()
{
}


void Slider::update()
{

}

void Slider::update(MouseData& fmouseData)
{
	updateElements();

	updateSliderState(fmouseData);
}






void Slider::draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition)
{
	if (lastDrawPosition != drawPosition)
	{
		lastDrawPosition = drawPosition;
	}

	position += drawPosition;



	backgroundSprite.draw(frenderWindow, position);

	notchSprite.draw(frenderWindow, position);

	sliderButton.draw(frenderWindow, position);



	position -= drawPosition;

}






void Slider::resetMD()
{

}






double Slider::inNotch(double a)
{
	double returnMe = a;


	double minVal = notchSprite.getPosition().x - notchSprite.getGlobalDimensions().x / 2;

	double maxVal = notchSprite.getPosition().x + notchSprite.getGlobalDimensions().x / 2;


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






void Slider::updateElements()
{
	backgroundSprite.update();

	notchSprite.update();

	sliderButton.update();
}




void Slider::updateSliderState(MouseData& fmouseData)
{
	sf::Vector2f mousePos = sf::Vector2f(fmouseData.getMousePosition().x, fmouseData.getMousePosition().y) - lastDrawPosition;

	sf::Vector2f buttonMousePos = mousePos - position - sliderButton.getPosition();

	int leftData = fmouseData.getLeftButtonData();


	if (buttonMousePos.x > extremeCorners[0].x && buttonMousePos.y > extremeCorners[0].y &&
		buttonMousePos.x < extremeCorners[1].x && buttonMousePos.y < extremeCorners[1].y)
	{

		if (leftData == 1)
		{
			lastHeld = 2;
		}
	}

	else if (leftData == 1)
	{
		lastHeld = 1;
	}


	if (leftData == 2 && lastHeld == 2)
	{


		double movePosx = inNotch(mousePos.x);

		double movePosy = notchSprite.getPosition().y;

		sliderButton.setPosition(sf::Vector2f(movePosx, movePosy));

		*affectedNumber = bounds[0] + scalingFactor * (movePosx + notchSprite.getGlobalDimensions().x / 2 - bounds[0]);

	}



	if (leftData == 3)
	{
		lastHeld = 0;
	}
}