#include "Ship.h"

Ship ship;

void checkKeyInput()
{
	float acceleration = 1;
	if (Core::Input::IsPressed(Core::Input::KEY_RIGHT)){
		ship.velocity.x += acceleration;
	}
	if (Core::Input::IsPressed(Core::Input::KEY_LEFT)){
		ship.velocity.x -= acceleration;
	}
}

bool myUpdate(float dt)
{
	checkKeyInput();
	ship.integrate();
	return false;
}

void myDraw(Core::Graphics& graphics)
{
	ship.drawThyself(graphics);
}

void main()
{
	Core::Init("Space Defender", 1000, 750);
	Core::RegisterUpdateFn(myUpdate);
	Core::RegisterDrawFn(myDraw);
	Core::GameLoop();
}