#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

void maxDepth(string &str) {
    int maxCount = 0, curCount = 0 ;
    for_each(begin(str), end(str), [&](const char &c) {
        if (c == '(') curCount++ ;
        if (maxCount < curCount) maxCount = curCount ;
        if (c == ')') curCount -- ;
    });

    cout << maxCount << endl ;
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    string str = "(((X))(((Y)))))" ;
    maxDepth(str) ;
   
    return 0;
}
