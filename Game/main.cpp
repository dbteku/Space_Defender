#include "Dependencies.h"
int width = 1000;
int height = 750;

Ship ship;
Bullet bullet;
EnemyManager manager;


void update(){
	manager.update();
}

bool myUpdate(float dt){
	checkKeyInput(ship, width, height);
	ship.integrate();
	update();
	updateShips(manager,width,height);
	isOutOfBounds(manager, width, height);
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
	mathInit();
	Core::Init("Space Defender", width, height);
	Core::RegisterUpdateFn(myUpdate);
	Core::RegisterDrawFn(myDraw);
	Core::GameLoop();
}