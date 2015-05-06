#ifndef KEYBOARD
#define KEYBOARD
#include "Ship.h"
#include "Boundary.h"
void checkKeyInput(Ship& ship, int& width, int& height){

	if (isAtEdge(ship.getPos(), width, height)){
		ship.stop();
	}
	if (Core::Input::IsPressed(Core::Input::KEY_RIGHT)){
		if (!isAtEdge(ship.getRightPos(), width, height)){
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
	else if (Core::Input::IsPressed(Core::Input::KEY_LEFT)){
		if (!isAtEdge(ship.getLeftPos(), width, height)){
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
	else{
		ship.slow();
	}
}

#endif KEYBOARD