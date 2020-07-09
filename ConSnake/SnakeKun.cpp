#include "SnakeKun.h"

SnakeKun::SnakeKun()
{
    _length = INIT_SNAKE_LENGTH;
    _body[0] = { WIDTH / 2,HEIGHT / 2 };
    _direction = INPUT::userInput;
    _foodCounter = INIT_FOOD_COUNTER;
    for (int i = 1; i < _length; i++)
    {
        _body[i].x = _body[i - 1].x - dx[(int)_direction];
        _body[i].y = _body[i - 1].y - dy[(int)_direction];
    }
}

void SnakeKun::update()
{
}

void SnakeKun::setGameMode(GameMode _gm)
{
}

int SnakeKun::getLength()
{
    return 0;
}

SnakeDirection SnakeKun::getDirection()
{
    return SnakeDirection();
}

int SnakeKun::getSpeed()
{
    return 0;
}

bool SnakeKun::isAive()
{
    return false;
}
