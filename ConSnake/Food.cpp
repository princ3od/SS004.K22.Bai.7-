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
	Color _foodColor = ((rand() % 10 + 1) > 5) ? Color::RED : Color::GREEN;
	setColor(_foodColor);
	cout << char(Symbol::APPLE);
}
Coordinate Food::get()
{
	return _coord;
}