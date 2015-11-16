#pragma once
#include "ResourceGroup.h"




class ResourceManager : public NameSearchable								/*This class will basically hold all textures, fonts, and soundBufs.*/
{																			/*Part of this is unimpressive -- IT DOES NOT CURRENTLY
																			load all files from a directory.*/

/*---------------------------------------------------------------------------------------------------------

NOTES: SoundBuffer doesnt work yet, so elements that pertain to them are likely commented out for now.

----------------------------------------------------------------------------------------------------------*/


public:

	ResourceManager();														//Constructor


	void addFile(std::string fileName, std::string name);					//Adds a generic file



	sf::Texture* getTexturePointerByName(std::string name);					//retrieves a pointer to a texture
	sf::Font* getFontPointerByName(std::string name);						//Retrieves a pointer to a font
	//sf::SoundBuffer* getSoundBufPointerByName(std::string name);



	void addEmptyResourceSet(std::string name);								//sets a new empty resourceGroup to resourceSet
	void addResourceSet(ResourceGroup fresourceSet, std::string name);		//sets a currently filled resourceGroup to resourceSet
	//void addResourceSet(Texture* texPArray[], Font* fontPArray[] /*, soundBufPArray[] */, std::string name);
	


	void addTexturetoResourceSet(std::string rsName, std::string texName);	//adds a Texture to a resourceSet
	void addFonttoResourceSet(std::string rsName, std::string fontName);	//adds a Font to a resourceSet
	//void addSoundBuftoResourceSet(std::string rsName, std::string sbName);
	
	ResourceGroup* getResourceSetByName(std::string fname); 
	


private:




	void addTexture(std::string fileName);									//adds a Texture
	void addFont(std::string fileName);										//adds a Font
	//void addSoundBuf(std::string fileName);								//adds a SoundBuf




	//int searchNameVector(std::string name, int num);						//searches through a vector to find a name



	std::vector<sf::Texture> textureVector;									//vector of Textures that will be used in the program

	std::vector<sf::Font> fontVector;										//vector of Fonts that will be used in the whole program
	//std::vector<sf::SoundBuffer> soundBufVector;



	std::vector<ResourceGroup> resourceSets;								/*presets for certain things like BasicButton. BasicButton will use
																			the preset Textures, Fonts, and SoundBuffers for BasicButton*/


	
	enum nameVectorIndeces {Texture_Names = 0, Font_Names = 1, SoundBuf_Names = 2, ResourceSet_Names = 3}; 
																			//enum for accessing vectors more intuitively


	
};

