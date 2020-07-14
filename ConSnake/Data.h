#pragma once
#include "Library.h"
namespace Data
{
	static MapData _map[MAX][MAX];
	static string _loseText[50];
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
private:
	static bool readHighScore(string _highScoreFile);
	static bool readLoseText(string _loseTextFile);
public:
	static bool readData(string _mapFile, string _highScoreFile, string _loseTextFile);
	static bool readMap(string _mapFile);
	static bool save(int _newScore, GameMode _gameMode, CampaignScore _newCScore = { 0,0 });
};

