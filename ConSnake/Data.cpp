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
					_file >> Data::_classicalHighScore[index];
					index++;
				}
				for (index = index; index < 10; index++)
					Data::_classicalHighScore[index] = 0;
			}
			else if (i == 1)
			{
				while (!_file.eof())
				{
					_file >> Data::_campaignHighScore[index]._lv
						>> Data::_campaignHighScore[index]._time;
					index++;
				}
				for (index = index; index < 10; index++)
					Data::_campaignHighScore[index] = { 0,0 };
			}
			else
			{
				while (!_file.eof())
				{
					_file >> Data::_endlessHighScore[index];
					index++;
				}
				for (index = index; index < 10; index++)
					Data::_endlessHighScore[index] = 0;
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
	_file.open(_loseTextFile);
	if (!_file.fail())
	{
		while (!_file.eof())
		{
			getline(_file, Data::_loseText[index]);
			index++;
		}
		for (index = index; index < 50; index++)
			Data::_loseText[index] = "";
		_file.close();
		return true;
	}
	for (index = index; index < 50; index++)
		Data::_loseText[index] = Data::_loseText[0];
	_file.close();
	return false;
}

bool DataControl::readMap(string _mapFile)
{
	const char WALL_CHAR = '#';
	string str;
	fstream _file;
	int index = 0;
	_file.open(_mapFile + EXTENSION::MAP);
	if (!_file.fail())
	{
		while (!_file.eof())
		{
			getline(_file, str);
			int i;
			for (i = 0; i < str.size(); i++)
			{
				if (str[i] == WALL_CHAR)
					Data::_map[i][index] = MapData::WALL;
				else
					Data::_map[i][index] = MapData::NOTHING;
			}
			for (i = i; i < MAX; i++)
				Data::_map[i][index] = MapData::NOTHING;
			index++;
		}
		for (index = index; index < MAX; index++)
			for (int i = 0; i < MAX; i++)
				Data::_map[i][index] = MapData::NOTHING;
		_file.close();
		return true;
	}
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			Data::_map[i][j] = MapData::NOTHING;
	return false;
}

bool DataControl::readData(string _mapFile, string _highScoreFile, string _loseTextFile)
{
	bool _get1 = readHighScore(_highScoreFile),
		_get2 = readLoseText(_loseTextFile);
	return (_get1 && _get2);
}

bool DataControl::save(int _newScore, GameMode _gameMode, CampaignScore _newCScore)
{
	int _pos = 0;
	fstream _file;
	string _fileName = "highscore";
	char _highType[3] = { '1','2','3' };
	if (_gameMode == GameMode::CLASSICAL)
	{
		_fileName = _fileName + _highType[0] + EXTENSION::DATA;
		_file.open(_fileName);
		while (_newScore < Data::_classicalHighScore[_pos])
			_pos++;
		for (int i = 9; i > _pos; i--)
			Data::_classicalHighScore[_pos] = Data::_classicalHighScore[_pos - 1];
		Data::_classicalHighScore[_pos] = _newScore;
		for (int index = 0; index < 10; index++)
			_file << Data::_classicalHighScore[index] << endl;
	}
	else if (_gameMode == GameMode::CAMPAIGN)
	{
		_fileName = _fileName + _highType[1] + EXTENSION::DATA;
		_file.open(_fileName);
		while (_newCScore._lv < Data::_campaignHighScore[_pos]._lv
			&& _newCScore._time < Data::_campaignHighScore[_pos]._time)
			_pos++;
		for (int i = 9; i > _pos; i--)
			Data::_campaignHighScore[_pos] = Data::_campaignHighScore[_pos - 1];
		Data::_campaignHighScore[_pos] = _newCScore;
		for (int index = 0; index < 10; index++)
			_file << Data::_campaignHighScore[index]._lv << " "
			<< Data::_campaignHighScore[index]._time << endl;
	}
	else
	{
		_fileName = _fileName + _highType[2] + EXTENSION::DATA;
		_file.open(_fileName);
		while (_newScore < Data::_endlessHighScore[_pos])
			_pos++;
		for (int i = 9; i > _pos; i--)
			Data::_endlessHighScore[_pos] = Data::_endlessHighScore[_pos - 1];
		Data::_endlessHighScore[_pos] = _newScore;
		for (int index = 0; index < 10; index++)
			_file << Data::_endlessHighScore[index] << endl;
	}
	_file.close();
	return true;
}
