#pragma once
#include "Library.h"
#include "SnakeKun.h"

static GameDifficult _gameDiff;
class GamePlay
{
public:
	static short int Campaign();
	static short int Classic();
	static GameMode ChooseGameMode(GameDifficult& _gd);
};
