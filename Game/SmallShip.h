#include "Point.h"

#ifndef SM_SHIP
#define SM_SHIP
struct SmallShip{

	float defaultAcceleration = 1;
	float maxLeftAcceleration = -10;
	float maxRightAcceleration = 10;
	Point Left;
	Point bottomLeft;
	Point Right;
	Point topPeak;
	Point Center;
	float spawnX = 500;
	float spawnY = 25;
	Point meBase;
	Point velocity;
	
	SmallShip() :
		
		Left(-20, 20),
		topPeak(0, 60),
		Right(20, 20),
		bottomLeft(-15, 0),
		Center(0, 0),

		meBase(spawnX, spawnY)
	{}

	void drawThyself(Core::Graphics& g)
	{
		drawLine(g, meBase + Left, meBase + topPeak);
		drawLine(g, meBase + topPeak, meBase + Right);
		drawLine(g, meBase + Left, meBase + Center);
		drawLine(g, meBase + Right, meBase + Center);
		drawLine(g, meBase + Right, meBase + Center);

	}

	void integrate()
	{
		meBase = meBase + velocity;
	}

	Point getPos(){
		return meBase;
	}

};
#endif SHIP_H