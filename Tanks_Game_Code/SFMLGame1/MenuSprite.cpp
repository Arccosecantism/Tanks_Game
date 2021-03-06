#include "MenuSprite.h"


//----------------------------------------------------------------------------------------------------------------------------***************************
//-----------------------------------------PUBLIC-----------------------------------------------------------------------------***************************
//----------------------------------------------------------------------------------------------------------------------------***************************



/*------------------------------------------------------------------------------------
----------------------------Argumentless-constructor----------------------------------
------------------------------------------------------------------------------------*/
MenuSprite::MenuSprite()
{
	requiresMouseData = false;			//by default, the MenuSprite does not require mouse data

	isHidden = false;					//it shall be drawn

	resetsOnMD = false;					//it does not reset when the menu deactivates
}



/*------------------------------------------------------------------------------------
--------------------------Multi-Argument-constructor----------------------------------
------------------------------------------------------------------------------------*/
MenuSprite::MenuSprite(sf::Texture* ftexture, sf::Vector2f fposition, sf::Vector2f fsize)
{
	requiresMouseData = false;			//same stuff

	isHidden = false;

	resetsOnMD = false;

	setup(ftexture, position, fsize);	//setup	
}



/*------------------------------------------------------------------------------------
--------------------------------deconstructor-----------------------------------------
------------------------------------------------------------------------------------*/
MenuSprite::~MenuSprite()
{

}



/*------------------------------------------------------------------------------------
---------------------------------setup------------------------------------------------
------------------------------------------------------------------------------------*/
void MenuSprite::setup(sf::Texture* ftexture, sf::Vector2f fposition, sf::Vector2f fsize)
{
	position = fposition;				//position is set

	menuImage.setup(ftexture, sf::Vector2f(0, 0), fsize, 0);
}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
---------------------------------update-----------------------------------------------
------------------------------------------------------------------------------------*/
void MenuSprite::update()	//empty
{

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
---------------------------------update-----------------------------------------------
------------------------------------------------------------------------------------*/
void MenuSprite::update(MouseData& fmouseData)	//empty
{

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
---------------------------------draw------------------------------------------------
------------------------------------------------------------------------------------*/
void MenuSprite::draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition)
{

	position += drawPosition;		//add the drawPosition  to make position relative
		

		
	menuImage.draw(frenderWindow, position);


	position -= drawPosition;		//subtract the drawPosition because we added it

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
---------------------------------resetMD----------------------------------------------
------------------------------------------------------------------------------------*/
void MenuSprite::resetMD()			//resetMD()
{

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
---------------------------------getGlobalDimensions----------------------------------
------------------------------------------------------------------------------------*/
sf::Vector2f MenuSprite::getGlobalDimensions()													//all this function does is literally return the global
																								//dimensions of the Sprite
{
	return menuImage.getGlobalDimensions();
}



/*------------------------------------------------------------------------------------
---------------------------------getLocalDimensions-----------------------------------
------------------------------------------------------------------------------------*/
sf::Vector2f MenuSprite::getLocalDimensions()													//same thing as above, except the dimensions are local
{
	return menuImage.getLocalDimensions();
}


//----------------------------------------------------------------------------------------------------------------------------***************************