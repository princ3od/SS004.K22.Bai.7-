#include "Library.h"
#include "Scene.h"

int main()
{
	setFont();
	hideCursor();
	//cout << Menu::StartMenu();
	cout << (char)Symbol::BOTTOM_RIGHT << (char)Symbol::LONG_BLOCK << (char)Symbol::BOTTOM_LEFT << endl;
	cout << (char)Symbol::TALL_BLOCK << " " << (char)Symbol::TALL_BLOCK << endl;
	cout << (char)Symbol::TOP_RIGHT << (char)Symbol::LONG_BLOCK << (char)Symbol::TOP_LEFT << endl;
	Scene* playScene = new Scene();
	playScene->run();
	return 0;
}