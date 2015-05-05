#include "Point.h"


#ifndef BULLET_H



class bullet{


private:
	Point top;
	Point bottom;
	Point base;
	float spawn_X = 500;
	float spawn_y =700;
	Point velocity;
	bool hitContact;
	bool noContact;


public:

	bullet() :
		top(450, 70),
		bottom(450, 50),

		base( spawn_X, spawn_y)
	{}



	void drawThyself(Core::Graphics& g){
		drawLine(g, base + top, base + bottom);
	}

	void move(){
		velocity.y = -7;
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