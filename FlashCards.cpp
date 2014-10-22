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

struct node
{
	Card card;
	struct node* left;
	struct node* right;
};

struct node *NewNode(Card cCard)
{
	struct node* node=new (struct node);
	node->card=cCard;
	node->left=NULL;
	node->right=NULL;
	return(node);
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

void DecomposeLines(FileHandler fl)
{
	string delimiter=":";

	vector<string> vec =fl.GetFileContent();
	for(vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		string line=*it;
    	if (line != "")
		{
			string word = line.substr(0, line.find(delimiter));
			string definition = line.substr(line.find(delimiter), line.length() - 1);
			cout << word<<definition<< endl;
		}
    }
	
}

int main(void)
{
	Card cd;
	cd.word = "blah";
	cd.definition = "nope";
	cout << cd;

	FileHandler fl("");
	fl.ReadFile();
	DecomposeLines(fl);
	
	
	return 0;
}