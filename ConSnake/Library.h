#pragma once
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <process.h>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;

//struct
struct CampaignScore
{
	int _lv, _time;
};
struct Board
{
	char Name[9];
	unsigned int Score;
};
struct Coordinate
{
	int x, y;
	bool operator==(Coordinate b)
	{
		return (x == b.x) && (y == b.y);
	}
};
enum Symbol
{
	BOTTOM_LEFT = 187,
	TOP_LEFT = 188,
	TOP_RIGHT = 200,
	BOTTOM_RIGHT = 201,
	LONG_BLOCK = 205,
	TALL_BLOCK = 186,

	LONG_BIG_BLOCK = 219,
	SQUARE_BLOCK = 254,
	LONG_THIN_LEFT_BLOCK = 221,
	LONG_THIN_RIGHT_BLOCK = 222,
	LONG_TOP_BLOCK = 220,
	LONG_BOTTOM_BLOCK = 223,
	APPLE = 153,

	UP_KEY = 72,
	DOWN_KEY = 80,
	RIGHT_KEY = 77,
	LEFT_KEY = 75,
	EXIT_KEY = 27,
	ENTER_KEY = 13,

	HEAD = 254,
	TALL_TAIL = 179,
	LONG_TAIL = 196,
};
//bien mau
enum class Color
{
	RED = 0,
	GREEN = 1,
	BLUE = 2,
	YELLOW = 3,
	PURPLE = 4,
	ORANGE = 5,
	WHITE = 6,
	GRAY = 7
};

//game difficult
enum class GameDifficult
{
	EASY = 1,
	NORMAL = 2,
	HARD = 3,
};
//game mode
enum class GameMode
{
	CLASSICAL = 0,
	CAMPAIGN = 1,
	ENDLESS = 2
};

//thua neu gia tri am
enum class MapData
{
	WALL = -2,
	SNAKE = -1,
	NOTHING = 0,
	FOOD = 1
};

enum class SnakeDirection {
	RIGHT = 0,
	UP = 1,
	LEFT = 2,
	DOWN = 3,
	EXIT = -1
};

//constant
const short int MAX_B = 11;
const short int MAX = 114;
const short int WIDTH = 80;
const short int BOARD_WIDTH = 37;
const short int HEIGHT = 28;
const short int INIT_SNAKE_LENGTH = 4;
const short int INIT_FOOD_COUNTER = 0;
static short int item = (short int)MapData::NOTHING;

//su dung cho cac windows func
static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

//huong di
static short int dx[5] = { 1, 0, -1, 0 };
static short int dy[5] = { 0, -1, 0, 1 };
static unsigned short int speed[5]{ 0, 34 , 74 , 0 };

//(1, 0) = phai
//(0, -1) = len
//(-1, 0) = trai
//(0, 1) = xuong
namespace Input
{
	static SnakeDirection prevInput;
	static SnakeDirection userInput;//bien toan cuc de lay huong di chuyen cua ran
}
static void gotoXY(int column, int row)
{
	HANDLE hStdOut;
	COORD coord;

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	coord.X = column;
	coord.Y = row;
	SetConsoleCursorPosition(hStdOut, coord);
}

static void clearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	)) return;
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

static void setColor(Color _color)
{
	switch (_color)
	{
	case Color::RED:
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		break;
	case Color::ORANGE:
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		break;
	case Color::GREEN:
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
		break;
	case Color::BLUE:
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);
		break;
	case Color::YELLOW:
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	case Color::PURPLE:
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE);
		break;
	case Color::WHITE:
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		break;
	case Color::GRAY:
		SetConsoleTextAttribute(h, 8);
		break;

	}
}

static void hideCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;   info.bVisible = false;
	SetConsoleCursorInfo(h, &info);
}
static void setFont()
{
	PCONSOLE_FONT_INFOEX font = new CONSOLE_FONT_INFOEX();
	font->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	//CONSOLE_FONT_INFOEX is defined in some windows header
	GetCurrentConsoleFontEx(h, false, font);
	//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
	font->dwFontSize.X = 20;
	font->dwFontSize.Y = 18;
	SetCurrentConsoleFontEx(h, false, font);
}
static bool isOppositeDirection(SnakeDirection input1, SnakeDirection input2)
{
	if ((input1 == SnakeDirection::LEFT && input2 == SnakeDirection::RIGHT)
		|| (input1 == SnakeDirection::UP && input2 == SnakeDirection::DOWN)
		|| (input2 == SnakeDirection::LEFT && input1 == SnakeDirection::RIGHT)
		|| (input2 == SnakeDirection::UP && input1 == SnakeDirection::DOWN))
		return true;
	return false;
}


