#pragma once
#include "SFMLbase.h"
class ResourceGroup
{

public:

	ResourceGroup();

	void addTexture(sf::Texture* ftexture);
	void addFont(sf::Font* ffont);
	//void addSoundBuf(sf::SoundBuffer* fsoundbuf);


	std::vector<sf::Texture*> getTextureVector();
	std::vector<sf::Font*> getFontVector();
	//std::vector<sf::SoundBuffer*> getSoundBufVector();

	sf::Texture* getTexturePointer(int findex);
	sf::Font* getFontPointer(int findex);
	//sf::SoundBuffer* getSoundBufPointer(int findex);

	//sf::Texture* getTexturePointerByName(std::string name);
	//sf::Font* getFontPointerByName(std::string name);
	////sf::SoundBuffer* getSoundBufPointerByName(std::string name);


private:

	//int searchNameVector(std::string name, int num);

	std::vector<sf::Texture*> textureVector;
	std::vector<sf::Font*> fontVector;
	//std::vector<sf::SoundBuffer*> soundBufVector;

	
	//std::vector<std::string> nameVectors[3];

};

