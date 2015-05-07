#include "Point.h"
#include <vector>
#include "Bullet.h"
#include "Boundary.h"

#ifndef SHIP_H
#define SHIP_H

using std::vector;
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
	vector<Bullet> bullets;
	int maxBullets = 5;
	int lives = 3;
	bool isDeadOrNot = false;
	
	void updateBullets(Core::Graphics& g, int& width, int& height){
		vector<Bullet>& clone = bullets;
		for (int x = 0; x < clone.size(); x++){
				clone[x].act(g);
		}
	}

	void isOutOfBounds(int& width, int& height){
		vector<Bullet>& clone = bullets;
		for (int x = 0; x < clone.size(); x++){
			if (isAtEdge(clone[x].getPos(), width, height)){
				bullets.erase(bullets.begin() + x);
			}
		}
	}

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

	void act(int& width, int& height, Core::Graphics& g){
		updateBullets(g, width, height);
		isOutOfBounds(width, height);

	}

	void stop(){
		velocity.x = 0;
	}

	void slow(){
		if (velocity.x > 0){
			velocity.x--;
		}
		else if (velocity.x < 0){
			velocity.x++;
		}
	}

	void fire(Core::Graphics& g){
		float x = meBase.x;
		float y = meBase.y + gPoint1.y;
		integrate();
		if (bullets.size() < maxBullets){
			Bullet b(x, y);
			b.drawThyself(g);
			b.integrate();
			bullets.push_back(b);
		}
	}

	Point getTop(){
		return meBase + gPoint1;
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

	void integrate()
	{
		meBase = meBase + velocity;
	}

	void loseLife(){
		lives--;
		isDeadOrNot = lives == 0;
		if (lives <= 0){
			lives = 3;
		}
	}

	bool isDead(){
		return isDeadOrNot;
	}

	vector<Bullet>& getBullets(){
		return bullets;
	}
};

#endif SHIP_H