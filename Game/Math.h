#ifndef MATH_H
#define MATH_H
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

void mathInit(){
	srand(time(0));
}

int random(int number, int padding){
	int result = 0;
	result = (rand() % number);

	if (result < number - number + padding){
		result = random(number, padding);
	}
	else if (result > number - padding){
		result = random(number, padding);
	}
	
	return result;
}

#endif MATH_H