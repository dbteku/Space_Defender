#include "Point.h"

#ifndef BOUNDARY
#define BOUNDARY

bool isAtEdge(Point& p, int& width, int& height){
	bool b = false;
	if (p.x >= width){
		b = p.x >= width;
	}
	else if (p.x <= width - width){
		b = p.x <= width - width;
	}
	if (p.y >= height){
		b = p.y >= height;
	}
	else if (p.y <= height - height){
		b = p.y <= height - height;
	}
	return b;
}

#endif BOUNDARY