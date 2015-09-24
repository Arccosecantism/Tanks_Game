#include "BasicButton.h"







//----------------------------------------------------------------------------------------------------------------------------***************************
//-----------------------------------------PUBLIC-----------------------------------------------------------------------------***************************
//----------------------------------------------------------------------------------------------------------------------------***************************



/*------------------------------------------------------------------------------------
------------------------------------Constructor---------------------------------------
------------------------------------------------------------------------------------*/
BasicButton::BasicButton(sf::Vector2f fposition, ResourceGroup& fResourceGroup,

							std::string ftextName, sf::Color ftextColor,				//constructor; sets textures to sprites and other similar things 

							sf::Vector2f fspriteSize,	sf::Vector2f ftextSize)
{

	//setting inherited protected stuff------------------
	
	position = fposition;																//set the inherited protected position to the entered position; this will be the position of the button
																						//relative to a menu

	requiresMouseData = true;															//set the inherited protected bool requiresMouseData to true because BasicButton requires mouse data

	isHidden = false;																	//set the inherited protected bool isHidden to false because BasicButton should be drawn by default
	
	//done-----------------------------------------------
	
	
	buttonState = Unheld;																//buttonState is unheld at the start of BasicButton's existence	

	lastMouseHeld = 0;																	//lastMouseHeld starts off as not having a hold value

	spriteSize = fspriteSize;															//set the desired size of the Sprite of the BasicButton

	textSize = ftextSize;																//set the desired size of the Text of the BasicButton


	for (int i = 0; i < 2; i++)															//cycle through extreme corner indices
	{
		extremeCorners[i] = sf::Vector2f(position.x + (2 * i - 1) * spriteSize.x / 2, position.y + (2 * i - 1) * spriteSize.y / 2);
																						//set the extreme corner position; note: f: x -> (2x - 1) maps 0 to -1 and 1 to 1
	}


	//Here, the Sprites are set----------------------------------------------------------------------------------------------------------------------------------------------------

	sf::Sprite tempSprite;																//declare a temporary Sprite to be pushed back

	sf::Vector2f tempDimensions;														//declare temporary helper dimensioins of the sprite


	for (unsigned int i = 0; i < States_Number; i++)									//cycle through 6 times
	{

		tempSprite.setTexture(*fResourceGroup.getTexturePointer(i));					//set Texture to the accoridng spot in the ResourceGroup

		tempDimensions = sf::Vector2f(tempSprite.getLocalBounds().width, tempSprite.getLocalBounds().height);
																						//set the temporary helper dimensions to the  current dimesions of the sprite

		tempSprite.setOrigin(tempDimensions.x / 2, tempDimensions.y / 2);				//set the origin in the center of the rectangle

		tempSprite.setScale(spriteSize.x / tempDimensions.x, spriteSize.y / tempDimensions.y);
																						//set the scale equal to the desired sprite size divided by the current sprite size, essentially replacing the dimensions

		tempSprite.setPosition(0,0);													//set the relative position at (0,0)

																						//now the Sprite should have the correct position, scaling, and origin


		buttonStateSprites.push_back(tempSprite);										//add the tempoarary sprite to the sprite vector
	}


	//Now, the text is set----------------------------------------------------------------------------------------------------------------------------------------------------------

	buttonText.setFont(*fResourceGroup.getFontPointer(0));								//set the font in the Text to the first font in the resourceGroup
	
	buttonText.setString(ftextName);													//set the drawn string to the desired string

	buttonText.setColor(ftextColor);													//set the color of the Text to the desired color

	tempDimensions = sf::Vector2f(buttonText.getLocalBounds().width, buttonText.getLocalBounds().height);
																						//set the temporary helper dimensions equal to the current dimentsions of the Text

	buttonText.setOrigin(tempDimensions.x / 2, tempDimensions.y);						//set the origin to the center of the rectangle

	buttonText.setScale(textSize.x / tempDimensions.x, textSize.y / tempDimensions.y);	//set the scale to the desired size

	buttonText.setPosition(0,0);														//set the relative position of the Text at (0,0)




	//soundBuffer stuff?
}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
--------------------------------Argumentless--update----------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::update()															//Empty update -- inherited virtual
{

}



