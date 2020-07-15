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
	char _lvStr[10] = { '1','2','3','4','5','6','7','8','9','10' };
	int _lv = 0;
	bool enableLGBT = 1;

	int choose = 0;
	Scene* playScene;
	do
	{
		DataControl _getMap;
		choose = Menu::Choices(_gameDifficult, _gameMode, enableLGBT);
		switch (_gameMode)
		{
		case GameMode::CLASSICAL:
			_getMap.readMap("map1");
			break;
		case GameMode::ENDLESS:
			_getMap.readMap("defaultmap");
			break;
		default:
			break;
		}

		if (choose == 0)
		{
			if (_gameMode != GameMode::CAMPAIGN)
			{
				playScene = new Scene(_getMap._map, _gameMode, _gameDifficult, enableLGBT);
				playScene->run();
			}
			else
			{
				while (true)
				{
					_getMap.readMap("map" + _lvStr[_lv]);
					playScene = new Scene(_getMap._map, _gameMode, _gameDifficult, enableLGBT, _lv + 1);
					playScene->run();
					if (!playScene->_getPass)
						break;
				}
			}
			delete playScene;
		}
	} while (choose < 4);
	return 0;
}