#include "Point.h"
#include <stdlib.h>

#ifndef SHIP_H
#define SHIP_H
struct SmallShip{

	float defaultAcceleration = 1;
	float maxLeftAcceleration = -10;
	float maxRightAcceleration = 10;
	Point Left;
	Point bottomLeft;
	Point Right;
	Point bottomRight;
	Point Center;
	float spawnX = 500;
	float spawnY = 700;
	Point meBase;
	Point velocity;
	
	SmallShip() :
		
		



	{}



};
#endif SHIP_H