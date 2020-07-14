#include "Scene.h"
#include "Data.h"

void UserInput(void* id)
{
	Scene* scene = (Scene*)id;
	int c = 2;
	do
	{
		c = _getch();
		switch (c)
		{
		case (int)Symbol::UP_KEY: case 'w': case'W':
			scene->userInput = SnakeDirection::UP;
			break;
		case (int)Symbol::DOWN_KEY: case 's': case'S':
			scene->userInput = SnakeDirection::DOWN;
			break;
		case (int)Symbol::RIGHT_KEY: case 'd': case'D':
			scene->userInput = SnakeDirection::RIGHT;
			break;
		case (int)Symbol::LEFT_KEY: case 'a': case'A':
			scene->userInput = SnakeDirection::LEFT;
			break;
		case (int)Symbol::EXIT_KEY:
			scene->userInput = SnakeDirection::EXIT;
			break;
		}
	} while (scene->userInput != SnakeDirection::EXIT);
	_endthread();
}

void Scene::drawMap()
{
	setColor(Color::WHITE);
	for (int j = 0; j < HEIGHT + 1; j++)
		for (int i = 0; i < WIDTH + 1; i++)
			if (_map[i][j] == MapData::WALL)
			{
				gotoXY(i, j);
				if (j == 0)
					cout << (char)Symbol::LONG_TOP_BLOCK;
				else if (j == HEIGHT)
					cout << (char)Symbol::LONG_BOTTOM_BLOCK;
				else if (i == 0)
					cout << (char)Symbol::LONG_THIN_RIGHT_BLOCK;
				else if (i == WIDTH)
					cout << (char)Symbol::LONG_THIN_LEFT_BLOCK;
				else
					cout << char(Symbol::LONG_BIG_BLOCK);
			}
	setColor(Color::GRAY);
	for (int j = 0; j < HEIGHT + 1; j++)
	{
		gotoXY(WIDTH + 1, j);
		cout << (char)Symbol::TALL_BLOCK;
	}
	for (int i = 0; i < WIDTH + 1; i++)
	{
		gotoXY(i, HEIGHT + 1);
		cout << (char)Symbol::LONG_BLOCK;
	}
	gotoXY(WIDTH + 1, HEIGHT + 1);
	cout << (char)Symbol::TOP_LEFT;

}

Scene::Scene(MapData _fileMap[MAX][MAX], GameMode gameMode, short int level, GameDifficult gameDiff, bool& _islgbt)
{
	_gd = gameDiff;
	_gm = gameMode;
	_lv = level;
	userInput = prevInput = SnakeDirection::RIGHT;
	for (int j = 0; j < MAX; j++)
		for (int i = 0; i < MAX; i++)
			_map[i][j] = _fileMap[i][j];
	drawMap();
	_snake = new SnakeKun(_map, _gd, _islgbt);
	_food = new Food(_map);
}

void Scene::run()
{
	_beginthread(UserInput, 0, this);
	bool eated = false;
	while (true)
	{
		_snake->update(_map, userInput, prevInput, eated);
		if (eated)
		{
			eated = false;
			_map[_food->get().x][_food->get().y] = MapData::NOTHING;
			delete _food;
			_food = new Food(_map);
		}
		if (!_snake->isAive())
		{
			gotoXY(2, 2);
			cout << "Press ESC key twice to back to main menu.";
			_getch();
			DataControl::save(_snake->_score, GameMode::CLASSICAL);
			delete _snake;
			break;
		}
	}
}
