#include "GamePlay.h"

short int GamePlay::Campaign()
{
	int _chosenSection;
	unsigned short int i;
	bool Menu[11] = { 1,0,0,0,0,0,0,0,0,0 };
	unsigned short int _unlock = 0;
	setColor(Color::RED);
	gotoXY(WIDTH / 2 - 4, 5);
	cout << "                 [Level 1]              " << endl;
	for (i = 1; i < 11; i++)
	{
		if (_unlock >= i)
		{
			setColor(Color::BLUE);
		}
		else setColor(Color::GRAY);
		gotoXY(WIDTH / 2 - 4, 5+ i*2);
		cout << "                 [Level "<<i+1<<"]              " << endl;
	}
	for (_chosenSection = 0; _chosenSection < 11;)
	{
		int j = _getch();
		clearScreen();
		switch (j)
		{
		case (int)Symbol::UP_KEY:
			Menu[_chosenSection] = 0;
			--_chosenSection;
			if (_chosenSection < 0)
				_chosenSection = 10;
			Menu[_chosenSection] = 1;
			break;
		case (int)Symbol::DOWN_KEY:
			if (_chosenSection + 1 > _unlock)
				break;
			else {
				Menu[_chosenSection] = 0;
				++_chosenSection;
				if (_chosenSection > 10)
					_chosenSection = 0;
				Menu[_chosenSection] = 1;
				break;
			}
		case '\r':
			_level = _chosenSection;
			return _level;
		}

		for (i = 0; i < 11; i++)
		{
			if (_unlock >= i)
			{
			setColor(Color::BLUE);
			}
			else setColor(Color::GRAY);
		if (_chosenSection == i)
		setColor(Color::RED);
		gotoXY(WIDTH / 2 - 4, 5+ i*2);
		cout << "                 [Level "<<i+1<<"]              " << endl;
		}
	}
	return _level;
}

short int GamePlay::Classic()
{
	short int _chosenSection;
	bool Menu[4];
	Menu[0] = 1;
	Menu[1] = 0;
	Menu[2] = 0;
	setColor(Color::GREEN);
	gotoXY(WIDTH / 2 - 6, HEIGHT / 2);
	cout << "[EASY]           ";
	setColor(Color::BLUE);
	cout << "[NORMAL]          ";
	cout << "[HARD]           ";
	gotoXY(WIDTH / 2+2, HEIGHT / 2 + 4);
	setColor(Color::GREEN);
	cout << "GAME MODE FOR CHILDREN ";
	for (_chosenSection = 0; _chosenSection < 3;)
	{
		int j = _getch();
		clearScreen();
		switch (j)
		{
		case (int)Symbol::LEFT_KEY:
			Menu[_chosenSection] = 0;
			--_chosenSection;
			if (_chosenSection < 0)
				_chosenSection = 2;
			Menu[_chosenSection] = 1;
			break;
		case (int)Symbol::RIGHT_KEY:
			Menu[_chosenSection] = 0;
			++_chosenSection;
			if (_chosenSection > 2)
				_chosenSection = 0;
			Menu[_chosenSection] = 1;
			break;
		case '\r':
			return _chosenSection;
		}
		setColor(Color::BLUE);
		if (Menu[0] == 1)
		setColor(Color::GREEN);
		gotoXY(WIDTH / 2 - 6 , HEIGHT / 2);
		cout << "[EASY]           ";
		setColor(Color::BLUE);
		if (Menu[1] == 1)
		setColor(Color::YELLOW);
		cout << "[NORMAL]          ";
		setColor(Color::BLUE);
		if (Menu[2] == 1)
		setColor(Color::RED);
		cout << "[HARD]           ";

	gotoXY(WIDTH / 2 + 2, HEIGHT / 2 + 4); //xuat giai thich gamemode
	if (Menu[0] == 1) {
		setColor(Color::GREEN);
		cout << "GAME MODE FOR CHILDREN ";
	}
	if (Menu[1] == 1) {
		setColor(Color::YELLOW);
		cout << "GAME MODE FOR NORMIES ";
	}
	if (Menu[2] == 1) {
			setColor(Color::RED);
			cout << "GAME MODE FOR MADLADS ";
		}

	}
	return _chosenSection;
}

short int GamePlay::ChooseGameMode()
{
	int _chosenSection;
	bool Menu[4];
	Menu[0] = 1;
	Menu[1] = 0;
	Menu[2] = 0;
	setColor(Color::RED);
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2 - 2);
	cout << "                 [CAMPAIGN]              " << endl;
	setColor(Color::BLUE);
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2);
	cout << "                 [CLASSIC]               " << endl;
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2 + 2);
	cout << "                 [ENDLESS]               " << endl;
	for (_chosenSection = 0; _chosenSection < 3;)
	{
		int j = _getch();
		clearScreen();
		switch (j)
		{
		case (int)Symbol::UP_KEY:
			Menu[_chosenSection] = 0;
			--_chosenSection;
			if (_chosenSection < 0)
				_chosenSection = 2;
			Menu[_chosenSection] = 1;
			break;
		case (int)Symbol::DOWN_KEY:
			Menu[_chosenSection] = 0;
			++_chosenSection;
			if (_chosenSection > 2)
				_chosenSection = 0;
			Menu[_chosenSection] = 1;
			break;
		case '\r':
			 goto choose;
		}
		setColor(Color::BLUE);
		if (Menu[0] == 1)
			setColor(Color::RED);
		gotoXY(WIDTH / 2 - 4, HEIGHT / 2 - 2);
		cout << "                 [CAMPAIGN]              " << endl;
		setColor(Color::BLUE);
		if (Menu[1] == 1)
			setColor(Color::WHITE);
		gotoXY(WIDTH / 2 - 4, HEIGHT / 2);
		cout << "                 [CLASSIC]              " << endl;
		setColor(Color::BLUE);
		if (Menu[2] == 1)
			setColor(Color::PURPLE);
		gotoXY(WIDTH / 2 - 4, HEIGHT / 2 + 2);
		cout << "                 [ENDLESS]              " << endl;
		setColor(Color::BLUE);
	}

	choose:
	if (_chosenSection == 0)
	{
		_level = Campaign();
		_gameDifficult = GameDifficult::NORMAL;
	}
	else if (_chosenSection == 1)
	{
		_level = 11;
		_gameDifficult = (GameDifficult)Classic();
	}
	else if (_chosenSection == 2)
	{
		_level = 12;
		_gameDifficult = (GameDifficult)Classic();
	}
	return _level;
}