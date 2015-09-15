#pragma once
#include "ResourceGroup.h"

class ResourceManager						//This is unimpressive. IT DOES NOT CURRENTLY load all files from a directory.
{
public:

	ResourceManager();

	void addFile(std::string fileName, std::string name);

	sf::Font* getFontPointerByName(std::string name);
	sf::Texture* getTexturePointerByName(std::string name);
	//sf::SoundBuffer* getSoundBufPointerByName(std::string name);

	void addResourceSet();

private:

	void addFont(std::string fileName);
	void addTexture(std::string fileName);
	//void addSoundBuf(std::string fileName);

	void addName(std::string name, int num);


	int searchNameVector(std::string name, int num);

	std::vector<sf::Font> fontVector;
	std::vector<sf::Texture> textureVector;
	//std::vector<sf::SoundBuffer> soundBufVector;


	std::vector<ResourceGroup> resourceSets;

	std::vector<std::string> nameVectors[4];


	
};

