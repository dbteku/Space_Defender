#include "Point.h"
#include "Counter.h"

#ifndef EXPLOSION_H
#define EXPLOSION_H
class  largeExplosion{


private:
	Point topPoint;
	Point botPoint;
	Point leftPoint;
	Point rightPoint;
	Point topLeftPoint;
	Point topRightPoint;
	Point botLeftPoint;
	Point botRightPoint;
	Point base;
	float spawnX = 500;
	float spawnY = 700;

public:
	largeExplosion() :
		topPoint(30, 60),
		botPoint(90, 150),

		leftPoint(0, 100),
		rightPoint(120, 100),

		topLeftPoint(110, 150),
		botRightPoint(11, 50),

		topRightPoint(5, 160),
		botLeftPoint(110, 80),

		base(spawnX, spawnY)

	{}


	void drawThySelf(Core::Graphics & g){
		drawLine(g, base + topPoint, base + botPoint);
		drawLine(g, base + leftPoint, base + rightPoint);
		drawLine(g, base + topLeftPoint, base + botRightPoint);
		drawLine(g, base + topRightPoint, base + botLeftPoint);

	}

	void integrate()
	{
		base = base;
	}


};

class biggestExplosion{

private:
	Point topPoint;
	Point botPoint;
	Point leftPoint;
	Point rightPoint;
	Point topLeftPoint;
	Point topRightPoint;
	Point botLeftPoint;
	Point botRightPoint;
	Point base;
	float spawnX = 500;
	float spawnY = 700;

public:
	biggestExplosion() :
		topPoint(10, 60),
		botPoint(120, 150),

		leftPoint(0, 100),
		rightPoint(140, 100),

		topLeftPoint(130, 170),
		botRightPoint(11, 50),

		topRightPoint(0, 180),
		botLeftPoint(90, 100),

		base(spawnX, spawnY)

	{}


	void drawThySelf(Core::Graphics & g){
		drawLine(g, base + topPoint, base + botPoint);
		drawLine(g, base + leftPoint, base + rightPoint);
		drawLine(g, base + topLeftPoint, base + botRightPoint);
		drawLine(g, base + topRightPoint, base + botLeftPoint);

	}

	void integrate()
	{
		base = base;
	}




};


class Explosion{
	largeExplosion lExplosion;
	biggestExplosion bExplosion;
	Counter count;
	Counter count1;
	Counter count2;
	

private:
	int runCount = 100;
	Point topPoint;
	Point botPoint;
	Point leftPoint;
	Point rightPoint;
	Point topLeftPoint;
	Point topRightPoint;
	Point botLeftPoint;
	Point botRightPoint;
	Point base;
	float spawnX = 500;
	float spawnY = 700;

public:
	Explosion() :
		topPoint(60,60),
		botPoint(60,150),

		leftPoint(20,100),
		rightPoint(100,100),


		topLeftPoint(90,130),
		botRightPoint(33, 70),

		topRightPoint(25,140),
		botLeftPoint(90,60),
		
		base(spawnX,spawnY)

	{}


	void drawThySelf(Core::Graphics & g){
		drawLine(g, base + topPoint, base + botPoint);
		drawLine(g, base + leftPoint, base + rightPoint);
		drawLine(g, base + topLeftPoint, base + botRightPoint);
		drawLine(g, base + topRightPoint, base + botLeftPoint);
		
	}

	void integrate()
	{
		base = base;
	}

	void explosionAct(Core::Graphics& graphics){
		if (count.explosionDelay()){
			drawThySelf(graphics);
			if (count1.explosionDelay()){
				lExplosion.drawThySelf(graphics);
				if (count2.explosionDelay()){
					bExplosion.drawThySelf(graphics);
				}
			}
		}
		
	}

};


#endif EXPLOSION_H

