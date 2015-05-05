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
Bullet bullet;
EnemyManager manager;

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
}

void update(){
	manager.update();
}

bool myUpdate(float dt){
	checkKeyInput();
	ship.integrate();
	update();
	return false;
}

void myDraw(Core::Graphics& graphics){
	ship.drawThyself(graphics);
	vector<SmallShip>& ships = manager.getShips();
	for (int x = 0; x < ships.size(); x++){
		ships[x].drawThyself(graphics);
	}
	
}

void main(){
	manager.add(enemy);
	Core::Init("Space Defender", width, height);
	Core::RegisterUpdateFn(myUpdate);
	Core::RegisterDrawFn(myDraw);
	Core::GameLoop();
}