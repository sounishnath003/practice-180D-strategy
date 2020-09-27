/*
	Name: Cities & Concert (CodeNation Problem Solution)
	Author: Sounish Nath
	Date: 28-09-20 00:18
*/

#include<bits/stdc++.h>
using namespace std ;
const int inf = 2e9+18 ;

int bfs(int source, vector<vector<pair<int, int>>> graph, int n, vector<int> A) {
    set<pair<int, int>> cache ; // {cost, vertex}
    vector<int> dist(n, inf);
    dist[source] = 0;
    cache.insert({0, source});
    while(!cache.empty()){
        auto pp = *(cache.begin());
        cache.erase(cache.begin()); // pop out
        int node = pp.second;
        int nodedist = pp.first;
        for(auto kid : graph[node]) {
            if(nodedist + kid.second < dist[kid.first]){
                int d = kid.first ;
                if(cache.find({dist[d], d}) != cache.end() ){
                    cache.erase( { dist[d], d } );   
                }
                dist[d] = nodedist + kid.second ;
                cache.insert({ dist[d], d });
            }
        }
    }
    int minco = INT_MAX ;
    for(int i = 0; i < n; i++){
        dist[i] = 2 * dist[i] + A[i];
        minco = min(minco , dist[i] ) ;
    }
    return minco;
}

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	vector<vector<int>> B;
	cin >> B;
	
	int n = A.size() ;
        vector<vector<pair<int, int>>> grap(n);
        for(int i = 0; i < (int) B.size(); i++) {
	    grap[B[i][0] - 1].push_back( {B[i][1] - 1, B[i][2]}); // adjacent matrix implementation
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
	    ans[i] = bfs(i, grap, n, A);
        }
	
	cout << ans ;
}

