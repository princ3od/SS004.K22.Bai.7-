#include "SnakeKun.h"

SnakeKun::SnakeKun(MapData map[WIDTH][HEIGHT])
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
    for (int i = 0; i < _length; i++)
        map[_body[i].y][_body[i].x] = MapData::SNAKE;
}

void SnakeKun::update()
{
    //dia chi tam thoi cua ran
    Coordinate _prev[WIDTH * HEIGHT];

    for (int i = 0; i < _length; i++)
    {
        _prev[i].x = _body[i].x;     
        _prev[i].y = _body[i].y;
    }
    if (INPUT::userInput != EXIT && !oppositeDirection(_direction, INPUT::userInput))
       
}

void SnakeKun::setGameMode(GameMode _gm)
{
    _gameMode = _gm;
}

Coordinate SnakeKun::getHead()
{
    return _body[0];
}

int SnakeKun::getLength()
{
    return _length;
}

SnakeDirection SnakeKun::getDirection()
{
    return _direction;
}

int SnakeKun::getSpeed()
{
    return _speed;
}

bool SnakeKun::isAive()
{
    return _isAlive;
}
