#pragma once
#include "Player.h"
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "Game.h"
class Player : public Game
{
private:
	string playerName;
	int scores;
public:
	Player();
	string getPlayerName();
	int getScores();
	void setScores();
	void setPlayerName(string);
	friend bool operator < (Player &, Player &);
	void docFile(ifstream &filein);
	void ghiFile(fstream &filein,Player X);
	void Run();
	~Player();
};

