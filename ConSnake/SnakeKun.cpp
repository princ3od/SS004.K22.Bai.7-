#include "SnakeKun.h"

void SnakeKun::createSnake()
{
    _length = INIT_SNAKE_LENGTH;
    _body[0] = { WIDTH / 2,HEIGHT / 2 };
    _direction = Input::userInput;
    _foodCounter = INIT_FOOD_COUNTER;
    for (int i = 1; i < _length; i++)
    {
        _body[i].x = _body[i - 1].x - dx[(int)_direction];
        _body[i].y = _body[i - 1].y - dy[(int)_direction];
    }
    for (int i = 0; i < _length; i++)
        _map[_body[i].y][_body[i].x] = MapData::SNAKE;
}

void SnakeKun::update(unsigned short int& delay)
{
    //dia chi tam thoi cua ran
    int i;
    int delay_slow = delay;
    Coordinate _prev[WIDTH * HEIGHT];

    for (i = 0; i < _length; i++)
    {
        _prev[i].x = _body[i].x;     
        _prev[i].y = _body[i].y;
    }
    if (Input::userInput != SnakeDirection::EXIT && !oppositeDirection(_direction, Input::userInput))
        _direction = Input::userInput;

    //di chuyen dau con snake theo huong cua input (2)
    _body[0].x = _prev[0].x + dx[(int)_direction];		
    _body[0].y = _prev[0].y + dy[(int)_direction];

    //neu tu dam vao minh thi gameover(3)
    if (_map[_body[0].y][_body[0].x] < MapData::NOTHING)
    {
        item = -1;     
        return;
    }

    //neu an duoc thi cong diem(4)
    if (_map[_body[0].y][_body[0].x] == FOOD)
    {
        countFood(delay);
    }
    else
    {
        _map[_body[_length - 1].y][_body[_length - 1].x] = MapData::NOTHING;
        item = (short int)MapData::NOTHING;
        gotoXY(_body[_length - 1].x, _body[_length - 1].y);		// neu snake chua tang kich co thi(6)
        cout << " ";						                    // xoa phan cuoi cua snake
    }

    for (i = 1; i < _length; i++)
    {
        _body[i].x = _prev[i - 1].x;	//snake di chuyen theo huong ban dau(7)
        _body[i].y = _prev[i - 1].y;
    }

    //dua du lieu snake vao map(8)
    for (i = 0; i < _length; i++)
        _map[_body[i].y][_body[i].x] = MapData::SNAKE;

    //neu ran di len/xuong thi giam toc do(9)
    if (Input::userInput == SnakeDirection::UP || Input::userInput == SnakeDirection::DOWN)
    {
        delay_slow += (delay * 25) / 100;
        Sleep(delay_slow);
    }
    else Sleep(delay);

}

void SnakeKun::countFood(unsigned short int& delay)
{
    //tinh diem khac nhau, tuy gamemode (5)
    switch (_gameMode) 
    {
    case GameMode::EASY:
        _foodCounter += (_length * 5); break;
    case GameMode::NORMAL:
        _foodCounter += (_length * 10); break;
    case GameMode::HARD:
        _foodCounter += (_length * 15); break;
    case GameMode::SPECIAL:
        _foodCounter += (_length * (_length - 3)); break;
    }
    // tang kich thuoc ran khi ran an(6)
    _length++; 
    item = FOOD;
    if (_gameMode == GameMode::SPECIAL && _length <= 104) {
        //tang toc do trong gamemode special
        --delay; 
    }
}

void SnakeKun::getSnakeBody()
{
    unsigned short _snakeLED;
    _snakeLED = rand() % 8;
    switch (_snakeLED)
    {
    case 0:
        setColor(Color::RED); break;
    case 1:
        setColor(Color::ORANGE); break;
    case 2:
        setColor(Color::YELLOW); break;
    case 3:
        setColor(Color::GREEN); break;
    case 4:
        setColor(Color::BLUE); break;
    case 5:
        setColor(Color::CYAN); break;
    case 6:
        setColor(Color::PURPLE); break;
    }
    //doi dau snake cu thanh than minh(8)
    if (Input::prevInput == SnakeDirection::UP && Input::userInput == SnakeDirection::RIGHT)
        cout << char(TOP_RIGHT);
    else if (Input::prevInput == SnakeDirection::DOWN && Input::userInput == SnakeDirection::RIGHT)
        cout << char(BOTTOM_RIGHT);
    else if (Input::prevInput == SnakeDirection::UP && Input::userInput == SnakeDirection::LEFT)
        cout << char(TOP_LEFT);
    else if (Input::prevInput == SnakeDirection::DOWN && Input::userInput == SnakeDirection::LEFT)
        cout << char(BOTTOM_LEFT);
    else if (Input::prevInput == SnakeDirection::RIGHT && Input::userInput == SnakeDirection::UP)
        cout << char(BOTTOM_LEFT);
    else if (Input::prevInput == SnakeDirection::RIGHT && Input::userInput == SnakeDirection::DOWN)
        cout << char(TOP_LEFT);
    else if (Input::prevInput == SnakeDirection::LEFT && Input::userInput == SnakeDirection::UP)
        cout << char(BOTTOM_RIGHT);
    else if (Input::prevInput == SnakeDirection::LEFT && Input::userInput == SnakeDirection::DOWN)
        cout << char(TOP_RIGHT);
    if (oppositeDirection(Input::prevInput, Input::userInput) == 0)
        Input::prevInput = Input::userInput;
    gotoXY(_body[0].x, _body[0].y);
    if (Input::userInput == SnakeDirection::UP || Input::userInput == SnakeDirection::DOWN) //them dau snake moi vao
    {
        cout << char(TALL_BLOCK);
        prevBlock = TALL_BLOCK;
    }
    else {
        cout << char(LONG_BLOCK);
        prevBlock = LONG_BLOCK;
    }
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
