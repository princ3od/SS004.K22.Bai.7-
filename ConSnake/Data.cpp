#include "Data.h"

bool Data::readData(string _scoreBoardFile, string _loseTextFile)
{
    fstream _file;
    if (!_file.is_open())
        return false;
    _file.open(_scoreBoardFile);
    int index = 0;
	do
	{
        _file >> _highScore[index];
        index++;
	} while (!_file.eof());

}

bool Data::save()
{
    return false;
}

string* Data::getLoseText()
{
    return _loseText;
}

int* Data::getHightScore()
{
    return _highScore;
}
