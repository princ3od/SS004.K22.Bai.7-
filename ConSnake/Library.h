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
struct Board
{
	char Name[9];
	unsigned int Score;
};
struct Coordinate
{
	int x, y;
};
enum Symbol
{
	TOP_LEFT = 187,
	TOP_RIGHT = 201,
	BOTTOM_LEFT = 188,
	BOTTOM_RIGHT = 200,

	LONG_BLOCK = 205,
	TALL_BLOCK = 186,
	LONG_BIG_BLOCK = 219,
	SQUARE_BLOCK = 254,
	LONG_THIN_LEFT_BLOCK = 222,
	LONG_THIN_RIGHT_BLOCK = 221,
	LONG_TOP_BLOCK = 220,
	LONG_BOTTOM_BLOCK = 223,
	APPLE = 153
};
//bien mau
enum class Color
{
	RED = 0,
	GREEN = 1,
	BLUE = 2,
	YELLOW = 3,
	PURPLE = 4
};

//game mode 
enum class GameMode
{
	EASY = 0,
	NORMAL = 1,
	HARD = 2,
	SPECIAL = 3
};

//thua neu gia tri am
enum class MapData
{
	WALL = -2,
	SNAKE = -1,
	NOTHING = 0
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
const short int WIDTH = 77;
const short int BOARD_WIDTH = 37;
const short int HEIGHT = 22;
const short int INIT_SNAKE_LENGTH = 4;
const short int INIT_FOOD_COUNTER = 0;
const short int FOOD = 1;

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
namespace INPUT
{
	static SnakeDirection prevInput = SnakeDirection::LEFT;
	static SnakeDirection userInput = SnakeDirection::LEFT;	//bien toan cuc de lay huong di chuyen cua ran
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
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		break;
	case Color::GREEN:
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		break;
	case Color::BLUE:
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		break;
	case Color::YELLOW:
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	case Color::PURPLE:
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE);
		break;
	}
}

static void hideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;   info.bVisible = false;
	SetConsoleCursorInfo(consoleHandle, &info);
}

static bool oppositeDirection(SnakeDirection input1, SnakeDirection input2)
{
	if (input1 == SnakeDirection::LEFT && input2 != SnakeDirection::RIGHT)
		return false;
	if (input1 == SnakeDirection::RIGHT && input2 != SnakeDirection::LEFT)
		return false;
	if (input1 == SnakeDirection::UP && input2 != SnakeDirection::DOWN)
		return false;
	if (input1 == SnakeDirection::DOWN && input2 != SnakeDirection::UP)
		return false;
	return true;
}