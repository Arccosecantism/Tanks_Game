#include "ResourceGroup.h"


ResourceGroup::ResourceGroup()
{
}


void ResourceGroup::addTexture(sf::Texture* ftexture)
{

	textureVector.push_back(ftexture);


}

void ResourceGroup::addFont(sf::Font* ffont)
{

	fontVector.push_back(ffont);

}

/*void addSoundBuf(sf::SoundBuffer* fsoundbuf)
{

	soundBufVector.push_back(fsoundbuf);


}*/








std::vector<sf::Texture*> ResourceGroup::getTextureVector()
{

	return textureVector;

}


std::vector<sf::Font*> ResourceGroup::getFontVector()
{

	return fontVector;

}



/*std::vector<sf::SoundBuffer*> ResourceGroup::getSoundBufVector()
{

	return soundBufVector;

}*/





sf::Texture* ResourceGroup::getTexturePointer(int findex)
{

	return textureVector[findex];

}

sf::Font* ResourceGroup::getFontPointer(int findex)
{

	return fontVector[findex];

}

/*sf::SoundBuffer* getSoundBufPointer(int findex)
{

	return soundBufVector[findex];

}*/





//int ResourceGroup::searchNameVector(std::string name, int num)
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

//sf::Texture* ResourceGroup::getTexturePointerByName(std::string name)
//{
//	int index = searchNameVector(name, 0);
//
//	if (index == -1)
//	{
//		index++;
//	}
//
//	return 
//}

//sf::Font* ResourceGroup::getFontPointerByName(std::string name)
//{
//	int index = searchNameVector(name, 1);
//
//	if (index == -1)
//	{
//		index++;
//	}
//}
//
///*sf::SoundBuffer* getSoundBufPointerByName(std::string name)
//{
//	int index = searchNameVector(name, 0);
//
//	if (index == -1)
//	{
//	index++;
//	}
//}