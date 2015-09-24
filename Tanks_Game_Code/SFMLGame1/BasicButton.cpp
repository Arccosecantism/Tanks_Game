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


	position = fposition;

	requiresMouseData = true;

	isHidden = false;



	buttonState = Unheld;

	lastMouseHeld = 0;

	buttonString = ftextName;

	spriteSize = fspriteSize;

	textSize = ftextSize;


	for (int i = 0; i < 2; i++)
	{
		extremeCorners[i] = sf::Vector2f(position.x + (2 * i - 1) * spriteSize.x / 2, position.y + (2 * i - 1) * spriteSize.y / 2);
	}




	sf::Sprite tempSprite;

	sf::Vector2f tempDimensions;


	for (unsigned int i = 0; i < States_Number; i++)
	{

		tempSprite.setTexture(*fResourceGroup.getTexturePointer(i));

		tempDimensions = sf::Vector2f(tempSprite.getLocalBounds().width, tempSprite.getLocalBounds().height);

		tempSprite.setOrigin(tempDimensions.x / 2, tempDimensions.y / 2);

		tempSprite.setScale(spriteSize.x / tempDimensions.x, spriteSize.y / tempDimensions.y);

		tempSprite.setPosition(0,0);



		buttonStateSprites.push_back(tempSprite);

	}




	buttonText.setFont(*fResourceGroup.getFontPointer(0));
	
	buttonText.setString(buttonString);

	buttonText.setColor(ftextColor);

	tempDimensions = sf::Vector2f(buttonText.getLocalBounds().width, buttonText.getLocalBounds().height);

	buttonText.setOrigin(tempDimensions.x / 2, tempDimensions.y);

	buttonText.setScale(textSize.x / tempDimensions.x, textSize.y / tempDimensions.y);

	buttonText.setPosition(0,0);




	//soundBuffer stuff?
}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
--------------------------------Argumentless--update----------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::update()
{

}



/*------------------------------------------------------------------------------------
-----------------------------------Monadic--upate-------------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::update(MouseData& fmouseData)
{

	updateButtonState(fmouseData);

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
--------------------------------------Draw--------------------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition)
{

	position += drawPosition;



	int drawState = buttonState;
	if (drawState == Clicked)
	{
		drawState = Hovered_Pressed;
	}
	else if (drawState == Released)
	{
		drawState = Hovered;
	}



	buttonStateSprites[drawState].move(position);

	frenderWindow.draw(buttonStateSprites[drawState]);

	buttonStateSprites[drawState].move(-position);



	buttonText.move(position);

	frenderWindow.draw(buttonText);

	buttonText.move(-position);



	position -= drawPosition;


}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
----------------------------SetRelativeSpritePosition---------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::setRelativeSpritePosition(int findex, sf::Vector2f fpos)
{

	if (findex >= States_Number)
	{
		findex = States_Number - 1;
	}

	else if (findex < 0)
	{
		findex = 0;
	}


	buttonStateSprites[findex].setPosition(fpos);
}



/*------------------------------------------------------------------------------------
----------------------------SetRelativeTextPosition-----------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::setRelativeTextPosition(sf::Vector2f fpos)
{

	buttonText.setPosition(fpos);

}



/*------------------------------------------------------------------------------------
----------------------------MoveRelativeSpritePosition--------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::moveRelativeSpritePosition(int findex, sf::Vector2f fvel)
{

	if (findex >= States_Number)
	{
		findex = States_Number - 1;
	}

	else if (findex < 0)
	{
		findex = 0;
	}


	buttonStateSprites[findex].move(fvel);

}



/*------------------------------------------------------------------------------------
--------------------------MoveRelativeTextPosition------------------------------------
------------------------------------------------------------------------------------*/
void BasicButton::moveRelativeTextPosition(sf::Vector2f fvel)
{

	buttonText.move(fvel);

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
--------------------------GetButtonState----------------------------------------------
------------------------------------------------------------------------------------*/
int BasicButton::getButtonState()
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
void BasicButton::updateButtonState(MouseData& fmousedata)
{
	sf::Vector2i mousePos = fmousedata.getMousePosition();
	int leftData = fmousedata.getLeftButtonData();

	bool pressedDown = (buttonState == Clicked) || (buttonState == Unheld_Pressed) || (buttonState == Hovered_Pressed) || (buttonState == Held_Pressed);

	if (mousePos.x > extremeCorners[0].x && mousePos.x < extremeCorners[1].x && mousePos.y > extremeCorners[0].y && mousePos.y < extremeCorners[1].y)
	{

		if(leftData == 0)
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

		else if (leftData == 2)
		{
			if (lastMouseHeld != 1)
			{
				if (pressedDown)
				{
					buttonState = Held_Pressed;
				}
				else
				{
					buttonState = Held;
				}

				lastMouseHeld = 2;
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
			}
			
			
		}

		else if (leftData == 3)
		{
			if (lastMouseHeld != 1)
			{
				if (pressedDown)
				{
					buttonState = Released;
				}
				else
				{
					buttonState = Clicked;
				}
				lastMouseHeld = 0;
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
