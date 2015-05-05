#include "Ship.h"
#include <iostream>
#include "SmallShip.h"
#include "EnemyManager.h"
#include "Bullet.h"

using std::vector;
using std::cout;
using std::endl;

int width = 1000;
int height = 750;

Ship ship;
SmallShip enemy;
bullet Bullet;

bool isAtEdge(Point p){
	bool b = false;
	if (p.x >= width){
		b = p.x >= width;
	}
	else if (p.x <= width - width){
		b = p.x <= width - width;
	}
	return b;
}

void checkKeyInput(){

	if (isAtEdge(ship.getPos())){
		ship.stop();
	}
	if (Core::Input::IsPressed(Core::Input::KEY_RIGHT)){
		if (!isAtEdge(ship.getRightPos())){
			if (ship.getRightPos().x <= width){
				ship.goRight();
			}
		}
		else{
			if (ship.getRightPos().x <= width){
				ship.goRight();
			}
			else{
				ship.stop();
			}
		}
	}
	if (Core::Input::IsPressed(Core::Input::KEY_LEFT)){
		if (!isAtEdge(ship.getLeftPos())){
			if (ship.getLeftPos().x >= width - width){
				ship.goLeft();
			}
		}
		else{
			if (ship.getLeftPos().x >= width - width){
				ship.goLeft();
			}
			else{
				ship.stop();
			}
		}
	}
	if (Core::Input::IsPressed(Core::Input::KEY_DOWN)){
		Bullet.move();
	}
}


bool myUpdate(float dt){
	checkKeyInput();
	ship.integrate();
	enemy.integrate();
	enemy.act();
	Bullet.move();
	return false;
}

void checkOutOfBounds(vector<SmallShip>& ships){

}

void myDraw(Core::Graphics& graphics){
	ship.drawThyself(graphics);
	enemy.drawThyself(graphics);
	Bullet.drawThyself(graphics);
	
}

void main(){
	Core::Init("Space Defender", width, height);
	Core::RegisterUpdateFn(myUpdate);
	Core::RegisterDrawFn(myDraw);
	Core::GameLoop();
}