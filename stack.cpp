#include <iostream>

using namespace std;

class Stack{

public:
Stack(int x)
{
	top = 0;
	len = x;
	ar = new int[len];
}

void Push(int x)
{
	if(top==len)
		return;

	ar[top++] = x;
}

int Pop()
{
	if(top==0)
		return -1;

	return ar[--top];
}

void Print()
{
	if(top-1==0)
		cout<<"empty"<<endl;

	while(--top>=0)
	{
		cout<<ar[top]<<endl;
	}
}
private:
	int * ar;
	int len;
	int top;
};

int main(void)
{
	Stack * stck = new Stack(100);

	for(int i=0; i<20; i++)
		stck->Push(i);
	stck->Pop();
	stck->Print();
	
	return 0;
}