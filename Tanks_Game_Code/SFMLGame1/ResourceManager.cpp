#include "ResourceManager.h"
#include <iostream>



//----------------------------------------------------------------------------------------------------------------------------***************************
//-----------------------------------------PUBLIC-----------------------------------------------------------------------------***************************
//----------------------------------------------------------------------------------------------------------------------------***************************



/*------------------------------------------------------------------------------------
-------------------------------Constructor--------------------------------------------
------------------------------------------------------------------------------------*/
ResourceManager::ResourceManager()											//Constructor
{
	setVectorSize(4);
}



//----------------------------------------------------------------------------------------------------------------------------***************************


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

	if (tail == "ttf")														//.ttf is a font
	{
		addFont(fileName);													//add the font

		addName(name, Font_Names, fontVector.size() - 1);				//add the name
	}



	else if (	tail == "png" || 
				tail == "jpg" || 
				tail == "jpeg" ||	
				tail == "bmp")												//these extensions are textures
	{
		addTexture(fileName);												//add the texture

		addName(name, Texture_Names, textureVector.size() - 1);				//add the name
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



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
-------------------------------getTexturePointer--------------------------------------
------------------------------------------------------------------------------------*/
sf::Texture* ResourceManager::getTexturePointerByName(std::string fname)					//returns a pointer to a Texture
{
	sf::Texture* returnMe;																//make a temporary pointer to a texture

	returnMe = &textureVector[ntoi(fname, Texture_Names)];							//set it to the texture with the desired name  

	return returnMe;																	//return it
}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
-------------------------------getFontPointer-----------------------------------------
------------------------------------------------------------------------------------*/
sf::Font* ResourceManager::getFontPointerByName(std::string fname)						//returns a pointer to a Font
{

	sf::Font* returnMe;																	//make a temporary pointer to a font

	returnMe = &fontVector[ntoi(fname, Font_Names)];									//set it to the font with the desired name

	return returnMe;																	//return it
	
}



//----------------------------------------------------------------------------------------------------------------------------***************************


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



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
-------------------------------addEmptyRS---------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addEmptyResourceSet(std::string fname)								//adds an empty resourceGroup and give it a name
{
	ResourceGroup empt;																		//make an empty resource group

	resourceSets.push_back(empt);															//add it
	
	addName(fname, ResourceSet_Names);														//add the name
}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
-------------------------------addRS--------------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addResourceSet(ResourceGroup fresourceSet, std::string fname)		//adds an already created resourceGroup and name it
{

	resourceSets.push_back(fresourceSet);												//add the resourceGroup

	addName(fname, ResourceSet_Names);
	
}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
-------------------------------addTexturetoRS-----------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addTexturetoResourceSet(std::string rsName, std::string texName)	//adds a Texture to a resourceSet by name
{
	
	resourceSets[ntoi(rsName, ResourceSet_Names)].addTexture(getTexturePointerByName(texName));
																						//literally just add the texture
}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
-------------------------------addFontoRS---------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addFonttoResourceSet(std::string rsName, std::string fontName)	//adds a Font to a resourceSet by name
{
	
	resourceSets[ntoi(rsName, ResourceSet_Names)].addFont(getFontPointerByName(fontName));
																						//literally just add the font
	
}



//----------------------------------------------------------------------------------------------------------------------------***************************


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



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
-------------------------------getResourceSetByName-----------------------------------
------------------------------------------------------------------------------------*/
ResourceGroup ResourceManager::getResourceSetByName(std::string fname)					//retrives a resourceGroup by name
{

	return resourceSets[ntoi(fname, ResourceSet_Names)];							//returns the resource set with the desired name
	
}






//----------------------------------------------------------------------------------------------------------------------------***************************
//-----------------------------------------PRIVATE----------------------------------------------------------------------------***************************
//----------------------------------------------------------------------------------------------------------------------------***************************



/*------------------------------------------------------------------------------------
-------------------------------addTexture---------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addTexture(std::string fileName)									//private function; adds a Texture to the TextureVector
{
	sf::Texture texture;																//make a temporary texture

	if (!texture.loadFromFile(fileName))												//try to make it load from the file
	{
		std::cout << fileName << " (Texture) failed to load." << std::endl;				// if it doesn't, there is an error
	}

	textureVector.push_back(texture);													//add the texture

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
-------------------------------addFont------------------------------------------------
------------------------------------------------------------------------------------*/
void ResourceManager::addFont(std::string fileName)										//private function; adds a font to the FontVector
{
	sf::Font font;																		//make a temporary font

	if (!font.loadFromFile(fileName))													//try to make it load from the file
	{
		std::cout << fileName << " (Font) failed to load." << std::endl;				// if it doesn't, there is an error
	}

	fontVector.push_back(font);															//add the font
}



//----------------------------------------------------------------------------------------------------------------------------***************************


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



//----------------------------------------------------------------------------------------------------------------------------***************************


///*------------------------------------------------------------------------------------
//-------------------------------addName------------------------------------------------
//------------------------------------------------------------------------------------*/
//void ResourceManager::addName(std::string name, int Mapnum)								//adds a name to one of the namevectors
//{
//	bool sameName = true;
//	bool firstDuplicate = true;
//
//	while (sameName == true)
//	{
//		
//		if (nameMaps[Mapnum].count(name) == 1)
//		{
//			if (firstDuplicate == true)
//			{
//				name += "2";							/*if there exists a "RedTexture" already, and you try to add another one,
//														it will become "RedTexture2"*/
//
//				firstDuplicate = false;
//			}
//			else
//			{
//				name[name.size() - 1]++;				/*if there exists a "RedTexture2" already, and you try to add another one,
//														it will become "RedTexture3"*/
//
//			}
//		}
//
//		else
//		{
//			sameName = false;							//if therer is no same name, exit the while loop
//		}
//
//	}
//
//	nameMaps[Mapnum][name] = elnum;						//then add the altered (or not) name
//
//}

//----------------------------------------------------------------------------------------------------------------------------***************************
