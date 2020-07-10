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
	int _curColor;
	void supportLGBTComunity();
public:
	SnakeKun() {}
	SnakeKun(MapData _map[MAX][MAX]);
	void update(unsigned short int& delay, MapData _map[MAX][MAX]);
	void setGameMode(GameMode _gm);
	void countFood(unsigned short int&);
	Coordinate getHead();
	int getLength();
	SnakeDirection getDirection();
	int getSpeed();
	bool isAive();

};

