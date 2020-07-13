#pragma once
#include "Library.h"

class GamePlay
{
	static short int _level;
public:
	short int Campaign();
	void Classic();
	void Endless();
	void setupLevel();
};
