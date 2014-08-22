#include <iostream>
#include <string>
 
 using namespace std;

class Stats;

class Car{
private:
    int speed, gear,horsepower;
public:
    Car(int sp=0, int gr=0, int hp=0)
    {
        speed=sp;
        gear=gr;
        horsepower=hp;
    }

    friend void Dyno(Car &cCar, Stats &cStats);
    friend bool operator ==(Car &cCar,Car &xCar);
    friend bool operator >(Car &cCar,Car &xCar);
 };

class Stats{
private:
    string color;
    long modelnumber;
public:
    Stats(string cl, long md)
    {
        color=cl;
        modelnumber=md;
    }

    friend void Dyno(Car &cCar, Stats &cStats);
};

void Dyno(Car &cCar, Stats &cStats)
{
    cout<<"Car info:"<<endl;
    cout<<"---------"<<endl;
    cout<<"Speed: "<<cCar.speed<<endl;
    cout<<"Gear: "<<cCar.gear<<endl;
    cout<<"Color: "<<cStats.color<<endl;
    cout<<"Model Number: "<<cStats.modelnumber<<endl;
}

bool operator ==(Car &cCar,Car &xCar)
{
    return(cCar.speed==xCar.speed &&
            cCar.gear==xCar.gear);
}
bool operator >(Car &cCar,Car &xCar)
{
    return(cCar.horsepower>xCar.horsepower);
}
 int main(void)
 {
    Car * c= new Car(50,3);
    Car * x= new Car(50,3);
    Stats * s= new Stats("Black",123456);
    Dyno(*c,*s);
 
 	return 0;
 }