#include "Slider.h"


//----------------------------------------------------------------------------------------------------------------------------***************************
//-----------------------------------------PUBLIC-----------------------------------------------------------------------------***************************
//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
------------------------------------constructor---------------------------------------
------------------------------------------------------------------------------------*/
Slider::Slider(	sf::Texture* bgTexture, sf::Texture* fnotchTexture, sf::Texture* sbTexture, sf::Vector2f bgDimensions, sf::Vector2f fnotchDimensions,
				sf::Vector2f sbDimensions, sf::Vector2f fposition, double& fVariable, double fminBound, double fmaxBound, double fstartVal	)
{

	position = fposition;						//set the position

	resetsOnMD = false;							//it doesn't reset on menu deactivation

	requiresMouseData = true;					//it requires mouse data												

	isHidden = false;							//draw it by default

	lastHeld = 0;								//last held is 0 -- wasn't held

	lastDrawPosition = sf::Vector2f(0, 0);		//last draw position was (0,0) by default









	backgroundSprite.setup(bgTexture, sf::Vector2f(0, 0), bgDimensions);		//setup the backgroudn sprite

	notchSprite.setup(fnotchTexture, sf::Vector2f(0, 0), fnotchDimensions);		//setupd the notchsprite

	sliderButton.setup(sbTexture, sf::Vector2f(0, 0), sbDimensions);			//setup the slider button


	for (int i = 0; i < 2; i++)															//cycle through extreme corner indices
	{
		extremeCorners[i] = sf::Vector2f(	sliderButton.getPosition().x + (2 * i - 1) * sbDimensions.x / 2,
											sliderButton.getPosition().y + (2 * i - 1) * sbDimensions.y / 2	);
																						//set the extreme corner position; 
																						//note: f: x -> (2x - 1) maps 0 to -1 and 1 to 1
	}

	



	affectedNumber = &fVariable;				//affected number is set

	bounds[0] = fminBound;						//bounds 0 is the minimum

	bounds[1] = fmaxBound;						//bounds 1 is the maximum

	*affectedNumber = fstartVal;				//affected number starts at the start value

	scalingFactor = (bounds[1] - bounds[0]) / notchSprite.getGlobalDimensions().x;
												//find the scaling factor

	sliderButton.setPosition(sf::Vector2f((fstartVal - bounds[0]) / scalingFactor - notchSprite.getGlobalDimensions().x / 2 + bounds[0], 0));
												//set the sliderButton's position equal to where it should be for its value
}



/*------------------------------------------------------------------------------------
------------------------------------destructor----------------------------------------
------------------------------------------------------------------------------------*/
Slider::~Slider()							//empty
{
}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
------------------------------------update--------------------------------------------
------------------------------------------------------------------------------------*/
void Slider::update()						//empty
{

}



/*------------------------------------------------------------------------------------
-----------------------------update-with-mouseData------------------------------------
------------------------------------------------------------------------------------*/
void Slider::update(MouseData& fmouseData)	//empty
{

	updateElements();						//update the elements

	updateSliderState(fmouseData);			//update the slider state (click logic)

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
------------------------------------draw----------------------------------------------
------------------------------------------------------------------------------------*/
void Slider::draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition)
{
	if (lastDrawPosition != drawPosition)
	{
		lastDrawPosition = drawPosition;				//last draw position is set
	}

	position += drawPosition;							//add the draw position to make things relative



	backgroundSprite.draw(frenderWindow, position);		//draw all of the MenuSprites 

	notchSprite.draw(frenderWindow, position);

	sliderButton.draw(frenderWindow, position);



	position -= drawPosition;							//subtract the drawPosition because it was added

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
------------------------------------resetMD-------------------------------------------
------------------------------------------------------------------------------------*/
void Slider::resetMD()									//does not reset on menuDeactivation
{

}



//----------------------------------------------------------------------------------------------------------------------------***************************



//----------------------------------------------------------------------------------------------------------------------------***************************
//-----------------------------------------PRIVATE----------------------------------------------------------------------------***************************
//----------------------------------------------------------------------------------------------------------------------------***************************




/*------------------------------------------------------------------------------------
----------------------------updateElements--------------------------------------------
------------------------------------------------------------------------------------*/
void Slider::updateElements()							//updates all of the smaller MenuElements
{
	backgroundSprite.update();

	notchSprite.update();

	sliderButton.update();
}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
-----------------------------updateSliderState----------------------------------------
------------------------------------------------------------------------------------*/
void Slider::updateSliderState(MouseData& fmouseData)	//updates the state of the slider -- click logic as well	
{


	sf::Vector2f mousePos = sf::Vector2f(fmouseData.getMousePosition().x, fmouseData.getMousePosition().y) - lastDrawPosition;
														//alter the mouse position to be relative to the lastDrawPosition

	sf::Vector2f buttonMousePos = mousePos - position - sliderButton.getPosition();
														//make a new relativity to the sliderButton

	int leftData = fmouseData.getLeftButtonData();		//left data is the left mouse data


	if (buttonMousePos.x > extremeCorners[0].x && buttonMousePos.y > extremeCorners[0].y &&	//if it's inside
		buttonMousePos.x < extremeCorners[1].x && buttonMousePos.y < extremeCorners[1].y)
	{

		if (leftData == 1)
		{
			lastHeld = 2;								//if the button was just clicked, the mouse was last held in the button
		}
	}

	else if (leftData == 1)								
	{
		lastHeld = 1;									//if it was outside and the button was just clicked, the mouse was last held outside of the button
	}


	if (leftData == 2 && lastHeld == 2)					//if the mouse was last held inside the button and the mouse is still being held
	{


		double movePosx = inNotch(mousePos.x);			

		double movePosy = notchSprite.getPosition().y;

		sliderButton.setPosition(sf::Vector2f(movePosx, movePosy));
														//move the sliderButton an appropriate amount

		*affectedNumber = bounds[0] + scalingFactor * (movePosx + notchSprite.getGlobalDimensions().x / 2 - bounds[0]);
														//change the affeected number an appropriate amount

	}



	if (leftData == 3)									
	{
		lastHeld = 0;									//if the mouse was just released, the mouse was not last held anywhere
	}
}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
------------------------------------inNotch-------------------------------------------
------------------------------------------------------------------------------------*/
double Slider::inNotch(double fpos)						//bounds a double according to the bounds of the notch 
{

	double returnMe = fpos;								//set it equal to the double entered

														//now, make min and max vals
	double minVal = notchSprite.getPosition().x - notchSprite.getGlobalDimensions().x / 2;

	double maxVal = notchSprite.getPosition().x + notchSprite.getGlobalDimensions().x / 2;


														//bound returnme
	if (fpos < minVal)
	{
		returnMe = minVal;
	}

	else if (fpos > maxVal)
	{
		returnMe = maxVal;
	}

	return returnMe;									//return returnme
}

//----------------------------------------------------------------------------------------------------------------------------***************************