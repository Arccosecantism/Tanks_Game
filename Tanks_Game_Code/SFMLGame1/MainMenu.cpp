#include "MainMenu.h"


MainMenu::MainMenu()
{

	isActive = true;


	void(MainMenu::* tmpPointer)();

	tmpPointer = &openNormalMenu;
	pointersToFunctions["openNormalMenu"] = tmpPointer;

	tmpPointer = &closeNormalMenu;
	pointersToFunctions["closeNormalMenu"] = tmpPointer;

	tmpPointer = &openSecondMenu;
	pointersToFunctions["openSecondMenu"] = tmpPointer;

	tmpPointer = &closeSecondMenu;
	pointersToFunctions["closeSecondMenu"] = tmpPointer;


}


MainMenu::~MainMenu()
{

}


void MainMenu::setup(ResourceManager& fresourceManager)
{
	MenuElement* greenButtonA;
	greenButtonA = new BasicButton(		sf::Vector2f(0, -150), fresourceManager.getResourceSetByName("GreenButtonRG"),
										"Test1", sf::Color::White, sf::Vector2f(200, 100), sf::Vector2f(100, 50)	);

	BasicButton* p_greenButtonA = static_cast<BasicButton*>(greenButtonA);
	p_greenButtonA->setRelativeTextPosition(sf::Vector2f(0, 0));


	


	MenuElement* greenButtonB;
	greenButtonB = new BasicButton(	sf::Vector2f(0, 150), fresourceManager.getResourceSetByName("GreenButtonRG"),
									"Test2", sf::Color::White, sf::Vector2f(200, 100), sf::Vector2f(100, 50)	);

	MenuElement* greenButtonC;
	greenButtonC = new BasicButton(	sf::Vector2f(0, -150), fresourceManager.getResourceSetByName("GreenButtonRG"),
									"Test3", sf::Color::White, sf::Vector2f(200, 100), sf::Vector2f(100, 50));

	BasicButton* p_greenButtonC = static_cast<BasicButton*>(greenButtonC);

	p_greenButtonC->addFunctionToDoOnButtonState((getPointerToFunctionByName("closeSecondMenu")), 3);

	

	

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



	secondMenu.addMenuElement(giraffeBG, "GiraffeBackground");
	secondMenu.addMenuElement(greenButtonC, "TopGreenButtonS");
	secondMenu.deactivate();
	


	MainMenuManager.addMenu(defaultMenu, "NormalMenu", sf::Vector2f(400, 300));
	MainMenuManager.addMenu(secondMenu, "SecondMenu", sf::Vector2f(400, 300));



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


void (MainMenu::* MainMenu::getPointerToFunctionByName(std::string fname))()
{

	void(MainMenu::*tmpPointerToFunction)();

	tmpPointerToFunction = pointersToFunctions[fname];

	return tmpPointerToFunction;

}


void MainMenu::openNormalMenu()
{
	MainMenuManager.getMenuPointerByName("NormalMenu")->activate();
}


void MainMenu::closeNormalMenu()
{
	MainMenuManager.getMenuPointerByName("NormalMenu")->deactivate();
}


void MainMenu::openSecondMenu()
{
	MainMenuManager.getMenuPointerByName("SecondMenu")->activate();
}

void
MainMenu::closeSecondMenu()
{
	MainMenuManager.getMenuPointerByName("SecondMenu")->deactivate();
}