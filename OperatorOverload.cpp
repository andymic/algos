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
    friend ostream& operator <<(ostream & out, Car & cCar);
    friend istream& operator >>(istream & in, Car & cCar);
 };

class Stats{
private:
    string color;
    long modelnumber;
public:
    Stats(string cl="", long md=0)
    {
        color=cl;
        modelnumber=md;
    }

    friend void Dyno(Car &cCar, Stats &cStats);
    friend ostream& operator <<(ostream & out, Stats & cStats);
    friend istream& operator >>(istream & in, Stats & cStats);
};

void Dyno(Car &cCar, Stats &cStats)
{
   cout<<cCar<<cStats<<endl;
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

ostream& operator <<(ostream & out, Car & cCar)
{
    out<<"Car info:"<<endl;
    out<<"---------"<<endl;
    out<<"Speed: "<<cCar.speed<<endl;
    out<<"Gear: "<<cCar.gear<<endl;

    return out;
}
ostream& operator <<(ostream & out, Stats & cStats)
{
    out<<"Car stats:"<<endl;
    out<<"---------"<<endl;
    out<<"Color: "<<cStats.color<<endl;
    out<<"Model Number: "<<cStats.modelnumber<<endl;

    return out;
}
 istream& operator >>(istream & in, Car & cCar)
 {
    in >> cCar.speed;
    in >> cCar.gear;
    return in;
 }
 istream& operator >>(istream & in, Stats & cStats)
 {
    in >> cStats.color;
    in >> cStats.modelnumber;
    return in;
 }
 int main(void)
 {
    // Car * c= new Car(50,3);
    // Car * x= new Car(50,3);
    // Stats * s= new Stats("Black",123456);
    Car * c= new Car();
    Stats * s= new Stats();

    cout<<"Enter car info:"<<endl;
    cin>>*c;
    cout<<"Enter car stats:"<<endl;
    cin>>*s;
    Dyno(*c,*s);
 
 	return 0;
 }

 