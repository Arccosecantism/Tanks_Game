#include "ResourceManager.h"


/*------------------------------------------------------------------------------------
-------------------------------Constructor--------------------------------------------
------------------------------------------------------------------------------------*/
ResourceManager::ResourceManager()											//Constructor
{

}





/*------------------------------------------------------------------------------------
-------------------------------addFile------------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addFile(std::string fileName, std::string name)		//adds a generic file
{



	std::string reverseTail = "";											//will be a reversed file extension
	std::string tail = "";													//will be the actual file extension

	for (int i = fileName.size() - 1; i >= 0; i--)							/*cycles from the back of the file name
																			and records the reversed file extension*/
	{
		if (fileName[i] == '.')												//goes to the dot
		{
			break;
		}
		else
		{
			reverseTail += fileName[i];										//otherwise, record the letter -- will be backwards when done in succession
		}
	}


	for (int i = reverseTail.size() - 1; i >= 0; i--)						//reverses the file extension
	{
		tail += reverseTail[i];
	}



	//---------------------------------------------
	//Now we interpret the file extension.
	//----------------------------------------------

	if (tail == "ttf")
	{
		addFont(fileName);
		addName(name, Texture_Names, textureVector.size() - 1);
	}



	else if (	tail == "png" || 
				tail == "jpg" || 
				tail == "jpeg" || 
				tail == "bmp")
	{
		addTexture(fileName);
		addName(name, Texture_Names, textureVector.size() - 1);
	}


	//else if (	tail == "wav" ||
	//			tail == "aif" ||
	//			tail == "mp3" ||
	//			tail == "mp2" ||
	//			tail == "ogg" ||
	//			tail == "raw")
	//{
	//	addSoundBuf(fileName);
	//	addName(name, SoundBuf_Names);
	//}


}







/*------------------------------------------------------------------------------------
-------------------------------getTexturePointer--------------------------------------
------------------------------------------------------------------------------------*/
sf::Texture* ResourceManager::getTexturePointerByName(std::string name)					//returns a pointer to a Texture
{
	sf::Texture* returnMe;

	returnMe = &textureVector[nameMaps[Texture_Names][name]];

	return returnMe;
}





/*------------------------------------------------------------------------------------
-------------------------------getFontPointer-----------------------------------------
------------------------------------------------------------------------------------*/
sf::Font* ResourceManager::getFontPointerByName(std::string name)						//returns a pointer to a Font
{

	sf::Font* returnMe;

	returnMe = &fontVector[nameMaps[Font_Names][name]];

	return returnMe;
	
}




/*------------------------------------------------------------------------------------
-------------------------------getSBPointer-------------------------------------------
------------------------------------------------------------------------------------*/
//sf::SoundBuffer* ResourceManager::getSoundBufPointerByName(std::string name)			//returns a pointer to a SoundBuf
//{
//
//	int index = searchNameVector(name, SoundBuf_Names);
//	sf::SoundBuffer* returnMe;
//
//	if (index == -1)
//	{
//		index++;
//	}
//
//	returnMe = &soundBufVector[index];
//
//	return returnMe;
//
//}



