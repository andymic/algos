#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//Given two arrays/Lists (choose whatever you want to) with sorted and non intersecting intervals. Merge them to get a new sorted non intersecting array/list.
struct Interval{
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

static bool comparator(Interval a, Interval b){
    return a.start < b.start;
}


vector<Interval> merge_lists(vector<Interval> first, vector<Interval> second){


    for(int i=0; i<second.size(); i++){
        first.push_back(second[i]);
    }

    sort(first.begin(), first.end(), comparator);
    int last = 0;

    for(int i=1; i<first.size(); i++){
        if(first.at(last).start == -1 && first.at(last).end == -1){
            last++;
        }
        else if(first.at(i).start < first.at(last).end && first.at(i).end < first.at(last).end){
            first.at(i).start = -1;
            first.at(i).end = -1;
        }
        else if(first.at(i).start < first.at(last).end && first.at(i).end > first.at(last).end){
            first.at(last).end = first.at(i).end;
            first.at(i).start = -1;
            first.at(i).end = -1;
        }
    }

    for(vector<Interval>::iterator it=first.begin(); it!=first.end(); ){
        if(it->start == -1 && it->end == -1){
            it = first.erase(it);
        }else{
            it++;
        }
    }

    return first;
}

int main(void){
    vector<Interval> first = {Interval(3,11), Interval(17,25), Interval(58,73)};
    vector<Interval> second = {Interval(6,18), Interval(40,47)};

    vector<Interval> merged = merge_lists(first, second);
    for(Interval i : merged){
        cout<<i.start<<"-"<<i.end<<",";
    }
    cout<<endl;
}
