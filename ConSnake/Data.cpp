#include "Data.h"

bool DataControl::readHighScore(string _highScoreFile)
{
	char _highType[3] = { '1','2','3' };
	fstream _file;
	int index = 0;
	for (int i = 0; i < 3; i++)
	{
		string _fileName = _highScoreFile + _highType[i] + EXTENSION::DATA;
		_file.open(_fileName);
		index = 0;
		if (!_file.fail())
		{
			if (i == 0)
			{
				while (!_file.eof())
				{
					_file >> _classicalHighScore[index];
					index++;
				}
				for (index = index; index < 10; index++)
					_classicalHighScore[index] = 0;
			}
			else if (i == 1)
			{
				while (!_file.eof())
				{
					_file >> _campaignHighScore[index]._lv
						>> _campaignHighScore[index]._time;
					index++;
				}
				for (index = index; index < 10; index++)
					_campaignHighScore[index] = { 0,0 };
			}
			else
			{
				while (!_file.eof())
				{
					_file >> _endlessHighScore[index];
					index++;
				}
				for (index = index; index < 10; index++)
					_endlessHighScore[index] = 0;
			}
		}
		_file.close();
		if (i == 2)
			return true;
	}
	return false;
}

bool DataControl::readLoseText(string _loseTextFile)
{
	fstream _file;
	int index = 0;
	_file.open(_loseTextFile + EXTENSION::DATA);
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

bool DataControl::readMap(string _mapFile)
{
	const char WALL_CHAR = '#';
	string str;
	fstream _file;
	int index = 0;
	string _fileName = _mapFile + EXTENSION::MAP;
	_file.open(_fileName);
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

bool DataControl::save(int _newScore, GameMode _gameMode, CampaignScore _newCScore)
{
	int _pos = 10;
	fstream _file;
	string _fileName = "highscore";
	string _highType[3] = { "1","2","3" };
	if (_gameMode == GameMode::CLASSICAL)
	{
		_fileName = _fileName + _highType[0] + EXTENSION::DATA;
		_file.open(_fileName);
		while (_pos > 0 && _newScore > _classicalHighScore[_pos - 1])
		{
			_pos--;
			_classicalHighScore[_pos + 1] = _classicalHighScore[_pos];
		}
		if (_pos < 10)
			_classicalHighScore[_pos] = _newScore;
		for (int index = 0; index < 10; index++)
			_file << _classicalHighScore[index] << endl;
	}
	else if (_gameMode == GameMode::CAMPAIGN)
	{
		_fileName = _fileName + _highType[1] + EXTENSION::DATA;
		_file.open(_fileName);
		while (_pos > 0 && _newCScore._lv >= _campaignHighScore[_pos - 1]._lv)
		{
			_pos--;
			_campaignHighScore[_pos + 1]._lv = _campaignHighScore[_pos]._lv;
			_campaignHighScore[_pos + 1]._time = _campaignHighScore[_pos]._time;
			
		}
		while (_newCScore._lv == _campaignHighScore[_pos - 1]._lv && _newCScore._time < _campaignHighScore[_pos - 1]._time)
		{
			_pos--;
			_campaignHighScore[_pos + 1]._lv = _campaignHighScore[_pos]._lv;
			_campaignHighScore[_pos + 1]._time = _campaignHighScore[_pos]._time;
		}
		if (_pos < 10)
		{

			_campaignHighScore[_pos]._lv = _newCScore._lv;
			_campaignHighScore[_pos]._time = _newCScore._time;

		}
		for (int index = 0; index < 10; index++)
			_file << _campaignHighScore[index]._lv << " "
			<< _campaignHighScore[index]._time << endl;
	}
	else
	{
		_fileName = _fileName + _highType[2] + EXTENSION::DATA;
		_file.open(_fileName);
		while (_pos > 0 && _newScore > _endlessHighScore[_pos - 1])
		{
			_pos--;
			_endlessHighScore[_pos + 1] = _endlessHighScore[_pos];
		}
		if (_pos < 10)
			_endlessHighScore[_pos] = _newScore;
		for (int index = 0; index < 10; index++)
			_file << _endlessHighScore[index] << endl;
	}
	_file.close();
	if (_pos < 9)
		return true;
	return false;
}

