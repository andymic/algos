#include <iostream>
#include <string>
using namespace std;

class Card{
public:
	 string word;
	 string definition;
	Card(string w = "", string d = "")
	{
		word = w;
		definition = d;
	}
};

ostream& operator<<(ostream &out, Card & cCard)
{
	out << cCard.word << ": " << cCard.definition << endl;
	return out;
}

istream& operator>>(istream &in, Card & cCard)
{
	in>>cCard.word;
	in>>cCard.definition;
	return in;
}
int main(void)
{
	Card cd;
	cd.word = "blah";
	cd.definition = "nope";
	cout << cd;

	
	return 0;
}