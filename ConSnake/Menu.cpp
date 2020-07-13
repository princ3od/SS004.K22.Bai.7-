#include "Menu.h"
#include "GamePlay.h"

int Menu::StartMenu()
{
	int _chosenSection;
	bool Menu[4];
	Menu[0] = 1;
	Menu[1] = 0;
	Menu[2] = 0;
	setColor(Color::RED);
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2 - 2);
	cout << "                 [PLAY]              " << endl;
	setColor(Color::BLUE);
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2);
	cout << "              [SCOREBOARD]           " << endl;
	gotoXY(WIDTH / 2 - 4, HEIGHT / 2 + 2);
	cout << "                 [EXIT]              " << endl;
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
		if (Menu[2] == 1)
			setColor(Color::RED);
		gotoXY(WIDTH / 2 - 4, HEIGHT / 2 + 2);
		cout << "                 [EXIT]              " << endl;
		setColor(Color::BLUE);
	}
	return _chosenSection;
}

void Menu::Choices()
{
	short int _chosenSection = StartMenu();
	if (_chosenSection == 0)
	{
		GamePlay::ChooseGameMode();
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