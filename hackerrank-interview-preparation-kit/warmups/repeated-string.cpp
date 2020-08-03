// Problem Link
// https://www.hackerrank.com/challenges/repeated-string/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=warmup

#include <bits/stdc++.h>
using namespace std;

long repeatedString(string s, long n) {
int len = s.length() ;
    // long run_lcount[len] ;
    // if(s[0] == 'a')
    //     run_lcount[0] = 1;
    
    // for(int i = 1; i < len ; i++) {
    //     run_lcount[i]  = run_lcount[i-1] ;
    //     if(s[i] == 'a'){
    //         run_lcount[i] += 1 ;
    //     }
    // }
    // long k = n/len ;
    // long remain = (n%len == 0) ? 0 : run_lcount[n%len - 1];
    // long total = k *run_lcount[len-1] + remain ;
    // return total ;
    string res = s ;
    for(long i = 1; i < n/len; i++ ){
        res += s;
    }
    return (n % len == 0) ? (long)count(res.begin(), res.end(), 'a') : (long)count(res.begin(), res.end(), 'a') + 1;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
