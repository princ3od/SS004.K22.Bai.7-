#pragma once
#include "Library.h"
#include "SnakeKun.h"
#include "Food.h"
class Scene
{
private:
	GameMode _gm;
	GameDifficult _gd;
	SnakeKun* _snake;
	Food* _food;
	MapData _map[MAX][MAX];
	SnakeDirection userInput, prevInput;
	int _lv;
	void drawMap();
	void endGame();
	void endCampaign();
	void passCampaign();
public:
	bool _getPass = false;
	Scene(MapData _fileMap[MAX][MAX], GameMode _gd, GameDifficult gameDiff, bool& _islgbt, int lv = 0);
	void run();
	friend void UserInput(void* id);
};

