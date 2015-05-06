#ifndef COUNT
#define COUNT
class Counter{
private:
	int counter = 20;
public:

	bool canSpawn(){
		counter--;
		if (counter < -1){
			counter = 100;
		}
		return counter == 0;
	}
};
#endif COUNT