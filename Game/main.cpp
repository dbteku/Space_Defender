#include "Dependencies.h"
int width = 1000;
int height = 750;

Ship ship;
Manager manager;


void update(){
	manager.update();
}

bool myUpdate(float dt){
	if (!ship.isDead()){
		ship.integrate();
		update();
		update(manager, width, height);
	}
	return false;
}

void myDraw(Core::Graphics& graphics){
	if (!ship.isDead()){
		checkKeyInput(ship, width, height, graphics);
		checkPlayerCollision(ship, manager.getShips());
		checkBulletCollision(ship.getBullets(), manager.getShips());
		ship.drawThyself(graphics);
		vector<SmallShip>& ships = manager.getShips();
		ship.act(width, height, graphics);
		for (int x = 0; x < ships.size(); x++){
			ships[x].act(graphics);
		}
	}
}

void main(){
	mathInit();
	Core::Init("Space Defender", width, height);
	Core::RegisterUpdateFn(myUpdate);
	Core::RegisterDrawFn(myDraw);
	Core::GameLoop();
}