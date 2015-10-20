#pragma once
#include "MenuManager.h"

class MainMenu										//A very specific class that runs itself well; it is the main menu of the program
{
public:
		
	MainMenu();										//constructor

	~MainMenu();									//destructor

	void setup(ResourceManager& fresourceManager);	//MainMenu requires a resource manager before it does anything


	//these functions are intuitive. NOTE: many of these functions deactivate the menuManager
	void activate();								//activate MainMenu (implies drawing and updating)

	void deactivate();

	void switchActivity();

	void setActivity(bool factive);

	bool getActivity();


	

	void update(MouseData& fmouseData);				//update with mouse data

	void draw(sf::RenderWindow& frenderwindow);		//draws its menuManager


private:
	

	
	//the following section is iffy:  These functions seem out of place because menuManager should set menus to be active.
	//These are here because  theis is where basic buttons are being created, and their callback functions need to be set.

	//Each button will get the static part of the function pairs because its not a class method
	//The static part requires a pointer to a main menu to call the secondary, non-static part of the function couple

	static void openNormalMenu(void* fmainmenu);	//opens the normal menu
	void openNormalMenuCalled();

	static void closeNormalMenu(void* fmainmenu);	//etc...
	void closeNormalMenuCalled();

	static void openSecondMenu(void* fmainmenu);
	void openSecondMenuCalled();

	static void closeSecondMenu(void* fmainmenu);
	void closeSecondMenuCalled();


	MenuManager MainMenuManager;					//the menuManager of the main menu

	bool isActive;									//is true if the main menu is being displayed.

	double sliderVariable;							//tmp: will get rid of eventually. Jsut here to test slider.

};

