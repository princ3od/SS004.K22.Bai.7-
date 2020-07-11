#include "Library.h"
#include "Scene.h"
#include "Data.h"
int main()
{
	setFont();
	hideCursor();
	Data _data;
	cout << _data.readData();
	//cout << Menu::StartMenu();
	cout << (char)Symbol::BOTTOM_RIGHT << (char)Symbol::LONG_BLOCK << (char)Symbol::BOTTOM_LEFT << endl;
	cout << (char)Symbol::TALL_BLOCK << " " << (char)Symbol::TALL_BLOCK << endl;
	cout << (char)Symbol::TOP_RIGHT << (char)Symbol::LONG_BLOCK << (char)Symbol::TOP_LEFT << endl;
	Scene* playScene = new Scene(_data._map);
	playScene->run();
	return 0;
}