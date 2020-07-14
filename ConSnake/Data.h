#pragma once
#include "Library.h"
namespace EXTENSION
{
	static const string MAP = ".cmap";
	static const string DATA = ".dat";
}
class DataControl
{
public:
	int _classicalHighScore[10];
	CampaignScore _campaignHighScore[10];
	int _endlessHighScore[10];
	bool readHighScore(string _highScoreFile);
	MapData _map[MAX][MAX];
	string _loseText[50];
	bool readMap(string _mapFile);
	bool readLoseText(string _loseTextFile);
	bool save(int _newScore, GameMode _gameMode, CampaignScore _newCScore = { 0,0 });
};

