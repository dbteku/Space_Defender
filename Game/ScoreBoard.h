#ifndef SCORE
#define SCORE
#include "Core.h"
#include "Manager.h"
#include <string>
#include "Point.h";
using Core::Graphics;
using std::string;
using std::to_string;

class Score{
private:
	Manager m;
	Point score = (0,455);
	Point lives = (0,0);
	Point ships = (0,935);

	void drawScore(Graphics& g, int i){
		string conv = to_string(i);
		string s = "Score: " + conv;
		const char * c = s.c_str();
		g.DrawString(score.x, score.y, c);
	}

	void drawLives(Graphics& g, int i){
		string conv = to_string(i);
		string s = "Lives: " + conv;
		const char * c = s.c_str();
		g.DrawString(lives.x, lives.y, c);
	}

	void drawShips(Graphics& g, int i){
		string conv = to_string(i);
		string s = "Ships: " + conv;
		const char * c = s.c_str();
		g.DrawString(ships.x, ships.y, c);
	}
public:

	void update(Graphics& g, int score, int lives, int ships){
		drawScore(g,score);
		drawLives(g,lives);
		drawShips(g, ships);
	}

};


#endif