#ifndef KEYBOARD
#define KEYBOARD
#include "Ship.h"
#include "Boundary.h"
#include "Core.h"

using Core::Graphics;
using Core::Input;

bool isSpacePressed = false;

void checkKeyInput(Ship& ship, int& width, int& height, Graphics& g){

	if (isAtEdge(ship.getPos(), width, height)){
		ship.stop();
	}
	if (Input::IsPressed(Input::KEY_RIGHT)){
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
	else if (Input::IsPressed(Input::KEY_LEFT)){
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

	if (Input::IsPressed(Input::BUTTON_SPACE)){
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