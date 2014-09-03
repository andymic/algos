#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static int frequencies[256];
void CalcFrequencies( char * buffer)
{
	for(int i=0; i<4096; i++)
	{
		frequencies[buffer[i]]++;
	}
}

bool OpenNRead()
{
	string line;
	ifstream file("");
	char * buffer=new char[4096];

	for(int i=0; i<256; i++)
	{
		frequencies[i]=0;
	}
	
	if(file.is_open())
	{
		 while ( getline (file,line) )
	     {

	      strncpy(buffer, line.c_str(), 4096);
	      CalcFrequencies(buffer);
	     }
	     file.close();
    }
    else
    {
    	cout << "Unable to open file";
    	return false;
    } 

  delete [] buffer;
  return true;
}

int main(void)
{
	 OpenNRead();
	return 0;
}