#pragma once
#include "MenuManager.h"

class MainMenu
{
public:

	MainMenu();

	~MainMenu();

	void setup(ResourceManager& fresourceManager);


	void activate();

	void deactivate();

	void switchActivity();

	void setActivity(bool factive);

	bool getActivity();


	

	void update(MouseData& fmouseData);

	void draw(sf::RenderWindow& frenderwindow);

private:
	

	void (MainMenu::* getPointerToFunctionByName(std::string fname))();

	void openNormalMenu();

	void closeNormalMenu();

	void openSecondMenu();

	void closeSecondMenu();


	MenuManager MainMenuManager;

	bool isActive;

	std::map<std::string, void(MainMenu::*)()> pointersToFunctions;
};

