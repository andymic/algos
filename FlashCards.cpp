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
	vector<string> filecontent;
	FileHandler(string loc=""):location(loc)
	{
	}
	void ReadFile()
	{
		string line;
		ifstream file(location.c_str(), ifstream::in);
		vector<string> vc;
		if(file.is_open())
		{
			while(getline(file,line))
			{
				vc.push_back(line);
			}
		}
		filecontent=vc;
		file.close();
	}

	vector<string> GetFileContent(){return filecontent;}
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