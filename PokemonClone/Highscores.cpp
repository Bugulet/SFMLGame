#include "Highscores.h"



Highscores::Highscores(std::string filePath)
{
	file.open(filePath);
}

void Highscores::LoadScores() {
	////we can read it
	//if (!file.bad()) {


	//	char *name, *score;

	//	while (!file.eof()) {
	//		file.getline(name, 255, ' ');
	//		//file.getline(score, 255, 'n');

	//	}
	//}
}


Highscores::~Highscores()
{
}
