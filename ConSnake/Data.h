#pragma once
#include "Library.h"
namespace Data
{
	static int _classicalHighScore[10];
	static CampaignScore _campaignHighScore[10];
	static int _endlessHighScore[10];
}
namespace EXTENSION
{
	static const string MAP = ".cmap";
	static const string DATA = ".dat";
}
class DataControl
{
public:
	static bool readHighScore(string _highScoreFile);
	MapData _map[MAX][MAX];
	string _loseText[50];
	bool readMap(string _mapFile);
	bool readLoseText(string _loseTextFile);
	static bool save(int _newScore, GameMode _gameMode, CampaignScore _newCScore = { 0,0 });
};

