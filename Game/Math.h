#ifndef MATH_H
#define MATH_H
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

void mathInit(){
	srand(time(0));
}

int random(int number){
	return (rand() % number);
}

#endif MATH_H