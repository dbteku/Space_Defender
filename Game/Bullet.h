#include "Point.h"

#ifndef BULLET_H
#define BULLET_H
class Bullet{

private:
	Point bottom;
	Point top;
	Point meBase;
	Point velocity;
	bool isAlive = true;

public:
	Bullet(int spawnX, int spawnY):

		bottom(0,0),
		top(0,-15),

		meBase(spawnX, spawnY)
	{}

	void drawThyself(Core::Graphics& g){
		drawLine(g, meBase + top, meBase + bottom);
	}

	void move(){
		velocity.y = -5;
	}

	void act(Core::Graphics& g){
		if (isAlive){
			move();
			integrate();
			drawThyself(g);
		}
		else{
			stop();
		}
	}

	void stop(){
		velocity.y = 0;
	}

	void integrate(){
		meBase = meBase + velocity;
	}

	void destroy(){
		isAlive = false;
	}

	Point getPos(){
		return meBase;
	}

};
#endif BULLET_H