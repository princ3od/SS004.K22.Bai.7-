#include "SnakeKun.h"
#include "Menu.h"
SnakeKun::SnakeKun(MapData _map[MAX][MAX], GameDifficult _gd, bool _isLgbt)
{
	isLGBT_ = _isLgbt;
	//khoi tao ban dau tuy do kho
	_gameDifficult = _gd;
	switch (_gameDifficult)
	{
	case GameDifficult::EASY:
		_delay = 120;
		break;
	case GameDifficult::NORMAL:
		_delay = 100;
		break;
	case GameDifficult::HARD:
		_delay = 80;
	}
	_curColor = 0;
	_direction = SnakeDirection::RIGHT;
	_length = INIT_SNAKE_LENGTH;
	_body[0] = { WIDTH / 2,HEIGHT / 2 };
	gotoXY(_body[0].x, _body[0].y);
	supportLGBTComunity(isLGBT_);
	cout << (char)Symbol::HEAD;

	_isAlive = true;
	_direction = SnakeDirection::RIGHT;
	_score = 0;
	_bonus = ((int)_gameDifficult * 15);
	for (int i = 1; i < _length; i++)
	{
		_body[i].x = _body[i - 1].x - dx[(int)_direction];
		_body[i].y = _body[i - 1].y - dy[(int)_direction];
		gotoXY(_body[i].x, _body[i].y);
		supportLGBTComunity(isLGBT_);
		cout << (char)Symbol::LONG_BLOCK;
	}
	for (int i = 0; i < _length; i++)
		_map[_body[i].x][_body[i].y] = MapData::SNAKE;
}

void SnakeKun::update(MapData _map[MAX][MAX],SnakeDirection userInput, SnakeDirection& prevInput, bool& _eated)
{
	gotoXY(1, 1);
	cout << _length << " " << _score;
	_bonus = (_bonus - 2 < 0) ? 0 : _bonus - 2;
	int i;

	if (Input::userInput != SnakeDirection::EXIT && !isOppositeDirection(_direction, userInput))
	{
		prevInput = _direction;
		_direction = userInput;
	}

	//di chuyen dau con snake theo huong cua input (2)
	Coordinate _head = _body[0];
	_head.x = _body[0].x + dx[(int)_direction];
	_head.y = _body[0].y + dy[(int)_direction];

	//snake di qua man hinh
	if (_head.x < 0)
		_head.x = WIDTH;
	else if (_head.x > WIDTH)
		_head.x = 0;
	if (_head.y < 0)
		_head.y = HEIGHT;
	if (_head.y > HEIGHT)
		_head.y = 0;

	//neu an duoc thi cong diem
	if (_map[_head.x][_head.y] == MapData::FOOD)
	{
		_eated = true;
		countFood();
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
		_body[i].x = _body[i - 1].x;	//snake di chuyen theo huong ban dau
		_body[i].y = _body[i - 1].y;
	}

	//neu tu dam vao minh thi gameover
	if (_map[_head.x][_head.y] == MapData::WALL
		|| _map[_head.x][_head.y] == MapData::SNAKE)
		_isAlive = false;

	supportLGBTComunity(isLGBT_); //yeah, we support LGBT community :v
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
		supportLGBTComunity(isLGBT_);
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
		float heSo = (130 / _delay);
		float delay_slow = _delay + ((_delay * 35) / 100) * heSo;
		Sleep(delay_slow);
	}
	else Sleep(_delay);

}

void SnakeKun::countFood()
{
	_score += (rand() % ((int)_gameDifficult * 4)) + (int)_gameDifficult + _bonus;
	_bonus = ((int)_gameDifficult * 15);
	_length += 1;
	if (_delay > 16 && ((_length - 3) % 2 == 0))
		_delay -= (rand() % (int)_gameDifficult + 1);
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
	return 216 - _delay;
}

bool SnakeKun::isAive()
{
	return _isAlive;
}

Color SnakeKun::supportLGBTComunity(bool isLGBT_)
{
	if (!isLGBT_)
	{
		setColor(Color::WHITE);
		return (Color::WHITE);
	}
	Color _c[6] = { Color::RED,Color::ORANGE,Color::YELLOW,Color::GREEN,Color::BLUE,Color::PURPLE };
	setColor(_c[_curColor]);
	_curColor++;
	_curColor = (_curColor > 5) ? 0 : _curColor;
	return _c[_curColor];
}
