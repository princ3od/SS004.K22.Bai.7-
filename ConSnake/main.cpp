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
				int _time = 0;
				chrono::steady_clock::time_point _timeBegin;
				chrono::steady_clock::time_point _timeEnd;
				while (true)
				{
					_getMap.readMap("map" + _lvStr[_lv]);
					playScene = new Scene(_getMap._map, _gameMode, GameDifficult::NORMAL, enableLGBT, _lv + 1);
					_timeBegin = chrono::steady_clock::now();
					playScene->run();
					_timeEnd = chrono::steady_clock::now();
					_time += (chrono::duration_cast<std::chrono::microseconds>(_timeBegin - _timeEnd).count()) / 1000000;
					if (!playScene->_getPass)
						break;
					_lv++;
					delete playScene;
					_getMap.save(0, _gameMode, CampaignScore{ _lv, _time });
					clearScreen();
				}
			}
			delete playScene;
		}
	} while (choose < 4);
	return 0;
}