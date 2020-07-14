#include "GamePlay.h"

short int GamePlay::Campaign()
{
	return 0;
}

short int GamePlay::Classic()
{
	bool back = 0;
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
	gotoXY(WIDTH / 2 + 2, HEIGHT / 2 + 4);
	setColor(Color::GREEN);
	cout << "GAME MODE FOR CHILDREN ";
	for (_chosenSection = 0; _chosenSection < 3;)
	{
		int j = _getch();
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
		case (int)Symbol::ENTER_KEY:
			clearScreen();
			return _chosenSection + 1;
			//break;
		case (int)Symbol::EXIT_KEY:
			back = 1;
			clearScreen();
			goto backToGameMode;
		}
		setColor(Color::BLUE);
		if (Menu[0] == 1)
			setColor(Color::GREEN);
		gotoXY(WIDTH / 2 - 6, HEIGHT / 2);
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
backToGameMode:
	ChooseGameMode(_gameDiff);
	return _chosenSection + 1;
}

GameMode GamePlay::ChooseGameMode(GameDifficult& _gd)
{
	_gameDiff = _gd;
	bool back = 0;
	GameMode _gm;
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
	cout << "                 [CLASSIC ]              " << endl;
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2 + 2);
	cout << "                 [ENDLESS ]              " << endl;
	for (_chosenSection = 0; _chosenSection < 3;)
	{
		int j = _getch();
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
		case (int)Symbol::ENTER_KEY:
			clearScreen();
			goto choose;
		case (int)Symbol::EXIT_KEY:
			back = 1;
			goto backToMenu;
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
		cout << "                 [CLASSIC ]              " << endl;
		setColor(Color::BLUE);
		if (Menu[2] == 1)
			setColor(Color::PURPLE);
		gotoXY(WIDTH / 2 - 4, HEIGHT / 2 + 2);
		cout << "                 [ENDLESS ]              " << endl;
		setColor(Color::BLUE);
	}
backToMenu:
	if (back)Menu::Choices(_gd, _gm, _lgbt);
choose:
	if (_chosenSection == 0)
	{
		_gm = GameMode::CAMPAIGN;
	}
	else if (_chosenSection == 1)
	{
		_gd = (GameDifficult)Classic();
		_gm = GameMode::CLASSICAL;
	}
	else if (_chosenSection == 2)
	{
		_gd = (GameDifficult)Classic();
		_gm = GameMode::ENDLESS;
	}
	return _gm;
}