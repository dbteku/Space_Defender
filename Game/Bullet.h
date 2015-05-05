#include "Point.h"

#ifndef BULLET_H
#define BULLET_H
class Bullet{

private:
	Point bottom;
	Point top;
	float spawnX = 500;
	float spawnY = 55;
	Point meBase;
	Point velocity;

public:
	Bullet():

		bottom(0,0),
		top(0,-15),

		meBase(spawnX, spawnY)
	{}

	void drawThyself(Core::Graphics& g){
		drawLine(g, meBase + top, meBase + bottom);
	}

	void move(){
		velocity.y = 3;
	}

	void act(){

	}

	void stop(){
		velocity.y = 0;
	}

	void integrate(){
		meBase = meBase + velocity;
	}

	Point getPos(){
		return meBase;
	}

};
#endif BULLET_H