#include "Menu.h"
int Menu::StartMenu(bool& isLGBT_)
{
	int _chosenSection;
	bool Menu[5];
	Menu[0] = 1;
	Menu[1] = 0;
	Menu[2] = 0;
	Menu[3] = 0;
	Menu[4] = 0;
	setColor(Color::RED);
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2 - 2);
	cout << "                 [PLAY]              " << endl;
	setColor(Color::BLUE);
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2);
	cout << "              [SCOREBOARD]           " << endl;
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2 + 2);
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
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2 + 4);
	cout << "                 [CREDIT]              " << endl;
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2 + 6);
	cout << "                 [EXIT]              " << endl;
	for (_chosenSection = 0; _chosenSection < 5;)
	{
		int j = _getch();
		clearScreen();
		switch (j)
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
		case '\r':
			if (_chosenSection == 4)
			{
				setColor(Color::RED); //man hình ket thuc
				gotoXY(WIDTH / 2 - 2, HEIGHT / 2 - 2); cout << "-------------------------" << endl;
				gotoXY(WIDTH / 2 - 7, HEIGHT / 2 - 1); cout << "     |    GOOD BYE! (^O^)/   |" << endl;
				gotoXY(WIDTH / 2 - 2, HEIGHT / 2); cout << "-------------------------" << endl;
				gotoXY(WIDTH / 2 - 2, HEIGHT / 2 + 5);
				_endthread();
			}
			if (_chosenSection == 3) {
				setColor(Color::GREEN);
				gotoXY(WIDTH / 2 - 2, HEIGHT / 2 - 3); cout << "-------------------------" << endl;
				gotoXY(WIDTH / 2 - 7, HEIGHT / 2 - 2); cout << "     |    BAI TAP SO 7 SS004.K22   |" << endl;
				gotoXY(WIDTH / 2 - 5, HEIGHT / 2 - 1); cout << "Dang Hai Thinh - 19520976" << endl;
				gotoXY(WIDTH / 2 - 5, HEIGHT / 2); cout << "Le Thanh Luan - 19520702" << endl;
				gotoXY(WIDTH / 2 - 5, HEIGHT / 2 + 1); cout << "Duong Binh Trong - 19521056" << endl;
				gotoXY(WIDTH / 2 - 2, HEIGHT / 2 + 2); cout << "-------------------------" << endl;
			}
			if (_chosenSection == 2) {
				isLGBT_ = !isLGBT_;
			}
			else
				return _chosenSection;
			break;
		}
		setColor(Color::BLUE);
		if (Menu[0] == 1)
			setColor(Color::RED);
		gotoXY(WIDTH / 2 - 4, HEIGHT / 2 - 2);
		cout << "                 [PLAY]              " << endl;
		setColor(Color::BLUE);
		if (Menu[1] == 1)
			setColor(Color::RED);
		gotoXY(WIDTH / 2 - 4, HEIGHT / 2);
		cout << "              [SCOREBOARD]           " << endl;
		setColor(Color::BLUE);
		if (Menu[2])
			setColor(Color::RED);
		gotoXY(WIDTH / 2 - 4, HEIGHT / 2 + 2);
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
		if (Menu[3]) {
			setColor(Color::RED);
		}
		gotoXY(WIDTH / 2 - 4, HEIGHT / 2 + 4);
		cout << "                 [CREDIT]              " << endl;
		if (Menu[4] == 1)
			setColor(Color::RED);
		gotoXY(WIDTH / 2 - 4, HEIGHT / 2 + 4);
		cout << "                 [EXIT]              " << endl;
	}
	return _chosenSection;
}

void Menu::Choices(short int &level, GameDifficult&_gd, GameMode& _gm, unsigned short int _unlock,bool& isLGBT_)
{
	short int _chosenSection = StartMenu(isLGBT_);
	if (_chosenSection == 0)
	{
		_gm = GamePlay::ChooseGameMode(level,_gd,_unlock);
	}
	else if (_chosenSection == 1)
	{

	}
	else if (_chosenSection == 2)
	{
		setColor(Color::RED); //man hình ket thuc
		gotoXY(WIDTH / 2 - 2, HEIGHT / 2 - 2); cout << "-------------------------" << endl;
		gotoXY(WIDTH / 2 - 7, HEIGHT / 2 - 1); cout << "     |    GOOD BYE! (^O^)/   |" << endl;
		gotoXY(WIDTH / 2 - 2, HEIGHT / 2); cout << "-------------------------" << endl;
		gotoXY(WIDTH / 2 - 2, HEIGHT / 2 + 5);
		_endthread();
	}
}
