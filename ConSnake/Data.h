#pragma once
#include "Library.h"
class Data
{
private:
	string _loseText[50];
	int _highScore[10];
	bool readHighScore(string _scoreBoardFile = "highscore.txt");
	bool readLoseText(string _loseTextFile = "losetext.txt");
	//int _map[][];
public:
	bool readData(string _scoreBoardFile = "highscore.txt", string _loseTextFile = "losetext.txt");
	bool save(int _newScore, string _scoreBoardFile = "scoreboard.txt");
	string* getLoseText();
	int* getHighScore();
	//int** getMap();
};

