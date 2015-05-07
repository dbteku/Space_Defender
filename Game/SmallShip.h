#ifndef SM_SHIP
#define SM_SHIP
#include "Point.h"
#include "Math.h"
#include "Core.h"

using Core::Graphics;
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
	
public:
	SmallShip(int& width, int padding) :
		
		Left(-20, 20),
		topPeak(0, 60),
		Right(20, 20),
		bottomLeft(-15, 0),
		Center(0, 0),

		meBase(random(width, padding), spawnY)
	{}

	void drawThyself(Graphics& g){
		g.SetColor(RGB(0, 255, 0));
		drawLine(g, meBase + Left, meBase + topPeak);
		drawLine(g, meBase + topPeak, meBase + Right);
		drawLine(g, meBase + Left, meBase + Center);
		drawLine(g, meBase + Right, meBase + Center);
		drawLine(g, meBase + Right, meBase + Center);
		g.SetColor(RGB(255, 255, 255));

	}

	void move(){
		velocity.y = 3;
	}

	void act(Graphics& g){
		if (!isDead){
			drawThyself(g);
			move();
		}
		else{
			stop();
		}
	}

	Point getTop(){
		return meBase + topPeak;
	}

	Point getBottom(){
		return meBase + Left;
	}

	Point getLeft(){
		return meBase + Left;
	}

	Point getRight(){
		return meBase + Right;
	}

	void stop(){
		velocity.y = 0;
	}

	void integrate()
	{
		meBase = meBase + velocity;
	}

	void destroy(){
		isDead = true;
	}

	Point getPos(){
		return meBase;
	}

};
#endif SHIP_H