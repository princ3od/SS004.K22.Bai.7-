#include "Data.h"

bool Data::readHighScore(string _scoreBoardFile)
{
	fstream _file;
	int index = 0;
	_file.open(_scoreBoardFile);
	if (!_file.fail())
	{
		while (!_file.eof())
		{
			_file >> _highScore[index];
			index++;
		}
		for (index = index; index < 10; index++)
			_highScore[index] = 0;
		_file.close();
		return true;
	}
	for (index = index; index < 10; index++)
		_highScore[index] = 0;
	_file.close();
	return false;
}

bool Data::readLoseText(string _loseTextFile)
{
	fstream _file;
	int index = 0;
	_file.open(_loseTextFile);
	if (!_file.fail())
	{
		while (!_file.eof())
		{
			getline(_file, _loseText[index]);
			index++;
		}
		for (index = index; index < 50; index++)
			_loseText[index] = "";
		_file.close();
		return true;
	}
	for (index = index; index < 50; index++)
		_loseText[index] = _loseText[0];
	_file.close();
	return false;
}

bool Data::readMap(string _mapFile)
{
	const char WALL_CHAR = '#';
	string str;
	fstream _file;
	int index = 0;
	_file.open(_mapFile);
	if (!_file.fail())
	{
		while (!_file.eof())
		{
			getline(_file, str);
			int i;
			for (i = 0; i < str.size(); i++)
			{
				if (str[i] == WALL_CHAR)
					_map[i][index] = MapData::WALL;
				else
					_map[i][index] = MapData::NOTHING;
			}
			for (i = i; i < MAX; i++)
				_map[i][index] = MapData::NOTHING;
			index++;
		}
		for (index = index; index < MAX; index++)
			for (int i = 0; i < MAX; i++)
				_map[i][index] = MapData::NOTHING;
		_file.close();
		return true;
	}
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			_map[i][j] = MapData::NOTHING;
	return false;
}

bool Data::readData(string _scoreBoardFile, string _loseTextFile)
{
	bool _get1 = readHighScore(_scoreBoardFile),
		_get2 = readLoseText(_loseTextFile),
		_get3 = readMap();
	return (_get1 && _get2 && _get3);
}

bool Data::save(int _newScore, string _scoreBoardFile)
{
	int _pos = 0;
	while (_newScore < _highScore[_pos])
		_pos++;
	for (int i = 9; i > _pos; i--)
		_highScore[_pos] = _highScore[_pos - 1];
	_highScore[_pos] = _newScore;

	fstream _file;
	if (_file.is_open())
		return false;
	_file.open(_scoreBoardFile);
	for (int index = 0; index < 10; index++)
		_file << _highScore[index] << endl;
	_file.close();
	return true;
}
