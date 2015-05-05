#include "Point.h"

#ifndef SHIP_H
#define SHIP_H
class Ship
{

private:
	float defaultAcceleration = 1;
	float maxLeftAcceleration = -10;
	float maxRightAcceleration = 10;
	Point Left;
	Point bottomLeft;
	Point Right;
	Point bottomRight;
	Point Center;
	Point Gun1;
	Point Gun2;
	Point gPoint1;
	Point gPoint2;
	float spawnX = 500;
	float spawnY = 700;
	Point meBase;
	Point velocity;

public:
	Ship() :
		Left(-40, 40),
		bottomRight(0, -40),
		Right(40, 40),
		bottomLeft(-5, 0),
		Center(0, 0),
		Gun1(0, -50),
		gPoint1(0, -40),

		meBase(spawnX, spawnY)
	{}
	void drawThyself(Core::Graphics& g)
	{
		drawLine(g, meBase + Left, meBase + bottomRight);
		drawLine(g, meBase + bottomRight, meBase + Right);
		drawLine(g, meBase + Left, meBase + Center);
		drawLine(g, meBase + Right, meBase + Center);
		drawLine(g, meBase + Right, meBase + Center);
		drawLine(g, meBase + gPoint1, meBase + Gun1);

	}

	Point getPos(){
		return meBase;
	}

	Point getLeftPos(){
		return meBase + Left;
	}

	Point getRightPos(){
		return meBase + Right;
	}

	void goLeft(){
		if (velocity.x > maxLeftAcceleration){
			velocity.x -= defaultAcceleration;
		}
	}

	void goRight(){
		if (velocity.x < maxRightAcceleration){
			velocity.x += defaultAcceleration;
		}
	}

	void act(){

	}

	void stop(){
		velocity.x = 0;
	}

	void integrate()
	{
		meBase = meBase + velocity;
	}
};

#endif SHIP_H