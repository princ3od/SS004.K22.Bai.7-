#include "Menu.h"
#include "Data.h"
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
			clearScreen();
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
back:
	_lgbt = isLGBT_;
	short int i = 0;
	Color _c[6] = { Color::RED,Color::ORANGE,Color::YELLOW,Color::GREEN,Color::BLUE,Color::PURPLE };
	short int _curColor = 0;
	short int input = (int)Symbol::ENTER_KEY;
	short int _chosenSection = StartMenu(isLGBT_);
	if (_chosenSection == 0)
	{
		_gm = GamePlay::ChooseGameMode(_gd);
	}
	else if (_chosenSection == 1)
	{
		DataControl _data;
		_data.readHighScore("highscore");

		setColor(Color::WHITE);
		gotoXY(MAX / 2 - 7, HEIGHT / 2 - 6);
		cout << "[CLASSICAL MODE]";
		for (int i = 0; i < 10; i++)
		{
			gotoXY(MAX / 2 - 3, HEIGHT / 2 - 6 + i + 1);
			if (i < 3)
				setColor(Color::YELLOW);
			else
				setColor(Color::GRAY);
			if(i == 9)
			{
				cout << i + 1 << ".  ";
			}else
			cout << i + 1 << ".   ";
			cout << _data._classicalHighScore[i];


			//Endless
			gotoXY(MAX / 2 + 8 , HEIGHT / 2 - 6);
			setColor(Color::PURPLE);
			cout << "[ENDLESS MODE]";
			gotoXY(MAX / 2 + 12, HEIGHT / 2 - 6 + i + 1);
			if (i < 3)
				setColor(Color::YELLOW);
			else
				setColor(Color::GRAY);
			if (i == 9)
			{
				cout << i + 1 << ".  ";
			}
			else
			cout << i + 1 << ".   ";
			cout << _data._endlessHighScore[i];


			//Campaign
			gotoXY(MAX / 2 - 48, HEIGHT / 2 - 6);
			setColor(Color::RED);
			cout << "[CAMPAIGN MODE]";
			gotoXY(MAX / 2 - 49 , HEIGHT / 2 - 6 + i + 1);
			if (i < 3)
				setColor(Color::YELLOW);
			else
				setColor(Color::GRAY);
			if (i == 9)
			{
				cout << i + 1 << ".  ";
			}
			else
				cout << i + 1 << ".   ";
			cout << _data._campaignHighScore[i]._lv;
			gotoXY(MAX / 2 - 39, HEIGHT / 2 - 6 + i + 1);
			cout << "TIME:";
			cout << _data._campaignHighScore[i]._time;
			cout << "s";

		}
		do
		{
				setColor(_c[_curColor]);
				_curColor++;
				_curColor = (_curColor > 5) ? 0 : _curColor;
				gotoXY(1, HEIGHT / 2 - 10);
				cout << "---------------------------------------------------[HIGH SCORE]--------------------------------------------------";
				gotoXY(2, HEIGHT - 6);
				cout << "----------------------------------------------------------------------------------------------------------------";
				for (i = HEIGHT / 2 - 10; i < HEIGHT - 5; i++)
				{
					gotoXY(0, i);
					cout << "||";
					gotoXY(MAX, i);
					cout << "||";
				}
				Sleep(100);
		} while (!_kbhit());
		input = _getch();
		goto back;
	}
	else if (_chosenSection == 3) {
		// credit
		setColor(Color::ORANGE);   gotoXY(6, 10); cout << "BAI THU HOACH SS004.K2.7";
		setColor(Color::ORANGE);   gotoXY(6, 11); cout << "Mon:"; setColor(Color::GREEN); cout << " Ky nang nghe nghiep(Professional Skill)";
		setColor(Color::ORANGE);   gotoXY(6, 12); cout << "GV:";  setColor(Color::GREEN); cout << "  TS.Nguyen Van Toan";
		setColor(Color::ORANGE);   gotoXY(6, 15); cout << "Nhom:";
		setColor(Color::GREEN);    gotoXY(6, 16);cout << "- Duong Binh Trong - 19521056";
								   gotoXY(6, 17);cout << "- Dang Hai Thinh - 19521056";
								   gotoXY(6, 18);cout << "- Le Thanh Luan - 19520702";

		
		//help
		setColor(Color::GRAY);
		for (int j = HEIGHT / 2 - 10; j < HEIGHT / 2 + 10; j++)
		{
			gotoXY(WIDTH - 17, j);
			cout << (char)Symbol::TALL_BLOCK;
			gotoXY(WIDTH + 13, j);
			cout << (char)Symbol::TALL_BLOCK;
		}
		for (int i = WIDTH - 16; i < WIDTH + 13; i++)
		{
			gotoXY(i, HEIGHT / 2 + 10);
			cout << (char)Symbol::LONG_BLOCK;
			gotoXY(i, HEIGHT / 2 - 11);
			cout << (char)Symbol::LONG_BLOCK;
		}
		gotoXY(WIDTH - 17, HEIGHT / 2 + 10);
		cout << (char)Symbol::TOP_RIGHT;
		gotoXY(WIDTH - 17, HEIGHT / 2 - 11);
		cout << (char)Symbol::BOTTOM_RIGHT;
		gotoXY(WIDTH + 13, HEIGHT / 2 + 10);
		cout << (char)Symbol::TOP_LEFT;
		gotoXY(WIDTH + 13, HEIGHT / 2 - 11);
		cout << (char)Symbol::BOTTOM_LEFT;

		setColor(Color::YELLOW);
		gotoXY(WIDTH - 15, HEIGHT / 2 - 9);		cout << "||   ||  ||===  ||    ||==\\\\";
		gotoXY(WIDTH - 15, HEIGHT / 2 - 8);		cout << "||===||  ||===  ||    ||==||";
		gotoXY(WIDTH - 15, HEIGHT / 2 - 7);		cout << "||   ||  ||===  ||==  ||    ";

		gotoXY(WIDTH - 15, HEIGHT / 2 - 6);		cout << "---------------------------";
		gotoXY(WIDTH - 15, HEIGHT / 2 - 4);
		cout << "UP        = UP ARROW / W";
		gotoXY(WIDTH - 15, HEIGHT / 2 - 2);
		cout << "DOWN      = DOWN ARROW / S";
		gotoXY(WIDTH - 15, HEIGHT / 2 );
		cout << "LEFT      = LEFT ARROW / A";
		gotoXY(WIDTH - 15, HEIGHT / 2 + 2);
		cout << "RIGHT     = RIGHT ARROW / D";
		gotoXY(WIDTH - 15, HEIGHT / 2 + 6);
		cout << "CHOOSE    = ENTER";
		gotoXY(WIDTH - 15, HEIGHT / 2 + 8);
		cout << "EXIT/BACK = ESC(~)";

		do
		{
			setColor(_c[_curColor]);	   gotoXY(4, 2); cout << " ====     ===      ====   ||==||     ||   ======== "; ++_curColor; if (_curColor > 5)_curColor = 0;
			setColor(_c[_curColor]);	   gotoXY(4, 3); cout << "||      ||   ||   ||      ||   ||    ||      ||    "; ++_curColor; if (_curColor > 5)_curColor = 0;
			setColor(_c[_curColor]);	   gotoXY(4, 4); cout << "||      ||===     ||===   ||    ||   ||      ||    "; ++_curColor; if (_curColor > 5)_curColor = 0;
			setColor(_c[_curColor]);       gotoXY(4, 5); cout << "||      ||   ||   ||      ||   ||    ||      ||    "; ++_curColor; if (_curColor > 5)_curColor = 0;
			setColor(_c[_curColor]);	   gotoXY(4, 6); cout << " ====   ||   ||    ====   ||==||     ||      ||    "; ++_curColor; if (_curColor > 5)_curColor = 0;

			if (_curColor > 5)_curColor = 0;
			Sleep(400);
		} while (!_kbhit());
		input = _getch();
		goto back;

	}
	else if (_chosenSection == 4)
	{
		clearScreen();
		setColor(Color::RED); //man hình ket thuc
		gotoXY(WIDTH / 2 - 2, HEIGHT / 2 - 2); cout << "-------------------------" << endl;
		gotoXY(WIDTH / 2 - 7, HEIGHT / 2 - 1); cout << "     |    GOOD BYE! (^O^)/   |" << endl;
		gotoXY(WIDTH / 2 - 2, HEIGHT / 2); cout << "-------------------------" << endl;
		gotoXY(WIDTH / 2 - 2, HEIGHT / 2 + 5);
		exit(1);
	}
	return _chosenSection;
}
