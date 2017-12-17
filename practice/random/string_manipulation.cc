#include <iostream>
#include <string.h>

void permutation(std::string val, int left, int right){
	if(left==right)
		std::cout<<val<<std::endl;
	else{
		for(int i=left; i<right; i++){
			std::swap(val[left], val[i]);
			permutation(val, left+1, right);
			std::swap(val[left], val[i]);
		}
	}
}

int main(void){
	std::string s ="abc";
	permutation(s,0,s.length());	
	return 0;
}
