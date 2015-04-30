#include "Core.h"
#ifndef POINT_H
#define POINT_H

struct Point
{
	float x;
	float y;
	Point(float x = 0.0f, float y = 0.0f) :
		x(x), y(y) {}
};

void drawLine(Core::Graphics& g, const Point& left, const Point& right)
{
	g.DrawLine(left.x, left.y, right.x, right.y);
}


Point operator+(const Point& left, const Point& right)
{
	return Point(left.x + right.x, left.y + right.y);
}

#endif // !POINT_H