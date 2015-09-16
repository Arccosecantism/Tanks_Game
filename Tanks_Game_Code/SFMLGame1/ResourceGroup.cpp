#include "ResourceGroup.h"




/*------------------------------------------------------------------------------------
-------------------------------Constructor--------------------------------------------
------------------------------------------------------------------------------------*/
ResourceGroup::ResourceGroup()												//Constructor is empty	
{
}




/*------------------------------------------------------------------------------------
-------------------------------addTexture---------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceGroup::addTexture(sf::Texture* ftexture)						//add a pointer to a texture to textureVector
{

	textureVector.push_back(ftexture);


}




/*------------------------------------------------------------------------------------
-------------------------------addFont------------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceGroup::addFont(sf::Font* ffont)								//add a pointer to a font to fontVector
{

	fontVector.push_back(ffont);

}


/*------------------------------------------------------------------------------------
-----------------------------addSoundBuf----------------------------------------------
------------------------------------------------------------------------------------*/
/*void addSoundBuf(sf::SoundBuffer* fsoundbuf)								//add a pointer to a soundBuf to soundBufVector
{

	soundBufVector.push_back(fsoundbuf);


}*/







/*------------------------------------------------------------------------------------
-------------------------------getTextureVector---------------------------------------
------------------------------------------------------------------------------------*/
std::vector<sf::Texture*> ResourceGroup::getTextureVector()					//returns the entire textureVector; probably not going to use
{

	return textureVector;

}





/*------------------------------------------------------------------------------------
-------------------------------getFontVector------------------------------------------
------------------------------------------------------------------------------------*/
std::vector<sf::Font*> ResourceGroup::getFontVector()						//returns the entire fontVector; probably not going to use
{

	return fontVector;

}





/*------------------------------------------------------------------------------------
-------------------------------getSoundBufVector--------------------------------------
------------------------------------------------------------------------------------*/
/*std::vector<sf::SoundBuffer*> ResourceGroup::getSoundBufVector()			//returns the entire soundBufVector; probably not going to use
{

	return soundBufVector;

}*/




/*------------------------------------------------------------------------------------
-------------------------------getTexturePointer--------------------------------------
------------------------------------------------------------------------------------*/
sf::Texture* ResourceGroup::getTexturePointer(int findex)					//returns an element of textureVector -- a pointer to a texture
{

	return textureVector[findex];

}



/*------------------------------------------------------------------------------------
-------------------------------getFontPointer-----------------------------------------
------------------------------------------------------------------------------------*/
sf::Font* ResourceGroup::getFontPointer(int findex)							//returns an element of fontVector -- a pointer to a font
{

	return fontVector[findex];

}




/*------------------------------------------------------------------------------------
-------------------------------getSoundBufPointer-------------------------------------
------------------------------------------------------------------------------------*/
/*sf::SoundBuffer* getSoundBufPointer(int findex)							//returns an element of soundBufVector -- a pointer to a soundBuffer
{

	return soundBufVector[findex];

}*/




/*------------------------------------------------------------------------------------
------------------------------searchNameVector----------------------------------------
------------------------------------------------------------------------------------*/
/*int ResourceGroup::searchNameVector(std::string name, int num)			//searches a vector for a name and returns that index
{
	int returnMe = -1;
	for (int i = 0; i < nameVectors[num].size(); i++)
	{
		if (name == nameVectors[num][i])
		{
			returnMe = i;
			break;
		}

	}

	return returnMe;
}*/




/*------------------------------------------------------------------------------------
------------------------------getTexturePointerbyName---------------------------------
------------------------------------------------------------------------------------*/
/*sf::Texture* ResourceGroup::getTexturePointerByName(std::string name)		//returns a pointer to a texture by name;
																			//I don't think ResourceGroup will have nameVectors, though
{
	int index = searchNameVector(name, 0);

	if (index == -1)
	{
		index++;
	}

	return textureVector[index];
}*/




/*------------------------------------------------------------------------------------
------------------------------getFontPointerbyName------------------------------------
------------------------------------------------------------------------------------*/
/*sf::Font* ResourceGroup::getFontPointerByName(std::string name)			//returns a pointer to a font by name;
																			//I don't think ResourceGroup will have nameVectors, though
{
	int index = searchNameVector(name, 1);

	if (index == -1)
	{
		index++;
	}

	return fontVector[index];
}*/




/*------------------------------------------------------------------------------------
------------------------------getSoundBufPointerbyName---------------------------------
------------------------------------------------------------------------------------*/
/*sf::SoundBuffer* getSoundBufPointerByName(std::string name)				//returns a pointer to a soundBuffer by name;
																			//I don't think ResourceGroup will have nameVectors, though
{
	int index = searchNameVector(name, 0);

	if (index == -1)
	{
	index++;
	}

	return soundBufVector[index];
}*/