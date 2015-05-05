#include "Point.h"


#ifndef BULLET_H
#define BULLET_H

class Bullet{


private:
	Point top;
	Point bottom;
	Point base;
	float spawn_X = 500;
	float spawn_y =700;
	Point velocity;
	bool noContact = true;


public:

	Bullet() :
		top(450, 70),
		bottom(450, 50),

		base( spawn_X, spawn_y)
	{}


	void integrate()
	{
		base = base + velocity;
	}

	void drawThyself(Core::Graphics& g){
		drawLine(g, base + top, base + bottom);
	}

	void move(){
		velocity.y = 3;
	}


	void stop(){
		velocity.y = 0;
	}


	void act(){
		if (noContact){
			move();
		}
		else{
			stop();

		}

	}


};
#endif BULLET_H