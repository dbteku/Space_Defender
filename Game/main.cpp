#include "Core.h"

struct Point
{
	float x;
	float y;
	Point(float x = 0.0f, float y = 0.0f) :
		x(x), y(y) {}
};

Point operator+(const Point& left, const Point& right)
{
	return Point(left.x + right.x, left.y + right.y);
}

void drawLine(Core::Graphics& g, const Point& left, const Point& right)
{
	g.DrawLine(left.x, left.y, right.x, right.y);
}

struct Ship
{
	Point lowerLeft;
	Point top;
	Point lowerRight;

	Point meBase;
	Point velocity;
	Ship() :
		lowerLeft(-50, 50),
		top(0, -50),
		lowerRight(50, 50),
		meBase(400, 400)
	{}
	void drawThyself(Core::Graphics& g)
	{
		drawLine(g, meBase + lowerLeft, meBase + top);
		drawLine(g, meBase + top, meBase + lowerRight);
		drawLine(g, meBase + lowerRight, meBase + lowerLeft);
	}
	void integrate()
	{
		meBase = meBase + velocity;
	}
};

Ship ship;

void checkKeyInput()
{
	float acceleration = 1;
	if (Core::Input::IsPressed(Core::Input::KEY_UP))
		ship.velocity.y -= acceleration;
	if (Core::Input::IsPressed(Core::Input::KEY_DOWN))
		ship.velocity.y += acceleration;
	if (Core::Input::IsPressed(Core::Input::KEY_RIGHT))
		ship.velocity.x += acceleration;
	if (Core::Input::IsPressed(Core::Input::KEY_LEFT))
		ship.velocity.x -= acceleration;
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
	Core::Init("My Game", 800, 800);
	Core::RegisterUpdateFn(myUpdate);
	Core::RegisterDrawFn(myDraw);
	Core::GameLoop();
}