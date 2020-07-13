#pragma once
#include "Library.h"
static GameDifficult _gameDifficult;
class SnakeKun
{
private:
	int _length;
	Coordinate _body[WIDTH * HEIGHT];
	SnakeDirection _direction;
	bool _isAlive;
	int _curColor;
	int _delay;
	int _bonus;
	Color supportLGBTComunity();
public:
	int _score;
	SnakeKun() {}
	SnakeKun(MapData _map[MAX][MAX], GameDifficult _gameDifficult);
	void update(MapData _map[MAX][MAX],
		SnakeDirection userInput, SnakeDirection& prevInput, bool& _eated);
	void countFood();
	Coordinate getHead();
	int getLength();
	SnakeDirection getDirection();
	int getSpeed();
	bool isAive();
};

