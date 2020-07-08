#pragma once
#include "Library.h"
class Data
{
private:
	string _loseText[100];
	int _highScore[10];
	//int _map[][];
public:
	bool readData(string _scoreBoardFile = "scoreboard.txt", string _loseTextFile = "losetext.txt");
	bool save();
	string* getLoseText();
	int* getHightScore();
	//int** getMap();
};

