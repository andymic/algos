#include <iostream>

using namespace std;

class Elevator{
private:
int maxFloors;
int currentFloor;

public:
	Elevator(int floors)
	{
		maxFloors = floors;
		currentFloor = 0;
	}

	void GoUp()
	{
		if(currentFloor < maxFloors)
			currentFloor++;

		cout<<"Current floor :"<<currentFloor<<endl;
	}

	void GoDown()
	{
		if(currentFloor <= 1)
			currentFloor--;

		cout<<"Current floor :"<<currentFloor<<endl;
	}

	void JumpUp(int steps)
	{
		if(steps < 0)
			return;

		if((currentFloor + steps) > maxFloors)
			currentFloor = maxFloors;
		else
			currentFloor += steps;

		cout<<"Current floor :"<<currentFloor<<endl;
	}

	void JumpDown(int steps)
	{
		if(steps < 0)
			return;

		if((currentFloor - steps) < 0)
			currentFloor = 0;
		else
			currentFloor-= steps;

		cout<<"Current floor :"<<currentFloor<<endl;

	}
};

int main(void)
{
	Elevator * v = new Elevator(10);

	v->GoUp();
	v->JumpUp(4);

	v->JumpDown(7);
	return 0;
}