#include<bits/stdc++.h>
#include<boost/algorithm/string.hpp>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}
#define fo(i, n) for(int i = 0; i < n ; i++)
const int N = 1e+6 ;

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

// search text queries
void textQueries(vector<string> sentences, vector<string> queries) {
    int i = 0 ; bool tt = false ; int gcnt = 0 ;

    // optimized solutions
    for(auto query : queries) {
        vector<string> q_words ;
        boost::split(q_words, query, boost::is_any_of(" "));
        for(auto sentence : sentences) {
            int cnt = 0 ;
            for(auto qwd : q_words) {
                vector<string> sentnces ;
                boost::split(sentnces, sentence, boost::is_any_of(" ")) ;
                auto match = find(sentnces.begin(), sentnces.end(), qwd);
                if (match != sentnces.end() ) {cnt++ ;}else{break;}
            }
            if(cnt == q_words.size()) {gcnt++; cout << i << " " ;}
            i++ ;
        }
        if(gcnt == 0) {cout << -1 ;}
        gcnt = 0 ; i = 0 ;
        cout << endl;   
    }

    // regex pattern matching solution
    for(auto query : queries) {
        vector<string> words;
        stringstream ss(query) ;
        do{
            string wor ; ss >> wor ;
            words.emplace_back(wor) ;
        }while(ss) ;
        for (auto sentence : sentences) {
            int cnt = 0 ;
            for(auto word : words )    {
                regex r ("\\b" + word + "\\b") ;
                if (regex_search(sentence, r)) {cnt++;}
                else {break ;}
            }
            if (cnt == words.size() ) {gcnt++; cout << i << " " ; }
            i++ ;
        }
        if (gcnt == 0) {cout << -1; }
        gcnt = 0 ;
        i = 0 ;
        cout << endl ;
    }

}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin) ;
        freopen("output.txt", "w", stdout) ;
    #endif

        string sentences_count_temp;
        getline(cin, sentences_count_temp);

        int sentences_count = stoi(ltrim(rtrim(sentences_count_temp)));

        vector<string> sentences(sentences_count);

        for (int i = 0; i < sentences_count; i++)
        {
            string sentences_item;
            getline(cin, sentences_item);

            sentences[i] = sentences_item;
        }

        string queries_count_temp;
        getline(cin, queries_count_temp);

        int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

        vector<string> queries(queries_count);

        for (int i = 0; i < queries_count; i++)
        {
            string queries_item;
            getline(cin, queries_item);

            queries[i] = queries_item;
        }

        textQueries(sentences, queries);

        return 0;
}