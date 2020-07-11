#pragma once
#include "Library.h"
#include "SnakeKun.h"
#include "Food.h"
class Scene
{
private:
	SnakeKun* _snake;
	Food* _food;
	MapData _map[MAX][MAX];
	SnakeDirection userInput, prevInput;
	void drawMap();
public:
	Scene(MapData _fileMap[MAX][MAX]);
	void run();
	friend void UserInput(void* id);
};

