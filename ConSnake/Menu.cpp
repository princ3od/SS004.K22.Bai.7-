#include "Menu.h"
int Menu::StartMenu(bool& isLGBT_)
{
	clearScreen();
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

int Menu::Choices(short int& level, GameDifficult& _gd, GameMode& _gm, bool& isLGBT_)
{
	short int _chosenSection = StartMenu(isLGBT_);
	if (_chosenSection == 0)
	{
		_gm = GamePlay::ChooseGameMode(level, _gd);
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
		exit(1);
	}
	return _chosenSection;
}


//GameMode Menu::GamemodeMenu()
//{
//	bool Mode[5]; Mode[0] = 0; Mode[1] = 0; Mode[2] = 0; Mode[3] = 0;
//	setColor(Color::GREEN);
//	gotoXY(WIDTH / 2 - 8, HEIGHT / 2 - 2);
//	cout << "[EASY]";
//	setColor(Color::BLUE);
//	cout << "         [NORMAL]";
//	cout << "         [HARD]";
//	cout << "         [SPECIAL]";
//	gotoXY(WIDTH / 2, HEIGHT / 2 + 2);
//	setColor(Color::GREEN);
//	cout << "GAME MODE FOR CHILDREN ";
//	GameMode gameMode;
//	for (int i = 0; i < 4;)
//	{
//		int j = _getch();
//		clearScreen();
//		switch (j)
//		{
//		case 75:
//			Mode[i] = 0;
//			--i;
//			if (i < 0) { i = 3; }
//			Mode[i] = 1;
//			break;
//		case 77:
//			Mode[i] = 0;
//			++i;
//			if (i > 3) { i = 0; }
//			Mode[i] = 1;
//			break;
//		case '\r':
//			if (i == 0) { gameMode = GameMode::EASY; i = 4; break; }
//			else if (i == 1) { gameMode = GameMode::NORMAL; i = 4; break; }
//			else if (i == 2) { gameMode = GameMode::HARD; i = 4; break; }
//			else { gameMode = GameMode::SPECIAL; i = 4; break; }
//		}
//		if (i == 4)break;
//		gotoXY(WIDTH / 2 - 8, HEIGHT / 2 - 2); //xuat lua chon gamemode
//		setColor(Color::BLUE);
//		if (Mode[0] == 1) { setColor(Color::GREEN); }
//		cout << "[EASY]";
//		setColor(Color::BLUE);
//		if (Mode[1] == 1) { setColor(Color::YELLOW); }
//		cout << "         [NORMAL]";
//		setColor(Color::BLUE);
//		if (Mode[2] == 1) { setColor(Color::RED); }
//		cout << "         [HARD]";
//		setColor(Color::BLUE);
//		if (Mode[3] == 1) { setColor(Color::PURPLE); }
//		cout << "         [SPECIAL]";
//
//		gotoXY(WIDTH / 2, HEIGHT / 2 + 2); //xuat giai thich gamemode
//		if (Mode[0] == 1) {
//			setColor(Color::GREEN);
//			cout << "GAME MODE FOR CHILDREN ";
//		}
//		if (Mode[1] == 1) {
//			setColor(Color::YELLOW);
//			cout << "GAME MODE FOR NORMIES ";
//		}
//		if (Mode[2] == 1) {
//			setColor(Color::RED);
//			cout << "GAME MODE FOR MADLADS ";
//		}
//		if (Mode[3] == 1) {
//			setColor(Color::PURPLE);
//			cout << "EVERYTIME SNAKE EATS, SNAKE GET FASTER ";
//		}
//	}
//	return gameMode;
//}