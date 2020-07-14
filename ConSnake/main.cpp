#include "Library.h"
#include "Menu.h"
#include "Scene.h"
#include "Data.h"
int main()
{
	setFont();
	hideCursor();
	DataControl::readData("map1","highscore","losetext");
	Menu::StartMenu();
	cout << (char)Symbol::BOTTOM_RIGHT << (char)Symbol::LONG_BLOCK << (char)Symbol::BOTTOM_LEFT << endl;
	cout << (char)Symbol::TALL_BLOCK << " " << (char)Symbol::TALL_BLOCK << endl;
	cout << (char)Symbol::TOP_RIGHT << (char)Symbol::LONG_BLOCK << (char)Symbol::TOP_LEFT << endl;
	Scene* playScene = new Scene(Data::_map);
	playScene->run();
	return 0;
}