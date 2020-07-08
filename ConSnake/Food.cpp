#include "Food.h"

Food::Food(MapData map[WIDTH][HEIGHT])
{
	srand(time(NULL));
	do
	{
		_coord.x = rand() % WIDTH + 1;
		_coord.y = rand() % HEIGHT + 1;
	} while (map[_coord.y][_coord.x] != MapData::NOTHING);
}
Coordinate Food::get()
{
	return _coord;
}
ostream& operator<<(ostream& myCout, Food& food) {
	gotoXY(food._coord.x, food._coord.y);
	setColor(Color::GREEN);
	myCout << char(Symbol::APPLE);
	return myCout;
}
