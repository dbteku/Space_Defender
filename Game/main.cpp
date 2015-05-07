#include "Dependencies.h"
int width = 1000;
int height = 750;
int gameX = 455;
int gameY = 300;

Ship ship;
Manager manager;
Score s;


void update(){
	manager.update();
}

bool myUpdate(float dt){
	if (!ship.isDead() && !manager.gameOver() && !manager.win()){
		ship.integrate();
		update();
		update(manager, width, height);
	}
	else{
		ShowCursor(TRUE);
	}
	return false;
}

void myDraw(Graphics& graphics){
	if (!ship.isDead() && !manager.gameOver() && !manager.win()){
		s.update(graphics,manager.getScore(),ship.getLives(),manager.getNumShips());
		checkKeyInput(ship, width, height, graphics);
		checkPlayerCollision(ship, manager.getShips());
		checkBulletCollision(ship.getBullets(), manager.getShips(), manager);
		ship.drawThyself(graphics);
		vector<SmallShip>& ships = manager.getShips();
		ship.act(width, height, graphics);
		for (int x = 0; x < ships.size(); x++){
			ships[x].act(graphics);
		}
	}
	else{
		if (manager.gameOver() || ship.isDead()){
			graphics.DrawString(gameX, gameY, "GAME OVER");
		}
		else if (manager.win()){
			graphics.DrawString(gameX, gameY, "YOU WIN!");
		}
	}
}

void main(){
	ShowCursor(FALSE);
	mathInit();
	Core::Init("Space Defender", width, height);
	Core::RegisterUpdateFn(myUpdate);
	Core::RegisterDrawFn(myDraw);
	Core::GameLoop();
}