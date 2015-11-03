#include "MainMenu.h"


//----------------------------------------------------------------------------------------------------------------------------***************************
//-----------------------------------------PUBLIC-----------------------------------------------------------------------------***************************
//----------------------------------------------------------------------------------------------------------------------------***************************



/*------------------------------------------------------------------------------------
----------------------------constructor-----------------------------------------------
------------------------------------------------------------------------------------*/
MainMenu::MainMenu()
{

	isActive = true;										//starts off as active


}



/*------------------------------------------------------------------------------------
----------------------------destructor------------------------------------------------
------------------------------------------------------------------------------------*/
MainMenu::~MainMenu()
{

}



/*------------------------------------------------------------------------------------
----------------------------setup-----------------------------------------------------
------------------------------------------------------------------------------------*/
void MainMenu::setup(ResourceManager& fresourceManager)							//setup
{

	//makes a textbox

	MenuElement* textBoxA;
	textBoxA = new SingleTextBox(sf::Vector2f(0, 0), fresourceManager.getFontPointerByName("DefaultFont"), "Welcome to the Grand Walrus Menu!", 50, 300, sf::Color::Red);





	//makes a BasicButton

	MenuElement* greenButtonA;
	greenButtonA = new BasicButton(		sf::Vector2f(0, -150), fresourceManager.getResourceSetByName("GreenButtonRG"),
										"Test1", sf::Color::White, sf::Vector2f(200, 100), 50	);


	



	//makes a BasicButton

	MenuElement* greenButtonB;
	greenButtonB = new BasicButton(	sf::Vector2f(0, 150), fresourceManager.getResourceSetByName("GreenButtonRG"),
									"Test2", sf::Color::White, sf::Vector2f(200, 100), 50	);

	//gives the basic button callback functions

	BasicButton* p_greenButtonB = static_cast<BasicButton*>(greenButtonB);		//cast the menuElement as a basicButton


	p_greenButtonB->addFunctionToDoOnButtonState(openSecondMenu, this, 12);		//add the openSecondMenu to the button on click

	p_greenButtonB->addFunctionToDoOnButtonState(closeNormalMenu, this, 12);	//add the closeNormalMenu to the button on click





	//same thing, essentially

	MenuElement* greenButtonC;

	greenButtonC = new BasicButton(	sf::Vector2f(0, -150), fresourceManager.getResourceSetByName("GreenButtonRG"),
									"Test3", sf::Color::White, sf::Vector2f(200, 100), 50	);


	BasicButton* p_greenButtonC = static_cast<BasicButton*>(greenButtonC);


	p_greenButtonC->addFunctionToDoOnButtonState(openNormalMenu, this, 12);

	p_greenButtonC->addFunctionToDoOnButtonState(closeSecondMenu, this, 12);

	




	//same thing but with a slider

	MenuElement* testSlider;

	testSlider = new Slider(	fresourceManager.getTexturePointerByName("SliderBackground"), fresourceManager.getTexturePointerByName("SliderNotch"),
								fresourceManager.getTexturePointerByName("SliderButton"), sf::Vector2f(200, 50), sf::Vector2f(150, 20), sf::Vector2f(20, 40),
								sf::Vector2f(0, 150), sliderVariable, 0, 100, 80); 




	//create a menu background

	MenuElement* walrusBG;
	walrusBG = new MenuBackground(	sf::Vector2f(0, 0), fresourceManager.getTexturePointerByName("WalrusBackground"),
									sf::Vector2f(800, 600)	);


	//again...

	MenuElement* giraffeBG;
	giraffeBG = new MenuBackground(	sf::Vector2f(0, 0), fresourceManager.getTexturePointerByName("GiraffeBackground"),
									sf::Vector2f(800, 600));
	
	

	//make two menus

	Menu defaultMenu;

	Menu secondMenu;


	//add the elements to one menu (order matters now)

	defaultMenu.addMenuElement(walrusBG, "WalrusBackground");
	defaultMenu.addMenuElement(greenButtonA, "TopGreenButton");
	defaultMenu.addMenuElement(greenButtonB, "BottomGreenButton");
	defaultMenu.addMenuElement(textBoxA, "TextBoxA");


	//add the elements to the other menu (order matters now)

	secondMenu.addMenuElement(giraffeBG, "GiraffeBackground");
	secondMenu.addMenuElement(greenButtonC, "TopGreenButtonS");
	secondMenu.addMenuElement(testSlider, "TestSlider");
	


	// add the menus to the menuManager (order matters)

	MainMenuManager.addMenu(defaultMenu, "NormalMenu", sf::Vector2f(400, 300));
	MainMenuManager.addMenu(secondMenu, "SecondMenu", sf::Vector2f(400, 300));
	MainMenuManager.getMenuPointerByName("SecondMenu")->deactivate();



	//delete greenButtonA;
	//delete greenButtonB;
	//delete walrusBG;

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
----------------------------activate--------------------------------------------------
------------------------------------------------------------------------------------*/
void MainMenu::activate()						//acitivate the main menu
{

	isActive = true;

	MainMenuManager.activateAllMenus();			//activates all menus

}



/*------------------------------------------------------------------------------------
----------------------------deactivate------------------------------------------------
------------------------------------------------------------------------------------*/
void MainMenu::deactivate()						//deacitivate the main menu
{

	isActive = false;

	MainMenuManager.deactivateAllMenus();

}



/*------------------------------------------------------------------------------------
----------------------------switchActivity--------------------------------------------
------------------------------------------------------------------------------------*/
void MainMenu::switchActivity()					//switch the activity of the main menu
{

	setActivity(!isActive);

}



/*------------------------------------------------------------------------------------
----------------------------setActivity-----------------------------------------------
------------------------------------------------------------------------------------*/
void MainMenu::setActivity(bool factive)		//set the activity of the main menu
{
	if (factive)
	{
		activate();
	}

	else
	{
		deactivate();
	}
}



/*------------------------------------------------------------------------------------
---------------------------getActivity------------------------------------------------
------------------------------------------------------------------------------------*/
bool MainMenu::getActivity()					//return the activity of the main menu
{

	return isActive;

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
----------------------------update----------------------------------------------------
------------------------------------------------------------------------------------*/
void MainMenu::update(MouseData& fmouseData)	//updates the mainMenuManager
{
	//std::cout << sliderVariable << std::endl;
	MainMenuManager.update(fmouseData);

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
----------------------------draw------------------------------------------------------
------------------------------------------------------------------------------------*/
void MainMenu::draw(sf::RenderWindow& frenderwindow)	//draws the mainMenuManager
{

	MainMenuManager.draw(frenderwindow);

}






//----------------------------------------------------------------------------------------------------------------------------***************************
//-----------------------------------------PRIVATE----------------------------------------------------------------------------***************************
//----------------------------------------------------------------------------------------------------------------------------***************************






//this area is explained more in the heared file; it's essentially an easy way to convert between method pointer and generic funtion pointer

/*------------------------------------------------------------------------------------
----------------------------openNormalMenu--------------------------------------------
------------------------------------------------------------------------------------*/
//{

void MainMenu::openNormalMenu(void* fmainmenu)
{
	MainMenu* tmpThis = static_cast<MainMenu*>(fmainmenu);
	tmpThis->openNormalMenuCalled();
}

//^v^v^v^v^v^v^v^v^v^v^v^v^v^v^^v^v^v^v^v^v^v^v^v^v^v^v^v^v^^v^v^v^v^v^v^v^v^v^v^v^v^v^v^

void MainMenu::openNormalMenuCalled()
{
	MainMenuManager.getMenuPointerByName("NormalMenu")->activate();
}

//}



/*------------------------------------------------------------------------------------
----------------------------openNormalMenu--------------------------------------------
------------------------------------------------------------------------------------*/
//{

void MainMenu::closeNormalMenu(void* fmainmenu)
{
	MainMenu* tmpThis = static_cast<MainMenu*>(fmainmenu);
	tmpThis->closeNormalMenuCalled();
}

//^v^v^v^v^v^v^v^v^v^v^v^v^v^v^^v^v^v^v^v^v^v^v^v^v^v^v^v^v^^v^v^v^v^v^v^v^v^v^v^v^v^v^v^

void MainMenu::closeNormalMenuCalled()
{
	MainMenuManager.getMenuPointerByName("NormalMenu")->deactivate();
}

//}



/*------------------------------------------------------------------------------------
----------------------------openNormalMenu--------------------------------------------
------------------------------------------------------------------------------------*/
//{

void MainMenu::openSecondMenu(void* fmainmenu)
{
	MainMenu* tmpThis = static_cast<MainMenu*>(fmainmenu);
	tmpThis->openSecondMenuCalled();
}

//^v^v^v^v^v^v^v^v^v^v^v^v^v^v^^v^v^v^v^v^v^v^v^v^v^v^v^v^v^^v^v^v^v^v^v^v^v^v^v^v^v^v^v^

void MainMenu::openSecondMenuCalled()
{
	MainMenuManager.getMenuPointerByName("SecondMenu")->activate();
}

//}



/*------------------------------------------------------------------------------------
----------------------------openNormalMenu--------------------------------------------
------------------------------------------------------------------------------------*/
//{

void MainMenu::closeSecondMenu(void* fmainmenu)
{
	MainMenu* tmpThis = static_cast<MainMenu*>(fmainmenu);
	tmpThis->closeSecondMenuCalled();
}

//^v^v^v^v^v^v^v^v^v^v^v^v^v^v^^v^v^v^v^v^v^v^v^v^v^v^v^v^v^^v^v^v^v^v^v^v^v^v^v^v^v^v^v^

void MainMenu::closeSecondMenuCalled()
{
	MainMenuManager.getMenuPointerByName("SecondMenu")->deactivate();
}

//}



//----------------------------------------------------------------------------------------------------------------------------***************************