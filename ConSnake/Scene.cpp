#include "Scene.h"
#include "Data.h"
void UserInput(void* id)
{
	Scene* scene = (Scene*)id;
	do
	{
		int c = _getch();
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
	return;
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
}

Scene::Scene(MapData _fileMap[MAX][MAX])
{
	userInput = prevInput = SnakeDirection::RIGHT;
	for (int j = 0; j < MAX; j++)
		for (int i = 0; i < MAX; i++)
			_map[i][j] = _fileMap[i][j];
	drawMap();
	_snake = new SnakeKun(_map, GameDifficult::HARD);
	_food = new Food(_map);
}

void Scene::run()
{
	Data _data;
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
			cout << "Lose";
			_data.save(_snake->_score);
			break;
		}
	}
}