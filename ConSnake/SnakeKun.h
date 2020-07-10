#pragma once
#include "Library.h"
class SnakeKun
{
private:
	int _length;
	Coordinate _body[WIDTH * HEIGHT];
	MapData _map[MAX][MAX];
	SnakeDirection _direction;
	int _speed;
	bool _isAlive;
	GameMode _gameMode;
	int _foodCounter;
public:
	SnakeKun() {}
	void createSnake();
	void update(unsigned short int& delay);
	void setGameMode(GameMode _gm);
	void countFood(unsigned short int&);
	Coordinate getHead();
	int getLength();
	SnakeDirection getDirection();
	int getSpeed();
	bool isAive();
	void getSnakeBody();

};

