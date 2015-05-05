#include "Point.h"
#include <vector>
#include <algorithm>
using std::vector;
using std::find;

class EnemyManager{

private:
	vector<SmallShip> ships;

public:

	vector<SmallShip>& getShips(){
		return ships;
	}

	void add(SmallShip& ship){
		ships.push_back(ship);
	}

	void remove(SmallShip& ship){

		for (int x = 0; x < ships.size(); x++){

		}
		//int pos = find(ships.begin(), ships.end(), ship) - ships.begin;
		//if (pos < ships.size()){
		//	ships.erase(ships.begin() + pos);
		//}
	}

	void update(){
		for (int x = 0; x < ships.size(); x++){
			ships[x].integrate();
			ships[x].act();
		}
	}

};
