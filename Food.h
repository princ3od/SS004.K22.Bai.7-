#include "Library.h"

class Food
{
private:
    Coordinate coord_;
public:
    Food();
    ~Food();
    friend ostream& operator<<(ostream&, Food&);
};

Food::Food()
{
    srand(time(0));
    do
	{
		coord_.x = rand() % WIDTH + 1; 
		coord_.y = rand() % HEIGHT + 1;
	} while (ground[coord_.y][coord_.x]);
}
Food::~Food()
{
    return;
}
ostream& operator<<(ostream& myCout, Food& food) {
    gotoXY(food.coord_.x, food.coord_.y);
	SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    myCout <<  char(Symbol::APPLE);
    return myCout;
}
