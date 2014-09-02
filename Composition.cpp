#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Map2D
{
private:
	int x, y, dx, dy;

public:
	Map2D(): x(0), y(0)
	{

	}
	Map2D(int cx, int cy):x(cx), y(cy)
	{

	}

	void SetLocation(int ux, int uy)
	{
		x=ux;
		y=uy;
	}

	void SetDestination(int dx=0, int dy=0)
	{
		this->dx=dx;
		this->dy=dy;
	}

	string GetDistance() const
	{
		int tempx=dx-x;
		int tempy=dy-y;
		stringstream sstm;
		sstm<<"Current Distance from destination is x="<<tempx<<" y="<<tempy;
		string distance=sstm.str();
		return distance;
	}
	int GetX() const{return x;}
	int GetY() const{return y;}
	int GetDX() const{return dx;}
	int GetDY() const{return dy;}
	friend ostream& operator<<(ostream& out, const Map2D &map)
	{
		out<<"Current Location: "<<"("<<map.GetX()<<","<<map.GetY()<<")"<<endl;
		out<<"Current Destination: "<<"("<<map.GetDX()<<","<<map.GetDY()<<")"<<endl;
		out<<map.GetDistance()<<endl;
		return out;
	}

	/* data */
};

class Car
{
private:
	Map2D map;
	string carname;
	Car(){}
public:
	Car(string car, const Map2D &location): carname(car), map(location)
	{

	}
	friend ostream& operator<<(ostream& out, const Car &car)
	{
		out<<"Car: "<<car.carname<<endl;
		out<<"---------------"<<endl;
		out<<car.map;
		return out;
	}

	void MoveCar(int x=0, int y=0)
	{
		map.SetLocation(x, y);
	}
	void SetDestination(int x=0, int y=0)
	{
		map.SetDestination(x,y);
	}

	/* data */
};
int main(void)
{
	cout<<"Enter the car make ";
	string name;
	cin>>name;
	Car car(name, Map2D(1,2));

	cout<<"Set car destination"<<endl;
	cout<<"Enter x destination ";
	int dx=0;
	cin>>dx;

	cout<<"Enter y destination ";
	int dy=0;
	cin>>dy;
	car.SetDestination(dx, dy);

	while(1)
	{
		cout<<"Enter -1 to anytime stop!"<<endl;
		cout<<"Enter x of current location ";
		int x=0;
		cin>>x;
		if(x==-1)break;

		cout<<"Enter y  current location ";
		int y=0;
		cin>>y;
		if(y==-1)break;

		cout<<" ";
		car.MoveCar(x,y);
		cout<<car;

	}
	return 0;
}