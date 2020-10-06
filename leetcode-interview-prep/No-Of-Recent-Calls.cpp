/*
	problem link: https://leetcode.com/problems/number-of-recent-calls/
	author: Sounish Nath
	Day 1
*/
#include<bits/stdc++.h>
using namespace std ;

class RecentCounter {
public:
	deque<int> requests;
    RecentCounter() {
        requests = {};
    }
    
    int ping(int t) {
        requests.push_back(t);
        while(requests.front() < t - 3000) {
        	requests.pop_front();
		}
		return (int)requests.size();
    }
};


int main() {
	srand(time(NULL)); cin.tie(0);
	ios::sync_with_stdio(false);

	RecentCounter* obj = new RecentCounter();
    int param_1 = obj->ping(t);

}

