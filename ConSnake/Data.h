#pragma once
#include "Library.h"
class Data
{
private:
	bool readHighScore(string _scoreBoardFile = "highscore.txt");
	bool readLoseText(string _loseTextFile = "losetext.txt");
	bool readMap(string _mapFile = "defaultmap.txt");
public:
	MapData _map[MAX][MAX];
	string _loseText[50];
	int _highScore[10];
	bool readData(string _scoreBoardFile = "highscore.txt", string _loseTextFile = "losetext.txt");
	bool save(int _newScore, string _scoreBoardFile = "highscore.txt");
};

