#include "Food.h"

Food::Food(MapData map[MAX][MAX])
{
	srand(time(NULL));
	do
	{
		_coord.x = rand() % WIDTH + 1;
		_coord.y = rand() % HEIGHT + 1;
	} while (map[_coord.x][_coord.y] != MapData::NOTHING);
	map[_coord.x][_coord.y] = MapData::FOOD;
	gotoXY(_coord.x, _coord.y);
	setColor(Color::GREEN);
	cout << char(Symbol::APPLE);
}
Coordinate Food::get()
{
	return _coord;
}