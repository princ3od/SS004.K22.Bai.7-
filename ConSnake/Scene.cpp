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
	setColor(Color::GRAY);
	string instruc = "*one more";
	gotoXY(MAX / 2, HEIGHT / 2 + 3);
	cout << instruc;
	_endthread();
}

void Scene::drawMap()
{
	setColor(Color::GRAY);
	for (int j = 0; j < HEIGHT + 1; j++)
	{
		gotoXY(WIDTH + 1, j);
		cout << (char)177;
	}
	for (int i = 0; i < WIDTH + 1; i++)
	{
		gotoXY(i, HEIGHT + 1);
		cout << (char)177;
	}
	gotoXY(WIDTH + 1, HEIGHT + 1);
	cout << (char)177;
	setColor(Color::WHITE);
	for (int j = 0; j < HEIGHT + 1; j++)
		for (int i = 0; i < WIDTH + 1; i++)
			if (_map[i][j] == MapData::WALL)
			{
				gotoXY(i, j);
				cout << char(Symbol::LONG_BIG_BLOCK);
			}
	setColor(Color::GRAY);
	gotoXY(86, 3);
	cout << "GAME MODE: ";
	switch (_gm)
	{
	case GameMode::CLASSICAL:
		setColor(Color::WHITE);
		cout << "Classical";
		break;
	case GameMode::CAMPAIGN:
		setColor(Color::RED);
		cout << "Campaign";
		break;
	case GameMode::ENDLESS:
		setColor(Color::PURPLE);
		cout << "Endless";
		break;
	default:
		break;
	}
	setColor(Color::GRAY);
	gotoXY(86, 4);
	cout << "GAME DIFFICULTY: ";
	switch (_gd)
	{
	case GameDifficult::EASY:
		setColor(Color::GREEN);
		cout << "Easy";
		break;
	case GameDifficult::NORMAL:
		setColor(Color::YELLOW);
		cout << "Normal";
		break;
	case GameDifficult::HARD:
		setColor(Color::RED);
		cout << "Hard";
		break;
	default:
		break;
	}
	setColor(Color::GRAY);
	gotoXY(86, 6);
	if (_gm != GameMode::CAMPAIGN)
		cout << "SCORE: ";
	else
		cout << "LEVEL: " << _lv;

	for (int x = 83; x <= MAX + 3; x++)
	{
		gotoXY(x, 8);
		cout << "-";
	}

	gotoXY(86, 10);
	cout << "DEBUG INFORMATION";
	gotoXY(86, 12);
	cout << "Snake length: 4 + ";
	gotoXY(86, 13);
	cout << "Snake location: ";
	gotoXY(86, 14);
	cout << "Snake speed: ";
	gotoXY(86, 15);
	cout << "Food location: ";

	for (int x = 83; x <= MAX + 3; x++)
	{
		gotoXY(x, 17);
		cout << "-";
	}

	gotoXY(90, 19);
	cout << "SNAKE GAME 1.0";
	gotoXY(85, 21);
	cout << "Final Term Project";
	gotoXY(85, 22);
	cout << "[Professional Skills (SS004.K22)]";
	gotoXY(85, 23);
	cout << "by: - Duong Binh Trong (19521056)";
	gotoXY(89, 24);
	cout << "- Dang Hai Thinh (19520702)";
	gotoXY(89, 25);
	cout << "- Le Thanh Luan (19520976)";
}

void Scene::endGame()
{
	DataControl _data;
	_data.readLoseText("losetext");
	_data.readHighScore("highscore");
	clearScreen();
	int i = rand() % 30;
	setColor(Color::WHITE);
	gotoXY(MAX / 2 - _data._loseText[i].length() / 2 + 4, HEIGHT / 2 - 2);
	cout << _data._loseText[i];
	gotoXY(MAX / 2 - 2, HEIGHT / 2);
	setColor(Color::GRAY);
	cout << "Your score: ";
	bool _new;
	_new = _data.save(_snake->_score, _gm);
	if (_new)
	{
		setColor(Color::GREEN);
		cout << _snake->_score;
		setColor(Color::ORANGE);
		gotoXY(MAX / 2 - 3, HEIGHT / 2 + 1);
		cout << "New High Score!";
	}
	else
	{
		setColor(Color::YELLOW);
		cout << _snake->_score;
	}
	setColor(Color::RED);
	string instruc = "Press [ESC] key to return to main menu.";
	gotoXY(MAX / 2 - instruc.length() / 2 + 5, HEIGHT / 2 + 2);
	cout << instruc;
}

void Scene::endCampaign()
{
	clearScreen();
	DataControl _data;
	_data.readLoseText("losetext");
	int i = rand() % 30;
	setColor(Color::WHITE);
	gotoXY(MAX / 2 - _data._loseText[i].length() / 2 + 4, HEIGHT / 2 - 2);
	cout << _data._loseText[i];
	gotoXY(MAX / 2 - 2, HEIGHT / 2);
	setColor(Color::GRAY);
	cout << "Your level pass: ";
	bool _new;
	_new = _data.save(_snake->_score, _gm);
	if (_new)
	{
		setColor(Color::GREEN);
		cout << _lv - 1;
		setColor(Color::ORANGE);
		gotoXY(MAX / 2 - 3, HEIGHT / 2 + 1);
		cout << "New High Score!";
	}
	else
	{
		setColor(Color::YELLOW);
		cout << _lv - 1;
	}
	setColor(Color::RED);
	string instruc = "Press [ESC] key to return to main menu.";
	gotoXY(MAX / 2 - instruc.length() / 2 + 5, HEIGHT / 2 + 2);
	cout << instruc;
}

Scene::Scene(MapData _fileMap[MAX][MAX], GameMode gameMode, GameDifficult gameDiff, bool& _islgbt, int lv)
{
	_lv = lv;
	_gd = gameDiff;
	_gm = gameMode;
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
	if (_lv == 1 || _gm != GameMode::CAMPAIGN)
		_beginthread(UserInput, 0, this);
	bool eated = false;
	while (_snake->isAive())
	{
		if (_gm != GameMode::CAMPAIGN)
		{
			gotoXY(93, 6);
			cout << _snake->_score;
		}
		setColor(Color::WHITE);
		gotoXY(104, 12);
		cout << _snake->getLength() - 4;
		gotoXY(102, 13);
		cout << "(" << _snake->getHead().x << "," << _snake->getHead().y << ")  ";
		gotoXY(99, 14);
		cout << _snake->getSpeed() - 100;
		gotoXY(101, 15);
		cout << "(" << _food->get().x << "," << _food->get().y << ")  ";
		_snake->update(_map, userInput, prevInput, eated);
		if (eated)
		{
			eated = false;
			_map[_food->get().x][_food->get().y] = MapData::NOTHING;
			delete _food;
			_food = new Food(_map);
		}
		if ( _gm == GameMode::CAMPAIGN && _snake->getLength() == 6)//_lv * (25 - _lv * 2))
		{
			_getPass = true;
			break;
		}
	}
	if (!_snake->isAive() && _gm != GameMode::CAMPAIGN)
	{
		endGame();
		_getch();
	}
	else if (!_snake->isAive() && _gm == GameMode::CAMPAIGN)
	{
		endCampaign();
		_getch();
	}
	delete _snake;
	if (!eated)
		delete _food;
}
