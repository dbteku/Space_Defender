#ifndef COUNT
#define COUNT
class Counter{
private:
	int counter = 20;
	int exploCounter = 30;
public:

	bool canSpawn(){
		counter--;
		if (counter < -1){
			counter = 100;
		}
		return counter == 0;
	}
	bool explosionDelay(){
		exploCounter--;
		if (exploCounter < -1){
			exploCounter = 30;
		}
		return exploCounter == 0;
	}
};
#endif COUNT;