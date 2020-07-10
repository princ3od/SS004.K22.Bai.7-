#pragma once
#include "Library.h"

class Food
{
private:
	Coordinate _coord;
public:
	Food() {}
	~Food() {}
	Food(MapData map[MAX][MAX]);
	Coordinate get();
};