/*------------------------------------------------------------------------------------
-------------------------------addEmptyRS---------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addEmptyResourceSet(std::string fname)								//adds an empty resourceGroup and give it a name
{
	ResourceGroup empt;
	resourceSets.push_back(empt);
	
	nameMaps[ResourceSet_Names][fname] = resourceSets.size() - 1;
}




/*------------------------------------------------------------------------------------
-------------------------------addRS--------------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addResourceSet(ResourceGroup fresourceSet, std::string fname)		//adds an already created resourceGroup and name it
{
	resourceSets.push_back(fresourceSet);
	nameMaps[ResourceSet_Names][fname] = resourceSets.size() - 1;
	
}
	
	
	
	
/*------------------------------------------------------------------------------------
-------------------------------addTexturetoRS-----------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addTexturetoResourceSet(std::string rsName, std::string texName)	//adds a Texture to a resourceSet by name
{
	
	resourceSets[nameMaps[ResourceSet_Names][rsName]].addTexture(getTexturePointerByName(texName));	
}




/*------------------------------------------------------------------------------------
-------------------------------addFontoRS---------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addFonttoResourceSet(std::string rsName, std::string fontName)	//adds a Font to a resourceSet by name
{
	
	resourceSets[nameMaps[ResourceSet_Names][rsName]].addFont(getFontPointerByName(fontName));
	
}





/*------------------------------------------------------------------------------------
-------------------------------addSoundBuftoRS----------------------------------------
------------------------------------------------------------------------------------*/
/*void addSoundBuftoResourceSet(std::string rsName, std::string sbName)					//adds a SoundBuf to a resourceSet by name
{
	int indexrs = searchNameVector(rsName, ResourceSet_Names);
	int indexsb = searchNameVector(sbName, SoundBuf_Names);
	
	if (indexrs == -1)
	{
		indexrs++;
	}
	
	if (indexsb == -1)
	{
		indexsb++;
	}
	
	resourceSets[indexrs].addSoundBuf(getFontPointerByName(sbName));
}*/
	
	
	
	
/*------------------------------------------------------------------------------------
-------------------------------getResourceSetByName-----------------------------------
------------------------------------------------------------------------------------*/
ResourceGroup ResourceManager::getResourceSetByName(std::string fname)					//retrives a resourceGroup by name
{

	return resourceSets[nameMaps[ResourceSet_Names][fname]];
	
}
	
	
	
///*------------------------------------------------------------------------------------
//-------------------------------searchNameVector---------------------------------------
//------------------------------------------------------------------------------------*/
//int ResourceManager::searchNameVector(std::string name, int num)						//searches an element in a vector by name
//{
//	int returnMe = -1;
//	for (int i = 0; i < nameVectors[num].size(); i++)
//	{
//		if (name == nameVectors[num][i])
//		{
//			returnMe = i;
//			break;
//		}
//
//	}
//	
//	return returnMe;
//}
//


/*------------------------------------------------------------------------------------
-------------------------------addTexture---------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addTexture(std::string fileName)									////private function; adds a Texture to the TextureVector
{
	sf::Texture texture;
	if (!texture.loadFromFile(fileName))
	{
		// error...
	}
	textureVector.push_back(texture);

}




/*------------------------------------------------------------------------------------
-------------------------------addFont------------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addFont(std::string fileName)										//private function; adds a font to the FontVector
{
	sf::Font font;
	if (!font.loadFromFile(fileName))
	{
		// error...
	}
	fontVector.push_back(font);
}




/*------------------------------------------------------------------------------------
-------------------------------addSoundBuf-------------------------------------------
------------------------------------------------------------------------------------*/
//void ResourceManager::addSoundBuf(std::string fileName)								//private function; adds a soundBuf to the soundBufVector
//{
//
//	sf::SoundBuffer buffer;
//	if (!buffer.loadFromFile(fileName))
//	{
//		//error...
//	}
//	soundBufVector.push_back(buffer);
//
//}






/*------------------------------------------------------------------------------------
-------------------------------addName------------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addName(std::string name, int Mapnum, int elnum)								//adds a name to one of the namevectors
{
	bool sameName = true;
	bool firstDuplicate = true;

	while (sameName == true)
	{
		
		if (nameMaps[Mapnum].count(name) == 1)
		{
			if (firstDuplicate == true)
			{
				name += "2";							/*if there exists a "RedTexture" already, and you try to add another one,
														it will become "RedTexture2"*/

				firstDuplicate = false;
			}
			else
			{
				name[name.size() - 1]++;				/*if there exists a "RedTexture2" already, and you try to add another one,
														it will become "RedTexture3"*/

			}
		}

		else
		{
			sameName = false;							//if therer is no same name, exit the while loop
		}

	}

	nameMaps[Mapnum][name] = elnum;						//then add the altered (or not) name

}
