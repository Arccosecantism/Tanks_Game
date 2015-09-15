#include "ResourceManager.h"


/*------------------------------------------------------------------------------------
-------------------------------Constructor--------------------------------------------
------------------------------------------------------------------------------------*/
ResourceManager::ResourceManager()
{

}





/*------------------------------------------------------------------------------------
-------------------------------addFile------------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addFile(std::string fileName, std::string name)
{
	std::string reverseTail = "";
	std::string tail = "";

	for (int i = fileName.size() - 1; i >= 0; i--)
	{
		if (fileName[i] == '.')
		{
			break;
		}
		else
		{
			reverseTail += fileName[i];
		}
	}


	for (int i = reverseTail.size() - 1; i >= 0; i--)
	{
		tail += reverseTail[i];
	}




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
-------------------------------getFontPointer-----------------------------------------
------------------------------------------------------------------------------------*/
sf::Font* ResourceManager::getFontPointerByName(std::string name)
{
	int index = searchNameVector(name, 0);
	sf::Font* returnMe;

	if (index == -1)
	{
		index++;
	}

	returnMe = &fontVector[index];

	return returnMe;
	
}





/*------------------------------------------------------------------------------------
-------------------------------getTexturePointer--------------------------------------
------------------------------------------------------------------------------------*/
sf::Texture* ResourceManager::getTexturePointerByName(std::string name)
{

	int index = searchNameVector(name, 0);
	sf::Texture* returnMe;

	if (index == -1)
	{
		index++;
	}

	returnMe = &textureVector[index];

	return returnMe;
}



/*------------------------------------------------------------------------------------
-------------------------------getSBPointer-------------------------------------------
------------------------------------------------------------------------------------*/
//sf::SoundBuffer* ResourceManager::getSoundBufPointerByName(std::string name)
//{
//
//	int index = searchNameVector(name, 0);
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
void ResourceManager::addEmptyResourceSet(std::string name)
{
	resourceGroup empt;
	resourceSets.push_back(empt);
	
	nameVectors[ResourceSet_Names].push_back(name);
}




/*------------------------------------------------------------------------------------
-------------------------------addRS---------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addResourceSet(ResourceGroup fresourceSet, std::string name)
{
	resourceSets.push_back(fresourceSet);
	nameVectors[ResourceSet_Names].push_back(name);
	
}
	
	
	
	
/*------------------------------------------------------------------------------------
-------------------------------addTextoRS---------------------------------------------
------------------------------------------------------------------------------------*/
void addTexturetoResourceSet(std::string rsName, std::string texName)
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
	
	
	
	
	
}

/*------------------------------------------------------------------------------------
-------------------------------addFontoRS---------------------------------------------
------------------------------------------------------------------------------------*/
void addFonttoResourceSet(std::string rsName, std::string fontName)
{
	
	
}

/*------------------------------------------------------------------------------------
-------------------------------addSoundBuftoRS----------------------------------------
------------------------------------------------------------------------------------*/
//void addSoundBuftoResourceSet(std::string rsName, std::string sbName);
	
	
	
	
/*------------------------------------------------------------------------------------
-------------------------------searchNameVector---------------------------------------
------------------------------------------------------------------------------------*/
int ResourceManager::searchNameVector(std::string name, int num)
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
-------------------------------addFont------------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addFont(std::string fileName)
{
	sf::Font font;
	if (!font.loadFromFile(fileName))
	{
		// error...
	}
	fontVector.push_back(font);
}



/*------------------------------------------------------------------------------------
-------------------------------addTexture---------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addTexture(std::string fileName)
{
	sf::Texture texture;
	if (!texture.loadFromFile(fileName))
	{
		// error...
	}
	textureVector.push_back(texture);

}




/*------------------------------------------------------------------------------------
-------------------------------addSoundBuf-------------------------------------------
------------------------------------------------------------------------------------*/
//void ResourceManager::addSoundBuf(std::string fileName)
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
void ResourceManager::addName(std::string name, int num)
{
	bool sameName = true;
	bool firstDuplicate = true;

	while (sameName == true)
	{
		
		if (searchNameVector(name, num) != -1)
		{
			if (firstDuplicate == true)
			{
				name += "2";
			}
			else
			{
				name[name.size() - 1]++;
			}
		}

		else
		{
			sameName = false;
		}

	}

	nameVectors[num].push_back(name);

}
