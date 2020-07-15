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
	string _lvStr[10] = { "1","2","3","4","5","6","7","8","9","10" };
	int _lv = 0;
	bool enableLGBT = 1;

	int choose = 0;
	Scene* playScene;
	DataControl _getMap;
	_getMap.readHighScore("highscore");
	do
	{

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
			_lv = 0;
			_getMap.readHighScore("highscore");
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
					_time += (chrono::duration_cast<std::chrono::microseconds>(_timeEnd - _timeBegin).count()) / 1000000;
					if (!playScene->_getPass)
						break;
					_lv++;
					delete playScene;
					clearScreen();
				}
				if (_getMap.save(0, GameMode::CAMPAIGN, CampaignScore{ _lv, _time }))
				{
					string annouce = "You've just made a new Campaign High Score!";
					setColor(Color::GRAY);
					gotoXY(MAX / 2 - annouce.length() / 2 - 5, 22);
					cout << annouce;
				}
			}
			delete playScene;
		}
	} while (choose < 4);
	return 0;
}