#include "MainMenu.h"


MainMenu::MainMenu()
{

	isActive = true;


}


MainMenu::~MainMenu()
{

}


void MainMenu::setup(ResourceManager& fresourceManager)
{


	MenuElement* textBoxA;
	textBoxA = new SingleTextBox(sf::Vector2f(0,-150), fresourceManager.getFontPointerByName("DefaultFont"), "Test post;\nplease ignore", sf::Vector2f(200, 150), sf::Color::Red);







	MenuElement* greenButtonA;
	greenButtonA = new BasicButton(		sf::Vector2f(0, -150), fresourceManager.getResourceSetByName("GreenButtonRG"),
										"Test1", sf::Color::White, sf::Vector2f(200, 100), sf::Vector2f(100, 50)	);

	BasicButton* p_greenButtonA = static_cast<BasicButton*>(greenButtonA);
	p_greenButtonA->setRelativeTextPosition(sf::Vector2f(0, 0));

	//BasicButton* p_greenButtonA = static_cast<BasicButton*>(greenButtonA);
	//p_greenButtonA->addFunctionToDoOnButtonState(closeSecondMenu, this, 3);


	


	MenuElement* greenButtonB;
	greenButtonB = new BasicButton(	sf::Vector2f(0, 150), fresourceManager.getResourceSetByName("GreenButtonRG"),
									"Test2", sf::Color::White, sf::Vector2f(200, 100), sf::Vector2f(100, 50)	);

	BasicButton* p_greenButtonB = static_cast<BasicButton*>(greenButtonB);
	p_greenButtonB->addFunctionToDoOnButtonState(openSecondMenu, this, 9);
	p_greenButtonB->addFunctionToDoOnButtonState(closeNormalMenu, this, 9);


	MenuElement* greenButtonC;
	greenButtonC = new BasicButton(	sf::Vector2f(0, -150), fresourceManager.getResourceSetByName("GreenButtonRG"),
									"Test3", sf::Color::White, sf::Vector2f(200, 100), sf::Vector2f(100, 50));


	BasicButton* p_greenButtonC = static_cast<BasicButton*>(greenButtonC);
	p_greenButtonC->addFunctionToDoOnButtonState(closeSecondMenu, this, 9);
	p_greenButtonC->addFunctionToDoOnButtonState(openNormalMenu, this, 9);

	

	

	MenuElement* walrusBG;
	walrusBG = new MenuBackground(	sf::Vector2f(0, 0), fresourceManager.getTexturePointerByName("WalrusBackground"),
									sf::Vector2f(800, 600)	);

	MenuElement* giraffeBG;
	giraffeBG = new MenuBackground(	sf::Vector2f(0, 0), fresourceManager.getTexturePointerByName("GiraffeBackground"),
									sf::Vector2f(800, 600));
	
	


	Menu defaultMenu;
	Menu secondMenu;

	defaultMenu.addMenuElement(walrusBG, "WalrusBackground");
	defaultMenu.addMenuElement(greenButtonA, "TopGreenButton");
	defaultMenu.addMenuElement(greenButtonB, "BottomGreenButton");
	defaultMenu.addMenuElement(textBoxA, "TextBoxA");



	secondMenu.addMenuElement(giraffeBG, "GiraffeBackground");
	secondMenu.addMenuElement(greenButtonC, "TopGreenButtonS");
	


	MainMenuManager.addMenu(defaultMenu, "NormalMenu", sf::Vector2f(400, 300));
	MainMenuManager.addMenu(secondMenu, "SecondMenu", sf::Vector2f(400, 300));
	MainMenuManager.getMenuPointerByName("SecondMenu")->deactivate();



	//delete greenButtonA;
	//delete greenButtonB;
	//delete walrusBG;

}


void MainMenu::activate()
{

	isActive = true;

	MainMenuManager.activateAllMenus();

}

void MainMenu::deactivate()
{

	isActive = false;

	MainMenuManager.deactivateAllMenus();

}

void MainMenu::switchActivity()
{

	setActivity(!isActive);

}

void MainMenu::setActivity(bool factive)
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


bool MainMenu::getActivity()
{

	return isActive;

}

void MainMenu::update(MouseData& fmouseData)
{

	MainMenuManager.update(fmouseData);

}

void MainMenu::draw(sf::RenderWindow& frenderwindow)
{

	MainMenuManager.draw(frenderwindow);

}


//void (MainMenu::* MainMenu::getPointerToFunctionByName(std::string fname))()
//{
//
//	void(MainMenu::*tmpPointerToFunction)();
//
//	tmpPointerToFunction = pointersToFunctions[fname];
//
//	return tmpPointerToFunction;
//
//}



void MainMenu::openNormalMenu(void* fmainmenu)
{
	MainMenu* tmpThis = static_cast<MainMenu*>(fmainmenu);
	tmpThis->openNormalMenuCalled();
}

void MainMenu::openNormalMenuCalled()
{
	MainMenuManager.getMenuPointerByName("NormalMenu")->activate();
}



void MainMenu::closeNormalMenu(void* fmainmenu)
{
	MainMenu* tmpThis = static_cast<MainMenu*>(fmainmenu);
	tmpThis->closeNormalMenuCalled();
}

void MainMenu::closeNormalMenuCalled()
{
	MainMenuManager.getMenuPointerByName("NormalMenu")->deactivate();
}



void MainMenu::openSecondMenu(void* fmainmenu)
{
	MainMenu* tmpThis = static_cast<MainMenu*>(fmainmenu);
	tmpThis->openSecondMenuCalled();
}

void MainMenu::openSecondMenuCalled()
{
	MainMenuManager.getMenuPointerByName("SecondMenu")->activate();
}



void MainMenu::closeSecondMenu(void* fmainmenu)
{
	MainMenu* tmpThis = static_cast<MainMenu*>(fmainmenu);
	tmpThis->closeSecondMenuCalled();
}

void MainMenu::closeSecondMenuCalled()
{
	MainMenuManager.getMenuPointerByName("SecondMenu")->deactivate();
}