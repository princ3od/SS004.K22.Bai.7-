#pragma once
#include "Library.h"
class SnakeKun
{
private:
	int _length;
	Coordinate _body[WIDTH * HEIGHT];
	SnakeDirection _direction;
	int _speed;
	bool _isAlive;
	GameMode _gameMode;
	int _foodCounter;
public:
	SnakeKun();
	void update();
	void setGameMode(GameMode _gm);
	int getLength();
	SnakeDirection getDirection();
	int getSpeed();
	bool isAive();

};

