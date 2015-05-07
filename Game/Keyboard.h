#ifndef KEYBOARD
#define KEYBOARD
#include "Ship.h"
#include "Boundary.h"

bool isSpacePressed = false;

void checkKeyInput(Ship& ship, int& width, int& height, Core::Graphics& g){

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

	if (Core::Input::IsPressed(Core::Input::BUTTON_SPACE)){
		if (!isSpacePressed){
			ship.fire(g);
			isSpacePressed = true;
		}
	}
	else{
		isSpacePressed = false;
	}
}

#endif KEYBOARD