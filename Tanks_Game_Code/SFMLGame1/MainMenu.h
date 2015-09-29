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
	

	/*void (MainMenu::* getPointerToFunctionByName(std::string fname))();*/

	static void openNormalMenu(void* fmainmenu);
	void openNormalMenuCalled();

	static void closeNormalMenu(void* fmainmenu);
	void closeNormalMenuCalled();

	static void openSecondMenu(void* fmainmenu);
	void openSecondMenuCalled();

	static void closeSecondMenu(void* fmainmenu);
	void closeSecondMenuCalled();


	MenuManager MainMenuManager;

	bool isActive;

	/*std::map<std::string, void(MainMenu::*)()> pointersToFunctions;*/
};

