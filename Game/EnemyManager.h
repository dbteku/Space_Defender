#include "Point.h"
#include <vector>
#include <algorithm>
#include "Boundary.h"
#include <iostream>
#include "Counter.h"
using std::vector;
using std::remove;
using std::begin;

class EnemyManager{

private:
	vector<SmallShip> ships;
	short maxShips = 5;
	Counter counter;
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
			ships[x].act();
		}
	}

	short getMaxShips(){
		return maxShips;
	}

	bool canSpawn(){
		return counter.canSpawn();
	}

	int getPadding(){
		return padding;
	}

};


void updateShips(EnemyManager& manager, int& width, int& height){
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

void isOutOfBounds(EnemyManager& manager,int& width, int& height){
	vector<SmallShip>& clone = manager.getShips();
	for (int x = 0; x < clone.size(); x--){
		if (isAtEdge(clone[x].getPos(), width, height)){
			manager.remove(x);
		}
	}
}
