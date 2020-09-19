#include<iostream>
#include<vector>

//Write an algo such that if an element in an
//MxN matrix is 0, it's entire row and column
//is set to 0. 

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

void setToZero(std::vector<std::vector<int>> &vect)
{
    int i = vect.size();
    int j = vect.at(0).size();
    std::vector<std::vector<int>> tmp(i,std::vector<int>(j,-1));

    for(int h =0; h<i; h++)
    {
        for(int w = 0; w<j; w++)
        {
            if(vect[h][w] == 0)
            {
                for(int walker = 0; walker<i; walker++)
                    tmp[walker][w] = 0;
                for(int walker = 0; walker<j; walker++)
                    tmp[h][walker] = 0;
            }
            else if(tmp[h][w] != 0)
            {
               tmp[h][w] = vect[h][w];
            }
        }
    } 
   vect = tmp; 
}


int main()
{
    std::vector<std::vector<int>> vect {
        {1,2,3,4},
        {1,0,3,4},
        {1,2,3,4},
        {1,2,3,4},
        {1,2,0,4},
        {1,2,3,4}
    };
    
    std::cout<<"Before:\n";
    print(vect);
    setToZero(vect); 
    std::cout<<"After:\n";
    print(vect);
}
