#include "BasicButton.h"





//----------------------------------------------------------------------------------------------------------------------------***************************
//-----------------------------------------PUBLIC-----------------------------------------------------------------------------***************************
//----------------------------------------------------------------------------------------------------------------------------***************************



/*------------------------------------------------------------------------------------
------------------------------------Constructor---------------------------------------
------------------------------------------------------------------------------------*/
BasicButton::BasicButton(sf::Vector2f fposition, ResourceGroup& fResourceGroup,

							std::string ftextName, sf::Color ftextColor,				//constructor; sets textures to sprites and other similar things 

							sf::Vector2f fspriteSize,	int ftextCharSize)
{

	//setting inherited protected stuff------------------
	
	position = fposition;																//set the inherited protected position to the entered position; this will be the position of the button
																						//relative to a menu

	requiresMouseData = true;															//set the inherited protected bool requiresMouseData to true because BasicButton requires mouse data

	isHidden = false;																	//set the inherited protected bool isHidden to false because BasicButton should be drawn by default
	
	resetsOnMD = true;																	//BasicButtons reset when their menu deactivates typically

	//done-----------------------------------------------
	
	for (int i = 0; i < 2; i++)
	{
		buttonStateCheckers[i] = 0;
	}
	
	buttonState = Unheld;																//buttonState is unheld at the start of BasicButton's existence	

	lastMouseHeld = 0;																	//lastMouseHeld starts off as not having a hold value

	for (int i = 0; i < 2; i++)															//cycle through extreme corner indices
	{
		extremeCorners[i] = sf::Vector2f(position.x + (2 * i - 1) * fspriteSize.x / 2, position.y + (2 * i - 1) * fspriteSize.y / 2);
																						//set the extreme corner position; note: f: x -> (2x - 1) maps 0 to -1 and 1 to 1
	}


	//Here, the Sprites are set----------------------------------------------------------------------------------------------------------------------------------------------------


	MenuSprite tempSprite;																//declare a temporary Sprite to be pushed back

	sf::Vector2f tempDimensions;														//declare temporary helper dimensioins of the sprite



	for (int i = 0; i < States_Number; i++)									//cycle through 6 times
	{

		tempSprite.setup(fResourceGroup.getTexturePointer(i), sf::Vector2f(0,0), fspriteSize);

																						//now the Sprite should have the correct position, scaling, and origin

		buttonSprites.addMenuSprite(tempSprite, i);										//add the tempoarary sprite to the sprite vector
		
	}




	std::vector<memfunc_of_object> tmpVectorOfPairs;								//create a temporary vector of function pointers

	for (int i = 0; i < Events_Number; i++)
	{
		doWhenButtonEvent.push_back(tmpVectorOfPairs);								//add as many vectors as there are button states 
	}




	//Now, the text is set----------------------------------------------------------------------------------------------------------------------------------------------------------

	buttonTextBox.setup(sf::Vector2f(0, 0), fResourceGroup.getFontPointer(0), ftextName, ftextCharSize, fspriteSize.x - 20, ftextColor);




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
--------------------------Single--argument--upate-------------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::update(MouseData& fmouseData)										//mpouse data update -- inherited virtual
{

	updateButtonState(fmouseData);													//update the buttonState
	updateButtonEvent();

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
--------------------------------------Draw--------------------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition)	//draws the Button
{
	
	lastDrawPosition = drawPosition;

	position += drawPosition;								//increase the position by thedesired draw position -- makes the position relative




	buttonSprites.draw(frenderWindow, drawPosition);						//draw the sprite


	buttonTextBox.draw(frenderWindow, position);



	position -= drawPosition;								//finally, subtract the drawPosition because we added it

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
-------------------------------------resetMD------------------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::resetMD()
{

	buttonState = Unheld;

}


//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
----------------------------SetRelativeSpritePosition---------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::setRelativeSpritePosition(sf::Vector2f fpos)		//sets the position of all the Sprites (relatively).
{
	for (int i= 0; i < 2; i++)
	{
		extremeCorners[i] = extremeCorners[i] + fpos - buttonSprites.getPosition();
																	//set the extremeCorners to be around the new position;
	}


	buttonSprites.setPosition(fpos);					//set the position (which will in draw() be relative) to the desired position
	
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


	buttonSprites.move(fvel);							//move the Sprites by the desired velocity

}



/*------------------------------------------------------------------------------------
----------------------------SetRelativeTextPosition-----------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::setRelativeTextPosition(sf::Vector2f fpos)			//set the position of the text (relative to the button)
{

	buttonTextBox.setPosition(fpos);										//move the Text to the desired position

}



/*------------------------------------------------------------------------------------
--------------------------MoveRelativeTextPosition------------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::moveRelativeTextPosition(sf::Vector2f fvel)			//move the position of the text by the desired velocity
{

	buttonTextBox.move(fvel);												//move it by the velocity

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


/*------------------------------------------------------------------------------------
----------------------------AddFunctionToDoOnButtonState--------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::addFunctionToDoOnButtonState(function_pointer function, void* object, int fbuttonState)		//adds a function to do when the button is a certain buttonState
{

	doWhenButtonEvent[fbuttonState].push_back(std::make_pair(function, object));									//add the desired function

}



//----------------------------------------------------------------------------------------------------------------------------***************************






//----------------------------------------------------------------------------------------------------------------------------***************************
//-----------------------------------------PRIVATE----------------------------------------------------------------------------***************************
//----------------------------------------------------------------------------------------------------------------------------***************************




//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
--------------------------UpdateButtonState-------------------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::updateButtonState(MouseData& fmousedata)			//*groan* Click logic...
{


	sf::Vector2f mousePos = sf::Vector2f(fmousedata.getMousePosition().x, fmousedata.getMousePosition().y) - lastDrawPosition;	
																	//make a new vec2i, mousePos that is the mousePosition from
																	//the mouseData; only here to shorten and simplify code
	int leftData = fmousedata.getLeftButtonData();

	bool pressedDown = (buttonState == Clicked) || (buttonState == Unheld_Pressed) || (buttonState == Hovered_Pressed) || (buttonState == Held_Pressed);
																	//if any of the above statements were true, pressed down should be true.
																	//This means that the mouse is being held down.



	//here goes the click logic. There will be weird tabbing to match the if satements

	if (mousePos.x > extremeCorners[0].x && mousePos.x < extremeCorners[1].x && mousePos.y > extremeCorners[0].y && mousePos.y < extremeCorners[1].y)
																//if the mousePosition was inside the extreme corners
	{

		if(leftData == 0)											//if the left mouse is unheld
		{
			if (pressedDown)											//if the button is currently in the down state
			{
				buttonState = Hovered_Pressed;							//it's hovered and pressed
			}

			else														//otherwise
			{
				buttonState = Hovered;									//it's only hovered
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
					callbackOnButtonEvent(Released);
				}

				else														//otherwise
				{
					callbackOnButtonEvent(Clicked);
				}
			}



			else														//otherwise if the mouse was pressed off of the Button
			{
				if (pressedDown)											//if the button is held down
				{
					buttonState = Hovered_Pressed;							//the button is now hovered and pressed
				}


				else														//otherwise
				{
					buttonState = Hovered;									//the button is hovered
				}

				
			}

			lastMouseHeld = 0;			//when the mouse is released, it is no longer held
		}

		else if (leftData == 1)										//else if the mouse was just pressed on the button
		{
			lastMouseHeld = 2;										//last held was on the button
		}



	}

	else															//else if the mouse was outside the button			
	{
		if (lastMouseHeld == 2)											//if the mouse was last held on the button
		{
			if (pressedDown)												//if the button was pressed down
			{
				buttonState = Hovered_Pressed;								//it's hovered and pressed even if the 
			}

			else															//otherwise
			{
				buttonState = Hovered;										//it's only hovered
			}
		}

		else if (leftData == 1)											//else if the mouse was just held down and was not already held down somewhere else
		{
			lastMouseHeld = 1;											//the mouse was last held off of the button
		}


		if (leftData == 3)												//if the mouse was released
		{
			lastMouseHeld = 0;											//the mouse wasnt held
		}


		if (lastMouseHeld != 2)											//if the mouse was not dragged off of the button
		{
			if (pressedDown)												//if the button was pressed down
			{
				buttonState = Unheld_Pressed;								//the button is now unheld and pressed
			}

			else															//otherwise
			{
				buttonState = Unheld;										//the button is simply unheld
			}
		}
	}

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
--------------------------updateButtonEvent---------------------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::updateButtonEvent()
{
	buttonStateCheckers[0] = buttonStateCheckers[1];

	buttonStateCheckers[1] = buttonState;

	if (buttonStateCheckers[0] != buttonStateCheckers[1])
	{
		for (int i = 0; i < States_Number; i++)
		{
			if (buttonStateCheckers[0] == i)
			{

				callbackOnButtonEvent(2 * i + 1);
			}

			if (buttonStateCheckers[1] == i)
			{

				buttonSprites.setCurrentMenuSpriteByIndex(i);

				callbackOnButtonEvent(2 * i);

			}
		}
	}
}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
--------------------------callbackClicked---------------------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::callbackOnButtonEvent(int fbuttonState)										//do this when the button is clicked
{
	for (unsigned int i = 0; i < doWhenButtonEvent[fbuttonState].size(); i++)					//cycle through all functions to be called
	{
		if (doWhenButtonEvent[fbuttonState][i].first != NULL)
		{
			doWhenButtonEvent[fbuttonState][i].first(doWhenButtonEvent[fbuttonState][i].second);	//do all functions
		}
	}
}


//----------------------------------------------------------------------------------------------------------------------------***************************