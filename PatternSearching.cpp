#include<iostream>
#include<string.h>

using namespace std;

void patternSearch(char * pattern, char * text)
{
	int ar[100];
	int index = 0;
	int p = strlen(pattern)-1;
	int t = strlen(text);
	for (int i = 0; i < 10; ++i)
	{
		ar[i] = -1;
	}
	for (int e=1, i = 0; i<t; i++)
	{
		char a = pattern[e];
		char b = text[i];
			if (a==b )
			{
				if (e == p)
				{
					ar[index]= i - e;
					e = 0;
					index++;
				}
				else
				{
					e++;
				}
			}
			else
			{
				e = 0;
			}
	}

	int j = 0;
	cout << "Pattern match found starting at index :\n";
	while (ar[j] > 0)
	{
		cout <<j+1<<") "<< ar[j]<<endl;
		j++;
	}

}
int main(void)
{
	cout << "Welcome to pattern searching" << endl;
	cout << "----------------------------" << " Created by Andy Michel: 6/23/2014" << endl;

	 patternSearch("ABABCABAB", "ABABDABACDABABCABAB");
	 cout << "\n";
	return 0;
}

