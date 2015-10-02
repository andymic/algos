#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdlib.h>  
using namespace std;

char * RemoveDuplicates(char * s)
{
    bool * hash= new bool[256];

    for(int i=0; i<256; i++)
    {
        hash[i]=false;
    }
    string res="";

    int length=strlen(s);

    for(int i=0; i<length; i++)
    {
        int temp=s[i];
        if(!hash[temp])
        {
            hash[temp]=true; 
            res+=s[i];
        }          
    }

    return (char *)&res[0];
}
void swap(char * a, char * b)
{
    char temp = *a;
    *a = *b;
    *b=temp;
}
void Permutate(char *a, int start, int len)
{
    int i;

    if(start == len)
        cout<<a<<endl;
    else
    {
        for(i = start; i<len; i++)
        {
            swap((a+start), (a+i));
            Permutate(a, start+1, len);
            swap((a+start), (a+i));
        }
    }
}

void BubbleSort(char * s, int len)
{
    //Runtime: On^2
    bool sorted;
    
    for(int a = 1; a<len-1; a++)
    {
        sorted = false;
        for( int i = 0; i<=len-a-1; i++)//avoids redudndant pass over sorted elements
        {
            if(s[i] > s[i+1])
            {
                swap(s[i], s[i+1]);
                sorted = true;
            }
        }
        
        if(!sorted)break; //avoids unecessary passes if string is already sorted
    }
}

void SelctionSort(char * s, int len)
{
    //swaps in place the current min vs the actual min
    for (int i = 0; i < len - 1; i++)
    {
        int  min = i;
        for (int m = i + 1; m<len ; m++)
        {
            if (s[m]<s[min])
                min = m;
        }

        swap(s[i], s[min]);
    }
}

void InsertionSort(char * s, int len)
{
    for(int i = 1; i<len; i++)
    {
        int val = s[i];
        int index = i;

        while(index > 0 && s[index - 1] > val)
        {
            s[index] = s[index - 1];
            index--;
        }

        s[index] = val;
    }
}

bool IsAnagram(string a, string b)
{   
    if(a.length() != b.length())
        return false;

    InsertionSort((char *)&a[0], a.length());
    InsertionSort((char *)&b[0], b.length());

    for(int i = 0; i<a.length(); i++)
    {
        if(a[i] != b[i])
            return false;
    }

    return true;
}

void ReverseWord(char * s, int start, int end)
{
    int len = (end - start)/2;

    for(int i = 0; i<len; i++)
    {
        char temp = s[start];
        s[start] = s[end -1];
        s[end - 1] = temp;

        start++;
        end--;
    }
}

char * ReverseWordsInString(char * s, char delimiter)
{
    int len = strlen(s);
    int startseg = 0;
    int endseg = 0;

    for (int i = 0; i<len; i++)
    {
        if (s[i] == delimiter || s[i+1] == '\0')
        {
            ReverseWord(s, startseg, startseg + endseg);
            startseg = i + 1;
            endseg = 0;
        }
        else
        {
            endseg++;
        }
        
    }
    return s;
}

bool IsPalindrome(char * s)
{
    int len = strlen(s);

    for(int i = 0, h = len-1; i<len-1; i++, h--)
    {
        if(s[i] != s[h])
            return false;
    }

    return true;
}

void RemoveFromString(string &s, char * chars)
{
    for(int i = 0; i<strlen(chars); i++)
    {
        s.erase(remove(s.begin(), s.end(), chars[i]), s.end());
    }
}

bool SpellChecker(string a, string b)
{
    /*Problem found at:http://mycodeschool.com/problems/spell-checker
    First line of input will contain an integer T = number of test cases. Next T lines 
    will each contain two strings comprising only of lower case English letters separated
     by space. Strings are compared by these rules designed by Mr. X : 

    1) All the vowels plus letter 'y' - set of characters: { 'a', 'e' , 'i', 'o', 'u', 'y' }
     are removed from both the strings if they are present at any index other than 0. First 
     letter is not removed even if its a vowel or 'y'. 

    2) Two strings are similar and can be suggested for each other if the
     first characters after modification by rule 1 are same and remaining 
     characters after modification are not different at more than 2 positions.
     If resulting strings after applying rule 1 are of unequal length, 
     all the extra indices in larger string should be counted as having different characters.
       e.g: if we get "bcd" and "bkd" after applying rule 1, they differ at one position. 
     "pqrs" and "pq" differ at 2 positions, (extra positions in "pqrs")
     */

    char letter [6] = { 'a', 'e' , 'i', 'o', 'u', 'y' };   
    int pos;
    char pholder = '-';
    for(int i = 0; i<6; i++)
    {
        while((pos = a.find(letter[i])) > 0)
        {
            a[pos] = pholder;
        }

        while((pos = b.find(letter[i])) > 0)
        {
            b[pos] = pholder;
        }
    }

    RemoveFromString(a, (char*)&pholder);
    RemoveFromString(b, (char*)&pholder);

    if(abs((int)(a.length() - b.length())) > 2)
        return false;

    int diff = abs((int)(a.length() - b.length()));

    int len;

    if(a.length() < b.length())
    {
        len = a.length();
        for(int i = 0; i<len; i++)
        {
            if(diff > 2)
                return false;

            if(a[i] != b[i] && i == 0)
                return false;
            else if(a[i] != b[i])
                diff++;
        }
    }
    else
    {
        len = b.length();
        for(int i = 0; i<len; i++)
        {
            if(diff > 2)
                return false;

            if(a[i] != b[i] && i == 0)
                return false;
            else if(a[i] != b[i])
                diff++;
        }
    }

    return true;
}
int main(void)
{
    cout<<SpellChecker("contest","test")<<endl;
    return 0;
}

 