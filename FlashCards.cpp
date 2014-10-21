#include <iostream>
#include <string.h>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <vector>
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

class FileHandler{
public:
	const string location;

	FileHandler(string loc=""):location(loc)
	{
	}
	void ReadFile()
	{
		string line;
		ifstream file(location.c_str(), ifstream::in);
		std::vector<string> vc;
		if(file.is_open())
		{
			while(getline(file,line))
			{
				vc.push_back(line);
			}
		}

		for(int i=0; i<vc.size(); i++)
		{
			cout<<vc[i]<<endl;
		}
		file.close();
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

	FileHandler fl("");
	fl.ReadFile();

	
	return 0;
}