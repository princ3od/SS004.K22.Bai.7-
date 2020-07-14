#pragma once
#include "Library.h"
#include "SnakeKun.h"

static short int _level;
class GamePlay
{
public:
	static short int Campaign(unsigned short int _unlock);
	static short int Classic();
	static GameMode ChooseGameMode(short int& level, GameDifficult& _gd, unsigned short int _unlock);
};
