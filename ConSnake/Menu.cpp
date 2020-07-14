#include "Menu.h"
int Menu::StartMenu(bool& isLGBT_)
{
	clearScreen();
	short int input = (int)Symbol::UP_KEY;
	int _chosenSection = 0;
	bool Menu[5];
	Menu[0] = 1;
	Menu[1] = 0;
	Menu[2] = 0;
	Menu[3] = 0;
	Menu[4] = 0;
	setColor(Color::RED);
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2 - 4);
	cout << "                 [PLAY]              " << endl;
	setColor(Color::BLUE);
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2 - 2);
	cout << "              [SCOREBOARD]           " << endl;
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2);
	cout << "               [LGBTMODE] ";
	if (isLGBT_) {
		setColor(Color::YELLOW);
		cout << "ON           " << endl;
	}
	else {
		setColor(Color::PURPLE);
		cout << "OFF           " << endl;
	}
	setColor(Color::BLUE);
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2 + 2);
	cout << "             [CREDIT & HELP]         " << endl;
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2 + 4);
	cout << "                 [EXIT]              " << endl;
	do
	{
		input = _getch();
		clearScreen();
		switch (input)
		{
		case (int)Symbol::UP_KEY:
			Menu[_chosenSection] = 0;
			--_chosenSection;
			if (_chosenSection < 0)
				_chosenSection = 4;
			Menu[_chosenSection] = 1;
			break;
		case (int)Symbol::DOWN_KEY:
			Menu[_chosenSection] = 0;
			++_chosenSection;
			if (_chosenSection > 4)
				_chosenSection = 0;
			Menu[_chosenSection] = 1;
			break;
		case (int)Symbol::ENTER_KEY:
			if (_chosenSection == 2) {
				isLGBT_ = !isLGBT_;
			}
			else
				return _chosenSection;
			break;
		case (int)Symbol::EXIT_KEY:
			_chosenSection = 4;
			return _chosenSection;
		}
		setColor(Color::BLUE);
		if (Menu[0] == 1)
			setColor(Color::RED);
		gotoXY(WIDTH / 2 - 4, HEIGHT / 2 - 4);
		cout << "                 [PLAY]              " << endl;
		setColor(Color::BLUE);
		if (Menu[1])
			setColor(Color::RED);
		gotoXY(WIDTH / 2 - 4, HEIGHT / 2 - 2);
		cout << "              [SCOREBOARD]           " << endl;
		setColor(Color::BLUE);
		if (Menu[2])
			setColor(Color::RED);
		gotoXY(WIDTH / 2 - 4, HEIGHT / 2);
		cout << "               [LGBTMODE] ";
		if (isLGBT_) {
			setColor(Color::YELLOW);
			cout << "ON           " << endl;
		}
		else {
			setColor(Color::PURPLE);
			cout << "OFF           " << endl;
		}
		setColor(Color::BLUE);
		if (Menu[3])
			setColor(Color::RED);
		gotoXY(WIDTH / 2 - 4, HEIGHT / 2 + 2);
		cout << "             [CREDIT & HELP]         " << endl;
		setColor(Color::BLUE);
		if (Menu[4])
			setColor(Color::RED);
		gotoXY(WIDTH / 2 - 4, HEIGHT / 2 + 4);
		cout << "                 [EXIT]              " << endl;
	} while (input != (int)Symbol::EXIT_KEY);
	return _chosenSection;
}

int Menu::Choices(GameDifficult& _gd, GameMode& _gm, bool& isLGBT_)
{
	_lgbt = isLGBT_;
	short int input = (int)Symbol::ENTER_KEY;
back:
	short int _chosenSection = StartMenu(isLGBT_);
	if (_chosenSection == 0)
	{
		_gm = GamePlay::ChooseGameMode(_gd);
	}
	else if (_chosenSection == 1)
	{
		do
		{
			input = _getch();
		} while (input != (int)Symbol::EXIT_KEY);
		goto back;
	}
	else if (_chosenSection == 3) {





		setColor(Color::GREEN);
		for (int j = HEIGHT / 2 - 10; j < HEIGHT / 2 + 5; j++)
		{
			gotoXY(WIDTH - 21, j);
			cout << (char)Symbol::TALL_BLOCK;
			gotoXY(WIDTH + 1, j);
			cout << (char)Symbol::TALL_BLOCK;
		}
		for (int i = WIDTH - 20; i < WIDTH + 1; i++)
		{
			gotoXY(i, HEIGHT / 2 + 5);
			cout << (char)Symbol::LONG_BLOCK;
			gotoXY(i, HEIGHT / 2 - 11);
			cout << (char)Symbol::LONG_BLOCK;
		}
		gotoXY(WIDTH - 21, HEIGHT / 2 + 5);
		cout << (char)Symbol::TOP_RIGHT;
		gotoXY(WIDTH - 21, HEIGHT / 2 - 11);
		cout << (char)Symbol::BOTTOM_RIGHT;
		gotoXY(WIDTH + 1, HEIGHT / 2 + 5);
		cout << (char)Symbol::TOP_LEFT;
		gotoXY(WIDTH + 1, HEIGHT / 2 - 11);
		cout << (char)Symbol::BOTTOM_LEFT;

		do
		{
			input = _getch();
		} while (input != (int)Symbol::EXIT_KEY);
		goto back;

	}
	else if (_chosenSection == 4)
	{
		setColor(Color::RED); //man hình ket thuc
		gotoXY(WIDTH / 2 - 2, HEIGHT / 2 - 2); cout << "-------------------------" << endl;
		gotoXY(WIDTH / 2 - 7, HEIGHT / 2 - 1); cout << "     |    GOOD BYE! (^O^)/   |" << endl;
		gotoXY(WIDTH / 2 - 2, HEIGHT / 2); cout << "-------------------------" << endl;
		gotoXY(WIDTH / 2 - 2, HEIGHT / 2 + 5);
		exit(1);
	}
	return _chosenSection;
}
