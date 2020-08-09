// Problem Link
// https://www.hackerrank.com/challenges/counting-valleys/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=warmup
#include <bits/stdc++.h>
using namespace std;

int countingValleys(int n, string s) {
int level = 0, vally = 0 ;
    for (const char x : s) {
        if(x == 'U') {
            if(level == -1) {
                vally++ ;
            }
            level++;
        }else{
            level-- ;
        }
    }
    return vally ;
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
