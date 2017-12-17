#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Interval{
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

static bool comparator(Interval a, Interval b){
    return a.start < b.start;
}

vector<Interval> merge(vector<Interval>& intervals) {
    int first = 0;
    int curr = 1;
    sort(intervals.begin(), intervals.end(), comparator);
    while(first != curr && curr < intervals.size()) {
        if(intervals.at(first).start == -1 && intervals.at(first).end == -1) {
            first++;
        }
        else if(intervals.at(first).end >= intervals.at(curr).start && intervals.at(first).end <= intervals.at(curr).end) {
            intervals.at(first).end = intervals.at(curr).end;
            intervals.at(curr).start = -1;
            intervals.at(curr).end = -1;
            curr++;
        }
        else if(intervals.at(first).end >= intervals.at(curr).start && intervals.at(first).end >= intervals.at(curr).end) {
            intervals.at(curr).start = -1;
            intervals.at(curr).end = -1;
            curr++;
        }
        else {
            first++;
            curr++;
        }
    }
    for(vector<Interval>::iterator it = intervals.begin(); it!=intervals.end(); ) {
        if(it->start == -1 && it->end == -1) {
            it = intervals.erase(it);
        } else {
            it++;
        }
    }
    return intervals;
}
int main(void){
    return 0;
}
