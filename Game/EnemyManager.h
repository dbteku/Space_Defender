#include "Point.h"
#include <vector>
using std::vector;

class EnemyManager{

private:
	vector<SmallShip> ships;

public:

	vector<SmallShip>& getShips(){
		return ships;
	}

};
