#include <iostream>
#include <string.h>
#include <map> 
using namespace std;

void Swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int * Rotate(int * ar, int len, int steps)
{
    /*Rotate an array of (n=len) elements to the right by (k=steps) steps.*/
    int * temp = new int[steps];

    for(int i =0; i<steps; i++)
        temp[i] = ar[i];

    for(int i = steps; i<len; i++)
        ar[i - steps] = ar[i];

    for(int i = len-steps, h = 0; i<len; i++, h++)
        ar[i] = temp[h];

    delete [] temp;
    return ar;
}

bool Isomorphic(string a, string b)
{
    if(a.length() != b.length())
        return false;

    if(a.length() == 0 && b.length() == 0)
        return true;

    map<char, char> chars;

    for(int i = 0; i<a.length(); i++)
    {
        char ac = a[i];
        char bc = b[i];

        if(chars.find(ac) != chars.end())
        {
            if(chars.find(ac)->second != bc)
                return false;
        }
        else
        {
            chars[ac] = bc;
        }
    }
    return true;
}
//////////////////////////////////////////////////////////////////Driver functions////////////////////////////////////////////////////////////////////
void RotateTest()
{
    int ar[7]= {1,2,3,4,5,6,7};

    int * b = Rotate(ar, 7, 3);

    for(int i = 0; i<7; i++)
        cout<<b[i]<<" ";

    cout<<endl;
}
int main(void)
{ 
    cout<<Isomorphic("foo", "bar");
    return 0;
}

 