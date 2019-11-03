#pragma once

#include <fstream>
#include <tuple>

class Highscores
{
public:
	Highscores(std::string filePath);

	void LoadScores();
	 
	~Highscores();

private:
	std::tuple<std::string, int> scoreList[5];
	std::ifstream file;
};

