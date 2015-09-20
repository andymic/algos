#include <iostream>
#include <string>
 
 using namespace std;

class Stat;

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

    friend void Dyno(Car &cCar, Stat &cStat);
    friend bool operator ==(Car &cCar,Car &xCar);
    friend bool operator >(Car &cCar,Car &xCar);
    friend ostream& operator <<(ostream & out, Car & cCar);
    friend istream& operator >>(istream & in, Car & cCar);
 };

class Stat{
private:
    string color;
    long modelnumber;
public:
    Stat(string cl="", long md=0)
    {
        color=cl;
        modelnumber=md;
    }

    friend void Dyno(Car &cCar, Stats &cStats);
    friend ostream& operator <<(ostream & out, Stat & cStat);
    friend istream& operator >>(istream & in, Stat & cStat);
};

void Dyno(Car &cCar, Stat &cStat)
{
   cout<<cCar<<cStat<<endl;
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
ostream& operator <<(ostream & out, Stat & cStat)
{
    out<<"Car stat:"<<endl;
    out<<"---------"<<endl;
    out<<"Color: "<<cStat.color<<endl;
    out<<"Model Number: "<<cStat.modelnumber<<endl;

    return out;
}
 istream& operator >>(istream & in, Car & cCar)
 {
    in >> cCar.speed;
    in >> cCar.gear;
    return in;
 }
 istream& operator >>(istream & in, Stat & cStat)
 {
    in >> cStat.color;
    in >> cStat.modelnumber;
    return in;
 }
 int main(void)
 {
    // Car * c= new Car(50,3);
    // Car * x= new Car(50,3);
    // Stat * s= new Stat("Black",123456);
    Car * c= new Car();
    Stat * s= new Stat();

    cout<<"Enter car info:"<<endl;
    cin>>*c;
    cout<<"Enter car stat:"<<endl;
    cin>>*s;
    Dyno(*c,*s);
 
 	return 0;
 }

 