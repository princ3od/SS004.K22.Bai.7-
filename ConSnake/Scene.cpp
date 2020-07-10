#include "Scene.h"
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

Scene::Scene()
{
	userInput = prevInput = SnakeDirection::RIGHT;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			_map[i][j] = MapData::NOTHING;
	_snake = new SnakeKun(_map);
	_food = new Food(_map);
}

void Scene::run()
{
	_beginthread(UserInput, 0, this);
	unsigned short int n = 100;
	bool eated = false;
	while (true)
	{
		_snake->update(n, _map, userInput, prevInput, eated);
		if (eated)
		{
			eated = false;
			_map[_food->get().x][_food->get().y] = MapData::NOTHING;
			_food = new Food(_map);
		}
		if (!_snake->isAive())
		{
			gotoXY(2, 2);
			cout << "Lose";
			break;
		}
	}
}
