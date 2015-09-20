#ifndef AlphabeticalComp_H
#define AlphabeticalComp_H
#include <map>
using namespace std;

void RankLetter();
int CompareWords(char* source, char* target);

typedef map<char, int> Ranking;
Ranking ranks;

void RankLetter()
{
	ranks.insert(std::make_pair('a',0));
	ranks.insert(std::make_pair('b',1));
	ranks.insert(std::make_pair('c',2));
	ranks.insert(std::make_pair('d',3));
	ranks.insert(std::make_pair('e',4));
	ranks.insert(std::make_pair('f',5));
	ranks.insert(std::make_pair('g',6));
	ranks.insert(std::make_pair('h',7));
	ranks.insert(std::make_pair('i',8));
	ranks.insert(std::make_pair('j',9));
	ranks.insert(std::make_pair('k',10));
	ranks.insert(std::make_pair('l',11));
	ranks.insert(std::make_pair('m',12));
	ranks.insert(std::make_pair('n',13));
	ranks.insert(std::make_pair('o',14));
	ranks.insert(std::make_pair('p',15));
	ranks.insert(std::make_pair('q',16));
	ranks.insert(std::make_pair('r',17));
	ranks.insert(std::make_pair('s',18));
	ranks.insert(std::make_pair('t',19));
	ranks.insert(std::make_pair('w',20));
	ranks.insert(std::make_pair('x',21));
	ranks.insert(std::make_pair('y',22));
	ranks.insert(std::make_pair('z',23));
}

int CompareWords(char* source, char* target)
{
	RankLetter();
	int len=0;
	if(strlen(source)>strlen(target))
		len=strlen(target);
	else
		len=strlen(source);

	for(int i=0; i<len; i++)
	{
		int temp_source, temp_target;

		temp_source=ranks.find(source[i])->second;
		temp_target=ranks.find(target[i])->second;
		if(temp_source<temp_target)//source alphabetically comes first
			return 1;
		else if(temp_target<temp_source)//target alphabetically comes first
			return 2;
	}

	return 0;//they are equal
}

#endif