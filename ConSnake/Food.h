#pragma once
#include "Library.h"

class Food
{
private:
	Coordinate _coord;
public:
	Food() {}
	~Food() {}
	Food(MapData map[WIDTH][HEIGHT]);
	Coordinate get();
	friend ostream& operator<<(ostream&, Food&);
};