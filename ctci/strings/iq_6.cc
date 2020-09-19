#include<iostream>
#include<vector>

//Rotate NxN matrix 90 degrees

void print(std::vector<std::vector<int>> &vect)
{
    for(std::vector<int> &v: vect)
    {
        std::cout<<"|";
        for(int i:v)
        {
           std::cout<<i<<"|"; 
        }
        std::cout<<std::endl;
    }
}

void rotate90_1(std::vector<std::vector<int>> &vect)
{
    int height = vect.size();
    int width = vect.at(0).size();
    std::vector<std::vector<int>> tmp(height, std::vector<int>(width));

    for(int j=0; j<width; j++)
    {
        for(int i=0; i<height; i++)
        {
           tmp[j][i] = vect[i][j];
        }
    }
    vect = tmp;
}

void rotate90_2(std::vector<std::vector<int>> &vect)
{
    int len = vect.size();
    
    for(int cnt=0; cnt<len; cnt++)
    {
        int pos = cnt;
        for(int walker=cnt; walker<len; walker++)
        {
          int tmp = vect[pos][walker];
          vect[pos][walker] = vect[walker][pos];
          vect[walker][pos] = tmp;
        }
    }
}

int main()
{
    std::vector<std::vector<int>> vect {
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4}
    };
    
    std::cout<<"Before:\n";
    print(vect);
    rotate90_2(vect); 
    std::cout<<"After:\n";
    print(vect);
}