/*------------------------------------------------------------------------------------
-----------------------------------Monadic--upate-------------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::update(MouseData& fmouseData)										//mpouse data update -- inherited virtual
{

	updateButtonState(fmouseData);													//update the buttonState

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
--------------------------------------Draw--------------------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition)	//draws the Button
{

	position += drawPosition;								//increase the position by thedesired draw position -- makes the position relative



	int drawState = buttonState;							//draw the Sprite based on the current buttonState

	if (drawState == Clicked)								//if it was clicked, draw the hovered_pressed state
	{
		drawState = Hovered_Pressed;
	}
	else if (drawState == Released)							//if it was released, draw the hovered state
	{
		drawState = Hovered;
	}



	buttonStateSprites[drawState].move(position);			//add the button's position to the Sprite -- makes the sprites position relative

	frenderWindow.draw(buttonStateSprites[drawState]);		//draw the sprite

	buttonStateSprites[drawState].move(-position);			//subtract the button's position because we added it;



	buttonText.move(position);								//same thing with Text

	frenderWindow.draw(buttonText);

	buttonText.move(-position);



	position -= drawPosition;								//finally, subtract the drawPosition because we added it

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
----------------------------SetRelativeSpritePosition---------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::setRelativeSpritePosition(sf::Vector2f fpos)		//sets the position of all the Sprites (relatively).
{
	for (int i= 0; i < 2; i++)
	{
		extremeCorners[i] = extremeCorners[i] + fpos - buttonStateSprites[0].getPosition();
																	//set the extremeCorners to be around the new position;
	}

	for (int i = 0; i < States_Number; i++)
	{
		buttonStateSprites[i].setPosition(fpos);					//set the position (which will in draw() be relative) to the desired position
	}
	
}



/*------------------------------------------------------------------------------------
----------------------------MoveRelativeSpritePosition--------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::moveRelativeSpritePosition(sf::Vector2f fvel)		//moves the position of all the Sprites
{

	for (int i = 0; i < 2; i++)
	{
		extremeCorners[i] += fvel;									//move the Extreme Corners by the velocity
	}

	for (int i = 0; i < States_Number; i++)
	{
		buttonStateSprites[i].move(fvel);							//move the Sprites by the desired velocity
	}
}



/*------------------------------------------------------------------------------------
----------------------------SetRelativeTextPosition-----------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::setRelativeTextPosition(sf::Vector2f fpos)			//set the position of the text (relative to the button)
{

	buttonText.setPosition(fpos);										//move the Text to the desired position

}



/*------------------------------------------------------------------------------------
--------------------------MoveRelativeTextPosition------------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::moveRelativeTextPosition(sf::Vector2f fvel)			//move the position of the text by the desired velocity
{

	buttonText.move(fvel);												//move it by the velocity

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
--------------------------GetButtonState----------------------------------------------
------------------------------------------------------------------------------------*/
int BasicButton::getButtonState()										//returns the buttonState
{

	return buttonState;

}



//----------------------------------------------------------------------------------------------------------------------------***************************



//void BasicButton::setResources(ResourceGroup& rgroup)
//{
//
//	
//}

//void BasicButton::setTextSize(int fsize)
//{
//
//
//}
//
//
//
//void BasicButton::setTextColor(sf::Color fcolor)
//{
//
//
//}
//
//
//
//void BasicButton::setTextString(std::string fstring)
//{
//
//
//}
//
//
//
//void BasicButton::setPosition(sf::Vector2f fposition)
//{
//
//
//}
//
//
//
//void BasicButton::setSpriteSize(sf::Vector2f  fsize)
//{
//
//
//}







//----------------------------------------------------------------------------------------------------------------------------***************************
//-----------------------------------------PRIVATE----------------------------------------------------------------------------***************************
//----------------------------------------------------------------------------------------------------------------------------***************************



/*------------------------------------------------------------------------------------
--------------------------UpdateButtonState-------------------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::updateButtonState(MouseData& fmousedata)			//*groan* Click logic...
{
	sf::Vector2i mousePos = fmousedata.getMousePosition();			//make a new vec2i, mousePos that is the mousePosition from the mouseData; only here to shorten and simplify code
	int leftData = fmousedata.getLeftButtonData();

	bool pressedDown = (buttonState == Clicked) || (buttonState == Unheld_Pressed) || (buttonState == Hovered_Pressed) || (buttonState == Held_Pressed);
																	//if any of the above statements were true, pressed down should be true. This means that the mouse is being held down.



	//here goes the click logic. There will be weird tabbing to match the if satements

	if (mousePos.x > extremeCorners[0].x && mousePos.x < extremeCorners[1].x && mousePos.y > extremeCorners[0].y && mousePos.y < extremeCorners[1].y)
																	//if the mousePosition was inside the extreme corners
	{

		if(leftData == 0)												//if the left mouse is unheld
		{
			if (pressedDown)												//if the button is currently in the down state
			{
				buttonState = Hovered_Pressed;								//it's hovered and pressed
			}

			else															//otherwise
			{
				buttonState = Hovered;										//it's only hovered
			}						
		}



		else if (leftData == 2)										//else if the left mouse was being held 
		{
			if (lastMouseHeld != 1)										//if the mouse was not last pressed outside of the button 
			{
				if (pressedDown)											//if the button is presed down
				{
					buttonState = Held_Pressed;								//the button is now pressed
				}

				else														//otherwise
				{
					buttonState = Held;										//it's pressed
				}

				lastMouseHeld = 2;
			}



			else														//if it was pressed outside	and is now in
			{
				if (pressedDown)											//if the button is pressed down
				{
					buttonState = Hovered_Pressed;							//it's hovered and pressed
				}

				else														//otherwise
				{
					buttonState = Hovered;									//it's hovered
				}
			}
		}



		else if (leftData == 3)										//else if the mouse was being released
		{
			if (lastMouseHeld != 1)										//if the mouse was not last pressed outside of the button
			{
				if (pressedDown)											//if the button is pressed down
				{
					buttonState = Released;									//the button is released
				}

				else														//otherwise
				{
					buttonState = Clicked;									//the button is clicked
				}

				lastMouseHeld = 0;			//when the mouse is relased, it is no longer held (only works for pressing initially on the button)
			}



			else
			{
				if (pressedDown)
				{
					buttonState = Hovered_Pressed;
				}

				else
				{
					buttonState = Hovered;
				}
				lastMouseHeld = 0;
			}
		}

	}
	else
	{
		if (lastMouseHeld == 2)
		{
			if (pressedDown)
			{
				buttonState = Hovered_Pressed;
			}

			else
			{
				buttonState = Hovered;
			}
		}

		else if (leftData == 2 && lastMouseHeld != 1)
		{
			lastMouseHeld = 1;
		}

		if (pressedDown)
		{
			buttonState = Unheld_Pressed;
		}

		else
		{
			buttonState = Unheld;
		}
	}

}


//----------------------------------------------------------------------------------------------------------------------------***************************
