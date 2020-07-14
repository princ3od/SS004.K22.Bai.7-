#include "Library.h"
#include "Menu.h"
#include "Data.h"
#include "Scene.h"
int main()
{
	setFont();
	hideCursor();

	GameMode _gameMode;
	GameDifficult _gameDifficult;
	short int _lv;
	bool enableLGBT;
	int choose = 0;
	DataControl::readHighScore("highscore");
	Scene* playScene;
	do
	{
		DataControl _getMap;
		_getMap.readMap("map9");
		choose = Menu::Choices(_lv, _gameDifficult, _gameMode, enableLGBT);
		if (choose == 0)
		{
			playScene = new Scene(_getMap._map,_gameMode, _lv, _gameDifficult, enableLGBT);
			playScene->run();
			delete playScene;
		}
	} while (choose < 4);
	return 0;
}