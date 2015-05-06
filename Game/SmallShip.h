#include "Point.h"
#include "Math.h"

#ifndef SM_SHIP
#define SM_SHIP
class SmallShip{

private:
	Point Left;
	Point bottomLeft;
	Point Right;
	Point topPeak;
	Point Center;
	float spawnY = 25;
	Point meBase;
	Point velocity;
	bool isDead = false;
	bool isMoving = true;
	
public:
	SmallShip(int& width, int padding) :
		
		Left(-20, 20),
		topPeak(0, 60),
		Right(20, 20),
		bottomLeft(-15, 0),
		Center(0, 0),

		meBase(random(width, padding), spawnY)
	{}

	void drawThyself(Core::Graphics& g){
		drawLine(g, meBase + Left, meBase + topPeak);
		drawLine(g, meBase + topPeak, meBase + Right);
		drawLine(g, meBase + Left, meBase + Center);
		drawLine(g, meBase + Right, meBase + Center);
		drawLine(g, meBase + Right, meBase + Center);

	}

	void move(){
		velocity.y = 3;
	}

	void act(){
		if (isMoving){
			move();
		}
		else{
			stop();
		}
	}

	void stop(){
		velocity.y = 0;
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