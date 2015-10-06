#include "MultiMenuSprite.h"


MultiMenuSprite::MultiMenuSprite()
{
	setVectorSize(1);

	requiresMouseData = false;	

	isHidden = false;														

	resetsOnMD = false;
}


MultiMenuSprite::~MultiMenuSprite()
{
}

void MultiMenuSprite::update()
{
	for (unsigned int i = 0; i < spriteVector.size(); i++)
	{
		spriteVector[i].update();
	}
}


void MultiMenuSprite::update(MouseData& fmouseData)
{
	for (unsigned int i = 0; i < spriteVector.size(); i++)
	{
		spriteVector[i].update(fmouseData);
	}
}


void MultiMenuSprite::draw(sf::RenderWindow& frenderwindow, sf::Vector2f drawPosition)
{
	position += drawPosition;

	for (unsigned int i = 0; i < spriteVector.size(); i++)
	{
		if (!spriteVector[i].getIsHidden())
		{
			spriteVector[i].draw(frenderwindow, position);
		}
		
	}

	position -= drawPosition;
}


void MultiMenuSprite::resetMD()
{

}

void MultiMenuSprite::setCurrentMenuSpriteByName(std::string fname)
{
	for (unsigned int i = 0; i < spriteVector.size(); i++)
	{
		spriteVector[i].hide();
	}

	spriteVector[ntoi(fname)].unhide();
}

void MultiMenuSprite::setCurrentMenuSpriteByIndex(int findex)
{
	for (unsigned int i = 0; i < spriteVector.size(); i++)
	{
		spriteVector[i].hide();
	}
	spriteVector[findex].unhide();
}

void MultiMenuSprite::addMenuSprite(MenuSprite fmenuSprite, std::string fname)
{
	if (spriteVector.size() > 0)
	{
		fmenuSprite.hide();
	}

	spriteVector.push_back(fmenuSprite);

	addName(fname, spriteVector.size() - 1);

}

void MultiMenuSprite::addMenuSprite(MenuSprite fmenuSprite, int fintname)
{
	if (spriteVector.size() > 0)
	{
		fmenuSprite.hide();
	}

	spriteVector.push_back(fmenuSprite);

	addName(fintname, spriteVector.size() - 1);
}


MenuSprite* MultiMenuSprite::getMenuSpritePointerByName(std::string fname)
{
	MenuSprite* tmpSprite = &spriteVector[ntoi(fname)];
	return tmpSprite;
}

MenuSprite* MultiMenuSprite::getMenuSpritePointerByIndex(int findex)
{
	MenuSprite* tmpSprite = &spriteVector[findex];
	return tmpSprite;
}