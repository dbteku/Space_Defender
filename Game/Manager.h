#ifndef MANAGER
#define MANAGER
#include "Point.h"
#include <vector>
#include <algorithm>
#include "Boundary.h"
#include <iostream>
#include "Counter.h"
#include "Math.h"
#include "Core.h"
#include <string>
#include "Bullet.h"
using std::vector;
using std::remove;
using std::begin;

class Manager{

private:
	vector<SmallShip> ships;
	short maxShips = 5;
	short maxBullets = 7;
	Counter counter;
	Counter bulletTimer;
	int padding = 30;
public:

	vector<SmallShip>& getShips(){
		return ships;
	}

	void add(SmallShip& ship){
		ships.push_back(ship);
	}

	void remove(int x){
		ships.erase(ships.begin() + x);
	}

	void update(){
		for (int x = 0; x < ships.size(); x++){
			ships[x].integrate();
		}
	}

	short getMaxShips(){
		return maxShips;
	}

	bool canSpawn(){
		return counter.isReady();
	}

	int getPadding(){
		return padding;
	}

};


void updateShips(Manager& manager, int& width, int& height){
	vector<SmallShip>& ships = manager.getShips();
	bool canSpawn = manager.canSpawn();
	if (ships.size() < manager.getMaxShips()){
		int difference = 0;
		difference = manager.getMaxShips() - ships.size();
			if (canSpawn){
				if (difference > 0){
					SmallShip s(width, manager.getPadding());
					manager.add(s);
				}
		}
	}
}

void isOutOfBounds(Manager& manager,int& width, int& height){
	vector<SmallShip>& clone = manager.getShips();
	for (int x = 0; x < clone.size(); x--){
		if (isAtEdge(clone[x].getPos(), width, height)){
			manager.remove(x);
		}
	}
}

void update(Manager& manager, int& width, int& height){

	updateShips(manager, width, height);
	isOutOfBounds(manager, width, height);
}

bool isColliding(Ship& ship, SmallShip enemy){
	bool isColliding = false;
	if (inBetween(ship.getTop().y, enemy.getBottom().y, enemy.getTop().y)){

		isColliding = inBetween(enemy.getLeft().x, ship.getLeft().x, ship.getRight().x) || inBetween(enemy.getRight().x, ship.getLeft().x, ship.getRight().x);

	}
	else if (inBetween(ship.getBottom().y, enemy.getBottom().y, enemy.getTop().y)){
		isColliding = inBetween(enemy.getLeft().x, ship.getLeft().x, ship.getRight().x) || inBetween(enemy.getRight().x, ship.getLeft().x, ship.getRight().x);
	}
	return isColliding;
}

bool isHitting(Bullet b, SmallShip enemy){
	bool isColliding = false;
	if (inBetween(b.getPos().y, enemy.getBottom().y, enemy.getTop().y)){

		isColliding = inBetween(b.getPos().x, enemy.getLeft().x, enemy.getRight().x) || inBetween(b.getPos().x, enemy.getLeft().x, enemy.getRight().x);

	}
	else if (inBetween(b.getPos().y, enemy.getBottom().y, enemy.getTop().y)){
		isColliding = inBetween(b.getPos().x, enemy.getLeft().x, enemy.getRight().x) || inBetween(b.getPos().x, enemy.getLeft().x, enemy.getRight().x);
	}
	return isColliding;
}

void checkPlayerCollision(Ship& ship, vector<SmallShip>& ships){
	vector<SmallShip>& clone = ships;
	for (int x = 0; x < clone.size(); x++){
		if (isColliding(ship, clone[x])){
			ship.loseLife();
			clone[x].destroy();
			ships.erase(ships.begin() + x);
		}
	}
}


void checkBulletCollision(vector<Bullet>& bullets, vector<SmallShip>& ships){
	vector<SmallShip>& clone = ships;
	vector<Bullet>& bulletClone = bullets;
	for (int x = 0; x < clone.size(); x++){
		for (int i = 0; i < bulletClone.size(); i++){
			if (isHitting(bulletClone[i], clone[x])){
				clone[x].destroy();
				bulletClone[i].destroy();
				bullets.erase(bullets.begin() + i);
				ships.erase(ships.begin() + x);
			}
		}

	}
}

#endif MANAGER