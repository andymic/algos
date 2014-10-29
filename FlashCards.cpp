#include <iostream>
#include <string.h>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <vector>
#include "AlphabeticalComp.h"
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

class BinaryTree
{
public:
	BinaryTree();
	static int Search(struct node * node, Card cCard)
	{
		if(node==NULL)
		{
			return -1;
		}
		else
		{
			if(node->card.word==cCard.word)
			{
				return 1;
			}
			else 
			{
				char * _node=const_cast<char*>(node->card.word.c_str());
				char * _card=const_cast<char*>(cCard.word.c_str());

				int decision=CompareWords(_node,_card);

				if(decision==1)
					return(Search(node->right,cCard));
				else if(decision==2)
					return(Search(node->left, cCard));
				else
					return(Search(node->left, cCard));
			}
		}
	}
	~BinaryTree();

	/* data */
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
	//Card cd;
	//cd.word = "blah";
	//cd.definition = "nope";
	//cout << cd;

	FileHandler fl("");
	fl.ReadFile();
	DecomposeLines(fl);
	
	
	return 0;
}