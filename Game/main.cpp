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
	Point Left;
	Point bottomLeft;
	Point Right;
	Point bottomRight;
	Point Center;
	Point Gun1;
	Point Gun2;
	Point gPoint1;
	Point gPoint2;
	

	Point meBase;
	Point velocity;
	Ship() :
		Left(-40, 40),
		bottomRight(0, -40),
		Right(40, 40),
		bottomLeft(-5,0),
		Center(0,0),
		Gun1(0,-50),
		
		gPoint1(0,-35),
		
		meBase(400, 400)
	{}
	void drawThyself(Core::Graphics& g)
	{
		drawLine(g, meBase + Left, meBase + bottomRight);
		drawLine(g, meBase + bottomRight, meBase + Right);
	 
		//drawLine(g, meBase + bottomLeft, meBase + Left);
		drawLine(g, meBase + Left, meBase + Center);
		drawLine(g, meBase + Right, meBase + Center);
		drawLine(g, meBase + Right, meBase + Center);
		drawLine(g, meBase + gPoint1, meBase + Gun1);
		


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
	Core::Init("Space Defender", 1000, 750);
	Core::RegisterUpdateFn(myUpdate);
	Core::RegisterDrawFn(myDraw);
	Core::GameLoop();
}