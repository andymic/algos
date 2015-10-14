#include <iostream>
#include <vector>
using namespace std;

class Stack{

public:
Stack(int x)
{
	top = 0;
	len = x;
	min = 0;
	ar = new int[len];
}

void Push(int x)
{
	if(top==len)
		return;

	ar[top++] = x;

	if(x < ar[min])
		min = top -1;
}

int Pop()
{
	if(top==0)
		return -1;

	if(top - 1 == min)
	{
		int currMin = 0;
		for(int i = 1; i < top - 1; i++)
		{
			if(ar[i] < ar[currMin])
				currMin = i;
		}

		min = currMin;
	}

	return ar[--top];
}

int Min()
{
	return ar[min];
}

int GetSize()
{
	return top;
}

int Capacity()
{
	return len;
}

bool IsFull()
{
	return (top == len) ? true : false;
}
void Print()
{
	if(top==0)
		cout<<"empty"<<endl;

	int t = top;

	while(--t >=0)
	{
		cout<<ar[t]<<" ";
	}
	cout<<endl;
}
private:
	int * ar;
	int len;
	int top;
	int min;//assuming stack contains all positive numbers
};

class SetOfStacks
{
	public:
		SetOfStacks(int len)
		{
			stackSize = len;
			stackNo = 0;
			stacks.push_back(Stack(stackSize));
		}

		void Push(int x)
		{
			if(stacks[stackNo].IsFull())
			{
				stacks.push_back(Stack(stackSize));
				stackNo++;
			}

			stacks[stackNo].Push(x);
		}

		int Pop()
		{
			if(stackNo == -1)
				return -1;

			if(stacks[stackNo].GetSize() == 0)
				stackNo--;

			if(stacks[stackNo].GetSize() -1 == 0)
				return stacks[stackNo--].Pop();

			return stacks[stackNo].Pop();
		}

		int PopAt(int stackNum)
		{
			if(stackNo == -1)
				return -1;

			if(stackNum > stackNo)
				return -1;

			return stacks[stackNum].Pop();
		}
		void Print()
		{
			int stNo = stackNo;

			while(stNo >= 0)
			{	
				cout<<"StackNo : "<<stNo<<endl;
				stacks[stNo].Print();
				stNo--;
			}
		}
	private:
		vector<Stack> stacks;
		int stackNo;
		int stackSize;
};

int main(void)
{
	SetOfStacks  stck(10);

	for(int i=0; i<100; i++)
		stck.Push(i);

	stck.Print();

	for(int i=0; i<5; i++)
		cout<<"Element popped :"<<stck.PopAt(3)<<endl;

	stck.Print();

	// stck->Push(-7);
	// //stck->Pop();
	// stck->Print();
	// cout<<"MIN: "<<stck->Min()<<endl;
	// cout<<"Popped eleement: "<<stck->Pop()<<endl;
	// stck->Print();
	// cout<<"MIN: "<<stck->Min()<<endl;
	return 0;
}