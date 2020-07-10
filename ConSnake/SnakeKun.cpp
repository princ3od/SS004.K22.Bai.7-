#include "SnakeKun.h"

SnakeKun::SnakeKun(MapData _map[MAX][MAX])
{
	_curColor = 0;
	_direction = SnakeDirection::RIGHT;
	_length = INIT_SNAKE_LENGTH;
	_body[0] = { WIDTH / 2 + 1,HEIGHT / 2 };
	gotoXY(_body[0].x, _body[0].y);
	supportLGBTComunity();
	cout << (char)Symbol::LONG_BLOCK;

	_direction = SnakeDirection::RIGHT;
	_foodCounter = INIT_FOOD_COUNTER;
	for (int i = 1; i < _length; i++)
	{
		_body[i].x = _body[i - 1].x - dx[(int)_direction];
		_body[i].y = _body[i - 1].y - dy[(int)_direction];
		gotoXY(_body[i].x, _body[i].y);
		supportLGBTComunity();
		cout << (char)Symbol::LONG_BLOCK;
	}
	for (int i = 0; i < _length; i++)
		_map[_body[i].x][_body[i].y] = MapData::SNAKE;
}

void SnakeKun::update(unsigned short int& delay, MapData _map[MAX][MAX],
	SnakeDirection userInput, SnakeDirection& prevInput, bool& _eated)
{
	gotoXY(1, 1);
	cout << _length;
	int i;
	int delay_slow = delay;

	if (Input::userInput != SnakeDirection::EXIT && !isOppositeDirection(_direction, userInput))
	{
		prevInput = _direction;
		_direction = userInput;
	}

	//di chuyen dau con snake theo huong cua input (2)
	Coordinate _head = _body[0];
	_head.x = _body[0].x + dx[(int)_direction];
	_head.y = _body[0].y + dy[(int)_direction];

	//neu tu dam vao minh thi gameover(3)
	if (_map[_head.x][_head.y] == MapData::WALL
		|| _map[_head.x][_head.y] == MapData::SNAKE)
		_isAlive = false;

	//neu an duoc thi cong diem(4)
	if (_map[_head.x][_head.y] == MapData::FOOD)
	{
		_eated = true;
		countFood(delay);
	}
	else
	{
		//xoa duoi (tail) snake khi snake chua tang kich co 
		_map[_body[_length - 1].x][_body[_length - 1].y] = MapData::NOTHING;
		gotoXY(_body[_length - 1].x, _body[_length - 1].y);
		cout << " ";
	}

	for (i = _length - 1; i > 0; i--)
	{
		_body[i].x = _body[i - 1].x;	//snake di chuyen theo huong ban dau(7)
		_body[i].y = _body[i - 1].y;
	}

	supportLGBTComunity(); //yeah, we support LGBT community :v
	if (Input::prevInput != _direction)
	{
		gotoXY(_body[1].x, _body[1].y);
		if ((Input::prevInput == SnakeDirection::RIGHT && _direction == SnakeDirection::DOWN)
			|| (Input::prevInput == SnakeDirection::UP && _direction == SnakeDirection::LEFT))
			cout << (char)Symbol::BOTTOM_LEFT;
		else if ((Input::prevInput == SnakeDirection::RIGHT && _direction == SnakeDirection::UP)
			|| (Input::prevInput == SnakeDirection::DOWN && _direction == SnakeDirection::LEFT))
			cout << (char)Symbol::TOP_LEFT;
		else if ((Input::prevInput == SnakeDirection::LEFT && _direction == SnakeDirection::UP)
			|| (Input::prevInput == SnakeDirection::DOWN && _direction == SnakeDirection::RIGHT))
			cout << (char)Symbol::TOP_RIGHT;
		else if ((Input::prevInput == SnakeDirection::LEFT && _direction == SnakeDirection::DOWN)
			|| (Input::prevInput == SnakeDirection::UP && _direction == SnakeDirection::RIGHT))
			cout << (char)Symbol::BOTTOM_RIGHT;
		Input::prevInput = _direction;

		gotoXY(_head.x, _head.y);
		supportLGBTComunity();
		cout << (char)Symbol::HEAD;
	}
	else
	{
		gotoXY(_head.x, _head.y);
		cout << (char)Symbol::HEAD;

		gotoXY(_body[1].x, _body[1].y);
		if (_direction == SnakeDirection::UP || _direction == SnakeDirection::DOWN)
			cout << (char)Symbol::TALL_BLOCK;
		else
			cout << (char)Symbol::LONG_BLOCK;
	}

	//dua du lieu snake vao map(8)
	_body[0] = _head;
	for (i = 0; i < _length; i++)
		_map[_body[i].x][_body[i].y] = MapData::SNAKE;

	//neu ran di len/xuong thi giam toc do(9)
	if (_direction == SnakeDirection::UP || _direction == SnakeDirection::DOWN)
	{
		delay_slow += (delay * 30) / 100;
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
	//item = FOOD;
	if (_gameMode == GameMode::SPECIAL && _length <= 104) {
		//tang toc do trong gamemode special
		--delay;
	}
}

void SnakeKun::setGameMode(GameMode _gm)
{
	_gameMode = _gm;
}

Coordinate SnakeKun::getHead()
{
	return _body[1];
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

Color SnakeKun::supportLGBTComunity()
{
	Color _c[6] = { Color::RED,Color::ORANGE,Color::YELLOW,Color::GREEN,Color::BLUE,Color::PURPLE };
	setColor(_c[_curColor]);
	_curColor++;
	_curColor = (_curColor > 5) ? 0 : _curColor;
	return _c[_curColor];
}
