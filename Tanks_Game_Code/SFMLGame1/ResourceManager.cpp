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
		addName(name, Texture_Names);
	}



	else if (	tail == "png" || 
				tail == "jpg" || 
				tail == "jpeg" || 
				tail == "bmp")
	{
		addTexture(fileName);
		addName(name, Font_Names);
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

	int index = searchNameVector(name, Texture_Names);
	sf::Texture* returnMe;

	if (index == -1)
	{
		index++;
	}

	returnMe = &textureVector[index];

	return returnMe;
}





/*------------------------------------------------------------------------------------
-------------------------------getFontPointer-----------------------------------------
------------------------------------------------------------------------------------*/
sf::Font* ResourceManager::getFontPointerByName(std::string name)						//returns a pointer to a Font
{
	int index = searchNameVector(name, Font_Names);
	sf::Font* returnMe;

	if (index == -1)
	{
		index++;
	}

	returnMe = &fontVector[index];

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
void ResourceManager::addEmptyResourceSet(std::string name)								//adds an empty resourceGroup and give it a name
{
	ResourceGroup empt;
	resourceSets.push_back(empt);
	
	nameVectors[ResourceSet_Names].push_back(name);
}




/*------------------------------------------------------------------------------------
-------------------------------addRS--------------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addResourceSet(ResourceGroup fresourceSet, std::string name)		//adds an already created resourceGroup and name it
{
	resourceSets.push_back(fresourceSet);
	nameVectors[ResourceSet_Names].push_back(name);
	
}
	
	
	
	
/*------------------------------------------------------------------------------------
-------------------------------addTexturetoRS-----------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addTexturetoResourceSet(std::string rsName, std::string texName)	//adds a Texture to a resourceSet by name
{
	int indexrs = searchNameVector(rsName, ResourceSet_Names);
	int indextx = searchNameVector(texName, Texture_Names);
	
	if (indexrs == -1)
	{
		indexrs++;
	}
	
	if (indextx == -1)
	{
		indextx++;
	}
	
	resourceSets[indexrs].addTexture(getTexturePointerByName(texName));
	
	
}




/*------------------------------------------------------------------------------------
-------------------------------addFontoRS---------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addFonttoResourceSet(std::string rsName, std::string fontName)	//adds a Font to a resourceSet by name
{
	
	int indexrs = searchNameVector(rsName, ResourceSet_Names);
	int indexfn = searchNameVector(fontName, Font_Names);
	
	if (indexrs == -1)
	{
		indexrs++;
	}
	
	if (indexfn == -1)
	{
		indexfn++;
	}
	
	resourceSets[indexrs].addFont(getFontPointerByName(fontName));
	
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
	int index = searchNameVector(fname, ResourceSet_Names);
	
	if (index == -1)
	{
		index++;
	}
	
	return resourceSets[index];
	
}
	
	
	
/*------------------------------------------------------------------------------------
-------------------------------searchNameVector---------------------------------------
------------------------------------------------------------------------------------*/
int ResourceManager::searchNameVector(std::string name, int num)						//searches an element in a vector by name
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
}



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
void ResourceManager::addName(std::string name, int num)								//adds a name to one of the namevectors
{
	bool sameName = true;
	bool firstDuplicate = true;

	while (sameName == true)
	{
		
		if (searchNameVector(name, num) != -1)
		{
			if (firstDuplicate == true)
			{
				name += "2";							/*if there exists a "RedTexture" already, and you try to add another one,
														it will become "RedTexture2"*/
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

	nameVectors[num].push_back(name);					//then add the altered (or not) name

}
