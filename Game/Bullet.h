#ifndef BULLET_H
#define BULLET_H
#include "Point.h"
#include "Core.h"

using Core::Graphics;
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

	void drawThyself(Graphics& g){
		g.SetColor(RGB(255,0,0));
		drawLine(g, meBase + top, meBase + bottom);
		g.SetColor(RGB(255,255,255));
	}

	void move(){
		velocity.y = -5;
	}

	void act(Graphics& g){
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