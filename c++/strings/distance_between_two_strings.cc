#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int getDistance(string a, string b){
int len_a = a.length();
int len_b = b.length();

if(abs(len_a-len_b) >= 2){
	//we know that the distance is at least two edits away
	return abs(len_a-len_b);
}

if(len_a < len_b){
	//swapping a and b here bc the below logic works on the premise of b being the shorter string
	string tmp = a;
	a = b;
	b=tmp;
	
	int tm = len_a;
	len_a = len_b;
	len_b = tm;
}

vector<char> vc;

sort(a.begin(), a.end());
sort(b.begin(), b.end());

for(int i =0; i<len_a; i++){
	vc.push_back(a[i]);

}

while(len_a>0){
	if(vc.at(len_a-1)==b[len_b-1]){
	 vc.pop_back();
	 len_b--;
	}

	len_a--;
}

return vc.size();
}

int main(void){
	//http://www.geeksforgeeks.org/check-if-two-given-strings-are-at-edit-distance-one/
	string dar [5][2]={
			{"geek","geeks"},
			{"geeks", "geeks"},
			{"geaks", "geeks"},
			{"peaks", "geeks"},
			{"gfg", "gf"}};

	for(int i=0; i<5; i++){
		int dist = getDistance(dar[i][0],dar[i][1]);

		if(dist == 1){
			cout<<"Yes...";
		}
		else{
			cout<<"No...";
		}
		cout<<"Distance between ["<<dar[i][0]<<"] and ["<<dar[i][1]<<"] is "<<dist<<endl;

	}
return 0;
}
